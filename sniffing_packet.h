#ifndef SNIFFING_PACKET_H
#define SNIFFING_PACKET_H
//sniffing data
#include<stdio.h>
#include<pcap.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/ether.h>
#include <ctype.h>
#include <time.h>
#include<netinet/ip.h>
void packet_loop( u_char *argc , const struct  pcap_pkthdr *handle  , const u_char *packet){
    struct ether_header *ether;
    struct ip *ip_header;
    char sor[INET_ADDRSTRLEN];
    char des[INET_ADDRSTRLEN];
    time_t t;
    time(&t);
    
    
    // GET ETHER HEADER ;
    ether = (struct ether_header*)packet;
    // check the packet is ip header
    if(ntohs(ether->ether_type ) == ETHERTYPE_IP){
    //ip header 
      ip_header = (struct ip*)(packet + sizeof(struct ether_header));
    // convert ip address into string
      inet_ntop(AF_INET ,&(ip_header->ip_src),sor,INET_ADDRSTRLEN);
      inet_ntop(AF_INET ,&(ip_header->ip_dst),des,INET_ADDRSTRLEN);
      //print packets detials 
      printf("packet's length as %d \n", handle->len);
      printf("Number of length as %d\n",handle->caplen);
      printf("Current time %s\n",ctime((const time_t *)&handle->ts.tv_sec));
      printf("source MAC %s\n",ether_ntoa((struct ether_addr*)ether->ether_shost));
      printf("Destination MAC %s\n",ether_ntoa((struct ether_addr*)ether->ether_dhost));
      printf("source ip %s \n",sor);
      printf("destination ip %s \n",des);
      }else{
      printf("cannot open to read the packet \n");
    }
      
  }
    
      
    
int c_the_packet(){
	pcap_t *open_d;
	char error[PCAP_BUF_SIZE];
	char *device;
	device = pcap_lookupdev(error);
	if(device == NULL){
		printf("device is not found \n");
	}
	printf("device name is %s ", device);
	open_d = pcap_open_live(device,BUFSIZ,1,1,error);
	if(open_d == NULL){
		printf("ERROR : CANNOT OPEN THE PCAKETS : %s " , error);
		exit(-1);
	}
	pcap_loop(open_d,0,packet_loop,NULL);
	
	pcap_close(open_d);
	return 0;
}


#endif 


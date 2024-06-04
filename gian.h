#ifndef GIBN_H
#define GIBN_H
#include<stdlib.h>
//ip //netmask
int  get_info_about_network(char *device){
	int lookup_return;
	char error[PCAP_ERRBUF_SIZE];
	char ip[20];
	char mask[20];
	bpf_u_int32 ip_raw;
	bpf_u_int32 mask_raw;
	struct in_addr addr;
	

	lookup_return = pcap_lookupnet(device,&ip_raw,&mask_raw,error);
	if(lookup_return == -1){
		printf(" ERROR :  device is not found enter a correct device  \n");
		exit(1);
		}
	addr.s_addr = ip_raw;
	strcpy(ip,inet_ntoa(addr));
	if(ip == NULL){
		printf("cannot itoa get a problem \n");
		return -1;
	      }
        printf("ip : %s\n",ip);
        
	addr.s_addr = mask_raw;
	strcpy(mask,inet_ntoa(addr));
	if(mask == NULL){
		printf("cannot itoa get a problem \n");
		return -1;
	}
	
	printf("netmask : %s \n",mask);
	
      }
	
	
		
  #endif

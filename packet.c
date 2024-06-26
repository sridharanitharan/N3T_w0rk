
#include<stdio.h>
#include<string.h>
#include<pcap.h>
#include<arpa/inet.h>
#include "ava_interface.h"
#include "gian.h"
#include "sniffing_packet.h"
#include "dpt.h"
#include<stddef.h>
#include<stdlib.h>

//version 1.0

void help_print_(char *binaryfile){
	printf("-l or --lookup to print a interface \n");
	printf("-s or --sniffing to print a data on the fly in the internet connection\n");
	printf("-r or --raw to print a ip address and netmask address \n");
	printf("-d or --dpt determine a packet type [ip or arp or revarp]\n");
	printf("Usage : %s <option> \n",binaryfile);
}
int main( int argc ,  char *argv[]){
	char *device;
	if(argc< 2 || strcmp("-h",argv[1]) == 0 ||strcmp("--help",argv[1] ) == 0 ){
	  help_print_(argv[0]);		
	}else if(strcmp("-l",argv[1])==0 || strcmp("--lookup",argv[1] )== 0 ){
	  available_interface();
	}else if(strcmp("-r",argv[1]) ==0 || strcmp("--raw",argv[1]) ==0){
	    if(argc<3){
	      printf("usage %s -r <enter a device name ",argv[0]);
	      help_print_(argv[0]);
	      }else{
	        get_info_about_network(argv[2]);
	      }
	  }
	else if(strcmp("-s",argv[1])==0 || strcmp("--sniffing",argv[1])==0){
		printf("sniffing......");
		if(argc == 2){
			c_the_packet();
		}
		else{
			help_print_(argv[0]);
		}
	}else if(strcmp("-d",argv[1])==0 || strcmp("--dpt",argv[1])==0){
	    determine_a_packet_type();
	    }
	else{
	        printf("invalid arugument \n");
		help_print_(argv[0]);	
	}
	
}
		

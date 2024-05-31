
#include<stdio.h>
#include<string.h>
#include<pcap.h>
#include<arpa/inet.h>
#include "ava_interface.h"
#include "gian.h"
#include "sniffing_packet.h"
#include<stddef.h>
#include<stdlib.h>


void help_print_(char *binaryfile){
	printf(" -i<eg : eth0 ,wlan >0 or --interface to  print a available devices \n");
	printf("Usage : %s <option> //enter a arugument\n",binaryfile);
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
		printf("sniffing");
		if(argc == 2){
			c_the_packet();
		}
		else{
			help_print_(argv[0]);
		}
	}    
	else{
	        printf("invalid arugument \n");
		help_print_(argv[0]);	
	}
	
}
		

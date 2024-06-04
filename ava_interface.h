#ifndef AVAILABLE_INTERFACE_H
#define AVAILABLE_INTERFACE_H

void available_interface(){
	char error[PCAP_ERRBUF_SIZE];
	pcap_if_t *interface,*temp;
	int i;
	if(pcap_findalldevs(&interface,error) == -1){
		printf("ERROR : Not found <%s> ",error);
	}else{
	printf("Device's interface \n");
	for(temp = interface ; temp ; temp =temp->next){
	  printf("%d {%s} \n",++i,temp->name);
	  }
	}
}

/*int main(){
    available_interface();
    return 0;
  }*/
  
#endif 

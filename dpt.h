#ifndef DPT_H
#define DPT_H
//determina a packet type
void dpt(u_char *argc , const struct pcap_pkthdr *handler , const u_char *packet){
  struct ether_header *eth_header;
  eth_header = (struct ether_header*)packet;
  if(ntohs(eth_header->ether_type)== ETHERTYPE_IP){
    printf("packet type is ip");
    }else if(ntohs(eth_header->ether_type) == ETHERTYPE_ARP){
    printf("packet type is ARP ");
    }else if(ntohs(eth_header->ether_type) == ETHERTYPE_REVARP){
    printf("packet type is REARP ");
    }else{
    printf("cannot determine packet ");
    }
}
  
  
void determine_a_packet_type(){
      char *dev;
      pcap_t *handle;
      char error[PCAP_BUF_SIZE];
      dev = pcap_lookupdev(error);
      if(dev == NULL){
        printf("ERROR %s ",error);
        exit(-2);
        }
      handle = pcap_open_live(dev,BUFSIZ,1,0,error);
      if(handle == NULL){
        printf("cannot open the packet's ERROR : %s ",error);
        exit(-1);
        }
      pcap_loop(handle,1,dpt,NULL);
      pcap_close(handle);
    }
#endif 

#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define DOCLEN 999999

int main(){
  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(PORT);
  address.sin_addr.s_addr = htonl(INADDR_ANY);


  int lstn_sock = socket(AF_INET, SOCK_STREAM, 0);
  if(lstn_sock == -1){
    printf("socket() call failed.");
    exit(-1);
  }
  printf("Socket created successfully.\n");

  while(1){ 
    int status;
    status = bind(lstn_sock, (struct sockaddr*)&address, sizeof(struct sockaddr_in));
    if(status == -1){
      printf("bind() call failed\n");
    }else{
      printf("Binding completed.\n");
    
      while(1){

	// LISTEN FOR CLIENT
	status = listen(lstn_sock, 5);
	if(status == -1){
	  printf("listen() call failed");
	  //	exit(-1);
	}
	printf("Listening for connection requests...\n");


	// ACCEPT CLIENT CONNECTION
	int mysocket2 = accept(lstn_sock, NULL, NULL);
	if(mysocket2 == -1){
	  printf("accept() call failed.");
	  //	break;
	}
	printf("Connection established.\n");

	
	int count;
	char snd_message[DOCLEN];
	count = recv(mysocket2, snd_message, sizeof(snd_message), 0);
	if(count == -1){
	  printf("recv() call failed.");
	}else
	  std::cout << snd_message << "\n";
	
      
	//CLIENT SECTION
	int ext_sock = socket(AF_INET, SOCK_STREAM, 0);
	if(ext_sock == -1){
	  printf("Error in connect()\n");
	}else
	  printf("Connected\n");
	
	status = connect(ext_sock, (struct sockaddr*)&address, sizeof(struct sockaddr_in));
	if(status == -1){
	  printf("connect() call failed");
	}

	//strcat(rcv_message, "\r\n");
	
	count = send(ext_sock, snd_message, sizeof(snd_message), 0);
	if(count == -1){
	  printf("send() call failed.");
	}else{
	  printf("message sent to server\n");
	}

	char rcv_message[DOCLEN];
	count = recv(ext_sock, rcv_message, sizeof(rcv_message), 0);
	std::cout << "here\n";
	if(count == -1){
	  printf("Error in recv()\n");
	}else
	  printf("Server: %s\n", rcv_message);	
	}      
	    
	close(ext_sock);
	
	// END CLIENT SECTION
	      
	// ADD PARSING AND EDITING HERE
	// PARSE ON rcv_message
	      
	count = send(socket2, rcv_message, sizeof(rcv_message), 0);
	if(count == -1){
	  printf("Error in final send()\n");
	}
	
	close(mysocket2); 
      }
    }
  }  
  close(lstn_sock);
}

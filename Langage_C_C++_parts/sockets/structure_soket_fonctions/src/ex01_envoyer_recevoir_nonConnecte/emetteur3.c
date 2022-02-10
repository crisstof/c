/**
 *
 * Envoie des types de données en mode non connecte
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>                                                                                          

#include "fonctionsSocket.h" 
                                                                        
int main(int argc, char  *argv[]) {                                                                
    int    desc_sock;                                                                                                   
	int     val=42;   
	int     envoyes; 		
	desc_sock = socketUDP_EAD(3000);                                                               
    if (desc_sock < 0) { 
		printf("Erreur creation socket");
     }  
     envoyes = sendto(desc_sock, &val, sizeof(int),0, 
            socketAddr_EAD("localhost", 2610), tailleAddr_EAD()); 
      if (envoyes== -1) {                                         
	  printf("Erreur a l’envoi");
     }                           
     close(desc_sock);           
     return 0;                   
}






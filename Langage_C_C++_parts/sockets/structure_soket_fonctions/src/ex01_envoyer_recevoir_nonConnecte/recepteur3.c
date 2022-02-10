/**
 *
 * reçoit différent type de données en mode non connecté
 */

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include "fonctionsSocket.h"
int main(int argc, char  *argv[]) {  
   int    desc_sock;  
   int     val;   
   int recus;
   desc_sock = socketUDP_EAD(2610);  
   if (desc_sock < 0) {
         printf("Erreur creation socket");
   }
   recus=recvfrom(desc_sock, &val, 
   sizeof(int),0,NULL,NULL);
   if (recus== -1) {
       printf("Erreur a la reception");
   }
   close(desc_sock);
   return 0;
}
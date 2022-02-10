#include "fonctionsSocket.h"
#include <string.h> 	//standard chaine et mémoire
#include <stdio.h>  	//standard entrée/sortie
#include <stdlib.h>		//conversion de nombre size_t ...
#include <sys/types.h>
#include <errno.h>		//affiche les erreurs exception
#include <netdb.h>       //*//définit struct hostent, servent ...
#include <sys/socket.h>  //*//pour créer les sockets
#include <netinet/in.h>  //*//retrouve machine dans le domaine internet AF_INET sockaddr_in
//#include <winsock2.h>  //sous windows les 2 remplacent //*
//#include <ws2tcpip.h>	 //ne fonctionne pas sous windows pas les mêmes fonctions

int socketServeur_EAD(unsigned short port) {
  int sock; /* descripteur de la socket */
  int err;	/* code d'erreur */

  struct sockaddr_in nom;	/* adresse de la sochet acces a toutes les machines du domaine Internet

  /* Creation de la socket, protocole TCP */
  sock = socket(AF_INET, SOCK_STREAM, 0);//(domain, type, protocol )  créer la socket renvoi -1

  if (sock < 0) {
    perror("Erreur a la creation de la socket");
    return ERR_SOCKET;
  }

  /* Initialisation de l'adresse de la socket */
  nom.sin_family = AF_INET; //famille d’adresse sin_family
  nom.sin_port = htons(port);//sin_port host to network|convertit short htons host to network octet réseau
  nom.sin_addr.s_addr = INADDR_ANY;//adresse internet @machine courante
  memset(nom.sin_zero, 0, 8);//(&addr,0, sizeof(addr))    

  /* Attribution de l'adresse a la socket */
  //(sock, Pointeur sur adresse qui doit être associé à la socket, taille de la structure adresse sizeof(addr) 
  err = bind(sock, (struct sockaddr *)&nom, sizeof(struct sockaddr_in));
  if (err < 0) {
    perror("Erreur sur le bind");
    return ERR_BIND;
  }

  /* Utilisation en socket de controle, puis attente de demandes de connexion. */
  //crée socket de connexion (backlog nb max demande attente)//socket de connexion
  err = listen(sock, 1);
  if (err < 0) {
    perror("Erreur dans listen");
    return ERR_LISTEN;
  }

  /* Retourne le descripteur de socket */
  return sock;
}
//Socket(crée socket)->bind(associe une adresse à une socket (numéro tél)->listen (attente connexion)

int socketClient_EAD(const char *nom_machine, unsigned short port) {

  int sock; /* descripteur de la socket */
  int err;  /* code d'erreur */

  struct hostent *host;     /* description de la machine serveur */
  struct sockaddr_in addr;  /* adresse de la sochet du serveur */

  /* Creation d'une socket, domaine AF_INET, protocole TCP */
  sock = socket(AF_INET, SOCK_STREAM, 0);//crée la socket
  if (sock < 0) {
    perror("Erreur a la creation de la socket");
    return ERR_SOCKET;
  }

  /* Initialisation de l'adresse de la socket */
  memset(&addr, 0, sizeof(addr));//mise a 0 avant initialisation de la structure
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);

  /* Recherche de l'adresse de la machine */
  host = gethostbyname(nom_machine);//il faut déclarer un pointeur hostent on retrouve @ IP réseau du serveur
  if (host == NULL) {
    printf("Erreur dans la recherche de l'adresse de la machine (gethostbyname)");
    return ERR_GETHOST;
  }

  /* Recopie de l'adresse IP */
  addr.sin_addr.s_addr = ((struct in_addr *) (host->h_addr_list[0]))->s_addr;

  /* Connection au serveur */
  err = connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));//connexion au serveur
  if (err < 0) {
    perror("Erreur la connexion de la socket");
    return ERR_CONNECT;
  }
 
  /* On retourne le descripteur de socket */
  return sock;
}
 

int socketUDP_EAD(unsigned short port) {
  int sock; /* descipteur de la socket */
  int err;	/* code d'erreur */

  struct sockaddr_in addr; /* adresse de la sochet du serveur*/

  /* Creation de la socket, protocole UDP */
  sock = socket(AF_INET, SOCK_DGRAM, 0);//crée la socket
  if (sock < 0) {
    perror("Erreur a la creation de la socket");
    return ERR_SOCKET;
  }

  /* Initialisation de l'adresse de la socket */
  memset(&addr, 0, sizeof(addr));//mise a 0 avant initialisation de la structure
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  /* Attribution de l'adresse a la socket */
  err = bind(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
  if (err < 0) {
    perror("Erreur sur le bind");
    return ERR_BIND ;
  }

  /* Retourne le descripteur de socket */
  return sock;
}


struct sockaddr *socketAddr_EAD(const char *nom_machine, unsigned short port) {
  static struct sockaddr_in addr;
  struct hostent *host;
  
  /* Cherche l'adresse de la machine */
  host = gethostbyname(nom_machine);
  if (host == NULL) {
    printf("Erreur dans la recherche de l'adresse de la machine (gethostbyname)");
    return NULL;
  }

  memset(&addr, 0, sizeof(addr));

  /* Recopie de l'adresse IP */
  addr.sin_addr.s_addr = ((struct in_addr *) (host->h_addr_list[0]))->s_addr;

  /* Initialisation de l'adresse de la socket */
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);

  return (struct sockaddr *)&addr;
}

socklen_t tailleAddr_EAD(void) {
  return sizeof(struct sockaddr_in);
}

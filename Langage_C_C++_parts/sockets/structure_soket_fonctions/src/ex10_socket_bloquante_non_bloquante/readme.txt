EXERCICE10 
Ecrire un serveur et 2 clients de manière à ce que le serveur affiche 
le message du client qui envoie un message le premier.

Q10.1 Programme non_connecté sans utiliser les 2 fonctions non-bloquante
Emetteur on crée socketUDP_EAD(port) ensuite on demande d’entrer le nom, port du destinataire et 
addr=socketAddr_EAD(nom,port) ansuite la chaine à envoyer et size_t len=strlen(chaine)+1) et 
on envoi err= sendto(sock,chiane,len,0,addr,sizeof(struct sockaddr_in) )

Recepteur sock= socketUDP_EAD(atoi(arv[1])) ; 
on réceptionne err= recvfrom(sock, buffer,LEN,0,NULL,NULL) on affiche le premier message emetteur1
et on réceptionne err= recvfrom(sock, buffer,LEN,0,NULL,NULL) on affiche le premier message emetteur2

R. En prenant les 2 clients du mode non connecté ça marche puisqu’on a pas de connexion, 
les clients s’adressent à la même socket et le serveur se contente d’attendre sur cette socket et 
reçoit le premier des 2 messages qui arrive.


Q10.2 cette fois en mode connecté   (problème)
 La mise en place de connexions entre le serveur et chacun des clients suppose que le serveur 
possède 2 sockets, chacune connectée avec l’un des clients. l’attente (recv) sur l’une des 
sockets nous empêche d'écouter l'autre. A moins de demander aux programmes clients d’envoyer 
sans arrrêt des message pour dire qu’il ne transmet rien.
On passe à la suite qui permet une attente simultanée sur les 2 sockets.

Q10.3  programme avec des fonctions non bloquantes puis avec select.
select: avantage permet de mettre le serveur en attente jusqu’à un message reçu, le serveur libère le processus pour les autres applications  (processus endormie)
non-bloquant attente active demande de recevoir sans arrêt consomme temps processeur.
Celle-ci est adapté car rien à faire d’autre que d’attendre la réception du premier message.

Par contre  le select :  c’est si on avait d’autres opération à faire en attendant.

1) Programme mode non-connecté sans utiliser de fonctions non-bloquante  : serveurNB.c

Juste à prendre 2 clients non-connecté et le serveur attend sur cette socket et 
reçoit le premier message et ainsi de suite:


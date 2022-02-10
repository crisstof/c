Ex07
 Taille des données inconnues avec les programmes plusieurs échanges réalisé avec des chaines de taille non fixe:
L'incidence est qu’on ne connait pas la taille à recevoir donc il faut un protocole de communication pour que 
le serveur reçoive des chaines de taille quelconque, on a 2 solutions:

1 on envoi d’abord la taille vers le serveur, le serveur réserve la taille (malloc).

2 le client envoie la chaine et le serveur reçoit la chaine par morceau tant qu’il y a des données dans la socket mais la fin de réception? 

Comment savoir s’il reste des données, on lit une lecture supplémentaire non bloquante pour ne pas rester en attente qu’il n’y a plus rien 
ou un marqueur de fin Prog1 avec marqueur de fin: Est-ce différent si on échange un tableau d’entier?
Le marqueur de fin ne peut pas être utilisé et dans un tableau il n’y a pas de fin de tableau 
le serveur a recours à malloc ou une réception non-bloquante ou un marqueur de fin mais quel caractère 
La version malloc prog2

Prog1: char chaine[taille]  et send en chaine, strlen(chaine)+1, le serveur cher buf|taillemax] avant 
d’entrée dans la boucle for(;;;)on ajoute \0 à la fin dt tableau: but[taillemax-1}=’\0’ 
on reçoit la chaine recv buf, taillemax-1, on affiche buf et taillmax += recus et si buf[recus-1]==’\0’ break du for
Le recus de recv reçoit le nombre de caractère de la chaine et \0

Prog2: comme le serveur ne sait pas ce qu’il peut réserver en mémoire pour recevoir les données d’un tableau alors on fait:
Client remplit un tab[i] de 1024 valeurs et la taille est initialisé à 1024 on envoie d’abord la taille du tableau send  &taille, sizeof(int).
Serveur reçoit la taille recus=recv(sock_trans,&taille, sizeof(int),0) puis 
on alloue la taille du tableau dynamiquement buf=calloc(taille, sizeof(int)); attention pour alloue il faut un pointeur donc int *buf;
Client envoie le tableau  send(sock,tab,taillemax*sizeof(int),0) 
Serveur reçoit le tableau recv(sock_trans,buf, taille*sizeof(int),0)
Ici recus = taille (1024*sizeof(int) qui est 2 = 4096

compilation avec make:
make -f Makefile

si linux n'a pas de g++ ou make  donc sur debian
sudo apt install build-essential

--------------------------------------------------------------
message: envoyer une chaine de caractère:

Emetteur    		------>   Recepteur


Emetteur2    		------>   Recepteur2 (Message reçu)	
 (message reçu)	       <-------    (message renvoyer)

--------------------------------------------------------------
message: pour envoyer des types de données en mode non connecté

Emetteur3  -------------> Recepteur3



L'Echange de données peuvent être:
-------------------------------

Entier                                                                           
int val=42              ---------->   int val;                         
&val, sizeof(int) , 0                 &val, sizeof(int),0           
                       


Tableau  /* mise a zero memset avant réception */
int array[5]= {1,2,3,4,5}; -------->  int array[5];
array, 5*sizeof(int),0                memset(array, 0, LEN*sizeof(int));
				             array, 5*sizeof(int),0


Chaine 
char  *chaine = "Hello"     -------->   char buf[20]
chaine,6,0                              buf, sizeof(buf),0









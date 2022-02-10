/**
 *
 * Envoie une chaine de caractère à un programme récepteur.
 */

#include <stdio.h>
#include <stdlib.h>

#include "fonctionsCommunication.h"

int main() {
  char chaine_envoyer[100];
  char *chaine_recevoir;

  /* 
   * Saisie de la chaine 
   */
  printf("Donnez une chaine: ");
  scanf("%s", chaine_envoyer);
  
  /*
   * Envoi de la chaine
   */
  envoyer(chaine_envoyer);

  /*
   * Réception du message de retour
   */
  chaine_recevoir = recevoir();

  printf("Message recu: %s\n", chaine_recevoir);
  
  fin_communication();
  free(chaine_recevoir);

  return 0;
}






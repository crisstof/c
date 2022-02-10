/**
 * Envoie une chaine de caractère à un programme récepteur.
 */

#include <stdio.h>
#include <stdlib.h>

#include "fonctionsCommunication.h"

int main() {
  char chaine_envoyer[100];

  /* 
   * Saisie de la chaine 
   */
  printf("Donnez une chaine: ");
  scanf("%s", chaine_envoyer);
  
  /*
   * Envoi de la chaine
   */
  envoyer(chaine_envoyer);
  fin_communication();

  return 0;
}

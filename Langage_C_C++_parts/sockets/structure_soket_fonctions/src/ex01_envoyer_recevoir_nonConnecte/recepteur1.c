/**
 *
 * Reçoit une chaine de caractère de l'émetteur.
 */

#include <stdio.h>
#include <stdlib.h>

#include "fonctionsCommunication.h"

int main() {
  char *chaine_recevoir;

  /* 
   * Reception du message
   */
  chaine_recevoir = recevoir();

  printf("Message recu: %s\n", chaine_recevoir);

  fin_communication();
  
  free(chaine_recevoir);
  return 0;
}

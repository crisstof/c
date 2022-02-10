#ifndef FONCTIONS_COMMUNICATION_H
#define FONCTIONS_COMMUNICATION_H

/**
 * Envoie la chaîne de caractère.
 * @param chaine la chaine de caractère à envoyer.
 */
void envoyer(const char *chaine);//envoyer la chaine

/**
 * Reçoit une chaîne de caractère.
 * @return la chaine de caractère reçue.
 */
char *recevoir(void); //reçoit la chaine de caractère reçue

/**
 * Coupe la communication.
 */

void fin_communication(void);

#endif /* FONCTIONS_COMMUNICATION_H */

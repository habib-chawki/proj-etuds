#include <stdio.h>
#include <stdlib.h>
#include "Fonctions.h"

float calculer_moyenne(float notes[]){
	int coeff[NBR_MODULES] = {2, 3, 3, 2, 3, 2, 1}, i;
	
	float somme_notes = 0.0;
	for(i = 0; i < NBR_MODULES; i++){
		somme_notes += notes[i] * coeff[i];
	}
	return somme_notes / SOMME_COEFF;
}

int calculer_credit(float notes[]){
	int credits[NBR_MODULES] = {4, 6, 4, 4, 5, 5, 2}, i;
	
	int somme_credits = 0;
	for(i = 0; i < NBR_MODULES; i++){
		if(notes[i] >= 10){
			somme_credits += credits[i];
		}
	}
	return somme_credits;
}

void afficher_liste_etudiants(Etudiant *etuds){
	while(etuds != NULL){
		printf("- %d %d %s %s %.2f %d \n", etuds->num,  etuds->groupe, etuds->nom, etuds->prenom, etuds->moyenne, etuds->credit);
		etuds = etuds->suivant;
	}
	printf("\n");
}

Etudiant *major_de_promo(Etudiant *etuds){
	Etudiant *major = etuds;
	while(etuds != NULL){
		if(etuds->moyenne > major->moyenne){
			major = etuds;
		}
		etuds = etuds->suivant;
	}
	
	return major;
}

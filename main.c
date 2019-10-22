#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fonctions.h"

int main() {
	Etudiant *etuds = NULL, *x, *major;
	char *modules[] = {"TL", "ASDD", "SI", "LM", "POO", "AO", "ENG"};
	float notes[NBR_MODULES];
	int reste = true, i;
	
	do{
		x = malloc(sizeof(Etudiant));
		printf("\t___ Saisir les informations de l'etudiant ___\n\n");
		printf("Num: "); scanf("%d", &x->num); 
		printf("Nom: "); scanf("%s", &x->nom);
		printf("Prenom: "); scanf("%s", &x->prenom);
		printf("Groupe: "); scanf("%d", &x->groupe);
		printf("\t__ ses notes __\n");
		
		for(i = 0; i < NBR_MODULES; i++){
			do{
				printf("%s: ", modules[i]);
				scanf("%f", &notes[i]);
			}while(notes[i] < 0 || notes[i] > 20);
		}
		
		x->moyenne = calculer_moyenne(notes);
		x->credit = x->moyenne >= 10 ? SOMME_CREDITS : calculer_credit(notes);
	
		x->suivant = etuds;
		etuds = x;
		
		printf("Reste-t-il des etudiants dans la promo ? ");
		scanf("%d", &reste);
	}while(reste);
	
	afficher_liste_etudiants(etuds);
	major = major_de_promo(etuds);
	
	printf("\nLe major de la promo est: %s %s sa moyenne est: %.2f\n", major->nom, major->prenom, major->moyenne);
	
	return 0;
}

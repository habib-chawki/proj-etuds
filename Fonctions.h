#define NBR_MODULES 7    // nombre des modules
#define SOMME_COEFF 16   // somme des coefficients
#define SOMME_CREDITS 30 // somme des credits

typedef struct Etudiant Etudiant;
struct Etudiant
{
	int num, groupe, credit;
	char nom[20], prenom[20];
	float moyenne;
	Etudiant *suivant;
};

void afficher_liste_etudiants(Etudiant *etuds);
float calculer_moyenne(float notes[]);
int calculer_credit(float notes[]);
Etudiant *major_de_promo(Etudiant *etud);

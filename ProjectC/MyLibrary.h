struct date{
	int jour;
	int mois;
	int annee;
};
typedef struct date DATE;
struct Livre{
	int Code;
	char titre[20];
	char auteur[20];
	int nbrCopier;
};
typedef struct Livre LIVRE;
struct Adherent{
	int Code;
	char Nom[20];
	char Prenom[20];
};
typedef struct Adherent ADHERENT;
struct emprunt{
	int code;
	int CodeLivre;
	int CodeAdherent;
	DATE dateEmprunt;
};
typedef struct emprunt EMPRUNT;
struct Employe{
	int CIN;
	char Nom[20];
	char Prenom[20];
};
typedef struct Employe EMPLOYE;
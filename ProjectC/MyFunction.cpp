#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<conio.h>
#include<string.h>
#include"MyLibrary.h"
#define Lib_bin "LivreBinaire"
#define Adh_bin "AdherentBinaire"
#define Emp_bin "EmployeBinaire"
#define Emprunt_bin "EmpruntBinaire"

void rempliredate(DATE* dte){
	printf(" donner le jour\n");
	do{
		scanf("%d",&(*dte).jour);
	}while(((*dte).jour>31)||((*dte).jour<1));
	printf(" donner le mois\n");
	do{
		scanf("%d",&(*dte).mois);
	}while(((*dte).mois>12)||((*dte).mois<1));
	printf(" donner l'annee (cette annee 2017)\n");
	do{
		scanf("%d",&(*dte).annee);
	}while(((*dte).annee>2018)||((*dte).annee<2017));
}
void afficherdate(DATE dte){
	printf("%d/%d/%d",dte.jour,dte.mois,dte.annee);
}
/*
	+-------------------------------------------+
	|       Les fonctions d'allocation           |
	+-------------------------------------------+
*/
void AllocationListeDesLivres(LIVRE*** lv,int nbr){
	*lv = (LIVRE**) malloc(nbr * sizeof(LIVRE*));
	if(!*lv) exit(-1);
	for(int i=0;i<nbr;i++){
		*(*lv+i) = (LIVRE*) malloc(sizeof(LIVRE));
		if(!*(*lv+i)) exit(-2);
	}
}
void ReallocationListeDesLivres(LIVRE*** lv,int nbr){
	*lv = (LIVRE**) realloc(*lv,nbr * sizeof(LIVRE*));
	if(!*lv) exit(-1);
	*(*lv+nbr-1) = (LIVRE*) malloc(sizeof(LIVRE));
	if(!*(*lv+nbr-1)) exit(-22);
}
void AllocationListeDesAdherent(ADHERENT*** adh,int nbr){
	*adh = (ADHERENT**) malloc(nbr * sizeof(ADHERENT*));
	if(!*adh) exit(-1);
	for(int i=0;i<nbr;i++){
		*(*adh+i) = (ADHERENT*) malloc(sizeof(ADHERENT));
		if(!*(*adh+i)) exit(-3);
	}
}
void ReallocationListeDesAdherent(ADHERENT*** adh ,int nbr){
	*adh = (ADHERENT**) realloc(*adh,nbr * sizeof(ADHERENT*));
	if(!*adh) exit(-1);
	*(*adh+nbr-1) = (ADHERENT*) malloc(sizeof(ADHERENT));
	if(!*(*adh+nbr-1)) exit(-33);
}
void AllocationListeDesEmploye(EMPLOYE*** emp,int nbr){
	*emp = (EMPLOYE**) malloc(nbr * sizeof(EMPLOYE*));
	if(!*emp) exit(-1);
	for(int i=0;i<nbr;i++){
		*(*emp+i) = (EMPLOYE*) malloc(sizeof(EMPLOYE));
		if(!*(*emp+i)) exit(-3);
	}
}
void ReallocationListeDesEmploye(EMPLOYE***emp,int nbr){
	*emp = (EMPLOYE**) realloc(*emp,nbr * sizeof(EMPLOYE*));
	if(!*emp) exit(-1);
	*(*emp+nbr-1) = (EMPLOYE*) malloc(sizeof(EMPLOYE));
	if(!*(*emp+nbr-1)) exit(-33);
}
void AllocationListeDesEmprunt(EMPRUNT*** emp,int nbr){
	*emp = (EMPRUNT**) malloc(nbr * sizeof(EMPRUNT*));
	if(!*emp) exit(-1);
	for(int i=0;i<nbr;i++){
		*(*emp+i) = (EMPRUNT*) malloc(sizeof(EMPRUNT));
		if(!*(*emp+i)) exit(-3);
	}
}
void ReallocationListeDesEmprunt(EMPRUNT***emp,int nbr){
	*emp = (EMPRUNT**) realloc(*emp,nbr * sizeof(EMPRUNT*));
	if(!*emp) exit(-1);
	*(*emp+nbr-1) = (EMPRUNT*) malloc(sizeof(EMPRUNT));
	if(!*(*emp+nbr-1)) exit(-33);
}
/*
	+-------------------------------------------+
	|    Les fonctions ouverture de ficher       |
	+-------------------------------------------+
*/
void OuvrireFicherModeEcriture(FILE**flivbin){
	printf("Creation d'un ficher binaire pour les livres...\n");
	*flivbin = fopen(Lib_bin,"wb+");
	if(*flivbin != NULL) printf("Ouverture effectuee!\n");
	else printf("Ouverture echouee!\n");
}
void OuvrireFicherModeEcritureAdh(FILE**fadherent){
	printf("Creation d'un ficher binaire pour les adherents...\n");
	*fadherent = fopen(Adh_bin,"wb+");
	if(*fadherent != NULL) printf("Ouverture effectuee!\n");
	else printf("Ouverture echouee!\n");
}
void OuvrireFicherModeEcritureEmp(FILE** femp){
	printf("Creation d'un ficher binaire pour les employees...\n");
	*femp = fopen(Emp_bin,"wb+");
	if(*femp != NULL) printf("Ouverture effectuee!\n");
	else printf("Ouverture echouee!\n");
}
void OuvrireFicherModeEcritureEmprunt(FILE**femp){
	printf("Creation d'un ficher binaire pour les emprunts...\n");
	*femp = fopen(Emprunt_bin,"wb+");
	if(*femp != NULL) printf("Ouverture effectuee!\n");
	else printf("Ouverture echouee!\n");
}

void OuvrireEnModeLecture(FILE**flivbin){
	printf("Ouverture du ficher binaire des livres...\n");
	*flivbin = fopen(Lib_bin,"rb");
	if(*flivbin != NULL) printf("Ouverture effectuee!\n");
	else printf("Ouverture echouee!\n");
}
void OuvrireEnModeLectureAdh(FILE** fadherent){
	printf("Ouverture du ficher binaire des adherents...\n");
	*fadherent = fopen(Adh_bin,"rb");
	if(*fadherent != NULL) printf("Ouverture effectuee!\n");
	else printf("Ouverture echouee!\n");
}
void OuvrireEnModeLectureEmp(FILE** femp){
	printf("Ouverture du ficher binaire des employees...\n");
	*femp = fopen(Emp_bin,"rb");
	if(*femp != NULL) printf("Ouverture effectuee!\n");
	else printf("Ouverture echouee!\n");
}
void OuvrireEnModeLectureEmprunt(FILE** femp){
	printf("Ouverture du ficher binaire des emprunts...\n");
	*femp = fopen(Emprunt_bin,"rb");
	if(*femp != NULL) printf("Ouverture effectuee!\n");
	else printf("Ouverture echouee!\n");
}
void Initialiser(FILE*flivbin,LIVRE***lv,int* nbr){
	*nbr = 0;
	fseek(flivbin,0,2);
	int i, reper = ftell(flivbin);
	*nbr = reper / sizeof(LIVRE);
	printf("le nombre de livres est : %d\n",*nbr);
	rewind(flivbin);
	AllocationListeDesLivres(lv,*nbr);
	for(int i=0;i<*nbr;i++){
		fread((*(*lv+i)),sizeof(LIVRE),1,flivbin);
		if(feof(flivbin)) break;
	}
}
void InitialiserAdh(FILE*fadhbin,ADHERENT***adh,int* nbr){
	*nbr = 0;
	fseek(fadhbin,0,2);
	int i, reper = ftell(fadhbin);
	*nbr = reper / sizeof(ADHERENT);
	printf("le nombre d'adherents est : %d\n",*nbr);
	rewind(fadhbin);
	AllocationListeDesAdherent(adh,*nbr);
	for(int i=0;i<*nbr;i++){
		fread((*(*adh+i)),sizeof(ADHERENT),1,fadhbin);
		if(feof(fadhbin)) break;
	}
}
void InitialiserEmp(FILE*femp,EMPLOYE***emp,int*nbr){
	*nbr = 0;
	fseek(femp,0,2);
	int i, reper = ftell(femp);
	*nbr = reper / sizeof(EMPLOYE);
	printf("le nombre d'employee est : %d\n",*nbr);
	rewind(femp);
	AllocationListeDesEmploye(emp,*nbr);
	for(int i=0;i<*nbr;i++){
		fread((*(*emp+i)),sizeof(ADHERENT),1,femp);
		if(feof(femp)) break;
	}
}
void InitialiserEmprunt(FILE* femp,EMPRUNT***emp,int*nbr){
	*nbr = 0;
	fseek(femp,0,2);
	int i, reper = ftell(femp);
	*nbr = reper / sizeof(EMPRUNT);
	printf("le nombre d'emprunts est : %d\n",*nbr);
	rewind(femp);
	AllocationListeDesEmprunt(emp,*nbr);
	for(int i=0;i<*nbr;i++){
		fread((*(*emp+i)),sizeof(EMPRUNT),1,femp);
		if(feof(femp)) break;
	}
}
void SauvegardeDesLivre(FILE*flivbin,LIVRE**lv,int nombre){
	for(int i=0;i<nombre;i++){
		fwrite((*(lv+i)), sizeof(LIVRE), 1, flivbin);
		printf("Ajout du livre( code = %d )  dans la base effectue ...\n",(*(lv+i))->Code);
	}
	printf("Sauvegarde des donnees terminee avec succes!\n");
}
void SauvegardeDesAdherent(FILE*fadhbin,ADHERENT**adh,int nbr){
	for(int i=0;i<nbr;i++){
		fwrite((*(adh+i)), sizeof(ADHERENT), 1, fadhbin);
		printf("Ajout de l'adherent( code = %d ) dans la base effectue ...\n",(*(adh+i))->Code);
	}
	printf("Sauvegarde des donnees terminee avec succes!\n");
}
void SauvegardeDesEmployee(FILE*femp,EMPLOYE**emp,int nbr){
	for(int i=0;i<nbr;i++){
		fwrite((*(emp+i)), sizeof(EMPLOYE), 1, femp);
		printf("Ajout de l'employee( CIN = %d ) dans la base effectue ...\n",(*(emp+i))->CIN);
	}
	printf("Sauvegarde des donnees terminee avec succes!\n");	
}
void SauvegardeDesEmprunts(FILE* femprunt,EMPRUNT** emp,int nbr){
	for(int i=0;i<nbr;i++){
		fwrite((*(emp+i)), sizeof(EMPRUNT), 1, femprunt);
		printf("Ajout de l'emprunt( code = %d ) dans la base effectue ...\n",(*(emp+i))->code);
	}
	printf("Sauvegarde des donnees terminee avec succes!\n");	
}
/*
	+-------------------------------------------+
	|         Les fonctions de test              |
	+-------------------------------------------+
*/
int Existe(LIVRE***lv,int code,int nombre){
	int r = 0;
	if(nombre == 0){
		return 0;
	}
	for(int i=0;i<nombre;i++){
		if((*(*lv+i))->Code == code){
			return 1;
		}
	}
	return 0;
}
int ExisteAdh(ADHERENT***adh,int code,int nombre){
	int r = 0;
	if(nombre == 0){
		return 0;
	}
	for(int i=0;i<nombre;i++){
		if((*(*adh+i))->Code == code){
			return 1;
		}
	}
	return 0;
}
int ExisteEmprunt(EMPRUNT*** emp,int code,int nbr){
	int r = 0;
	if(nbr == 0){
		return 0;
	}
	for(int i=0;i<nbr;i++){
		if((*(*emp+i))->code == code){
			return 1;
		}
	}
	return 0;
}
int ExisteEmp(EMPLOYE*** emp,int cin,int nbr){
	int r = 0;
	if(nbr == 0){
		return 0;
	}
	for(int i=0;i<nbr;i++){
		if((*(*emp+i))->CIN == cin){
			return 1;
		}
	}
	return 0;
}
/*
	+-------------------------------------------+
	|          Les fonctions de Menu             |
	+-------------------------------------------+
*/
char SaisieReponse()
{
	char rep;
	do{
		printf("Voulez vous continuer ?(Y/N)\n");
		rep = getch();
	}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
	
	return rep;
}
int menuPrincipale()
{
    int choix;
    printf("\n 1. Gestion des livres");
    printf("\n 2. Gestion des Adherents");
	printf("\n 3. Gestion des Employes");
	printf("\n 4. Gestion des Emprunts");
	printf("\n 5. vider l'ecran");
	printf("\n");
	
	do{
		scanf("%d",&choix);
	}while((choix>5)||(choix<1));

	return choix;
}
int menuAdherent()
{
    int choix;
    printf("\n\t 1. Afficher les Adherents");
    printf("\n\t 2. Ajouter un Adherent");
    printf("\n\t 3. Modifier un Adherent");
    printf("\n\t 4. Supprimer un Adherent");
	printf("\n\t 5. Enregistrer toutes les donnees");
	printf("\n\t 6. vider l'ecran");
	printf("\n");
	
	do{
		scanf("%d",&choix);
	}while((choix>6)||(choix<1));

	return choix;
}
int menuEmploye(){
	int choix;
    printf("\n\t 1. Afficher les Employes");
    printf("\n\t 2. Ajouter un Employe");
    printf("\n\t 3. Modifier un Employe");
    printf("\n\t 4. Supprimer un Employe");
	printf("\n\t 5. Enregistrer toutes les donnees");
	printf("\n\t 6. vider l'ecran");
	printf("\n");
	
	do{
		scanf("%d",&choix);
	}while((choix>6)||(choix<1));

	return choix;
}
int menuEmprunt(){
	int choix;
    printf("\n\t 1. Afficher les Emprunts");
    printf("\n\t 2. Ajouter un Emprunt");
    printf("\n\t 3. Modifier un Emprunt");
    printf("\n\t 4. Supprimer un Emprunt");
	printf("\n\t 5. Enregistrer toutes les donnees");
	printf("\n\t 6. vider l'ecran");
	printf("\n");
	
	do{
		scanf("%d",&choix);
	}while((choix>6)||(choix<1));

	return choix;
}

int menulivre()
{
    int choix;
    printf("\n\t 1. Afficher les livres");
    printf("\n\t 2. Ajouter un livre");
    printf("\n\t 3. Modifier un livre");
    printf("\n\t 4. Supprimer un livre");
	printf("\n\t 5. Trier les livres");
	printf("\n\t 6. Rechercher un livre");
	printf("\n\t 7. Enregistre toutes les donnees");
	printf("\n\t 8. vider l'ecran");
	printf("\n");
	
	do{
		scanf("%d",&choix);
	}while((choix>8)||(choix<1));

	return choix;
}

/*
	+-------------------------------------------+
	|     Les fonctions de gestion Livre         |
	+-------------------------------------------+
*/
void AjouterUnLivre(LIVRE***liv,int nbr){
	int code,r,test = 0;
	while(test == 0){
		printf("Donnez le code du livre :\n");
		scanf("%d",&code);
		r = Existe(liv,code,nbr);
		if(r == 0 ){
			(*(*liv+nbr-1))->Code = code;
			test = 1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Saisissez un autre code car celui-ci existe deja!                |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
	printf("Donnez le titre du livre :\n");
	scanf("%s",&(*(*liv+nbr-1))->titre);
	printf("Donnez le nom de l'auteur du livre :\n");
	scanf("%s",&(*(*liv+nbr-1))->auteur);
	printf("Donnez le nombre d'exemplaire du livre :\n");
	scanf("%d",&(*(*liv+nbr-1))->nbrCopier);
	
}
void ModifierUnLivre(LIVRE***lv,int nombre){
	if(nombre == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas de livre enregistre a Modifier!               |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	int code,r,test = 0;
	char rep;
	printf("+-------------------------------------------------+\n");
	printf("|Saisissez le code du livre a Modifier :            |\n");
	printf("+-------------------------------------------------+\n");
	while(test == 0){
		scanf("%d",&code);
		r = Existe(&*lv,code,nombre);
		if(r == 1 ){
			//Modifier le titre : 
			do{
				printf("Voulez-vous modifier le titre du livre dont le code est (%d)?(Y/N)\n",code);
				rep = getch();
			}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
			if(toupper(rep) == 'Y'){
				for(int i=0;i<nombre;i++){
					if( (*(*lv+i))->Code ==code){
						printf("Donner le nouveau titre du livre :\n");
						scanf("%s",&(*(*lv+i))->titre);
						break;
					}
				}
			}
			//modifier le nom de l'auteur
			do{
				printf("Voulez-vous modifier l'auteur du livre dont le code est (%d)?(Y/N)\n",code);
				rep = getch();
			}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
			if(toupper(rep) == 'Y'){
				for(int i=0;i<nombre;i++){
					if( (*(*lv+i))->Code ==code){
						printf("Donnez le nouveau nom de l'auteur du livre :\n");
						scanf("%s",&(*(*lv+i))->auteur);
						break;
					}
				}
			}
			//modifier le nombre d'exemplaire
			do{
				printf("Voulez-vous modifier le nombre d'exemplaire du livre dont le code est (%d)?(Y/N)\n",code);
				rep = getch();
			}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
			if(toupper(rep) == 'Y'){
				for(int i=0;i<nombre;i++){
					if( (*(*lv+i))->Code ==code){
						printf("Donner le nouveau nombre d'exemplaire du livre :\n");
						scanf("%d",&(*(*lv+i))->nbrCopier);
						break;
					}
				}
			}
			printf("Modification effectuee!\n");
			test=1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Code inexistant!                                                 |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
}
void SupprimerUnLivre(LIVRE***lv,int nombre){
	if(nombre == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas de livre enregistre a supprimer!!             |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	int code,r,test = 0;
	printf("+-------------------------------------------------+\n");
	printf("|Saisissez le code du livre a supprimer :          |\n");
	printf("+-------------------------------------------------+\n");
	while(test == 0){
		scanf("%d",&code);
		r = Existe(&*lv,code,nombre);
		if(r == 1 ){
			for(int i=0;i<nombre;i++){
				if((*(*lv+i))->Code == code){
					for(int j=i;j<nombre-1;j++){
						(*(*lv+j)) = (*(*lv+j+1));
					}
				}
			}
			printf("Suppression effectuee !!\n");
			test=1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Code inexistant!                                                 |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
}

void TriListeDesLivres(LIVRE*** lv,int nbr){
	LIVRE* x;
	//int j;
	if(nbr >1)
	{
		for(int k=0;k<nbr-1;k++){
			for(int i=0;i<nbr-1;i++){
				if(strcmp( (*(*lv+i))->titre , (*(*lv+i+1))->titre )>0)
				{  /* j= (*(*lv+i))->Code;
				   (*(*lv+i))->Code=(*(*lv+i+1))->Code;
				   (*(*lv+i+1))->Code=j; */
					x = (*(*lv+i));
					(*(*lv+i)) = (*(*lv+i+1));
					(*(*lv+i+1))=x;
					
				}
			}
		}
	}
}

void RechercheLivre(LIVRE*** lv,int nbr){
	char x[20];
	int tr=-1;
	
	
		printf("Donner le nom du livre recherche\n");
		scanf("%s",x);
			for(int i=0;i<nbr;i++)
				if(strcmp( (*(*lv+i))->titre , x)==0)
				  tr=i;
				if(tr>-1)
					printf("\nCe livre est disponible, son code est\t %d\n",(*(*lv+tr))->Code);
				else printf("\nCe livre n'est pas disponible" );
					
				
}

/*
	+-------------------------------------------+
	|      Les fonctions d'affichage livre       |
	+-------------------------------------------+
*/
void AfficherLesLivre(LIVRE** lv,int nbr){
	if(nbr == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas de livres enregistres!!                       |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	printf("+-------------------------------------------------+\n");
	printf("|Affichage des livres :                            |\n");
	printf("+-------------------------------------------------+\n");
	for(int i=0;i<nbr;i++){
		printf("|Code : %d	\n",(*(lv+i))->Code);
		printf("|Titre : %s	 \n",(*(lv+i))->titre);
		printf("|Auteur : %s\n",(*(lv+i))->auteur);
		printf("|Nombre d'exemplaire : %d \n",(*(lv+i))->nbrCopier);
		printf("+-------------------------------------------------+\n");
	}
}
void AfficherLesLivresCodesTitre(LIVRE**lv,int nbr){
	if(nbr == 0){
		return;
	}
	printf("+-------------------------------------------------+\n");
	printf("|Les Livres :                                      |\n");
	printf("+-------------------------------------------------+\n");
	for(int i=0;i<nbr;i++){
		printf("|Code : %d	",(*(lv+i))->Code);
		printf("|\t Titre : %s	 \n",(*(lv+i))->titre);
		printf("+-------------------------------------------------+\n");
	}
}
void AfficherLesLivresEnLigne(LIVRE**lv,int nbr){
	if(nbr == 0){
		return;
	}
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|Les Livres :                                                                   |\n");
	printf("+-----------------------------------------------------------------------------+\n");
	for(int i=0;i<nbr;i++){
		printf("|Code: %d\t",(*(lv+i))->Code);
		printf("|Titre: %s\t",(*(lv+i))->titre);
		printf("|Auteur: %s\t",(*(lv+i))->auteur);
		printf("|Nombre d'exemplaire: %d\n",(*(lv+i))->nbrCopier);
		printf("+-----------------------------------------------------------------------------+\n");
	}
}

/*
	+-------------------------------------------+
	|     Les fonctions de gestion adherent      |
	+-------------------------------------------+
*/
void AjouterUnAdherent(ADHERENT*** adh,int nbr)
{
	int code,r,test = 0;
	while(test == 0){
		printf("Donnez le code de l'adherent :\n");
		scanf("%d",&code);
		r = ExisteAdh(adh,code,nbr);
		if(r == 0 ){
			(*(*adh+nbr-1))->Code = code;
			test = 1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Saisissez un autre code car celui-ci existe deja!                |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
	printf("Donnez le nom de l'adherent :\n");
	scanf("%s",&(*(*adh+nbr-1))->Nom);
	printf("Donnez le prenom de l'adherent:\n");
	scanf("%s",&(*(*adh+nbr-1))->Prenom);
	
}
void ModifierUnAdherent(ADHERENT*** adh,int nbr){
	if(nbr == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas d'adherent enregistre a modifier!!            |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	int code,r,test = 0;
	char rep;
	printf("+-------------------------------------------------+\n");
	printf("|Saisissez le code de l'adherent a modifier :      |\n");
	printf("+-------------------------------------------------+\n");
	while(test == 0){
		scanf("%d",&code);
		r = ExisteAdh(&*adh,code,nbr);
		if(r == 1 ){
			//Modifier le nom : 
			do{
				printf("Voulez vous modifier le Nom de l'adherent dont le code est (%d)?(Y/N)\n",code);
				rep = getch();
			}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
			if(toupper(rep) == 'Y'){
				for(int i=0;i<nbr;i++){
					if( (*(*adh+i))->Code ==code){
						printf("Donnez le nouveau Nom :\n");
						scanf("%s",&(*(*adh+i))->Nom);
						break;
					}
				}
			}
			//modifier le prenom
			do{
				printf("Voulez-vous modifier le prenom de l'adherent dont le code est (%d)?(Y/N)\n",code);
				rep = getch();
			}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
			if(toupper(rep) == 'Y'){
				for(int i=0;i<nbr;i++){
					if( (*(*adh+i))->Code ==code){
						printf("Donnez le nouveau prenom :\n");
						scanf("%s",&(*(*adh+i))->Prenom);
						break;
					}
				}
			}
			printf("Modification effectuee!\n");
			test=1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Code inexistant!                                                 |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
}
void SupprimerUnAdherent(ADHERENT*** adh,int nbr){
	if(nbr == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas d'adherent enregistre a supprimeer!!          |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	int code,r,test = 0;
	printf("+-------------------------------------------------+\n");
	printf("|Saisissez le code de l'adherent a supprimer :     |\n");
	printf("+-------------------------------------------------+\n");
	while(test == 0){
		scanf("%d",&code);
		r = ExisteAdh(&*adh,code,nbr);
		if(r == 1 ){
			for(int i=0;i<nbr;i++){
				if((*(*adh+i))->Code == code){
					for(int j=i;j<nbr-1;j++){
						(*(*adh+j)) = (*(*adh+j+1));
					}
				}
			}
			printf("Suppression effectuee!\n");
			test=1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Code inexistant!                                                 |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
}
/*
	+-------------------------------------------+
	|    Les fonctions d'affichage adherent      |
	+-------------------------------------------+
*/
void AfficherLesAdherent(ADHERENT**adh,int nbr){
	if(nbr == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas d'adherent enregistre!                        |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	printf("+-------------------------------------------------+\n");
	printf("|Affichage des adherents :                         |\n");
	printf("+-------------------------------------------------+\n");
	for(int i=0;i<nbr;i++){
		printf("|Code : %d	\n",(*(adh+i))->Code);
		printf("|Nom : %s	 \n",(*(adh+i))->Nom);
		printf("|Prenom : %s\n",(*(adh+i))->Prenom);
		printf("+-------------------------------------------------+\n");
	}
}
void AfficherLesAdherentEnLigne(ADHERENT** adh,int nbr){
	if(nbr == 0){
			return;
	}
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|Les Adherent :                                                                 |\n");
	printf("+-----------------------------------------------------------------------------+\n");
	for(int i=0;i<nbr;i++){
		printf("|Code: %d\t",(*(adh+i))->Code);
		printf("|Nom: %s\t",(*(adh+i))->Nom);
		printf("|prenom: %s\n",(*(adh+i))->Prenom);
		printf("+-----------------------------------------------------------------------------+\n");
	}
}
/*
	+-------------------------------------------+
	|     Les fonctions de gestion employe       |
	+-------------------------------------------+
*/
void AjouterUnEmploye(EMPLOYE***emp,int nbr)
{
	int code,r,test = 0;
	while(test == 0){
		printf("Donnez le numero de la CIN de l'employe :\n");
		scanf("%d",&code);
		r = ExisteEmp(emp,code,nbr);
		if(r == 0 ){
			(*(*emp+nbr-1))->CIN = code;
			test = 1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Saisissez un autre numero de CIN car celui-ci existe deja!       |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
	printf("Donnez le nom d'employe :\n");
	scanf("%s",&(*(*emp+nbr-1))->Nom);
	printf("Donnez le prenom d'employe:\n");
	scanf("%s",&(*(*emp+nbr-1))->Prenom);
}
void ModifierUnEmployee(EMPLOYE*** emp,int nbr){
	if(nbr == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas d'employe enregistre a modifier!!             |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	int code,r,test = 0;
	char rep;
	printf("+--------------------------------------------------------+\n");
	printf("|Saisissez le numero de la CIN de l'employe a modifier :  |\n");
	printf("+--------------------------------------------------------+\n");
	while(test == 0){
		scanf("%d",&code);
		r = ExisteEmp(&*emp,code,nbr);
		if(r == 1 ){
			//Modifier le nom : 
			do{
				printf("Voulez-vous modifier le Nom de l'employe dont le numero de la CIN est (%d)?(Y/N)\n",code);
				rep = getch();
			}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
			if(toupper(rep) == 'Y'){
				for(int i=0;i<nbr;i++){
					if( (*(*emp+i))->CIN ==code){
						printf("Donnez le nouveau Nom :\n");
						scanf("%s",&(*(*emp+i))->Nom);
						break;
					}
				}
			}
			//modifier le prenom
			do{
				printf("Voulez-vous modifier le Prenom de l'employe dont le numero de la CIN est (%d)?(Y/N)\n",code);
				rep = getch();
			}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
			if(toupper(rep) == 'Y'){
				for(int i=0;i<nbr;i++){
					if( (*(*emp+i))->CIN ==code){
						printf("Donnez le nouveau Prenom :\n");
						scanf("%s",&(*(*emp+i))->Prenom);
						break;
					}
				}
			}
			printf("Modification effectuee !!\n");
			test=1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Numero de CIN inexistant!                                        |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
}
void SupprimerUnEmploye(EMPLOYE*** emp,int nbr){
	if(nbr == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas d'employe enregistre a supprimer!           |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	int code,r,test = 0;
	printf("+-------------------------------------------------------------------+\n");
	printf("|Saisissez le numero de la CIN de l'employe a supprimer :             |\n");
	printf("+-------------------------------------------------------------------+\n");
	while(test == 0){
		scanf("%d",&code);
		r = ExisteEmp(&*emp,code,nbr);
		if(r == 1 ){
			for(int i=0;i<nbr;i++){
				if((*(*emp+i))->CIN == code){
					for(int j=i;j<nbr-1;j++){
						(*(*emp+j)) = (*(*emp+j+1));
					}
				}
			}
			printf("Suppression effectuee!\n");
			test=1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Numero de CIN inexistant!                                        |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
}
/*
	+-------------------------------------------+
	|     Les fonctions d'affichage employe      |
	+-------------------------------------------+
*/
void AfficherLesEmployes(EMPLOYE** emp,int nbr){
	if(nbr == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas d'employe enregistre!                         |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	printf("+-----------------------------------------------------+\n");
	printf("|Affichage des employes:                               |\n");
	printf("+-----------------------------------------------------+\n");
	for(int i=0;i<nbr;i++){
		printf("|Cin : %08d	\n",(*(emp+i))->CIN);
		printf("|Nom : %s	 \n",(*(emp+i))->Nom);
		printf("|Prenom : %s\n",(*(emp+i))->Prenom);
		printf("+-------------------------------------------------+\n");
	}
}
void AfficherLesEmployeeEnLigne(EMPLOYE** emp,int nbr){
	if(nbr == 0){
			return;
	}
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|Les Employes :                                                                 |\n");
	printf("+-----------------------------------------------------------------------------+\n");
	for(int i=0;i<nbr;i++){
		printf("|Cin: %08d\t",(*(emp+i))->CIN);
		printf("|Nom: %s\t",(*(emp+i))->Nom);
		printf("|prenom: %s\n",(*(emp+i))->Prenom);
		printf("+-------------------------------------------------------------------------+\n");
	}
}
/*
	+-------------------------------------------+
	|     Les fonctions de gestion emprunt       |
	+-------------------------------------------+
*/
void AjouterUnEmprunt(EMPRUNT***emp,LIVRE** lv,int nbrlv,ADHERENT**adh,int nbradh,int nbr)
{
	int code,r,test = 0;
	while(test == 0){
		printf("Donnez le code de l'emprunt :\n");
		scanf("%d",&code);
		r = ExisteEmprunt(emp,code,nbr);
		if(r == 0 ){
			(*(*emp+nbr-1))->code = code;
			test = 1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Code inexistant!                                                 |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
	AfficherLesLivresEnLigne(lv,nbrlv);
	test = 0;
	while(test == 0){
		printf("Donnez le code du livre :\n");
		scanf("%d",&code);
		r = Existe(&lv,code,nbrlv);
		if(r == 1 ){
			(*(*emp+nbr-1))->CodeLivre = code;
			test = 1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Code inexistant!                                                 |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
	AfficherLesAdherentEnLigne(adh,nbradh);
	test = 0;
	while(test == 0){
		printf("Donnez le code de l'adherent :\n");
		scanf("%d",&code);
		r = ExisteAdh(&adh,code,nbradh);
		if(r == 1 ){
			(*(*emp+nbr-1))->CodeAdherent = code;
			test = 1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Code inexistant!                                                 |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
	printf("Donnez la date de l'emprunt :\n");
	rempliredate(&(*(*emp+nbr-1))->dateEmprunt);
}
void ModifierUnEmprunt(EMPRUNT***emp,int nbr,LIVRE**lv,int nbrlv,ADHERENT**adh,int nbradh){
	if(nbr == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas d'emprunt enregistre a modifier!              |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	int code,code2,r,r1,test1,test = 0;
	char rep;
	printf("+-------------------------------------------------+\n");
	printf("|Saisissez le code d'emprunt a modifier :          |\n");
	printf("+-------------------------------------------------+\n");
	while(test == 0){
		scanf("%d",&code);
		r = ExisteEmprunt(&*emp,code,nbr);
		if(r == 1 ){
			//Modifier le codelivre : 
			do{
				printf("Voulez-vous modifier le code livre emprunté dont le code est (%d)?(Y/N)\n",code);
				rep = getch();
			}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
			if(toupper(rep) == 'Y'){
				for(int i=0;i<nbr;i++){
					if( (*(*emp+i))->code ==code){
						
						AfficherLesLivresEnLigne(lv,nbrlv);
						test1 = 0;
						while(test1 == 0){
							printf("Donner le nouveau code du livre :\n");
							scanf("%d",&code2);
							r1 = Existe(&lv,code2,nbrlv);
							if(r1 == 1 ){
								(*(*emp+i))->CodeLivre = code2;
								test1 = 1;
							}else{
								printf("+------------------------------------------------------------------------+\n");
								printf("|Erreur : Code inexistant!                                                 |\n");
								printf("+------------------------------------------------------------------------+\n");
							}
						}
						break;
					}
				}
			}
			//modifier le code adherent
			do{
				printf("Voulez-vous modifier le code adherent emprunteur dont le code est (%d)?(Y/N)\n",code);
				rep = getch();
			}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
			if(toupper(rep) == 'Y'){
				for(int i=0;i<nbr;i++){
					if( (*(*emp+i))->code ==code){
						AfficherLesAdherentEnLigne(adh,nbradh);
						test1 = 0;
						while(test1 == 0){
							printf("Donner le nouveau code de l'adherent emprunteur :\n");
							scanf("%d",&code2);
							r1 = ExisteAdh(&adh,code2,nbradh);
							if(r1 == 1 ){
								(*(*emp+i))->CodeAdherent = code2;
								test1 = 1;
							}else{
								printf("+------------------------------------------------------------------------+\n");
								printf("|Erreur : Code inexistant!                                                 |\n");
								printf("+------------------------------------------------------------------------+\n");
							}
						}
						break;
					}
				}
			}
			//modifier le date emprunt
			do{
				printf("Voulez-vous modifier le date d'emprunt dont le code est (%d)?(Y/N)\n",code);
				rep = getch();
			}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
			if(toupper(rep) == 'Y'){
				for(int i=0;i<nbr;i++){
					if( (*(*emp+i))->code ==code){
						printf("Donner la nouvelle date d'emprunt :\n");
						rempliredate(&(*(*emp+i))->dateEmprunt);
						break;
					}
				}
			}
			printf("Modification effectuee!\n");
			test=1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Code inexistant!                                                 |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
}
void SupprimerUnEmprunt(EMPRUNT***emp,int nbr){
	if(nbr == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas d'emprunt enregistre a supprimer!!            |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	int code,r,test = 0;
	printf("+-------------------------------------------------+\n");
	printf("|Saisissez le code d'emprunt a supprimer :         |\n");
	printf("+-------------------------------------------------+\n");
	while(test == 0){
		scanf("%d",&code);
		r = ExisteEmprunt(&*emp,code,nbr);
		if(r == 1 ){
			for(int i=0;i<nbr;i++){
				if((*(*emp+i))->code == code){
					for(int j=i;j<nbr-1;j++){
						(*(*emp+j)) = (*(*emp+j+1));
					}
				}
			}
			printf("Suppression effectuee!\n");
			test=1;
		}else{
			printf("+------------------------------------------------------------------------+\n");
			printf("|Erreur : Code inexistant!                                                  |\n");
			printf("+------------------------------------------------------------------------+\n");
		}
	}
}
/*
	+-------------------------------------------+
	|    Les fonctions d'affichage emprunts      |
	+-------------------------------------------+
*/
void AfficherLesEmpunts(EMPRUNT**emp,int nbr,LIVRE**lv,int nbrlv,ADHERENT**adh,int nbradh){
	if(nbr == 0){
		printf("+-------------------------------------------------+\n");
		printf("|Pas d'emprunt enregistre!                         |\n");
		printf("+-------------------------------------------------+\n");
		return;
	}
	printf("+-----------------------------------------------------+\n");
	printf("|Affichage des emprunts :                              |\n");
	printf("+-----------------------------------------------------+\n");
	for(int i=0;i<nbr;i++){
		printf("|code : %d	\n",(*(emp+i))->code);
		for(int j=0;j<nbrlv;j++)
		{
			if((*(emp+i))->CodeLivre == (*(lv+j))->Code){
				printf("|Code livre : %d ; Titre : %s \n",(*(lv+j))->Code,(*(lv+j))->titre);
				break;
			}
		}
		for(int j=0;j<nbradh;j++)
		{
			if((*(emp+i))->CodeAdherent == (*(adh+j))->Code){
				printf("|code Adherent : %d ; Nom : %s ; Prenom : %s\n",(*(adh+j))->Code,(*(adh+j))->Nom,(*(adh+j))->Prenom);
				break;
			}
		}
		printf("|Date d'emprunt : ");
		afficherdate((*(emp+i))->dateEmprunt);
		putchar('\n');
		printf("+-------------------------------------------------+\n");
	}
}
void AfficherLesEmpruntEnLigne(EMPRUNT** emp,int nbr){
	if(nbr == 0){
			return;
	}
	printf("+---------------------------------------------------------------------------------+\n");
	printf("|Les Emprunt:                                                                       |\n");
	printf("+---------------------------------------------------------------------------------+\n");
	for(int i=0;i<nbr;i++){
		printf("|Code: %d\t",(*(emp+i))->code);
		printf("|Code livre: %d\t",(*(emp+i))->CodeLivre);
		printf("|Code adherent: %d",(*(emp+i))->CodeAdherent);
		printf("|Date d'emprunt : ");
		afficherdate((*(emp+i))->dateEmprunt);
		putchar('\n');
		printf("+-----------------------------------------------------------------------------+\n");
	}
}
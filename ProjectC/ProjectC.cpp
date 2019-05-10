#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
 
#include<string.h>
#include"MyLibrary.h"
#include"MyFunction.h"

void main(){
	FILE *flivreBin,*fadherentbin,*fEmployebin,*femprunt;
	char choix;
	int choixAction,choixActionPrincipale,choixActionadherent,choixActionEmprunt,choixActionEmploye,nbrEmprunt=0,nbrLivre =0,nbrEmploye = 0,nbrAdherent = 0;
	LIVRE** livres;
	ADHERENT** adherents;
	EMPLOYE** employes;
	EMPRUNT** emprunts;
	printf("Initialisation des variables ...\n");
	printf("Lecture des donnees livres...\n");
	OuvrireEnModeLecture(&flivreBin);
	Initialiser(flivreBin,&livres,&nbrLivre);
	fclose(flivreBin);
	printf("Lecture des donnees Adherents...\n");
	OuvrireEnModeLectureAdh(&fadherentbin);
	InitialiserAdh(fadherentbin,&adherents,&nbrAdherent);
	fclose(fadherentbin);
	printf("Lecture des donnees Employee...\n");
	OuvrireEnModeLectureEmp(&fEmployebin);
	InitialiserEmp(fEmployebin,&employes,&nbrEmploye);
	fclose(fEmployebin);
	printf("Lecture des donnees Emprunt...\n");
	OuvrireEnModeLectureEmprunt(&femprunt);
	InitialiserEmprunt(femprunt,&emprunts,&nbrEmprunt);
	fclose(femprunt);
	do{
		choixActionPrincipale = menuPrincipale();
		switch(choixActionPrincipale)
		{
			case 1:
				{
					choixAction = menulivre();
					switch(choixAction)
					{
						case 1:
							  {
									AfficherLesLivre(livres,nbrLivre);
							  }break;
						case 2:
							  {
									nbrLivre++;
									ReallocationListeDesLivres(&livres,nbrLivre);
									AjouterUnLivre(&livres,nbrLivre);
							  }break;
						case 3:
							  {
									AfficherLesLivresEnLigne(livres,nbrLivre);
									ModifierUnLivre(&livres,nbrLivre);
									AfficherLesLivresEnLigne(livres,nbrLivre);
							  }break;
						case 4:
							  {
									AfficherLesLivresCodesTitre(livres,nbrLivre);
									SupprimerUnLivre(&livres,nbrLivre);
									if(nbrLivre>0) nbrLivre--;
									AfficherLesLivresCodesTitre(livres,nbrLivre);
							  }break;
						case 5:
							  {
									TriListeDesLivres(&livres,nbrLivre);
									AfficherLesLivresEnLigne(livres,nbrLivre);
							  }break;
						case 6:
							  {
									RechercheLivre(&livres,nbrLivre);
							  }break;
						case 7:
							  {
									OuvrireFicherModeEcriture(&flivreBin);
									SauvegardeDesLivre(flivreBin,livres,nbrLivre);
									fclose(flivreBin);
						
							  }break;
						case 8:
							  {
									system("cls");
						
							  }break;
				 
				 
						default : printf("\n\n\tErreur : Choix impossible!\n");
					}
				}break;
			case 2 : 
				{	
					choixActionadherent = menuAdherent();
					switch(choixActionadherent)
					{
						case 1:
							  {
									AfficherLesAdherent(adherents,nbrAdherent);
							  }break;
						case 2:
							  {
									nbrAdherent++;
									ReallocationListeDesAdherent(&adherents,nbrAdherent);
									AjouterUnAdherent(&adherents,nbrAdherent);
							  }break;
						case 3:
							  {
									AfficherLesAdherentEnLigne(adherents,nbrAdherent);
									ModifierUnAdherent(&adherents,nbrAdherent);
									AfficherLesAdherentEnLigne(adherents,nbrAdherent);
							  }break;
						case 4:
							  {
									AfficherLesAdherentEnLigne(adherents,nbrAdherent);
									SupprimerUnAdherent(&adherents,nbrAdherent);
									if(nbrAdherent>0) nbrAdherent--;
									AfficherLesAdherentEnLigne(adherents,nbrAdherent);
							  }break;
						case 5:
							  {
									OuvrireFicherModeEcritureAdh(&fadherentbin);
									SauvegardeDesAdherent(fadherentbin,adherents,nbrAdherent);
									fclose(fadherentbin);
							  }break;
						case 6:
							  {
									system("cls");
						
							  }break;
				 
						default : printf("\n\n\tErreur : Choix impossible!\n");
					}
				}break;
			case 3 : 
				{	
					choixActionEmploye = menuEmploye();
					switch(choixActionEmploye)
					{
						case 1:
							  {
									AfficherLesEmployes(employes,nbrEmploye);
							  }break;
						case 2:
							  {
									nbrEmploye++;
									ReallocationListeDesEmploye(&employes,nbrEmploye);
									AjouterUnEmploye(&employes,nbrEmploye);
							  }break;
						case 3:
							  {
									AfficherLesEmployeeEnLigne(employes,nbrEmploye);
									ModifierUnEmployee(&employes,nbrEmploye);
									AfficherLesEmployeeEnLigne(employes,nbrEmploye);
							  }break;
						case 4:
							  {
									AfficherLesEmployeeEnLigne(employes,nbrEmploye);
									SupprimerUnEmploye(&employes,nbrEmploye);
									if(nbrEmploye>0) nbrEmploye--;
									AfficherLesEmployeeEnLigne(employes,nbrEmploye);
							  }break;
						case 5:
							  {
									OuvrireFicherModeEcritureEmp(&fEmployebin);
									SauvegardeDesEmployee(fEmployebin,employes,nbrEmploye);
									fclose(fEmployebin);
							  }break;
						case 6:
							  {
									system("cls");
						
							  }break;
				 
						default : printf("\n\n\tErreur : Choix impossible!\n");
					}
				}break;
			case 4 : 
				{	
					choixActionEmprunt = menuEmprunt();
					switch(choixActionEmprunt)
					{
						case 1:
							  {
									AfficherLesEmpunts(emprunts,nbrEmprunt,livres,nbrLivre,adherents,nbrAdherent);
							  }break;
						case 2:
							  {
									nbrEmprunt++;
									ReallocationListeDesEmprunt(&emprunts,nbrEmprunt);
									AjouterUnEmprunt(&emprunts,livres,nbrLivre,adherents,nbrAdherent,nbrEmprunt);
							  }break;
						case 3:
							  {
									AfficherLesEmpruntEnLigne(emprunts,nbrEmprunt);
									ModifierUnEmprunt(&emprunts,nbrEmprunt,livres,nbrLivre,adherents,nbrAdherent);
									AfficherLesEmpruntEnLigne(emprunts,nbrEmprunt);
							  }break;
						case 4:
							  {
									AfficherLesEmpruntEnLigne(emprunts,nbrEmprunt);
									SupprimerUnEmprunt(&emprunts,nbrEmprunt);
									if(nbrEmprunt>0) nbrEmprunt--;
									AfficherLesEmpruntEnLigne(emprunts,nbrEmprunt);
							  }break;
						case 5:
							  {
									OuvrireFicherModeEcritureEmprunt(&femprunt);
									SauvegardeDesEmprunts(femprunt,emprunts,nbrEmprunt);
									fclose(femprunt);
							  }break;
						case 6:
							  {
									system("cls");
						
							  }break;
				 
						default : printf("\n\n\tErreur : Choix impossible!\n");
					}
				}break;
			case 5 : 
				{	
					system("cls");
				}break;
			default : printf("\n\n\tError : Choix impossible!\n");
		}
		choix = SaisieReponse();
	}while(toupper(choix) != 'N');
	system("cls");
	printf("\n+---------------+");
	printf("\n|Fin du Programe|");
	printf("\n+---------------+");
	
	_getch();
}

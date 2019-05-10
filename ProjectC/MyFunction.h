//fichier
void OuvrireFicherModeEcriture(FILE**);
void OuvrireFicherModeEcritureAdh(FILE**);
void OuvrireFicherModeEcritureEmp(FILE**);
void OuvrireFicherModeEcritureEmprunt(FILE**);
void OuvrireEnModeLecture(FILE**);
void OuvrireEnModeLectureAdh(FILE**);
void OuvrireEnModeLectureEmp(FILE**);
void OuvrireEnModeLectureEmprunt(FILE**);
void SauvegardeDesLivre(FILE*,LIVRE**,int);
void SauvegardeDesAdherent(FILE*,ADHERENT**,int);
void SauvegardeDesEmployee(FILE*,EMPLOYE**,int);
void SauvegardeDesEmprunts(FILE*,EMPRUNT**,int);
void Initialiser(FILE*,LIVRE***,int*);
void InitialiserAdh(FILE*,ADHERENT***,int*);
void InitialiserEmp(FILE*,EMPLOYE***,int*);
void InitialiserEmprunt(FILE*,EMPRUNT***,int*);
//menu
char SaisieReponse();
int menuPrincipale();
int menulivre();
int menuAdherent();
int menuEmploye();
int menuEmprunt();
//allocation
void AllocationListeDesLivres(LIVRE***,int);
void AllocationListeDesAdherent(ADHERENT***,int);
void AllocationListeDesEmploye(EMPLOYE***,int);
void AllocationListeDesEmprunt(EMPRUNT***,int);
void ReallocationListeDesLivres(LIVRE***,int);
void ReallocationListeDesAdherent(ADHERENT***,int);
void ReallocationListeDesEmploye(EMPLOYE***,int);
void ReallocationListeDesEmprunt(EMPRUNT***,int);
//gestion du livre 
void TriListeDesLivres(LIVRE***,int);
void AjouterUnLivre(LIVRE***,int);
void ModifierUnLivre(LIVRE***,int);
void SupprimerUnLivre(LIVRE***,int);
void AfficherLesLivre(LIVRE**,int);
void AfficherLesLivresCodesTitre(LIVRE**,int);
void AfficherLesLivresEnLigne(LIVRE**,int);
void RechercheLivre(LIVRE***,int);
//gestion du ahderent 
void AjouterUnAdherent(ADHERENT***,int);
void ModifierUnAdherent(ADHERENT***,int);
void SupprimerUnAdherent(ADHERENT***,int);
void AfficherLesAdherent(ADHERENT**,int);
void AfficherLesAdherentEnLigne(ADHERENT**,int);
//gestion des employe
void AjouterUnEmploye(EMPLOYE***,int);
void ModifierUnEmployee(EMPLOYE***,int);
void SupprimerUnEmploye(EMPLOYE***,int);
void AfficherLesEmployes(EMPLOYE**,int);
void AfficherLesEmployeeEnLigne(EMPLOYE**,int);
//gestion les emprunt 
void AjouterUnEmprunt(EMPRUNT***,LIVRE**,int,ADHERENT**,int,int);
void ModifierUnEmprunt(EMPRUNT***,int,LIVRE**,int,ADHERENT**,int);
void SupprimerUnEmprunt(EMPRUNT***,int);
void AfficherLesEmpruntEnLigne(EMPRUNT**,int);
void AfficherLesEmpunts(EMPRUNT**,int,LIVRE**,int,ADHERENT**,int);
//test
int Existe(LIVRE***,int,int);
int ExisteAdh(ADHERENT***,int,int);
int ExisteEmp(EMPLOYE***,int,int);
//date
void afficherdate(DATE);
void rempliredate(DATE*);
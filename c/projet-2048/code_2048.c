/* IMPORTS */
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
//#include <conio.h>

#define DIM_JEU 4
#define	OBJECTIFS 2048
#define	TAUX_DE_2 5
#define getch() wgetch(stdscr)

/* Fonction d'initialisation de ncurses -------------------------------- */
void init_curses() {
  initscr();
  start_color();
  init_pair(1,COLOR_WHITE,COLOR_BLUE);   
  init_pair(2,COLOR_GREEN,COLOR_WHITE);
  init_pair(3,COLOR_RED,COLOR_WHITE);
  curs_set(0);
  noecho();
  keypad(stdscr,TRUE);
  nodelay(stdscr, TRUE);  // pour que la fonction getch() ne soit pas bloquante
}

/* Saisie des touches directionnelles -------------------------------- */
int SaisieChar(void) {
	int key = 0;
	while((key!=122)&&(key!=115)&&(key!=113)&&(key!=100)) { //UP - DOWN - LEFT - RIGHT
		key = getchar(); //haut Z (122) bas S (115) gauche Q (113) droite D (100)
	}
	return key;
}

char SaisieDirection(void) {
	int key;
	key = SaisieChar();
	switch (key) {
		case 122:
			return 'h';
		case 115:
			return 'b';
		case 113:
			return 'g';
		case 100:
			return 'd';
	}	
}

/* Fonction d'affichage des lignes -------------------------------- */
void AfficheLigne(char c1,char c2) {
	int i,j;
	for (i=0;i<=2*DIM_JEU;i=i+2) {
		for(j=0;j<=6*DIM_JEU;j++) {
			move(i,j);
			printw("%c",c1);
			refresh();
		}
	}

	for (i=0;i<2*DIM_JEU;i=i+2) {
		for (j=0;j<=6*DIM_JEU;j=j+6) {
			move(i+1,j);
			printw("%c",c2);
			refresh();
		}
	}
	move(15,0);
	printw("Z: haut,  S: bas,  Q: gauche,  D: droite.");
	refresh();
}

/* Fonction d'affichage des grilles -------------------------------- */
void AfficheGrille(int T[DIM_JEU][DIM_JEU],int score) {
	int i,j;
	for (i=0;i<DIM_JEU;i++) {
		for (j=0;j<DIM_JEU;j++) {
			if (T[i][j]!=0) {	
				move(2*i+1,6*j+1);
				printw("%d",T[i][j]);
				refresh();
			}
		}
	}
	move(10,0);
	printw("score: %d",score);
	refresh();
}

/* Fonction d'initialisation des grilles -------------------------------- */
void InitGrille(int T[DIM_JEU][DIM_JEU]) {
	int i,j;
	for (i=0;i<DIM_JEU;i++) {
		for (j=0;j<DIM_JEU;j++) {
			T[i][j]=0;
		}
	}
}

/* Fonction d'initialisation pour choisir les valeurs du début -------------------------------- */
int ValeurAleatoire(void) {
	int a;
	a=rand()%(TAUX_DE_2+1);
	if (a==0) {
		return 4;
	} else {
		return 2;
	}
}

void CopyTab(int T1[DIM_JEU][DIM_JEU],int T2[DIM_JEU][DIM_JEU]) {
	int i,j;
	for (i=0;i<DIM_JEU;i++) {
		for (j=0;j<DIM_JEU;j++) {
			T2[i][j]=T1[i][j];
		}
	}
}

/* Fonction de déplacement à droite -------------------------------- */
int RetasseDroite (int T[DIM_JEU][DIM_JEU]) {
	int i,j,k,l=0;
	for (i=0;i<DIM_JEU;i++) {	
		k = DIM_JEU-1;
		for (j=DIM_JEU-1;j>=0;j--) {
			if (T[i][j]!=0) {
				T[i][k]=T[i][j];
				if (k>j) {
					T[i][j]=0;
					l=1;
				}
				k--;
			}
		}
	}
	return l;
}

/* Fonction de déplacement à gauche -------------------------------- */
int RetasseGauche (int T[DIM_JEU][DIM_JEU]) {
	int i,j,k,l=0;
	for (i=0;i<DIM_JEU;i++) {
		k = 0;
		for (j=0;j<DIM_JEU;j++) {
			if (T[i][j]!=0) {
				T[i][k]=T[i][j];
				if (k<j) {
					T[i][j]=0;
					l=1;
				}
				k++;
			}
		}
	}
	return l;
}

/* Fonction de déplacement en haut -------------------------------- */
int RetasseHaut (int T[DIM_JEU][DIM_JEU]) {
	int i,j,k,l=0;
	for (j=0;j<DIM_JEU;j++) {
		k = 0;
		for (i=0;i<DIM_JEU;i++) {
			if (T[i][j]!=0)	{
				T[k][j]=T[i][j];
				if (k<i) {
					T[i][j]=0;
					l=1;
				}
				k++;
			}
		}
	}
	return l;
}

/* Fonction de déplacement en bas -------------------------------- */
int RetasseBas (int T[DIM_JEU][DIM_JEU]) {
	int i,j,k,l=0;
	for (j=0;j<DIM_JEU;j++) {
		k = DIM_JEU-1;
		for (i=DIM_JEU-1;i>=0;i--) {
			if (T[i][j]!=0) {
				T[k][j]=T[i][j];
				if (k>i) {
					T[i][j]=0;
					l=1;
				}
				k--;
			}
		}
	}
	return l;
}

/* Fonction de d'addition à droite -------------------------------- */
int AdditionneDroite(int T[DIM_JEU][DIM_JEU]) {
	int i,j,score=0;
	for (i=0;i<DIM_JEU;i++) {
		for (j=DIM_JEU-1;j>0;j--) {
			if (T[i][j]==T[i][j-1]) {	
				T[i][j]=T[i][j]+T[i][j-1];
				score+=T[i][j];
				T[i][j-1]=0;
			}
		}
	}
	return score;
}

/* Fonction de d'addition à gauche -------------------------------- */
int AdditionneGauche(int T[DIM_JEU][DIM_JEU]) {
	int i,j,score=0;
	for (i=0;i<DIM_JEU;i++) {
		for (j=0;j<DIM_JEU-1;j++) {
			if (T[i][j]==T[i][j+1]) {	
				T[i][j]=T[i][j]+T[i][j+1];
				score+=T[i][j];
				T[i][j+1]=0;
			}
		}
	}
	return score;
}

/* Fonction de d'addition en haut -------------------------------- */
int AdditionneHaut(int T[DIM_JEU][DIM_JEU]) {
	int i,j,score=0;
	for (i=0;i<DIM_JEU-1;i++) {
		for (j=0;j<DIM_JEU;j++) {
			if (T[i][j]==T[i+1][j]) {	
				T[i][j]=T[i][j]+T[i+1][j];
				score+=T[i][j];
				T[i+1][j]=0;
			}
		}
	}
	return score;
}

/* Fonction de d'addition en bas -------------------------------- */
int AdditionneBas(int T[DIM_JEU][DIM_JEU]) {
	int i,j,score=0;
	for (i=DIM_JEU-1;i>0;i--) {
		for (j=0;j<DIM_JEU;j++) {
			if (T[i][j]==T[i-1][j]) {	
				T[i][j]=T[i][j]+T[i-1][j];
				score+=T[i][j];
				T[i-1][j]=0;
			}
		}
	}
	return score;
}

void OrdiJoue(int T[DIM_JEU][DIM_JEU]) {
	int i,j;
	do {
		i=rand()%DIM_JEU;
		j=rand()%DIM_JEU;
	} while(T[i][j]!=0);
	T[i][j]=ValeurAleatoire();
}

/* Fonction de jeu de joueur -------------------------------- */
int JoueurJoue(int T[DIM_JEU][DIM_JEU],char direction,int *score) {
	int k1=0,k2=0,k3=0;
	switch (direction) {
		case 'h':
			k1=RetasseHaut(T);
			k2=AdditionneHaut(T);
			k3=RetasseHaut(T);
			*score=*score+k2;
			break;
		case 'b':
			k1=RetasseBas(T);
			k2=AdditionneBas(T);
			k3=RetasseBas(T);
			*score=*score+k2;
			break;
		case 'g':
			k1=RetasseGauche(T);
			k2=AdditionneGauche(T);
			k3=RetasseGauche(T);
			*score=*score+k2;
			break;
		case 'd':
			k1=RetasseDroite(T);
			k2=AdditionneDroite(T);
			k3=RetasseDroite(T);
			*score=*score+k2;
			break;	
	}
	return (k1+k2+k3);
}

/* Fonction pour jouer encore -------------------------------- */
int JoueEncore(int T[DIM_JEU][DIM_JEU]) { 	
	int i,j,k=0,lmax=0,cmax=0,lmin=0,cmin=0;
	for (i=0;i<DIM_JEU;i++) {
		for (j=0;j<DIM_JEU;j++) {
			if (T[i][j]>T[lmax][cmax]) {
				lmax=i;
				cmax=j;
			}
			if (T[i][j]<T[lmin][cmin]) {
				lmin=i;
				cmin=j;
			}
		}
	}
	if(T[lmax][cmax]==OBJECTIFS) {
		return 1;
	}
	if ((T[lmax][cmax]<OBJECTIFS)&&(T[lmin][cmin])==0) {
		return 0;
	}
	if ((T[lmax][cmax]<OBJECTIFS)&&(T[lmin][cmin])!=0) {
		int T_cp[DIM_JEU][DIM_JEU],k=0;
		CopyTab(T,T_cp);
		k=AdditionneBas(T_cp);
		k+=AdditionneHaut(T_cp);
		k+=AdditionneDroite(T_cp);
		k+=AdditionneGauche(T_cp);
		if (k==0) {
			return -1;
		} else {
			return 0;
		}
	}
}

/* Fonction d'initialisation -------------------------------- */
void InitJeu_2048(int T[DIM_JEU][DIM_JEU],int score) {
  	InitGrille(T);
  	OrdiJoue(T);
  	OrdiJoue(T);
  	AfficheLigne('-','|');
  	AfficheGrille(T,score);
} 

/* Fonction principale -------------------------------- */
int main (void) {
	srand(time(NULL));
	init_curses();     
  	bkgd(COLOR_PAIR(3)); 
 
  	int tab [DIM_JEU][DIM_JEU],l=0,s=0,score=0;
  	char direction;
  	InitJeu_2048(tab,score);
  	while(s==0) {
		clear();
		direction=SaisieDirection();
		l=JoueurJoue(tab,direction,&score);
		if (l>0) {
			OrdiJoue(tab);
		}
		s=JoueEncore(tab);
		AfficheLigne('-','|');
		AfficheGrille(tab,score);	
	}
	if (s==1) {
		move(12,0);
		printw("GAGNE !");
		refresh();
	}
	if (s==-1) {
		move(12,0);
		printw("PERDU");
		refresh();
	}
	sleep(10);
	endwin();   
  return 0;
}
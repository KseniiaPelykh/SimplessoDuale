#include <iostream>
#include <stdio.h>

#define Prec 0.000001
#define Inf 10000000000.
#define MaxVar 5000			// #colonne massime tableau
#define MaxCon 500			// #righe massime tableau

//	Dati input
long m;						// #vincoli
long n;						// #variabili
double B[MaxCon];			// i termini noti
double Mat[MaxCon][MaxVar];	// tableau
int Segno[MaxCon];			// segno vincoli

//	Variabili simplesso duale
long m1;					// #righe + variabili artificiale
long n1;					// #colonne + variabili slack
long n2;					// #colonne + variabili slack + variabile atricifiale
long Base[MaxCon];			// colonna in base per ogni riga
long Stato[MaxVar];			// riga per cui ogni colonna e in base, 0 = fuori base;
int Artif;					// vincolo artificiale? 0 = no > 0 = si

void Risolvi_Duale(void){
	/*Opt = 1;

	Aggiungi_Variabili_Slack();

	Calcola_Base_Iniziale();
	if (Opt != 1) return;

	Aggiungi_Variabile_Artificiale();

	while( i = Trova_Uscente() ) > 0) {
		j = Trova_Entrante(i);
		if (j == 0){
			Opt = -1;
			return;
		}
		Stato[Base[i]] = 0;
		Base[i] = j;
		Stato[j] = i;
		Pivot(i,j);
	}

	// verifiche soluzione illimitata*/
}

void Aggiungi_Variabili_Slack(void){
	n1 = n;
	int i, k;
	
	for (i = 1; i <= m; ++i){
		if (Segno[i] != 0){
			++n1;
			for (k = 0; k <= m; ++k){
				Mat[k][n1] = 0.0;
			}
			Mat[i][n1] = Segno[i];
		}
	}

	n2 = n1;
	m1 = m;
}

void Calcola_Base_Iniziale(void){
	int i,j;

	for (j = 0; j <= n1; ++j) {
		Stato[j] = 0;
	}

	for ( i = 1; i <= m1; ++i ) {
		for ( j = n1; j>= 1; --j) {
			if (Mat[i][j] < -Prec); 
		}
	}
}

void main(void){
	int i, j;
	// lettura dati di input
	scanf("%ld %ld", &n, &m);	
	for (i = 0; i < m; i++) {
		scanf("%lf", &B[i]);
	}

	for (i = 0; i < m; i++){
		scanf("%d", &Segno[i]);
	}

	int num,pos;
	double value;

	for (i = 0; i < n; i++){
		scanf("%lf %d", &Mat[0][i], &num);
		for (j = 0; j < num; j++){
			scanf("%d %lf", &pos, &value);
			Mat[pos][i] = value;
		}
	}
	
	Risolvi_Duale();
	// stampa output
}


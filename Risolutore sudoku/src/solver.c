
#include <stdlib.h> 
#include <stdbool.h>
#include <stdio.h>

bool valueWorks(unsigned char(*problem)[9][9], int i, int j, int value) {
	// funzione che determina se un dato valore value va bene per la cella in posizione i,j della matrice problem
	
	
	for (int z=0;z<9;z++) {
		if ((*problem)[i][z]==value || (*problem)[z][j]==value) { 
			return false; //restituisce false se incontra un valore nella riga i o nella colonna j
		}
	}
	
	int r,c;
	int rReg=(i/3)*3; //individuo gli indici di riga iniziali della regione
	int cReg=(j/3)*3; //individuo gli indici di colonna iniziali della regione
	
	for (r=0;r<3;r++){ //controllo la regione
		for (c=0;c<3;c++){
			if((*problem)[rReg+r][cReg+c]==value) { 
				return false; //restituisce false se il valore è già presente in una cella della regione
			}
		}
	}
	
	return true;
}




int cellCheck(unsigned char (*problem)[9][9], int i, int j) //la funzione ricorsiva che usa i valori di ritorno 0 (ritenta) e 1 (corretto).
{
	
	if (i ==9) { 
		return 1; //caso base 1: ho superato l'ultima cella della griglia (il sudoku è corretto e chiudo tutte le ricorsioni a catena)
	}
	
	if ((*problem)[i][j] != 0) { //caso 2: mi trovo in una cella indizio, vado alla cella successiva
		if (j<8) {
			return cellCheck(problem, i, j+1); 
		}
		return cellCheck(problem, i+1, 0);
		
	} else {
		for (int k=1;k<10;k++) { //scorro la lista dei possibili valori per la cella corrente
			if (valueWorks(problem,i,j,k)){ //se il valore non va bene il ciclo for va direttamente al prossimo valore 
				(*problem)[i][j]=k;
				if (j<8)  { //se non mi trovo nell'ultimo elemento dell'array vado all'elemento successivo
					if (cellCheck(problem,i,j+1)) {
						return 1;//se la cella successiva va bene chiudo anche la cella corrente, altrimenti continua l'iterazione
					}
					
				} else {
					if (cellCheck(problem,i+1,0)){ // se mi trovo nell'ultimo elemento dell'array vado al primo elemento dell'array successivo
						return 1;
					}
				}
			}
		}
		(*problem)[i][j]=0; //se al termine dell'iterazione sono arrivata qui vuol dire che non c'erano valori possibili per la cella corrente, quindi la setto nuovamente a 0
		return 0;	
	}	
}


void solve(unsigned char (*problem)[9][9])
{
	if (!cellCheck(problem,0,0)) {
		printf("No solution found :(");
	}
}


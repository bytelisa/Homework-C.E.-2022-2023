# Homework 1: Risolutore Sudoku

<img alt="points bar" align="right" height="36" src="../../blob/status/.github/graphics/points-bar.svg" />

L'obiettivo di questo homework è realizzare un programma che sia in grado di risolvere delle griglie del Sudoku.

Il sudoku è un gioco di logica nel quale viene proposta una griglia di 9×9 celle, ciascuna delle quali può contenere un
numero da 1 a 9, oppure essere vuota.
La griglia è suddivisa in 9 righe orizzontali, 9 colonne verticali e in 9 "sottogriglie" di 3×3 celle contigue. Queste
sottogriglie sono delimitate da bordi in neretto e chiamate regioni.

Lo scopo del gioco è quello di riempire le caselle bianche con numeri da 1 a 9 in modo tale che in ogni riga, in ogni
colonna e in ogni regione siano presenti tutte le cifre da 1 a 9, quindi senza ripetizioni.

![](.github/graphics/sudoku.jpg)

## Organizzazione del repository

Il repository che è stato appena creato contiene un _codice di avvio_, organizzato nel modo seguente:

* `Makefile`: permette di generare il programma `sudoku` che risolve una griglia
* `src/problems.h`: contiene 4 griglie da risolvere, di difficoltà crescente. Queste griglie verranno usate per la
  valutazione finale
* `src/main.c`: è dove inizia il programma. Il codice contenuto nel file si preoccupa già di:
    * recuperare un parametro numerico da riga di comando (nell'intervallo [1, 4]) che seleziona una delle quattro
      righe;
    * invocare la funzione `solve()`;
    * stampare la griglia risolta;
    * validare la soluzione.
* `src/validator.c`: contiene la funzione che verifica se una soluzione del sudoku è corretta
* `src/solver.c`: è dove dovete implementare la vostra soluzione. La firma della funzione `solve()` è già presente.

## Regole dell'homework e punti

È possibile totalizzare un **massimo di 3 punti** con questo homework. I punti sono assegnati come segue:

1. Se la soluzione è in grado di risolvere la griglia numero 1, si ottengono 0.25 punti;
2. Se la soluzione è in grado di risolvere la griglia numero 2, si ottengono 0.25 punti;
3. Se la soluzione è in grado di risolvere la griglia numero 3, si ottengono 0.5 punti;
4. Se la soluzione è in grado di risolvere la griglia numero 4, si ottengono 0.5 punti;
5. Se la soluzione è in grado di risolvere almeno una griglia e compila senza alcun warning, si ottengono 0.5 punti.

_Al termine della consegna_, tutte le soluzioni consegnate in grado di risolvere tutte le griglie verranno testate su una
macchina di riferimento. Le **quattro più veloci** (in termini di tempo di calcolo) riceveranno 1 punto.

Ogni volta che viene effettuato il push di un commit su questo repository, viene testata la soluzione proposta su tutte
le quattro griglie di riferimento. La barra del punteggio comunica qual è il punteggio attuale dell'homework.
Ovviamente, il massimo punteggio indicato è di 2 punti, poiché non si considera in questa fase il punto legato alle
prestazioni della soluzione.

Nel test delle soluzioni (sia automatizzato che manuale in fase di validazione) viene utilizzato un *timeout di 1 minuto*.
Se il programma impiega più tempo a trovare una soluzione per la griglia, la soluzione sarà comunque considerata errata.

**Attezione**: l'indicazione dei punti fornita dal sistema è _indicativa_: il punteggio finale verrà confermato dal
docente dopo una verifica della soluzione.

**Attezione 2**: potete modificare tutto il codice, come preferite. Sappiate che, in fase di verifica e di test delle
prestazioni, il contenuto dei file `Makefile`, `src/main.c`, `src/problems.h` e `src/validator.c` verrà ripristinato
a quello del commit iniziale. Potete quindi anche testare la vostra soluzione su altre griglie, ma quelle che verranno
usate per la verifica e validazione delle soluzioni sono quelle proposte nel repository.

**Attezione 3**: tutte le soluzioni consegnate verranno sottoposte ad un _software automatico di antiplagio_, in grado
di confrontare la _semantica_ del codice con quello di tutte le soluzioni proposte e di tutto il codice ospitato online
sui principali siti di hosting di codice sorgente. A discrezione del docente, il punteggio può essere annullato. Quindi:
1. Non è consentito copiare le soluzioni tra di voi;
2. Non è consentito scaricare soluzioni da Internet e riadattarle.

È ovviamente consentito cercare algoritmi, studiare soluzioni possibili, farsi ispirare da tecniche algoritmiche.
L'importante è che l'implementazione sia di vostro pugno.

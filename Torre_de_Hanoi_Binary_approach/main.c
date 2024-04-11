#include <stdio.h>
#include <math.h>

/**
 * Solves the Tower of Hanoi problem using a binary approach.
 *
 * @param quantityOfDiscs Number of discs in the tower.
 */
 
void resolveHanoiBinary(int quantityOfDiscs) {
    int P[quantityOfDiscs];
    for (int i = 1; i <= quantityOfDiscs; i++) {
        P[i]='A';
    }

    int dir = (quantityOfDiscs % 2 == 0) ? 0 : 1;

    int maxMoviments = pow(2, quantityOfDiscs) - 1;

    int i;
    for(int j = 1; j <= maxMoviments; j++) {
        i=0;
        while(!(j >> i & 1)) i++;
        printf("\tMover o disco %d ", ++i);
        printf("da coluna %c ", P[i]);
        printf("para coluna %c\n",
            P[i] = 'A' + (P[i] - 'A' + 1 + (i & 1 ? dir : 1-dir)) %3);
    }
}


int main() {
    int quantityOfDiscs;

    printf("Qual a Quantidade de Discos na torre?\n");
    scanf ("%d", &quantityOfDiscs);

    printf("\nA sequencia de movimentos a seguir e':\n");
    resolveHanoiBinary(quantityOfDiscs);

    system ("pause");
    return 0;
}


#include <stdio.h>
#include <time.h>

void torre(int, char, char, char);
void HanoiBinario(int n, char inicial, char Final);


int main()
{
    int num;
    clock_t T;


    printf("Qual a Quantidade de Discos na torre?\n");
    scanf ("%d", &num);
    printf("\nA sequencia de movimentos a seguir e':");

    printf("\n\nVersao Recursiva:\n");
    T = clock();
    torre(num, 'A', 'B', 'C');
    T = clock() - T;
    printf("\nO tempo de execucao do algoritmo recursivo foi de %.3lf segundos\n",((double)T/ CLOCKS_PER_SEC));

    printf("\n\nVersao Interativa binaria:\n");
    T = clock();
    HanoiBinario(num,'A','C');
    T = clock() - T;
    printf("\nO tempo de execucao do algoritmo interativo foi de %.3lf segundos\n\n",((double)T/ CLOCKS_PER_SEC));

    system ("pause");
    return 0;
}

void torre(int n, char posteInicial, char posteAuxiliar, char posteFinal)
{
    if (n == 1)
    {
       printf("\tMover disco 1 da coluna %c para coluna %c\n", posteInicial, posteFinal);
        return;
    }
    torre(n-1, posteInicial, posteFinal, posteAuxiliar);
        printf("\tMover disco %d da coluna %c para coluna %c\n", n, posteInicial, posteFinal);
    torre(n-1, posteAuxiliar, posteInicial, posteFinal);
}

void HanoiBinario(int n, char inicial, char Final)
{
int limite, i, x, dir;
int P[n];
for (i=1;i<=n;i++)
P[i]=inicial;
dir=(n&1)!=(Final-inicial ==1 || Final-inicial==-2);
limite=(1<<n)-1;
for(x=1;x<=limite;x++){
i=0;
while(!(x>>i&1)) i++;
printf("\tMover o disco %d ", ++i);
printf("da coluna %c ", P[i]);
printf("para coluna %c\n",
    P[i]='A'+(P[i]-'A'+1+(i&1?dir:1-dir))%3);
}
}

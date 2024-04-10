#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Estrutura para elementos da pilha
struct elemento{
	char expressao;
	int peso;
	struct elemento *prox;
};

typedef struct elemento *Pilha;
typedef struct elemento Elem;

// Função para criar uma pilha vazia
Pilha* cria_Pilha(){
	Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
	if(pi != NULL)
		*pi = NULL;
		return pi;
}
// Função para inserir um elemento na pilha
void insere_pilha (Pilha *pi, char Ex, int P){
	if(pi == NULL) {printf("Erro de criação\n"); return;}
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) {printf("Erro de Alocação\n"); return;}
	no->expressao = Ex;
	no->peso = P;
	no->prox = (*pi);
	*pi = no;
}
// Função para remover o topo da pilha
char remove_No(Pilha *pi){
	char chac;
	if(pi == NULL) {printf("Erro de criação\n"); return;}
	if((*pi) == NULL) {return '0';}
	Elem *no = *pi;
	chac=no->expressao;
	*pi = no->prox;
	free(no);
	return chac;
}
// Função para imprimir os elementos da pilha
void imprime(Pilha *pi){
	Elem *no = *pi;
	if ((*pi) == NULL){printf("pilha vazia");return;}
	while((*pi) != NULL){
		printf("%c", no->expressao);
		*pi = (*pi)->prox;
		no = *pi;
	}
}
// Função para retornar o topo da pilha
char Ver_topo(Pilha* pi){
	char chac;
	if(pi == NULL) {printf("Erro de criação\n"); return;}
	if((*pi) == NULL) {return '0';}
	Elem *no = *pi;
	chac=no->expressao;
	return chac;
}
// Função para liberar a memória utilizada pela pilha
void libera_Pilha (Pilha* pi){
	if(pi != NULL){
		Elem* no;
		while((*pi) != NULL){
			no = *pi;
			*pi = (*pi)->prox;
			free(no);
		}
		free(pi);
	}
}

// Função de análise sintática
/***** REf. https://youtu.be/9GGJH2sjOac ***********/

void analiseLexica(char *expre);
void analiseSintatica(char *expre);


void analiseSintatica(char *expre){
int tam = strlen(expre);
char pos[300];
Pilha *conta;
conta = cria_Pilha();
char teste, cont=0;

int i,j;
for (i = j = 0; i < tam; i++){

	switch(expre[i]){

	case '(':
	insere_pilha(conta,expre[i], 1);
	break;

	case ')':
	while( (teste = remove_No(conta)) != '(' ){pos[j]=teste; j++;};
	break;

	case '^':
	while((	teste = Ver_topo(conta)) != '0' &&
			teste != '(' &&
			teste != '/' &&
			teste != '*' &&
			teste != '+' &&
			teste != '-' &&
			teste != '>' &&
			teste != '<' &&
			teste != '=' &&
			teste != '#' &&
			teste != '.' &&
			teste != '|' ){
			pos[j]=teste; j++;remove_No(conta);}
	insere_pilha(conta,expre[i], 6);
	cont++;
	break;

	case '+':
	case '-':
	while((	teste = Ver_topo(conta)) != '0' &&
			teste != '(' &&
			teste != '>' &&
			teste != '<' &&
			teste != '=' &&
			teste != '#' &&
			teste != '.' &&
			teste != '|'){
	pos[j]=teste; j++;remove_No(conta);}
	insere_pilha(conta,expre[i], 4);
	cont++;
	break;

	case '/':
	case '*':
	while((	teste = Ver_topo(conta)) != '0' &&
			teste != '(' &&
			teste != '+' &&
			teste != '-' &&
			teste != '>' &&
			teste != '<' &&
			teste != '=' &&
			teste != '#' &&
			teste != '.' &&
			teste != '|' ){
			pos[j]=teste; j++;remove_No(conta);}
	insere_pilha(conta,expre[i], 5);
	cont++;
	break;

	case '>':
	case '<':
	case '=':
	case '#':
	while((	teste = Ver_topo(conta)) != '0' &&
			teste != '(' &&
			teste != '.' &&
			teste != '|' ){
			pos[j]=teste; j++;remove_No(conta);}
	insere_pilha(conta,expre[i], 3);
	cont++;
	break;

	case '.':
	while((	teste = Ver_topo(conta)) != '0' &&
			teste != '(' &&
			teste != '|' ){
			pos[j]=teste; j++;remove_No(conta);}
	insere_pilha(conta,expre[i], 2);
	cont++;
	break;

	case '|':
	while((	teste = Ver_topo(conta)) != '0' &&
			teste != '('){
			pos[j]=teste; j++;remove_No(conta);}
	insere_pilha(conta,expre[i], 1);
	cont++;
	break;

	default:
		if(cont>1){
		printf("Syntax Error!\n"); return;
		}
		else if (expre[i]>='A' && expre[i]<='Z' ||
			expre[i]>='a' && expre[i]<='z' ||
			expre[i]>='0' && expre[i]<='9'){
		pos[j]=expre[i];j++;cont=0;}
		else{
			printf("Lexical Error!\n"); return;
		}

	}
	}

while( (teste = remove_No(conta)) != '0'){pos[j]=teste; j++;};
pos[j]='\0';

int w=0;
while(pos[w] != '\0'){
	if (pos[w] == '(' || pos[w] == ')'){ printf("Syntax Error!\n"); return;}
	w++;
}

printf("%s\n", pos);

libera_Pilha(conta);

//Baseado nos conceitos aprendidos na viodeo aula do link:https://youtu.be/IPLzxX1Vibo
}
// Função principal
int main() {

	char expre[300];
	while (scanf("%s", &expre)!=EOF){
		analiseSintatica(expre);
		}
	return 0;
}


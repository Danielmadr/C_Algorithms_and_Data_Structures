## Documentação do Código para Análise Sintática e Conversão para Notação Pós-fixa

### Visão Geral
Este código implementa uma análise sintática de expressões matemáticas infixas e converte essas expressões para notação pós-fixa (ou pós-fixada) usando uma pilha. Ele suporta operadores matemáticos básicos, parênteses, operadores de comparação e operadores lógicos.

### Funcionalidades
- **Análise Léxica**:
  - Identifica operandos válidos (letras maiúsculas/minúsculas e números).
  - Verifica a presença de parênteses e operadores permitidos.

- **Análise Sintática**:
  - Utiliza uma pilha para verificar o balanceamento de parênteses.
  - Garante a correta ordem de operadores e operandos conforme regras estabelecidas.

- **Conversão para Notação Pós-fixa**:
  - Aplica o algoritmo Shunting Yard para converter a expressão de infixa para pós-fixa.
  - Mantém a precedência e associatividade dos operadores durante a conversão.

### Entrada
- Expressões matemáticas fornecidas como entrada.
- Operandos: letras (maiúsculas/minúsculas) e números.
- Parênteses: `(` e `)`.
- Operadores permitidos com suas prioridades específicas.

### Saída
- Para cada expressão:
  - Se estiver correta, imprime a expressão na notação pós-fixa.
  - Se houver erros léxicos, imprime "Lexical Error!".
  - Se houver erros de sintaxe, imprime "Syntax Error!".

### Restrições
- Não é permitida a presença de operadores unários, como o - em 4 * -2.
- Expressões que violarem essa restrição serão consideradas inválidas e resultarão em um erro sintático.

### Tabela de Prioridades dos Operadores
| Operador | Prioridade |
|----------|------------|
| `^`      | 6          |
| `*`, `/` | 5          |
| `+`, `-` | 4          |
| `>`, `<`, `=`, `#` | 3 |
| `AND (.)` | 2        |
| `OR (\|)`  | 1        |

Nesta tabela:

- O operador `^` tem a maior prioridade (6).
- Os operadores `*` e `/` têm prioridade 5.
- Os operadores `+` e `-` têm prioridade 4.
- Os operadores `>`, `<`, `=`, `#` têm prioridade 3.
- O operador `AND (.)` tem prioridade 2.
- O operador `OR (|)` tem a menor prioridade (1).

Essa tabela é utilizada para determinar a ordem correta de avaliação dos operadores durante a análise sintática e conversão da expressão para notação pós-fixa.


### Estruturas e Funções

#### Estrutura da Pilha (`struct elemento`)
```c
struct elemento {
    char expressao;
    int peso;
    struct elemento *prox;
};
```
- `expressao`: Armazena um caractere representando um operando, operador ou parêntese.
- `peso`: Indica o peso do operador para determinar a precedência na pilha.
- `prox`: Ponteiro para o próximo elemento na pilha.

#### `typedef` para `Pilha` e `Elem`
```c
typedef struct elemento *Pilha;
typedef struct elemento Elem;
```
- `Pilha`: Tipo abstrato de dados que representa uma pilha.
- `Elem`: Alias para `struct elemento`.

#### Funções da Pilha

- `Pilha* cria_Pilha()`: Cria e retorna uma nova pilha vazia.
- `void insere_pilha(Pilha *pi, char Ex, int P)`: Insere um novo elemento na pilha com um caractere (`Ex`) e seu peso (`P`).
- `char remove_No(Pilha *pi)`: Remove e retorna o elemento do topo da pilha.
- `void imprime(Pilha *pi)`: Imprime todos os elementos da pilha (para fins de depuração).
- `char Ver_topo(Pilha* pi)`: Retorna o caractere no topo da pilha sem removê-lo.
- `void libera_Pilha(Pilha* pi)`: Libera toda a memória alocada para a pilha.

#### Funções Principais

- `void analiseSintatica(char *expre)`: Realiza a análise sintática da expressão `expre`, convertendo-a para notação pós-fixa.

### Funcionamento da Análise Sintática

1. **Inicialização**:
   - Cria-se uma pilha vazia (`conta`) para ajudar na conversão para notação pós-fixa.

2. **Processamento Caractere por Caractere**:
   - A função `analiseSintatica` percorre cada caractere da expressão `expre`.
   - Para cada caractere, decide se é um operando, operador ou parêntese, e age de acordo.

3. **Inserção e Remoção da Pilha**:
   - Ao encontrar operadores ou parênteses, decide a ordem de inserção/remoção na pilha com base no seu peso/precedência.
   - Operadores de maior peso têm maior precedência na pilha.

4. **Conversão para Notação Pós-fixa**:
   - Ao final da análise, os elementos restantes na pilha são removidos na ordem correta para construir a notação pós-fixa.

5. **Tratamento de Erros**:
   - Verifica se a expressão possui erros léxicos (caracteres inválidos) ou erros de sintaxe (parênteses desbalanceados).

### Exemplos de Uso

- A função `main` lê expressões de entrada e chama `analiseSintatica` para cada uma delas.
- A saída é a expressão convertida para notação pós-fixa ou uma mensagem de erro se houver problemas na análise.

### Testes Recomendados

- Teste com expressões simples.
- Teste com parênteses balanceados e desbalanceados.
- Teste com diferentes operadores matemáticos e lógicos.
- Teste com caracteres inválidos para verificar tratamento de erros.

### Limitações

- Este código não lida com números ou funções matemáticas complexas.
- É limitado a expressões infixas simples com operadores básicos.

### Conclusão
Esta documentação oferece uma visão geral do funcionamento e dos componentes do código, bem como orientações sobre testes recomendados. Certifique-se de ajustar e expandir conforme necessário, dependendo dos requisitos específicos do projeto ou da aplicação onde este código será utilizado.
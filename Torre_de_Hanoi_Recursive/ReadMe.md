# Solução Recursiva para o Problema das Torres de Hanói

Este programa resolve o **Problema das Torres de Hanói** utilizando uma abordagem recursiva. O usuário insere o número de discos, e o programa exibe a sequência de movimentos necessários para resolver o problema.

## Como Usar

1. Compile o código-fonte usando um compilador C (por exemplo, GCC).
2. Execute o programa gerado.
3. Insira o número de discos na torre quando solicitado.
4. O programa exibirá a sequência de movimentos para resolver o problema.

## Função `solveHanoiTowers`

A função `solveHanoiTowers` é responsável por mover os discos entre as colunas (pilares) A, B e C. Ela recebe os seguintes parâmetros:

- `quantityOfDiscs`: Número de discos na torre.
- `initialPole`: Pilar inicial (A).
- `auxPole`: Pilar auxiliar (B).
- `finalPole`: Pilar final (C).

A função utiliza a recursão para resolver o problema, movendo os discos conforme necessário.

## Observações

- Este código é apenas para fins de demonstração e não deve ser usado em produção.
- Sugiro implementar tratamento de erros e validação de entrada para tornar o programa mais robusto.

## Bugs Conhecidos

Nenhum bug conhecido no momento.

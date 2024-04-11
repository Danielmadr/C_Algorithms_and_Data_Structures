### Algoritmo para Resolver a Torre de Hanói (sem Recursão)

#### Visão Geral
O problema da Torre de Hanói consiste em mover uma pilha de discos de um pino inicial para um pino de destino, usando um pino intermediário como auxiliar. As regras são simples: apenas um disco pode ser movido de cada vez, e um disco maior nunca pode ficar em cima de um menor.

#### Funcionalidade
1. **`resolveHanoiBinary(int n)`**: Esta função resolve o problema das Torres de Hanói para `n` discos. Ela utiliza uma abordagem baseada em movimentos binários para determinar as etapas necessárias para mover os discos. O estado atual das torres é mantido em um array `P[]` que representa a torre em que cada disco está.

2. **`main()`**: A função principal do programa solicita ao usuário o número de discos desejado e imprime a sequência de movimentos necessários para resolver o problema das Torres de Hanói com a quantidade especificada de discos.

#### Estratégia de Resolução
- O algoritmo utiliza a técnica de simulação com base nos movimentos binários para determinar a ordem dos discos a serem movidos.
- Cada movimento é identificado usando operações de bitshift (`j >> i & 1`) para determinar qual disco deve ser movido em cada etapa.

#### Detalhes Técnicos
- A torre de origem é representada como 'A', a torre intermediária como 'B' e a torre de destino como 'C'.
- O número máximo de movimentos é calculado como `pow(2, n) - 1`, onde `n` é o número de discos.
- A lógica de movimento de disco é implementada dentro de um loop principal que executa o número máximo de movimentos possíveis.
- Os movimentos de cada disco são impressos na tela conforme são executados.

#### Entrada e Saída
- A entrada é o número de discos desejado pelo usuário.
- A saída é a sequência de movimentos necessários para resolver o problema das Torres de Hanói com a quantidade especificada de discos.

#### Possíveis Melhorias
- Melhorar a legibilidade e a eficiência do código.
- Adicionar validações para garantir que o usuário insira um número válido de discos.
- Implementar uma abordagem iterativa ou recursiva mais clara e eficiente para a resolução do problema.

### Exemplo de Uso
```plaintext
Qual a Quantidade de Discos na torre?
3

A sequencia de movimentos a seguir e':
        Mover o disco 1 da coluna A para coluna B
        Mover o disco 2 da coluna A para coluna C
        Mover o disco 1 da coluna B para coluna C
        Mover o disco 3 da coluna A para coluna B
        Mover o disco 1 da coluna C para coluna A
        Mover o disco 2 da coluna C para coluna B
        Mover o disco 1 da coluna A para coluna B
```

### Observação
Certifique-se de compilar e executar o código em um ambiente adequado, como um compilador C/C++ padrão.
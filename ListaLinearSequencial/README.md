# O que é uma lista linear sequencial e como é implementada?

Uma lista linear sequencial é uma lista linear, onde cada elemento conta com um sucessor e predecessor, em que as posições lógicas dos elementos coincidem com as posições físicas (em memória). A implementação dessa estrutura pode ser observada em main.cpp.

# Por que precisamos de um indicador de número de elementos?

Como a implementação utiliza um arranjo no qual a memória é alocada antes da inserção dos elementos da estrutura, o indicador é necessário para manter controle sobre quais posições estão realmente ocupadas por elementos válidos.

# Como fazer uma busca sequencial simples para uma dada chave?

Basta utilizar um loop para iterar sobre os elementos da lista até encontrar (ou não) a posição da chave passada.

# Como inserir novos elementos na lista?

Dada uma determinada posição, é necessário passar todos os elementos a partir desta posição para a direita e então substituir o elemento antigo da posição pelo novo.

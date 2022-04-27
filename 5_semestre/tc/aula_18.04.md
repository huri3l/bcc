# Aula 18.04 - Conceitos matemáticos e sua relação com a programação
https://github.com/huri3l/bcc

## Conjuntos
É uma coleção de zero ou mais objetos chamados de elementos. Podem ser representados de diversas formas, sendo a mais comum entre as chaves. Exemplo: {5, 12, 21}.
## Elementos
Os elementos em si são algo que pertence ao conjunto, podendo ser qualquer tipo de objeto (número, símbolo, conjuntos…).
Existem alguns símbolos para facilitar o uso e as lógicas relacionadas aos elementos e seus conjuntos.
* ∈ indica que o elemento pertence ao conjunto (pertinência): 12 ∈ {5, 12, 21};
* ∉ indica que o elemento não pertence ao conjunto (não-pertinência): 9 ∉ {5, 12, 21};
* ⊆ indica que é um subconjunto. B ⊆ A (todos os elementos de B estão em A também);
* ⊂ indica que está contido. A ⊃ B.
## Conjunto finitos e infinitos
Refere-se ao tamanho de um conjunto.
* **Conjunto finito:** Esse tipo de conjunto contém uma quantidade precisa de elementos: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
* **Conjunto infinito:** Contém uma quantidade infinita de elementos. {…, -2, -1, 0, 1, 2, …};
* **Conjunto vazio:** Conjunto que contém 0 elementos. Representado por ∅.


## Anotações
Abstrações de C quanto à estrutura de dados
* Em C, o tipo bool não existe. Para representar valores verdadeiros ou falsos, o número 0 é considerado falso. Qualquer coisa que não seja 0 é verdadeiro. Chars, por exemplo, são abstrações de números. Então, desde que sua sequência de bits não resulte em todos os bits 0, é verdadeiro. Isso é útil pois as condicionais de IF exigem um retorno booleano, como conhecemos em linguagens mais modernas, feature que veio inclusa no C++. Entretanto, até em C++, não passa de uma abstração, pois no final é convertido para 0 e 1 no compilador;
* NULL também é uma abstração. Pois NULL, é basicamente um ponteiro que não aponta para nada, para nenhum endereço de memória. Entretanto, na prática, o NULL aponta sim para um endereço de memória, porém é um endereço de memória “inválido”, reservado pelo sistema, para avisar que ali não há valor nenhum. O funcionamento segue o mesmo, entretanto, não passa de uma abstração, pois na prática, está sim, apontando para um endereço de memória.


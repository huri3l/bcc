# Aula 25.04 - Conceitos Fundamentais
https://github.com/huri3l/bcc
## Linguagens Formais: Léxica, Sintaxe e Semântica
As linguagens podem ser **entidades livres**, sem significado associado (um comando). 
Também podem ser **entidades significativas**, onde consideram a interpretação de seu significado (um programa).
### Léxica
* Trata do conjunto de símbolos da linguagem;
* Processa entradas de forma a reconhecer símbolos do alfabeto que pertençam uma linguagem ou não, para reconhecer erros;
* Produz como saída símbolos denominados "lexemas" ou "tokens" a serem manipulados pela sintaxe.
### Sintaxe
* Trata das propriedades livres da linguagem, como verificação gramatical;
* Manipula símbolos sem considerar o seu significado, apenas a sintaxe;
* Não considera a solução do programa, mas se o programa foi corretamente escrito.
### Semântica
* Busca prover significado para o programa de uma linguagem;
* Considera se o programa resolve o problema especificado;
* Não resolve erros relacionados à lógica.

## Cadeias e Linguagens
* **Alfabeto**: É qualquer conjunto finito não vazio de *símbolos*. É identificado pela letra grega Σ (sigma)
* **Símbolos**: São os elementos básicos do alfabeto
* **Cadeias de caracteres/símbolos**: Blocos fundamentais de símbolos

**Exemplos de cadeias do alfabeto**  
Σ1 = {0,1} -> 0, 1, 01  
Σ2 = {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z} -> a, p, ax, aabb

### Cadeia de caracteres sobre um alfabeto (string)
Sequência finita de símbolos daquele alfabeto. Por exemplo: w = 010001 é uma cadeia válida do alfabeto Σ1 = {0,1}

### Comprimento de uma cadeia
Define o número de símbolos que uma cadeia contém. É representado por |w| (não é módulo!), sendo w uma cadeia. No exemplo acima, o comprimento da cadeia w é 6.

### Cadeia de comprimento 0
É chamada de cadeia vazia, ou seja, uma cadeia que **não contém símbolos**. É representada pela letra grega ε (épsilon).

### Prefixo
Compreende uma sequência de símbolos iniciais de uma cadeia. Por exemplo, a cadeia p = {010} é um prefixo da cadeia base w = **010**001

### Sufixo
Compreende uma sequência de símbolos finais de uma cadeia. Por exemplo, a cadeia z = {001} é um sufixo da cadeia base w = 010**001**

### Subcadeia
Compreende um subconjunto consecutivo da cadeia base, incluindo prefixos e sufixos. Por exemplo: a cadeia z = {100} é uma subcadeia da base w = 0**100**01

### Exemplo de subcadeia, prefixos e sufixos para a cadeia w = abcde
* Prefixos: ε, a, ab, abc, abcd, abcde;
* Sufixos: ε, e, de, cde, bcde, abcde;
* Subcadeias: bc, bcd, cd, ...

### Linguagem
Compreende um conjunto de palavras/cadeias sobre um alfabeto.
Sendo Σ um alfabeto: 
* Σ* representa o conjunto de todas as palavras possíveis sobre o Σ;
* Σ^+ representa o conjunto de todas as palavras não vazia sobre o Σ.

O conjunto vazio (Ø) e o conjunto formado pela palavra vazia (ε) constituem linguagens sobre o alfabeto (Σ).  
Entretanto, Ø != {ε}  
A linguagem infinita é denominada uma linguagem que possui um número infinito de palavras. Por exemplo, o conjunto de palíndromos sobre um alfabeto (Σ).

### Ordenação lexicográfica
Corresponde à ordenação convencional tradicional: alfabética, numérica... Como o dicionário.  
Para o alfabeto Σ1 = {0, 1}, a ordenação lexicográfica é: {ε, 0, 1, 00, 01, 10, 11, 000, 001, ...}

### Concatenação
Corresponde a justaposição da cadeia x seguida pela cadeia y. 
* Considere as cadeias x = {x1, x2, ...} e y = {y1, y2, ...}, a concatenação, escrito xy, será: {x1, x2, ..., y1, y2, ...};
* Pode ser aplicada entre diferentes linguagens.

### Concatenação sucessiva
Corresponde a concatenação de uma palavra com ela mesma.
* Representada por w^n, onde n indica o número de concatenações sucessivas;
* Por exemplo: w^4 = wwww, w^1 = w, w^0 = ε.
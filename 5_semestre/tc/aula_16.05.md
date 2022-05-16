# Aula 16.05 - Representação de Autômatos

## Descrição Formal
A descrição formal busca descrever um autômato sem um gráfico.  
**Exemplo:**  
M4 = ( {s, q1, q2, r1, r2}, {a, b}, δ, s, {q1, r1} )  

**Composição:**
* Primeiro conjunto: Conjunto de Estados (serve para mostrar quais são os estados daquele autômato);
* Segundo conjunto: Conjunto do Alfabeto (os símbolos do autômato);
* Terceiro conjunto: A função de transição;
* Quarto conjunto: Estado inicial;
* Quinto conjunto: Estado(s) que pode(m) ser transicionado(s) diretamente do estado inicial.

Existe também o RESET, que é um símbolo que retorna o autômato ao Estado Inicial.
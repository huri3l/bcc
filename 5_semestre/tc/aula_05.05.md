# Aula 05.05 - 
## Definições
São a base para o desenvolvimento de teoremas. Descrevem os objetos e conceitos a serem considerados (modelos).  
Podem ser:
* Simples: Como uma simples descrição de um conjunto;
* Complexo: Descrição do conjunto + definições de segurança de um sistema criptográfico.  
É fundamental para a definição das regras de um objeto. Quando o objeto for definido, é possível propor enunciados matemáticos.  

## Enunciado matemático
Expressa as propriedades que um objeto pode possuir ou não. Deve ser preciso, sem qualquer dúvida ou ambiguidade.

## Prova
Argumento lógico convincente (irrefutável) de forma a comprovar que o enunciado é verdadeiro - “prova além de qualquer dúvida".

### Prova matemática
É o único método científico para comprovar se um enunciado é verdadeiro ou não.  
Algumas estratégias que podem ajudar a provar enunciados são:
* Ler detidamente e entender o enunciado a ser provado;
* Decompor o problema em partes menores e resolve-las individualmente;
* Empregar experiências e conhecimentos anteriores.  

**Exemplo**  
Prova matemática desenvolvida por decomposição
Como provar “P se e somente se Q”, onde P e Q são enunciados matemáticos
* Parte 1: 
“P somente se Q” -> se P é verdadeiro então Q também é -> P ⇒ Q
* Parte 2: 
“P se Q” -> se Q é verdadeiro então P também é -> P ⇐ Q
  * O que implica em “P⇐⇒Q”
  * Para provar os enunciados precisamos provar as partes 1 e 2 (verdadeiras)

**Tipos de provas**  
* **Por construção**: Diversos enunciados são encadeados de forma lógica e incremental. Ao final, o objetivo é demonstrar como construir o objeto do enunciado através do 
sequenciamento de enunciados;
* **Por contradição**: Partimos da premissa de que um teorema é falso. Mostrarmos que uma suposição leva a um resultado falso, significa que é uma contradição, e dessa forma, concluímos que o teorema é verdadeiro;
* **Por indução**: Busca-se mostrar que uma propriedade específica ocorre para todos os elementos de um conjunto. Se a propriedade vale para o 1º elemento: P(1), então vale para P(2), P(3)... O desenvolvimento ocorre em 2 partes:
  * Passo 1 (base): provamos que a propriedade é válida para o 1º elemento, digamos que seja i, ou seja, provamos verdadeira o enunciado para P(i);
  * Passo 2 (hipótese de indução): provamos que a propriedade permanece válida para o próximo elemento, P(i+1).  
Se ambos os passos forem verdadeiros, a propriedade P é válida para todo elemento i, indicando que o enunciado é verdadeiro.

## Anotações
* Realizar os exercícios postados no Moodle.
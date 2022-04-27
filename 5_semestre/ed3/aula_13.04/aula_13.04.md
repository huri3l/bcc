# Aula 13.04 - Análise do Custo dos Algoritmos
Aqui faremos a análise dos algoritmos de fibonacci implementados na aula anterior.  

## Custo computacional
**Por que um algoritmo funciona mais rápido que outro?**  
O custo computacional é medido pelo número de operações executadas pelo algoritmo para uma determinada entrada de dados.
O número de operações do fib recursivo é aproximadamente 2^(n-1), onde n é a entrada.

### Custo do Fibonacci dinâmico
**Relação das Operações**
| fib(n) | custo | repetições |
| --- | --- | --- |
| arr = [0,1,1] | 1 | 1 |
|	para i  de 3 até n, faça | 1 | n-3 |
|		arr[i] = arr[i-1] + arr[i-2] | 1 | n-3 |
| retorna arr[n] | 1 | 1 |

**Cálculo**  
Ct = 1 + n-3 + n-3 + 1  
Ct = n-3 + n-3 + 2  
Ct = 2(n-3) + 2  
Ct = 2n-6+2  
Ct = 2n-4

**Notação assintótica**  
Existem 3 tipos básicos:  
* Big ó (O): Usada para representar o pior caso de execução do algoritmo;
* Ohmega (Ω): Usada para representar o melhor caso de execução do algoritmo;
* Theta (Ө): Usada para representar o caso médio de execução do algoritmo.  

**Para representar o custo, as constantes e termos de menor ordem são ignorados.**  
* Custo total do Fibonacci Recursivo: Ct = O(2^n);  
* Custo total do Fibonacci Dinâmico: Ct = O(n).

## Introdução à Ordenação
Para analisarmos como fazer algoritmos de ordenação, precisamos analisar duas coisas: Problema vs Instância.  
* Problema: Ordenar um Array;
* Instância: Conjunto de dados. Exemplo:
  * 9,8,4,5,4,8,7
  * 1,2,3,5,7,7,5
  * 7,7,5,5,3,2,1

**Pseudocódigo**
```
ordena(A,n):
para i=1 até n, faça:
	para j=1 até n, faça:
		se A[i] < A[j], faça:
			troca(A[i],A[j])
		fim-se
	fim-para
fim-para
```
Em C++:
```c++
vector<int> ordena(vector<int> A, int n) {
  int aux;
  for (auto i = A.begin(); i < A.end(); i++) {
      for (auto j = A.begin(); j < A.end(); j++) {
          if (*i < *j) {
              aux = *i;
              *i = *j;
              *j = aux;
          }
      }
  }

  return A;
}
```
O código completo se encontra em: [ex01-ordenacao_bubble_sort](./ex01-ordenacao_bubble_sort.cpp)
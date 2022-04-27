# Aula 27.04 - Ordenação Eficiente
Analisaremos dois algoritmos mais eficientes que os da aula anterior, a Ordenação por Seleção e Ordenação por Inserção.
## Ordenação por Seleção
**Pseudocódigo:**
```
ordenaçãoSeleção(A,n)
para i = 1 até n; faça:
	menor  = i
	para j = i+1 até n; faça:
		se A[j] < A[menor], faça:
			menor = j
		fim-se
		j++
	fim-para
	troca(A[i],A[menor])
fim-para
```
O código implementado foi feito em C++: [ex01-ordenacao-ordenacao_por_selecao.cpp](./ex01-ordenacao-ordenacao_por_selecao.cpp).  
**Análise**  
O código implementado em C++ levou aproximadamente **530.053ms** para executar a função 'ordenaSelecao()' para um vetor com dez mil inteiros.
## Ordenação por Inserção
**Pseudocódigo:**
```
ordenaçãoInserção(A,n)
para i=1 até n; faça:
	chave = A[i]
	j = i-1
	enquanto j > -1 e A[j] > chave
		A[j+1]  = A[j]
		j--
	fim-enquanto
	A[j+1] = chave
fim-para
```
O código implementado foi feito em C++: [ex02-ordenacao-ordenacao_por_insercao](./ex01-ordenacao-ordenacao_por_insercao.cpp)  
**Análise:**
O código implementado em C++ levou aproximadamente **292.029ms** para executar a função 'ordenaInsercao()' para um vetor com dez mil inteiros.
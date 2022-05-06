# Aula 04.05 - Testes de Mesa e Ordenação por Quick Sort
Nessa aula, vamos realizar alguns testes de mesa dos algoritmos já implementados e veremos sobre o algoritmo Quick Sort.

## Teste de Mesa Algoritmo Bubble Sort
**Pseudocódigo**
```
para i=1 até n, faça:
	para j=1 até n, faça:
		se A[i] < A[j], faça:
			troca(A[i],A[j])
		fim-se
	fim-para
fim-para
```
**Teste**
| i | j | Condicional de Troca | Troca | Vetor |
| --- | --- | --- | --- | --- |
| 0 | 0 | A[0] < A[0] (7 < 7) = **F** | Não | A = [7, 3, 1, 5, 3] |
| 0 | 1 | A[0] < A[1] (7 < 3) = **F** | Não | A = [7, 3, 1, 5, 3] |
| 0 | 2 | A[0] < A[2] (7 < 1) = **F** | Não | A = [7, 3, 1, 5, 3] |
| 0 | 3 | A[0] < A[3] (7 < 5) = **F** | Não | A = [7, 3, 1, 5, 3] |
| 0 | 4 | A[0] < A[4] (7 < 3) = **F** | Não | A = [7, 3, 1, 5, 3] |
| 1 | 0 | A[1] < A[0] (3 < 7) = **V** | Sim | A = [3, 7, 1, 5, 3] |
| 1 | 1 | A[1] < A[1] (7 < 7) = **F** | Não | A = [3, 7, 1, 5, 3] |
| 1 | 2 | A[1] < A[2] (7 < 1) = **F** | Não | A = [3, 7, 1, 5, 3] |
| 1 | 3 | A[1] < A[3] (7 < 5) = **F** | Não | A = [3, 7, 1, 5, 3] |
| 1 | 4 | A[1] < A[4] (7 < 3) = **F** | Não | A = [3, 7, 1, 5, 3] |
| 2 | 0 | A[2] < A[0] (1 < 3) = **V** | Sim | A = [1, 7, 3, 5, 3] |
| 2 | 1 | A[2] < A[1] (3 < 7) = **V** | Sim | A = [1, 3, 7, 5, 3] |
| 2 | 2 | A[2] < A[2] (7 < 7) = **F** | Não | A = [1, 3, 7, 5, 3] |
| 2 | 3 | A[2] < A[3] (7 < 5) = **F** | Não | A = [1, 3, 7, 5, 3] |
| 2 | 4 | A[2] < A[4] (7 < 4) = **F** | Não | A = [1, 3, 7, 5, 3] |
| 3 | 0 | A[3] < A[0] (5 < 1) = **F** | Não | A = [1, 3, 7, 5, 3] |
| 3 | 1 | A[3] < A[1] (5 < 3) = **F** | Não | A = [1, 3, 7, 5, 3] |
| 3 | 2 | A[3] < A[2] (5 < 7) = **V** | Sim | A = [1, 3, 5, 7, 3] |
| 3 | 3 | A[3] < A[3] (7 < 7) = **F** | Não | A = [1, 3, 5, 7, 3] |
| 3 | 4 | A[3] < A[4] (7 < 3) = **F** | Não | A = [1, 3, 5, 7, 3] |
| 4 | 0 | A[4] < A[0] (3 < 1) = **F** | Não | A = [1, 3, 5, 7, 3] |
| 4 | 1 | A[4] < A[1] (3 < 3) = **F** | Não | A = [1, 3, 5, 7, 3] |
| 4 | 2 | A[4] < A[2] (3 < 5) = **V** | Sim | A = [1, 3, 3, 7, 5] |
| 4 | 3 | A[4] < A[3] (5 < 7) = **V** | Sim | A = [1, 3, 3, 5, 7] |
| 4 | 4 | A[4] < A[4] (7 < 7) = **F** | Não | A = [1, 3, 3, 5, 7] |

## Teste de Mesa Algoritmo Selection Sort
**Pseudocódigo**
```
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
**Teste**
| i | j | menor | Condicional de Troca | Atualiza Vetor | Vetor A[7, 3, 1, 5, 3] |
| --- | --- | --- | --- | --- | --- |
| 0 | 1 | 0 | A[1] < A[menor] (3 < 7) = **V** | Não | Menor = 1 e J = 2 |
| 0 | 2 | 1 | A[2] < A[menor] (3 < 7) = **V** | Não | Menor = 2 e J = 3 |
| 0 | 3 | 2 | A[3] < A[menor] (5 < 1) = **F** | Não | Menor = 2 e J = 4 |
| 0 | 4 | 2 | A[4] < A[menor] (3 < 1) = **F** | Não | Menor = 2 e J = 5 |
| 0 | 4 | 2 |  | Sim | Troca(0, 2) = A[1, 3, 7, 5, 3] |
| 1 | 2 | 1 | A[2] < A[menor] (7 < 3) = **F** | Não | Menor = 1 e J = 3 |
| 1 | 3 | 1 | A[3] < A[menor] (5 < 3) = **F** | Não | Menor = 1 e J = 4 |
| 1 | 4 | 1 | A[4] < A[menor] (3 < 3) = **F** | Não | Menor = 1 e J = 5 |
| 1 | 4 | 1 |  | Sim | Troca(1, 1) = A[1, 3, 7, 5, 3] |
| 2 | 3 | 2 | A[3] < A[menor] (5 < 7) = **V** | Não | Menor = 3 e J = 4 |
| 2 | 4 | 3 | A[4] < A[menor] (3 < 5) = **V** | Não | Menor = 4 e J = 5 |
| 2 | 4 | 3 |  | Sim | Troca(2, 3) = A[1, 3, 5, 7, 3] |
| 3 | 4 | 3 | A[4] < A[menor] (3 < 7) = **V** | Não | Menor = 4 e J = 5 |
| 3 | 4 | 3 |  | Sim | Troca(3, 4) = A[1, 3, 5, 3, 7] |
| 4 | 5 | 4 |  | Sim | Troca(4, 4) = A[1, 3, 5, 3, 7] |

## Teste de Mesa Algoritmo Insertion Sort
**Pseudocódigo**
```
para i=1 até n; faça:
	chave = A[i]
	j = i-1
	enquanto j > -1 e A[j] > chave
		A[j+1] = A[j]
		j--
	fim-enquanto
	A[j+1] = chave
fim-para
```
**Teste**  
| i | Chave | j | Condicional de Loop | Atribuição de Valor | Vetor [7, 3, 1, 5, 3] |
| --- | --- | --- | --- | --- | --- |
| 0 | 7 | -1 | J > -1 && A[-1] > chave (-1 > -1 E NULL > 7) **F** | A[0] = 7 | A = [7, 3, 1, 5, 3] |
| 1 | 3 | 0 | J > -1 && A[0] > chave (0 > -1 E 7 > 3) **V** | A[1] = A[0] (A[1] = 7) | A = [7, 7, 1, 5, 3] J = -1 |
| 1 | 3 | -1 | J > -1 && A[-1] > chave (0 > -1 E NULL > 3) **F** | A[0] = 3 | A = [3, 7, 1, 5, 3] |
| 2 | 1 | 1 | J > -1 && A[1] > chave (1 > -1 E 7 > 1) **V** | A[2] = A[1] (A[2] = 7) | A = [3, 7, 7, 5, 3], J = 0 |
| 2 | 1 | 0 | J > -1 && A[0] > chave (0 > -1 E 3 > 1) **V** | A[1] = A[0] (A[1] = 3) | A = [3, 3, 7, 5, 3], J = -1 |
| 2 | 1 | -1 | J > -1 && A[-1] > chave (0 > -1 E NULL > 3) **F** | A[0] = 1 | A = [1, 3, 7, 5, 3] |
| 3 | 5 | 2 | J > -1 && A[2] > chave (2 > -1 E 7 > 5) **V** | A[3] = A[2] (A[3] = 7) | A = [1, 3, 7, 7, 3], J = 1 |
| 3 | 5 | 1 | J > -1 && A[1] > chave (1 > -1 E 3 > 5) **F** | A[2] = 5 | A = [1, 3, 5, 7, 3] |
| 4 | 3 | 3 | J > -1 && A[3] > chave (3 > -1 E 7 > 3) **V** | A[4] = A[3] (A[4] = 7) | A = [1, 3, 5, 7, 7], J = 2 |
| 4 | 3 | 2 | J > -1 && A[2] > chave (2 > -1 E 5 > 3) **V** | A[3] = A[2] (A[3] = 5) | A = [1, 3, 5, 5, 7], J = 1 |
| 4 | 3 | 1 | J > -1 && A[1] > chave (1 > -1 E 3 > 3) **F** | A[2] = 3 | A = [1, 3, 3, 5, 7] | 



## Algoritmo de Ordenação Quick Sort
Esse algoritmo é o mais performático dentre todos que trabalhamos até agora. Esse algoritmo é um algoritmo recursivo que utiliza da divisão e conquista, onde ele particiona o array em partes menores através de um pivô (ou pivot), esse pivô é um dos valores guias do vetor, que deixa os valores menores que ele à sua esquerda e maiores que ele à direita, então, tudo que já é menor que o pivô não é analisado.  
Isso deixa o algoritmo muito mais eficiente, pois ele vai diminuindo a quantia de números que precisa analisar a medida que já ordenou parte do array.  
**Pseudocódigo:**
```
quickSort(ini,fim):
	se ini <= fim, faça:
		p = ordenaEparticiona(ini,fim)
		quickSort(ini,p-1)
		quickSort(p+1,fim)
	
ordenaEparticiona(p,r):
	pivo = A[r]
	i = p-1
	
	para j=p até r, faça
		se a[j] <= pivo, faça:
			i = i+1
			troca(i,j)
	i = i+1
	troca(i,r)
	retorna i

```
Em C++:
```c++
void quickSort(int ini, int fim) {
    int p;

    if(ini <= fim) {
        p = ordenaEParticiona(ini, fim);
        quickSort(ini, p-1);
        quickSort(p+1, fim);
    }
}

int ordenaEParticiona(int p, int r) {
    int pivo, i, aux;
    pivo = vetor[r];
    i = p-1;

    for(int j = p; j < r; j++) {
        if(vetor[j] <= pivo) {
            i = i + 1;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    i = i + 1;
    aux = vetor[i];
    vetor[i] = vetor[r];
    vetor[r] = aux;

    return i;
}
}
```
O código implementado foi feito em C++: [ex01-ordenacao-ordenacao_quick_sort.cpp](./ex01-ordenacao-ordenacao_quick_sort.cpp).  
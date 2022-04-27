# Aula 20.04 - Ordenação (Por Bubble Sort)
Significa classificar algo, fazer uma ordenação por troca (comparando chaves). As mais comuns são a ordenação crescente e decrescente, mediante à um parâmetro (número, alfabeto...).  
Os códigos em C++ implementados aqui estão disponíveis em: [ex01-analise_diferentes_ordenacoes_bubble_sort](./ex01-analise_diferentes_ordenacoes_bubble_sort.cpp)

## Análise
### Variação 1 (Laço duplo)
**Pseudocódigo**
```
ordena_Bolha1(A,n):
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i] < A[j]) {
                aux = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
        }
    }

    return A;
}
```

### Variação 2 (Do-While)
**Pseudocódigo**
```
ordena_Bolha2(A,n):
faça:
	trocas = false
	para i=1 até n, faça:
		se A[i] > A[i+1]
			troca(A[i], A[i+1])
			trocas = true
		fim-se
	fim-para
enquanto trocas == true
```
Em C++:
```c++
vector<int> ordena2(vector<int> B, int n) {
    bool trocas;
    int aux;

    do {
        trocas = false;

        for(int i = 0; i < n; i++) {
            if(B[i] > B[i+1]) {
                aux = B[i];
                B[i] = B[i + 1];
                B[i + 1] = aux;
                trocas = true;
            }
        }
    } while (trocas == true);

    return B;
}
```

### Variação 3 (While)
**Pseudocódigo**
```
ordena_Bolha3(A,n):
trocas == true
while(trocas == true)
	trocas = false
	para i=1 até n, faça:
		se A[i] > A[i+1]
			troca(A[i], A[i+1])
			trocas = true
		fim-se
	fim-para
fim-while
```
Em C++:
```c++
vector<int> ordena3(vector<int> C, int n) {
    bool trocas = true;
    int aux;

    while (trocas == true) {
        trocas = false;

        for(int i = 0; i < n; i++) {
            if(C[i] > C[i+1]) {
                aux = C[i];
                C[i] = C[i + 1];
                C[i + 1] = aux;
                trocas = true;
            }
        }
    }

    return C;
}
```

### Custo da execução
| ordena_Bolha3(A,n): | custo | repetição |
| --- | --- | --- |
| para i=1 até n, faça: | 1 | n |
|	  para j=1 até n, faça: | 1 | n*n |
|		  se A[i] < A[j], faça: | 1 | n*n |
|			  troca(A[i],A[j]) | 1 | 0 ou n*n ou (n*n)/2 | 
|		fim-se | - | - |
|	fim-para | - | - |
| fim-para | - | - |

**Pior Caso**  
Ct = n + n\*n + n\*n + n\*n  
Ct = n.1 + n².1 + n².1 + n².1  
Ct = n²(1+1+1) + n 
Assintoticamente (ignora constantes e termos de menor ordem)  
Ct = O(n^2)

**Melhor Caso**  
Ct = n + n\*n + n\*n + 0  
Ct = n + n² + n²  
Ct = n²(1+1) + n  
Assintoticamente (ignora constantes e termos de menor ordem)  
Ct = Ω(n^2)  

**Caso médio**  
Ct = n + n\*n + n\*n + (n\*n)/2  
Ct = n + n\*n + n\*n + (n\*n)*1/2  
Ct = n + n^2 + n^2 + n^2 * 1/2  
Ct = n + n^2(1+1) + n^2 * 1/2  
Assintoticamente (ignora constantes e termos de menor ordem)  
Ct = Ө(n^2)

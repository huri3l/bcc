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
Em C++:
```c++
vector<int> ordenaSelecao(vector<int> vetor) {
    int menor, aux;

    for(int i = 0; i < vetor.size(); i++) {
        menor = i;

        for(int j = i + 1; j < vetor.size(); j++) {
            if(vetor[j] < vetor[menor])
                menor = j;
        }
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }

    return vetor;
}
```
O código implementado foi feito em C++: [ex01-ordenacao-ordenacao_por_selecao.cpp](./ex01-ordenacao-ordenacao_por_selecao.cpp).  
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
Em C++:
```c++
vector<int> ordenaInsercao(vector<int> vetor) {
    int j, chave;

    for(int i = 0; i < vetor.size(); i++) {
        chave = vetor[i];
        j = i-1;

        while(j > -1 && vetor[j] > chave) {
              vetor[j+1] = vetor[j];
              j--;
        }

        vetor[j + 1] = chave;
    }

    return vetor;
}
```
O código implementado foi feito em C++: [ex02-ordenacao-ordenacao_por_insercao](./ex01-ordenacao-ordenacao_por_insercao.cpp)  
## Análise da Ordenação por Seleção e Inserção
Uma tabela com os tempos de execução das funções implementadas durante a aula.  
Para essa análise, serão usados arquivos disponibilizados no Moodle da disciplina.
Esses arquivos tem uma quantia de números inteiros e podem ser aleatórios, ordenados crescentemente ou decrescentemente. Esses arquivos também estão disponíveis nessa pasta   
**Observação:** Essa análise é empírica, portanto, relativa e depende de diversos fatores, como CPU, linguagem, sistema operacional...
|     | Bubble | Selection | Insertion |
| --- | --- | --- | --- |
| Dez mil aleatório | 1751ms | 344.001ms | 193.999ms |
| Dez mil crescente | 1522ms | 349.998ms | 0ms |
| Dez mil decrescente | 1938ms | 354ms | 362.998ms |
| Cem mil aleatório | 175255ms | 35357.8ms | 18744ms |
| Cem mil crescente | 152526ms | 34975.4ms | 0.9991ms |
| Cem mil decrescente | 192163ms | 35261.2ms | 37600.2ms |
# Aula 16.04 - Análise de Algoritmos Fibonacci
O objetivo dessa análise será de verificar a complexidade de algoritmos e de sua performance.

## Análise de Fibonacci
A fórmula matemática de fibonacci é:
```
fib(n) = fib(n-1) + fib(n -2)
fib(0) = 0
fib(1) = 1
```
Com essa fórmula, temos que:
```
fib(5)
fib(5) = fib(5-1) + fib(5-2)
```
Isso gera uma árvore de recursão. Através da recursividade, podemos criar um algoritmo capaz de identificar o fibonacci de um valor passado:
```
fib(5) = fib(4) + fib(3)
fib(5) = fib(3)+fib(2) + fib(2) + fib(1)
fib(5) = fib(2) + fib(1) +fib(1) + fib(0) + fib(2) + fib(1)
fib(5) = fib(1) + fib(0) + fib(1) +fib(1) + fib(0) + fib(1) + fib(0) + fib(1)
fib(5) = 1 + 0 + 1 + 1 + 0 + 1 + 0 + 1 = 5
```
### Análise do Algoritmo - Recursivo
Vamos realizar testes com os valores 10 (55), 40 (102334155), e 50 (12586269025) 
**Pseudocódigo**
```
fib(n) {
	se n <=2, então
		retorna 1
	senão, 
		retorna fib(n-1) + fib(n-2)
}
```
Em C++: 
```c++
int fibonacci(int value) {
    if(value == 0) {
        return 0;
    } else if (value == 1 || value == 2) {
        return 1;
    }

    return fibonacci(value - 1) + fibonacci(value - 2);
}
```
O código completo (com análise do tempo de execução) se encontra em: [ex01-fibonacci_recursivo-tempo_execucao](./ex01-fibonacci_recursivo-tempo_execucao.cpp)  
**Questões**
* Funcionou? Sim;
* Quanto tempo levou a execução? 
  * 5: 0ms;
  * 40: 534.715ms;
  * 50: 65487.4ms.
* Por que demorou esse tempo? As chamadas recursivas “em excesso” ocupam a CPU em demasia.

### Análise do Algoritmo - Programação Dinâmica
Vamos realizar testes com os valores 10 (55), 40 (102334155), e 50 (12586269025)  
**Pseudocódigo**
```
fib(n) {
	arr = [0,1,1]
	para i de 3 até n, faça
		arr[i] = arr[i-1] + arr[i-2]
	
	retorna arr[n]
}
```
Em C++:
```c++
int64_t fibonacci(int value) {
    vector<int64_t> known_results;
    known_results.push_back(0);
    known_results.push_back(1);
    known_results.push_back(1);

    for(int i = 3; i <= value; i++) {
        known_results.push_back(known_results[i - 1] + known_results[i - 2]);
    }

    return known_results[value];
}
```
O código completo (com análise do tempo de execução) se encontra em: [ex02-fibonacci_prog_dinamica-tempo_execucao](./ex02-fibonacci_prog_dinamica-tempo_execucao.cpp)  
**Questões**
* Funcionou? Sim;
* Quanto tempo levou a execução? 
  * 5: 0ms;
  * 40: 0ms;
  * 50: 0ms.
* Por que demorou esse tempo? As chamadas recursivas “em excesso” ocupam a CPU em demasia.
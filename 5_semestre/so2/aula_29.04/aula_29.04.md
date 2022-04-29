# Aula 29.04 - Conflitos de Threads
Para solucionar esse problema, usamos a **sincronização**. Através da sincronização, 
podemos resolver esse conflito de diversas formas:
* Monitores
* Locks
* Semáforos
* API Java  

Se bem implementado, a sincronização significa mais desempenho. Entretanto, dependendo da implementação,
pode resultar em inconsistência nos dados e problemas no compartilhamento de recursos.

## Resolvendo o problema da última aula com Java
Para resolver o problema de sincronização da AgenciaBancaria, 
podemos colocar um **synchronized** ao redor do conteúdo da função saque().
```java
public class AgenciaBancaria {
    public boolean saque(ContaBancaria contaBancaria, double valor) {
        
        synchronized(contaBancaria) {
            double saldo = contaBancaria.getSaldo();
        
            if(saldo < valor) {
                System.out.println("Saldo insuficiente");
                return false;
            }

            double novoSaldo = saldo - valor;
            System.out.println(Thread.currentThread().getName() + " sacou R$" + valor + ". Saldo após o saque R$ " + novoSaldo);
            contaBancaria.setSaldo(novoSaldo);
            return true;
        }
    }
}
```

## Anotações
* [Solução Producer-Consumer com BlockingQueue](https://www.geeksforgeeks.org/producer-consumer-solution-using-blockingqueue-in-java-thread/)
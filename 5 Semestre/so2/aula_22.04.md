# Aula 22.04 - Threads
https://github.com/huri3l/bcc
## O que é
Resumidamente, threads são uma forma de um processo se dividir em duas ou mais tarefas para execução paralela. É uma linha que rege o processo para que seja executado de forma particionada, a fim de se obter mais performance na execução do programa.
## Monothreads
As monothreads são problemáticas por consumirem muito recurso, além de limitar seu uso para a sequência de: criação, gerenciamento e término, não podendo ser consumida no meio do caminho. Para solucionar isso, o multithread surgiu, podendo dividir o processo em mais threads, consumir menos recurso e ser mais performático.
## Onde as threads são implementadas
**Existem as threads implementadas à nível de Kernel. A respeito dessas threads, as vantagens são:**
* O Kernel tem conhecimento total de todas as threads;
* O escalonador pode decidir dar mais tempo de CPU a um processo com grande número de threads;
* É bom para aplicativos que bloqueiam com frequência.  


Entretanto, existem desvantagens também:
* O Kernel é sobrecarregado e existe um aumento na complexidade do Kernel;
* As threads de Kernel são lentas e ineficientes se comparadas às threads de usuário, em centenas de vezes.

**Existem as threads implementadas à nível de usuário. A respeito dessas threads, as vantagens são:**
* Podem ser implementadas em um SO que não suporta threads de Kernel;
* São criadas, trocadas e sincronizadas no espaço do usuário sem intervenção do Kernel;
Rápidas e eficientes.

Entretanto, existem desvantagens também:
* Não é uma solução perfeita;
* Existe a falta de coordenação entre o gerenciador de threads no nível do usuário e o kernel;
* Para solucionar os problemas acima, é necessário uma comunicação entre o kernel e o gerenciador de thread em nível de usuário (Scheduler activation).
## Por que utilizar?
* Threads são muito mais “leves” que processos, em relação a criação, manutenção e encerramento;
* Na grande maioria dos sistemas, a criação de uma thread é muito mais rápido do que criar um novo processo;
* Threads geralmente tem acesso à um mesmo recurso compartilhado. Isso faz com que a thread de um editor de texto possa enviar dados para o processo que gerencia a fila de impressão.
## Memória compartilhada
* A memória compartilhada entre processos/threads causa o problema da seção/região crítica. É basicamente uma variável compartilhada;
* O problema da seção crítica é garantir que quando um processo ou thread esteja executando sua seção crítica, nenhum outro entre nela;
* Caso 2 threads estejam concorrendo pela mesma variável, ocorre o deadlock. Como solução seria implementado um “semáforo”, que diria quando uma thread pode usar uma variável ou não, a partir do uso de outra. Isso ocorre quando uma thread informar que finalizou para que a seguinte possa executar.
## Anotações
| Estrutura básica de um Computador |
| --- |
| Aplicações |
| Sistema Operacional (Kernel/Núcleo) |
| Hardware |

**Orientação a Objetos em Java:**
* Implements: Existem métodos pré-definidos que devem ser implementados;
* Extends: Herda os métodos de uma 
classe.

Caso nosso projeto tenha herança, não podemos utilizar o Extends Thread, pois não poderíamos herdar outra classe no projeto. Nesse caso, teríamos que usar Implements Runnable no lugar.


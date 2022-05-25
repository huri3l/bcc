# Exercício 2
#### 1 - Leia e analise a generalização do autômato finito apresentada no slide 24.

#### 2 - Com base nas explicações dos slides 22-24, construa um autômato finito que processe cadeias cuja soma dos símbolo seja múltiplo de 5 (cinco). Apresente o autômato e cadeias de teste. OBS: ao construir o autômato considere o alfabeto contendo os símbolos Σ = {0, 2, 3, (RESET)}
**R:** Autômato: M = ({q0, q1, q2}, {0, 2, 3, (RESET)}, δ, q0, {q0})  
Teste: 23023 = 10

#### 3 - Leia e analise o slide 26 e comente o que significa cada uma das condições de aceitação: (1), (2) e (3)
**R:** A condição de aceitação 1 busca declarar como e onde a máquina inicia, com seu estado inicial. A condição de aceitação 2 torna possível que cada estado tenha ao menos uma transição para alterar o estado do autômato. Por fim, a condição 3 cita que a máquina aceita entradas que terminam em um estado de aceitação.

#### 4 - Leia e analise o slide 28 e comente por quê o conjunto de estados de execução {q0, q1, q1, q0, q2, q1, q0, q0, q1, q0} representam o processamento da cadeia de entrada w = 10(RESET)22(RESET)012
**R:** Pois ao processar a entrada w = 10(RESET)22(RESET), o autômato transita, respectivamente, para os estados {q0, q1, q1, q0, q2, q1, q0, q0, q1, q0}, de acordo com as transições existentes para cada estado.

#### 5 - Explique o que caracteriza uma linguagem ser regular (baseie-se no slide 27)
**R:** Uma linguagem é regular se algum autômato existente é capaz de reconhecer, entender e interpretar tal linguagem
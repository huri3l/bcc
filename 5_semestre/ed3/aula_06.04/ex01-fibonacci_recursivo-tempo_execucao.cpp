#include <iostream>
#include <chrono>

using namespace std;

int fibonacci(int value);

int main() {
    setlocale(LC_ALL, "Portuguese");

    int result;

    auto start_time = chrono::high_resolution_clock::now(); // Obtém o momento antes da execução
    result = fibonacci(40);
    auto end_time = chrono::high_resolution_clock::now(); // Obtém o momento depois da execução

    chrono::duration<double, std::milli> float_ms = end_time - start_time; // Obtém quanto tempo decorreu desde o momento antes da execução até depois da execução em float
    auto int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time); // Obtém quanto tempo decorreu desde o momento antes da execução até depois da execução em int

    cout << "Resultado: " << result << endl;

    cout << "Tempo de execução da função 'fibonacci()': " << float_ms.count() << " ms "
         << "( " << int_ms.count() << " milliseconds )" << endl;
}

int fibonacci(int value) {
    if(value == 0) {
        return 0;
    } else if (value == 1 || value == 2) {
        return 1;
    }

    return fibonacci(value - 1) + fibonacci(value - 2);
}

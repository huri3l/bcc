#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int64_t fibonacci(int value);

int main() {
    setlocale(LC_ALL, "Portuguese");
    int64_t result;

    auto start_time = chrono::high_resolution_clock::now();
    result = fibonacci(39);
    auto end_time = chrono::high_resolution_clock::now();

    chrono::duration<double, std::milli> float_ms = end_time - start_time;
    auto int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    cout << "Resultado: " << result << endl;

    cout << "Tempo de execução da função 'fibonacci()': " << float_ms.count() << " ms "
         << "( " << int_ms.count() << " milliseconds )" << endl;

}

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


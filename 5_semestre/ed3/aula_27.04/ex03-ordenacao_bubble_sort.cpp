#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

vector<int> geraVetor();
vector<int> ordena(vector<int> A, int n);

main() {
    vector<int> A;

    // Variáveis para análise de tempo de execução dos algoritmos
    auto start_time = chrono::high_resolution_clock::now();
    auto end_time = chrono::high_resolution_clock::now();
    auto int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    chrono::duration<double, std::milli> float_ms = end_time - start_time;


    A = geraVetor();
    int n = A.size();

    start_time = chrono::high_resolution_clock::now();
    A = ordena(A, n);
    end_time = chrono::high_resolution_clock::now();
    float_ms = end_time - start_time;
    int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    cout << "Tempo de execução da função 'ordena()': " << float_ms.count() << " ms "
        << "( " << int_ms.count() << " milliseconds )" << endl << endl;
}

vector<int> geraVetor() {
    string linha;
    int num;
    vector<int> vetor;

    ifstream arquivo ("arqCemMil.txt");
    if(arquivo.is_open()) {
        while(arquivo >> num) {
            vetor.push_back(num);
        }
    }

    return vetor;
}

vector<int> ordena(vector<int> A, int n) {
    int aux;
    for (auto i = A.begin(); i < A.end(); i++) {
        for (auto j = A.begin(); j < A.end(); j++) {
            if (*i < *j) {
                aux = *i;
                *i = *j;
                *j = aux;
            }
        }
    }

    return A;
}

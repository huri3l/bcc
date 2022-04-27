#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;

vector<int> gera_vetor(int tamanho);
vector<int> ordena(vector<int> A, int n);
vector<int> ordena2(vector<int> B, int n);
vector<int> ordena3(vector<int> C, int n);

main() {
    setlocale(LC_ALL, "Portuguese");

    vector<int> A, B, C;

    // Variáveis para análise de tempo de execução dos algoritmos
    auto start_time = chrono::high_resolution_clock::now();
    auto end_time = chrono::high_resolution_clock::now();
    auto int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    chrono::duration<double, std::milli> float_ms = end_time - start_time;

    A = gera_vetor(5000);
    B = A;
    C = A;

    // Bubble sort comum com la�o duplo
    cout << "Ordenação 1\n";
    start_time = chrono::high_resolution_clock::now();
    A = ordena(A, A.size());
    end_time = chrono::high_resolution_clock::now();
    float_ms = end_time - start_time;
    int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    cout << "Tempo de execução da função 'ordena()': " << float_ms.count() << " ms "
         << "( " << int_ms.count() << " milliseconds )" << endl << endl;


    cout << "Ordenação 2\n";
    start_time = chrono::high_resolution_clock::now();
    B = ordena2(B, B.size());
    end_time = chrono::high_resolution_clock::now();
    float_ms = end_time - start_time;
    int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    cout << "Tempo de execução da função 'ordena2()': " << float_ms.count() << " ms "
         << "( " << int_ms.count() << " milliseconds )" << endl << endl;


    // Bubble sort com Do While
    cout << "Ordenação 3\n";
    start_time = chrono::high_resolution_clock::now();
    C = ordena3(C, C.size());
    end_time = chrono::high_resolution_clock::now();
    float_ms = end_time - start_time;
    int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    cout << "Tempo de execução da função 'ordena3()': " << float_ms.count() << " ms "
         << "( " << int_ms.count() << " milliseconds )" << endl << endl;
}

vector<int> gera_vetor(int tamanho) {
    vector<int> V;
    srand(time(NULL));
    for(int i = 0; i < tamanho; i++) {
        V.push_back(rand() % 1001);
    }

    return V;
}

// Bubble sort comum com laço duplo
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

// Bubble sort com Do While
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

// Bubble sort com While
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

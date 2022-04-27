#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

vector<int> geraVetor();
vector<int> ordenaSelecao(vector<int> vetor);

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Variáveis para análise de tempo de execução dos algoritmos
    auto start_time = chrono::high_resolution_clock::now();
    auto end_time = chrono::high_resolution_clock::now();
    auto int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    chrono::duration<double, std::milli> float_ms = end_time - start_time;

    vector<int> vetor;
    vetor = geraVetor();

    start_time = chrono::high_resolution_clock::now();
    vetor = ordenaSelecao(vetor);
    end_time = chrono::high_resolution_clock::now();
    float_ms = end_time - start_time;
    int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    cout << "Tempo de execução da função 'ordenaSelecao()': " << float_ms.count() << " ms "
        << "( " << int_ms.count() << " milliseconds )" << endl << endl;

}

vector<int> geraVetor() {
    string linha;
    int num;
    vector<int> vetor;

    ifstream arquivo ("arqDezMil.txt");
    if(arquivo.is_open()) {
        while(arquivo >> num) {
            vetor.push_back(num);
        }
    }

    return vetor;
}

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

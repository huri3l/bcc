#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

void quickSort(int ini, int fim);
int ordenaEParticiona(int p, int r);
vector<int> geraVetor();

vector<int> vetor;

int main() {
    setlocale(LC_ALL, "Portuguese");
    vetor = geraVetor();

    // Variáveis para análise de tempo de execução dos algoritmos
    auto start_time = chrono::high_resolution_clock::now();
    auto end_time = chrono::high_resolution_clock::now();
    auto int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    chrono::duration<double, std::milli> float_ms = end_time - start_time;

    start_time = chrono::high_resolution_clock::now();
    quickSort(0, vetor.size() - 1);
    end_time = chrono::high_resolution_clock::now();
    float_ms = end_time - start_time;
    int_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    cout << "Tempo de execução da função 'quickSort()': " << float_ms.count() << " ms "
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

void quickSort(int ini, int fim) {
    int p;

    if(ini <= fim) {
        p = ordenaEParticiona(ini, fim);
        quickSort(ini, p-1);
        quickSort(p+1, fim);
    }
}

int ordenaEParticiona(int p, int r) {
    int pivo, i, aux;
    pivo = vetor[r];
    i = p-1;

    for(int j = p; j < r; j++) {
        if(vetor[j] <= pivo) {
            i = i + 1;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    i = i + 1;
    aux = vetor[i];
    vetor[i] = vetor[r];
    vetor[r] = aux;

    return i;
}

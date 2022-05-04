#include <iostream>
#include <vector>

using namespace std;

void quickSort(int ini, int fim);
int ordenaEParticiona(int p, int r);

vector<int> vetor;

int main() {
    setlocale(LC_ALL, "Portuguese");

    // vetor = geraVetor();

    vetor.push_back(7);
    vetor.push_back(3);
    vetor.push_back(1);
    vetor.push_back(5);
    vetor.push_back(3);

    cout << "Vetor antes da ordenação: \n";
    for(int i = 0; i < vetor.size(); i++) {
        cout << vetor[i] << "\n";
    }

    quickSort(vetor[0], vetor.back());

    cout << "Vetor depois da ordenação: \n";
    for(int i = 0; i < vetor.size(); i++) {
        cout << vetor[i] << "\n";
    }

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

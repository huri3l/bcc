#include <iostream>
#include <vector>

using namespace std;

vector<int> ordena(vector<int> A, int n);

main() {
  vector<int> A;

  A = {9, 8, 4, 5, 16, 7, 3, 2, 1, 20, 17, 15, 33, 12, 11, 13};
  int n = A.size();

  cout << "\nArray informado:\n";
  for (auto i = A.begin(); i < A.end(); i++) {
      cout << *i << " - ";
  }

  A = ordena(A, n);

  cout << "\n\nArray ordenado:\n";
  for (auto i = A.begin(); i < A.end(); i++) {
      cout << *i << " - ";
  }
  cout << endl;
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

/*Crear un vector dinámico con “n” números aleatorios sin repetir ningún elemento. Imprimir el arrays
dinámico creado.*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

bool verificar(int n, int* vector, int ax);
int main() {
  srand(time(NULL));
  int n=5;
  int ax;

  int* vector = new int[n];

  for (int i = 0; i < n; i++) {
    do {
      ax = rand() % 5 + 1;
    } while (verificar(n, vector, ax));
    vector[i] = ax;
  }
  cout << "el vector cargado es: " << endl;
  for (int i = 0; i < n; i++) {
    cout << vector[i] << "\t";
  }

  delete[] vector;
  return 0;
}
bool verificar(int n, int* vector, int ax) {
  for (int i = 0; i < n; i++) {
    if (ax == vector[i]) {
      return true;
    }
  }
  return false;
}
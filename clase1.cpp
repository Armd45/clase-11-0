/* Ingresar dos números distintos. Imprimir la serie de números existentes entre ambos. Imprime a demás,
la ubicación en memoria de dicha serie de números.*/
#include<iostream>
#include<stdlib.h>
using namespace std;

bool ingresar(int n, int* dos, int ax);
void mayor_menor(int n, int* dos, int& menor, int& mayor);
int main() {
  int n = 2;
  int* dos = new int[n];
  int c = 0, ax;
  int menor, mayor;

  while (c < 2) {
    do {
      cout << "Ingrse un numero: ";cin >> ax;
    } while (ingresar(n, dos, ax));
    *(dos + c) = ax;
    c++;
  }

  mayor_menor(n, dos, menor, mayor);

  for (int i = menor; i <= mayor; i++) {
    cout << "posicion de memoria " << (dos + i) << " del numero " << i << endl;
  }

  delete[] dos;
  return 0;
}
bool ingresar(int n, int* dos, int ax) {
  for (int i = 0; i < n; i++) {
    if (ax == *(dos + i)) {
      cout << "numero repetido ";
      return true;
    }
  }
  return false;
}
void mayor_menor(int n, int* dos, int& menor, int& mayor) {
  mayor = *dos;
  menor = *dos;
  for (int i = 0; i < n; i++) {
    if (mayor < *(dos + i)) {
      mayor = *(dos + i);
    }if (menor > *(dos + i)) {
      menor = *(dos + i);
    }
  }
}
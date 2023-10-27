/*Generar “n” cantidad de números aleatorios establecidos entre Li: límite superior, Ls: límite superior. A
cada número aleatorio generado, mostrar su posición en memoria y además indica si los mismos son
pares o impares utilizando punteros.*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void operacion(int* numeros, int n, int ls, int li);
int main() {
  srand(time(NULL));
  int n, li, ls;
  cout << "Ingresar los datos: " << endl;
  cout << "ingrese la cantidad de elementos: ";cin >> n;
  cout << "ingrese el limite inferior: ";cin >> li;
  cout << "ingrese el limite superior: ";cin >> ls;

  int* numeros = new int[n];

  operacion(numeros, n, ls, li);

  delete[] numeros;
  return 0;
}
void operacion(int* numeros, int n, int ls, int li) {
  for (int i = 0; i < n; i++) {
    numeros[i] = rand() % (ls - li) + li;
    int* impar_par = &numeros[i];
    cout << "La posicion de memoria del numero " << *impar_par << " es " << impar_par;
    if (*impar_par % 2 == 0) {
      cout << " Par " << endl;
    }
    else {
      cout << " Impar " << endl;
    }
  }

}
/*
Crear y cargar una matriz A hallar la cantidad de elementos pares de cada fila de la matriz
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void cargar(int** m, int rows, int column);
void mostrar(int** m, int rows, int column);
void contadorPar(int** m, int rows, int column);
int main() {
  srand(time(NULL));
  int rows, column;

  cout << "Ingrese el numero de filas: ";cin >> rows;
  cout << "Ingrese el numero de columnas: ";cin >> column;

  int** m = new int* [rows];
  for (int i = 0; i < rows; i++) {
    m[i] = new int[column];
  }
  //cargando matriz
  cargar(m, rows, column);
  
  cout << "La matriz cargada es: " << endl;
  mostrar(m, rows, column);

  //cantidad de pares
  contadorPar(m, rows, column);

  for (int i = 0; i < rows; i++) {
    delete m[i];
  }
  delete[] m;
  return 0;
}
void cargar(int** m, int rows, int column) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      m[i][j] = rand() % 100 + 1;
    }
  }
}
void mostrar(int** m, int rows, int column) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      cout << m[i][j] << "\t";
    }
    cout << endl;
  }
}
void contadorPar(int** m, int rows, int column) {
  for (int i = 0; i < rows; i++) {
    int par = 0;
    for (int j = 0; j < column; j++) {
      if (m[i][j] % 2 == 0) {
        par++;
      }
    }
    cout << "Fila " << i + 1 << " total de pares: " << par << endl;
  }
}
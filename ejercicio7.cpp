/*
Crear y cargar una matriz M. Imprimir la matriz junto con el promedio de elementos de la diagonal
principal y secundaria.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

void cargar(int** M, int rows, int column);
int diagonalP(int** M, int rows, int column);
int diagonalD(int** M, int rows, int column);
int main() {
  int rows = 4, column = 4;

  int** M = new int* [rows];
  for (int i = 0; i < rows; i++) {
    M[i] = new int[column];
  }

  cargar(M, rows, column);

  cout << "\nLa matriz M cargada es: " << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      cout << M[i][j] << "\t";
    }
    cout << endl;
  }
  cout << "Y la diagonal principal es: " << diagonalP(M, rows, column);
  cout << "\nY la diagonal secundaria es: " << diagonalD(M, rows, column);

  for (int i = 0; i < rows; i++) {
    delete M[i];
  }
  delete[] M;

  return 0;
}
void cargar(int** M, int rows, int column) {
  cout << "Cargar Matriz M\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      cout << "Ingrese el valor de la posicion " << i << "." << j << ": ";cin >> M[i][j];
    }
  }
}
int diagonalP(int** M, int rows, int column) {
  int p;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      if (i == j) {
        p += M[i][j];
      }
    }
  }
  return p;
}
int diagonalD(int** M, int rows, int column) {
  int d;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      if (i + j == rows - 1) {
        d += M[i][j];
      }
    }
  }
  return d;
}
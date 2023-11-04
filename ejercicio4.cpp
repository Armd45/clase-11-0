/* Crear y cargar una matriz dinámica. Utiliza el siguiente menú para imprimir los siguientes datos:
a) Imprimir la Matriz
b) Imprimir una Fila determinada
c) Mayor elemento cargado en la matriz*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void cargando(int rows, int column, int** matriz);
void mostrar(int rows, int column, int** matriz);
void solo_column(int rows, int** matriz, int col);
void verificar_op(int& col, int column);
int mayor(int rows, int column, int** matriz);
int main() {
  srand(time(NULL));
  int rows, column;
  int op, col;

  cout << "Ingrese numero de filas: ";cin >> rows;
  cout << "Ingrese numero de columnas: ";cin >> column;
  cout << endl;
  system("cls");

  //creando matriz dinamica
  int** matriz = new int* [rows];
  for (int i = 0;i < rows; i++) {
    matriz[i] = new int[column];
  }

  //cargando la matriz
  cargando(rows, column, matriz);

  cout << "Menu Principal\n\n";
  cout << "1-Imprimir la Matriz" << endl << "2-Imprimir una fila determinada" << endl << "3-Mayor elemento caragado en la matriz" << endl;
  cout << "Ingrese opcion: ";cin >> op;
  while ((op < 1) || (op > 3)) {
    cout << "1-Imprimir la Matriz" << endl << "2-Imprimir una fila determinada" << endl << "3-Mayor elemento caragado en la matriz" << endl;
    cout << "Ingrese opcion: ";cin >> op;
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      cout << matriz[i][j] << "\t";
    }
    cout << endl;
  }
  switch (op) {
  case 1:
    //mostrando matriz
    mostrar(rows, column, matriz);
    break;
  case 2:
    verificar_op(col, column);
    cout << "La columna imprimida es: " << endl;
    solo_column(rows, matriz, col);
    break;
  case 3:
    cout<<"\n\nEl mayor valor cargado es: "<<mayor(rows, column, matriz);
    break;
  }


  //librarndo 
  for (int i = 0; i < rows; i++) {
    delete[] matriz[i];
  }
  delete[] matriz;

  return 0;
}
void cargando(int rows, int column, int** matriz) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      matriz[i][j] = rand() % 50 + 1;
    }
  }
}
void mostrar(int rows, int column, int** matriz) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      cout << matriz[i][j] << "\t";
    }
    cout << endl;
  }
}
void verificar_op(int& col, int column) {
  cout << "Que columna desea imprimir del 1 al " << column << " ?: ";cin >> col;
  while ((col < 1) || (col > column)) {
    cout << "Que columna desea imprimir del 1 al " << column << " ?: ";cin >> col;
  }
}
void solo_column(int rows, int** matriz, int col) {
  for (int i = 0; i < rows; i++) {
    cout << matriz[i][col - 1] << "\t";
  }
}
int mayor(int rows, int column, int** matriz) {
  int mayor = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      if (matriz[i][j] > mayor) {
        mayor = matriz[i][j];
      }
    }
  }
  return mayor;
}
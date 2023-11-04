/*
Crear los vectores dinámicos A, B, C, y D, cargar los vectores A, B, C y con los mismos elementos cargar
en forma ordenada el vector D. Utiliza un menú para imprimir los siguientes datos:
a) Imprimir vector A
b) Imprimir vector B
c) Imprimir vector C
d) Imprimir vector D
e) Imprimir todos los vectore
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void cargar_vectores(int n, int* A, int* B, int* C);
void cargar_matriz(int n, int* A, int* B, int* C, int** D);
void validadarMenu(int& op);
void imprimirA(int n, int* A);
void imprimirB(int n, int* B);
void imprimirC(int n, int* C);
void imprimirD(int n, int** D);
int main() {
  srand(time(NULL));
  int n = 4;
  int* A = new int[n];
  int* B = new int[n];
  int* C = new int[n];
  int op;
  char op2;

  cargar_vectores(n, A, B, C);

  int** D = new int* [3];
  for (int i = 0; i < 3; i++) {
    D[i] = new int[n];
  }

  cargar_matriz(n, A, B, C, D);

  do {
    validadarMenu(op);
    switch (op) {
    case 1:
      cout << "\nEl vector A es: " << endl;
      imprimirA(n, A);
      break;
    case 2:
      cout << "\nEl vector B es: " << endl;
      imprimirB(n, B);
      break;
    case 3:
      cout << "\nEl vector C es: " << endl;
      imprimirC(n, C);
      break;
    case 4:
      cout << "\nLa matriz D es: " << endl;
      imprimirD(n, D);
      break;
    case 5:
      cout << "\nEl vector A es " << endl;
      imprimirA(n, A);
      cout << "\nEl vector B es " << endl;
      imprimirB(n, B);
      cout << "\nEl vector C es " << endl;
      imprimirC(n, C);
      cout << "\nY la matriz D es: " << endl;
      imprimirD(n, D);
      break;
    }
    cout << "\nDesea seguir ?: ";cin >> op2;
    system("cls");
  } while ((op2 == 's') || (op2 == 'S'));

  for (int i = 0; i < 3; i++) {
    delete[] D[i];
  }
  delete[] D;
  delete[] A;
  delete[] B;
  delete[] C;

  return 0;
}
void cargar_vectores(int n, int* A, int* B, int* C) {
  for (int i = 0; i < n; i++) {
    A[i] = rand() % 50 + 1;
    B[i] = rand() % 50 + 1;
    C[i] = rand() % 50 + 1;
  }
}
void cargar_matriz(int n, int* A, int* B, int* C, int** D) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0) {
        D[i][j] = A[j];
      }
      else if (i == 1) {
        D[i][j] = B[j];
      }
      else if (i == 2) {
        D[i][j] = C[j];
      }
    }
  }
}
void validadarMenu(int& op) {
  cout << "Menu Principal" << endl;
  cout << "\nIngrese la opcion: " << endl;
  cout << "\n1-Imprimir vector A" << endl;
  cout << "2-Imprimir vector B" << endl;
  cout << "3-Imprimir vector C" << endl;
  cout << "4-Imprimir vector D" << endl;
  cout << "5-Imprimir todos los vectores" << endl;
  cout << "\nIngrese la opcion: " << endl;cin >> op;
  while ((op < 1) || (op > 5))
  {
    cout << "ERROR. Opciones disponibles del 1 al 5: ";cin >> op;
  }

}
void imprimirA(int n, int* A) {
  for (int i = 0; i < n; i++) {
    cout << A[i] << "\t";
  }
}
void imprimirB(int n, int* B) {
  for (int i = 0; i < n; i++) {
    cout << B[i] << "\t";
  }
}
void imprimirC(int n, int* C) {
  for (int i = 0; i < n; i++) {
    cout << C[i] << "\t";
  }
}
void imprimirD(int n, int** D) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      cout << D[i][j] << "\t";
    }
    cout << endl;
  }
}
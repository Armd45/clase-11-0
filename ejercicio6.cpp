/*
Crear y cargar una matriz dinámica y con el siguiente menú de selección, desarrolla las rutinas para cada
uno:
- cargarMatriz: se encargará de agregar elementos a la matriz dinámica
- mostrarMatriz: se encargará de mostrar los elementos cargados en la matriz dinámica
- sumaDP: se encargará de hallar la sumatoria de los elementos de la diagonal principal
- cantPIP: se encargará de hallar la cantidad de elementos pares e impares de la diagonal secundaria.
- perimetroM: se encargará de mostrar el perímetro correspondiente a la matriz cargada
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

void cargarMatriz(int** matriz, int rows, int column);
void mostrarMatriz(int** matriz, int rows, int column);
int sumaDP(int** matriz, int rows, int column);
void cantPIP(int** matriz, int rows, int column, int& par, int& impar);
int perimetroM(int** matriz, int rows, int column);
int main() {
  int rows = 4, column = 4;
  int op;
  int par = 0, impar = 0;
  char op2;
  cout << "MENU PRINCIPAL";

  int** matriz = new int* [rows];
  for (int i = 0; i < rows; i++) {
    matriz[i] = new int[column];
  }

  cargarMatriz(matriz, rows, column);

  do {
    cout << "OPCIONES DISPONIBLES:\n\n";
    cout << "1- Mostrar los elementos cargados";
    cout << "\n2- Hallar la sumatoria de la diagonal principal";
    cout << "\n3- Hallar la cantidad de pares e impares de la diagonal secundaria";
    cout << "\n4- Hallar el perimetro de la matriz" << endl;
    cout << "Ingrese se opcion: ";cin >> op;
    while ((op < 1) || (op > 4)) {
      cout << "ERROR. Las opciones disponibles estan del 1 al 4: ";cin >> op;
    }

    switch (op) {
    case 1:
      mostrarMatriz(matriz, rows, column);
      break;
    case 2:
      cout << "La sumatoria de la diagonal principal es: " << sumaDP(matriz, rows, column);
      cout << endl;
      break;
    case 3:
      cantPIP(matriz, rows, column, par, impar);
      cout << endl;
      break;
    case 4:
      int perimetro = perimetroM(matriz, rows, column);
      cout << "El perimero de la Matriz es: " << perimetro;
      cout << endl;
      break;
    }
    cout << "Desea seguir?(S/N): ";cin >> op2;
  } while ((op2 == 's') || (op2 == 'S'));

  for (int i = 0; i < rows; i++) {
    delete matriz[i];
  }
  delete[] matriz;
  return 0;
}
void cargarMatriz(int** matriz, int rows, int column) {
  cout << "\nCargando Matriz: \n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      cout << "Ingresar elementa " << i << "." << j << ": ";cin >> matriz[i][j];
    }
  }
}
void mostrarMatriz(int** matriz, int rows, int column) {
  cout << "\nLa matriz cargade es: " << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      cout << matriz[i][j] << "\t";
    }
    cout << endl;
  }
}
int sumaDP(int** matriz, int rows, int column) {
  int suma = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      if (i == j) {
        suma += matriz[i][j];
      }
    }
  }
  return suma;
}
void cantPIP(int** matriz, int rows, int column, int& par, int& impar) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      if (i + j == rows - 1) {
        if (matriz[i][j] % 2 == 0) {
          par++;
        }
        else {
          impar++;
        }
      }
    }
  }
  cout << "Cantidad de Pares e Impares de la Diagonal Secundaria\n";
  cout << "Pares: " << par << " y Impares: " << impar;
}
int perimetroM(int** matriz, int rows, int column) {
  int p = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      if ((i == 0) || (i == rows - 1) || (j == 0) || (j == column - 1)) {
        p += matriz[i][j];
      }
    }
  }
  return p;
}
//============================================================================
// Name        : Ejerc4.cpp
// Author      : Jonathan J. Areas
// Version     : Ultimate
// Copyright   : N.A.
// Description : Ingresar e imprimir una lista de nombres en una pila (LIFO)
//============================================================================

#include <iostream>
#define MAX 10

using namespace std;

struct Pila {
    int cola{};
    string nombres[MAX];
};

void crear(struct Pila * nuevo) {
    nuevo->cola = 0;
}

void apilar(struct Pila * ultimo, string entrada) {
    ultimo->nombres[ultimo->cola] = move(entrada);
    ultimo->cola++;
}

bool estaLlena(struct Pila * pila) {
    return(pila->cola  >= MAX);
}

void ingresar(Pila & pila);
void leer(const Pila & pila);

int main() {
    struct Pila pila;
    crear(&pila);
    ingresar(pila);
    leer(pila);
    return 0;
}

void ingresar(Pila & pila) {
    int n{};
    char nombre[30];
    cout << "Cuantos nombres desea ingresar?" << endl;
    cout << "NOTA: Cantidad de elementos ingresados debe ser un entero positivo menor o igual que " << MAX << endl;
    cin >> n;
    cout << "Ingrese " << n << " nombres." << endl;
    for (int i = 0; i < n; i++) {
        if (estaLlena(&pila)) {
            cout << "No hay mas espacios. La pila esta llena." << endl;
            break;
        } else {
            fflush(stdin);
            apilar(&pila, gets(nombre));
        }
    }
}

void leer(const Pila & pila) {
    cout << "Elementos Ingresados (LIFO): " << endl;
    for (int k = pila.cola - 1; k >= 0; k--)
        cout << pila.nombres[k] << endl;
}

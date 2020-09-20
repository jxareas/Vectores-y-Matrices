//============================================================================
// Name        : Ejerc1.cpp
// Author      : Francisco Molina, Jonathan J. Areas
// Version     : Ultimate
// Copyright   : N.A.
// Description : Obtener temperaturas mediante un vector, calcular la media aritmetica
//				y el numero de elementos mayores o iguales que la media.
//============================================================================

#include <iostream>

using namespace std;
void leerTemp(double vector[]);
double calcMedia(const double vector[]);
int MayorIgualqueMedia(const double * vector,  double media);
int n{};

int main() {
    cout << "Cuantas temperaturas desea ingresar al sistema?" << endl;
    cin >> n;
    auto * vector = new double[n];
    leerTemp(vector);
    double media = calcMedia(vector);
    cout << "\nEl resultado de la media aritmetica es: " << media << endl;
    cout << "Elemento(s) mayor(es) o igual(es) que la media: " << MayorIgualqueMedia(vector, media) << endl;
    return 0;
}

void leerTemp(double vector[]) {
    for (int i = 0; i < n; i++) {
        cout << "Introduzca la temperatura " << i + 1 << endl;
        cin >> vector[i];
    }
}

double calcMedia(const double vector[]) {
    double sum {};
    for (int j = 0; j < n; j++)
        sum += vector[j];
     return sum / n;
}

int MayorIgualqueMedia(const double * vector, double media) {
    int contador{};
    for (int k = 0; k < n; k++)
        contador += (vector[k] >= media) ? 1 : 0;
     return contador;
}

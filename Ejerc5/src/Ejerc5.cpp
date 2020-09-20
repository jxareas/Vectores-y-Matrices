//============================================================================
// Name        : Ejerc5.cpp
// Author      : Emiliano Urbina
// Version     : Ultimate
// Copyright   : N.A.
// Description : Ingresar e imprimir una lista de nombres en una cola (FIFO)
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;

#define maxSize 100

struct elemento{
    char name;
    string nombres[maxSize];
    int salida, entrada;
};

int vacia(struct elemento *cola){
    return(cola->salida >= cola->entrada);
};

int llena(struct elemento *cola){
    return(cola->entrada == maxSize);
};

void crearElemento(struct elemento *obj){
    obj -> salida = obj -> entrada = obj -> name = 0;
    return;
}

void encolar(struct elemento *cola, string elem){
    cola->entrada++;
    cola->nombres[cola->entrada] = elem;
    if(cola->salida > cola->entrada){
        cola->salida = 0;
        cola->entrada = maxSize-1;
    };

    return;
}




int main() {
    struct elemento cola;
    string dato;
    int i = 0;
    string letra;
    int indicador;
    char elem[30];
    crearElemento(&cola);

    cout<<"Cuantos nombres desea agregar?"<<endl;
    cin>>indicador;
    if(indicador >100){
        cout<<"Deben ser menos de 100 nombres."<<endl;

    };
    cout<<"Escriba "<<indicador<<" nombres"<<endl;

    do{
        if(llena(&cola)){
            cout<<"No hay mas espacio"<<endl;
        }else{
            gets(elem);
            dato = elem;
            encolar(&cola, dato);
        };
        i++;
    }while(i < indicador+1);


    cout<<"\n"<<"Esto es lo que se almaceno: "<<endl;
    for(int y = 0; y < cola.entrada+1; y++){
        cout<<cola.nombres[y]<<endl;
    };


    return 0;
}

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
#include "rlutil.h"
int main() {

int selector,puntos, max_puntos=0,vidas,cont=0;
bool salir=true,record=false;
char nombre[NOMBRE] = {};
char max_jugador[NOMBRE];

    selector = Mostrar_Menu();

    while(salir!=false) {

        switch(selector) {

        case 1:
            cont=HOLA(cont);
            cin >> nombre;
            puntos=jugar(cont,nombre,record,puntos);

            if(cont==1 || puntos > max_puntos) { // si el contador es 1 es el primer registro.record=true;
                max_puntos = puntos;
                for(int i=0; i<NOMBRE; i++) {
                    max_jugador[i] = nombre[i];
                }
            }
             selector = Mostrar_Menu();

            break;

        case 2:
            selector=RECORD(record,max_jugador,max_puntos,selector);
            break;

        case 3:
            selector=LEGAJOS(selector);
            break;

        case 0:
            salir=SALIR(salir);
            if(salir==true){
              selector = Mostrar_Menu();
            }
            break;
        default:
             selector=errorMENU(selector);
            break;
    }
    }
    rlutil::cls();
    saludo();
    system("pause");
    return 0;
}



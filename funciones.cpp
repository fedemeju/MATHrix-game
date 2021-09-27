#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
#include "rlutil.h"

int valores[CANT] = {}; //donde guardo los valores a checkear
int Mostrar_Menu(void) {

    int seleccion;
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
    cout << "                           MATHRIX                                     \n";
    rlutil::setBackgroundColor(rlutil::BLACK);
    cout<<"_______________________________________________________________________\n";
    cout << "\t\t\t 1 - JUGAR \n";
    cout << "\t\t\t 2 - ESTADISTICAS \n";
    cout << "\t\t\t 3 - CREDITOS \n";
    cout<<"_______________________________________________________________________\n";
    rlutil::setColor(rlutil::RED);
    cout << "\t\t\t 0 - SALIR \n";
    rlutil::setColor(rlutil::WHITE);
    cout<<"_______________________________________________________________________\n";
    cout<< "\n Elija una opcion: ";
    cin >> seleccion;
    cout<<"_______________________________________________________________________\n";
    return seleccion;
}
void cargar_10(int matr[][COLUMNAS]) {

    for(int i=0; i<FILAS; i++) {
        for(int j=0; j<COLUMNAS; j++) {
            matr[i][j] = 10;
        }
    }
}
void iniciar_matr(int matr[][COLUMNAS]) {
    srand(time(NULL));           // ESTO HACE QUE LA MATRIZ SEA SIEMPRE DISTINTA (la comente para que podamos hacer pruebas con una matriz siemrpe igual)

    for(int i=1; i<FILAS-1; i++) {
        for(int j=1; j<COLUMNAS-1; j++) {
            matr[i][j] = rand()%(10);
        }
    }
}
void mostrar_matr(int matr[][COLUMNAS] , int fil, int col) {

    int j;
    cout<<"   ";
    for(int i=1;i<COLUMNAS-1;i++){   //imprimir numero de columna
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout<<i<<" ";
        rlutil::setColor(rlutil::WHITE);
    }
    cout<<endl;
    for(int i=0; i<FILAS; i++) {

            if(i>0 && i<FILAS-1){   //imprimir numero de fila
                rlutil::setColor(rlutil::LIGHTCYAN);
                cout<<i;
                rlutil::setColor(rlutil::WHITE);
                }
                else{
                    cout<<" ";
                }
        for(j=0; j<COLUMNAS; j++) {
                rlutil::setBackgroundColor(rlutil::BLACK);
            if(matr[i][j] == 10) {
                rlutil::setBackgroundColor(rlutil::GREEN);
                cout<<"  ";
                rlutil::setBackgroundColor(rlutil::BLACK);
            }
            else {
               if(fil==i && col==j){
                rlutil::setBackgroundColor(rlutil::RED);   // PONGO EN ROJO LA POSICION DEL JUEGADOR
                cout<<matr[i][j]<<" ";
            }
            else{
                rlutil::setBackgroundColor(rlutil::BLACK);
                cout<<matr[i][j]<<" ";
            }
            }
        }
        cout<<"\n";
    }
}
char Operaciones (int matr[][COLUMNAS],int fil, int col) {

    char tip;
    rlutil::cls();
    cout<<endl;
    mostrar_matr(matr,fil,col); //LA MUESTRO PARA MOSTRAR LA POSICION
    cout<<"______________________________________________________________________\n\n";
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
    cout << "                           OPERACION                                  \n\n";
    rlutil::setBackgroundColor(rlutil::BLACK);
    cout<<" - Suma: (+) \n";
    cout<<" - Resta: (-) \n";
    cout<<" - Multiplicacion: (*) \n";
    cout<<" - Division (Cociente): (/) \n";
    cout<<" - Division (Resto): (%) \n\n";

    cout << "Ingrese el tipo de operacion que quiere realizar: ";
    cin >> tip;
    cout<<"_______________________________________________________________________\n";

    return tip;

}
int Movimientos() {

    int dire;
    cout<<"\n_______________________________________________________________________\n\n";
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
    cout << "                           DIRECCION                                   \n\n";
    rlutil::setBackgroundColor(rlutil::BLACK);
    cout<<"- Arriba: (8) \n";
    cout<<"- Abajo: (2) \n";
    cout<<"- Izquierda: (4) \n";
    cout<<"- Derecha: (6) \n\n";

    cout << "Ingrese la direccion teniendo en cuenta los siguientes valores: ";
    cin >> dire;
    cout<<"_______________________________________________________________________\n\n";
    return dire;
}
void mover_direccion(int matr[][COLUMNAS],int fil_e, int col_e, int direc[]) {

    for(int i=0; i<CANT; i++) {
        if(i==0) {
            valores[i] = matr[fil_e][col_e];
        }
        else {

            valores[i] = matr[fil_e][col_e];
        }

        fil_e += direc[0];
        col_e += direc[1];
    }
}
int check(int matr[][COLUMNAS], int fil_e, int col_e, int dir, int pos, bool FLAG) {  // matriz , fila , columna , tipo de operacion

    int movimiento[2] = {};

    switch(dir) {  // direccion de movimiento

    case 8:   // arriba

        movimiento[0] = -1;
        movimiento[1] = 0;
        mover_direccion(matr, fil_e, col_e, movimiento);
        borrar(matr, fil_e, col_e, movimiento, FLAG);
        break;

    case 2:  // abajo
        movimiento[0] = 1;
        movimiento[1] = 0;
        mover_direccion(matr, fil_e, col_e, movimiento);
        borrar(matr, fil_e, col_e, movimiento,FLAG);
        break;

    case 4:  //izq
        movimiento[0] = 0;
        movimiento[1] = -1;
        mover_direccion(matr, fil_e, col_e, movimiento);
        borrar(matr, fil_e, col_e, movimiento, FLAG);
        break;

    case 6:  //der
        movimiento[0] = 0;
        movimiento[1] = 1;
        mover_direccion(matr, fil_e, col_e, movimiento);
        borrar(matr, fil_e, col_e, movimiento, FLAG);
        break;
    }

    return valores[pos];
}
bool comprobar(int vec[CANT], char tipo) {

    bool flag = false;

    switch(tipo) {

    case '+':

        if(vec[0]+vec[1]==vec[2]) {
            flag = true;
        }
        break;

    case '-':

        if(vec[0]-vec[1]==vec[2]) {
            flag = true;
        }
        break;

    case '*':

        if(vec[0]*vec[1]==vec[2]) {
            flag = true;
        }
        break;

    case '/':

        if(vec[0]/vec[1]==vec[2]) {
            flag = true;
        }
        break;

    case '%':

        if(vec[0]%vec[1]==vec[2]) {
            flag = true;
        }
        break;


    }

    return flag;
}
void borrar(int matr[][COLUMNAS],int fil_e, int col_e, int direc[], bool FLAG) {    // borro si corresponde

    for(int i=0; i<CANT; i++) {
        if(FLAG == true && i == 0) {
            matr[fil_e][col_e]= 10;
        }
        else {
            if(FLAG == true) {
                matr[fil_e][col_e] = 10;
            }
        }
        fil_e += direc[0];
        col_e += direc[1];
    }

}
bool licito(int vec[CANT],char operacion) {
    bool licito=true;

    for(int i=0; i<CANT; i++) {
        if(vec[i] == 10) {
            licito = false;
        }
    }
        if(vec[1]==0 && operacion=='/' || operacion=='%'){   //division o resto cero
            rlutil::setBackgroundColor(rlutil::RED);
            cout << "NO se puede dividir por cero\n";
            rlutil::setBackgroundColor(rlutil::BLACK);
            licito = false;
                }
    return licito;
}
void VIDAS(int vidas) {
    switch (vidas)
    {
    case 3:
        cout<<endl;
        cout<<"PILAS: \n";
        rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
        cout<<"____\n""____\n"<<"____\n";
        rlutil::setBackgroundColor(rlutil::BLACK);
        break;

    case 2:
        cout<<endl;
        cout<<"PILAS: \n";
        rlutil::setBackgroundColor(rlutil::BROWN);
        cout<<"____\n""____\n";
        rlutil::setBackgroundColor(rlutil::BLACK);
        break;

    case 1:
        cout<<endl;
        cout<<"PILAS: \n";
        rlutil::setBackgroundColor(rlutil::RED);
        cout<<"____\n";
        rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    }
}
void CORRECTO(int valores[CANT],char operacion) {
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
    cout << "La operacion ingresada es correcta: " << valores[0] << " " << operacion << " " << valores[1] << " = " << valores[2] << endl << endl;
    rlutil::setBackgroundColor(rlutil::BLACK);
}
int INCORRECTO(int valores[CANT],char operacion,int vidas) {
    rlutil::setBackgroundColor(rlutil::RED);
    vidas--;
    cout << "La operacion ingresada es incorrecta: " << valores[0] << " " << operacion << " " << valores[1] << " != " << valores[2] << endl << endl;
    rlutil::setBackgroundColor(rlutil::BLACK);

    return vidas;
}
int INVALIDO(int valores[CANT],char operacion, int vidas) {
    rlutil::setBackgroundColor(rlutil::RED);
    cout << "Movimiento invalido, pierde una pila\n\n";
    rlutil::setBackgroundColor(rlutil::BLACK);
    vidas--;

    return vidas;
}
int  LEGAJOS(int selector){
    rlutil::cls();
    cout<<"_______________________________________________________________________\n";
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
    cout << "                        MORPHEUS - team                                \n";
    rlutil::setBackgroundColor(rlutil::BLACK);
    cout << "Wawryniuk Lucas - Legajo nro: 25263"<<endl;
    cout << "Linares Ivan - Legajo nro: 24996"<<endl;
    cout << "Mejuto Federico - Legajo nro: 24590"<<endl;
    cout<<"_______________________________________________________________________\n\n";
    selector = Mostrar_Menu();

    return selector;
}
bool SALIR(bool salida){

    int opcion;
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
    cout << "                      seguro que desea salir?                          \n";
    rlutil::setBackgroundColor(rlutil::BLACK);
    cout<<"_______________________________________________________________________\n";
    cout<< "1- Continuar \n";
    rlutil::setColor(rlutil::RED);
    cout<< "2- Salir \n";
    rlutil::setColor(rlutil::WHITE);
    cin>>opcion;

    if(opcion==2){
        salida=false;
    }
    rlutil::cls();
    return salida;

}
int RECORD(bool record, char vec[],int maximo,int selector){
    rlutil::cls();
    cout<<"_______________________________________________________________________\n";
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
    cout << "                           RECORD                                      \n";
    rlutil::setBackgroundColor(rlutil::BLACK);
    if(record == false) {
        cout << "Aun no se han registrado puntajes ): \n\n";
    }
    else {
        cout << "PUNTAJE MAXIMO: " << maximo<< endl;
        cout << "JUGADOR: ";

        for(int i=0; i<NOMBRE; i++) {
            cout << vec[i];
        }

        cout << endl << endl;
    }
    selector = Mostrar_Menu();
    return selector;
}
int HOLA(int cont){
    cont++; // cuento para encontrar el primer jugador
    rlutil::cls();  //funcion que limpia la pantalla
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
    cout<< "                       -BIENVENIDO A MATHRIX-                         \n";
    rlutil::setBackgroundColor(rlutil::BLACK);
    cout<<"_______________________________________________________________________\n\n";
    cout << "Ingrese su nombre (maximo 15 caracteres): ";
    return cont;

}
int ingreso_fila_col(int num){
    int pos;
    if(num==1){
    cout<<"\ningrese 0,0 para reiniciar la matriz(PERDERA UNA VIDA)\n";
    cout<<"_______________________________________________________________________\n\n";;
    cout << "Ingrese una fila: ";
    cin >> pos;
    }
    else{
    cout << "Ingrese una columna: ";
    cin >> pos;
    cout<<"________________________________________________________________________\n\n";
    }

    return pos;

}
void mostrar_puntos(int puntos, int vidas){
 if(vidas>0){
    cout << "Tu puntaje actual es: " << puntos << endl << endl;
    cout << "________________________________________________________________________\n\n";
 }
 else{
       cout << "Perdiste :(\n\n";
       cout << "Tu puntaje fue: " << puntos << endl;  // el puntaje final
       cout << "_______________________________________________________________________\n";
 }

}
void saludo(){
    cout<<"          (0 0)                  \n";
    cout<<"  ---oOO-- (_) ----oOO---        \n";
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
    rlutil::setColor(rlutil::BLACK);
    cout<<"                            \n";
    cout<<"    GRACIAS POR JUGAR       \n";
    cout<<"                            \n";
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    cout<<"   -------------------           \n";
    cout<<"         |__|__|                 \n";
    cout<<"          || ||                  \n";
    cout<<"         ooO Ooo                 \n\n\n";
}
int PARCIAL(bool volver, int fil, int col,int vidas,int matr[][COLUMNAS]){
        if(fil==0 && col ==0){
            volver=true;
        }
        rlutil::cls();  //funcion que limpia la pantalla
        if(volver==true){
            rlutil::setBackgroundColor(rlutil::RED);
            cout<<"INGRESO 0,0 pierde una vida y se reinicia la matriz \n\n";
            rlutil::setBackgroundColor(rlutil::BLACK);
            cargar_10(matr);
            iniciar_matr(matr); // pone numeros aleatorios
            vidas--;;
          }

        return vidas;
}
int jugar(int cont,char nombre[],bool record,int puntos){

    int selector, vidas,vidaA;
    int fil=0, col=0, direc, i, ronda=0;
    char operacion,calcu[NOMBRE] = {};
    int matriz [FILAS][COLUMNAS];
    int numeros[CANT];
    bool FLAG, LICITO, volver=false;

            cargar_10(matriz);
            iniciar_matr(matriz); // pone numeros aleatorios
            vidas = VIDAS_MAX;
            puntos=ronda=0;
            cout << "Ingrese su modelo de calculadora favorito: ";
            cin >> calcu;
            cout<<"_______________________________________________________________________\n";
            rlutil::cls();

            while(vidas > 0) {
                inicio:
                fil=col=0;  // las pongo en cero para que no marque nada en la matriz
                ronda++;
                cout << "\nRonda numero: " << ronda <<"\n";
                cout<< "JUGADOR: " << nombre <<endl<<endl;
                mostrar_puntos(puntos,vidas); // muestro puntaje de la ronda

                FLAG = false;   // la tengo que volver a poner en falso cada vez
                mostrar_matr(matriz,fil,col);
                VIDAS(vidas); //grafico pilas
                fil=ingreso_fila_col(1); //fila
                col=ingreso_fila_col(2);  //columna
                vidaA=vidas; // control de vidas

                vidas=PARCIAL(volver,fil,col,vidas,matriz); //CAMBIO PEDIDO POR EL PARCIAL
                volver=false;

                if(vidas>0 && vidas==vidaA){ // si ingreso 00 en PARCIAL resto una vida y no tengo que entrar aca

                operacion = Operaciones(matriz,fil,col); // muestro y pido operacion
                direc = Movimientos(); // muestro y pido direccion
                rlutil::cls();  //funcion que limpia la pantalla

                for(i=0; i < CANT; i++) {
                    numeros[i] = check(matriz, fil, col, direc, i, FLAG);     // cargo los numeros (a analizar) en el vector
                }

                LICITO = licito(numeros,operacion); // se fija que no este fuera de rango

                if(LICITO == true) {

                    FLAG = comprobar(numeros, operacion);   // veo si esta bien la operacion matematica
                    check(matriz, fil, col, direc, cont, FLAG);   // la llamo denuevo para usar la funcion borrar

                    if(FLAG == false) {
                        vidas = INCORRECTO(numeros,operacion,vidas);
                    }
                    else {                                              // si es verdadero sumo los puntos y muestro operaccion
                        CORRECTO(numeros,operacion);
                        puntos += numeros[0] + numeros[1] + numeros[2];
                    }
                }
                else {
                    vidas = INVALIDO(numeros,operacion,vidas);
                }
            }
            vidaA=vidas;
            }
            fin:
            mostrar_puntos(puntos,vidas); // muestro puntaje de la ronda


            return puntos;
}
int errorMENU(int selector){

    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::RED);
    cout<<"OPCION INVALIDA \ningrese nuevamente:\n";
    rlutil::setBackgroundColor(rlutil::BLACK);
    selector = Mostrar_Menu();

    return selector;

}




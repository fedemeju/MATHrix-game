#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

const int FILAS = 8;
const int COLUMNAS = 8;
const int VIDAS_MAX = 3;
const int NOMBRE = 15;
const char CALC = 15;
const int CANT = 3;

int Mostrar_Menu(void); //menu principal
char Operaciones(int matr[][COLUMNAS],int,int);//menu con las operaciones matematicas
int Movimientos();//menu para señalar los movimientos del jugador
void mostrar_matr(int matr[][COLUMNAS],int,int);//dibuja la matriz recibida
void iniciar_matr(int matr[][COLUMNAS]);//inicializa con numeros aleatorios entre 0 y 10(desde la pos 1 hasta la 6)
bool comprobar(int vec[CANT],char tipo);  // comprueba si la operacion esta bien
int check(int matr[][COLUMNAS],int fil_e,int col_e, int dir, int pos, bool FLAG);  // busca los elementos de la matriz a partir de la direccion
void mover_direccion(int matr[][6],int fil_e, int col_e, int dir[]); // complemento para check
void borrar(int matr[][COLUMNAS],int fil_e, int col_e, int direc[], bool FLAG);
void cargar_10(int matr[][COLUMNAS]); // Inicializo la matriz con un 10 en cada posicion
bool licito(int vec[CANT],char); //controlo de que el movimiento sea licito
void VIDAS(int vidas); //pilas manera visual
void CORRECTO(int valores[CANT],char);
int INCORRECTO(int valores[CANT],char operacion, int vidas); // si esta mal la operacion resto vida
int INVALIDO(int valores[CANT],char operacion, int vidas);
int LEGAJOS(int selector);
bool SALIR(bool salida);  // queres salir?
int RECORD(bool record, char vec[], int maximo,int selector);// muestra el record, si lo hay
int HOLA(int);
int ingreso_fila_col(int);
void mostrar_puntos(int puntos, int vidas);
void saludo();
int PARCIAL(bool,int,int,int,int matr[][COLUMNAS]); // funcion parcial
int jugar(int cont,char nombre[],bool record,int puntos);
int errorMENU(int selector);




#endif // FUNCIONES_H_INCLUDED

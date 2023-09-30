#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

const int n = 3;                                                                // delaro como constante global a "n" que sera mi tamaño de matriz para todo el programa
bool matrizCargada = false;                                                     // declaro una variable booleana para gestionar el control de la carga de la matriz en todo el programa
                                                
void menu();                                                                    // declaro todos los prototipos de las fucniones con las que voy a trabajar.
void menucarga();
void menubusqueda();
void menuOrdena();
void carga(int matriz[n][n],bool&);
void carga1(int matriz[n][n],bool&);
void carga2(int matriz[n][n],bool&);
void mostrarMatriz(int matriz[n][n],bool&);
void buscarElemento(int matriz[n][n],bool&);
void MayoroMenor(int matriz[n][n],bool&);
void ordenarMatriz(int matriz[n][n],bool&);
void determinante(int matriz[n][n],bool&);
void ascendente(int matriz[n][n],bool&);
void descendente(int matriz[n][n],bool&);
bool numeroValido(string&, int&);
int IngresoNumeroEntero(string);

int main(){
    
    int opcion = 0;                                                             // declaro la variable opcion que sirve para gestionar las opciones ingresadas por el usuario
    int matriz[n][n];                                                           // declaro la matriz con la que voy a trabajar a lo largo del programa
    
    do{        
    menu();                                                                     // llama a la funcion menu que contiene el cartel con las opciones a elejir por el usuario
    opcion = IngresoNumeroEntero("Ingrese Una Opcion:");                        // Ingreso la opcion mediante la funcion que controla que se ingresen valores correctos
   
     switch(opcion){                                                            // El switch gestiona a que funcion deribar el programa segun el numero ingresado por el usuario.
            case 1: carga(matriz,matrizCargada);
                    break;   
            case 2: mostrarMatriz(matriz,matrizCargada);
                    break;
            case 3: buscarElemento(matriz,matrizCargada);       
                    break;
            case 4: MayoroMenor(matriz,matrizCargada);
                    break;
            case 5: ordenarMatriz(matriz,matrizCargada);
                    break;
            case 6: determinante(matriz,matrizCargada);
                    break;
            case 7: cout << "Saliendo del programa.." << endl;                      // muestra el cartel de "Saliendo" antes de terminar el programa.
                break;
            default: cout << "Opcion incorrecta!, Intentelo denuevo"<< endl;        // cualquier opcion diferente de los dnumeros mostrados mostrara el carte de opcion incorrecta.

        }
           getch();                                                                    // da tiempo a presionar una tecla par continuar con la ejecucion.
           //system("cls");             //limpia la pantalla para volver a mostrar solo el menu principal, esta comentado porque solo funciona con el ejecutable(.exe)

    }while(opcion != 7);                                                            // este while se ejecutara indefinidamente hasta que se presione el numero 7(salir).

    return 0;
}

void menu(){                                                                        // funcion que contiene el cartel general de opciones
    cout << endl;
    cout << "    -----*********************************************************************************----" << endl;
    cout << "    -----********************************* MENU PRINCIPAL ********************************----" << endl;
    cout << "    ------------------------------------------------------------------------------------------" << endl;
    cout << "    ---- 1 * CARGAR MATRIZ (MANUAL O ALEATORIO)                                           ----" << endl;
    cout << "    -----                                                                                 ----" << endl;
    cout << "    ---- 2 * MOSTRAR MATRIZ                                                               ----" << endl;
    cout << "    -----                                                                                 ----" << endl;
    cout << "    ---- 3 * BUSCAR UN ELEMENTO EN LA MATRIZ                                              ----" << endl;
    cout << "    -----                                                                                 ----" << endl;
    cout << "    ---- 4 * MOSTRAR VALOR (MAXIMO O MINIMO)                                              ----" << endl;
    cout << "    -----                                                                                 ----" << endl;
    cout << "    ---- 5 * ORDENAR MATRIZ (ASCENDENTE / DESCENDENTE)                                    ----" << endl;
    cout << "    -----                                                                                 ----" << endl;
    cout << "    ---- 6 * CALCULAR EL DETERMIANTE DE LA MATRIZ 3X3                                     ----" << endl;
    cout << "    -----                                                                                 ----" << endl;
    cout << "    ---- 7 * SALIR DEL PROGRAMA                                                          ----" << endl;
    cout << "    -----********************************************************************************-----" << endl;
    cout << endl;

}
                                                                                    // funcion dedicada a gestionar los dos tipos de carga diferentes del programa
void carga(int matriz[n][n], bool &cargada){
        int carga;                                                                  // defino una variable para seleccionar una de las dos opciones
        do{
        menucarga();                                                                // llamo a la funcion que contiene el cartel que muestra las opciones de carga
           carga = IngresoNumeroEntero("Esperando Opcion: ");                       // mediante el llamado a la funcion que controla los ingresos le asigno a la variable dicho ingreso
           switch(carga){                                                           // el switch gestina las opciones ingresadas
                     case 1: carga1(matriz,matrizCargada);                          // opcion 1 llama a la funcion que genera el ingreso aleatorio
                            cout <<"Matriz cargada correctamente con valores Aleatorios"<< endl; // una vez cargada muestra el cartel de que se completo dichna cargva
                             break;
                     case 2: carga2(matriz,matrizCargada);                          // opcion 2 llama a la funcion que genera el ingreso manual de los elementos de la matriz      
                            cout <<"Matriz cargada correctamente!";                 // luego muestra el cartel de que se completo la cargva
                             break;
                     default: cout << "Opcion incorrecta!, Intentelo denuevo"<< endl;   // si se ingresa una opcion diferente a las permitidas muestra el cartel de ikncorrecto.
                             break;
                    } 
        }while(carga != 1 && carga != 2);                                           // el bucle se ejecutara hasta que las opciones no sean 1 o 2.

}

void menucarga(){       
    cout << endl;                                                    //funcion que contiene los carteles del menu de carga.
    cout << "---***************************************---" << endl;
    cout << "--- Ingrese La Forma de Cargar La Matriz  ---"<< endl;
    cout << "---------------------------------------------" << endl;
    cout << "--- 1 * Cargar Con numeros aleatorios:    ---"<< endl;
    cout << "--- 2 * Cargar Ingresando valores:        ---"<< endl;
    cout << "---***************************************---" << endl;
    cout << endl;

}

void carga1(int matriz[n][n], bool& cargada){                       //funcion que maneja la carga aleatoria de la matriz, paso como parametros la matriz y variable booleana de control
    srand(time(NULL));                                              // parte de la funcion rand que genera numeros aleatorios
           
    for(int i= 0; i < n ; i++){
        for(int j= 0; j < n ; j++){
            matriz[i][j]= rand() % 100 + 1;                         // recorro la matriz ingresando en cada posicion un elemento generado por la funcion rand().
        }
    }
    cargada = true;                                                 // cambio el estado de la variable booleana a true ya que fue cargada
}

void carga2(int matriz[n][n], bool& cargada){                       //funcion que maneja la carga manual de la matriz, paso como parametros la matriz y variable booleana de control
    
    int nro;                                                        // declaro una variable entera que me va a srvir para ingresar los elementos de la matriz
    
    for(int i= 0; i < n ; i++){
        for(int j= 0; j < n ; j++){                                 // recorro la matriz para ir ingresando cada valor
            cout << "Ingrese un valor para la posicion: "<< i + 1 << " " << j + 1 << endl;
            nro = IngresoNumeroEntero("Valor: ");                   // llamo a la funcion que controlo el ingreso asignando el valor controlado a la variable nro
            matriz[i][j]= nro;                                      // asigno a cada posicion el valor ingresado y controlado previamente
        }
    }
    cargada = true;                                                 // cambio el estado de la variable de control a true ( matriz cargada)
}

void mostrarMatriz(int matriz[n][n],bool& cargada){                       // funcion que se encarga de mostrar la matriz se pasan como parametros la matriz y la variable booleana de control
   if (cargada){ 
     cout << endl;                                              // si la matriz esta cargada realiza el recorrido y muestra de elementos en pantalla
     for(int i= 0; i < n ; i++){
        for(int j= 0; j < n ; j++){                             //recorro la matriz
            if(j == 0){                                         //sola para la primera linea muestrp la barra
                cout <<"|";
            }
           cout << "\t" << matriz[i][j];                        //imprimo cada elemento de la matriz con una tabulacion para mejor visualizacion
           if(j == 2){
            cout <<"\t|";                                       // nuevamente "cierro" la matriz con una barra en la ultima posicion
           }
        }
       cout << endl;                                            //saltos de linea para una visualizacion mas atractiva
       cout << endl;
     }
    }else{                                                      // de lo contrario muestra un cartel para que primero realice la carga de la matriz
        cout << "Primero debe cargar la matriz!";
    }
 }
    
void buscarElemento(int matriz[n][n], bool& cargada){                //funcion que se encarga de  realizar la busqueda de un elemento ingresado por el ususario
    if(cargada){                                                    //controlo que la matriz primero haya sido cargada
    int nro, posi, posj;                                            // declaro variables para el numero a buscar y para guardar las posiciones donde se encontro el elemento
    bool encontrado = false;
    do{
    nro = IngresoNumeroEntero("Ingrese numero a buscar: ");         //nuevamente controlo el ingreso del numero a buscar utilizando la funcion de ingreso de Numeros
    }while(nro < -100 && nro > 100);                                //repite hasta que ingrese un numero entre los valores -100 y 100.

        for(int i= 0; i < n ; i++){                                 // recorro la matriz
            for(int j= 0; j < n ; j++){
                if(nro == matriz[i][j]){                            //comparo cada elemento de la matriz con el numero ingresado
                 encontrado = true;                                 //si lo encuentro cambio el estado de la variable booleana
                 posi = i + 1;                                      //guardo las posiciones donde se encontro el elmento
                 posj = j + 1;
                }
            }
        }

    if(encontrado){                                                 //pregunto si la variable de busqueda booleana es positiva entonces muestro el numero y donde fue encontrado
            cout << "El Numero "<< nro << " Fue encontrado en la posicion "<< "[" << posi << "," << posj << "]" << endl;
         }else{
            cout << "Numero no encontrado " << endl;                // de lo contrario muestro que no fue encontrado
         }
    }else{
        cout << "Primero debe cargar la matriz" << endl;            //si la matriz no fue cargada muestro cartel
    }
    
}

void menubusqueda(){       
    cout << endl;                                                    //funcion que contiene los carteles del menu de busqueda.
    cout << "---***************************************---" << endl;
    cout << "---     Menu De Busqueda En La Matriz     ---"<< endl;
    cout << "---------------------------------------------" << endl;
    cout << "--- 1 * Buscar El Mayor:                  ---"<< endl;
    cout << "--- 2 * Buscar El Menor:                  ---"<< endl;
    cout << "---***************************************---" << endl;
    cout << endl;

}


void MayoroMenor(int matriz[n][n], bool &cargada){                  //funcion que se encarga de buscar el mayor o el menor de los elementos de la matriz
   if(cargada){                                                     //controlo que la matriz haya sido cargada previamente
    int mayor, menor, op = 0;                                       // declaro las variables que voy a utilizar para las busquedas de los elementos

    do{                                         
    menubusqueda();                                                 //muestro el menu de busqueda llamando a dicha funcion
    op= IngresoNumeroEntero("Opcion: ");                            //llamo a la funcion de ingreso para realizar el mismo y controlar lo que se ingresa
    cout << endl;
    }while((op != 1) && (op != 2));                                 //repite le bucle hasta que se ingrese las opciones correspondientes

    mayor = matriz[0][0];                                           //a la variable "mayor" le asigno la primera posicion de la matriz
    menor = matriz[0][0];                                           //hago lo mismo para la variable "menor"
    if(op == 1){                                                    //si la opcion ingresada es 1 realizo la busqueda del mayor
     for(int i= 0; i < n ; i++){
        for(int j= 0; j < n ; j++){
           if(matriz[i][j] > mayor){                                //recorro la matriz y voy preguntando por cada elemento si el actual es mayor que el anterior
            mayor = matriz[i][j];                                   //si la condicion es verdadera le asigna a la variable "mayor" mi nuevo mayor
           }
        }
      }
      cout << "El Mayor de la matriz es: "<< mayor << endl;         // muestro cual fue el valor mayor encontrado
      mostrarMatriz(matriz,matrizCargada);                          //muestro la matriz completa
    }else{                                              
        for(int i= 0; i < n ; i++){
            for(int j= 0; j < n ; j++){                             //si la opcion fue la 2 relizo el mismo proceso solo que comparando con menor y preguntando si es menor
                 if(matriz[i][j] < menor){                      
                   menor = matriz[i][j];                            //si la condicion es verdadera asigno mi nuevo valor menor a mi variable "menor"
                 }
            }
        }
        cout << "El Menor de la matriz es: "<< menor << endl;       //muestro el el menor valor encontrado
        mostrarMatriz(matriz,matrizCargada);                        //muestro la matriz
    }
   }else{
    cout << "Primero debe cargar la matriz" << endl;                //como en todas las fucniones si la matriz no fue cargada previamente se mostrara el cartel
   }
    
}

void menuOrdena(){       
    cout << endl;                                                    //funcion que contiene los carteles del menu de Ordenamiento de la matriz
    cout << "---***************************************---" << endl;
    cout << "--- Ingrese La Forma de Ordenar La Matriz ---"<< endl;
    cout << "---------------------------------------------" << endl;
    cout << "--- 1 * Ordenar de Manera Ascendente:     ---"<< endl;
    cout << "--- 2 * Ordenar de Manera Descendente:    ---"<< endl;
    cout << "---***************************************---" << endl;
    cout << endl;

}

void ascendente(int matriz[n][n], bool &cargada)                //funcion que se encarga de ordenar la matriz de forma ascendente
{
    const int m = 9;                                            //declaro las variables y constantes que voy a autilizar en el programa
    int aux, c = 0, arreglo[m];

     for(int i= 0; i < n ; i++){                                //recorro la matriz y asigno cada valor a un nuevo arreglo unidimencional
        for(int j = 0; j < n ; j++){
            arreglo[c] = matriz[i][j];
            c++;
        }
      }
      for(int i = 0; i < m ; i++){                              //realizo el ordenamiento mediante el metodo de burbujeo del arreglo anterior
        for(int j = 0; j < m-1-i ; j++){
            if(arreglo[j+1] < arreglo[j]){                      //comparo si el siguiente elemento de la matriz es menor que el actual
                aux = arreglo[j+1];                             //si es asi lo almaceno en una variable auxiliar
                arreglo[j+1] = arreglo[j];                      //al elemnto siguiente le asigno el elemento actual
                arreglo[j] = aux;                               //con este paso termino el intercambio de los elementos
            }
            }
        }
        c = 0;                                                  //vuelvo el contador a 0 para volver a formar la matriz 3x3
        for(int i= 0; i < n ; i++){                             //realizo un recorrido y voy asignando los nuevos valores ordenados del arreglo a la matriz 
         for(int j = 0; j < n ; j++){
            matriz[i][j] = arreglo[c];
            c++;
        }
      }

}

void descendente(int matriz[n][n], bool &cargada)               //funcion que se encarga de ordenar la matriz de forma descendente
{
    const int m = 9;                                            //declaro las variables y constantes que voy a autilizar en el programa
    int aux, c = 0, arreglo[m];

     for(int i= 0; i < n ; i++){                                //recorro la matriz y asigno cada valor a un nuevo arreglo unidimencional
        for(int j = 0; j < n ; j++){
            arreglo[c] = matriz[i][j];
            c++;
        }
      }
      for(int i = 0; i < m ; i++){                               //realizo el ordenamiento mediante el metodo de burbujeo del arreglo anterior
        for(int j = 0; j < m-1-i ; j++){                         
            if(arreglo[j+1] > arreglo[j]){                       //comparo si el siguiente elemento de la matriz es mayor que el actual
                aux = arreglo[j+1];                              //si es asi lo almaceno en una variable auxiliar 
                arreglo[j+1] = arreglo[j];                       //al elemnto siguiente le asigno el elemento actua
                arreglo[j] = aux;                                //con este paso termino el intercambio de los elementos
            }
            }
        }
        c = 0;                                                     //vuelvo el contador a 0 para volver a formar la matriz 3x3
        for(int i= 0; i < n ; i++){       
         for(int j = 0; j < n ; j++){                               //realizo un recorrido y voy asignando los nuevos valores ordenados del arreglo a la matriz 
            matriz[i][j] = arreglo[c];
            c++;
        }
      }

}


void ordenarMatriz(int matriz[n][n], bool &cargada){                //Funcion que se encarga de ordenar la matriz segun la opcion elegida ascendente o Desendente
    if (cargada){                                                   //controlo que la matriz haya sido cargada previamente
    int op;                                                         //declaro las variables a utilizar en el programa
    do{
    menuOrdena();                                                   //muestro el menu de opciones de ordenamiento llamando a la fucnion correspondiente
    op = IngresoNumeroEntero("Opcion: ");                           //llamo a la funcion que controla el ingreso por consola y lo repito con un bucle para que solo acepte 1 o 2
    }while(op != 1 && op != 2); 

    if( op == 1){   
        ascendente(matriz,matrizCargada);                           //si la opcion es 1 llamo a la funcion que realiza el ordenamiento de forma Ascendente
    }else{                                                          //de lo contrario llamo a la funcion que realiza el ordenamiento de forma Descendente
        descendente(matriz,matrizCargada);
    }
    cout << endl;
    mostrarMatriz(matriz,matrizCargada);                            // llamo a la funcion de muestra para mostrar la matriz ordenada de la forma elegida

    }else{
        cout << "Primero debe cargar la matriz" << endl;
    }

}

void determinante(int matriz[n][n], bool &cargada){             //Funcion que calcula el determinante de una matriz 3x3     
    if (cargada){                                               //utilizando como metodo de referencia el llamado Sarrous par encontrar el determinante
    int t1=0,t2=0,t3=0,t4=0,t5=0,t6=0,s1=0,s2=0, det = 0;       //defino variables para utlizar y separar los terminos y que sea mas visible
    cout << "El determinante de la Matriz: "<< endl;   
    mostrarMatriz(matriz,matrizCargada);                        //llamo a la funcion para de muestra de matriz 
    
    t1 = matriz[0][0] * matriz[1][1] * matriz[2][2];            //Mediante el metodo Sarrous hago los calculos para las posiciones especificas
    t2 = matriz[1][0] * matriz[2][1] * matriz[0][2];            //y asi hallar el determiante
    t3 = matriz[2][0] * matriz[0][1] * matriz[1][2];
    t4 = matriz[1][0] * matriz[0][1] * matriz[2][2];
    t5 = matriz[0][0] * matriz[2][1] * matriz[1][2];
    t6 = matriz[2][0] * matriz[1][1] * matriz[0][2];
    s1 = t1 + t2 + t3;
    s2 = t4 + t5 + t6;
    det = s1 - s2;
    cout << "Es: " << det << endl;                              //muestro el numero final de los calculos que corresponden al determinante

    }else{
        cout << "Primero debe cargar la matriz" << endl;        //al igual que las otras funciones si la matriz no fue cargada mostrara el cartel 
    }


}

bool numeroValido(string &cadena, int& numero)         //funcion que controla el ingreso por teclado, como parametro recibe un dato de tipo string y 
{                                                      //devuelve un dato de tipo entero si se ingreso un digito de ese tipo, ademas de cambiar el estado de la funcion a true.
    bool esValido = false, valido = false;             // declaro las variables necesarias para realizar el proceso
    int i = 0, largo = cadena.length();                // declaro un indice y un tope que me lo da el largo del string ingresado

    while(i < largo && !esValido){                     //con un mietras recorro cada caracter de la cadena y comparo que no sea un caracter difirente de un numero del 0 al 9
        if( cadena[i] != '0' && cadena[i] != '1' && cadena[i] != '2' && cadena[i] != '3' && cadena[i] != '4' && cadena[i] != '5' && cadena[i] != '6' && cadena[i] != '7' && cadena[i] != '8' && cadena[i] != '9'){
            esValido = true;                           // si ingresa en esta condicon es porque encontro un caracter diferente a un numero cualquiera este sea y esto nos saca del ciclo while
            
        }else{
            valido = true;                             //si no encontro ningun caracter diferente a los 10 digitos decimales le asigna true a la variable "valido"
        }
        i++;                                           //incrementa el indice para poder recorrer todo el string
    }
        if (valido){                                   //si la variable "valido" esta en true utilizo la funcion "stoi" que convierte el string a entero y se lo asigno a la variable "numero"
            numero = stoi(cadena);
        }

    return valido;                                     // retorno el valor de la variable "valido"
}

int IngresoNumeroEntero(string cartel)                 //funcion con la que genero un ingreso con "cartel" de parametro
{
    string cadena;
    int numero;                                        //defino las variables que voy a utilizar
    bool valido;

    do{
        cout << cartel;                                //muestro el cartel pasado por parametro en la llamada a la funcion
        cin >> cadena;
        valido = numeroValido(cadena,numero);          //llamo la funcion numeroValido para controlar que sea un digito correcto la misma al ser booleana me permite realizar el bucle
        if(!valido){  
            cout << endl;                                 //para solicitar un nuevo ingreso si es incorrecto
            cout <<"Ingreso Incorrecto, intente nuevamente.." << endl;
        }
    }while(!valido);                                   // se repetira el bucle hasta que se ingrese un digito correcto por teclado

    return numero;                                     //la funcion de tipo entera se lleva el numero ingresado como retorno
}
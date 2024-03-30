#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {


    // Guardar el alfabeto
    //*-----------------------------------------------------------*
    vector<string> alfabeto; 
    int i = 0;
    string caracter;
    string cadena;
    getline(cin, caracter);

    while(caracter[i] != '\0') 
    {
        while(caracter[i] != ' ' && caracter[i] != '\0')
        {
            cadena += caracter[i];
            i++;
        }

        alfabeto.push_back(cadena);
        cadena = "";

        if(caracter[i] == ' '){i++;}
    }
    //*-----------------------------------------------------------*

    //Guardar estados
    //*-----------------------------------------------------------*
    vector<string> estados;
    i = 0;
    cadena = "";
    string input_estados;
    getline(cin, input_estados);



    while(input_estados[i] != '\0')// input_estados = q0 q1 q2 cadena = q0 estados[0] = q0
    {
        while(input_estados[i] != ' ' && input_estados[i] != '\0')
        {
            cadena += input_estados[i];
            i++;
        }
        estados.push_back(cadena);
        cadena = "";

        if(input_estados[i] == ' '){i++;}
    }
    //*-----------------------------------------------------------*

    // Estado inicial
    //*-----------------------------------------------------------*
    string estado_inicial; //Perhaps toca cambiarlo
    getline(cin, estado_inicial);
    //*-----------------------------------------------------------*

    // Estados finales
    //*-----------------------------------------------------------*
    vector<string> estados_finales;

    i = 0;
    cadena = "";

    string estadoF;
    getline(cin, estadoF);


    while(estadoF[i] != '\0')
    {
        while(estadoF[i] != ' ' && estadoF[i] != '\0')
        {
            cadena += estadoF[i];
            i++;
        }
        estados_finales.push_back(cadena);
        cadena = "";

        if(estadoF[i] == ' '){i++;}
    }

    //*-----------------------------------------------------------*

    //Transiciones
    //*-----------------------------------------------------------*
    vector<string> transiciones;

    string input_trans;
    getline(cin, input_trans);

    i = 0;
    cadena = "";

    while(input_trans[i] != '\0') //q0,a->q1 q0,b->q2 q1,a->q1 q1,b->q2 q2,a->q2 q2,b->q2
    {
        while(input_trans[i] != ' ' && input_trans[i] != '\0')
        {
            cadena += input_trans[i]; //cadena = q0,a->q1 
            i++;
        }
        transiciones.push_back(cadena);
        cadena = "";

        if(input_trans[i] == ' '){i++;}
    }
   //*-----------------------------------------------------------*
      //alfabeto
      //estados
      //estado_inicial
      //estados_finales
      //transiciones

    //Cadenas a verificar
    //*-----------------------------------------------------------*

    int n;
    cin>>n;
    bool validar;
    bool seguir = true;
    string expresiones[n];
    string aux_expresiones;

    string estado_actual;
    estado_actual = estado_inicial; //q0


    string aux_transiciones; 
    string aux_estado1;
    string aux_estado2;



    //variables de conteo
    size_t j = 0;
    size_t k = 0;

    for(int i = 0; i<n; i++)
    {
        cin>>expresiones[i];
    }

                                                    //0        1        2        3       4        5
    for(int i = 0; i<n; i++) //aabab, aababa     q0,a->q0 q0,b->q1 q1,a->q1 q1,b->q2 q2,a->q1 q2,b->q1
    {
        aux_expresiones = expresiones[i]; //aabab

        while(k < transiciones.size())// 0 < 6
        {
            aux_transiciones = transiciones[k]; //q0,a->q0

            aux_estado1 = aux_transiciones[0]; 
            aux_estado1 += aux_transiciones[1];//q0 
            aux_estado2 = aux_transiciones[6]; 
            aux_estado2 += aux_transiciones[7]; //q0 

            while(estado_actual == aux_estado1) //q0 = q0
            {
                if(j < aux_expresiones.size() && aux_expresiones[j] == aux_transiciones[3]) //a == b
                {
                    if(estado_actual == aux_estado2)
                    {
                        seguir = false;
                    }
                   estado_actual = aux_estado2; //q1
                    j++;       
                }

                if(seguir)
                {
                    k++;
                    aux_transiciones = transiciones[k]; //q0,b->q1
                    aux_estado1 = aux_transiciones[0];  
                    aux_estado1 += aux_transiciones[1]; //q0
                    aux_estado2 = aux_transiciones[6]; 
                    aux_estado2 += aux_transiciones[7]; //q1    
                }
                seguir = true;
            }
            k++;     
        }

        validar = false;
        for(size_t h = 0; h<estados_finales.size(); h++)
        {
            if(estado_actual == estados_finales[h])
            {
               validar = true;
               break; 
            }
        }
        if(validar)
        {
            cout<<"ACEPTADA"<<endl;
        }else
        {
            cout<<"RECHAZADA"<<endl;
        }

        estado_actual = estado_inicial; 
        j=0;
        k=0;
    }


    return 0;
}
#include <iostream>
#include <conio.h>

using namespace std;

struct Estudiante
{
	char nombre[20];
	int edad;
	float promedio;
} estudiantes[3];

float promedio_edad(int n)
{
	int sum = 0;
	for(int i = 0; i<n; i++)
	{
		sum += estudiantes[i].edad; 
	}	
	return 	sum/n;
} 


float promedio_prom(int n)
{
	float sum = 0;
	for(int i = 0; i<n; i++)
	{
		sum += estudiantes[i].promedio; 
	}	
	return 	sum/n;
} 

int main()
{
	int mayor = 0, menor = 0, posMa, posMe, n;
	
	do 
	{
		cout<<"Cantidad de estudiantes: "; cin>>n;	
	}while(n<=1);
	
	for(int i = 0; i<n; i++)
	{
		
		cout<<"Nombre: "; cin>>estudiantes[i].nombre;
		cout<<"Edad: ";cin>>estudiantes[i].edad;
		cout<<"Promedio: ";cin>>estudiantes[i].promedio; cout<<endl;
		
		if(estudiantes[i].promedio >= mayor)
		{
			mayor = estudiantes[i].promedio;
			posMa = i;
		}
	}
	
	menor = mayor;
	
	for(int i = 0; i<n; i++)
	{
		if( estudiantes[i].promedio <= menor)
		{
			menor = estudiantes[i].promedio;
			posMe = i;
		}
	}
	cout<<"           				Datos de los estudiantes                   "<<endl<<endl;
	cout<<"El estudiante "<<estudiantes[posMa].nombre<<" tiene el mayor promedio con: "<<estudiantes[posMa].promedio<<endl;
	cout<<"El estudiante "<<estudiantes[posMe].nombre<<" tiene el menor promedio con: "<<estudiantes[posMe].promedio<<endl;
	cout<<"El promedio de la edad de los estudiantes es: "<<promedio_edad(n)<<endl;
	cout<<"El promedio de las notas de los estudiantes es: "<<promedio_prom(n)<<endl;
	
}

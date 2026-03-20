#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numero[10], *dir_numeros;
	
	for(int i=0; i<10; i++){
	cout<<"Digite un numero["<<i<<"]: ";
	cin>>numero[i]; 
	}
	
	dir_numeros = numero;
	
	for(int i=0; i<10; i++){
		if(*dir_numeros % 2 != 0){
			cout<<"El Numero"<<*dir_numeros<<" es Impar"<<endl;
			cout<<"Posicion. "<<dir_numeros<<endl;
		}
		dir_numeros++;
	}
	
	getch();
	return 0;
}
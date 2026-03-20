#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numero, *dir_numero;
	
	cout<<"Digite un numero: "; cin>>numero;
	
	dir_numero = &numero;
	
	if(*dir_numero % 2 == 0){
		cout<<"El Numero "<< *dir_numero <<" es Par"<<endl;
		cout<<"Posicion: "<<dir_numero<<endl;
	}
	else{
		cout<<"El Numero "<< *dir_numero <<" es Impar"<<endl;
	}
	
	cout<<"Posicion: "<<dir_numero<<endl;
	
	getch();
	return 0;
}
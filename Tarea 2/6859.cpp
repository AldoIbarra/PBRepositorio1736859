#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	cout << "Nombre: " << endl;

	char nombre[20];

	cin >> nombre;

	cout << "apellido: " << endl;

	char apellido[20];

	cin >> apellido;


	cout << "Edad: " << endl;

	int edad;

	cin >> edad;

	cout << "telefono: " << endl;

	char telefono[20];

	cin >> telefono;


	cout << "Nombre: " << apellido
		<< ", " << nombre
		<< "\n --------- \n"
		<< "Edad: " << edad << " anios \n"
		<< "Telefono: +52" << telefono << "\n";



	system("pause");

	return 0;
}
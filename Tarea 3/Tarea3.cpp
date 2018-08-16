#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	cout << "Suma de los n primeros numeros naturales" << endl;

	cout << "¿Hasta que numero quieres sumar?" << endl;

	int numero;

	cin >> numero;

	int suma;

	int numero2;

	numero2 = numero++;

	suma = ((numero * (numero2) ) / 2);

    cout << "La suma de los n primeros numeros es: " << suma
		<< "\n";
	

    system("pause");

	return 0;
}
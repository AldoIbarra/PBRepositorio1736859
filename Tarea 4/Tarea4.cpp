#include <iostream>
#include <math.h>
using namespace std;

float grados;
float radio;

int main()
{
	cout << "Calcule las coordenadas de un punto a partir del angulo y el radio!" << endl << "\n";
	
	cout << "ingrese los grados: " <<endl;
	cin >> grados;

	cout << "Ingrese el radio: " << endl;
	cin >> radio;

	float gradoscos = cos(grados)*(180/3.1416f); 
	float gradossen = sin(grados)*(180/3.1416f);

	float x = radio * gradoscos;
	float y = radio * gradossen;

	cout << "Las coordenadas son: (" << x << ", " << y << ")" << "\n";


	system("pause");
}

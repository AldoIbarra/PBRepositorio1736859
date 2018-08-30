#include <iostream>
#include <time.h>
using namespace std;

int main() {
	system("cls");
	locale::global(locale("spanish"));
	srand(time(NULL));

	cout << "´¡piedra papel o tijera! \n Elige una opción: \n 1. Piedra \n 2. Papel \n 3. Tijera" << endl;
	int opcion;
	cin >> opcion;
	if (opcion < 1 || opcion > 3) {
		cout << "¡Esa opción no es valida! \n ¡Adios!" << endl;
		system("Pause");
		return 0;
	}
	opcion = --opcion;
	int num;
	num = rand() % 3;
	if (num == 0) {
		cout << "¡La computadora eligió piedra!" << endl;
	}
	else {
		if (num == 1) {
			cout << "¡La computadora eligió papel!" << endl;
		}
		else {
			cout << "¡La computadora eligió tijera!" << endl;
		}
	}
	if (opcion == num) {
		cout << "¡Eligieron la misma opción!" << endl;

	}

	if ((opcion == 0 && num == 1) || (opcion == 1 && num == 2) || (opcion == 2 && num == 0)) {
		cout << "¡Perdiste!" << endl;
	}
	else {
		cout << "¡Ganaste!" << endl;

	}
	system("pause");




}
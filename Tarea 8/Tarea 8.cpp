#include <iostream>
using namespace std;

int opcion;

void menu();
void listaalumns();
void borraralumn();
void editalumn();
int salir();
void altaalumn();
void altacalif();
void manualusuario();

int main() {
	locale::global(locale("spanish"));
	menu();
}
void menu() {
	system("cls");
	cout << "Men� principal" << endl;
	cout << "Seleccione una opci�n: \n 1. Mostrar la lista de alumnos \n 2. Dar de alta alg�n alumno \n 3. Editar alumno" << endl;
	cout << " 4. Dar de alta alguna calificaci�n \n 5. Borrar alg�n alumno \n 6. Mostrar el manual de usuario \n 7. Salir" << endl;

	cin >> opcion;

	switch (opcion) {
	case 1:
		listaalumns();
		break;
	case 2:
		altaalumn();
		break;
	case 3:
		editalumn();
		break;
	case 4:
		altacalif();
		break;
	case 5:
		borraralumn();
		break;
	case 6:
		manualusuario();
		break;
	case 7:
		salir();
		break;
	default:
		cout << "Esa no es una opci�n valida. \n Vuelve a elegir una opci�n.";
		system("pause");
		menu();
	}
}
void listaalumns() {
	cout << "Esta es la lista de alumnos: " << endl;
	system("pause>nul");
	menu();
}
void borraralumn() {
	int borrar;
	cout << "Ingrese la matricula del alumno que desea borrar: " << endl;
	cin >> borrar;
	cout << "Alumno eliminado correctamente." << endl;
	system("pause>nul");
	menu();
}
void editalumn() {
	int editar;
	cout << "Ingrese la matricula del alumno que desea editar: " << endl;
	cin >> editar;
	cout << "Alumno editado exitosamente. " << endl;
	system("pause>nul");
	menu();
}
int salir() {
	return 0;
}
void altaalumn() {
	int alta;
	cout << "Ingrese la matricula del alumno que desea dar de alta: " << endl;
	cin >> alta;
	cout << "El alumno ha sido exitosamente dado de alta." << endl;
	system("pause>nul");
	menu();
}
void altacalif() {
	int altacalif;
	int calif;
	cout << "Ingrese la matricula del alumno a quien desea agregar una calificaci�n: " << endl;
	cin >> altacalif;
	cout << "ingrese la calificaci�n: " << endl;
	cin >> calif;
	cout << "La calificaci�n ha sido dada de alta. " << endl;
	system("pause>nul");
	menu();
}
void manualusuario() {
	cout << "Bienvenido al manual de usuario." << endl;
	system("pause>nul");
	menu();

}



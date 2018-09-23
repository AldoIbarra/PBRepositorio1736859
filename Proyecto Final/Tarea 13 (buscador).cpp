#include <iostream>
#include <string>
using namespace std;
int menu();
void registrar();
void mostrar();
void buscar();
int o; //Opción en el menú.
int c; //Contador de numero de alumnos registrados.

struct Lista { //Por ser solo la muestra de la estructura, no se valida que los datos sean 
			   //los adecuados
	string nombre;
	string apellidos;
	string correo;
	string telefono;
	string Matricula;
	string calificaciones[3];
	string direccion[2]; //0.- Calle y número. 1.- Colonia
};

Lista alumnos[100];
int main() {
	system("cls");
	menu();
}
void registrar() {
	system("cls");
	if (c == 100) {
		cout << "Lo sentimos, ha alcanzado el numero maximo de alumnos que se pueden registrar." << endl;
		system("pause>nul");
		menu();
	}
	else {
		c++;
		cout << "Introduce el nombre del alumno: " << endl;
		cin >> alumnos[c].nombre;
		cout << "Introduce los apellidos del alumno: " << endl;
		cin >> alumnos[c].apellidos;
		cout << "Introduce el correo del alumno: " << endl;
		cin >> alumnos[c].correo;
		cout << "Introduce el Telefono del alumno: " << endl;
		cin >> alumnos[c].telefono;
		cout << "Introduce la Matricula del alumno (Solo numeros. 7 digitos): " << endl;
		cin >> alumnos[c].Matricula;
		cout << "Introduce las tres calificaciones del alumno: \n Calificacion 1: " << endl;
		cin >> alumnos[c].calificaciones[0];
		cout << "Calificacion 2: " << endl;
		cin >> alumnos[c].calificaciones[1];
		cout << "Calificacion 3: " << endl;
		cin >> alumnos[c].calificaciones[2];
		cout << "Introduce la calle y numero del alumno: " << endl;
		cin >> alumnos[c].direccion[0];
		cout << "Introduce la colonia del alumno: " << endl;
		cin >> alumnos[c].direccion[1];
		cout << "Registro completado exitosamente!" << endl;
		system("pause>nul");
		menu();
	}
}
int menu() {
	system("cls");
	cout << "Que desea hacer? \n 1.- Registrar un alumno \n 2. Ver la lista de alumnos \n 3. Buscar \n 4. SALIR YAAAA" << endl;
	cin >> o;
	switch (o) {
	case 1:
		registrar();
		break;
	case 2:
		mostrar();
		break;
	case 3:
		buscar();
		break;
	case 4:
		cout << "Adios!" << endl;
		system("pause>nul");
		return 0;
	default:
		cout << "Esa no es una opcion valida." << endl;
		system("pause");
		menu();
	}
	return 0;
}
void mostrar() {
	system("cls");
	for (int cc = 1; cc <= c; cc++) {
		cout << "Nombre del alumno: " << alumnos[cc].nombre << " " << alumnos[cc].apellidos << endl;
		cout << "Correo del alumno: " << alumnos[cc].correo << endl;
		cout << "Telefono del alumno: " << alumnos[cc].telefono << endl;
		cout << "Matricula del alumno: " << alumnos[cc].Matricula << endl;
		cout << "Calificacion 1: " << alumnos[cc].calificaciones[0] << endl;
		cout << "Calificacion 2: " << alumnos[cc].calificaciones[1] << endl;
		cout << "Calificacion 3: " << alumnos[cc].calificaciones[2] << endl;
		cout << "Direccion del alumno: " << alumnos[cc].direccion[0] << " Colonia " << alumnos[cc].direccion[1] << endl;
		system("pause>nul");
	}
	cout << "Esos fueron todos los alumnos!" << endl;
	system("pause>nul");
	menu();
}
void buscar() {
	system("cls");
	int con = 0;
	string bu;
	bool inter = false;
	cout << "Introduce los 7 digitos de la Matricula que deseas buscar." << endl;
	cin >> bu;
	while (con <= c) {
		if (alumnos[con].Matricula == bu) {
			cout << "Lo encontre! " << endl;
			cout << "Nombre del alumno: " << alumnos[con].nombre << " " << alumnos[con].apellidos << endl;
			cout << "Correo del alumno: " << alumnos[con].correo << endl;
			cout << "Telefono del alumno: " << alumnos[con].telefono << endl;
			cout << "Matricula del alumno: " << alumnos[con].Matricula << endl;
			cout << "Calificacion 1: " << alumnos[con].calificaciones[0] << endl;
			cout << "Calificacion 2: " << alumnos[con].calificaciones[1] << endl;
			cout << "Calificacion 3: " << alumnos[con].calificaciones[2] << endl;
			cout << "Direccion del alumno: " << alumnos[con].direccion[0] << " Colonia " << alumnos[con].direccion[1] << endl;
			system("pause>nul");
			inter = true;
			break;
		}
		else {
			con++;
		}
	}
	menu();
}
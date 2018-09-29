#include <iostream>
#include <string>
using namespace std;
int menu();
void registrar();
void mostrar();
void buscar();
void modificar();
void borrar();
int o; //Opcion en el menú.
int c = 0; //Contador de numero de alumnos registrados.

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
		cin.ignore();
		cout << "Calificacion 2: " << endl;
		cin >> alumnos[c].calificaciones[1];
		cin.ignore();
		cout << "Calificacion 3: " << endl;
		cin >> alumnos[c].calificaciones[2];
		cin.ignore();
		cout << "Introduce la calle y numero del alumno: " << endl;
		getline(cin, alumnos[c].direccion[0]);
		cout << "Introduce la colonia del alumno: " << endl;
		getline(cin, alumnos[c].direccion[1]);
		cout << "Registro completado exitosamente!" << endl;
		system("pause>nul");
		menu();
	}
}
int menu() {
	system("cls");
	cout << "Que desea hacer? \n 1.- Registrar un alumno \n 2. Ver la lista de alumnos \n 3. Buscar \n"; 
	cout << " 4. Modificar Alumno \n 5. Eliminar alumno \n 6. SALIR YAAAA" << endl;
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
		modificar();
		break;
	case 5:
		borrar();
		break;
	case 6:
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
	if (c == 0) {
		cout << "Aun no hay alumnos registrados" << endl;
		system("pause>nul");
		menu();
	}
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
bool modi;
bool inter = false;
string bu;
void buscar() {
	system("cls");
	int con = 0;
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
			if (modi) {
				cout << "que deseas modificar?, selecciona una opcion!" << endl;
				cout << "1. Nombre \n 2. Apellido \n 3. Correo \n 4. Telefono \n 5. Matricula \n 6. Calificaciones \n 7. Calle y numero \n 8. Colonia" << endl;
				int opc;
				cin >> opc;
				switch (opc) {
				case 1:
					cout << "Introduce el nuevo nombre del alumno: " << endl;
					cin >> alumnos[con].nombre;
					modi = false;
					cout << "Nombre modificado!" << endl;
					system("pause>nul");
					modificar();
					break;
				case 2:
					cout << "Introduce el nuevo apellido del alumno: " << endl;
					cin >> alumnos[con].apellidos;
					modi = false;
					cout << "Apellido modificado" << endl;
					system("pause>nul");
					modificar();
					break;
				case 3:
					cout << "Introduce el nuevo correo del alumno: " << endl;
					cin >> alumnos[con].correo;
					modi = false;
					cout << "Correo modificado" << endl;
					system("pause>nul");
					modificar();
					break;
				case 4:
					cout << "Introduce el nuevo telefono del alumno: " << endl;
					cin >> alumnos[con].telefono;
					modi = false;
					cout << "telefono modificado" << endl;
					system("pause>nul");
					modificar();
					break;
				case 5:
					cout << "Introduce la nueva matricula del alumno: " << endl;
					cin >> alumnos[con].Matricula;
					modi = false;
					cout << "Matricula modificada" << endl;
					system("pause>nul");
					modificar();
					break;
				case 6:
					cout << "Introduce las nuevas calificaciones del alumno: " << endl;
					for (int k = 0; k <= 2; k++) {
						cout << "Introduce la calificacion numero " << k + 1 << " del alumno: " << endl;
						cin >> alumnos[con].calificaciones[k];
						cout << "Calificacion modificada" << endl;
						system("pause>nul");
					}
					modi = false;
					cout << "Calificaciones modificadas" << endl;
					system("pause>nul");
					modificar();
					break;
				case 7:
					cout << "Introduce la nueva calle y numero del alumno: " << endl;
					getline(cin, alumnos[con].direccion[0]);
					modi = false;
					cout << "Calle y numero modificados" << endl;
					system("pause>nul");
					modificar();
					break;
				case 8:
					cout << "Introduce la nueva colonia del alumno: " << endl;
					getline(cin, alumnos[con].direccion[1]);
					modi = false;
					cout << "Colonia modificada" << endl;
					system("pause>nul");

					modificar();
					break;
				default:
					cout << "Esa no es una opcion valida. " << endl;
					system("pause>nul");
					modificar();
					break;
				}
			}
			break;
		}
		else {
			con++;
		}
	}
	if (inter = false) {
		if (modi) {
			cout << "El alumno que deseabas modificar no fue encontrado. Asegurate de haber introducido correctamente su matricula." << endl;
			system("pause>nul");
			modificar();
		}
		cout << "El alumno que buscabas no fue encontrado. Asegurate de haber introducido correctamente su matricula." << endl;
		system("pause>nul");
		buscar();
	}
	menu();
}
void modificar() {
	system("cls");
	cout << "Deseas modificar la informacion de algun de algun alumno? \n 1. Si \n 2. No" << endl;
	int ops;
	cin >> ops;
	switch (ops) {
	case 1:
		modi = true;
		buscar();
		break;
	case 2:
		menu();
		break;
	default:
		cout << "Esa no es una opcion valida!" << endl;
		modificar();
		break;
	}
}
bool encbo = false;
void borrar() {
	system("cls");
	int con = 0;
	cout << "Introduce los 7 digitos de la Matricula que deseas borrar." << endl;
	cin >> bu;
	while (con <= c) {
		if (alumnos[con].Matricula == bu) {
			encbo = true;
			cout << "Lo encontre! " << endl;
			cout << "Nombre del alumno: " << alumnos[con].nombre << " " << alumnos[con].apellidos << endl;
			cout << "Correo del alumno: " << alumnos[con].correo << endl;
			cout << "Telefono del alumno: " << alumnos[con].telefono << endl;
			cout << "Matricula del alumno: " << alumnos[con].Matricula << endl;
			cout << "Calificacion 1: " << alumnos[con].calificaciones[0] << endl;
			cout << "Calificacion 2: " << alumnos[con].calificaciones[1] << endl;
			cout << "Calificacion 3: " << alumnos[con].calificaciones[2] << endl;
			cout << "Direccion del alumno: " << alumnos[con].direccion[0] << " Colonia " << alumnos[con].direccion[1] << endl;
			cout << "Esta seguro de querer borrarlo? \n 1. Si \n 2. No" << endl;
			int opt;
			cin >> opt;
			switch (opt) {
			case 1: 
				cout << "Ok!" << endl;
				for (int j = con; j < c; j++) {
					alumnos[j] = alumnos[j + 1];
				}
				c--;
				cout << "Alumno borrado exitosamente!" << endl;
				system("pause>nul");
				menu();
				break;
			case 2:
				cout << "Ok!" << endl;
				borrar();
				break;
			default:
				cout << "Esa no es una opción valida!" << endl;
				borrar();
				break;
			}
			break;
		}
		else {
			con++;
		}
	}
}
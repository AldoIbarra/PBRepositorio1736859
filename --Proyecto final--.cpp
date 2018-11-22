#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include<time.h>
#include <sstream>
using namespace std;
int menu();
void registrar();
void mostrar();
void buscar();
void modificar();
void borrar();
void guardar();
int o; //Opcion en el menú.
int c = 0; //Contador de numero de alumnos registrados.
struct Lista { //Todos los datos que los alumnos tienen
	string nombre;
	string apellidos;
	string correo;
	string telefono;
	string Matricula;
	string calificaciones[3];
	string direccion[2]; //0.- Calle y número. 1.- Colonia
	int calicalcu[3];
	float calfinal;
};

Lista alumnos[100];
int main() {
	system("cls");
	menu();
}
void registrar() {
	c++;
	cin.ignore();
	srand(time(NULL));
	system("cls");
	if (c == 100) {
		cout << "Lo sentimos, ha alcanzado el numero maximo de alumnos que se pueden registrar." << endl;
		system("pause>nul");
		menu();
	}
	else {
		cout << "Introduce el nombre del alumno: " << endl;
		getline(cin, alumnos[c].nombre);
		cout << "Introduce los apellidos del alumno: " << endl;
		getline(cin, alumnos[c].apellidos);
		cout << "Introduce el correo del alumno(Asegurese de que contenga '@' y '.com'[en ese orden]):" << endl;
		cin >> alumnos[c].correo;
		int conta = 0;
		bool inte = false;
		while (alumnos[c].correo[conta] != NULL) {
			if (alumnos[c].correo[conta] == 64) {
				while (alumnos[c].correo[conta] != NULL) {
					if (alumnos[c].correo[conta] == 46 && (alumnos[c].correo[conta + 1] == 67 || alumnos[c].correo[conta + 1] == 99) && (alumnos[c].correo[conta + 2] == 79 || alumnos[c].correo[conta + 2] == 111) && (alumnos[c].correo[conta + 3] == 77 || alumnos[c].correo[conta + 3] == 109)) {
						inte = true;
						break;
					}
					else conta++;
				}
				break;
			}
			else conta++;
		}
		if (inte == false) {
			cout << "El correo que usted introdujo no cuenta con '@' y '.com'. O al menos no en el orden especificado" << endl;
			system("pause>nul");
			--c;
			registrar();
		}
		cin.ignore();
		cout << "Introduce el Telefono del alumno (Valido solo con mas de 8 digitos o menos de 12): " << endl;
		cin >> alumnos[c].telefono;
		int contele = 0;
		while (alumnos[c].telefono[contele] != NULL) {
			if (alumnos[c].telefono[contele] < 48 || alumnos[c].telefono[contele] > 57) {
				cout << "Solo se admiten numeros" << endl;
				system("pause>nul");
				--c;
				registrar();
			}
			contele++;
		}
		if (contele > 12 || contele < 8) {
			cout << "Numero no admitido" << endl;
			system("pause>nul");
			--c;
			registrar();
		}
		int op;
		int temp;
		stringstream ss;
		cout << "Desea generar una matricula automaticamente o introducirla manualmente? \n 1. Generarla automaticamente \n 2. Introducirla manualmente" << endl;
		cin >> op;
		switch (op) {
		case 1:
			temp = 1000000 + rand() % (9999999 + 1) - 1;
			cout << "La matricula que el sistema genero es: " << temp << endl;
			ss << temp;
			alumnos[c].Matricula = ss.str();
			system("pause>nul");
			break;
		case 2:
			cout << "Asegurate de que la matricula que introduzcas tenga 7 digitos" << endl;
			cin >> alumnos[c].Matricula;
			temp = 0;
			while (alumnos[c].Matricula[temp] != NULL) {
				if (alumnos[c].Matricula[temp] < 48 || alumnos[c].Matricula[temp] > 57) {
					cout << "La matricula debe contener solo numeros" << endl;
					system("pause>nul");
					c--;
					registrar();
				}
				temp++;
			}
			if (temp < 7 || temp > 7) {
				c--;
				cout << "Se requiere que la matricula a ingresar sea de 7 digitos." << endl;
				system("pause>nul");
				registrar();
			}
			else cout << "Registro de matricula hecho exitosamente!" << endl;
			break;
		default:
			cout << "Esa no es una opcion valida." << endl;
			system("pause>nul");
			menu();
		}
		cout << "Introduce las tres calificaciones del alumno." << endl;
		for (int contc = 0; contc < 3; contc++) {
			cout << "Calificacion " << contc + 1 << " : " << endl;
			int cca = 0;
			cin >> alumnos[c].calificaciones[contc];
			while (alumnos[c].calificaciones[contc][cca] != NULL) {
				if (alumnos[c].calificaciones[contc][cca] < 48 || alumnos[c].calificaciones[contc][cca]>57) {
					cout << "Solo se admiten numeros." << endl;
					system("pause>nul");
					--c;
					registrar();
				}
				cca++;
			}
			temp = atoi(alumnos[c].calificaciones[contc].c_str());
			if (temp > 100 || temp < 0) {
				cout << "La calificacion ingresada debe estar en un rango de 0 a 100" << endl;
				system("pause>nul");
				--c;
				registrar();
			}
			else {
				alumnos[c].calicalcu[contc] = temp;
			}
		}
		alumnos[c].calfinal = alumnos[c].calicalcu[0] * .3 + alumnos[c].calicalcu[1] * .45 + alumnos[c].calicalcu[2] * .25;
		cout << "La calificacion final es: " << alumnos[c].calfinal << endl;
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
	cout << " 4. Modificar Alumno \n 5. Eliminar alumno \n 6. Salir \n 7. Guardar \n 8. Manual de Usuario" << endl;
	cin >> o;
	switch (o) {
	case 1:
		registrar();
		cin.ignore();
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
		cin.ignore();
		cout << "Adios!" << endl;
		system("pause>nul");
		return 0;
	case 7:
		guardar();
		break;
	case 8:
		system("cls");
		cout << "Manual de Usuario" << endl;



		cout << "Al iniciar" << endl;

		cout << "Una pantalla con el menú de opciones se desplegará al iniciar, y mostrará todo en el siguiente orden:" << endl;
		cout << "1. Registrar Alumno" << endl;
		cout << "2. Ver la lista de alumnos";
		cout << "3. Buscar" << endl;
		cout << "4. Modificar Alumno" << endl;
		cout << "5. *Eliminar Alumno" << endl;
		cout << "6. Salir" << endl;
		cout << "7. Manual de usuario" << endl;


		cout << "Requerimientos para buen funcionamiento" << endl;

		cout << "Si se desea un buen funcionamiento del programa, se deben seguir todas las instrucciones dadas durante su funcionamiento" << endl;
		cout << "Algunas de dichas instrucciones o aclaraciones son :" << endl;
		cout << "1. Respetar todas los requerimientos hechos durante la introducción de datos" << endl;
		cout << "2. No forzar su funcionamiento" << endl;
		cout << "3. Denunciar cualquier mal funcionamiento con el desarrollador" << endl;
		system("pause>nul");
		menu();

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
		cout << "Promedio final: " << alumnos[cc].calfinal << endl;
		cout << "Direccion del alumno: " << alumnos[cc].direccion[0] << " Colonia " << alumnos[cc].direccion[1] << endl;
		cout << "---------------------------------------------------" << endl;
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
	cin.ignore();
	system("cls");
	int con = 0;
	cout << "Introduce los 7 digitos de la Matricula que deseas buscar." << endl;
	cin >> bu;
	while (con <= c) {
		if (alumnos[con].Matricula == bu) {
			inter = true;
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
			menu();
		}
		else if (con == c && inter == false) {
			cout << "El alumno que buscabas no fue encontrado. Asegurate de haber introducido correctamente su matricula." << endl;
			system("pause>nul");
			menu();
		}
		con++;
	}
}
int tempo;
void modificar() {
	bool intm = false;
	string bum;
	system("cls");
	int conm = 0;
	cout << "Introduce los 7 digitos de la Matricula que deseas modificar." << endl;
	cin >> bum;
	while (conm <= c) {
		if (alumnos[conm].Matricula == bum) {
			intm = true;
			cout << "Lo encontre! " << endl;
			cout << "Nombre del alumno: " << alumnos[conm].nombre << " " << alumnos[conm].apellidos << endl;
			cout << "Correo del alumno: " << alumnos[conm].correo << endl;
			cout << "Telefono del alumno: " << alumnos[conm].telefono << endl;
			cout << "Matricula del alumno: " << alumnos[conm].Matricula << endl;
			cout << "Calificacion 1: " << alumnos[conm].calificaciones[0] << endl;
			cout << "Calificacion 2: " << alumnos[conm].calificaciones[1] << endl;
			cout << "Calificacion 3: " << alumnos[conm].calificaciones[2] << endl;
			cout << "Direccion del alumno: " << alumnos[conm].direccion[0] << " Colonia " << alumnos[conm].direccion[1] << endl;
			cout << "que deseas modificar?, selecciona una opcion!" << endl;
			cout << "1. Nombre \n 2. Apellido \n 3. Correo \n 4. Telefono \n 5. Matricula \n 6. Calificaciones \n 7. Calle y numero \n 8. Colonia" << endl;
			int opc;
			cin >> opc;
			switch (opc) {
			case 1:
				cout << "Introduce el nuevo nombre del alumno: " << endl;
				getline(cin, alumnos[conm].nombre);
				cout << "Nombre modificado!" << endl;
				system("pause>nul");
				menu();
				break;
			case 2:
				cout << "Introduce el nuevo apellido del alumno: " << endl;
				getline(cin, alumnos[conm].apellidos);
				cout << "Apellido modificado" << endl;
				system("pause>nul");
				menu();
				break;
			case 3:
				cout << "Introduce el nuevo correo del alumno: " << endl;
				cin >> alumnos[conm].correo;
				cout << "Correo modificado" << endl;
				system("pause>nul");
				menu();
				break;
			case 4:
				cout << "Introduce el nuevo telefono del alumno: " << endl;
				cin >> alumnos[conm].telefono;
				cout << "telefono modificado" << endl;
				system("pause>nul");
				menu();
				break;
			case 5:
				cout << "Introduce la nueva matricula del alumno: " << endl;
				cin >> alumnos[conm].Matricula;
				cout << "Matricula modificada" << endl;
				system("pause>nul");
				menu();
				break;
			case 6:
				cout << "Introduce las nuevas calificaciones del alumno: " << endl;
				for (int k = 0; k <= 2; k++) {
					cout << "Introduce la calificacion numero " << k + 1 << " del alumno: " << endl;
					cin >> alumnos[conm].calificaciones[k];
					alumnos[conm].calicalcu[k] = atoi(alumnos[conm].calificaciones[k].c_str());
					cout << "Calificacion modificada" << endl;
					system("pause>nul");
				}
				alumnos[conm].calfinal = alumnos[conm].calicalcu[0] * .3 + alumnos[conm].calicalcu[1] * .45 + alumnos[conm].calicalcu[2] * 25;
				cout << "Calificaciones modificadas" << endl;
				cout << "El nuevo promedio es de: " << alumnos[conm].calfinal << endl;
				system("pause>nul");
				menu();
				break;
			case 7:
				cout << "Introduce la nueva calle y numero del alumno: " << endl;
				getline(cin, alumnos[conm].direccion[0]);
				cout << "Calle y numero modificados" << endl;
				system("pause>nul");
				menu();
				break;
			case 8:
				cout << "Introduce la nueva colonia del alumno: " << endl;
				getline(cin, alumnos[conm].direccion[1]);
				cout << "Colonia modificada" << endl;
				system("pause>nul");
				menu();
				break;
			default:
				cout << "Esa no es una opcion valida. " << endl;
				system("pause>nul");
				menu();
				break;
			}
			break;
		}
		conm++;
	}
	if (intm == false) {
		cout << "El alumno cuya informacion querias modificar no existe. Tal vez hayas escrito mal su matricula." << endl;
		system("pause>nul");
		menu();
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
void guardar() {
	system("cls");
	ofstream lista;
	if (c == 0) {
		cout << "Aun no hay alumnos registrados" << endl;
		system("pause>nul");
		menu();
	}
	for (int cc = 1; cc <= c; cc++) {
		lista.open("Lista de alumnos.txt");
		lista << "Nombre del alumno: " << alumnos[cc].nombre << " " << alumnos[cc].apellidos << endl;
		lista << "Correo del alumno: " << alumnos[cc].correo << endl;
		lista << "Telefono del alumno: " << alumnos[cc].telefono << endl;
		lista << "Matricula del alumno: " << alumnos[cc].Matricula << endl;
		lista << "Calificacion 1: " << alumnos[cc].calificaciones[0] << endl;
		lista << "Calificacion 2: " << alumnos[cc].calificaciones[1] << endl;
		lista << "Calificacion 3: " << alumnos[cc].calificaciones[2] << endl;
		lista << "Promedio final: " << alumnos[cc].calfinal << endl;
		lista << "Direccion del alumno: " << alumnos[cc].direccion[0] << " Colonia " << alumnos[cc].direccion[1] << endl;
		lista << "------------------------------------------------";
	}
	lista.close();



	cout << "Archivo exitosamente guardado!" << endl;
	system("pause>nul");
	menu();
}
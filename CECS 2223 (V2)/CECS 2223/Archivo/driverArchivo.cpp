#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	//Escritura
	/*ofstream file;
	double numero;
	int cantidad;

	file.open("numero.txt");
	if (file.fail())
		cout << "Error: NO se pudo abrir el archivo "
		<< "numeros.txt" << endl;
	else
	{
		cout << "Cuantos numeros guardara en el archivo: ";
		cin >> cantidad;
		for (int i = 1; i <= cantidad; i++)
		{
			cout << " Entre cualquier numero: ";
			cin >> numero;

			file << numero << endl;
		}
	}
	file.close();
	*/

	//Lectura
	/*ifstream file;
	double numero;

	file.open("numero.txt");
	if (file.fail())
	{
		cout << "Error: No se pudo abrir el archivo "
			<< "numeros.txt" << endl;
	}
	else
	{
		file >> numero;
		while (!file.eof())
		{
			cout << numero << endl;
			file >> numero;
		}
		file.close();
	}*/

	//Escritura y lectura a la misma vez
	fstream file;
	double numero;
	int cantidad;
	bool abierto = true;

	file.open("numero.txt", ios::in | ios::out); //read+
	if (file.fail())
	{
		cout << "No se pudo abrir read+" << endl;
		file.clear();
		file.open("numero.txt", ios::in | ios::out | ios::trunc);
		if (file.fail())
		{
			cout << "ERROR: No se pudo abrir el archivo numeros.txt" << endl << endl;
		}
	}

	if (!file.fail())
	{
		bool exitProgram = false;
		do
		{
			int opcion;
			cout << "Elija una de las siguientes opciones:\n"
				<< "1. Escribir documnento tipo .txt\n"
				<< "2. Abrir un documento tipo .txt\n"
				<< "3. Salir de programa\n";
			cin >> opcion;
			cout << endl << endl;
			switch (opcion)
			{
			case 1:
				cout << "Write" << endl << endl;
				//Si deseamos escribir al principio del archivo
				file.seekp(0, ios::beg);	
				cout << "Cuantos numeros guardara en el archivo: ";
				cin >> cantidad;
				for (int i = 1; i <= cantidad; i++)
				{
					cout << " Entre cualquier numero: ";
					cin >> numero;

					file << numero << endl;
				}
				break;
			case 2:
				//Lectura
				cout << "Leer" << endl << endl;
				file.seekg(0, ios::beg);	// mover cursor al comienzo para 
				file >> numero;			// poder leer archivo
				while (!file.eof())
				{
					cout << numero << endl;
					file >> numero;
				}
				file.clear();
				break;
			case 3:
				cout << "Adios\n";
				exitProgram = true;
				break;
			default:
				cout << "Error: Selecion equivocada\n";
			}
		} while (!(exitProgram));

		file.close();
	}
	system("pause");
	return 0;
}
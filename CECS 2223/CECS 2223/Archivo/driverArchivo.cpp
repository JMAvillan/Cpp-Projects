#include <iostream>
#include <fstream>
using namespace std;

int main()
{


	ofstream file;
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
			cout << " Entre cualquier numero: ";
		cin >> numero;
		file << numero << endl;
	}
	file.close();

	system("pause");
	return 0;
}
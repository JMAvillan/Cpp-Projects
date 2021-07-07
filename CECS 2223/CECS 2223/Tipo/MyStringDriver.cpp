//#include "MyString.h"
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	MyString a, b, c;
//
//	cout << "Entre su primer nombre: ";
//	cin >> a;
//	cout << "Entre su primer apellido: ";
//	cin >> b;
//	c = "Su nombre es: " + a + ' ' + b + '.';
//	cout << c << endl << endl;
//
//	cout << endl << "--------------" << endl << endl;
//
//	b = "Entre un numero real: ";
//	c = "ERROR: No es un numero real.";
//
//	while (!a.representAReal())
//	{
//		cout << c.toUppercase() << endl;
//		cout << b.toLowercase() << endl;
//		cin >> a;
//	}
//
//	cout << endl << endl << "Largo maximo de una cadena: "
//		<< MyString::MaxLen() << endl << endl;
//
//
//
//	system("pause");
//	return 0;
//}
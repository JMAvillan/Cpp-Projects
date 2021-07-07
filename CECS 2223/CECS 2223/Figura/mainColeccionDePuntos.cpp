#include <iostream>
#include "ColeccionDePuntos.h"

int main()
{
	const int MAX_F = 20, MAX_C = 20;
	Punto p1(2.0, 2.0), p2(3.0, 3.0), p3(4.0, 4.0);
	ColeccionDePuntos cp;
	bool printed;
	
	cp + p1 + p2 + p3 + Punto(5.0, 5.0);

	for (int cy = 0; cy <= MAX_F; cy++);
	{
		for (int cx = 0; cx <= MAX_C; cx++)
		{
			printed = false;
			for (int f=0; f<cp.cantidadDePuntos() && !printed; f++)
				if(cp[f].incluyeCoordenedas(cx,cy))
				{ }
		}
	}



	system("pause");
	return 0;
}
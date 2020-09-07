// Programa 14_03.cpp 
#include <iostream>

using namespace std;

class Gato{
public:
	Gato(int edad):suEdad(edad){CuantosGatos++;}
	virtual ~Gato() { CuantosGatos--;}
	virtual int ObtenerEdad() { return suEdad;}
	virtual void AsignarEdad(int edad){suEdad = edad;}
	virtual int ObtenerCuantos(){ return CuantosGatos;}
private:
	int suEdad;
	static int CuantosGatos;
};

int Gato::CuantosGatos = 0;
int main()
{
	const int MaxGatos = 5; int i;
	Gato *CasaGatos[MaxGatos];
	for(i = 0; i <MaxGatos; i++)
		CasaGatos[i] = new Gato(i);

	for(i = 0; i <MaxGatos; i++){
		cout << "¡Quedan ";
		cout << CasaGatos[i]->ObtenerCuantos();
		cout << " gatos!\n";
		cout << "Se vva a eliminar el que tiene ";
		cout << CasaGatos[i]->ObtenerEdad()+2;
		cout << " anios de edad\n";
		delete CasaGatos[i];
		CasaGatos[i] = 0;
	}

	return 0;
}


// Datos miembros estáticos
#include <iostream>

using namespace std;

class Gato{
public:
	Gato(int edad):suEdad(edad){CuantosGatos++;}
	virtual ~Gato() {CuantosGatos --;}
	virtual int ObtenerEdad() { return suEdad;}
	virtual void AsignarEdad(int edad){suEdad = edad;}
	static int CuantosGatos;

private:
	int suEdad;
};

// Aquí es donde se "declara" e inicializa la variable estática
// Aquí es donde se reserva la memoria.
int Gato::CuantosGatos = 0;

int main(){
const int MaxGatos = 5; int i;
Gato *CasaGatos[MaxGatos]; //Arreglo de punteros a gatos
for (i = 0; i < MaxGatos; i++){
	CasaGatos[i] = new Gato(i); //Creando Gatos en el heap
}

for(i = 0; i <MaxGatos; i++){
	cout <<"Quedan ";
	cout << Gato::CuantosGatos;
	cout << " gatos!\n";
	cout << "Se va  a eliminar el que tiene ";
	cout << CasaGatos[i]->ObtenerEdad();
	cout << " años de edad \n";
	delete CasaGatos[i];
	CasaGatos[i] = 0;
}
return 0;
}

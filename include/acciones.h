#ifndef ACCIONES_H
#define ACCIONES_H
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class acciones
{
    public:
        acciones(){};

        void agregar(int codigo,string nombre,string clase,int cantidad,double precio);
        void eliminar(int fila);
        void modificar(int codiG,int cant);
        virtual ~acciones();


    private:
        vector<int> CodiVect;
        vector<int> cantVect;
        vector<string>nombre;
        vector<string>tipo;
        vector<int>precio;
        vector <int>pos2;

};

#endif // ACCIONES_H

#ifndef ACCIONES_H
#define ACCIONES_H
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class acciones
{
    public:
        acciones(int codigo_, string nombre_, string clase_, int cantidad_,int fila_ ){
            codigo=codigo_;
            nombre=nombre_;
            clase=clase_;
            cantidad=cantidad_;
            fila=fila_;
        };

        void agregar(int codigo,string nombre,string clase,int cantidad);
        void eliminar(int fila);
        void modificar(int codiG,int cant);
        virtual ~acciones();


    private:
        int codigo;
        string nombre;
        string clase;
        int cantidad;
        int fila;
        vector<int> CodiVect;
        vector<int> cantVect;
        vector<string>lineas;
        vector <int>pos2;

};

#endif // ACCIONES_H

//Desarrollar un sistema de registro de stock de un minimarket que permite agregar, editar y eliminar registros de libros, mostrar los productos por categor�a.
// Todos los registros deben ser almacenados en un archivo, a cada �tem se le identifica por un c�digo �nico.
#ifndef MINI_H
#define MINI_H
#include <vector>
#include <fstream>
#include "Record.h"
class MINI
{
    public:
        MINI(string codigo,string nombre,string tipo,string cantidad);

        void getcodigo(string cod_){this -> codigo=cod_;};
        void getnombre(string nomb_){this -> nombre=nomb_;};
        void gettipo(string tip_){this -> tipo=tip_;};
        void getcantidad(string cant_){this -> cantidad=cant_;};

        string setcodigo(){return this -> codigo;};
        string setnombre(){return this -> nombre;};
        string settipo(){return this -> tipo;};
        string setcantidad(){return this -> cantidad;};


        void show();
        void load_producto(string dato="data.txt");
        void show_productos();
        void show_cantidades();
        virtual ~MINI();

    private:
        string codigo;
        string nombre;
        string tipo;
        string cantidad;
        vector<Record> Lista;


};

#endif // MINI_H

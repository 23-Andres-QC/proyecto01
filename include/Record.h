#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <iostream>
using namespace std;
class Record
{
    public:
        Record(int codigo_,string nombre_,string tipo_,int cantidad_,double precio_);
        void show();
        int getcodigo(){return this -> codigo;};
        string getnombre(){return this -> nombre;};
        string gettipo(){return this -> tipo;};
        int getcantidad(){return this -> cantidad;};
        double getprecio(string precio_){return this -> precio;};

        void setcodigo(int cod){codigo=cod;};
        void setnombre(string nomb){nombre=nomb;};
        void settipo(string tip){tipo=tip;};
        void setcantidad(int cant){cantidad=cant;};
        void setprecio(double preciO_){precio=preciO_;};

        virtual ~Record();
    private:
        int codigo;
        string nombre;
        string tipo;
        int cantidad;
        double precio;

};

#endif // RECORD_H

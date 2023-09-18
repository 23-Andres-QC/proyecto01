
//Desarrollar un sistema de registro de stock de un minimarket que permite agregar, editar y eliminar registros de libros, mostrar los productos por categoría.
// Todos los registros deben ser almacenados en un archivo, a cada ítem se le identifica por un código único.
#include "MINI.h"

MINI::MINI(string cod,string nomb,string tip_,string cant,string preci_){
        this -> codigo=cod;
        this -> nombre=nomb;
        this -> tipo=tip_;
        this -> cantidad=cant;
        this-> precio=preci_;
}
void MINI::show(){
    cout<<this->codigo<<" "<<this->nombre<<" "<<this->tipo<<" "<<this->cantidad<<" "<<this->precio<<endl;
}
void MINI::load_producto(string dato)
{
    ifstream trae(dato);
    int codi;
    string nom;
    string tip;
    int can;
    double precio;
    while (trae>>codi>>nom>>tip>>can>>precio){
        Record hh(codi, nom, tip,can,precio);
        this->Lista.push_back(hh);
    }
    trae.close();
}
void MINI::show_productos(){
    for(auto e:this->Lista){
        e.show();
    }
}

MINI::~MINI()
{
    //dtor
}

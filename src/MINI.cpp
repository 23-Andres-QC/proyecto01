
//Desarrollar un sistema de registro de stock de un minimarket que permite agregar, editar y eliminar registros de libros, mostrar los productos por categoría.
// Todos los registros deben ser almacenados en un archivo, a cada ítem se le identifica por un código único.
#include "MINI.h"

MINI::MINI(string cod,string nomb,string tip_,string cant){
        this -> codigo=cod;
        this -> nombre=nomb;
        this -> tipo=tip_;
        this -> cantidad=cant;
}
void MINI::show(){
    cout<<this->codigo<<" "<<this->nombre<<" "<<this->tipo<<" "<<this->cantidad<<endl;
}
void MINI::load_producto(string dato)
{
    ifstream trae(dato);
    int codi;
    string nom;
    string tip;
    int can;
    while (trae>>codi>>nom>>tip>>can){
        Record hh(codi, nom, tip,can);
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

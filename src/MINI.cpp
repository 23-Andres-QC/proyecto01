
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
    const char* rojo = "\x1b[31m";
    const char* verde = "\x1b[32m";
    const char* azul = "\x1b[34m";
    const char* cyan = "\x1b[37m";
    const char* magenta = "\x1b[35m";
    const char* reset = "\x1b[0m";
    cout<<rojo<<codigo<<reset<<" "<<verde<<nombre<<reset<<" "<<azul<<tipo<<reset<<" "<<cyan<<cantidad<<reset<<" "<<magenta<<precio<<reset<<endl;
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

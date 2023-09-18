#include <iostream>
#include "Record.h"
#include "MINI.h"
#include "acciones.h"
#include <cstdio>
#include <string>
#include <fstream>
#include <conio.h>
void llamaacciones(string a);
using namespace std;
void agregarA();
void modificar();
void eliminar ();
int main(){
    string a;
    string u = R"(
   ****   *****   ****     *****     ****     *****    ****         ****
  *   *  *       *           *      *           *     *    *      *      *
  *   *  *       *           *       **         *     *    *     *        *
  ****   ****    *   ***     *        **        *     ****       *        *
  *  *   *       *     *     *         **       *     *  *       *        *
  *   *  *       *     *     *          *       *     *    *      *      *
  *    * *****    *****    *****    ****        *     *     *       ****
                    BY> Andres and Ronal DEV)";

    printf(" %s\n\n", u.c_str());
    cout <<"Presiona cualquier tecla para continuar..."<<endl;
    char tecla= _getch();
    system("cls");
    do{
    cout<<"Que es lo que desea hacer mostrar,agregar,eliminar, modificar,salir: ";
    cin>>a;
    llamaacciones(a);
    }while(a!="a");
    return 0;

}
void llamaacciones(string a){

    if(a=="mostrar"){
        MINI ver("codigos","nombre","clase","cantidad","precio");
        ver.show();
        ver.load_producto();
        ver.show_productos();
    }else{
        system("cls");
    }
    if (a=="agregar"){
        agregarA();
    }else if(a=="eliminar"){
        eliminar();
    }else if(a=="modificar"){
        modificar();
    }else{
        cout<<"Accion no existe ";
    }
}
void agregarA(){
    int cod;
    string nombre,clase;
    int cant;
    double preciO;
    cout<<"Mencioname el codigo: ";
    cin>>cod;
    cout<<"Mencioname el nombre:  ";
    cin>>nombre;
    cout<<"Mencioname la clase:  ";
    cin>>clase;
    cout<<"Mencioname la cantidad de productos: ";
    cin>>cant;
    cout<<"Mencione el precio del producto: ";
    cin>>preciO;
    acciones a;
    a.agregar(cod,nombre,clase,cant,preciO);
        MINI ver("codigos","nombre","clase","cantidad","precio");
        ver.show();
        ver.load_producto();
        ver.show_productos();

}

void eliminar(){
    int cant,cod;
    cout<<"Menciona el codigo del producto a eliminar:  "<<endl;
    cin>>cod;
    acciones b;
    b.eliminar(cod);
        MINI ver("codigos","nombre","clase","cantidad","precio");
        ver.show();
        ver.load_producto();
        ver.show_productos();
}
void modificar (){
    int cod,cant;
    string desi;
    cout<<"Mencioname el codigo del producto a modificar: ";
    cin>>cod;
    cout<<"Deseas aumentar o disminuir ";
    cin>>desi;
    cout<<"Mencioname cuanto: ";
    cin>>cant;
    acciones x;
    if(desi=="aumentar"){
        x.modificar(cod,cant);

    }else{
        x.modificar(cod,cant*-1);

    }
    MINI ver("codigos","nombre","clase","cantidad","precio");
    ver.show();
    ver.load_producto();
    ver.show_productos();
}

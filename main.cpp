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
  )";

    printf(" %s\n", u.c_str());
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
        MINI ver("codigos","nombre","clase","cantidad");
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
    cout<<"Mencioname el codigo: ";
    cin>>cod;
    cout<<"Mencioname el nombre:  ";
    cin>>nombre;
    cout<<"Mencioname la clase:  ";
    cin>>clase;
    cout<<"Mencioname la cantidad de productos: ";
    cin>>cant;
    acciones a(1,"agraga ","datos",1,1);
    a.agregar(cod,nombre,clase,cant);
        MINI ver("codigos","nombre","clase","cantidad");
        ver.show();
        ver.load_producto();
        ver.show_productos();

}

void modificar(){
    int cant,cod;
    cout<<"Menciona el codigo del producto a modificar:  "<<endl;
    cin>>cod;
    cout<<"Menciona cual es la nueva cantidad del producto: "<<endl;
    cin>>cant;
    acciones b(2,"modificar ","datos",2,2);
    b.modificar(cod,cant);
        MINI ver("codigos","nombre","clase","cantidad");
        ver.show();
        ver.load_producto();
        ver.show_productos();
}
void eliminar (){
    int cod;
    cout<<"Mencioname el codigo del producto a eliminar: ";
    cin>>cod;
    acciones x(2,"modificar ","datos",2,2);
    x.eliminar(cod);
        MINI ver("codigos","nombre","clase","cantidad");
        ver.show();
        ver.load_producto();
        ver.show_productos();
}

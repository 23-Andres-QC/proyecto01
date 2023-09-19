#include <iostream>
#include "Record.h"
#include "MINI.h"
#include "acciones.h"
#include <cstdio>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
void setColor(int color);
void llamaacciones(string a);
void agregarA();
void modificar();
void eliminar ();

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
enum MenuOption {
    Mostrar,
    Agregar,
    Modificar,
    Eliminar,
    Salir
};

void drawMenu(const std::vector<std::string>& options, int selectedOption) {
    system("cls");
    setColor(2);
    cout<< "                           Selecciona una opción:"<<endl;
    for(int i=0; i<options.size();i++){
        if (i==selectedOption){
            cout<<"             > ";
        } else {
            cout<<"  ";
        }
            cout<<options[i]<<endl;
    }
}

int menuPrincipal(){
    vector<std::string>menuOptions={
        "                           Mostrar",
        "                           Agregar",
        "                           Modificar",
        "                           Eliminar",
        "                           Salir"};
    int selectedOption = 0;
    string a;
    while (true){
        drawMenu(menuOptions, selectedOption);
        char tecla = _getch();
        switch (tecla){
            case 72: //arriba
                if (selectedOption > 0){
                    selectedOption--;
                }
                break;
            case 80: //abajo
                if (selectedOption<menuOptions.size()-1){
                    selectedOption++;
                }
                break;
            case 13: //Enter
                switch (static_cast<MenuOption>(selectedOption)) {
                    case Mostrar:
                        cout << "Seleccionaste Mostrar." <<endl;
                        llamaacciones(a);
                        break;
                    case Agregar:
                        cout << "Seleccionaste Agregar." <<endl;
                        agregarA();
                        break;
                    case Modificar:
                        cout << "Seleccionaste Modificar." <<endl;
                        modificar();
                        break;
                    case Eliminar:
                        cout << "Seleccionaste Eliminar." <<endl;
                        eliminar ();
                        break;
                    case Salir:
                        return 0;
                }
                break;
            default:
                break;
        }
    }
}



int main() {
    setColor(6);
    std::string u = R"(
               ****   *****   ****     *****     ****     *****    ****         ****
              *   *  *       *           *      *           *     *    *      *      *
              *   *  *       *           *       **         *     *    *     *        *
              ****   ****    *   ***     *        **        *     ****       *        *
              *  *   *       *     *     *         **       *     *  *       *        *
              *   *  *       *     *     *          *       *     *    *      *      *
              *    * *****    *****    *****    ****        *     *     *       ****
                                BY> Andres QC and Ronal MA DEV)";

    printf(" %s\n\n", u.c_str());

    setColor(9);
        cout << "                   Presiona cualquier tecla para continuar..."<<endl;
        char tecla = _getch();

    menuPrincipal(); // Llama a la función del menú principal



    /*
    string a;
    setColor(6);
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
    setColor(9);
            cout <<"                          Presiona cualquier tecla para continuar..."<<endl;
            char tecla= _getch();
            system("cls");
    setColor(10);
            do{
            cout<<"Que es lo que desea hacer mostrar,agregar,eliminar, modificar,salir: ";
            cin>>a;
            llamaacciones(a);
            }while(a!="a");
            */
            return 0;

}
void llamaacciones(string a){
    MINI ver("codigos","nombre","clase","cantidad","precio");
        ver.show();
        ver.load_producto();
        ver.show_productos();
    /*if(a=="mostrar"){
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
    }*/
    cout << "                     Presiona la barra espaciadora para volver al menú...";
    while (_getch() != 32) {
}
}
void agregarA(){
    int cod;
    string nombre,clase;
    int cant;
    double preciO;
    setColor(7);
            do{
            cout<<"Mencioname el codigo: ";
            cin>>cod;
            }while(cod<=0 || cod>=200);
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
      cout << "                     Presiona la barra espaciadora para volver al menú...";
    while (_getch() != 32) {

}
}

void eliminar(){
    int cant,cod;
    setColor(7);
            do{
            cout<<"Menciona el codigo del producto a eliminar:  "<<endl;
            cin>>cod;
            }while(cod<=0 || cod>=200);
    acciones b;
    b.eliminar(cod);
        MINI ver("codigos","nombre","clase","cantidad","precio");
        ver.show();
        ver.load_producto();
        ver.show_productos();
       cout << "                     Presiona la barra espaciadora para volver al menú...";
    while (_getch() != 32) {
}
}
void modificar (){
    int cod,cant;
    string desi;
    setColor(7);
            do{
            cout<<"Mencioname el codigo del producto a modificar: ";
            cin>>cod;
            }while(cod<=0 || cod>=200);
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
    cout << "                     Presiona la barra espaciadora para volver al menú...";
    while (_getch() != 32) {
}
}

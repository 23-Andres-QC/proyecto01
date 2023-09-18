#include "acciones.h"
using namespace std;
void acciones::agregar(int codi,string nombre,string clase,int cantidad,double precio){
    ofstream datos("data.txt",ios::app);
    datos<<codi<<" "<<nombre<<" "<<clase<<" "<<cantidad<<" "<<precio<<endl;
}
void acciones::eliminar(int codi){
    ifstream datos1("data.txt");
    string linea;
    int posicion;
    int a;
    int codig,can;
    double prec;
    string nom,tip;
    CodiVect.clear();
    cantVect.clear();
    nombre.clear();
    tipo.clear();
    precio.clear();
   while (datos1>>codig>>nom>>tip>>can>>prec) {
        CodiVect.push_back(codig);
        cantVect.push_back(can);
        nombre.push_back(nom);
        tipo.push_back(tip);
        precio.push_back(prec);
    }
   for (int i=0; i<=CodiVect.size(); i++) {
        if (CodiVect[i]==codi) {
            posicion=i;
        }
    }
    for (int i=0; i<cantVect.size(); i++) {
        if (cantVect[i]==0) {
            pos2.push_back(i+1);
        }
    }
    datos1.close();
    CodiVect.erase(CodiVect.begin() + posicion);
    cantVect.erase(cantVect.begin() + posicion);
    nombre.erase(nombre.begin() + posicion);
    tipo.erase(tipo.begin() + posicion);
    precio.erase(precio.begin() + posicion);
    for (int i = 0; i < pos2.size(); i++) {
        int posicionEliminar = pos2[i];
        if (posicionEliminar >= 0 && posicionEliminar < CodiVect.size()) {
            CodiVect.erase(CodiVect.begin() + posicionEliminar);
            cantVect.erase(cantVect.begin() + posicionEliminar);
            nombre.erase(nombre.begin() + posicionEliminar);
            tipo.erase(tipo.begin() + posicionEliminar);
            precio.erase(precio.begin() + posicionEliminar);
        } else {
            cout << "Posición fuera de rango: " << posicionEliminar << endl;
        }
    }
    ofstream datos2("data.txt");
    for (int i = 0; i < CodiVect.size(); i++) {
        datos2 << CodiVect[i] << " " << nombre[i] << " " << tipo[i] << " " << cantVect[i] << " " << precio[i] << endl;
    }
    datos2.close();
}
void acciones::modificar(int codiG,int cant){
    ifstream in("data.txt");
    int codi;
    string nom;
    string tip;
    int can;
    double prec;
    CodiVect.clear();
    cantVect.clear();

    while (in>>codi>>nom>>tip>>can>>prec) {
        CodiVect.push_back(codi);
        cantVect.push_back(can);
        nombre.push_back(nom);
        tipo.push_back(tip);
        precio.push_back(prec);
    }
    in.close();
    int pos;
    for (int i=0; i<CodiVect.size(); i++) {
        if (CodiVect[i]==codiG) {
            pos=i;
        }
    }
    cout<<"Tienes esta cantidad: "<<cantVect[pos]<<endl;

    cantVect[pos]=cantVect[pos]+cant;

    ofstream subir("data.txt");

    for (int i = 0; i < CodiVect.size(); i++) {
    subir << CodiVect[i] << " " << nombre[i] << " " << tipo[i] << " " << cantVect[i] << " " << precio[i] << endl;
    }
    subir.close();

}

acciones::~acciones()
{
    //dtor
}

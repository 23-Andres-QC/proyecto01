#include "acciones.h"
using namespace std;
void acciones::agregar(int codi,string nombre,string clase,int cantidad){
    ofstream datos("data.txt",ios::app);
    datos<<codi<<" "<<nombre<<" "<<clase<<" "<<cantidad;
}
void acciones::eliminar(int codi){
    ifstream datos1("data.txt");
    string linea;
    int posicion;
    int a;
    int codig,can;
    string nom,tip;
    CodiVect.clear();
    cantVect.clear();
   while (datos1>>codig>>nom>>tip>>can) {
        CodiVect.push_back(codi);
        cantVect.push_back(can);
    }

   for (int i=0; i<CodiVect.size(); i++) {
        if (CodiVect[i]==codi) {
            posicion=i;
        }
    }

    for (int i=0; i<cantVect.size(); i++) {
        if (cantVect[i]==0) {
            pos2.push_back(i);
        }
    }

    while(getline(datos1,linea)){
        lineas.push_back(linea);
    }
    datos1.close();

    lineas.erase(lineas.begin() + posicion);

    for(int i=0;i<pos2.size();i++){
        lineas.erase(lineas.begin() + pos2[i]);
    }

    ofstream datos2 ("data.txt");
    for (int i=0; lineas.size();i++) {
        datos2 <<lineas[i]<< endl;
    }
    datos2.close();
}
void acciones::modificar(int codiG,int cant){
    ifstream in("data.txt");
    int pos=-1;
    int codi;
    string nom;
    string tip;
    int can;
    CodiVect.clear();
    cantVect.clear();

    while (in>>codi>>nom>>tip>>can) {
        CodiVect.push_back(codi);
        cantVect.push_back(can);
    }
    in.close();
    for (int i=0; i<CodiVect.size(); i++) {
        if (CodiVect[i]==codigo) {
            pos=i;
        }
    }
    if (pos!=-1) {
        cantVect[pos]=cant;
    } else {
        cout << "Codigo no encontrado en el archivo " << endl;
        return;
    }
    ofstream subir("data.txt");

    for (int i=0;i<CodiVect.size(); i++) {
        subir<<CodiVect[i]<<" "<<nom<<" "<<tip<<" "<<cantVect[i]<< endl;
    }

    subir.close();


}
acciones::~acciones()
{
    //dtor
}

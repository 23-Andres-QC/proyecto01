#include "Record.h"
#include <iostream> // Include the <iostream> header file for 'cout'

using namespace std; // Add the 'using namespace std;' directive

Record::Record(int codigo_,string nombre_,string tipo_,int cantidad_,double precio_){
            this -> codigo=codigo_;
            this -> nombre=nombre_;
            this -> tipo=tipo_;
            this -> cantidad=cantidad_;
            this -> precio=precio_;

        };

void Record::show(){
    cout<<this->codigo <<" "<<this-> nombre <<" "<<this->tipo<<" "<<this->cantidad<<" "<<this->precio<<endl;
}

Record::~Record()
{
    //dtor
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class avion{
public:
    string aerolinea;
    int numserie;
    avion(){aerolinea="AEROLINEA NO REGISTRADA ";numserie=0;}
    avion(string Naero,int Nserie){aerolinea=Naero;numserie=Nserie;}

    virtual void mensaje()=0;
    void mostrar(){
        cout<<"Numero de serie: "<<numserie<<" de "<<aerolinea<<endl;
    }
};
class transporte:public avion{

    int Numpasa;
    public:
    transporte(int a = 0):Numpasa(a){};
    void mensaje(){
        cout<<"Avion de transporte,su numero de pasajeros es:"<<Numpasa<<endl;
    }
};
class cargamento:public avion{
     int Numcarga;
    public:

    cargamento(int a = 0):Numcarga(a){};
    void mensaje(){
        cout<<"Avion de carga,su numero de carga es:"<<Numcarga<<endl;
    }
};
class guerra:public avion{
    int balas;
public:
    guerra(int a=0):balas(a){};

    void mensaje(){
        cout<<"Avion de querra,su numero de balas es:"<<balas<<endl;
    }
};

class Torre{
    vector<avion*>aviones;
    static int tot;
public:
    Torre(){}
    void agregar(avion*a){
        tot++;
        aviones.push_back(a);
    }
    void enviar(int navion,string mensaje){
        aviones[navion]->mensaje();
        cout<<mensaje<<endl;
    }
    void mostrar_a(){
        for(int i=0;i<tot;i++){
            aviones[i]->mostrar();

        }
    }

};
int Torre::tot=0;

int main(){

    Torre ballon1;
    transporte e1(25);
    e1.aerolinea={"Latam"};e1.numserie=123;
    cargamento e2(2);
    guerra e3(100);
    ballon1.agregar(&e1);
    ballon1.agregar(&e2);
    ballon1.agregar(&e3);
    ballon1.mostrar_a();
    ballon1.enviar(1,"Que tenga buen vuelo");

}

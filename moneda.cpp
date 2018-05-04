#include <iostream>
#include <vector>
using namespace std;
class moneda{
    public:
        int soles;int centavos;
        moneda(){soles=0;centavos=0;}
        moneda(int ns,int nc){soles=ns;centavos=nc;}
};
 moneda operator+(const moneda a, const moneda b){
    moneda c;
    c.soles=a.soles+b.soles;
    c.centavos=a.centavos+b.centavos;
    if(c.centavos>=100){c.soles+=1;c.centavos=c.centavos-100;}
    return c;


 }
moneda operator-(const moneda a, const moneda b){
    moneda c;
    if(a.soles>b.soles && a.centavos>b.centavos){
        c.soles=a.soles-b.soles;
        c.centavos=a.centavos-b.centavos;
    }
     if(a.centavos<b.centavos &&a.soles>b.soles){
        c.soles=a.soles-b.soles;
        c.centavos=a.centavos-b.centavos + 100;
        c.soles-=1;
    }
    if(a.soles==0 && b.soles==0 && a.centavos>b.centavos){
        c.soles=0;
        c.centavos=a.centavos-b.centavos;
    }
    return c;


}


 ostream& operator<<(ostream &output, const moneda &x){
    output<<x.soles<<"."<<x.centavos;

 }

 class billetera{
    vector <moneda> lista;
    int sizee=0;
    public:

    void agregar(moneda a){
        sizee++;
        lista.push_back(a);}
    void mostrar(){
    for(int i=0;i<sizee;i++){
        cout<<lista[i]<<endl;}
    }
    void total(){
        moneda nueva,nuev1;
        for(int i=0;i<sizee;i++){
            nueva=lista[i]+nueva;
        }
         cout<<nueva;
    }
    void borrar(int pos){
        lista.erase(lista.begin()+pos);
        sizee--;
    }

};





int main(){
    moneda a(0,20),b(0,30),c(1,30),d(8,60);
    billetera lacoste;
    lacoste.agregar(a);
    lacoste.agregar(b);
    lacoste.agregar(c);
    lacoste.agregar(d);
    cout<<"Las monedas que tienes ahora son "<<endl;lacoste.mostrar();
    cout<<"El total de la billetera es ";lacoste.total();cout<<endl;
    lacoste.borrar(2);
    lacoste.mostrar();
    cout<<"TOTAL: ";lacoste.total();


    return 0;


}

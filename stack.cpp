#include <iostream>
#include <vector>
using namespace std;

 template < class T>
 class Stack {
     public:
           vector<T>items;

           bool empty () const { return items.empty () ;}
           void push ( const T & item ) { items . push_back ( item );}
           T pop () {
                T last = items . back ();
                items . pop_back ();
                return last ;
            }
           T &top(){
           		return items.back();
               /* T last=items.back();
                return last;*/
           }
           void mostrar(){
                for(int i=0;i<items.size();i++){
                    cout<<items[i]<<" ";
                }
                cout<<endl;
           }
  };

  int main(){
   Stack<int>a;
   a.push(2);
   a.push(4);
   a.push(6);
   a.mostrar();
   cout<<a.top()<<endl;
   a.pop();
   a.mostrar();
   if(a.empty()==1){
        cout<<"Vacia"<<endl;}
    else{cout<<"Aun con elementos"<<endl;}




   }



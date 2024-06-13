#include<iostream>
using namespace std;

class uninary{
    int a,b;
    public:
    uninary(int x,int y){
        a=x;
        b=y;
    }
    void out(){
        cout<<"A="<<a<<endl<<"B="<<b<<endl;
    }
    
    void operator -(){
        a=-a;
        b=-b;
    }
};

int main(){
    int a,b;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;
    uninary c(a,b); 
    c.out();
    -c;
    c.out();
    return 0;
}

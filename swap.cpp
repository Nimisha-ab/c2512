#include <iostream>
using namespace std;


void swapNo(int &n1,int &n2){
    int temp=n1;
    n1=n2;
    n2=temp;
}
void swapofTest(){
    int n1,n2;
    cout<<"enter n1"<<endl;
    cin>>n1;
    cout<<"enter n2"<<endl;
    cin>>n2;
    swapNo( n1, n2);
    cout<<"new no1"<<n1<<endl;
    cout<<"new no2"<<n2<<endl;
    
}

int main(){
    swapofTest();
    return 0;
}

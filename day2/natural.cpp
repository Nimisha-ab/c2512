#include <iostream>
using namespace std;


void printNaturalno(int n){
    if(n>0)
    {
        for(int i=1;i<=n;i++){
            cout<<i<<endl;
        }
    }
}
void printNaturalnoTest(){
    int n;
    cout<<"enter the no"<<endl;
    cin>>n;
    printNaturalno(n);
}

int main(){
    printNaturalnoTest();
}

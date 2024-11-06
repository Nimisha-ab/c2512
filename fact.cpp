#include <iostream>
using namespace std;

int main(){
    int n,i,fact=1;
    cout<<"enter a no"<<endl;
    cin>>n;
    for(i=1;i<n;i++)
    {
        fact=fact*i;
    }
    cout<<"factorial of no is"<<fact<<endl;
}

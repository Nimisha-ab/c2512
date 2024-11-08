#include <iostream>
using namespace std;

int avgofNo(int n1,int n2){
    return (n1+n2)/2;
}
void avgofNoTest(){
    int n1,n2;
    cout<<"enter no1"<<endl;
    cin>>n1;
    cout<<"enter no2"<<endl;
    cin>>n1;
    int avg=avgofNo(n1,n2);
    cout<<"avg of no is"<<avg<<endl;
}
    
       

int main()
{
    avgofNoTest();

    return 0;
}

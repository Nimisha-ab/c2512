#include <iostream>
using namespace std;

int cubeofNo(int no){
    return no*no*no;
}
 void cubeNoTest(){
     int no; 
     cout<<"enter the no"<<endl;
     cin>>no;
     int cube=cubeofNo( no);
     cout<<"cube of no is"<<cube<<endl;
     
 }      

int main()
{
    cubeNoTest();

    return 0;
}

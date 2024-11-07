#include <iostream>
using namespace std;


int squareofNo(int no){
    return no*no;
}
 void squareNoTest(){
     int no; 
     cout<<"enter the no"<<endl;
     cin>>no;
     int square=squareofNo( no);
     cout<<"square of no is"<<square<<endl;
     
 }      

int main()
{
    squareNoTest();

    return 0;
}

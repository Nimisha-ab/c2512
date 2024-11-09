#include <iostream>
    using std::cout;
    using std::cin;
    
    
    bool isLeapYear(int year ){
        
    
            return ((year % 4 == 0 && year % 100 !=0) || (year % 400 == 0));
    }         
    void isLeapYearTest(){
            int year;
            cout<<"enter the year";
            cin>>year;
            if (isLeapYear(year)){
                
            
               cout<<year<<"is Leap Year";
            }
            else
            {
               cout<<year<< "Not Leap Year";
            }
    }
            
    int main(){
     
           isLeapYearTest();
           return 0;
    
        
    }

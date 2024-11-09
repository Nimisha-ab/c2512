#include <iostream>
using std::cout;
using std::cin;

int reverseNumber(int number)
{
    int reverse = 0;

    while(number != 0)
    {
        int reminder = (number % 10);
        reverse = ((reverse * 10) + reminder);
        number = (number / 10);
    }
     
    return reverse;
}

bool isNumberPalindrome(int number)
{
    int reverse = reverseNumber(number);

    return (number == reverse);
}
         
void isNumberPalindromeTest(void)
{
    int number;
    
    cout << "Enter number: ";
    cin >> number;
    
    if(isNumberPalindrome(number))
    {
        cout << number << " is Palindrome";
    }
    else
    {
        cout << number << " is not Palindrome";
    }
}

int main(void)
{
    isNumberPalindromeTest();
    
    return 0;
}

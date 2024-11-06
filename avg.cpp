#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3;
    float avg; 

    cout << "Enter the 3 numbers: " << endl;
    cin >> n1 >> n2 >> n3;

    
    avg = (n1 + n2 + n3) / 3.0;  

    cout << "Average of the numbers is: " << avg << endl;

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    char a ;
    while (cin >>a)
    {
        switch (a)
        {
        case 'a':
            cout << "1\n";
            break;
        case 'b':
            cout << "2\n" ;
            break;
        case 'c':
            cout << "3\n" ;
            break;
        
        default:
            cout << "non\n" ;
            break;
        }
    }
    
}
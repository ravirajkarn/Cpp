#include <iostream>
#include <string>

using namespace std;

int main()
{
    string zoro = "45yes";
    int a;
    while (cin >> a)
    {
        bool lufi = isalpha(zoro.at(a));
        if ( lufi == true)
        //bool yes = isalpha(zoro[a]);
            cout << "yes" << '\n';
        else
        cout << "no" << '\n' ;
    }
    
}
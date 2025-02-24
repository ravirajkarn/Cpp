#include<iostream>
#include <iomanip>

using namespace std;

int main()
{
    int hight = 5;
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j+1;  
        }
        cout  << setw(2*hight - 2*(i)-1)<< setfill(' ');
        for (int j = i; j >= 0; j--)
        {
            cout << j+1;  
        }
        cout << endl;   
    }
    return 0;
}
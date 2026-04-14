/*

    Write a C++ program that outputs a complete multiplication table (as shown opposite) on screen.

*/

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    int row=1, colunm=1;
    
    while(row <= 10)  // upper row
    {
        if(row==1)
        {
            cout << setfill(' ') << setw(10) << row ;
            row++;
        }else
        {
            cout<< setfill(' ') << setw(4) << row ;
            row++;            
        }
    }
    row=1;
    cout << endl<< setfill('_') << setw(48)<<"_"<< endl;

    for (row=1,colunm=1;colunm <= 10; colunm++)
    {
        cout << setfill(' ') << setw(4) << colunm << " |";
        for (row=1; row <= 10; row++)
        {
            cout << setw(4) << row * colunm;
        }
        cout /*<< " |" */<< endl;
    }
    
    //cout << setfill('-') << setw(48)<<"-"<< endl;
    return 0;
}
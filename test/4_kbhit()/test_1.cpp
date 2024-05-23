//! this program is test kbhit() and getch().
//~ dafdff
//? fgsfgf
// fdsgsfdv
//* sfgsggssvvs


#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main(){
    int a, b;

    START:
    
    if(kbhit() != 0) {
        int a(getch());

        cout << a << endl ;
        goto START;
        /*if(getch() == 27)
        return 0;
        else 
        ;*/
    }
    else
        goto START;
       /* for( int c(0) , n = 0; c <= 42; c++ , n=n+2 )
    {
        cout << setw(43-n/2) << " ";
        for (int r(0) ; r <= c; r++)
        {
            cout << "* " ;
        }
        cout << endl;
    }


    cout << "\n\n\n";

    goto START;*/

}

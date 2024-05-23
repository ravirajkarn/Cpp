#include <iostream>
#include <cmath>

using namespace std;
int main(){
    double a[4];
    string line(40,'_');
    a[0]=4, a[1]=12.25, a[2]=0.0121;
    cout << "enter number to get square. To exit enter 0.\n";
    int i(0);
    do
    {
        if (i!=0)
            {
                do
                {   
                    if (i==3)
                    {
                        cin >> a[3];
                        cout << a[i] << "\t" << sqrt(a[i]) << endl;
                    }
                    else
                    {
                        cout << a[i] << "\t" << sqrt(a[i]) << endl;
                        i++;
                    }
                } while (a[3]!=0);
            }
        else
            {
                cout << "Number \t square root \n" << line << endl;
                cout << a[i] << "\t" << sqrt(a[i]) << endl;
                i=i+1;            
            }
    } while (a[3]!=0);
    return 0;
}
/*This file is a detailed analysis to find average of given inters.
/*Motive to collect and use all the possible ways or algorithm to find average.
/*Table contains:-
/*1) average1   #
/*# is the best one till now */

#include<iostream>

using namespace std;

double average1(int n, double sum);

int main (){
    double sum(0), a;
    int n(0);
    cout <<"\nEnter your numbers to calculate average." << endl;
    do
    {
        a = 0;
        cin >> a;
        cout << endl;
        sum = sum + a ;
        n++;
    } while (a != 0);
    cout << "your average is : " << average1(n, sum);
    return 0;     
}

/*This average1 is function created by me. Without any help from external source.*/
double average1(int n, double sum){
    return sum/n;
}
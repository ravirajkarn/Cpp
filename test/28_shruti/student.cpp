#include <iostream>

using namespace std;

class Student
{
private:
    int Roll_no;
    char Name[20];
    char Class[8];
    int Marks[4];
    float Percentage;
public:
    void ReadData(){
        cout << "Enter Roll No: ";
        cin >> Roll_no;
        cout << "Enter Name: ";
        cin >> Name;
        cout << "Enter Class: ";
        cin >> Class;
        cout << "Enter Marks in 4 Subject.(Full Marks 100)\nEnglish: ";
        cin >> Marks[0];
        cout << "Maths: ";
        cin >> Marks[1];
        cout << "Science: ";
        cin >> Marks[2];
        cout << "Social Science: ";
        cin >> Marks[3];
    }
    void Calculate(){
        Percentage = (Marks[0] + Marks[1] + Marks[2] + Marks[3]) / 4;
    }
    void Display(){
        cout << "\n\nRoll No: " << Roll_no << '\n';
        cout << "Name: " << Name << '\n';
        cout << "Class: " << Class << '\n';
        cout << "Marks in 4 Subject.\nEnglish: " << Marks[0] << '\n';
        cout << "Maths: " << Marks[1] << '\n';
        cout << "Science: " << Marks[2] << '\n';
        cout << "Social Science: " << Marks[3] << '\n';
        cout << "Percentage: " << Percentage << '\n';
    }
};

int main(){
    Student s;
    s.ReadData();
    s.Calculate();
    s.Display();
    return 0;
}
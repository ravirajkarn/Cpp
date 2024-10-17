#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

//! the code be more optimize.

//~ search function 1.
/*
 This function is basic function.
 function is taking large amount of time.
 reasons: 
    * we are working with fourteen variables i.e. arr[] of size 10, size, key and i.
    * arr is faster but vector is dynamic.
*/
bool search(int arr[], int size, int key){ 
    for (int  i = 0; i < size; i++) 
    {
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

//~ search function 2.
/*
    this is taking half the time of function 1. faster
    using "range based loop" which is new and advance.
    reason:
        * less variable i.e. arr of size 10, key and temp. where temp is reference which consume less space.
        * vector allows you use dynamic size i.e. you can increase the size of arr in runtime form 10 to 15.
*/
bool search(vector<int> arr, int key){
    for(const auto &temp : arr)
        if(temp == key)
            return 1;
    return 0;
}

int main(){
    //~ function 1
    cout << "running function 1 and testing runtime.\n";
    cout << "Enter the element to search for \n";
    int key;
    cin >> key;

    auto now = chrono::high_resolution_clock::now();  //* this function capture the current time and store in now variable. To generate run time information. 
    
    int arr[10] = {5,7,-2,10,22,-2,0,5,22,1};

    bool found = search(arr, 10, key);

    if(found){
        cout << "present" << endl;
    }
    else {
        cout << "absent" << endl;
    }
    auto end = chrono::high_resolution_clock::now(); //* this function capture the current time and store in end variable. to generate run time information.
    auto duration = chrono::duration_cast<std::chrono::microseconds>(end -now); //* by subtracting now and end variable in the given circumstances we get runtime and store in duration variable function.
    
    cout << "\nrun time: " << duration.count() << " microseconds\n\n"; //* we get the runt time output through duration.cout() function. 




    //~ runtime of function 2;

    cout << "running function 2 and testing runtime.\n";

    auto now1 = chrono::high_resolution_clock::now();
    
    vector arrr = {5,7,-2,10,22,-2,0,5,22,1};

    bool found1 = search(arrr, key);

    if(found1){
        cout << "present" << endl;
    }
    else {
        cout << "absent" << endl;
    }
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<std::chrono::microseconds>(end1 -now1);
    
    cout << "\nrun time: " << duration1.count() << " microseconds\n";

    return 0;
}
#include <iostream> 

int main(){
    int v[] = {10, 20, 30, 40 }, i, *pv;

    std::cout << "\nPoint a.\n";
    for (pv = v; pv <= v + 3 ; pv++)
        std::cout << "       *pv = "<< *pv;

    std::cout << "\nPoint b.\n";
    for (pv = v, i = 1; i <= 3 ; i++)
        std::cout << "     pv[i] = "<< pv[i];

    std::cout << "\nPoint c.\n";
    for (pv = v, i = 0; pv+i <= &v[3] ; pv++, i++)
        std::cout << " *(pv + i) = "<< *(pv + i);

    std::cout << "\nPoint d.\n";
    for (pv = v + 3; pv >= v; --pv)
        std::cout << "      v[" << (pv -v) << "] = " << v[pv -v];
    
    return 0;
}
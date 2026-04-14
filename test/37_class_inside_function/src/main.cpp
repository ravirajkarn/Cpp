#include <iostream>
#include <vector>

void test37() {
    class MyClass {
    public:
        void display() {
            std::cout << "Hello from MyClass!" << std::endl;
        }
    };

    MyClass obj;
    obj.display();
}

int main() {
    int x = 100;
    std::cout << x << std::endl;

    test37();
}
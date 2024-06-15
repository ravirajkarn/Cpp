/*
Exercise 2
In the exercises for chapter 13, an initial version of the Date class containing
members for day, month, and year was defined. Now extend this class to add
additional functionality.The methods are shown on the opposite page.
■The constructors and the method setDate() replace the init method
used in the former version.The default constructor uses default values,
for example, 1.1.1, to initialize the objects in question.The setDate()
method without any parameters writes the current date to the object.
■The constructor and the setDate() method with three parameters do
not need to perform range checking.This functionality will be added in
the next exercise.
■The methods isEqual() and isLess() enable comparisons with a date
passed to them.
■The method asString() returns a reference to a string containing the
date in the format mm-dd-year, e.g. 03-19-2006.You will therefore need
to convert any numerical values into their corresponding decimal strings.
This operation is performed automatically when you use the << operator
to output a number to the standard output cout. In addition to the cin
and cout streams, with which you are already familiar, so-called string
streams with the same functionality also exist. However, a string stream
does not read keyboard input or output data on screen. Instead, the tar-
get, or source, is a buffer in main memory.This allows you to perform for-
matting and conversion in main memory.
■Use an application program that calls all the methods defined in the class
to test the Date class.
*/


#include "timee.h"

int main()
{
    Date first(10,05,2024);
    first.print();

    first.setDate();
    first.print();

    std::cout << '\n' << first.getDay() << '.' << first.getMonth() << '.' << first.getYear() << '\n';
    Date second(10,2,2023);
    std::cout << first.isEqual(second) << '\t' << first.isLess(second) << '\n';
    std::cout << first.asString();
    return 0;
}
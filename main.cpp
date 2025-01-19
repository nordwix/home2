#include "Array.h"
#include "String.h"
#include <iostream>

int main() {
    /*Array arr;

    std::cout << "Size: " << arr.getSize() << ", capacity: " << arr.getCapacity() << "\n";

    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.display();

    std::cout << "Append elements, size: " << arr.getSize() << ", capacity: " << arr.getCapacity() << "\n";

    arr.reserve(50);
    std::cout << "Reserved capacity, size: " << arr.getSize() << ", capacity: " << arr.getCapacity() << "\n";

    arr.erase(1);
    arr.display();
    std::cout << "Erased an element, size: " << arr.getSize() << ", capacity: " << arr.getCapacity() << "\n";

    arr.shrink();
    std::cout << "Shrink, size: " << arr.getSize() << ", capacity: " << arr.getCapacity() << "\n";

    arr.clearAll();
    std::cout << "Cleared all elements, size: " << arr.getSize() << ", capacity: " << arr.getCapacity() << "\n";

    return 0;*/



    String str1("Hello");
    str1.output();

    str1.append('!');
    str1.output();

    String str2(" World");
    str1.append(str2);
    str1.output();

    std::cout << "Length: " << str1.length() << ", Capacity: " << str1.getCapacity() << std::endl;

    str1.reserve(100);
    std::cout << "Reserved, Capacity: " << str1.getCapacity() << std::endl;

    str1.shrink();
    std::cout << "Shrink, Capacity: " << str1.getCapacity() << std::endl;

    str1.clear();
    str1.output();

    std::cout << "Cleared, Length: " << str1.length() << ", Capacity: " << str1.getCapacity() << std::endl;

    return 0;
}

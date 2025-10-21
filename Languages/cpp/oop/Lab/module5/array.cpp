#include <iostream>
#include <array>
#include <string>
class ArrayOperations {
private:
    std::array<int, 6> ax;

public:
    void printArray() {
        std::cout << "Current array elements: ";
        for (int element : ax) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    void assignValues() {
        std::cout << "i) Assigning 10, 60, 30, 70, 20..." << std::endl;
        // The array has 6 elements. The 6th element will be value-initialized to 0.
        ax = {10, 60, 30, 70, 20};
        printArray();
    }

    // ii) Print third element of ax using at() function
    void printThirdElement() {
        std::cout << "ii) Third element (at index 2): " << ax.at(2) << std::endl;
    }

    // iii) Print first element of ax using front() function
    void printFirstElement() {
        std::cout << "iii) First element: " << ax.front() << std::endl;
    }

    // iv) Print last element of ax using back() function
    void printLastElement() {
        std::cout << "iv) Last element: " << ax.back() << std::endl;
    }

    // v) Fill the elements of ax using fill() function
    void fillArray() {
        int fill_value = 5;
        std::cout << "v) Filling the array with value " << fill_value << "..." << std::endl;
        ax.fill(fill_value);
        printArray();
    }

    // vi) Test whether ax is empty or not using empty() function
    void checkIfEmpty() {
        // std::array::empty() is a constexpr function available since C++11.
        // It returns true if the array size is 0, false otherwise.
        // For a fixed-size array like std::array<int, 6>, this will always be false.
        std::cout << "vi) Is array empty? " << (ax.empty() ? "Yes" : "No") << std::endl;
    }

    // vii) Print size of ax
    void printSize() {
        std::cout << "vii) Size of array: " << ax.size() << std::endl;
    }

    // viii) Print maximum size of ax using max_size() function
    void printMaxSize() {
        // For std::array, size() and max_size() return the same value.
        std::cout << "viii) Maximum size of array: " << ax.max_size() << std::endl;
    }

    // ix) Print address of first element of ax using begin() function
    void printBeginAddress() {
        // begin() returns an iterator to the first element.
        // &*ax.begin() gets the address of the element the iterator points to.
        // ax.data() is a more direct way to get a pointer to the underlying data.
        std::cout << "ix) Address of the first element (begin): " << &*ax.begin() << std::endl;
    }

    // x) Print address of the element following the last element using end() function
    void printEndAddress() {
        // end() returns an iterator to the element *past* the last element.
        // This address is often used in range-based operations but does not point to a valid element.
        std::cout << "x) Address of the element after the last (end): " << &*ax.end() << std::endl;
    }
};

int main() {
    ArrayOperations demo;

    demo.assignValues();
    std::cout << "----------------------------------------" << std::endl;

    demo.printThirdElement();
    std::cout << "----------------------------------------" << std::endl;

    demo.printFirstElement();
    std::cout << "----------------------------------------" << std::endl;

    demo.printLastElement();
    std::cout << "----------------------------------------" << std::endl;

    demo.fillArray();
    std::cout << "----------------------------------------" << std::endl;

    demo.checkIfEmpty();
    std::cout << "----------------------------------------" << std::endl;

    demo.printSize();
    std::cout << "----------------------------------------" << std::endl;

    demo.printMaxSize();
    std::cout << "----------------------------------------" << std::endl;

    demo.printBeginAddress();
    std::cout << "----------------------------------------" << std::endl;
    
    demo.printEndAddress();
    std::cout << "----------------------------------------" << std::endl;

    return 0;
}
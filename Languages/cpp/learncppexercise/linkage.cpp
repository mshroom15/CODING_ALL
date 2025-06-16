#include <iostream>
using namespace std;

int main() {
    int x{5};
    {
        int x{10};
        std::cout << "Inside block: x = " << x <<std::endl;
    }
    cout << "Outside block: x = " << x << endl;

    return 0;
}
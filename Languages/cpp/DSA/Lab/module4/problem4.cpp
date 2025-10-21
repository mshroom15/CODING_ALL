#include <iostream>

using namespace std;

int main() {
    int info[12]={0,0, 201, 402, 325, 101, 301, 251,0,0, 385,0};
    int link[12] = {0, 0, 7, 0, 10, 2, 4, 6, 0, 0, 3, 0};
    int start = 5;
    int current = start;
    int item = 385;
    int index = -1;
    cout << "The elements in the list are: ";
    while (current != 0) {
        if(item==info[current]){
            index = current;
            cout << "index: " << current << " value: " << info[current] << " ";
            break; 
        }
        current = link[current];
    }
    if(index == -1) {
        cout << "Item not found in the list.";
    } ;

    return 0;
}

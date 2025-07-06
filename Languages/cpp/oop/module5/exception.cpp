#include <iostream>  
using namespace std;    
int main() {    
    try {
        int i;    
        int ax[5] = {10, 20, 60, 40, 30};    
        cout << "enter index: ";    
        cin >> i;    
        
        if (i < 0 || i >= 5) {
            if (i < 0)
                throw i;
            else
                throw string("Out of Range Error");
        }
        
        cout << "ax[" << i << "]=" << ax[i] << endl;
    }
    catch (int index) {5
        cout << "Negative index error: " << index << endl;
    }
    catch (string msg) {
        cout << "Exception: " << msg << endl;
    }
    catch (...) {
        cout << "Default exception handler: Unknown exception" << endl;
    }
    
    return 0;
}
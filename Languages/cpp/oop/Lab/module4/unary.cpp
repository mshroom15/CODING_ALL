#include <iostream>
using namespace std;

class Remote {
private:
    int sound;

public:
    Remote(int s = 50) : sound(s) {}
    Remote& operator++() {
        if (sound < 100) { // Assuming maximum sound is 100
            sound++;
            cout << "Sound increased to: " << sound << endl;
        } else {
            cout << "Sound already at maximum!" << endl;
        }
        return *this;
    }
    Remote& operator--() {
        if (sound > 0) { // Assuming minimum sound is 0
            sound--;
            cout << "Sound decreased to: " << sound << endl;
        } else {
            cout << "Sound already at minimum!" << endl;
        }
        return *this;
    }
    
    // Display function to show current sound level
    void Display() {
        cout << "Current sound level: " << sound << endl;
    }
};

int main() {
    Remote rs;
    ++rs; // Sound increases when '+' button is pressed
    ++rs; 
    --rs; // Sound decreases when '-' button is pressed
    rs.Display(); // Display the value of sound
    return 0;
}
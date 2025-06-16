#include<iostream>
#include<string>
#include<string_view>
using namespace std;
void printView(string_view view) {
        cout << "View in function: " << view << endl;
    }
int main() {
    string str = "Hello, World!";
    string_view sv = str; // Create a string_view from a string

    cout << "String: " << str << endl;
    cout << "String View: " << sv << endl;

    // Modifying the original string
    str[0] = 'h';
    cout << "Modified String: " << str << endl;
    cout << "String View after modification: " << sv << endl;

    // Using string_view to access a substring
    string_view sv_sub = sv.substr(7, 5); // Get "World"
    cout << "Substring from String View: " << sv_sub << endl;
    
    // Example of string_view in function parameters
    
    
    // More efficient than passing std::string because no copy is made
    printView(sv);
    printView("Direct literal");  // Works with string literals too
    
    // Function that returns a string_view
    auto getFirstWord = [](string_view input) -> string_view {
        size_t pos = input.find(' ');
        return input.substr(0, pos);
    };
    
    string_view first = getFirstWord(sv);
    cout << "First word: " << first << endl;

    return 0;
}
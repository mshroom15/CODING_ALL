#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

int main() {
    // Basic string creation
    std::string s1 = "Hello";
    std::string s2("World");
    std::string s3(5, '*'); // ***** (5 asterisks)
    
    std::cout << "Basic strings: " << s1 << " " << s2 << " " << s3 << "\n\n";
    
    // String concatenation
    std::string combined = s1 + " " + s2 + "!";
    std::cout << "Concatenation: " << combined << "\n\n";
    
    // String length and size
    std::cout << "Length: " << combined.length() << "\n";
    std::cout << "Size: " << combined.size() << "\n";
    std::cout << "Max size: " << combined.max_size() << "\n";
    std::cout << "Capacity: " << combined.capacity() << "\n\n";
    
    // String access
    std::cout << "First character: " << combined[0] << "\n";
    std::cout << "Last character: " << combined.back() << "\n";
    std::cout << "Using at(): " << combined.at(6) << "\n\n";
    
    // String modification
    std::string modify = "Hello";
    modify.append(" World");
    modify.push_back('!');
    std::cout << "After append and push_back: " << modify << "\n";
    
    modify.insert(5, " beautiful");
    std::cout << "After insert: " << modify << "\n";
    
    modify.replace(6, 9, "wonderful");
    std::cout << "After replace: " << modify << "\n";
    
    modify.erase(5, 10);
    std::cout << "After erase: " << modify << "\n\n";
    
    // Substring
    std::string text = "The quick brown fox";
    std::cout << "Substring: " << text.substr(4, 5) << "\n\n";
    
    // Find operations
    std::string sentence = "C++ programming is fun and C++ is powerful";
    std::cout << "Find 'fun': " << sentence.find("fun") << "\n";
    std::cout << "Find 'C++' from beginning: " << sentence.find("C++") << "\n";
    std::cout << "Find 'C++' from position 10: " << sentence.find("C++", 10) << "\n";
    std::cout << "Find last 'C++': " << sentence.rfind("C++") << "\n";
    
    if (sentence.find("Python") == std::string::npos) {
        std::cout << "'Python' not found\n\n";
    }
    
    // Compare
    std::string a = "apple";
    std::string b = "banana";
    std::cout << "Compare 'apple' to 'banana': " << a.compare(b) << "\n";
    std::cout << "Compare 'banana' to 'apple': " << b.compare(a) << "\n\n";
    
    // String to number conversion
    std::string numStr = "42";
    int num = std::stoi(numStr);
    std::cout << "String to int: " << num << " (+" << (num + 10) << ")\n";
    
    std::string floatStr = "3.14159";
    double pi = std::stod(floatStr);
    std::cout << "String to double: " << pi << " (*2=" << (pi * 2) << ")\n\n";
    
    // Number to string conversion
    int value = 123;
    std::string valueStr = std::to_string(value);
    std::cout << "Int to string: " << valueStr << " + 100 = " << valueStr + "100" << "\n\n";
    
    // String algorithm examples
    std::string mixed = "AbCdEf";
    std::transform(mixed.begin(), mixed.end(), mixed.begin(), ::tolower);
    std::cout << "Lowercase: " << mixed << "\n";
    
    std::transform(mixed.begin(), mixed.end(), mixed.begin(), ::toupper);
    std::cout << "Uppercase: " << mixed << "\n\n";
    
    // String streams
    std::stringstream ss;
    ss << "Age: " << 25 << ", Height: " << 1.75;
    std::string streamStr = ss.str();
    std::cout << "Stringstream: " << streamStr << "\n";
    
    // Parsing with stringstream
    std::stringstream parser("10 20 30");
    int a1, a2, a3;
    parser >> a1 >> a2 >> a3;
    std::cout << "Parsed values sum: " << (a1 + a2 + a3) << "\n";
    
    return 0;
}
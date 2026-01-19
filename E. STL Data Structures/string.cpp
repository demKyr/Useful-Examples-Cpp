#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str1 = "Hello,";
    char str2[] = "World!";
    string str3 = str1 + " " + str2; // concatenation, complexity: O(n)
    cout << str3 << endl;
    
    cout << "Length of str3: " << str3.length() << endl; // prints length of str3, complexity: O(1)
    cout << "Length of str3: " << str3.size() << endl; // same as length(), complexity: O(1)

    str3.push_back('!'); // adding a character at the end , complexity: O(1) amortized
    cout << str3 << endl; // prints Hello, World!!
    str3.pop_back(); // removing the last character
    cout << str3 << endl; // prints Hello, World!

    str3.replace(7, 5, "C++"); // replacing the part that starts at index 7 with length 5 with "C++", complexity: O(n)
    cout << str3 << endl; // prints Hello, C++!

    str3.erase(5, 2); // erasing 2 characters starting from index 5, complexity: O(n)
    cout << str3 << endl; // prints HelloC++!

    cout << str3.substr(1, 4) << endl; // prints substring from index 1 with length 4, complexity: O(n)

    int pos = str3.find("C++"); // finding substring, complexity: O(n*m) where m is length of substring
    if(pos < str3.size())
        cout << "'C++' found at position: " << pos << endl; // prints position of C++

    if(str3 == "HelloC++!") // comparing strings, complexity: O(n)
        cout << "str3 is equal to 'HelloC++!'" << endl;

    int lastc = str3.rfind('l'); // finding last occurrence of character, complexity: O(n)
    if(lastc < str3.size())
        cout << "Last occurrence of 'l' is at position: " << lastc << endl; // prints position of last 'l'

    reverse(str3.begin(), str3.end()); // reversing the string, complexity: O(n)
    cout << "Reversed str3: " << str3 << endl; // prints !++ColleH

    str3.clear(); // clearing the string
    cout << "Is str3 empty? " << str3.empty() << endl; // prints 1 (true)

    return 0;
}
#include<iostream>
#include <sstream> // for stringstream
#include <iomanip> // for setprecision

// stringstream stream; // create a stringstream object
// getline(stream, str, delim); // reads from stream into str until delim is found (delim is optional, default is '\n')

using namespace std;

int main(){

    string tempinput = "12.3413 45.6735 78.9024";
    stringstream ss(tempinput); // create a stringstream object initialized with tempinput string
    double number;
    vector<double> numbers;
    while(ss>>number)   // read double numbers from the stringstream until no more numbers are left
        numbers.push_back(number);
    for(double num : numbers)
        cout<<num<<" ";
        cout<<endl; 

    ss.clear(); // clear the eof and fail flags
    
    ss << fixed<<setprecision(2) << "number 1: " << numbers[0] << ", number 2: " << numbers[1] << ", number 3: " << numbers[2]; // write formatted data into the stringstream
    cout << ss.str() << endl; // .str() returns the contents of the stringstream as a string
        

    cout<<"Enter a line of text separated with spaces: ";
    string line, element;
    if(!getline(cin, line)) // reads a line from standard input into the string 'line'
        cout<<"error";
    stringstream sstrm(line); // create a stringstream object initialized with the input line
    while(getline(sstrm, element, ' ')){ // splits line in every ' '
        cout<<element<<"|";
    }
    cout<<endl;

    sstrm.clear(); // clear the eof and fail flags
    
    cout<<"Enter a line of text separated with commas: ";
    if(!getline(cin, line)) // reads a line from standard input into the string 'line'
    cout<<"error";
    // sstrm<<line; // would not work as expected because the read pointer is at the end
    sstrm.str(line); // set the contents of the stringstream to the new input line
    while(getline(sstrm, element, ',')){ // splits line in every ','
        cout<<element<<"|";
    }
    cout<<endl;

    return 0;

}
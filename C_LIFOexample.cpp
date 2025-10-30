#include<iostream>

using namespace std;

#define MAX_SIZE 100

class Stack {

	public:
		Stack();

		char& operator[](int index);
		const char& operator[](int index) const;

		int count() const;

		void push(char value);
		char pop();

	private:
		char array[MAX_SIZE];
		int head;

};

Stack::Stack() {
	head = 0;
}

char& Stack::operator[](int index) {
	return array[index];
}

const char& Stack::operator[](int index) const {
	return array[index];
}

int Stack::count() const {
	return head;
}

void Stack::push(char value) {
	if(head == MAX_SIZE) { exit(1); }
	array[head] = value;
	head++;
}

char Stack::pop() {
	if(head == 0) { exit(1); }
	head--;
	return array[head];
}


void print_backwards(const char *text) { // *text is a pointer to the first character of the string
	cout<<*text<<endl; // prints the first character of the string (H)
	Stack s;

	while(*text) { // while the character is not null
		s.push(*(text++)); // push the character to the stack and increment the pointer becase elements of arrays are stored in contiguous memory locations
	}

	while(s.count() > 0) {
		cout << s.pop();
	}
	cout << endl;
}


int main() {

	print_backwards("Hello world!");

	return 0;
}
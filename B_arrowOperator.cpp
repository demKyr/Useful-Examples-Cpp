// Virtual functions ensure that the correct function is called for an object, 
// regardless of the type of reference (or pointer) used for the function call.

#include <iostream>

// using namespace std;

struct Node;
typedef Node *Node_ptr;

struct Node{
    // char word[50];
    std::string word;
    Node_ptr ptr_to_next_node;
};

int main(){

    Node_ptr my_node_ptr, another_node_ptr;
	my_node_ptr = new Node;
	another_node_ptr = new Node;
    my_node_ptr->word = "Hello";
    another_node_ptr->word = "World";

    // Accessing members of a struct using a pointer
    // Using the arrow operator (->)
    my_node_ptr->ptr_to_next_node = another_node_ptr;
    std::cout << "Address of my_node_ptr: " << my_node_ptr << std::endl;
    std::cout << "Address of another_node_ptr: " << another_node_ptr << std::endl;
    std::cout << "Address stored in my_node_ptr->ptr_to_next_node: " << my_node_ptr->ptr_to_next_node << std::endl;
    std::cout << "Word stored in my_node_ptr: " << my_node_ptr->word << std::endl;
    std::cout << "Word stored in my_node_ptr->ptr_to_next_node: " << my_node_ptr->ptr_to_next_node->word << std::endl;
    

    // Equivalent way using dereferencing and dot operator (.)
    (*my_node_ptr).ptr_to_next_node = another_node_ptr;
    std::cout << "Address of another_node_ptr: " << another_node_ptr << std::endl;
    std::cout << "Address stored in (*my_node_ptr).ptr_to_next_node: " << (*my_node_ptr).ptr_to_next_node << std::endl;
    std::cout << "Word stored in my_node_ptr: " << (*my_node_ptr).word << std::endl;
    std::cout << "Word stored in (*my_node_ptr).ptr_to_next_node: " << (*(*my_node_ptr).ptr_to_next_node).word << std::endl;

    delete my_node_ptr;
    delete another_node_ptr;
    
}
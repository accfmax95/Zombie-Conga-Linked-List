/*
  Author: Maxwell Berry
  Date: July 6, 2021
  Description: This is the header file. This file initializes all the templated linked list classes, their functions, and
               their variables. These classes are designed to store and manipulate the data used within the main class through self-designed linked list.
*/

#include <iostream>

using namespace std;

#ifndef berry_max_assn4_h
#define berry_max_assn4_h

// Instantiating the classes early
template <typename T> // Templating to allow dynamic data types
class LinkedList;
template <typename T>
class Node { // Node class that stores the index and data of each node

    friend class LinkedList<T>;
    private:
        // Member variables
        T data;
        Node* next;
    
    public:
        // Constructors
        Node();
        Node(T data);

        // Destructor
        ~Node();

        // Setters
        void setNext(Node* next);
        void setData(T data);

        // Getters
        Node* getNext();
        T getData();
    
};

template <typename T>
class LinkedList { // Linked list class that completes all the necessary functions to manipulate the data and nodes within the linked list

    private:
        // Member variables
        Node<T>* head;
    
    public:
        // Constructors
        LinkedList();
        LinkedList(Node<T> head);

        // Destructor
        ~LinkedList();

        // Add Functions
        void AddToFront(T data);
        void AddToEnd(T data);
        bool AddAtIndex(T data, int index);

        // Remove Functions
        T RemoveFromFront();
        T RemoveFromEnd();
        void RemoveTheFirst(T data);
        void RemoveAllOf(T data);
        
        // Finder Functions
        bool ElementExists(T data);
        Node<T>* Find(T data);
        int IndexOf(T data);
        T RetrieveFront();
        T RetrieveEnd();
        T Retrieve(int index);

        // Misc. 
        void PrintList();
        void Empty();
        int Length();

};    

/* --------------------------- Node Class ------------------------------------ */

template <typename T>
Node<T>::Node() { // Constructor

    data = 0;
    next = 0;
}

template <typename T>
Node<T>::Node(T data) { // Constructor

    this -> data = data;
}

template <typename T>
Node<T>::~Node() { // Destructor

   
}

template <typename T>
void Node<T>::setNext(Node* next) { // Setter method

    this -> next = next;
}
        
template <typename T> 
void Node<T>::setData(T data) { // Setter method

    this -> data = data;
}

template <typename T>
Node<T>* Node<T>::getNext() { // Getter method

    return next;
}

template <typename T>
T Node<T>::getData() { // Getter method

    return data;
}

/* --------------------------- Linked List Class ------------------------------------ */

template <typename T>
LinkedList<T>::LinkedList() { // Constructor

    head = 0;
}

template <typename T> 
LinkedList<T>::LinkedList(Node<T> head) { // Constructor
 
    this -> head = head;
}

template <typename T>  
LinkedList<T>::~LinkedList() { // Destructor

    Node<T>* currNode = head;
    Node<T>* nextNode = 0;

    while (currNode != 0) {

        nextNode = currNode -> next;

        free(currNode);
        currNode = nextNode;
    }

    head = 0;
}

template <typename T>
void LinkedList<T>::AddToFront(T data) { // Function that adds an element to the front of the linked list

    Node<T>* currNode = new Node<T>();
    currNode -> data = data; 
    currNode -> next = head;
    head = currNode;
    
}

template <typename T>
void LinkedList<T>::AddToEnd(T data) { // Functions that adds an element to the end of the linked list

    Node<T>* currNode = new Node<T>(data);
    currNode -> data = data; 
    currNode -> next = 0;
    if (head == 0) { // If the head node is empty

        head = currNode;
        return;
    } else {

        Node<T>* currNode2 = head;
        while ((currNode2 -> next) != 0) { // While the next node is not empty

            currNode2 = currNode2 -> next; // Links to the next node
        }

        currNode2 -> next = currNode;
    }
}

template <typename T>
bool LinkedList<T>::AddAtIndex(T data, int index) { // Function to add an element to a specific index of the linked list

    Node<T>* prevNode = new Node<T>();
    Node<T>* currNode = new Node<T>();
    Node<T>* newNode = new Node<T>();
    newNode -> data = data;

    int tempIndex = 0;   // Traverses through the list

    currNode = head;  
    if (head != 0) { // If the head is not empty
        
        while (currNode -> next != 0 && tempIndex != index) { // While the next node contains data
           
            prevNode = currNode;
            currNode = currNode -> next;
            tempIndex++;
        }
        
        if (index == 0) {
            
            AddToFront(data);  // Call function to addNode from head;
            return true;
        } else if (currNode -> next == 0 && index == tempIndex+1) {
            
            AddToEnd(data); // Call function to addNode at head;
            return true;
        } else if (index > tempIndex + 1) {
            
            return false; //indexition not valid
        } else if (index < 0 || index > Length()) {
            
            return false; //indexition not valid
        } else {
            
            prevNode -> next = newNode;
            newNode -> next = currNode;
            return true;
        }
    } else { // If the linked list is currently empty
        
        head = newNode;
        newNode -> next = 0;
        return true;
    }
}

template <typename T>    
T LinkedList<T>::RemoveFromFront() { // Removes the data within the head of the linked list

    Node<T>* currNode = head;

    if (head == 0) { // If the head is empty
        
        return 0;
    } 

    head = head -> next;

    if ((head -> next) == 0) {

        Empty();
    }
    
    currNode -> data = 0;
    return currNode -> data;
}

template <typename T>
T  LinkedList<T>::RemoveFromEnd() { // Removes the data within the tail of the linked list

    Node<T>* currNode = head;

    while ((currNode -> next -> next) != 0) { // Go through the linked list
    
            currNode = currNode -> next;
    }
 
    T tempInfo = currNode -> data; // Set the data to a new variable
    currNode -> next = 0;
    return tempInfo;
}

template <typename T>
void LinkedList<T>::RemoveTheFirst(T data) { // Removes the first instance of an element within the linked list

    Node<T>* currNode = head;
    bool prompt = false;
     
    if (head -> data == data) { // If the first node contains the data
        
        head = head -> next;
    }
    while (currNode -> next != 0 && prompt == false) { // Loops through the linked list
        
        if (currNode -> next -> data == data) { // Prompt boolean ensures only the first value is deleted, rather than all the values
            
            currNode -> next = currNode -> next -> next;
            prompt = true;
        } else {
            
            currNode = currNode -> next;
        }
    }
}

template <typename T>
void LinkedList<T>::RemoveAllOf(T data) { // Removes all instances of an element within the linked list

    Node<T>* currNode = head;
     
    while (head -> data == data) { // While the first node contains the data
        
        head = head -> next;
    }
    while (currNode -> next != 0) { // Loops through the linked list
        
        if (currNode -> next -> data == data) {
            
            currNode -> next = currNode -> next -> next; // Deletes the value 
        } else {
            
            currNode = currNode -> next;
        }
    }
}

template <typename T>           
bool LinkedList<T>::ElementExists(T data) { // Boolean function to check if an element exists within the linked list

    Node<T>* currNode = head;

    while (currNode != 0) {

        if (currNode -> data == data) {

            return true;
        } 
        
        currNode = currNode -> next;
    }

    return false;
}

template <typename T>
Node<T>* LinkedList<T>::Find(T data) { // Returns the address of an element within the linked list

    Node<T>* currNode = head;

    while (currNode != 0) { // While the current node is not 0

        if (currNode -> data == data) {

            return currNode;
        }

        currNode = currNode -> next;
    }

    return 0;
}

template <typename T>
int LinkedList<T>::IndexOf(T data) { // Returns the index of an element within the linked list

    Node<T>* currNode = head;
    int index = 0;

    while (currNode != 0) { // While the current node is not 0

        if (currNode -> data == data) {

            return index;
        }

        currNode = currNode -> next;
        index++; // Increases index value to return proper value
    }

    return -1;
}

template <typename T>
T LinkedList<T>::RetrieveFront() { // Returns the head of the linked list

    return head -> data;
}

template <typename T>
T LinkedList<T>::RetrieveEnd() { // Returns the tail of the linked list

    Node<T>* currNode = head;
    if (currNode -> next == 0) { // If this node is the last in the list
  
        T temp = currNode -> data;
        return temp;

    } else {

        while (currNode -> next != 0) { // Loops through the list until it finds the last 
        
            currNode = currNode -> next;

            if (currNode -> next == 0) {
  
                T temp = currNode -> data;
                return temp;
            }
        }
    }

    return 0;
}

template <typename T>
T LinkedList<T>::Retrieve(int index) { // Function to retrieve the element at a specific index

    Node<T>* currNode = head;

    int count = 0;
    while (currNode != 0) { // While the current node does not equal 0
        
        if (count == index) {
            
            return currNode -> data;
        }
        
        currNode = currNode -> next;
        count++; // Increases until the desired index is reached
    }

        return 0;
}   

template <typename T>      
void LinkedList<T>::PrintList() { // Function to print the entire list

    Node<T>* currNode = head;
    
    while (currNode != 0) { // Loops through the linked list
        
        cout << currNode -> data << " ";
        currNode = currNode -> next;
    }
}

template <typename T>
void LinkedList<T>::Empty() { // Function to empty the entire linked list

    Node<T>* currNode = head;
 
    while (currNode != 0) { // Loops through each node of the list
        
        free(currNode);
        currNode = currNode -> next;
    }
 
    head = 0;
}

template <typename T>
int LinkedList<T>::Length() { // Function to return the length of the entire linked list


    int count = 0; 
    Node<T>* currNode = head; 
    
    while (currNode != 0) {  // Loops through each node of the list
        
        count++; // Increases to return the length
        currNode = currNode -> next;
    }
    
    return count;
}

#endif
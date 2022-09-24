//CS311 Yoshii S22 llist.h
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Kyrstn Hall
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

#include "elem.h"

// alias el_t : element type definition
//typedef char el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  // returns true if linked list is empty
  // otherwise, it returns false
  bool isEmpty();
    
  // displays each element stored in node starting from the front
  void displayAll();

  // adds node at the front of the list
  void addFront(el_t);
    
  // adds node to the rear of the list
  void addRear(el_t);

  // deletes node at the front of the list
  void deleteFront(el_t&);
  
  //---------------------------------------
    
  // deletes node at the rear of the list
  void deleteRear(el_t&);
    
  // Will delete Ith element in the list
  void deleteIth(int, el_t&);  // calls moveTo

  // Will insert node at Ith spot of the list
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};

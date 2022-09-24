//CS311 Yoshii S22 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Kyrstn Hall
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ 
  //cout << "... in llist constructor..." << endl; 
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

llist::~llist()
{ 
  //cout << ".... in llist destructor..." << endl; 
  el_t x; // to store removed element
  while(!isEmpty())
    {
      deleteFront(x);
    }
}

//PURPOSE: Returns true if Front AND Rear are both pointing to NULL AND Count is 0
//         Otherwise returns false
//PARAMETER: None
bool llist::isEmpty()  // be sure to check all 3 data members
{
  if(Front==NULL && Rear==NULL && Count==0)
    return true;
  else
    return false;
}

//PURPOSE: Display each element of the list starting from Front
//         If list is empty, displays [ empty ]
//PARAMETER: None
void llist::displayAll() // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
{
  if(isEmpty()) // special case - list is empty
    cout << "[ empty ]" << endl;
  else
    {
      Node *P = Front; // P will be used to go through each node
      cout << "[ ";
      while(P != NULL)
	{
	  cout << P->Elem << " ";
	  P = P->Next;
	}
      cout << "]" << endl;
    }
}
  
//PURPOSE: Adds a new node at the rear and updates Count
//PARAMETER: NewNum is some val to be stored in rear element to be added
void llist::addRear(el_t NewNum) // comment the 2 cases
{
  if(isEmpty()) // special case - will be very first node 
    {
      Front = Rear = new Node;
      Front->Elem = NewNum;
      Rear->Next = NULL;
    }
  else // regular case
    {
      Rear->Next = new Node;
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
    }
  Count++;
}

//PURPOSE: Adds a new node at the front and update Count
//PARAMETER: NewNum is some val to be stored in front element to be added
void llist::addFront(el_t NewNum) // comment the 2 cases
{
  if(isEmpty()) // special case - will be very first node
    {
      Front = Rear = new Node;
      Front->Elem = NewNum;
      Rear->Next = NULL;
    }
  else // regular case
    {
      Node *P = new Node;
      P->Next = Front;
      Front = P;
      Front->Elem = NewNum;
    }
  Count++;
}


//PURPOSE: If not empty, it will give back the front node element through OldNum and remove the front node. Count is updated.
//         Otherwise, if its empty, it will throw an exception. 
//PARAMETER: OldNum (passed by ref) will be element that will be deleted from list 
void llist::deleteFront(el_t& OldNum)  // comment the 3 cases
{
  if(isEmpty()) // error case
    {
      throw Underflow();
    }
  else if(Count==1) // special case - will make list empty
    {
      OldNum = Front->Elem;
      delete Front;
      Front = Rear = NULL;
      Count--;
    }
  else // regular case 
    {
      Node *P = Front->Next; // P will be pointing at the new front, or 2nd from first node
      OldNum = Front->Elem;
      delete Front;
      Front = P;
      Count--;
    }
}


//PURPOSE: If not empty, it will give back the rear node element through OldNum and remove the rear node. Count is updated.
//         Otherwise if its empty, it will throw an exception.
//PARAMETER: OldNum (passed by ref) will be element that will be deleted from list
void llist::deleteRear(el_t& OldNum) // comment the 3 cases
{
  if(isEmpty()) // error case                                                                                                                         
    {
      throw Underflow();
    }
  else if(Count==1) // special case - will make list empty                                                                                            
    {
      OldNum = Front->Elem;
      delete Front;
      Front = Rear = NULL;
      Count--;
    }
  else // regular case                                                                                                                                
    {
      Node *P = Front; // P will be pointing at the new rear, or 2nd to last node
      while(P->Next != Rear)
	{		 
	  P = P->Next;
	}
      OldNum = Rear->Elem;
      delete Rear;
      Rear = P;
      Rear->Next = NULL;
      Count--;
   }
}

/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node  
  // for ( int K = ... ) temp = temp->Next;
  temp = Front;
  for(int K=1; K<=J-1; K++)
    {
      temp = temp->Next;
    }
}


//PURPOSE: To delete Ith (I) node 
//PARAMETER: I is Ith node to delete, OldNum (pass by ref) is elem stored in node to be deleted
void llist::deleteIth(int I, el_t& OldNum) // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  
{
  if( I>Count || I<1) // error case 
    {
      throw OutOfRange();
    }
  else if(I == 1) // special case - node to delete is 1st node
    {
      deleteFront(OldNum);
    }
  else if(I == Count) // special case - node to delete is last node
    {
      deleteRear(OldNum);
    }
  else // regular case
    {
      Node *before = Front; // will point before node to be deleted (I-1)
      moveTo(I-1, before);
      Node* after = Front; // will point after node to be deleted (I+1)
      moveTo(I+1, after);
      
      OldNum = before->Next->Elem; // OldNum will get node to be deleted
      before->Next->Next = NULL; // Ith node's next not pointing to anything
      delete before->Next; // Ith node deleted
      before->Next = after; // before's next is updated 
      Count--;
    }
}

//PURPOSE: To insert Ith (I) node
//PARAMETER: I is Ith node to insert, newNum is elem stored in node to be added
void llist::insertIth(int I, el_t newNum)  // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.
{
  if( I>Count+1 || I<1) // error case                                                                                                                                                     
    {
      throw OutOfRange();
    }
  else if(I == 1) // special case - node to insert is the front
    {
      addFront(newNum);
    }
  else if(I == Count+1) // special case - node to insert is the rear                                                                                                                      
    {
      addRear(newNum);
    }
  else // regular case                                                                                                                                                                 
    {
      Node *before = Front; // node will point before node to be added
      moveTo(I-1, before);
      Node *after = Front; // node after before (before adding) , but will be new node's next after adding
      moveTo(I, after);

      Node *toInsert = new Node; // new node to be inserted
      toInsert->Elem = newNum; // value stored in Elem of Node
      before->Next = toInsert; // before's next will now point to the new node
      toInsert->Next = after; // new node's next is updated
      Count++;
    }
}

//PURPOSE: copy constructor to allow passing of a list by value and returning of a list by value
//PARAMETER:
llist::llist(const llist& Original)  // use my code
{
  //  this->'s data members need to be initialized here first
  this->Front = NULL; 
  this->Rear = NULL; 
  this->Count = 0;
  //  this-> object has to be built up by allocating new cells
  //  and copying the values from Original into each cell as we did with 
  //  operator= above. To do this,
  //copy here the (**) lines in Operator Overloading of = but note that it is Original and not OtherOne.
      Node* P; // local pointer for Original                                                                                                             
      P = Original.Front;
      while(P!=NULL)
	{
	  this->addRear(P->Elem);
	  P = P->Next;
	}// end of while

  //  Nothing to return because this is a constructor.
}

//PURPOSE: to allow client to use = for linked list objects with pointers - allow L1 = L2 in the client
//PARAMETER: 
llist& llist::operator=(const llist& OtherOne)  // use my code
{
  el_t x;
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	this->deleteRear(x);  
      // this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P’s element is added to this->
	  P = P->Next;                         // Go to the next node in OtherOne   
	} 
    }// end of if              
  return *this;    // return the result unconditionally.  Note that the result is returned by reference.
}


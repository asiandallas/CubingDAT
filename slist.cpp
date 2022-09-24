// CS311 Yoshii S22 slist.cpp
// Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Kyrstn Hall
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{ 
  //cout << "slist constructor: " << endl;
}

// positions always start at 1
int slist::search(el_t key)
{
  Node *P = Front;
  int pos = 1;
  
  while(P != NULL)
    {
      if(P->Elem == key)
	{
	  return pos;
	} // end of if
      P = P->Next;
      pos++;
    } // end of while
  return -1;
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
void slist::replace(el_t element, int pos)
{
  if(pos>Count || pos<1) // error case - out of range
    {
      throw OutOfRange();
    }
  else // regular case
    {
      Node *P = Front; // P will start at front, will move until it reaches pos
      moveTo(pos, P);
      P->Elem = element;
    }
}

bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false immediately
  // if the same lengths,                                                                                                                                                                                
  // check each node to see if the elements are the same
  if(this->Count != OtherOne.Count)
    return false;
  else
    {
      // P1 and P2 will go through each node and check if their Elem are the same
      Node *P1 = this->Front; 
      Node *P2 = OtherOne.Front;
      
      while(P1 != NULL && P2 != NULL)
	{
	  if(P1->Elem != P2->Elem) 
	    return false;

	  P1 = P1->Next;
	  P2 = P2->Next;
	}// end of while
      return true;
    }// end of else
}

el_t slist:: search2(el_t X)
{
  el_t M; // blank
  // X has only the ID part set
  // In the slist look for matching el_t in Elem (the same code as search)
  // Return the el_t obj or if not found
  // return a blank object M

  Node *P = Front;

  while(P != NULL)
    {
      if(P->Elem == X)
        {
          return P->Elem;
        }                                                                                                                     
      P = P->Next;
    } // end of while                                                                                                                     
  return M;
}

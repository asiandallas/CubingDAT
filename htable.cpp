// CS311 Yoshii S22 - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//  NEVER delete my comments!!
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Kyrstn Hall
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"
#include "elem.h"

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(string key)
{ 
  int sum = 0;
  for(int i=0; i<key.size(); i++)
    {
      sum += key[i];
    }
  return sum % TSIZE;
}

// adds the element to the table and returns slot#
int htable::add(el_t element)
{
  int slot = hash(element.getkey());  // hash with the key part
  table[slot].addRear(element);// Note that this means adding the element to a slist in the slot (call addRear)
  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(string skey)
{ 
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 el_t el;

 selement.setkey(skey); // initialize selement with just the skey (call setkey)
 el = table[slot].search2(selement); // call slist's search2 with selement which returns the found element 
 return el; // return the found element from here (it could be blank)
}

// finds the element given the key  and deletes it from the table.
//  Returns the slot number.
int htable::deleteIt(string key)
{
 int slot = hash(key); // hash with skey
 el_t selement;  // this is the element to look for in slist
 int I; // has location

 selement.setkey(key); //  initialize selement with just the skey
 I = table[slot].search(selement); //  call slist's search which gives you the location I and then deleteIth
 if(I != -1)
   {
     table[slot].deleteIth(I, selement);
     return slot;
   }
 else
   return -1; 
 //return slot; //  return the slot number
}

// fills the table using the specified input file 
void htable::fillTable(istream& fin)
{ 
  string akey; // key
  string name; // name of customer
  string event; // name of event
  double time; // time
  string fname; // name of file
  el_t theelement; // will add to  LL
  //  model this after HW6 to get data from the file the user specified
  //  which elem and slist functions do you call? List them here first.
  
  //cout << "Enter a file name: ";
  //cin >> fname;
  //fin(fname.c_str(), ios::in); // declare and open fname
  
  while (fin >> akey)
    { 
    // fin other parts and create an element
    // YOu can call the add function to add the created element to the table
    fin >> name;
    fin >> event;
    fin >> time;
    theelement = el_t(akey, name, event, time);   
    int slot = add(theelement);  
    // cout << "Added the element in slot " << slot << endl;
  }
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < 37; i++)
    { 
      cout << i << ":" ;   
      table[i].displayAll(); // call slist's displayAll
    }
}


// saves into the specified file in the same format as the input file
void htable::saveTable(ostream& fout) 
{
  // for each non-empty slot of the table, retrieve the slist to a local variable
  // and fout each removed element.
  el_t e;

  for (int i = 0; i < 37; i++)
    { 
      if(!table[i].isEmpty())
	{
	  while(!table[i].isEmpty())
	    {
	      table[i].deleteFront(e);
	      fout << e << endl;
	    }
	}
    }
}

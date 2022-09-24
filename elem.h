// CS311 Yoshii S22 - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// I use IFNDEF in case this file gets included more than once
// Update based on **
// ---------------------------------------------------------

#ifndef ELEM_H
#define ELEM_H

#include <iostream>
#include <string>
using namespace std;

class el_t
{
 private:  // these will change depending
           // on the client needs
  string key;      // key
 public:
  string name;  // customer name
  //** add 2 more pieces of info here
  string main_event; 
  double fast_time;
 public:

  el_t();  // to create a blank el_t object
  el_t(string, string, string, double); // to create an initialized el_t object - useful for the client   ** add more arguments to create the object

 // The following functions are available to
 // the htable class to be able to
 // use different el_t without modifying the code

  string getkey(); // only the key part can be accessed by the user of this class.

  void setkey(string); // only the key part can be accessed by the user of this class.


  // In linked list search,
  //    == is used to compare node elements
  // but what does it mean for this client to compare
  // node elements?  
  bool operator==(el_t);  // overload == for search
  bool operator!=(el_t);  // overload != for search

  // This overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  friend ostream& operator<<(ostream&, const el_t&);

  friend class htable;
};

#endif
  



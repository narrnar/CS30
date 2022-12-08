//Daren Sathasivam
//CS30, 0171,
//Homework #1
//Utilize LinkedList class and implement several different functions. The program should consist of functions that print, insert, extract, swap, and reverse a LinkedList. Output should match that of the one provided in the prompt.
#include <iostream>
#include <string>
#include <cassert>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList ls;
    ls.insertToFront("Hawkeye");
    ls.insertToFront("Thor");
    ls.insertToFront("Hulk");
    ls.insertToFront("Black Widow");
    ls.insertToFront("Iron Man");
    ls.insertToFront("Captain America");
     
    for (int k = 0; k < ls.size(); k++)
    {
        string x;
       ls.get(k, x);
       cout << x << endl;
    }
    
    LinkedList ls1;
    ls1.insertToFront("The Mandalorian");
    ls1.insertToFront("Baby Yoda");
    ls1.insertToFront("Cara Dune");
    ls1.insertToFront("Greef Karga");
     
    ls1.printList();
    ls1.printReverse();
    
    LinkedList e1;
    e1.insertToFront("Athos");
    e1.insertToFront("Porthos");
    e1.insertToFront("Aramis");
    LinkedList e2;
    e2.insertToFront("Robin");
    e2.insertToFront("Batman");
    e1.append(e2);  // adds contents of e2 to the end of e1
    string s;
    assert(e1.size() == 5  &&  e1.get(3, s)  &&  s == "Batman");
    assert(e2.size() == 2  &&  e2.get(1, s)  &&  s == "Robin");
    
    LinkedList e3;
    e3.insertToFront("Jim");
    e3.insertToFront("Oz");
    e3.insertToFront("Paul");
    e3.insertToFront("Kevin");
    e3.reverseList();  // reverses the contents of e1
    string s2;
    assert(e3.size() == 4  &&  e3.get(0, s2)  &&  s2 == "Jim");
    
    LinkedList e4;
    e4.insertToFront("A");
    e4.insertToFront("B");
    e4.insertToFront("C");
    e4.insertToFront("D");
    LinkedList e5;
    e5.insertToFront("X");
    e5.insertToFront("Y");
    e5.insertToFront("Z");
    e4.swap(e5);  // exchange contents of e1 and e2
    string s3;
    assert(e4.size() == 3  &&  e4.get(0, s3)  &&  s3 == "Z");
    assert(e5.size() == 4  &&  e5.get(2, s3)  &&  s3 == "B");
}

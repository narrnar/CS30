//
//  LinkedList.cpp
//  CS30 HW#1
//
//  Created by Daren Sivam on 8/30/22.
//

#include "LinkedList.h"
#include <stack>
// default constructor
LinkedList::LinkedList()
{
    head = nullptr;
}
         
// copy constructor
LinkedList::LinkedList(const LinkedList& rhs)
{
    head = nullptr;                    //Initialize
    Node *node = rhs.head;              //point to head of rhs
    while (node != nullptr)             //loop until end of LinkedList
    {
        insertToFront(node->value);     //inserts elements to the front of LinkedList
        node = node->next;              //traverse through Linked List
    }
}
         
// Destroys all the dynamically allocated memory
// in the list.
LinkedList::~LinkedList()
{
    Node *node = head;              //initialize
    while (node != nullptr)         //loop until end of LinkedList
    {
        Node *temp = node->next;    //store next element under temp
        delete node;                //delete current element
        node = temp;                //temp to new node value to continue traversal through LinkedList
    }
}
         
// assignment operator
const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    LinkedList copy = LinkedList(rhs); //assigns copy to rhs LinkedList
    this->swap(copy);                   //swap heads of the LinkedLists
    return *this;
}
        
// Inserts val at the front of the list
void LinkedList::insertToFront(const ItemType &val)
{
    Node *node = new Node; //allocate new node
    node->value = val;      //initialize the value for the new node
    node->next = head;      //link new node to the old top node
    head = node;            //point head to the new top node
}
         
// Prints the LinkedList
void LinkedList::printList() const
{
    Node *node = head;
    if(head == nullptr)         //if empty list
    {
        std::cout << "Empty list!\n";
    }
    else
    {
       while(node != nullptr)
       {
           std::cout << node->value; //print out value from LinkedList
           node = node->next;        //traverse through LinkedList
       }
    }
}
         
// Sets item to the value at position i in this
// LinkedList and return true, returns false if
// there is no element i
bool LinkedList::get(int i, ItemType& item) const
{
    if(i >= 0 && i < size())    //if i is within the LinkedList
    {
        int j = 0;              //initializers
        Node *node = head;
        while(j < i)        //loop until ith node in LinkedList
        {
            node = node->next;      //traverse LinkedList
            j++;                //increment
        }
        item = node->value; //item found and set to value
        return true;
    }
    return false;   //no valid value in ith position in the LinkedList
}
       
// Reverses the LinkedList
void LinkedList::reverseList()
{
    if(head == nullptr || head->next == nullptr)    //if empty or one item LinkedList
    {
        return;
    }
    Node *ogList = head->next;
    Node *revList = head;
    revList->next = nullptr;
    while(ogList != nullptr)  //loop until end of original LinkedList
    {
        Node *temp = ogList;        //go down original LinkedList
        ogList = ogList->next;
        temp->next = revList;       //set temp as head of the reversed LinkedList
        revList = temp;
    }
     head = revList;        //set head to value at revList
}
       
// Prints the LinkedList in reverse order
void LinkedList::printReverse() const
{
    /*
    LinkedList revList(*this);  //initialize LinkedList
    revList.reverseList();      //reverse LinkedList
    revList.printList();        //print out reversed LinkedList
     */
    this->revPrint(this->head); //call helper function
    std::cout << "\n";  
}
// Reverse Print Helper Function
void LinkedList::revPrint(Node *node) const
{
    if(node != nullptr)
    {
      revPrint(node->next); //recursive case
      std::cout << node->value; //print out value
    }
    return;
}
       
// Appends the values of other onto the end of this
// LinkedList.
void LinkedList::append(const LinkedList &other)    //maybe reverse list, addToFront, then reverse list again
{
    Node *node = other.head; //initialize node to "other" list's head
    while (node != nullptr)
    {
        insertToRear(node->value);
        node = node->next;      //traverse through "other" list
    }
}
//Inserts val at the end of the list
void LinkedList::insertToRear(const ItemType &val)
{
    Node *node;
    if(head == nullptr)  //add to front if list is empty
    {
        insertToFront(val);
    }
    else
    {
        node = head;                    //add to rear if not empty
        while(node->next != nullptr)
            node = node->next;
            Node *current = new Node;
            current->value = val;
            node->next = current;       //node points at the last node once it hits the line
            current->next = nullptr;    //after the last node stored in the list
    }
}
       
// Exchange the contents of this LinkedList with the other
// one.
void LinkedList::swap(LinkedList &other)
{
    std::swap(head, other.head); //referenced from GeeksforGeeks
}
       
// Returns the number of items in the Linked List.
int LinkedList::size() const
{
    if(head == nullptr) //size zero if nothing is in LinkedList
    {
        return 0;
    }
    Node *node = head;  //initializers
    int count = 0;
    while (node != nullptr) //loop until end of LinkedList
    {
        count ++;           //increment count
        node = node->next;  //traverse through LinkedList
    }
    return count;           //return size as int
}

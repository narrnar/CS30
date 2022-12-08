//Daren Sathasivam
//CS30, 0171
//Project #1
//Create a program that assists in wedding planning utilzing a doubly linked list that organizes the guests in alphabetical order based off of their last name then first name.

#include "WeddingGuest.h"
#include <stack>
//default constructor
WeddingGuest::WeddingGuest()
{
    head = nullptr;
    tail = nullptr;
}
//copy constructor
WeddingGuest::WeddingGuest(const WeddingGuest& wgList)
{
    head = tail = nullptr;
    
    Guest* headCopy = head;
    Guest* otherHead = wgList.head;
    
    while (otherHead != nullptr)
    {
        if(headCopy == nullptr)
        {
            headCopy = new Guest;
            headCopy->firstName = otherHead->firstName;
            headCopy->lastName = otherHead->lastName;
            otherHead = otherHead->next;
        }
        else
        {
            headCopy->next = new Guest;
            headCopy->next->firstName = otherHead->firstName;
            headCopy->next->lastName = otherHead->lastName;
            headCopy->next->prev = headCopy;
            headCopy = headCopy->next;
        }
        otherHead = otherHead->next;
    }
    tail = headCopy;
}
//destructor
WeddingGuest::~WeddingGuest()
{
    Guest *node = head;              //initialize
    while (node != nullptr)         //loop until end of LinkedList
    {
        Guest *temp = node->next;    //store next element under temp
        delete node;                //delete current element
        node = temp;                //temp to new node value to continue traversal through wgList
    }
}
//assignment operator
const WeddingGuest& WeddingGuest::operator=(const WeddingGuest& wgList)
{
    if(this == &wgList)
    {
        return *this;
    }
    WeddingGuest copy = WeddingGuest(wgList); //assigns copy to right-hand list
    this->swap(copy);                   //swap heads of the lists
    return *this;
}
void WeddingGuest::swap(WeddingGuest &wgList)
{
    std::swap(head, wgList.head);
}


bool WeddingGuest::noGuests() const
{
    return head == nullptr;
}

int WeddingGuest::guestCount() const
{
    Guest* node = head;
    int gCount = 0;
    while(node != nullptr)
    {
        gCount++;
        node = node->next;
    }
    return gCount;
}

bool WeddingGuest::inviteGuest(const std::string &firstName, const std::string &lastName, const GuestType &value)
{
    Guest *wgList= head;
    if(lastName < wgList->lastName || (lastName == wgList->lastName && firstName < wgList->firstName))
    {
        Guest *current = new Guest;
        current->next = head;
        head->prev = current;
        head = current;
        current->lastName = lastName;
        current->firstName = firstName;
        current->value = value;
        return true;
    }
    while(wgList != nullptr)
    {
        if(lastName == wgList->lastName && firstName == wgList->firstName)
        {
            return false;
        }
        if(wgList->lastName == lastName)
        {
            if(wgList->firstName > firstName)
            {
                Guest *current = new Guest;
                current->lastName = lastName;
                current->firstName = firstName;
                current->value = value;
                wgList->prev->next = current;
                current->prev = wgList->prev;
                current->next = wgList;
                wgList->prev = wgList;
                return true;
            }
            continue;
        }
        if(wgList->lastName > lastName)
        {
            //insert
            Guest *current = new Guest;
            current->lastName = lastName;
            current->firstName = firstName;
            current->value = value;
            wgList->prev->next = current;
            current->prev = wgList->prev;
            current->next = wgList;
            wgList->prev = wgList; //if prev is nullptr ->error -->create new Head so it isnt nullptr
            return true;
        }
        wgList = wgList->next;
    }
    Guest *current = new Guest;
    tail->next = current;
    current->lastName = lastName;
    current->firstName = firstName;
    current->value = value;
    current->prev = tail;
    tail = current;
    return true;
}

bool WeddingGuest::alterGuest(const std::string &firstName, const std::string &lastName, const GuestType &value)
{
    Guest *wgList = head;
    while(wgList != nullptr)
    {
        if(wgList->lastName == lastName && wgList->firstName == firstName)
        {
            wgList->value = value;
            return true;
        }
        wgList = wgList->next;
    }
    return false;
}

bool WeddingGuest::inviteOrAlter(const std::string &firstName, const std::string &lastName, const GuestType &value)
{
    return inviteGuest(firstName,lastName, value) || alterGuest(firstName, lastName, value);
}

bool WeddingGuest::crossGuestOff(const std::string &firstName, const std::string &lastName)
{
    Guest *wgList = head;
    while(wgList != nullptr)
    {
        if(wgList->lastName == lastName && wgList->firstName == firstName)
        {
            //remove name from list
            wgList->next->prev = wgList->prev;
            wgList->prev->next = wgList->next;
            delete wgList;
            return true;
        }
        wgList = wgList->next;
    }
    return false;
}

bool WeddingGuest::invitedToTheWedding(const std::string& firstName, const
std::string& lastName) const
{
    Guest *wgList = head;
    while(wgList != nullptr)
    {
        if(wgList->lastName == lastName && wgList->firstName == firstName)
        {
            return true;    //name is already in list
        }
        wgList = wgList->next;
    }
    return false;
}

bool WeddingGuest::matchInvitedGuest(const std::string& firstName, const
std::string& lastName, GuestType& value) const
{
    Guest *wgList = head;
    while(wgList != nullptr)
    {
        if(wgList->lastName == lastName && wgList->firstName == firstName)
        {
            value = wgList->value;
            return true;
        }
        wgList = wgList->next;
    }
    return false;
}

bool WeddingGuest::verifyGuestOnTheList(int i, std::string& firstName,
std::string& lastName, GuestType & value) const
{
    Guest *wgList = head;
    int count = 0;
    while(wgList != nullptr)
    {
        if(count == i)
        {
            lastName = wgList->lastName;
            firstName = wgList->firstName;
            value = wgList->value;
            return true;
        }
        count++;
        wgList = wgList->next;
    }
    return false;
}

void WeddingGuest::swapWeddingGuests(WeddingGuest& other)
{
    std::swap(head, other.head);
}

bool joinGuests(const WeddingGuest & odOne,
                const WeddingGuest & odTwo,
                WeddingGuest & odJoined)
{
    int i = 0;
    std::string firstName, lastName;
    GuestType value;
    bool result = true;
    while(odOne.verifyGuestOnTheList(i, firstName, lastName, value))
    {
        i++;
        GuestType value2;
        if(odJoined.matchInvitedGuest(firstName,  lastName, value2))
        {
            if(value == value2)
            {
                continue;
            }
            result = false;
            odJoined.crossGuestOff(firstName, lastName);
            continue;
        }
        odJoined.inviteGuest(firstName, lastName,   value);
    }
    i = 0;
    while(odTwo.verifyGuestOnTheList(i, firstName, lastName, value))
    {
        i++;
        GuestType value2;
        if(odJoined.matchInvitedGuest(firstName,  lastName, value2))
        {
            if(value == value2)
            {
                continue;
            }
            result = false;
            odJoined.crossGuestOff(firstName, lastName);
            continue;
        }
        odJoined.inviteGuest(firstName, lastName,   value);
    }
    return result;
}

void attestGuests (const std::string& fsearch,
                   const std::string& lsearch,
                   const WeddingGuest& odOne,
                   WeddingGuest& odResult)
{
    int i = 0;
    std::string  firstName, lastName;
    GuestType value;
    while(odOne.verifyGuestOnTheList(i, firstName, lastName, value))
    {
        i++;
        if((fsearch == "*" || fsearch == firstName) && (lsearch == "*" || lsearch == lastName))
        {
            odResult.inviteGuest(firstName, lastName, value);
        }
    }
}



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
WeddingGuest::WeddingGuest(const WeddingGuest& wgList) : WeddingGuest()
{
    if (wgList.noGuests())
        return;

    head = new Guest; // initializing head with a new node
    // putting values at head from the first node of received list
    head->firstName = wgList.head->firstName;
    head->lastName = wgList.head->lastName;
    head->value = wgList.head->value;
    head->prev = nullptr;
    Guest* headCopy = head, *otherHead = wgList.head->next;
    // continue making copies of nodes until the NULL (last node) is reached
    while (otherHead != nullptr)
    {
        headCopy->next = new Guest;
        headCopy->next->firstName = otherHead->firstName;
        headCopy->next->lastName = otherHead->lastName;
        headCopy->next->value = otherHead->value;
        headCopy->next->prev = headCopy;
        headCopy = headCopy->next;
        otherHead = otherHead->next;
    }
    headCopy->next = nullptr;
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
    WeddingGuest copy(wgList); //assigns copy to right-hand list
    this->swap(copy); //swap heads of the lists
    return *this;
}
void WeddingGuest::swap(WeddingGuest &wgList)
{
    std::swap(head, wgList.head);
}

// return true if list is empty
bool WeddingGuest::noGuests() const
{
    return head == nullptr;
}

// returns total number of nodes in the list
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
    if (head == nullptr)
    {
        head = new Guest;
        head->firstName = firstName;
        head->lastName = lastName;
        head->prev = nullptr;
        head->next = nullptr;
        head->value = value;
        tail = head;
        return true;
    }

    Guest* wgList = head;
    while (wgList != nullptr)
    {
        if (wgList->firstName == firstName && wgList->lastName == lastName)
            return false;
        wgList = wgList->next;
    }
    wgList = head;
    while (wgList != nullptr && wgList->lastName < lastName)
        wgList = wgList->next;

    if (wgList == nullptr)
    {
        tail->next = new Guest;
        tail->next->firstName = firstName;
        tail->next->lastName = lastName;
        tail->next->value = value;
        tail->next->prev = tail;
        tail = tail->next;
        tail->next = nullptr;
    }
    else if (wgList->lastName > lastName)
    {
        wgList = wgList->prev;
        if (wgList == nullptr)
        {
            Guest* current = head;
            head = new Guest;
            head->firstName = firstName;
            head->lastName = lastName;
            head->prev = nullptr;
            head->value = value;
            head->next = current;
            current->prev = head;
        }
        else
        {
            Guest* current = wgList->next;
            wgList->next = new Guest;
            wgList->next->firstName = firstName;
            wgList->next->lastName = lastName;
            wgList->next->value = value;
            wgList->next->prev = wgList;
            wgList->next->next = current;
            current->prev = wgList->next;
        }
    }
    else
    {
        while (wgList != nullptr && wgList->firstName < firstName)
            wgList = wgList->next;
        if (wgList == nullptr)
        {
            tail->next = new Guest;
            tail->next->firstName = firstName;
            tail->next->lastName = lastName;
            tail->next->value = value;
            tail->next->prev = tail;
            tail = tail->next;
            tail->next = nullptr;
        }
        else
        {
            wgList = wgList->prev;
            if (wgList == nullptr)
            {
                Guest* current = head;
                head = new Guest;
                head->firstName = firstName;
                head->lastName = lastName;
                head->prev = nullptr;
                head->value = value;
                head->next = current;
                current->prev = head;
            }
            else
            {
                Guest* current = wgList->next;
                wgList->next = new Guest;
                wgList->next->firstName = firstName;
                wgList->next->lastName = lastName;
                wgList->next->value = value;
                wgList->next->prev = wgList;
                wgList->next->next = current;
                current->prev = wgList->next;
            }
        }
    }
    //std::cout << "End" << std::endl;
    return true;
}

bool WeddingGuest::alterGuest(const std::string &firstName, const std::string &lastName, const GuestType &value)
{
    Guest* wgList = head;
    while (wgList != nullptr)
    {
        if (wgList->firstName == firstName && wgList->lastName == lastName)
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
    if (head == nullptr)
        return false;
    if (head->firstName == firstName && head->lastName == lastName)
    {
        Guest* current = head->next;
        delete head;
        head = current;
        if(head != nullptr)
        {
            head->prev = nullptr;
        }
        return true;
    }

    Guest* wgList = head;
    while (wgList != nullptr)
    {
        if (wgList->firstName == firstName && wgList->lastName == lastName)
        {
            Guest* current = wgList->prev;
            current->next = wgList->next;
            if(wgList->next)
                wgList->next->prev = current;
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

// swap both lists
void WeddingGuest::swapWeddingGuests(WeddingGuest& other)
{
    WeddingGuest temp = *this;
    *this = other;
    other = temp;
}

bool joinGuests(const WeddingGuest & odOne,
                const WeddingGuest & odTwo,
                WeddingGuest & odJoined)
{
    bool result = true;
    WeddingGuest tempList(odOne);

    int countTwo = odTwo.guestCount();
    for (int i = 0; i < countTwo; i++)
    {
        std::string firstName, lastName;
        GuestType value;
        odTwo.verifyGuestOnTheList(i, firstName, lastName, value);
        GuestType value2;
        if (tempList.matchInvitedGuest(firstName, lastName, value2))
        {
            if (value != value2)
            {
                result = false;
                tempList.crossGuestOff(firstName, lastName);
            }
        }
        else
        {
            tempList.inviteGuest(firstName, lastName, value);
        }
    }

    odJoined = tempList;
    return result;
}

void attestGuests (const std::string& fsearch,
                   const std::string& lsearch,
                   const WeddingGuest& odOne,
                   WeddingGuest& odResult)
{
    WeddingGuest tempList;
    int count = odOne.guestCount();
    for (int i = 0; i < count; i++) 
    {
        std::string firstName, lastName;
        GuestType value;
        odOne.verifyGuestOnTheList(i, firstName, lastName, value);
        if ((fsearch == "*" || fsearch == firstName) && (lsearch == "*" || lsearch == lastName))
        {
            tempList.inviteGuest(firstName, lastName, value);
        }
    }
    odResult = tempList;
}

void WeddingGuest::dump() const
{
    std::cerr << "Error\n";
}

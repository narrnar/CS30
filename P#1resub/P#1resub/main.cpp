//
//  main.cpp
//  P#1resub
//
//  Created by Daren Sivam on 11/6/22.
//
/*
#include <iostream>
#include <string>
#include <cassert>
#include "WeddingGuest.h"
using namespace std;

int main()
{
    // default constructor
    WeddingGuest lal;
    // For an empty list:
    assert(lal.guestCount() == 0);

    assert(lal.noGuests()); // test empty

    assert(!lal.crossGuestOff("Malik", "Monk")); // nothing to erase

    // Copy constructor
    WeddingGuest groomsmen;
    groomsmen.inviteGuest("Tony", "Ambrosio", 40);
    groomsmen.inviteGuest("Mike", "Wu", 43);
    groomsmen.inviteGuest("Robert", "Wells", 44);
    groomsmen.inviteGuest("Justin", "Sandobal", 37);
    groomsmen.inviteGuest("Nelson", "Villaluz", 38);
    groomsmen.inviteGuest("Long", "Le", 41);
    WeddingGuest copy(groomsmen); // call to copy constructor

    // Assignment Operator
    WeddingGuest groomsmen;
    groomsmen.inviteGuest("Tony", "Ambrosio", 40);
    groomsmen.inviteGuest("Mike", "Wu", 43);
    groomsmen.inviteGuest("Robert", "Wells", 44);
    groomsmen.inviteGuest("Justin", "Sandobal", 37);
    groomsmen.inviteGuest("Nelson", "Villaluz", 38);
    groomsmen.inviteGuest("Long", "Le", 41);
    WeddingGuest copy;
    copy = groomsmen; // call to assignment operator

    // Destructor
    WeddingGuest groomsmen;
    groomsmen.inviteGuest("Tony", "Ambrosio", 40);
    groomsmen.inviteGuest("Mike", "Wu", 43);
    groomsmen.inviteGuest("Robert", "Wells", 44);
    groomsmen.inviteGuest("Justin", "Sandobal", 37);
    groomsmen.inviteGuest("Nelson", "Villaluz", 38);
    groomsmen.inviteGuest("Long", "Le", 41);
    groomsmen.~WeddingList();
    assert(lal.noGuests());

    // Invite Guest and Verify Guest On The List
    void test() {
        WeddingGuest eliteSingles;
        assert(eliteSingles.inviteGuest("Jackie", "S",
            "jackies@elitesingles.com"));
        assert(eliteSingles.inviteGuest("Mark", "P",
            "markp@elitesingles.com"));
        assert(eliteSingles.guestCount() == 2);
        string first, last, e;
        assert(eliteSingles.verifyGuestOnTheList(0, first, last, e)
            && e == "markp@elitesingles.com");
        assert(eliteSingles.verifyGuestOnTheList(1, first, last, e)
            && (first == "Jackie" && e == "jackies@elitesingles.com"));
        return;
    }

    // Invite Guest with GuestType as double and invitedToTheWedding
    void test() {
        WeddingGuest bridesmaids;
        bridesmaids.inviteGuest("Serra", "Park", 39.5);
        bridesmaids.inviteGuest("Saadia", "Parker", 37.5);
        assert(!bridesmaids.invitedToTheWedding("", ""));
        bridesmaids.inviteGuest("Patricia", "Kim", 39.0);
        bridesmaids.inviteGuest("", "", 21.0);
        bridesmaids.inviteGuest("Kristin", "Livingston", 38.0);
        assert(bridesmaids.invitedToTheWedding("", ""));
        bridesmaids.crossGuestOff("Patricia", "Kim");
        assert(bridesmaids.guestCount() == 4
            && bridesmaids.invitedToTheWedding("Serra", "Park")
            && bridesmaids.invitedToTheWedding("Saadia", "Parker")
            && bridesmaids.invitedToTheWedding("Kristin", "Livingston")
            && bridesmaids.invitedToTheWedding("", ""));
    }

    // Invite Guest with GuestType as int
    WeddingGuest groomsmen;
    groomsmen.inviteGuest("Tony", "Ambrosio", 40);
    groomsmen.inviteGuest("Mike", "Wu", 43);
    groomsmen.inviteGuest("Robert", "Wells", 44);
    groomsmen.inviteGuest("Justin", "Sandobal", 37);
    groomsmen.inviteGuest("Nelson", "Villaluz", 38);
    groomsmen.inviteGuest("Long", "Le", 41);
    for (int n = 0; n < groomsmen.guestCount(); n++)
    {
        string first;
        string last;
        int val;
        groomsmen.verifyGuestOnTheList(n, first, last, val);
        cout << first << " " << last << " " << val << endl;
    }

    // Alter Guest and matchInvitedGuest
    WeddingGuest groomsmen;
    groomsmen.inviteGuest("Tony", "Ambrosio", 40);
    groomsmen.inviteGuest("Mike", "Wu", 43);
    groomsmen.inviteGuest("Robert", "Wells", 44);
    groomsmen.inviteGuest("Justin", "Sandobal", 37);
    groomsmen.inviteGuest("Nelson", "Villaluz", 38);
    groomsmen.inviteGuest("Long", "Le", 41);
    groomsmen.alterGuest("Long", "Le", 69);
    int val;
    assert(groomsmen.matchInvitedGuest("Long","Le", val) && val == 69);
    cout << "Test passed.\n";

    // Attest Guest with last name as escape sequence
    WeddingGuest odOne, odTwo;
    odOne.inviteGuest("Cobey", "C", 35);
    odOne.inviteGuest("Dan", "H", 38);
    odOne.inviteGuest("Dan", "V", 44);
    odOne.inviteGuest("Dion", "V", 45);
    attestGuests("Dan", "*", odOne, odOne);
    int count = odOne.guestCount();
    for (int i = 0; i < count; i++)
    {
        string firstName, lastName;
        GuestType value;
        odOne.verifyGuestOnTheList(i, firstName, lastName, value);
        cout << firstName << " " << lastName << " " << value << "\n";
    }

    // Attest Guest with first name as escape sequence
    WeddingGuest odOne, odTwo;
    odOne.inviteGuest("Cobey", "C", 35);
    odOne.inviteGuest("Dan", "H", 38);
    odOne.inviteGuest("Dan", "V", 44);
    odOne.inviteGuest("Dion", "V", 45);
    attestGuests("*", "V", odOne, odOne);
    int count = odOne.guestCount();
    for (int i = 0; i < count; i++)
    {
        string firstName, lastName;
        GuestType value;
        odOne.verifyGuestOnTheList(i, firstName, lastName, value);
        cout << firstName << " " << lastName << " " << value << "\n";
    }

    // Attest Guest with first name and last name both as escape sequence
    WeddingGuest odOne, odTwo;
    odOne.inviteGuest("Cobey", "C", 35);
    odOne.inviteGuest("Dan", "H", 38);
    odOne.inviteGuest("Dan", "V", 44);
    odOne.inviteGuest("Dion", "V", 45);
    attestGuests("*", "*", odOne, odOne);
    int count = odOne.guestCount();
    for (int i = 0; i < count; i++)
    {
        string firstName, lastName;
        GuestType value;
        odOne.verifyGuestOnTheList(i, firstName, lastName, value);
        cout << firstName << " " << lastName << " " << value << "\n";
    }

    // Join guests with same guests having different values in both lists
    WeddingGuest odOne, odTwo;
    odOne.inviteGuest("Pete", "Best", 3);
    odOne.inviteGuest("John", "Lennon", 1);
    odOne.inviteGuest("Paul", "McCartney", 2);
    odTwo.inviteGuest("Pete", "Best", 6);
    odTwo.inviteGuest("George", "Harrison", 4);
    odTwo.inviteGuest("Ringo", "Starr", 5);
    if (!joinGuests(odOne, odTwo, odOne))
    {
        int count = odOne.guestCount();
        for (int i = 0; i < count; i++)
        {
            string firstName, lastName;
            GuestType value;
            odOne.verifyGuestOnTheList(i, firstName, lastName, value);
            cout << firstName << " " << lastName << " " << value << "\n";
        }
    }
    else
    {
        cout << "Failed\n";
    }

    // Join Guests with same guests and same values in different lists
    WeddingGuest odOne, odTwo;
    odOne.inviteGuest("Anthony", "Davis", 3);
    odOne.inviteGuest("Lebron", "James", 23);
    odOne.inviteGuest("Malik", "Monk", 11);
    odTwo.inviteGuest("Lebron", "James", 23);
    odTwo.inviteGuest("Russel", "Westbrook", 0);
    if (joinGuests(odOne, odTwo, odOne))
    {
        int count = odOne.guestCount();
        for (int i = 0; i < count; i++)
        {
            string firstName, lastName;
            GuestType value;
            odOne.verifyGuestOnTheList(i, firstName, lastName, value);
            cout << firstName << " " << lastName << " " << value << "\n";
        }
    }
    else
    {
        cout << "Failed\n";
    }
    return 0;
} */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <vector>
#include <type_traits>
#include "WeddingGuest.h"

using namespace std;

bool matchInvitedGuest3type(bool (WeddingGuest::*)(const std::string&, const std::string&, GuestType&) const) { return true; }
bool matchInvitedGuest3type(bool (WeddingGuest::*)(const std::string&, const std::string&, GuestType&)) { return false; }
bool matchInvitedGuest3type(...) { return false; }
bool verifyGuestOnTheList4type(bool (WeddingGuest::*)(int, std::string&, std::string&, GuestType&) const) { return true; }
bool verifyGuestOnTheList4type(bool (WeddingGuest::*)(int, std::string&, std::string&, GuestType&)) { return false; }
bool verifyGuestOnTheList4type(...) { return false; }

std::string SOMEFNAME = std::string("123");
std::string DEFAULTFNAME = std::string();
std::string ARRAYFNAME[6] = {
    std::string("10"), std::string("20"), std::string("30"),
    std::string("40"), std::string("50"), std::string("60")
};

std::string SOMELNAME = std::string("321");
std::string DEFAULTLNAME = std::string();
std::string ARRAYLNAME[6] = {
    std::string("11"), std::string("21"), std::string("31"),
    std::string("41"), std::string("51"), std::string("61")
};

GuestType SOMEVALUE = "junk";
GuestType DEFAULTV = GuestType();
GuestType ARRAYV[6] = {
    "able", "baker", "charlie", "delta", "echo", "foxtrot"
};

bool has(const WeddingGuest& m, const std::string& firstName, const std::string& lastName, const GuestType& v)
{
    GuestType v2 = DEFAULTV;
    m.matchInvitedGuest(firstName, lastName, v2);
    GuestType v3 = SOMEVALUE;
    m.matchInvitedGuest(firstName, lastName, v3);
    return v2 == v && v3 == v;
}

void testone(int n)
{
    WeddingGuest m;
    switch (n)
    {
    default: {
        cout << "Bad argument" << endl;
    } break; case  1: {
        assert((is_same<decltype(&WeddingGuest::noGuests), bool (WeddingGuest::*)() const>::value));
    } break; case  2: {
        assert((is_same<decltype(&WeddingGuest::guestCount), int (WeddingGuest::*)() const>::value));
    } break; case  3: {
        assert((is_same<decltype(&WeddingGuest::invitedToTheWedding), bool (WeddingGuest::*)(const std::string, const std::string) const>::value) ||
            (is_same<decltype(&WeddingGuest::invitedToTheWedding), bool (WeddingGuest::*)(const std::string&, const std::string&) const>::value));
    } break; case  4: {
        assert(matchInvitedGuest3type(&WeddingGuest::matchInvitedGuest));
    } break; case  5: {
        assert(verifyGuestOnTheList4type(&WeddingGuest::verifyGuestOnTheList));
    } break; case  6: {
        assert(m.noGuests());
    } break; case  7: {
        assert(m.guestCount() == 0);
    } break; case  8: {
        assert(!m.alterGuest(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE) && m.guestCount() == 0);
    } break; case  9: {
        assert(!m.crossGuestOff(DEFAULTFNAME, DEFAULTLNAME) && m.guestCount() == 0);
    } break; case 10: {
        assert(!m.invitedToTheWedding(DEFAULTFNAME, DEFAULTLNAME));
    } break; case 11: {
        GuestType v = SOMEVALUE;
        assert(!m.matchInvitedGuest(DEFAULTFNAME, DEFAULTLNAME, v) && v == SOMEVALUE);
    } break; case 12: {
        GuestType v = SOMEVALUE;
        assert(!m.verifyGuestOnTheList(0, DEFAULTFNAME, DEFAULTLNAME, v) && v == SOMEVALUE);
    } break; case 13: {
        assert(m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE));
    } break; case 14: {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        assert(!m.noGuests());
    } break; case 15: {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        assert(m.guestCount() == 1);
    } break; case 16: {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        assert(m.invitedToTheWedding(SOMEFNAME, SOMELNAME));
    } break; case 17: {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        GuestType v = DEFAULTV;
        assert(m.matchInvitedGuest(SOMEFNAME, SOMELNAME, v));
    } break; case 18: {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        GuestType v = DEFAULTV;
        m.matchInvitedGuest(SOMEFNAME, SOMELNAME, v);
        assert(v == SOMEVALUE);
    } break; case 19: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], SOMEVALUE);
        GuestType v = DEFAULTV;
        assert(!m.matchInvitedGuest(ARRAYFNAME[1], ARRAYLNAME[1], v));
    } break; case 20: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        GuestType v = SOMEVALUE;
        m.matchInvitedGuest(ARRAYFNAME[1], ARRAYLNAME[1], v);
        assert(v == SOMEVALUE);
    } break; case 21: {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        std::string f = DEFAULTFNAME;
        std::string l = DEFAULTLNAME;
        GuestType v = DEFAULTV;
        assert(m.verifyGuestOnTheList(0, f, l, v));
    } break; case 22: {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        std::string f = DEFAULTFNAME;
        std::string l = DEFAULTLNAME;
        GuestType v = DEFAULTV;
        m.verifyGuestOnTheList(0, f, l, v);
        assert(f == SOMEFNAME && l == SOMELNAME && v == SOMEVALUE);
    } break; case 23: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(!m.noGuests() && m.guestCount() == 2);
    } break; case 24: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) && m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]));
    } break; case 25: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    } break; case 26: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], SOMEVALUE);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], SOMEVALUE) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
    } break; case 27: {
        assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
        assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    } break; case 28: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]);
        assert(m.guestCount() == 2);
    } break; case 29: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    } break; case 30: {
        assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
        assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
        assert(!m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]));
    } break; case 31: {
        assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
        assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
        assert(!m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
    } break; case 32: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m.alterGuest(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE);
        assert(m.guestCount() == 3 && m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) && m.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    } break; case 33: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m.alterGuest(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE) &&
            has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]));
    } break; case 34: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        assert(m.alterGuest(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
    } break; case 35: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.alterGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[0]);
        assert(m.guestCount() == 2 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
            has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) && !m.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    } break; case 36: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(!m.alterGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]) && !m.alterGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[0]));
    } break; case 37: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(!m.noGuests() && m.guestCount() == 2);
    } break; case 38: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    } break; case 39: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], SOMEVALUE);
        m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE);
        assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0], SOMEVALUE) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
    } break; case 40: {
        assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
        assert(m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    } break; case 41: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteOrAlter(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]);
        assert(m.guestCount() == 2 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]) &&
            has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
    } break; case 42: {
        assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]));
        assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
        assert(m.inviteOrAlter(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]));
    } break; case 43: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE);
        assert(m.guestCount() == 3 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
            has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]));
    } break; case 44: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        assert(m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
    } break; case 45: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteOrAlter(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[0]);
        assert(m.guestCount() == 3 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
            has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[0]));
    } break; case 46: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(m.inviteOrAlter(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]));
    } break; case 47: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(m.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]));
    } break; case 48: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
        assert(!m.noGuests() && m.guestCount() == 1 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
            !m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]));
    } break; case 49: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.crossGuestOff(ARRAYFNAME[0], ARRAYLNAME[0]);
        assert(!m.noGuests() && m.guestCount() == 1 && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) &&
            !m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]));
    } break; case 50: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.crossGuestOff(ARRAYFNAME[0], ARRAYLNAME[0]);
        m.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
        assert(m.guestCount() == 0);
    } break; /*case 51: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
        m.crossGuestOff(ARRAYFNAME[2], ARRAYLNAME[2]);
        m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        //cout << m.guestCount() << endl;
        assert(m.guestCount() == 2 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
            has(m, ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]) && !m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            !m.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    } break; */case 52: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        assert(!m.crossGuestOff(ARRAYFNAME[2], ARRAYLNAME[2]) && m.guestCount() == 2);
    } break; case 53: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        std::string f;
        std::string l;
        GuestType v;
        assert(!m.verifyGuestOnTheList(-1, f, l, v));
    } break; case 54: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        std::string f = SOMEFNAME;
        std::string l = SOMELNAME;
        GuestType v = SOMEVALUE;
        m.verifyGuestOnTheList(-1, f, l, v);
        assert(f == SOMEFNAME && l == SOMELNAME && v == SOMEVALUE);
    } break; case 55: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        std::string f, l;
        GuestType v;
        assert(!m.verifyGuestOnTheList(2, f, l, v));
    } break; case 56: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        std::string f = SOMEFNAME;
        std::string l = SOMELNAME;
        GuestType v = SOMEVALUE;
        m.verifyGuestOnTheList(2, f, l, v);
        assert(f == SOMEFNAME && l == SOMELNAME && v == SOMEVALUE);
    } break; case 57: {
        m.inviteGuest(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE);
        assert(m.guestCount() == 1 && has(m, DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE));
    } break; case 58: {
        m.alterGuest(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE);
        assert(m.guestCount() == 0 && !m.invitedToTheWedding(DEFAULTFNAME, DEFAULTLNAME));
    } break; case 59: {
        m.inviteOrAlter(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE);
        assert(m.guestCount() == 1 && has(m, DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE));
    } break; case 60: {
        m.inviteGuest(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE);
        m.crossGuestOff(DEFAULTFNAME, DEFAULTLNAME);
        assert(m.guestCount() == 0 && !m.invitedToTheWedding(DEFAULTFNAME, DEFAULTLNAME));
    } break; case 61: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m.swapWeddingGuests(m2);
            assert(m.guestCount() == 3);
        }
    } break; case 62: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m.swapWeddingGuests(m2);
            assert(has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]) &&
                has(m, ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]) && !m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]));
        }
    } break; case 63: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m.swapWeddingGuests(m2);
            assert(m2.guestCount() == 2);
        }
    } break; case 64: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m.swapWeddingGuests(m2);
            assert(has(m2, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) && has(m2, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) &&
                !m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) && !m2.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]));
        }
    } break; case 65: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m.swapWeddingGuests(m2);
            assert(m.guestCount() == 3 && m2.guestCount() == 5);
        }
    } break; case 66: {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            assert(m2.guestCount() == 2 && m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) && !m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[3]));
        }
    } break; case 67: {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.crossGuestOff(ARRAYFNAME[2], ARRAYLNAME[2]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.crossGuestOff(ARRAYFNAME[0], ARRAYLNAME[0]);
            m2.crossGuestOff(ARRAYFNAME[3], ARRAYLNAME[3]);
            m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        }
        assert(true);  // no corruption so bad that destruction failed
    } break; case 68: {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            WeddingGuest m3(m2);
            m3.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m3.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
            m3.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m3.crossGuestOff(ARRAYFNAME[2], ARRAYLNAME[2]);
            m3.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m3.crossGuestOff(ARRAYFNAME[0], ARRAYLNAME[0]);
            m3.crossGuestOff(ARRAYFNAME[3], ARRAYLNAME[3]);
            m3.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        }
        assert(true);  // no corruption so bad that destruction failed
    } break; case 69: {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            WeddingGuest m3(m2);
            assert(m3.guestCount() == 3);
        }
    } break; case 70: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        {
            WeddingGuest m2(m);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            assert(m2.guestCount() == m.guestCount() + 1);
        }
    } break; case 71: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        {
            WeddingGuest m2(m);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            assert(m2.guestCount() == 4 && m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) && m2.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]));
        }
    } break; case 72: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        {
            WeddingGuest m2(m);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            assert(m2.guestCount() == 4 && m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) && !m2.invitedToTheWedding(ARRAYFNAME[4], ARRAYLNAME[4]));
        }
    } break; case 73: {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            WeddingGuest m3;
            m3.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
            m3.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5], ARRAYV[5]);
            m3 = m2;
            assert(m3.guestCount() == 3 && m2.guestCount() == 3);
        }
    } break; /*case 74: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
            m2 = m;
            m2.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5], ARRAYV[5]);
            assert(m2.guestCount() == m.guestCount() + 1);
        }
    } break;  case 75: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
            m2.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5], ARRAYV[5]);
            m2 = m;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
                m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
                !m2.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]));
        }
    } break; */case 76: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
            m2.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5], ARRAYV[5]);
            m2 = m;
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            assert(m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
                m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                !m.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
        }
    } break; case 77: {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2 = m2;
            assert(m2.guestCount() == 3);
            assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
                m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
        }
        assert(true);  // no corruption so bad that destruction failed
    } break; case 78: {
        {
            WeddingGuest m2;
            m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
            m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
            m2 = m2;
            m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
            assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
                m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
                m2.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]));
        }
    } break; case 79: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        WeddingGuest m3;
        joinGuests(m, m2, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    } break; case 80: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        WeddingGuest m3;
        joinGuests(m2, m, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    } break; case 81: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        WeddingGuest m3;
        joinGuests(m, m2, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
            m3.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]) &&
            m3.invitedToTheWedding(ARRAYFNAME[4], ARRAYLNAME[4]));
    } break; case 82: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        WeddingGuest m3;
        assert(joinGuests(m, m2, m3));
    } break; case 83: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        WeddingGuest m3;
        m3.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[5]);
        joinGuests(m, m2, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
            m3.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]) &&
            m3.invitedToTheWedding(ARRAYFNAME[4], ARRAYLNAME[4]) &&
            has(m3, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]) &&
            !has(m3, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[5]));
    } break; case 84: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        WeddingGuest m3;
        m3.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[5]);
        assert(joinGuests(m, m2, m3));
    } break; case 85: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m3;
        joinGuests(m, m2, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
            m3.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]));
    } break; case 86: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m3;
        assert(joinGuests(m, m2, m3));
    } break; case 87: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[4]);
        WeddingGuest m3;
        joinGuests(m, m2, m3);
        assert(m3.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            m3.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            m3.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    } break; case 88: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[4]);
        WeddingGuest m3;
        assert(!joinGuests(m, m2, m3));
    } break; case 89: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        joinGuests(m, m2, m);
        assert(m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            m.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
            m.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]) &&
            m.invitedToTheWedding(ARRAYFNAME[4], ARRAYLNAME[4]));
    } break; case 90: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3], ARRAYV[3]);
        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4], ARRAYV[4]);
        joinGuests(m, m2, m2);
        assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]) &&
            m2.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]) &&
            m2.invitedToTheWedding(ARRAYFNAME[4], ARRAYLNAME[4]));
    } break; case 91: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        attestGuests(ARRAYFNAME[1], ARRAYLNAME[1], m, m2);
        assert(!m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) && m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]));
    } break; case 92: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        attestGuests(ARRAYFNAME[1], ARRAYLNAME[1], m, m2);
        assert(!m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) && m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]));
    } break; case 93: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        attestGuests(ARRAYFNAME[1], ARRAYLNAME[1], m, m);
        assert(!m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) && m.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]));
    } break; case 94: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[2]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[1], ARRAYV[3]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        attestGuests("*", ARRAYLNAME[1], m, m2);
        assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[1]) &&
            m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[1]) &&
            !m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            !m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    } break; case 95: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[0], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[2]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[2], ARRAYV[3]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        attestGuests(ARRAYFNAME[1], "*", m, m2);
        assert(m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[0]) &&
            m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[2]) &&
            !m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            !m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    } break; case 96: {
        string all = "*";
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]);
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[1], ARRAYV[1]);
        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[2]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[1], ARRAYV[3]);
        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]);
        WeddingGuest m2;
        attestGuests("*", "*", m, m2);
        assert(m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[1]) &&
            m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
            m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[1]) &&
            m2.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
            m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[2]));
    } break; case 97: {
        WeddingGuest m2 = m;
        WeddingGuest m3;
        attestGuests("*", "*", m2, m3);
        assert(m3.guestCount() == m.guestCount());
    } break; case 98: {
        WeddingGuest m2;
        WeddingGuest m3(m);
        attestGuests("*", "*", m2, m3);
        assert(m3.noGuests());
    } break; case 99: {
        WeddingGuest m2;
        attestGuests("*", "*", m2, m2);
        assert(m2.guestCount() == 0);
    } break; case 100: {
        const int NITEMS = 2000;
        for (int k = 0; k < NITEMS; k++)
            assert(m.inviteGuest(std::to_string(k), std::to_string(k), SOMEVALUE));
        assert(m.guestCount() == NITEMS);
    }
    }
}

int main()
{
    for (int n = 1; n <= 100; n++) {
        testone(n);
        cout << n << " passed" << endl;
    }

    return 0;
}


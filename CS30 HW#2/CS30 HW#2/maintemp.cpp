//Daren Sathasivam
//CS30, 0171
//Homework #2
//Create out own smart pointer type which containts a reference count. Various other functions will also be implemented to display raw pointer's abilities.
/*
#include <iostream>
#include <stdexcept>
#include "smart_ptr.h"
using namespace std;

struct Point { int x = 2; int y = -5; };

int main()
{
    int* p { new int { 42 } };
    smart_ptr<int> sp1 { p };
     
    // Ref Count is 1
    cout << "Ref count is " << sp1.ref_count() << endl;
    {
       smart_ptr<int> sp2 { sp1 };
       // Ref Count is 2
       cout << "Ref count is " << sp1.ref_count() << endl;
       // Ref Count is 2
       cout << "Ref count is " << sp2.ref_count() << endl;
    }
     
    // Ref Count is 1
    cout << "Ref count is " << sp1.ref_count() << endl;
         
    smart_ptr<int> sp3;
     
    // Ref Count is 0
    cout << "Ref count is " << sp3.ref_count() << endl;
         
    sp3 = sp1;
     
    // Ref Count is 2
    cout << "Ref count is " << sp1.ref_count() << endl;
    // Ref Count is 2
    cout << "Ref count is " << sp3.ref_count() << endl;
     
    smart_ptr<int> sp4 = std::move(sp1);
     
    cout << *sp4 << " " << *sp3 << endl;        // prints 42 42
    

    smart_ptr<Point> sp { new Point };
    cout << sp->x << " " << sp->y << endl;   // prints 2 -5
     
    
    smart_ptr<double> dsp1 { new double {3.14} };
    smart_ptr<double> dsp2, dsp3;
         
    dsp3 = dsp2 = dsp1;
     
    cout << dsp1.ref_count() << " " << dsp2.ref_count() << " "
         << dsp3.ref_count() << endl; // prints 3 3 3
    // prints 3.14 3.14 3.14
    cout << *dsp1 << " " << *dsp2 << " " << *dsp3 << endl;
     
    dsp1.clone();        // returns true
     
    cout << dsp1.ref_count() << " " << dsp2.ref_count() << " "
         << dsp3.ref_count() << endl; // prints 1 2 2
    // prints 3.14 3.14 3.14
    cout << *dsp1 << " " << *dsp2 << " " << *dsp3 << endl;
     
    cout << *sp1 << endl;   // throws null_ptr_exception
    
    return 0;
}
*/

#include <stdexcept>
#include <new>
#include <set>
#include <iostream>
#include <cassert>
using namespace std;

class null_ptr_exception : public std::runtime_error
{
    //constructor for runtime_error
    //other functions are optional
public:
    null_ptr_exception(const char* n) : runtime_error(n){}
};

template <typename T>
class smart_ptr {
public:
    smart_ptr() noexcept
    {
        // Create a smart_ptr that is initialized to nullptr. The reference count should be initialized to nullptr.
        //std::cout << "Base Constructor\n";
        ref_ = nullptr;
        ptr_ = nullptr;
    }

       
    explicit smart_ptr(T* raw_ptr) noexcept //raw_ptr does not change if constructed
    {
        // Create a smart_ptr that is initialized to raw_ptr. The
        // reference count should be one.  Make sure it points to
        // the same pointer as the raw_ptr.
        //std::cout << "Constructor Argument\n";
        ptr_ = raw_ptr;
        ref_ = new int(1);
    }
 
    smart_ptr(const smart_ptr& rhs) noexcept
    {
        // Copy construct a pointer from rhs. The reference count should be incremented by one.
        //std::cout << "Copy Constructor\n";
        if(rhs.ptr_ != nullptr)
        {
            ptr_ = rhs.ptr_;
            ref_ = rhs.ref_;
            (*ref_) ++;
        }
    }
 
    smart_ptr(smart_ptr&& rhs) noexcept
    {
        // Move construct a pointer from rhs.
        //std::cout << "Move Constuctor\n";
        ptr_ = rhs.ptr_;
        ref_ = rhs.ref_;
        rhs.ptr_ = nullptr;
        rhs.ref_ = nullptr;
    }
 
    smart_ptr& operator=(const smart_ptr& rhs) noexcept
    {
        // This assignment should make a shallow copy of the
       // right-hand side's pointer data. The reference count
       // should be incremented as appropriate.
        //std::cout << "RHS Shallow Copy\n";
        if (this == &rhs) //check for aliasing
            return *this;
        if (ref_ != nullptr)
        {
            if (ref_count() <= 1) //delete node when 1 or less
            {
                delete ptr_;
                delete ref_;
            }
            else
            {
                (*ref_)--; //decrement
            }
        }
        //shallow copies
        ptr_ = rhs.ptr_;
        ref_ = rhs.ref_;
        if (ref_ != nullptr)
            (*ref_)++; //increment ref count

        return *this;
    }

 
    smart_ptr& operator=(smart_ptr&& rhs) noexcept
    {
        // This move assignment should steal the right-hand side's pointer data.
        //std::cout << "Steal RHS\n";
        if (this == &rhs) //check for aliasing
            return *this;
        if (ref_ != nullptr)
        {
            if (ref_count() <= 1) //delete node when 1 or less
            {
                delete ptr_;
                delete ref_;
            }
            else
            {
                (*ref_)--; //decrement
            }
        }
        
        ptr_ = rhs.ptr_;
        ref_ = rhs.ref_;
        rhs.ptr_ = nullptr;
        rhs.ref_ = nullptr;
        
        return *this;
    }

       
    bool clone()
    {
        // If the smart_ptr is either nullptr or has a reference
        // count of one, this function will do nothing and return
        // false. Otherwise, the referred to object's reference
        // count will be decreased and a new deep copy of the
        // object will be created. This new copy will be the
        // object that this smart_ptr points and its reference
        // count will be one.
        //std::cout << "Clone\n";

        if(ptr_ == nullptr || *ref_ == 1)
        {
            return false;
        }
        T* oldPtr = this->ptr_;
        try {
            this->ptr_ = new T(*this->ptr_);
        } catch (std::bad_alloc) {
            this->ptr_ = oldPtr; //set value to original
            throw std::bad_alloc();
        }
        int* newRef;
        try {   //try twice
            newRef = new int(1);
        } catch (std::bad_alloc) {
            delete this->ptr_;
            this->ptr_ = oldPtr; //set value to original
            throw std::bad_alloc();
        }

        (*ref_)--; //decrement
        this->ref_ = newRef;
        return true;
    }
    /*
     (*ref_)--; //decrement
     this->ptr_ = new T(*this->ptr_); //deep copy
     //this = new smart_ptr(this->ptr_); //deep copy
     this->ref_ = new int(1); //set ref count to 1
     return true;
     */
     
    int ref_count() const noexcept
    {
        // Returns the reference count of the pointed to data.
        if(ref_ == nullptr)
            return 0;
        return *ref_;
    }

    T& operator*()
    {
        // The dereference operator shall return a reference to the referred object. Throws null_ptr_exception on invalid access.
        if(ptr_ == nullptr)
            throw null_ptr_exception("Null pointer exception");
        return *ptr_; //reference to referred ptr
    }


    T* operator->()
    {
      // The arrow operator shall return the pointer ptr_. Throws null_ptr_exception on invalid access.
        if(ptr_ == nullptr)
            throw null_ptr_exception("Null pointer exception");
        return ptr_; //returns pointer ptr_
    }


  ~smart_ptr() noexcept // deallocate all dynamic memory
    {
        //std::cout << "Destructor\n";
        if (ref_ != nullptr)
        {
            if (*ref_ > 1)
            {
                --(*ref_);
            }
            else
            {
                delete ptr_;
                delete ref_;
            }
        }
  }
   
private:
  T* ptr_;               // pointer to the referred object
  int* ref_;             // pointer to a reference count
};

struct OurType
{
    explicit OurType(int v = 0) : m_value(v) { m_count++; }
    OurType(const OurType& other) : m_value(other.m_value)
    {
        m_count++; m_asstcopycount++;
    }
    ~OurType() { m_count--; }
    OurType& operator=(const OurType& rhs)
    {
        m_value = rhs.m_value; m_asstcopycount++; return *this;
    }

    int m_value;
    static int m_count;
    static int m_asstcopycount;
};

inline
bool operator==(const OurType& lhs, const OurType& rhs)
{
    return lhs.m_value == rhs.m_value;
}

inline
bool operator<(const OurType& lhs, const OurType& rhs)
{
    return lhs.m_value < rhs.m_value;
}

inline
bool operator!=(const OurType& lhs, const OurType& rhs)
{
    return !(lhs == rhs);
}

inline
bool operator<=(const OurType& lhs, const OurType& rhs)
{
    return !(rhs < lhs);
}

inline
bool operator>=(const OurType& lhs, const OurType& rhs)
{
    return !(lhs < rhs);
}

inline
bool operator>(const OurType& lhs, const OurType& rhs)
{
    return rhs < lhs;
}

inline
bool operator==(const OurType& lhs, int rhs)
{
    return lhs.m_value == rhs;
}

inline
bool operator!=(const OurType& lhs, int rhs)
{
    return !(lhs == rhs);
}

#include <iostream>

inline
std::ostream& operator<<(std::ostream& lhs, const OurType& rhs)
{
    return lhs << rhs.m_value;
}

int OurType::m_count = 0;
int OurType::m_asstcopycount = 0;

inline int itemcount()
{
    return OurType::m_count;
}

inline int nasstcopys()
{
    return OurType::m_asstcopycount;
}

std::set<void*> addrs;
bool recordaddrs = false;

int throwBadAlloc = 0;
// value of 0 means allocations don't throw
// value of 1 means 1st allocation throws
// value of 2 means 2nd allocation throws
// value of n means nth allocation throws

void* operator new(size_t n)
{
    if (recordaddrs) {
        if (throwBadAlloc == 1)
            throw std::bad_alloc();
        else if (throwBadAlloc > 1)
            throwBadAlloc--;
    }
    void* p = malloc(n);
    if (recordaddrs)
    {
        recordaddrs = false;
        addrs.insert(p);
        recordaddrs = true;
    }
    return p;
}

void operator delete(void* p) noexcept
{
    if (recordaddrs)
    {
        recordaddrs = false;
        std::set<void*>::iterator it = addrs.find(p);
        if (it != addrs.end())
            addrs.erase(it);
        recordaddrs = true;
    }
    free(p);
}

void testone(int n)
{
    smart_ptr<double> dsp0;
    smart_ptr<double> dsp1{ new double{ 3.14 } };
    smart_ptr<double> dsp2, dsp3;

    switch (n)
    {
    default: {
        assert(false);
    } break; case  1: {
        assert(dsp0.ref_count() == 0);
    } break; case  2: {
        assert(dsp1.ref_count() == 1);
    } break; case  3: {
        dsp0 = dsp1;
        assert(dsp0.ref_count() == 2);
    } break; case  4: {
        dsp3 = dsp2 = dsp1;
        assert(dsp3.ref_count() == dsp2.ref_count() &&
            dsp1.ref_count() == dsp2.ref_count() &&
            dsp1.ref_count() == 3);
    } break; case  5: {
        dsp1 = dsp0;
        assert(dsp1.ref_count() == 0 && dsp0.ref_count() == 0);
    } break; case  6: {
        assert(std::is_nothrow_constructible<smart_ptr<int>>::value);
        assert(std::is_nothrow_copy_constructible<smart_ptr<int>>::value);
        // possible XCode compiler bug for following two asserts
        //assert(std::is_nothrow_constructible<smart_ptr<int>,int*>::value);
        //assert(std::is_nothrow_assignable<A,A>::value);
        assert(std::is_nothrow_move_assignable<smart_ptr<int>>::value);
        assert(std::is_nothrow_move_constructible<smart_ptr<int>>::value);
        assert(!noexcept(std::declval<smart_ptr<int>>().clone()));
        assert(!noexcept(std::declval<smart_ptr<int>>().operator*()));
        assert(!noexcept(std::declval<smart_ptr<int>>().operator->()));
        assert(noexcept(std::declval<smart_ptr<int>>().ref_count()));
    } break; case  7: {
        {
            // testing constructor
            smart_ptr<OurType> osp0{ new OurType{ 0 } };
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    } break; case  8: {
        {
            // testing assignment operator
            smart_ptr<OurType> osp0{ new OurType{ 0 } };
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1;
            osp1 = osp0;
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    } break; case  9: {
        {
            // testing copy constructor
            smart_ptr<OurType> osp0{ new OurType{ 0 } };
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1{ osp0 };
            assert(osp0.ref_count() == 2);
            assert(osp1.ref_count() == 2);
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    } break; case 10: {
        {
            // testing move constructor
            smart_ptr<OurType> osp0{ new OurType{ 0 } };
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1{ std::move(osp0) };
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    } break; case 11: {
        {
            // testing move assignment
            smart_ptr<OurType> osp0{ new OurType{ 0 } };
            assert(osp0.ref_count() == 1);
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1;
            osp1 = std::move(osp0);
            assert(osp1.ref_count() == 1);
            assert(osp0.ref_count() == 0);
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    } break; case 12: {
        {
            // testing move constructor
            smart_ptr<OurType> osp0{ new OurType{ 0 } };
            assert(osp0.ref_count() == 1);
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1{ std::move(osp0) };
            assert(osp1.ref_count() == 1);
            assert(osp0.ref_count() == 0);
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    } break; case 13: {
        {
            // testing move assignment
            smart_ptr<OurType> osp0{ new OurType{ 0 } };
            assert(osp0.ref_count() == 1);
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1;
            osp1 = std::move(osp0);
            assert(osp1.ref_count() == 1);
            assert(osp0.ref_count() == 0);
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    } break; case 14: {
        {
            // testing assignment operator
            smart_ptr<OurType> osp0;
            assert(itemcount() == 0);
            smart_ptr<OurType> osp1;
            osp1 = osp0;
            assert(itemcount() == 0);
        }
        assert(itemcount() == 0);
    } break; case 15: {
        try {
            *dsp0;
            assert(0);
        }
        catch (...) {}
    } break; case 16: {
        smart_ptr<OurType> osp{ new OurType{ 42 } };
        try {
            assert((*osp).m_value == 42);
        }
        catch (...) {
            assert(0);
        }
    } break; case 17: {
        smart_ptr<OurType> osp;
        try {
            (*osp).m_value;     // should throw
            assert(0);
        }
        catch (...) {}
    } break; case 18: {
        smart_ptr<OurType> osp{ new OurType{ 42 } };
        try {
            assert(osp->m_value == 42);
        }
        catch (...) {
            assert(0);
        }
    } break; case 19: {
        smart_ptr<OurType> osp;
        try {
            osp->m_value;       // should throw
            assert(0);
        }
        catch (...) {}
    } break; case 20: {
        assert(!dsp0.clone());
        assert(!dsp1.clone());
    } break; case 21: {
        dsp3 = dsp2 = dsp1;
        assert(dsp1.clone());
        assert(dsp1.ref_count() == 1 && dsp2.ref_count() == 2 && dsp3.ref_count() == 2);
        assert(*dsp1 == 3.14 && *dsp2 == 3.14 && *dsp3 == 3.14);
    } break; case 22: {
        dsp3 = dsp2 = dsp1;
        recordaddrs = true;
        throwBadAlloc = 1;      // first allocation throws exception
        size_t oldSize = addrs.size();
        try {
            dsp1.clone();
            assert(0);
        }
        catch (std::bad_alloc) {}
        // test for strong guarantee, no change to dsp1
        assert(*dsp1 == *dsp2 && dsp1.ref_count() == dsp2.ref_count());
        assert(addrs.size() == oldSize);
        recordaddrs = false;
    } break; case 23: {
        dsp3 = dsp2 = dsp1;
        recordaddrs = true;
        throwBadAlloc = 2;      // second allocation throws exception
        size_t oldSize = addrs.size();
        try {
            dsp1.clone();
            assert(0);
        }
        catch (std::bad_alloc) {}
        // test for strong guarantee, no change to dsp1
        assert(*dsp1 == *dsp2 && dsp1.ref_count() == dsp2.ref_count());
        assert(addrs.size() == oldSize);
        recordaddrs = false;
    } break; case 24: {
        dsp3 = dsp2 = dsp1;
        assert(*dsp1 == *dsp2 && *dsp2 == *dsp3 && *dsp1 == 3.14);
        assert(dsp1.ref_count() == dsp2.ref_count() &&
            dsp2.ref_count() == dsp3.ref_count() &&
            dsp1.ref_count() == 3);
    } break; case 25: {
        dsp3 = dsp2 = dsp1;
        dsp3 = dsp0;
        assert(*dsp1 == *dsp2 && *dsp1 == 3.14);
        assert(dsp1.ref_count() == dsp2.ref_count() &&
            dsp1.ref_count() == 2 &&
            dsp3.ref_count() == 0);
    }
    }
}

int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed" << endl;
}

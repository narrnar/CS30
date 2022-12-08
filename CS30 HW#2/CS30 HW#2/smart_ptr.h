//
//  smart_ptr.h
//  CS30 HW#2
//
//  Created by Daren Sivam on 10/10/22.
//

#ifndef smart_ptr_h
#define smart_ptr_h

#include <stdio.h>
#include <stdexcept>

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
            throw null_ptr_exception("Invalid * opertaion");
        return *ptr_; //reference to referred ptr
    }


    T* operator->()
    {
      // The arrow operator shall return the pointer ptr_. Throws null_ptr_exception on invalid access.
        if(ptr_ == nullptr)
            throw null_ptr_exception("Invalid -> operation");
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

#endif /* smart_ptr_h */

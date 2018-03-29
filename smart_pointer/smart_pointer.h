#include <algorithm>
#include <utility>
#include <iostream>

namespace my_smart_pointer
{
class smart_pointer 
{
public:
    smart_pointer() = default;
    smart_pointer(int* ptr) : ptr_{ptr} {};
    smart_pointer(const smart_pointer& sptr){ copy(sptr); };
    smart_pointer(smart_pointer&& sptr){ std::swap(*this, sptr); };
    ~smart_pointer(){ delete ptr_; };

    smart_pointer& operator=(const smart_pointer& rhs)
    {
        // if(sptr == this) return *this; // no ==operator
        copy(rhs);
        return *this;
    };
    smart_pointer& operator=(smart_pointer&& sptr)
    {
        //if (sptr == this) return *this;
        std::swap(ptr_, sptr.ptr_); // Important that sptr dont delete our ptr
        return *this;
    };

    int& operator*() const { return *ptr_; }; 
    int* operator->() const { return ptr_; }; 

    bool operator!() const { return (ptr_ == nullptr); };
    // We eant the operators to be able to accept (int* == smart_pointer) and (smart_pointer == int*).
    // We do this by declaring non-member operators
    friend bool operator==( const smart_pointer& lhs, const smart_pointer& rhs);
    friend bool operator==( const int* lhs, const smart_pointer& rhs);
    friend bool operator==( const smart_pointer& lhs, const int* rhs);
    friend bool operator!=( const smart_pointer& lhs, const smart_pointer& rhs);
    friend bool operator!=( const int* lhs, const smart_pointer& rhs);
    friend bool operator!=( const smart_pointer& lhs, const int* rhs);
private:
    int* ptr_{nullptr};
    void clear(){ delete ptr_; ptr_ =  nullptr; };
    void copy(const smart_pointer& sptr)
    {
        sptr.ptr_ == nullptr? ptr_ = nullptr : ptr_ = new int{*sptr.ptr_};
    };      
  
};

bool operator== (const smart_pointer& lhs, const smart_pointer& rhs)
{
    return (lhs.ptr_ == rhs.ptr_);
}
bool operator== (const int* lhs, const smart_pointer& rhs)
{
    return (lhs == rhs.ptr_);
}
bool operator== (const smart_pointer& lhs, const int* rhs)
{
    return (lhs.ptr_ == rhs);
}
bool operator!= (const smart_pointer& lhs, const smart_pointer& rhs)
{
    return (lhs.ptr_ != rhs.ptr_);
}
bool operator!= (const int* lhs, const smart_pointer& rhs)
{
    return (lhs != rhs.ptr_);
}
bool operator!= (const smart_pointer& lhs, const int* rhs)
{
    return (lhs.ptr_ != rhs);
}


} // namespace my_smart_pointer






// always initialized
// deallocated automatically
//  deep copy (copy-on-create/assign), destructive copy, reference counting, reference linking and copy on
//  write (COW)


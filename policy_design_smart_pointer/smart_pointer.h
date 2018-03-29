#include <algorithm>
#include <utility>
#include <iostream>

namespace my_smart_pointer
{

/************************************************************************
 * TYPE SELECTION
 * **********************************************************************/

/* 
 * select_type selects one of the two template types depending on a bolean constant.
 * The boolean is a complile-type constant. T1 is the default type (true) and T2 is the
 * specialization since the that's where the argument list is defined. (?) */
template<bool selector, typename T1, typename T2>
struct select_type
{   //non-specialized
    typedef T1 result;
};

template <typename T1, typename T2>
struct select_type <false, T1, T2>
{   //specialized
    typedef T2 result;
};

/************************************************************************
 * CONVERSION POLICY
 * **********************************************************************/

/* allow_conversion allows conversion to the pointee type */

struct allow_conversion { static const bool allow{true}; };

/* disallow_conversion disallows conversion to the pointee type */

struct disallow_conversion { static const bool allow{false}; };

/************************************************************************
 * SMART POINTER 
 * **********************************************************************/

class incompatible{};

template <typename T, typename conversion_policy = disallow_conversion>
class smart_pointer : conversion_policy
{
public:
    smart_pointer() = default;
    explicit smart_pointer(T* ptr) : ptr_{ptr} {};
    smart_pointer(const smart_pointer& rhs){ copy(rhs); };
    smart_pointer(smart_pointer&& rhs){ std::swap(*this, rhs); };
    ~smart_pointer(){ delete ptr_; };

    smart_pointer& operator=(const smart_pointer& rhs)
    {
        if(this == rhs) return *this;

        delete ptr_;
        copy(rhs);
        return *this;
    };
    smart_pointer& operator=(smart_pointer&& rhs)
    {
        if (rhs == this) return *this;
        std::swap(ptr_, rhs.ptr_); // Important that rhs dont delete our ptr
        return *this;
    };

    T& operator*() const { return *ptr_; }; 
    T* operator->() const { return ptr_; }; 

    bool operator!() const { return (ptr_ == nullptr); };
    // We eant the operators to be able to accept (T* == smart_pointer) and (smart_pointer == T*).
    // We do this by declaring non-member operators
    // friend bool operator==( const smart_pointer& lhs, const smart_pointer& rhs);
    // friend bool operator==( const int* lhs, const smart_pointer& rhs);
    // friend bool operator==( const smart_pointer& lhs, const int* rhs);
    // friend bool operator!=( const smart_pointer& lhs, const smart_pointer& rhs);
    // friend bool operator!=( const int* lhs, const smart_pointer& rhs);
    // friend bool operator!=( const smart_pointer& lhs, const int* rhs);
private:
    class disallowed {};
    
    // If implicit type conversion is allowed, 'implicit_conversion_type'
    // will be defined as 'pointer type', else as 'disallowed'
    using implicit_conversion_type = typename select_type<conversion_policy::allow, T*, disallowed>::result;

public:

    // If implicit type conversion is allowed, 'implicit_conversion_type'
    // will be 'pointer_type', otherwise 'implicit_conversion_type' will
    // be 'disallowed'. Since there is no conversion from 'pointer_type'
    // to 'disallowed', it will result in a compile-time error.
    operator implicit_conversion_type() const { return ptr_; }



private:
    T* ptr_{nullptr};
    void clear(){ delete ptr_; ptr_ =  nullptr; };
    void copy(const smart_pointer& rhs)
    {
        rhs.ptr_ == nullptr? ptr_ = nullptr : ptr_ = new T{*rhs.ptr_};
    };      
  
};
/*
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
*/

} // namespace my_smart_pointer






// always initialized
// deallocated automatically
//  deep copy (copy-on-create/assign), destructive copy, reference counting, reference linking and copy on
//  write (COW)




// varför inte frienda operatorer i templates?

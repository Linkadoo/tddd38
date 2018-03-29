
//1. By fucntion
//3. Adding constexpr
constexpr unsigned Fib(unsigned N)
{
  if(N <= 1)
    return N;
  return Fib(N-1) + Fib(N-2);
}

//2. Template instead:
template <unsigned N>
struct FIB
{
  static const unsigned value = FIB<N-1>::value + FIB<N-2>::value;
};

template<>
struct FIB<1> { static const unsigned value = 1;};

template<>
struct FIB<0> { static const unsigned value = 0;};


int main()
{
  //return Fib<4>::value;
  return Fib(4); //3. Now the compiler can optimize since constexpr
}
// When this compiles all calculations are done.

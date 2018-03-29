### Lecture 6

#### groups of containers
 - sequence containers
 - Sequence adaptors, built on sequence containers but changes the ingerface
 - Associative containers, key - value

##### Sequence containers

- vector - stores values in a continguous block, can be changed in size
- array - Like a vector but fixed size
- deque - Useful if u wanna change the start or end
- list - A double-linked list
- forward_list A single-linked list

##### adaptors
- stack - Push and pop
- queue

##### Associative containers
Keys cannot change in an associative container. You will have to remove + insert a new one

- Map - Associates a value to a key <string, int>
- Set - Like map but will only use the key

##### Iterators
The container provides us with an iterator to traverse the underlying data structures. Different containers have different kinds of iterators. Works the same way as C-pointers.

Five types of iterators: Input, output, forward, bidirectional, random access
 - begin gives an iterator to the first element
 - end gives an iterator to the first position outside the elements

Tag dispatching - Checks what kind of iterator we have and does different things.

Why are the iterators so important to get?
#### Algorithms

stl algorithms to make our lives easier. stl algorithms operates on iterators, for example sort requires random access iterators.

Example:
min_element calculates the min element in a container. Inputs two iterators, one where to start and one where to end. Requires operator ++ and < to be implemented. (can also take a third argument which is a comparator)

#### Lambda expressions
Creates a temporary anonymous function object
``` cpp
struct __SECRET_NAME__
{
  bool operator()(int l, int r){}
}{*creates an object of that type*}
```

#### Summary

**Containers** ->provides->  **iterators** <-work on<- **algorithms**

**streams** -> **iterators**

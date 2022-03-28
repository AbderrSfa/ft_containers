# ft_containers
## 🧐 Description
This project is a re-implementation of three container types from the C++ Standard Template Library (STL). `std::vector`, `std::stack`, and `std::map`.

I also implemented:

- `iterator` and `reverse_iterator` for vector and map.
- `enable_if`.
- `std::equal` and `std::lexicographical_compare`.
- `std::pair`.

### ➡️ vector
Vectors are sequence containers representing arrays that can change in size. Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

These vector member functions are implemented:
```
  - Constructors.
  - Destructor.
  - operator=.

  Iterators:
  - begin
  - end
  - rbegin
  - rend

  Capacity:
  - size
  - max_size
  - resize
  - capacity
  - empty
  - reserve

  Element access:
  - operator[]
  - at
  - front
  - back

  Modifiers:
  - assign
  - push_back
  - pop_back
  - insert
  - erase
  - swap
  - clear

  Allocator:
  - get_allocator

Non-member function overloads:
  - relational operators
  - swap
```

### 📚 stack
Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.
Stacks use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack.

These vector member functions are implemented:
```
  - Constructor
  - empty
  - size
  - top
  - push
  - pop

Non-member function overloads:
  - relational operators
```

### 🗺 map
Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.
In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key. The types of key and mapped value may differ.

These vector member functions are implemented:
```
  - Constructors
  - Destructor
  - operator=

  Iterators:
  - begin
  - end
  - rbegin
  - rend

  Capacity:
  - empty
  - size
  - max_size

  Element access:
  - operator[]

  Modifiers:
  - insert
  - erase
  - swap clear

  Observers:
  - key_comp
  - value_comp

  Operations:
  - find
  - count
  - lower_bound
  - upper_bound
  - equal_range

  Allocator:
  - get_allocator

Non-member function overloads:
  - relational operators
  - swap
```

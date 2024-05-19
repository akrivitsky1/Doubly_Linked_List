# <center> Doubly Linked List </center>

## Goals
- Practice creating templated code
- Practice creating iterators
- Use Google Test


## Matthew’s Stats
- Time taken: 2 hours
- Files: 13
- Lines of Code: 987


## Restrictions and Requirements
- No global variables may be used
- You may **NOT** change the signatures of any of the provided methods
    - You may add additional members and methods if you wish 
- You may **NOT** remove any methods
    - Again, adding members and methods is completely fine
- You may **NOT** use any stl containers such as but not limited to std::deque or std::vector in your solution. Doing so **will be considered cheating** and you will be sent to SJA for it.  
    
## Problem Description
Implement a **templated** library for a doubly-linked list class. A doubly linked list is made up of Nodes. Each node contains a value and a pointer to the next element in the sequence as well as to the previous element. You can think of it like the barrel of monkeys below. 

![barrel of monkeys](https://i.pinimg.com/originals/a6/85/7c/a6857c4b21553f96a13ea6bce783420e.jpg)

Each monkey is a Node with its body the value and its arms the pointers to the next and previous Node. 

The way that the Doubly Linked List keeps track of its nodes is through two pointers: head and tail. Head points to the first element in the list and tail points to the last element in the list so you end up with something that looks like ![A doubly linked list](https://miro.medium.com/max/750/1*92uL4rbcoVNErS72qzFw-g.png)

Your doubly linked list will be **templated** over the type of element it stores in the Node. 

While doubly-linked lists may appear similar to vectors the way that they are stored in memory causes them to have very different performance characteristics. 
- Insertion and deletion of elements at both the front and end of a doubly-linked list are very quick while only insertions and deletions at the end of vectors are efficient.
- To access an element in a doubly-linked list you must go through all of the elements that come before it but with a vector the amount of time it takes to access an element is constant 

So if you do a lot of removals and insertions a doubly-linked list is probably better but if you do a lot of random element accesses a vector would be superior.

## The Classes
### Doubly Linked List
- The doubly linked list class. 
- You will need to add the members mentioned in the problem description
- Templated over the type of element it stores

### Doubly Linked Node
- A Node in the Doubly Linked List Class
- I haven't given you anything here so what you do is up to you but make sure it has at least the members discussed in the problem description
- Templated over the type of value that it stores

### Iterators
- All of the iterators you are creating are [bidirectional iterators](http://www.cplusplus.com/reference/iterator/BidirectionalIterator/).
- Implementing them will be a little different from what we've covered in class because our container is not indexed based and does not possess an at method. Don't worry though, the implementation is not hard. 

#### Forward iterators 
- Doubly Linked List Iterator 
- Const Doubly Linked List Iterator
- These iterators move from the start of the list to the end of the list 

#### Reverse iterators
- Reverse Doubly Linked List Iterator 
- Const Reverse Doubly Linked List Iterator
- These iterators move from the end of the list to the start of the list 
- These iterators behave similarly to [std::vector's reverse iterators](http://www.cplusplus.com/reference/vector/vector/rbegin/) and I recommend you take a look over the example if you haven't done anything with reverse iterators before. 

### Exceptions
- The string returned by the what method can contain anything you want it to but make it relevant to the problem that is happening. 

 
#### Doubly Linked List Error
- A generic exception for representing an error that has occurred when working with a Doubly Linked List
- Inherits from: std::exception
- Thrown by: None

#### Doubly Linked List Empty Error
- An exception representing that the operation could not be done because the list is empty
- Inherits from: DoublyLinkedLIstError
- Thrown by: DoublyLinkedList::front and DoublyLinkedList::back


#### Doubly Linked List Out Of Bounds Error
- An exception representing that the operation could not be done because the iterator is out of bounds
- Inherits from: DoublyLinkedLIstError
- Thrown by: operator* in the iterators

## Testing
We will once again be using Google Test to test your program. 

## What to Submit
A zip file containing the **src** directory. Yes, you really are zipping the folder this time. 

## Hints
- Since you are writing templated code CLion might not be as helpful in suggesting autocompletes or might not be able to at all
- When you write templated code don't forget that the function definitions must also appear in the header file
- Since you are writing templated code, if you make an error the compiler will spit out a huge amount of errors. When trying to fix the errors start wit the first error and don't go past that. Fix that error then recompile and then go again. Keep doing this until all of the errors are fixed. 
- Be careful when doing things with the empty list, lists that only have a single item, operations that reduce the list to a single element, and operations that make the list empty
    - You will have to make sure to update head and tail correctly in these cases
- The test cases rely heavily on your iterators so make sure that they are correct. 


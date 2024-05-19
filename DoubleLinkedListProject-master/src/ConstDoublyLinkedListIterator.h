//
// Created by mfbut on 11/24/2019.
//

#ifndef DLLPROJECT_CONSTDOUBLYLINKEDLISTITERATOR_H
#define DLLPROJECT_CONSTDOUBLYLINKEDLISTITERATOR_H

#include <iterator>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedListOutOfBoundsError.h"

template<typename T>
class ConstDoublyLinkedListIterator {
 public:
  //type tags
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = T;
  using reference = const value_type&;
  using pointer = const value_type*;
  using difference_type = ptrdiff_t;

  //create an iterator starting at the specified node
  explicit ConstDoublyLinkedListIterator(const DoublyLinkedNode<T>* start);

  //set the iterator to be at null
  ConstDoublyLinkedListIterator();

  //copy constructor
  ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator<T>& orig);

  //are the two iterators equal?
  bool operator==(const ConstDoublyLinkedListIterator<T>& rhs) const;
  //are the two iterators different?
  bool operator!=(const ConstDoublyLinkedListIterator<T>& rhs) const;
  //is the iterator safe to dereference?
  explicit operator bool() const;

  //go to the next element
  ConstDoublyLinkedListIterator<T>& operator++(); //pre
  const ConstDoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  ConstDoublyLinkedListIterator<T>& operator--(); //pre
  const ConstDoublyLinkedListIterator<T> operator--(int); //post

  //get a reference to the value
  reference operator*() const;

 private:
  const DoublyLinkedNode<T>* curNode;
};

template<typename T>
ConstDoublyLinkedListIterator<T>::ConstDoublyLinkedListIterator(const DoublyLinkedNode<T>* start)  {
    *this = start.getPos();
}

template<typename T>
ConstDoublyLinkedListIterator<T>::ConstDoublyLinkedListIterator()  {
    *this = nullptr;
}

template<typename T>
ConstDoublyLinkedListIterator<T>::ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator<T>& orig) {
    ConstDoublyLinkedListIterator<T> copy(orig);
    return copy;
}

template<typename T>
bool ConstDoublyLinkedListIterator<T>::operator==(const ConstDoublyLinkedListIterator<T>& rhs) const {
    return curNode == rhs.curNode;
}

template<typename T>
bool ConstDoublyLinkedListIterator<T>::operator!=(const ConstDoublyLinkedListIterator<T>& rhs) const {
    return !(*this == rhs);
}

template<typename T>
ConstDoublyLinkedListIterator<T>::operator bool() const {
    return curNode != nullptr;
}

template<typename T>
ConstDoublyLinkedListIterator<T>& ConstDoublyLinkedListIterator<T>::operator++() {
    *this++;
    return curNode->getValue(*this);
}

template<typename T>
const ConstDoublyLinkedListIterator<T> ConstDoublyLinkedListIterator<T>::operator++(int) {
    *this++;
    return curNode->getValue(*this);
}

template<typename T>
ConstDoublyLinkedListIterator<T>& ConstDoublyLinkedListIterator<T>::operator--() {
    *this--;
    return curNode->getValue(*this);
}

template<typename T>
const ConstDoublyLinkedListIterator<T> ConstDoublyLinkedListIterator<T>::operator--(int) {
    *this--;
    return curNode->getValue(*this);
}

template<typename T>
typename ConstDoublyLinkedListIterator<T>::reference ConstDoublyLinkedListIterator<T>::operator*() const {
    if(*this) {
        return curNode->getValue();
    }else{
        throw DoublyLinkedListOutOfBoundsError();
    }
}



#endif //DLLPROJECT_CONSTDOUBLYLINKEDLISTITERATOR_H

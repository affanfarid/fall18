/*counter.h*/

//
// Affan Farid
// U. of Illinois, Chicago
// CS 341, Fall 2018
// Project #03: Counter container
//
// The Counter container is a set with no duplicates.  However, it keeps
// a count of how many times an element was inserted, hence the name
// "Counter".  Users of the Counter container can test for set membership,
// as well as obtain an element's count.
// 
// Example:  suppose C is a Counter, and you insert the elements 3, 11, 
// 5, 11, 3, and 11.  Then C contains the elements {3, 5, 11}, where 3's 
// count is 2, 5's count is 1, and 11's count is 3.
//
// Given N elements, search operations are O(lgN), and insert is O(N); these
// are average-time complexities.  In terms of space, the container will 
// consume at most 4N space.
// 

#pragma once

#include <iostream>
#include <iterator>

using std::cout;  // for debug printing:
using std::endl;


template<typename T>
class Counter
{
private:

  
  class iterator
  {
    public:
        typedef iterator self_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef int difference_type;
        iterator(pointer ptr) : ptr_(ptr) { }
        self_type operator++() { self_type i = *this; ptr_++; return i; }
        self_type operator++(int junk) { ptr_++; return *this; }
        reference operator*() { return *ptr_; }
        pointer operator->() { return ptr_; }
        bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
        bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
    private:
        pointer ptr_;
  };

  class elem{
    int position;
    T value;
    //int count;
    elem(T val, int pos){
      value = val;
      position = pos;
    }
    T getValue(){
      return value;
    }
    int getPosition(){
      return position;
    }

  };

  int sizeOfCounter;
  elem *array;
  int *countArray;
  int capacity;

public:
  
  //
  // constructor:
  //
  Counter()
  {
    capacity = 1000;
    array = new elem[capacity];
    sizeOfCounter =0;
    countArray = new int[capacity];
  }
  
  
  //
  // copy constructor:
  //
  Counter(const Counter& other)
  {
    for(int i = 0; i<sizeOfCounter; i++){
      other.insert(array[i].getValue());
    }
  }
  
  
  //
  // destructor:
  // 
  ~Counter()
  { 
    delete [] array;
    delete [] countArray;
    delete sizeOfCounter;
    array = NULL;
    countArray = NULL;
  }

  T* getArray(){
    return array;
  }

  T getArrayValue(int i){
    return array[i];
  }


  //
  // size()
  // 
  // Returns the # of elements in the set.
  // 
  // Time complexity: O(1).
  // 
  int size() const
  {
    return sizeOfCounter;
  }
  
  
  //
  // empty()
  //
  // Returns true if the set is empty, false if not.
  // 
  // Time complexity: O(1).
  // 
  bool empty() const
  {
    if (sizeOfCounter <= 0 ) return true;
    else return false;
  }
  
  
  //
  // clear()
  //
  // Empties the set, deleting all elements and counts.
  //
  void clear()
  {
    delete [] array;
    delete [] countArray;
    sizeOfCounter =0;
  }
  
  
  //
  // [e]
  //
  // Returns true if set contains e, false if not.
  //
  // NOTE: since the type of e is unknown, elements are compared using <. 
  // This implies 2 elements x and y are equal if (!(x<y)) && (!(y<x)).
  // 
  // Time complexity: average-case O(lgN).
  //
  bool operator[](const T& e)
  {

    int r = sizeOfCounter;
    int l = 0;
    while(1<=r){
      int m = l + (r-l)/2;

      if  (   !(array[m].getValue()<e) && !(e<array[m].getValue() )   )   {
        return true;
      }

      if( array[m] < e){
        l = m+1;
      }
      else{
        r = m-1;
      }

    }

    return false;
  }


  //
  // (e)
  // 
  // Returns a count of how many times e has been inserted into the set;
  // the count will be 0 if e has never been inserted.
  // 
  // NOTE: since the type of e is unknown, elements are compared using <. 
  // This implies 2 elements x and y are equal if (!(x<y)) && (!(y<x)).
  // 
  // Time complexity: average-case O(lgN).
  // 
  int operator()(const T& e) const
  { 

    int r = sizeOfCounter;
    int l = 0;
    while(1<=r){
      int m = l + (r-l)/2;

      if  (   !(array[m].getValue()<e) && !(e<array[m].getValue() )   )   {
        return countArray[m];
      }

      if( array[m] < e){
        l = m+1;
      }
      else{
        r = m-1;
      }

    }
    return -1;
  }
  
  
  //
  // insert(e)
  // 
  // If e is not a member of the set, e is inserted and e's count set to 0.
  // If e is already in the set, it is *not* inserted again; instead, e's
  // count is increased by 1.  Sets are unbounded in size, and elements are
  // inserted in order as defined by T's < operator; this enables in-order 
  // iteration.
  // 
  // NOTE: since the type of e is unknown, elements are compared using <. 
  // This implies 2 elements x and y are equal if (!(x<y)) && (!(y<x)).
  // 
  // Time complexity: worst-case O(N).
  // Space complexity: 4N.
  //
  void insert(const T& e)
  {

    sizeOfCounter++;

    //already exists
    for(int i = 0; i<sizeOfCounter; i++){
      if(!(array[i].getValue()<e) && !(e<array[i].getValue() )){
        countArray[i]++;
        return;
      }
    }

    //insert in order
    if(sizeOfCounter >= capacity){
      //dynamically grow
      elem* temp1;
      int* temp2;

      
      capacity *=2;

      temp1 = (elem*)realloc(array, sizeof(elem)*capacity);
      temp2 = (int*)realloc(array, sizeof(int)*capacity);

      delete [] array;
      delete [] countArray;

      array = temp1;
      countArray = temp2;
    }

    int j; 
    for (j=sizeOfCounter-1; ( j >= 0  && array[j].getValue() > e); j--) {
      array[j+1] = array[j]; 
      countArray[j+1] = countArray[j];
    }
    array[j+1] = elem(e,j);
    countArray[j+1] = 0;

  }
  
  
  // 
  // += e
  //
  // Inserts e into the set; see insert.
  //
  // Time complexity: worst-case O(N).
  // Space complexity: 4N.
  // 
  Counter& operator+=(const T& e)
  {
    //
    // insert e into "this" set:
    //
    this->insert(e);

    // return "this" updated set:
    return *this;
  }
  
  
  //
  // lhs = rhs;
  //
  // Makes a deep copy of rhs (right-hand-side) and assigns into
  // lhs (left-hand-side).  Any existing elements in the lhs
  // are destroyed *before* the deep copy is made.
  // 
  // NOTE: the lhs is "this" object.
  //
  Counter& operator=(const Counter& rhs)
  {
    //
    // NOTE: where is the lhs in the function call?  The lhs operand is 
    // hidden --- it's "this" object.  So think this->operator=(rhs).  
    //

    // check for self-assignment:
    if (this == &rhs)  // S = S;
      return *this;
    
    
    //
    // TODO
    //

    this->clear();
    //iterator iter = iterator(array);
    iterator iter1 = iterator(rhs.getArray());
    for(int i =0; i<rhs.size(); i++){
      this->insert(iter1->getArrayValue(i));
    }

    //
    // return "this" updated set:
    //
    return *this;
  }
  

  //
  // begin()
  // 
  // Returns an iterator denoting the first element of the set.  If the 
  // set is empty, begin() == end().  The iterator will advance through
  // the elements in order, as defined by T's < operator.
  //
  iterator begin()
  {
    return iterator(array[0]);
  }
  
  
  //
  // end()
  // 
  // Returns an iterator denoting the end of the iteration space --- i.e.
  // one past the last element of the set.  If the set is empty, then
  // begin() == end().
  // 
  iterator end()
  {
    return iterator(array[sizeOfCounter]);
  }

};

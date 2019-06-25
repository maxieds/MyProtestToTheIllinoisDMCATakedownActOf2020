// *******************************************************
// *                                                     *
// *  singly-linked-stack.h                              *
// *                                                     *
// *  Interface for a stack class, implemented via       *
// *    a singly-linked-list                             *
// *                                                     *
// *  Written February 1998 by Jason Zych                * 
// *    - slight edits done July 2001 by Jason Zych      *
// *                                                     *
// *******************************************************
 
#ifndef _STACK_H
#define _STACK_H

#include <stddef.h>


template <class Etype>
class Stack 
{
public:

 // *** Constructors and other assorted additions to core ADT

 
   // Stack
   //    - default constructor
   //    - initializes object to be an empty stack  
   Stack();

   
   // Stack
   //    - copy constructor
   //    - parameters : origVal - previously allocated Stack object
   //    - initializes object to be a copy of origVal
   Stack(const Stack& origVal); 


   // ~Stack
   //    - destructor
   //    - deletes dynamically allocated memory
   ~Stack(); 


   // operator=
   //    - parameters : origVal - previously allocated Stack object
   //    - return value : this Stack object, after assignment 
   //    - sets object to be equal to origVal 
   const Stack& operator=(const Stack& origVal); 


   // Size
   //    - return value : non-negative integer
   //    - returns the number of elements in the stack
   int Size() const;


   // Print
   //    - prints the values in the stack in order, starting
   //         from the top element
   void Print() const;


 
 // *** Functions in the core Stack ADT


   // Push
   //    - parameters : newElem - an element to be added to the stack
   //    - places newElem on top of stack 
   void Push(const Etype& newElem);


   // Pop
   //    - return value : a value of the type held in stack
   //    - removes and returns top element of stack. Assumes 
   //        stack is not empty; if the stack is indeed empty,
   //        an assertion is triggered.   
   Etype Pop(); 


   // Top
   //    - return value : a reference to a value in the stack
   //    - returns top element of stack, without removing it. Assumes
   //        stack is not empty; if the stack is indeed empty, an
   //        assertion is triggered. 
   const Etype& Top() const; 


   // Is_Empty
   //    - return value : boolean integer
   //    - returns 1 if stack is empty, 0 otherwise
   int IsEmpty() const; 

private:

   class StackNode
   {
   public:

      // StackNode
      //    - constructor
      //    - initializes element to default Etype, and next to NULL
      StackNode()  { next = NULL; }
  
      
      // StackNode
      //    - constructor
      //    - parameters : value - the value to store in the element field
      //    - initializes node to hold value and NULL
      StackNode(Etype value) { element = value; next = NULL; } 


      Etype element;       // holds element of node
      StackNode* next;     // pointer to the next node in the 
                           //   singly-linked list that will be built
   }; 

   StackNode* head;     // points to first (top) node of stack 
   int size;            // number of elements in stack
}; 


#endif 


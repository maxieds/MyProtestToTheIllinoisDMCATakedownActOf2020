// ********************************************************
// *                                                      *
// *   intarray.h                                         *     
// *                                                      *
// *   Interface for an integer array class               * 
// *                                                      *
// *   Modified from the generalized array class in       *
// *    array.h October 2004 by Jason Zych                *    
// *                                                      *    
// *    - changes by Jason Zych January 2005:             *
// *       - return type of const version of operator[]   *
// *           changed from "by const reference" to       *
// *           "by value"                                 *
// *                                                      *
// ********************************************************

#ifndef INTARRAY_225_H
#define INTARRAY_225_H

class IntArray
{
public:

   // IntArray
   //    - constructor
   //    - initializes object to be a zero-element array; low and high
   //        indices will be 0 and -1, respectively
   IntArray();


   // IntArray
   //    - constructor
   //    - parameters : low - desired lower bound of array
   //                 : high - desired higher bound of array
   //    - high is required to be greater than or equal to low - 1; if it
   //       is not, an assertion is triggered. Assuming high >= low - 1,
   //        initializes object to be a (high - low + 1)-element array; cells
   //        themselves are uninitialized. Note that if high == low - 1, then 
   //        the value of the expression high - low + 1 is 0 and we create an 
   //        IntArray object without any legal indices
   IntArray(int low, int high); 


   // IntArray
   //    - constructor
   //    - parameters : origVal - reference to previously-created IntArray
   //                    object; that IntArray object cannot be changed through
   //                    the parameter reference
   //    - initializes array to be a copy of origVal	
   IntArray(IntArray const & origVal);

 
   // ~IntArray
   //    - destructor
   //    - deletes dynamically allocated memory	
   ~IntArray(); 


   // operator=
   //    - parameters : origVal - reference to previously-created IntArray
   //                    object; that IntArray object cannot be changed through
   //                    the parameter reference
   //    - return value : reference to this IntArray object, after the
   //        operation has been performed; we cannot change this object
   //        through the returned reference
   //    - assigns this object to be a copy of origVal
   IntArray const & operator=(IntArray const & origVal);
 

   // operator[]
   //    - parameters : index - integer index into array
   //    - return type : copy of the value in the array cell at the   
   //                        parameter index
   //    - This version of the operator[] will be called on const objects.
   //       The parameter index is required to be a legal index into the
   //       array, i.e. lowerBound <= index and index <= upperBound. (Note 
   //       that for arrays of size 0, there *is* no legal index.) If the 
   //       index is NOT legal, an assertion is triggered. Otherwise, the 
   //       function returns a copy of the value in the array cell at the
   //       given index. (Since you return a copy of what is in the cell, 
   //       the value in the cell cannot be changed via the use of this 
   //       function.)
   int operator[](int index) const;					


   // operator[]
   //    - parameters : index - integer index into array
   //    - return type : reference to the array cell at the parameter index
   //    - This version of the operator[] will be called on non-const objects.
   //       The parameter index is required to be a legal index into the
   //       array, i.e. lowerBound <= index and index <= upperBound. (Note
   //       that for arrays of size 0, there *is* no legal index.) If the
   //       index is NOT legal, an assertion is triggered. Otherwise, the
   //       function returns a reference to the array cell at the given index.
   int & operator[](int index);


   // initialize
   //    - parameters : initElement - reference to object with which to 
   //                     initialize the array; that object cannot be
   //                     changed through the parameter reference
   //    - assigns each cell in the array to hold a copy of parameter value
   void initialize(int initElement);


   // setBounds
   //    - parameters : theLow - desired new lower bound of array
   //                 : theHigh - desired new upper bound of array
   //    - theHigh is required to be greater than or equal to theLow - 1;  
   //        if it is not, an assertion is triggered. Assuming 
   //        theHigh >= theLow - 1,assigns object to be a 
   //        (theHigh - theLow + 1)-element array. For any indices in 
   //        the array's new index range (theLow <= index <= theHigh) that 
   //        were also in the array's old index range 
   //        (lower() <= index <= upper()), the cells at those contain the 
   //        same values that they contained before this function was called. 
   //        For any indices in the array's new index range that were NOT 
   //        in the array's old index range, the cells at those indices are 
   //        uninitialized. For any indices in the array's old index range
   //        that are NOT indices in the array's new index range, the values 
   //        in the cells at those indices are lost, since we no longer have 
   //        cells with those indices in our array.
   void setBounds(int theLow, int theHigh);


   // size
   //    - return value : non-negative integer
   //    - returns size of array  
   int size() const; 


   // lower
   //    - return value : integer index
   //    - returns "lower bound" index of array. If array has size >= 1,
   //        this will be lowest legal index of array. If array is of 
   //        size 0, then this will be an integer one greater than the
   //        value returned by upper(), but will not be a legal index.
   int lower() const; 


   // upper
   //    - return value : integer index
   //    - returns "upper bound" of array. If array has size >= 1,
   //        this will be highest legal index of array. If array is of
   //        size 0, then this will be an integer one less than the
   //        value returned by lower(), but will not be a legal index.
   int upper() const; 


private:

   int lowerBound;  // lower bound 
   int upperBound;  // upper bound
   int * data; // Pointer to the array elements. 

};

#endif



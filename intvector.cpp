#include "intvector.h"

/*******************************************************************************
 * Constructor IntVector: Class IntVector
 *______________________________________________________________________________
 * This constructor sets size and capacity to 0. returns nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/

IntVector::IntVector()
{
    // PROCESSING - initialize size and capacity of array to 0
    sz = 0;
    cap = 0;
}

/*******************************************************************************
 * Constructor IntVector: Class IntVector
 *______________________________________________________________________________
 * This constructor sets size and cap to passed value and each element in array
 * to 0. returns nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      unsigned size: size of dynamic array
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/

IntVector::IntVector(unsigned size)     // IN - size of dynamic array
{
    // PROCESSING - set size and capacity to passed value
    sz = size;
    cap = size;
    // PROECSSING - initialize dynamic array
    data = new int[size];
    // PROCESSING - fill dynamic array with 0

    for(unsigned i = 0; i < size; i++)
    {
        data[i] = 0;
    }
}

/*******************************************************************************
 * Constructor IntVector: Class IntVector
 *______________________________________________________________________________
 * This constructor sets size and cap to passed value and each element in array
 * to passed value. returns nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      unsigned size: size of dynamic array
 *      int value    : number to go into each element
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/

IntVector::IntVector(unsigned size,         // IN - size of dynamic array
                     int value)             // IN - value for each element
{
    // PROCESSING - set size and capacity to passed value
    sz = size;
    cap = size;
    // PROECSSING - initialize dynamic array
    data = new int[size];

    // PROCESSING - fill dynamic array with passed value
    for(unsigned i = 0; i < size; i++)
    {
        data[i] = value;
    }
}

/*******************************************************************************
 * Copy Constructor IntVector: Class IntVector
 *______________________________________________________________________________
 * This copy constructor copys one IntVector obj to another including the
 * dynamic array. Returns new IntVector obj.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const IntVector & source: Passed IntVector object to copy dynamic array
 *
 * POST-CONDITIONS
 *      IntVector: new IntVector object copy
 ******************************************************************************/

IntVector::IntVector(const IntVector & source)  // IN - IntVector Object
{
    // PROCESSING - copy all private data to new IntVector
    sz = source.sz;
    cap = source.cap;
    data = new int[cap];
    // PROCESSING - parse dynamic array assign old to new
    for(unsigned i = 0; i < sz; i++) data[i] = source.data[i];
}

/*******************************************************************************
 * Destructor IntVector: Class IntVector
 *______________________________________________________________________________
 * This is the destructor for IntVecor Objects dynamic arrays. Returns nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/

IntVector::~IntVector()
{
    // PROCESSING - delete dynamic memory from heap
    delete[] data;
}

/*******************************************************************************
 * Method size: Class IntVector
 *______________________________________________________________________________
 * This method returns the current size of the dynamic array.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONS
 *      unsigned
 ******************************************************************************/

unsigned IntVector::size() const
{
    // PROCESSING - return size
    return sz;
}

/*******************************************************************************
 * Method capacity: Class IntVector
 *______________________________________________________________________________
 * This method returns the current capacity of the dynamic array.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONS
 *      unsigned
 ******************************************************************************/

unsigned IntVector::capacity() const
{
    // PROCESSING - return capacity
    return cap;
}

/*******************************************************************************
 * Method empty: Class IntVector
 *______________________________________________________________________________
 * This method returns true if the current size of the dynamic array is 0.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONS
 *      bool
 ******************************************************************************/

bool IntVector::empty() const
{
    // PROCESSING - return true if size is 0
    if(sz == 0) return true;
    else return false;
}

/*******************************************************************************
 * Method at: Class IntVector
 *______________________________________________________________________________
 * This method returns the current value in the dynamic array at the passed
 * value element.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      unsigned index: index for array
 *
 * POST-CONDITIONS
 *      const int &
 ******************************************************************************/

const int& IntVector::at(unsigned index) const      // IN - index of array
{
    // PROCESSING - return value stored in array[passed value] if within bounds
    if(index < sz) return data[index];
}

/*******************************************************************************
 * Method front: Class IntVector
 *______________________________________________________________________________
 * This method returns the current value in the first element of the array.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      const int &
 ******************************************************************************/

const int& IntVector::front() const
{
    // PROCESSING - returning data
    return data[0];
}

/*******************************************************************************
 * Method back: Class IntVector
 *______________________________________________________________________________
 * This method returns the current value in the last element of the array.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      const int &
 ******************************************************************************/

const int& IntVector::back() const
{
    // PROCESSING - returning data
    return data[sz-1];
}

/*******************************************************************************
 * Method expand: Class IntVector
 *______________________________________________________________________________
 * This method increases the capacity of the dynamic array by double.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      none
 ******************************************************************************/

void IntVector::expand()
{
    // PROCESSING - reallocate dynamic memory for new array
    int * temp = new int[cap];
    for(unsigned i = 0; i < cap; i++) temp[i] = data[i];
    cap *= 2;
    data = new int[cap];
    for(unsigned i = 0; i < cap/2; i++) data[i] = temp[i];
    delete[] temp;
}

/*******************************************************************************
 * Method expand: Class IntVector
 *______________________________________________________________________________
 * This method increases the capacity of the dynamic array by the passed value.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      unsigned amount
 *
 * POST-CONDITIONS
 *      none
 ******************************************************************************/

void IntVector::expand(unsigned amount)     // IN - amount to expand cap by
{
    // PROCESSING - reallocate dynamic memory for new array
    int * temp = new int[cap];
    for(unsigned i = 0; i < cap; i++) temp[i] = data[i];
    cap += amount;
    data = new int[cap];
    for(unsigned i = 0; i < cap; i++) data[i] = temp[i];
    delete[] temp;
}

/*******************************************************************************
 * Method insert: Class IntVector
 *______________________________________________________________________________
 * This method insters the passed value into the array at the passed index.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      unsigned index, int value
 *
 * POST-CONDITIONS
 *      none
 ******************************************************************************/

void IntVector::insert(unsigned index,      // IN - index of array
                       int value)           // IN - value to insert
{
    // PROECSSING - only allow valid input
    if(index > sz)
    {
        exit(1);
    }
    else
    {
        // PROCESSING - expand if size is at capacity
        if(sz == cap)
        {
            expand();
        }
        for(unsigned i = sz; i >= index; i--)
        {
            // PROECSSING - shift
            data[i+1] = data[i];
        }
        sz += 1;
        // PROCESSING - insert
        data[index] = value;
    }
}

/*******************************************************************************
 * Method erase: Class IntVector
 *______________________________________________________________________________
 * This method erases the element at the passed index.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      unsigned index
 *
 * POST-CONDITIONS
 *      none
 ******************************************************************************/

void IntVector::erase(unsigned index)       // IN - Index of array
{
    // PROCESSING - only valid input
    if(index > sz)
    {
        exit(1);
    }
    else
    {
        // PROCESSING - shift and resize
        for(unsigned i = index; i <= sz; i++)
        {
            data[i] = data[i+1];
        }
        sz -= 1;
    }
}

/*******************************************************************************
 * Method push_back: Class IntVector
 *______________________________________________________________________________
 * This method adds the passed value to the end of the array.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      int value
 *
 * POST-CONDITIONS
 *      none
 ******************************************************************************/

void IntVector::push_back(int value)        // IN - value to store
{
    // PROCESSING - expand if size reaches capacity
    if(cap == 0) expand(1);
    if(sz == cap)
    {
        expand();
    }
    // PROCESSING - set net value
    data[sz] = value;
    sz++;
}

/*******************************************************************************
 * Method pop_back: Class IntVector
 *______________________________________________________________________________
 * This method removes the element at the end of the array.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      none
 ******************************************************************************/

void IntVector::pop_back()
{
    // PROCESSING - remove last element
    sz--;
}

/*******************************************************************************
 * Method clear: Class IntVector
 *______________________________________________________________________________
 * This method empties the array.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      none
 ******************************************************************************/

void IntVector::clear()
{
    // PROCESSING - clear array
    sz=0;
}

/*******************************************************************************
 * Method resize: Class IntVector
 *______________________________________________________________________________
 * This method changes the size of the array by the passed value any new elemnts
 * are set to 0.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      unsigned size
 *
 * POST-CONDITIONS
 *      none
 ******************************************************************************/

void IntVector::resize(unsigned size)       // IN - new size of array
{
    // PROCESSING - don't expand if less than capacity
    if(size < cap)
    {
        if(size > sz)
        {
            // PROCESSING - set new elements to 0
            int hold = sz;
            sz = size;
            for(unsigned i = hold; i < sz; i++) data[i] = 0;
        }
        else
        {
            sz = size;
        }
    }
    else
    {
        // PROCESSING - expand if size is over cap
        expand();
        int hold = sz;
        sz = size;
        for(unsigned i = hold; i < sz; i++) data[i] = 0;
    }
}

/*******************************************************************************
 * Method resize: Class IntVector
 *______________________________________________________________________________
 * This method changes the size of the array by the passed value any new elemnts
 * are set to the passed value.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      unsigned size, int value
 *
 * POST-CONDITIONS
 *      none
 ******************************************************************************/

void IntVector::resize(unsigned size,       // IN - new size of array
                       int value)           // IN - value to store in array
{
    // PROCESSING - don't expand if less than capacity
    if(size < cap)
    {
        if(size > sz)
        {
            // PROCESSING - set new elements to passed value
            int hold = sz;
            sz = size;
            for(unsigned i = hold; i < sz; i++) data[i] = value;
        }
        else
        {
            sz = size;
        }
    }
    else
    {
        // PROCESSING - expand if size is over cap
        expand();
        int hold = sz;
        sz = size;
        for(unsigned i = hold; i < sz; i++) data[i] = value;
    }
}

/*******************************************************************************
 * Method reserve: Class IntVector
 *______________________________________________________________________________
 * This method changes the capacity of the array by the passed value.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      unsigned n
 *
 * POST-CONDITIONS
 *      none
 ******************************************************************************/

void IntVector::reserve(unsigned n)         // IN - new capacity of array
{
    // PROCESSING - only change cap if input is over current cap
    if(n > cap)
    {
        // PROCESSING - copy over to new array
        int * temp = new int[cap];
        for(unsigned i = 0; i < cap; i++) temp[i] = data[i];
        if(n > (cap*2)) expand(n-cap);
        else expand();
        data = temp;
        // PROCESSING - copy back to original bigger
    }
}

/*******************************************************************************
 * Method assign: Class IntVector
 *______________________________________________________________________________
 * This method resets the array to a new size and value passed in.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      unsigned size, int value
 *
 * POST-CONDITIONS
 *      none
 ******************************************************************************/

void IntVector::assign(unsigned size,       // IN - new size of array
                       int value)           // IN - value to store in array
{
    // PROCESSING - increase capacity if passed size is larger
    if(size > cap)
    {
        expand(size-cap);
        sz = size;
        for(unsigned i = 0; i < size; i++) data[i] = value;
    }
    else
    {
        //PROCESSING - execute if now cap increase
        sz = size;
        for(unsigned i = 0; i < size; i++) data[i] = value;
    }
}

/*******************************************************************************
 * Method at: Class IntVector
 *______________________________________________________________________________
 * This method returns the value stored in the array at the passed index.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      unsigned index
 *
 * POST-CONDITIONS
 *      int &
 ******************************************************************************/

int& IntVector::at(unsigned index)          // IN - index of array
{
    // PROCESSING - return value
    if(index < sz) return data[index];
    else exit(1);
}

/*******************************************************************************
 * Method front: Class IntVector
 *______________________________________________________________________________
 * This method returns the value stored in the first element of the array.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      int &
 ******************************************************************************/

int& IntVector::front()
{
    // PROCESSING - returning data
    return data[0];
}

/*******************************************************************************
 * Method back: Class IntVector
 *______________________________________________________________________________
 * This method returns the value stored in the last element of the array.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      int &
 ******************************************************************************/

int& IntVector::back()
{
    // PROCESSING - returning data
    return data[sz-1];
}

/*******************************************************************************
 * Method operator=: Class IntVector
 *______________________________________________________________________________
 * This is the overloaded asigment operator.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const IntVector &
 *
 * POST-CONDITIONS
 *      IntVector &
 ******************************************************************************/

IntVector& IntVector::operator=(const IntVector & source) // IN - IntVector OBJ
{
    // PROCESSING - self assignment check
    if(this == &source)
    {
        return *this;
    }

    // PROCESSING - assignment
    sz = source.sz;
    cap = source.cap;
    for(unsigned i = 0; i < sz; i++) data[i] = source.data[i];

    // PROCESSING - returnqww
    return *this;
}

IntVector& IntVector::operator+=(const IntVector &source) {
    sz += source.sz;
    unsigned addOnPoint = cap;

    if (sz > cap)
        this->expand(); // expand capacity if concatenation exceeds cap

    for (unsigned i = addOnPoint, j = 0; i < sz && j < (sz - addOnPoint); i++, j++) {
        data[i] = source.data[j];
    }

    return *this;
}


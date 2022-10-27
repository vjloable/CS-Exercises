#include <iostream>
#include <assert.h>

using namespace std;

template <class E>
struct DLink
{
    E theElement;
    DLink<E> *nextPtr;
    DLink<E> *prevPtr;
};

template <class E>
class DList
{
    DLink<E> *head;
    DLink<E> *tail;
    DLink<E> *curr;
    int cnt;

public:
    // Return the size of the list
    int length() const
    {
        return cnt;
    }

    // The constructor with initial list size
    DList(int size)
    {
        this();
    }

    // The default constructor
    DList()
    {
        head = nullptr;
        tail = nullptr;
        curr = nullptr;
        cnt = 0;
    }

    // The copy constructor
    DList(const DList &source)
    {
        this->head = source.head;
        this->tail = source.tail;
        this->curr = source.curr;
        this->cnt = 0;
    }

    // The class destructor
    ~DList()
    {
        
    }

    // Empty the list
    void clear()
    {

    }

    // Set current to first element
    void moveToStart()
    {
        curr = head;
    }

    // Set current element to end of list
    void moveToEnd()
    {
        curr = tail;
    }

    // Advance current to the next element
    void next()
    {
        curr = curr->nextPtr;
    }

    // Return the current element
    E &getValue() const
    {
        return *(this->curr->theElement);
    }

    // Insert value at current position
    void insert(const E &it)
    {
        //
        // ??? - implement this method
        //
    }

    // Append value at the end of the list
    void append(const E &it)
    {
        curr = new DLink<E>();
        curr->theElement = *it;
        if (this->head == nullptr && cnt == 0)
        {
            this->head = curr;
            this->tail = curr;
            curr->nextPtr = this->head;
            curr->prevPtr = this->tail;
        } 
        else
        {
            DLink<E> *temp;
            temp = this->tail;
            this->tail = curr;
            temp->nextPtr = this->tail;
            this->tail->prevPtr = temp;
            this->tail->nextPtr = this->head;
            this->head->prevPtr = this->tail;
        }
        ++cnt;
    }

    // Remove and return the current element
    E remove()
    {
        DLink<E> *tempPrev, *tempNext;
        E e;
        tempPrev = curr->prevPtr;
        tempNext = curr->nextPtr;
        e = curr->theElement;
        delete curr;
        --cnt;
        tempPrev->nextPtr = tempNext;
        tempNext->prevPtr = tempPrev;
        return e;

    }

    // Advance current to the previous element
    void prev()
    {
        curr = curr->prevPtr;
    }

    // Return position of the current element
    int currPos() const
    {
        //
        // ??? - implement this method
        //
    }

    // Set current to the element at the given position
    void moveToPos(int pos)
    {
        DLink<E> *newPos, *temp;
        for(int p = 0; p < pos; ++p){
            head
        }
    }
};

/*
This is the main function for testing the implementation of the DList class.
This function can be freely modified.
*/
int main(void)
{
    int i;
    DList<int> theList;

    // populate the list
    for (i = 0; i < 10; ++i)
    {
        theList.append(i);
    }
    while (i < 20)
    {
        theList.insert(i);

        ++i;
    }

    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i)
    {
        cout << theList.getValue() << " ";

        theList.next();
    }
    cout << "\n";

    // display the contents of the list in reverse order
    theList.moveToEnd();
    for (i = 0; i < theList.length(); ++i)
    {
        theList.prev();

        cout << theList.getValue() << " ";
    }
    cout << "\n";

    // replace the contents of the list
    theList.clear();
    for (i = 0; i < 10; ++i)
    {
        theList.append(i + 100);
    }

    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i)
    {
        cout << theList.getValue() << " ";

        theList.next();
    }
    cout << "\n";

    // remove two elements at the specified position
    theList.moveToPos(5);
    cout << theList.currPos() << "\n";

    theList.remove();
    theList.remove();

    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i)
    {
        cout << theList.getValue() << " ";

        theList.next();
    }
    cout << "\n";

    return 0;
}
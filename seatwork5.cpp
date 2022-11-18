#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

template <class E>
struct DLink
{
    E theElement;
    DLink<E> *nextPtr;
    DLink<E> *prevPtr;
};

/*
Complete this implementation variant of the doubly-linked list. Use the same
convention as described in the slides. The DLink declaration to be used here is
just a struct and should not be modified in any way. All of the operations of
the original DLink class must be done in the methods of this class. Use
assertions to ensure the correct operation of this ADT. All memory allocations
should be checked with assertions and all discarded memory must be properly
deallocated.
*/
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
        head = new DLink<E>();
        tail = new DLink<E>();
        head->nextPtr = tail;
        tail->prevPtr = head;
        tail->nextPtr = nullptr;
        head->prevPtr = nullptr;
        curr = head;
        cnt = 0;
    }

    // The copy constructor
    DList(const DList &source)
    {
        this->head = source.head;
        this->tail = source.tail;
        this->curr = source.curr;
    }

    // The class destructor
    //~DList()
    //{
        ///~(this->head);
        ///~(this->tail);
        ///~(this->curr);
    //}

    // Empty the list
    // void clear()
    // {
        
    // }

    // Set current to first element
    void moveToStart()
    {
        this->curr = this->head;
    }

    // Set current element to end of list
    void moveToEnd()
    {
        this->curr = this->tail;
    }

    // Advance current to the next element
    void next()
    {
        (curr->nextPtr != NULL) ? curr = curr->nextPtr : curr = curr;
    }

    // Return the current element
    E &getValue() const
    {
        return this->curr->nextPtr->theElement;
    }

    // Insert value at current position
    void insert(const E &it)
    {
        DLink<E> *entry = new DLink<E>();
        entry->theElement = it;

        entry->nextPtr = curr->nextPtr;
        entry->prevPtr = curr;
        curr->nextPtr->prevPtr = entry;
        curr->nextPtr = entry;

        cnt++;

        // cout << endl;
        // cout << "PREV PTR: " << curr->prevPtr << endl;
        // cout << "CUR [PTR-VALUE]: " << curr << " - " << curr->theElement << endl;
        // cout << "NEXT PTR: " << curr->nextPtr << endl;
        // cout << endl;

    }

    // Append value at the end of the list
    // void append(const E &it)
    // {
    //     DLink<E> *entry = new DLink<E>();
    //     entry->theElement = it;

    //     DLink<E> *prevTail = tail->prevPtr;
    //     prevTail->nextPtr = entry;
    //     entry->prevPtr = tail->prevPtr;
    //     entry->nextPtr = tail;
    //     tail->prevPtr = entry;
        
    //     ++cnt;
    // }

    // Remove and return the current element
    E remove()
    {
        DLink<E> *temp = curr->nextPtr;    
        E tempE = temp->theElement;

        curr->nextPtr = temp->nextPtr;
        temp->nextPtr->prevPtr = curr;
        delete temp;
        
        return tempE;
    }

    // Advance current to the previous element
    // void prev()
    // {
    //     curr = curr->prevPtr;
    // }

    void debug()
    {
        cout << endl;

        DLink<E> *temp = head;

        cout << "CURRENT POINTER: " << ((temp == head) ? "HEAD" : (temp == tail) ? "TAIL" : to_string(temp->theElement)) << "\n"<< endl;
        
        int index = -1;

        string tb = "         .------------.\n     ";
        string bb = "         '------------'";
        string ca = "    |  ";
        string cb = "  |";
        string al = "             ^    .\n             |    |\n    ";
        string ac = " |    | ";
        string ar = "\n             |    |\n             '    v";
        while (temp != nullptr)
        {
            cout << tb << ca << temp << cb + " = " << ((temp == head) ? "HEAD" : (temp == tail) ? "TAIL" : ("i " + to_string(index) + ": " + to_string(temp->theElement))) << "\n" + bb << endl;
            (temp != tail) ? (cout << al << temp << ac << temp->nextPtr << ar << endl) : (cout << endl);
            
            temp = temp->nextPtr;
            index++;
        }
    }
    /*
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
    }*/
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
    for (i = 0; i < 5; ++i)
    {
        theList.insert(i+50);
    }

    theList.debug();
    cout << theList.remove() << endl;
    cout << theList.remove() << endl;
    cout << theList.remove() << endl;
    theList.debug();
    // cout << "------------" << endl;
    // cout << theList.remove() << endl;
    // theList.debug();

    // while (i < 20)
    // {
    //     theList.insert(i);

    //     ++i;
    // }

    //theList.debug();                

    // display the contents of the list
        // theList.moveToStart();
        // for (i = 0; i < theList.length(); ++i)
        // {
        //     cout << theList.getValue() << " ";

        //     theList.next();
        // }
        // cout << "\n";
    /*
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
    */
    return 0;
}


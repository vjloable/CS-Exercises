#include <iostream>
#include <assert.h>
#include <string>
#include <sstream>
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

private:
    string spacer(int x)
    {
        string cc = "";
        for (int y = x - 7; y > 0; y--)
        {
            cc += " ";
        }
        return cc;
    }

    string dasher(int x)
    {
        string cc = "";
        for (int y = x - 7; y > 0; y--)
        {
            cc += "-";
        }
        return cc;
    }

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
        this->head = new DLink<E>();
        this->tail = new DLink<E>();
        this->head->nextPtr = this->tail;
        this->tail->prevPtr = this->head;
        this->tail->nextPtr = nullptr;
        this->head->prevPtr = nullptr;
        this->curr = this->head;
        this->cnt = 0;
        cout << "\n\n\n" << "Object created!\n\n\n"; 
    }

    // The copy constructor
    DList(const DList &source)
    {
        this->head = source.head;
        this->tail = source.tail;
        this->curr = source.curr;
        this->cnt = source.cnt;
    }

    // The class destructor
    ~DList()
    {
        cout << "\n\n\n" << "Object destroyed!\n\n\n"; 
        this->clear();
        delete this->head;
        delete this->tail;
    }

    // Empty the list
    void clear()
    {
        if (this->cnt > 0)
        {
            this->moveToStart();
            while (this->cnt != 0)
            {
                this->remove();
            }
        }
    }

    // Set current to first element
    void moveToStart()
    {
        this->curr = this->head;
    }

    // Set current element to end of list
    void moveToEnd()
    {
        (this->cnt > 0) ? this->curr = this->tail->prevPtr : this->curr = this->curr;
    }

    // Advance current to the next element
    void next()
    {
        (this->curr->nextPtr != nullptr) ? this->curr = this->curr->nextPtr : this->curr = this->curr;
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

        entry->nextPtr = this->curr->nextPtr;
        entry->prevPtr = this->curr;
        this->curr->nextPtr->prevPtr = entry;
        this->curr->nextPtr = entry;

        this->cnt++;
    }

    // Append value at the end of the list
    void append(const E &it)
    {
        DLink<E> *entry = new DLink<E>();
        entry->theElement = it;

        this->tail->prevPtr->nextPtr = entry;
        entry->prevPtr = this->tail->prevPtr;
        entry->nextPtr = this->tail;
        this->tail->prevPtr = entry;

        this->cnt++;
    }

    // Remove and return the current element
    E remove()
    {
        E tempE;
        DLink<E> *temp;
        if (this->cnt > 0)
        {
            if (this->curr->nextPtr == tail)
            {
                return E(NULL);
            }
            else
            {
                temp = this->curr->nextPtr;
                tempE = temp->theElement;
                //-----------------------------------cout<<"TEST             "<<this->curr<<endl;
                this->curr->nextPtr->nextPtr->prevPtr = this->curr;
                this->curr->nextPtr = curr->nextPtr->nextPtr;
            }
            delete temp;
            this->cnt--;
        }
        return tempE;
    }

    // Advance current to the previous element
    void prev()
    {
        (this->curr->prevPtr != nullptr) ? this->curr = this->curr->prevPtr : this->curr = this->curr;
    }

    
    // Return position of the current element
    int currPos() const
    {
        DLink<E> *temp = this->head;
        int index = -1;
        while (temp != nullptr && temp != this->curr)
        {
            temp = temp->nextPtr;
            index++;
        }
        return index;
    }

    // Set current to the element at the given position
    void moveToPos(int pos)
    {
        if(pos < (this->cnt) && pos >= 0){
            DLink<E> *temp = this->head;
            int index = -1;
            while (index != cnt)
            {
                if(index == pos){
                    curr = temp;
                    break;
                }
                temp = temp->nextPtr;
                index++;
            }
        }   
    }

    void debug()
    {
        cout << endl;
        DLink<E> *temp = head;
        int index = -1;
        int tempindex = 0;
        string tb = "    .-----------";
        string tl = ".\n";
        string bb = "    '-----------";
        string bl = "'";
        string ca = "    |  ";
        string cb = "  |";
        string al = "        ^    .\n";
        string tc = "        |    |\n";
        string ac = " |    | ";
        string ar = "        '    v";
        string xx = "";
        string xy = "";
        string xz = "";
        while (temp != nullptr)
        {
            ostringstream oss;
            oss << curr;
            string s(oss.str());
            int space = (((s + " ").length()) - 1);
            xz = (curr == temp ? "  <-- CURR" : " ");
            cout << spacer(space) << tb << dasher(space) << tl << spacer(space) << ca << temp << cb + " = " << ((temp == head) ? "HEAD" : (temp == tail) ? "TAIL" : ("POS " + to_string(index) + ": " + to_string(temp->theElement))) << xz << "\n" + spacer(space) + bb << dasher(space) << bl << endl;
            (temp != tail) ? (cout << spacer(space) << al << spacer(space) << tc << temp << ac << temp->nextPtr << "\n" << spacer(space) << tc << spacer(space) << ar << endl): (cout << endl);
            if (temp == curr) {
                tempindex = index;
            }
            xx = ((curr == head) ? " - HEAD" : (curr == tail) ? " - TAIL" : " - ITEM");
            xy = (curr != head && curr != tail) ? (" at POSITION ") : xy;

            temp = temp->nextPtr;
            index++;
        }

        cout << "CURRENT POINTER: " << curr;
        if (curr != head && curr != tail) {
            cout << xx << xy << tempindex << endl;
        }else
        {
            cout << xx << xy << endl;
        }
        cout << "NUMBER OF ITEMS: " << cnt << "\n\n\n\n" << endl;
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
    
    theList.debug(); //-----------------------------------------------------   DEBUG
    // populate the list
    for (i = 0; i < 10; ++i)
    {
        theList.insert(i+50);
    };

    while (i < 20)
    {
        theList.insert(i);

        ++i;
    }
    
    theList.debug(); //-----------------------------------------------------   DEBUG
    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i)
    {
        
        cout << theList.getValue() << " ";
        theList.next();
    }
    cout << "\n";

    theList.debug(); //-----------------------------------------------------   DEBUG
    // display the contents of the list in reverse order
    theList.moveToEnd();
    for (i = 0; i < theList.length(); ++i)
    {
        theList.prev();

        cout << theList.getValue() << " ";
    }
    cout << "\n";

    theList.debug(); //-----------------------------------------------------   DEBUG
    // // replace the contents of the list
    theList.clear();
    theList.debug(); //-----------------------------------------------------   DEBUG
    for (i = 0; i < 10; ++i)
    {
        theList.append(i + 100);
    }

    theList.debug(); //-----------------------------------------------------   DEBUG
    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i)
    {
        cout << theList.getValue() << " ";

        theList.next();
    }
    cout << "\n";
    theList.debug(); //-----------------------------------------------------   DEBUG

    // remove two elements at the specified position
    theList.moveToPos(5);
    theList.debug(); //-----------------------------------------------------   DEBUG
    
    cout << theList.currPos() << "\n";

    theList.remove();
    theList.remove();
    theList.debug(); //-----------------------------------------------------   DEBUG

    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i)
    {
        cout << theList.getValue() << " ";

        theList.next();
    }
    cout << "\n";
    theList.debug(); //-----------------------------------------------------   DEBUG

    return 0;
}


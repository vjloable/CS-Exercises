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
        this->cnt = source.cnt;
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
        (cnt > 0) ? curr = this->tail->prevPtr : curr = curr;
    }

    // Advance current to the next element
    void next()
    {
        (curr->nextPtr != nullptr) ? curr = curr->nextPtr : curr = curr;
    }

    // Return the current element
    E &getValue() const
    {
        return curr->nextPtr->theElement;
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
    }

    // Append value at the end of the list
    void append(const E &it)
    {
        DLink<E> *entry = new DLink<E>();
        entry->theElement = it;

        tail->prevPtr->nextPtr = entry;
        entry->prevPtr = tail->prevPtr;


        cnt++;
    }

    // Remove and return the current element
    E remove()
    {
        E tempE;
        DLink<E> *temp;
        if(cnt > 0){
            if(curr->nextPtr == tail){
                return E(NULL);
                // temp = curr->prevPtr;
                // tempE = curr->theElement;
                // temp->nextPtr = tail;
                // tail->prevPtr = temp;
                // temp = curr;
            } else {
                // temp = curr->nextPtr;
                // tempE = temp->theElement;
                // curr->nextPtr = temp->nextPtr;
                // temp->nextPtr->prevPtr = curr;
                temp = curr->nextPtr;
                tempE = temp->theElement;
                temp->nextPtr->prevPtr = curr;
                curr->nextPtr = temp->nextPtr;
            }
            delete temp;
            cnt--;
        }
        return tempE;
    }

    // Advance current to the previous element
    void prev()
    {
        (curr->prevPtr != nullptr) ? curr = curr->prevPtr : curr = curr;
    }

    
    // Return position of the current element
    int currPos() const
    {
        DLink<E> *temp = head;
        int index = -1;
        while (temp != nullptr && temp != curr){
            ///                           cout << index << "-   "<< temp << " == " << curr << endl;
            temp = temp->nextPtr;
            index++;
        }
        return index;
    }

    // Set current to the element at the given position
    // void moveToPos(int pos)
    // {
    //     DLink<E> *newPos, *temp;
    //     for(int p = 0; p < pos; ++p){
    //         head
    //     }
    // }

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
        cout << "NUMBER OF ITEMS: " << cnt << endl;
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
    // for (i = 0; i < 5; ++i)
    // {
    //     theList.insert(i+50);
    // };
    theList.moveToEnd();
    theList.debug();
    theList.remove();
    theList.debug();


    // while (i < 20)
    // {
    //     theList.insert(i);

    //     ++i;
    // }

    // theList.debug();                

    // // display the contents of the list
    // theList.moveToStart();
    // for (i = 0; i < theList.length(); ++i)
    // {
        
    //     cout << theList.getValue() << " ";
    //     theList.next();
    // }
    // cout << "\n";

    // theList.debug();
    // // display the contents of the list in reverse order
    // theList.moveToEnd();
    // for (i = 0; i < theList.length(); ++i)
    // {
    //     theList.prev();

    //     cout << theList.getValue() << " ";
    // }
    // cout << "\n";


    // ////////////////cout << theList.currPos() << endl;
    // replace the contents of the list
    // theList.clear();
    // for (i = 0; i < 10; ++i)
    // {
    //     theList.append(i + 100);
    // }

    // display the contents of the list
    // theList.moveToStart();
    // for (i = 0; i < theList.length(); ++i)
    // {
    //     cout << theList.getValue() << " ";

    //     theList.next();
    // }
    // cout << "\n";

    // remove two elements at the specified position
    // theList.moveToPos(5);
    // cout << theList.currPos() << "\n";

    // theList.remove();
    // theList.remove();

    // // display the contents of the list
    // theList.moveToStart();
    // for (i = 0; i < theList.length(); ++i)
    // {
    //     cout << theList.getValue() << " ";

    //     theList.next();
    // }
    // cout << "\n";
    
    return 0;
}


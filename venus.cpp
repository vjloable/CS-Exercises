#include <iostream>
#include <cassert>
using namespace std;

struct link
{
    int value;
    link *nextlink;
};

int main(void)
{
    int i;
    link *head = new link();
    assert(head != NULL);

    head->value = 20;
    head->nextlink = NULL;

    for (i = 19; i > 0; --i)
    {
        link *tempPtr = new link();
        assert(tempPtr != NULL);
        tempPtr->value = i;
        tempPtr->nextlink = head;
        head = tempPtr;
    }

    link *valDisplay = head;
    for (i = 0; i < 19; ++i)
    {
        cout << valDisplay->value << " ";
        valDisplay = valDisplay->nextlink;
        if (valDisplay == NULL)
        {
            valDisplay = head;
        }
    }
    cout << endl;

    link *valDisplay2 = head;
    link *temp;
    for (i = 20; i > 0; --i)
    {
        temp = valDisplay2->nextlink;

        delete valDisplay2;
        valDisplay2 = temp;
    }

    return 0;
}

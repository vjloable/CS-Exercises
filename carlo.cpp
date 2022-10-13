#include <iostream>

using namespace std;

struct link
{
    int value;
    link *next;
};

int main()
{
    int num_node = 4;
    int num_display = 20;

    link *head = NULL;
    link *tail = NULL;

    for (int i = 1; i < num_node; i++)
    {
        link *newnode = new link();
        if (head == NULL)
        {
            head = newnode;
        }

        newnode->value = i;

        if (newnode->next == NULL)
        {
            newnode->next = head;
        }
        if (tail != NULL)
        {
            tail->next = newnode;
        }
        tail = newnode;
    }

    link *arrow = head;
    for (int i = 0; i < num_display; ++i)
    {
        cout << arrow->value << "  ";
        arrow = arrow->next;
    }

    link *arrow2 = head;
    link *temp;
    for (int i = 1; i <= num_node; i++)
    {
        temp = arrow2->next;
        delete arrow2;
        arrow2 = temp;
    }

    return 0;
}
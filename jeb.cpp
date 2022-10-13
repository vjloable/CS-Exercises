#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main(){
    int x = 5;
    int y = 21;

    Node *head = new Node();
    head->data = 1;
    head->next = head;
    Node *tail;
    for (int i = 2; i <= x; i++) {
        if (head->next == head){
            tail = head;
        }
        Node *tempNode = new Node();
        tempNode->data = i;
        tail->next = tempNode;
        tempNode->next = head;
        tail = tempNode;
    }

    Node *temp1 = head;
    for (int i = 0; i < y; i++) {
        cout << temp1->data << "  >>>  ";
        temp1 = temp1->next;
    }

    Node *temp2;
    for (int i = 1; i <= x; i++) {
        temp2 = head->next;
        delete head;
        head = temp2;
    }

    return 0;
}

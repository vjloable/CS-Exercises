#include <iostream>
using namespace std;

struct link
{
    int value;
    link *next = NULL;
};

int main(){
    link *head = NULL;
    link *anchor = NULL;
    for(int i=1;i<=3;i++){
        link newnode = new link();
        if(head == NULL){
            head = newnode;
        }
        newnode->value = i;
        if(anchor->nextnode == &head){
            
        }
        if(newnode->nextnode == NULL{
            newnode->nextnode = &head;
        }
        anchor = &newnode;
    }
    /*
    link one, two, three;
    one.value = 1;
    one.next = &two;
    two.value = 2;
    two.next = &three;
    three.value = 3;
    three.next = &one;

    link *cursor = &one;
    for(int i = 0; i<60; ++i){
        cout<<cursor->value<<" ";
        cursor = cursor->next;
    }
    */
    return 0;
}
#include <iostream>
using namespace std;
/*
struct node {
    int value;
    node *newNode;
    };

int main(){
    int loop = 3;

    node *head = new (node);
    head->value = 1;
    head->newNode = NULL;

    node *ptr = head;

    for (int i = 1; i < loop; i++) 
    {
        ptr->newNode = new (node);
        ptr->newNode->value = i + 1;
        ptr->newNode->newNode = NULL;
        ptr = ptr->newNode;
    }

    
    ptr->newNode = head;
    ptr = head;

    for (int i = 1; i <= 30; i++){
        cout << ptr->value << " "<<endl;
        ptr = ptr->newNode;
    }
        
    delete head;

    return 0;
}
*/

struct link
{
    int value;
    link *next;
};

int main(){
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
    return 0;
}
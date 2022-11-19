//  VINCE JAPHETH F. LOABLE    2021-1910 

#include <iostream>
using namespace std;

struct Link
{
    int value;
    Link *next = NULL;
};

int main(){
    //CONSTS
    int num_nodes = 3;
    int num_disp = 19;
    cout << "Input the number of nodes to produce: ";
    cin >> num_nodes;
    cout << "Input the max number of nodes to display: ";
    cin >> num_disp;
    
    //IMPLEMENTATION
    Link *head = NULL;
    Link *anchor = NULL;
    for (int i = 1; i <= num_nodes; i++)
    {
        Link *newnode = new Link();
        if(head == NULL){
            head = newnode;
        }
        newnode->value = i;
        
        if (newnode->next == NULL)
        {
            newnode->next = head;
        }
        if(anchor != NULL){
            anchor->next = newnode;
        }
        anchor = newnode;
    }
    
    //DISPLAY
    cout<<"\n\n\n"<<endl;
    Link *cursor1 = head;
    for (int i = 0; i < num_disp; ++i)
    {
        cout << cursor1->value <<" ["<<cursor1<< "]  -->  ";
        cursor1 = (cursor1->next);
    }

    //DELETE
    cout <<"\n\n\n"<<endl;
    Link *cursor2 = head;
    Link *temp;
    for (int i = 1; i <= num_nodes; i++){
        cout << "DELETING Node (" << cursor2 << ") of value " << cursor2->value << endl;
        temp = cursor2->next;
        delete cursor2;
        cursor2 = temp;
    }

    return 0;
}
#include<iostream>
using namespace std;

class node
{
    public:
    int data;   //Let us assume for now that the data which the linked list is storing is int
    node *next;

    node(int data_input)
    {
        this->data = data_input;
        this->next = NULL;
    }
};

void printnode(node * &node)
{
    cout<<"Value : "<<node->data;
    cout<<"Address: "<<node->next;
}
void printlinkedlist(node * &head)
{
    if(head == NULL)
    {
        cout<<"The linked list is still empty!! "<<endl;
        return;
    }
    node *temp;
    temp = head;

    //This is called the transversing of a linked list
    while(temp!=NULL)
    {
        cout<<temp->data<<" -->";
        temp = temp->next;
    }
    cout<<endl;
}

void Insertatstart(node * &head, int data)
{
    node * temp = new node(data);

    if(head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;  //where temp is the new head and now, we need to assign the address of the old head to it
    head = temp;
}
void Insertatend(node * &head, int data)
{
    node * temp = new node(data);

    if(head == NULL)
    {
        head = temp;
        return;
    }
    
    node *end;
    end = head;

    while(end->next!=NULL)
    {
        end = end->next;
    }
    //After this while loop is complete, we have basically reached the end of the linked list

    end->next = temp;
}
int main()
{
    //Head of a linked list is nothing but a fancy term to indicate the top or the first element of the linked list
    node *head = NULL;
    // printlinkedlist(head);

    node * node1 = new node(5);
    head = node1;
    // printlinkedlist(head);
    // cout<<endl;

    node * node2 = new node(7);
    node1->next = node2;    //The storing address of the first node which was initially pointing to NULL will now point to the address of the next node
    // printlinkedlist(head);
    // cout<<endl;

    node * node3 = new node(8);
    node2->next = node3;
    printlinkedlist(head);
    // cout<<endl;

    // printnode(node1);
    // cout<<node2<<endl;
    // printnode(node2);
    // cout<<node3<<endl;
    // printnode(node3);
    
    // printnode(node1->next);     //node2 == node1->next
    // printnode(node1->next->next);       //node3 == node2->next == node1->next->next

    //Inserting new elements to the linked list, when the head is given
    //Inserting new element at the start of the linked list

    Insertatstart(head,3);
    //printlinkedlist(head);
    Insertatstart(head,2);
    //printlinkedlist(head);'

    Insertatend(head,9);
    Insertatend(head,10);

    printlinkedlist(head);

    return 0;
}

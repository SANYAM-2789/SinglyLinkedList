#include<iostream>
using namespace std;
    class Node{
        public:
        int data;
        Node* next;

        Node(int d)
        {
            this -> data=d;
            this -> next = NULL;
        }
        ~Node(){
            int value= this -> data;
            // if(this->next != NULL)
            // {
            //     delete next;
            //     this->next=NULL;
            //     cout<<"hiiiiii"<<endl;///////////////////////////////////////////////////////////////////////////////////////
            // }
                cout<<"Deleting the value "<<value<<endl;
        }
    };

    void insertAtHead(Node* &head, int d)
    {
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }

    void insertAtTail(Node* &tail, int d)
    {
        Node* temp= new Node(d);
        tail->next = temp;
        tail = temp;
    }

    void insertAtPosition(Node* &head,Node* &tail, int pos,int d)
    {
        if(pos==1)
        {
            insertAtHead(head,d);
            return;
        }
        int cnt=1;
            Node* temp = head;
        while(cnt<(pos-1))
        {
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL)
        {
            insertAtTail(tail,d);
            return;
        }
        Node* nodeti = new Node(d);
        nodeti->next=temp->next;
        temp->next = nodeti;
    }
    void deleteNode(int pos, Node* &head,Node* &tail)
    {
        if(pos==1)
        {
            Node* temp =head;
            head= head->next;
            temp->next=NULL;
            delete temp;
        }
        else{
            Node*curr=head;
            Node*prev=NULL;
            int cnt=1;
            while(cnt<pos)
            {
                prev=curr;
                curr=curr->next;
                cnt++;
            }
            prev->next=curr->next;
            curr->next=NULL;
            if(prev->next==NULL)
            {
                tail=prev;
            }
            delete curr;
        }
    }


    void printLL(Node* head)
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<< temp->data<<" ";
            temp= temp->next;
        }
        cout<<endl;
    }

int main()
{
    Node* node1= new Node(5);
    Node* head= node1;
    Node* tail= node1;
    printLL(head);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtTail(tail,6);
    insertAtPosition(head,tail,7,7);
    printLL(head);
    cout<<"Head "<< head->data<<endl;
    cout<<"Tail "<< tail->data<<endl;
    deleteNode(7,head,tail);
    printLL(head);
    cout<<"Head "<< head->data<<endl;
    cout<<"Tail "<< tail->data<<endl;

}
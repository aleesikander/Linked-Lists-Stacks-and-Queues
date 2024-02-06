#include<iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node* next;

    Node(int data)
    {
        value = data;
        next = nullptr;
    }
};

class LinkedList
{
    public:
    Node* head;
    LinkedList() : head(nullptr) {}

     void insertAtbeginning(int data)
     {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
     }

     void insertAtEnd(int data)
     {
        Node* newNode = new Node(data);
        if(head==nullptr)
        {
            head = newNode;
            return;
        }
        else
        {
            Node* current = head;
            while(current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
     }

     void insertAfterNode(Node* prev, int data)
     {
        Node* newNode = new Node(data);
        if(prev == nullptr)
        {
            cout << "Previous node cant be a null pointer" << endl;
            return;
        }
        newNode->next = prev->next;
        prev->next = newNode;
     }

     void insertAtPosition(int position, int data)
     {
        Node* newNode = new Node(data);
        if(position<0)
        {
            cout << "invalid position" << endl;
            return;
        }
        if(position==0)
        {
            insertAtbeginning(data);
            return;
        }
        if(head==nullptr)
        {
            head = newNode;
            return;
        }
        Node* current = head;
        for (int i =0; current != nullptr && i<position-1; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        if( current== nullptr)
        {
            cout << "position is greater than number of nodes" << endl;
            delete newNode;
            return;
        }
     }
};  
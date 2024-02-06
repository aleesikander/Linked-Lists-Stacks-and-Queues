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
     
};  
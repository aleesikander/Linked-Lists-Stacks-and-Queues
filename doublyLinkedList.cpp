#include<iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node* next;
    Node* prev;
    Node(int data)
    {
        value = data;
        next = nullptr;
        prev = nullptr;
    }
};
class LinkedList
{
    public:
    Node* head;
    Node* tail;
    LinkedList() : head(nullptr), tail(nullptr) {}

    void addNodeAtFront(int data)
    {
        Node* newNode = new Node(data);
        if(head==nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addNodeAtEnd(int data)
    {
        Node* newNode = new Node(data);
        if(head==nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward()
    {
        if(head==nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }
        else
        {
            Node* current = head;
            while(current->next != nullptr)
            {
                cout << current->value << " ";
                current = current->next;
            }
        }
    }

    void displayBackward()
    {
        if(head==nullptr)
        {
            cout << "list is empty " << endl;
            return;
        }
        else
        {
            Node* current = tail;
            while(current->prev != head)
            {
                cout << current->value << " ";
                current = current->prev;
            }
        }
    }

    ~LinkedList()
    {
        if(head==nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }
        else
        {
            Node* current = head;
            while(current->next != nullptr)
            {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};
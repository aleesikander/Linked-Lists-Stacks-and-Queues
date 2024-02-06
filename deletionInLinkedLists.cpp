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

    void append(int data)
    {
        Node* newNode = new Node(data);
        if(head==nullptr)
        {
            head = newNode;
            return;
        }
        Node* current = head;
        while(current->next != nullptr)
        {
            current= current->next;
        }
        current->next = newNode;
    }

    void deleteFromStart()
    {
        if(head==nullptr)
        {
            cout <<"list is already empty" << endl;
            return;
        }
        Node* temp  = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd()
    {
        if(head==nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }
        Node* current = head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    void deleteByValue(int value)
    {
        if(head==nullptr)
        {
            cout << "the list is already empty " << endl;
            return;
        }
        
        while(head != nullptr && head->value == value)
        {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        Node* current = head;
        Node* prev = nullptr;
        while(current != nullptr)
        {
            if(current->value==value)
            {
                Node* toDelete = current;
                prev->next = current->next;
                delete toDelete;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
};
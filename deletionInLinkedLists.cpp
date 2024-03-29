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

    void deleteByPosition(int position)
    {
        if(position<0)
        {
            cout << "invalid position" << endl;
            return;
        }
        if(head==nullptr)
        {
            cout << "empty list" << endl;
            return;
        }
        if(position==0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        for(int i =0; current != nullptr && i<position-1; i++)
        {
            current = current->next;
        }
        if(current == nullptr || current->next == nullptr)
        {
            return;
        }
        Node* temp = current;
        Node* prev = nullptr;
        prev->next = current->next;
        delete temp;
    }

    void printlist()
    {
        if(head==nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            Node* current = head;
            while(current->next!=nullptr)
            {
                cout << current->value << " ";
                current = current->next;
            }
        }
    }

    ~LinkedList()
    {
        if(head==nullptr)
        {
            cout <<"list is empty " << endl;
            return;
        }
        while(head!= nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
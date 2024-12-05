#include <iostream>
using namespace std;

template <typename type>
class Node 
{
    public:
        type val;
        Node* next;
        Node* prev;

        Node() {next = prev = nullptr;}
        Node(type val, Node* next = nullptr, Node* prev = nullptr)  
        { 
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
};

template <typename type>
class LinkedList 
{
    public:
        Node<type> *head, *tail;
        LinkedList() { this->head = this->tail = nullptr; }

        // node insertion
        void add_to_head(type val) 
        {
            if (head == nullptr) { this->head = this->tail = new Node<type>(val); }

            else 
            {
                Node<type>* newNode = new Node<type>(val, head)
                head = newNode;
                head->next->prev = head;
            }
        }

        void add_to_tail(type val) 
        {
            if ( tail == nullptr ) { add_to_head(val); }

            else 
            {
                Node<type>* newNode = new Node<type>(val);
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void add_to_middle(type val, int index) 
        {
            int ctr = -1;
            Node<type>* current = this->head;

            while (current && ++ctr < index ) current = current->next;

            if (current == head ) { add_to_head(val); return; }

            Node<type>* newNode = new Node<type>(val, current->next, current);
            current->next = newNode;
            newNode->next->prev = newNode; 
        }

        ~LinkedList() { delete this->head; delete this->tail; }
};
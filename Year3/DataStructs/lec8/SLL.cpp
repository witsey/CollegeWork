#include <iostream>
using namespace std;

template <typename type>
class Node 
{
    public:
        type val;
        Node* next;

        Node() {next = nullptr;}
        Node(type val, Node* next = nullptr)  
        { 
            this->val = val;
            this->next = next;
        }
};

template <typename type>
class LinkedList 
{
    private:

    public:
        Node<type> *head, *tail;
        LinkedList() { this->head = this->tail = nullptr; }
        
        void add_to_head(type val) 
        {
            if (head == nullptr) { this->head = this->tail = new Node<type>(val); }

            else 
            {
                Node<type>* newNode = new Node<type>(val, head);
                this->head = newNode;
            }
        }

        void add_to_tail(type val) 
        {
            if (tail == nullptr) { this->head = this->tail = new Node<type>(val); }

            else
            {
                this->tail->next = new Node<type>(val);
                this->tail = this->tail->next;
            }
        }

        void add_to_middle(type val, int index) 
        {
            int ctr = -1;
            Node<type>* current = this->head;

            while (current && ++ctr < index) {current = current->next;}

            if (current == this->head) { add_to_head(val); return; }

            Node<type>* newNode = new Node<type>(val, current->next);
            current->next = newNode;
        }

        ~LinkedList() {delete this->head; delete this->tail;}
};

int main() 
{
    // Node<int>* head = new Node<int>(3);
    // head->next = new Node<int>(4);
    // head->next->next = new Node<int>(5);

    LinkedList<int> l1;
    l1.add_to_head(1);
    l1.add_to_tail(2);
    l1.add_to_tail(3);

    Node<int>* cur = l1.head;

    while (cur != nullptr) 
    {
        cout << cur->val << endl;
        cur = cur->next;
    }    
}
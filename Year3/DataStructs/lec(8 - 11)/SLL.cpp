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

            while (current && ++ctr < index) current = current->next;

            if (current == this->head) { add_to_head(val); return; }

            Node<type>* newNode = new Node<type>(val, current->next);
            current->next = newNode;
        }


        void delete_from_head() 
        {
            if (head == tail) 
            {
                delete head;
                head = tail = nullptr;
                return;
            }

            Node<type>* tmp = head;
            head = head->next;
            delete tmp;
        }

        void delete_from_tail() 
        {
            if (tail == head) 
            {
                delete_from_head(); // empty list or one element so it doesn't matter
                return;
            }

            Node<type>* cur = head;
            while(cur->next != tail) cur = cur->next;

            tail = cur;
            delete tail->next;
            tail->next = nullptr;
        }


        void delete_from_mid(type target) 
        {
            if (head == tail) { delete_from_head(); return; }

            Node<type>* cur = head;

            while (cur->next->val != target) 
            {
                cur = cur->next;
                if (cur->next == nullptr)
                    return;
            } 


            Node<type>* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp; 
        }

        
        void print() 
        {
            Node<type>* cur = head;

            while (cur) 
            {
                cout << cur->val << " -> ";
                cur = cur->next;
            }
        }


        ~LinkedList() {delete this->head; delete this->tail;}
};



int main() 
{
    LinkedList<int> l1;
    LinkedList<int> l2;

    l1.add_to_tail(1);
    l1.add_to_tail(4);
    l1.add_to_tail(3);


}
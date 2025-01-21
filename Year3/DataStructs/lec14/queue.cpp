#include <iostream>
#include <deque>
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

    int size;
    public:
        Node<type> *head, *tail;
        LinkedList() { this->head = this->tail = nullptr; size = 0;}
        
        
        void add_to_head(type val) 
        {
            size++;
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
            size++;
        }

        void add_to_middle(type val, int index) 
        {
            int ctr = -1;
            Node<type>* current = this->head;

            while (current && ++ctr < index) current = current->next;

            if (current == this->head) { add_to_head(val); return; }

            Node<type>* newNode = new Node<type>(val, current->next);
            current->next = newNode;
            size++;
        }


        
        void delete_from_head() 
        {
            --size;
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
                delete_from_head(); 
                return;
            }

            Node<type>* cur = head;
            while(cur->next != tail) cur = cur->next;

            tail = cur;
            delete tail->next;
            tail->next = nullptr;
            --size;
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
            --size;
        }


        void print() 
        {
            Node<type>* cur = head;

            while (cur) 
            {
                cout << cur->val << " ";
                cur = cur->next;
            }

            cout << endl;
        }


        int get_size() {return size;}


        ~LinkedList() {delete this->head; delete this->tail;}
};


template <typename type, typename container = LinkedList<type>>
class Queue 
{
    container queue;

    public:
        Queue() {}

        bool isEmpty() {return queue.head == nullptr;}

        void enqueue(type data) {queue.add_to_tail(data);}
        type dequeue() 
        {
            type elem = queue.head->val;
            queue.delete_from_head();
            return elem;
        }

        void first() { return queue.head->val; }
        void clear() 
        {
            for (int i = 0; i < queue.get_size(); ++i) 
            {
                queue.delete_from_tail();
            }
        }

        void display() { queue.print(); }
};



int main() 
{
    Queue<int> queue1;

    queue1.enqueue(10);
    queue1.enqueue(5);
    queue1.display();

    queue1.dequeue();
    queue1.display();

    queue1.enqueue(15);
    queue1.enqueue(7);
    queue1.display();

    queue1.dequeue();
    queue1.display();
}
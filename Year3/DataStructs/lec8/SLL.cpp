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

int main() 
{
    Node<int>* head = new Node<int>(3);
    head->next = new Node<int>(4);
    head->next->next = new Node<int>(5);

    Node<int>* cur = head;

    while (cur != nullptr) 
    {
        cout << cur->val << endl;
        cur = cur->next;
    }    
}
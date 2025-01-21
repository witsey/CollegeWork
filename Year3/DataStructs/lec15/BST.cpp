#include <iostream>
#include <queue>
using namespace std;


template <typename type>
class Node
{
    public:
        type data;
        Node<type>* left;
        Node<type>* right;

        Node(type data = 0, Node<type>* left = nullptr, Node<type>* right = nullptr) 
        {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};



template <typename type>
class BST
{
    public:

        Node<type>* root;
        int height;

        BST() : root(nullptr) {}
        void clear() {root = nullptr;}
        bool isEmpty() {return root == nullptr;}


        void insert(const type& data) 
        {

            if (root == nullptr) {root = new Node<type>(data); return;}

            Node<type>* new_node = new Node<type>(data);
            Node<type>* current = root;

            while(current) 
            {
                if (data < current->data) 
                {
                    if (current->left) 
                    {
                        current = current->left;
                        continue;
                    }

                    current->left = new Node<type>(data);
                    return;
                }

                else 
                {
                    if (current->right) 
                    {
                        current = current->right;
                        continue;
                    }

                    current->right = new Node<type>(data);
                    return;
                }
            }


        }


        type* search(const type data) 
        {
            Node<type>* current = root;

            while(current) 
            {
                if (current == nullptr) return nullptr;
                
                if (current->data == data) return &(current->data);


                if (data < current->data) current = current->left;
                else  current = current->right;
            }
        }


        void BFS() 
        {
            
        }

        void pre_order(Node<type>* node = root) 
        {
            if (node != 0) 
            {
                cout << node->data << " ";
                pre_order(node->left);
                pre_order(node->right)
            }
        }

        void in_order(Node<type>* node = root) 
        {
            if (node != 0) 
            {
                pre_order(node->left);
                cout << node->data << " ";
                pre_order(node->right)
            }
        }

        void post_order(Node<type>* node = root) 
        {
            if (node != 0) 
            {
                pre_order(node->left);
                pre_order(node->right)
                cout << node->data << " ";
            }
        }
        
};


int main() 
{
    BST<int> bst;

    bst.insert(10);
    bst.insert(8);
    bst.insert(13);
    bst.insert(7);
    bst.insert(9);
    bst.insert(11);
    bst.insert(15);

    bst.BFS();
}
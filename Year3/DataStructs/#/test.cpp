class Node 
{
public:
    int  data;
    Node* next;

    Node() {data = 0; next = 0;}
    Node(int input_data, Node* input_next = 0) 
    {
        data = input_data;
        next = input_next;
    }
};

int main() 
{
    Node* n2 = new Node(2);
    Node* n1 = new Node(1, n2);
}
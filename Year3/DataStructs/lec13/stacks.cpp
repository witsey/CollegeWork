#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;


template<typename type, typename container = deque<type>>
class Stack
{
    private:
        container stack;

    public:
        Stack() {}

        void clear() { stack.clear(); }

        bool isEmpty() { return stack.empty(); }

        type& top() { stack.back(); }
        type pop() 
        {
            type last = top();
            stack.pop_back();
            return last;
        }


        void push(const type& data) 
        {
            stack.push_back(data);
        }

        void display() 
        {
            for (type data : this->stack) 
            {
                cout << data << " ";
            }
        }
        
};


int main() 
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    s1.display();

    Stack<int, list<int>> s2;
}
#include <iostream>
using namespace std;

template <typename type>
class Queue 
{   
    private:
        static const int size = 5;
        type queue[size];
        int first, last;

    public:

        Queue() : first(-1), last(-1) {}


        bool isEmpty() 
        {
            return first == -1;
        }

        
        bool isFull() 
        {
            return (last + 1) % size == first;
        }

        
        void enqueue(type data) 
        {
            if (isFull()) return;

            if (isEmpty()) 
                first = last = 0;
            else
                last = (last + 1) % size;
            
            queue[last] = data;
        }


        type dequeue() 
        {
            if (isEmpty()) exit(0);

            type data = queue[first];

            if (first == last) first = last = -1; // queue becomes empty
            else first = (first + 1) % size; // increment first normally otherwise
            return data;
        }


        void display() 
        {
            if (isEmpty()) return;

            int i = first;
            while (true) 
            {
                cout << queue[i] << " ";
                if (i == last) break;
                i = (i + 1) % size;
            }

            cout << endl;
        }


        int getSize() 
        {
            if (isEmpty()) return 0;
            if (first == last) return 1;

            int cnt = 1;

            int i = first;
            while (true) 
            {
                i = (i + 1) % size;
                cnt++;
                if (i == last) return cnt;
            } 
        }
};


int main() 
{
    Queue<int> q1;

    q1.enqueue(3);
    q1.enqueue(5);
    q1.enqueue(8);
    q1.enqueue(5);
    q1.enqueue(10);

    q1.display();

    cout << endl << q1.getSize();
}
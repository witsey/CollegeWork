#include <iostream>
#include <vector>
using namespace std;

template <typename type>
class Heap
{
    private:
        vector<type> heap;

        int left(int i) {return 2*i + 1;}
        int right(int i) {return 2*i + 2;}
        int parent(i) {return (i - 1)/2;}

    public:

        void max_heapify(int i, int size = 2424) 
        {
            if (size == 2424) size = heap.size();
            int l = left(i);
            int r = right(i);
            int largest;

            if (l < size && heap[l] > heap[i]) 
            {
                largest = l;
            }
            else largest = i;

            if (r < size && heap[r] > heap[largest]) 
            {
                largest = r;
            }
            else largest = i;

            if (largest != i) 
            {
                swap(heap[i], heap[largest]);
                max_heapify(largest);
            }
        }


        void build_heap() 
        {
            int size = heap.size();
            for (int i = (size/2 - 1); i > -1; --i) {max_heapify(i); /* log(n) */} // n
        }


        void push(type data) 
        {
            this->heap.push_back(data);
            build_heap();
        }


        void sort() 
        {
            build_heap(); // nlogn
            int size = heap.size();
            for (int i = (size - 1); i > 0; --i) // n
            {
                swap(heap[0], heap[i]);
                max_heapify(0, i); // log(n)
            }
        }


        void extract_max() 
        {
            size = heap.size();
            int max = heap[0];
            heap[0] = heap[size - 1];
            heap.pop_back();
            max_heapify(0, size - 1);
            return max;
        }

        void increase_key(i, key) 
        {
            if (key < heap[i]) 
            {
                cout << "cannot increase to a smaller value." << endl;
                return;
            }

            heap[i] = key;
            while ( i > 0 && heap[parent(i)] < heap[i]) 
            {
                swap(heap[parent(i)], heap[i]);
                i = parent(i);
            }

        }

        void decrease_key(i, key) 
        {
            if (key > heap[i]) 
            {
                cout << "cannot decrease to a larger value";
                return;
            }

            heap[i] = key;

            while(i > 0 && heap[parent(i)] > heap[i]) 
            {
                swap(heap[parent(i)], heap[i]);
                i = parent(i);
            }
        }

        void insert(key) 
        {
            size = heap.size();
            heap.resize(size + 1);
            heap[size] = -100000;
            increase_key(size, key);
        }


};
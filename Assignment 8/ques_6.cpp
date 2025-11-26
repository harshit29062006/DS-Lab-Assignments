// 6. Implement priority queues using heaps.

#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
public:
    vector<int> heap;

    void push(int x){
        heap.push_back(x);
        int i = heap.size() - 1;

        while(i > 0){
            int parent = (i - 1) / 2;
            if(heap[parent] < heap[i]){
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    void pop(){
        if(heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0, n = heap.size();

        while(true){
            int left = 2*i + 1, right = 2*i + 2, largest = i;

            if(left < n && heap[left] > heap[largest]) largest = left;
            if(right < n && heap[right] > heap[largest]) largest = right;

            if(largest != i){
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

    int top(){
        return heap.empty() ? -1 : heap[0];
    }

    bool empty(){
        return heap.empty();
    }
};

int main(){
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(40);

    cout << "Max element: " << pq.top() << "\n";

    pq.pop();
    cout << "After pop, Max: " << pq.top() << "\n";

    return 0;
}

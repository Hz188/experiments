#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap {
public:
    MinHeap() {}

    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() const {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        return heap[0];
    }

    bool empty() const {
        return heap.empty();
    }

private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] >= heap[parent]) {
                break;
            }
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest == index) {  //不用交换
                break;
            }
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }
};

int main() {
    MinHeap minHeap;

    // 向优先队列中插入元素
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);
    minHeap.push(15);

    // 输出优先队列中的元素
    std::cout << "Priority Queue (min heap): ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " "; // 输出最小元素
        minHeap.pop(); // 移除最小元素
    }
    std::cout << std::endl;

    return 0;
}

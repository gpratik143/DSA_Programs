#include <iostream>

class QueueUsingStacks {
private:
    int capacity;
    int *stack1; // For enqueue operation
    int *stack2; // For dequeue operation
    int top1;
    int top2;

public:
    QueueUsingStacks(int size) {
        capacity = size;
        stack1 = new int[capacity];
        stack2 = new int[capacity];
        top1 = -1;
        top2 = -1;
    }

    ~QueueUsingStacks() {
        delete[] stack1;
        delete[] stack2;
    }

    void enqueue(int value) {
        if (top1 == capacity - 1) {
            std::cout << "Queue is full, cannot enqueue.\n";
            return;
        }

        // Push the element onto stack1
        stack1[++top1] = value;
    }

    void dequeue() {
        if (top1 == -1 && top2 == -1) {
            std::cout << "Queue is empty, cannot dequeue.\n";
            return;
        }

        // If stack2 is empty, move all elements from stack1 to stack2
        if (top2 == -1) {
            while (top1 != -1) {
                stack2[++top2] = stack1[top1--];
            }
        }

        // Pop the top element from stack2 (which corresponds to the front of the queue)
        std::cout << "Dequeued: " << stack2[top2--] << "\n";
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the queue: ";
    std::cin >> size;

    QueueUsingStacks queue(size);

    // Enqueue elements
    for (int i = 1; i <= size; ++i) {
        queue.enqueue(i);
    }

    // Dequeue elements
    std::cout << "Dequeuing elements:\n";
    for (int i = 0; i < size; ++i) {
        queue.dequeue();
    }

    return 0;
}

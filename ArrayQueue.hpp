#include <iostream>
#include "Queue.h"
using namespace std;

template<typename T>
class ArrayQueue : public Queue<T> {
    public:
        ArrayQueue() : max_size{10}, front{0}, back{0}, data{new T[10]} {}
        ~ArrayQueue() {
            delete [] data;
        };
        ArrayQueue(const ArrayQueue &q) : max_size{q.max_size}, front{q.front}, back{q.back}, data{new T[q.max_size]} {
            for (int i = 0; i < max_size; i++) {
                data[i] = q.data[i];
            }
        }
         Queue<T> &operator=(const ArrayQueue<T> &rhs) {
                if (this != &rhs) {
                    delete [] data;
                    max_size = rhs.max_size;
                    front = rhs.front;
                    back = rhs.back;
                    data = new T[max_size];
                    for (int i = 0; i < back; i++) {
                        data[i] = rhs.data[i];
                    }
                }
                return *this;
            }

        void enqueue(const T &t) {
            if (back == max_size) {
                T *tmp = new T[max_size * 2];
                for (int i = 0; i < max_size; i++) {
                    tmp[i] = data[i];
                }
                delete [] data;
                data = tmp;
                max_size *= 2;
            }
            data[back] = t;
            ++back;
        };
        T dequeue() {
            if (isEmpty()) {
                throw "Queue is empty";
            }
            T ret = data[front];
            ++front;
            return ret;
        };

        T peek() const {
            if (isEmpty()) {
                throw "Queue is empty";
            }
            return data[front];
        };
        bool isEmpty() const {
            return front == back;
        };
        int size() const {
            return back - front;
        };
    private:
        int max_size;
        int top;
        T *data;
        int front;
        int back;
};

int main() {
    ArrayQueue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    if (!q.isEmpty()) {
        cout << "Pass, queue is not empty" << endl;
    }
    else{
        cout << "Fail, queue is empty"  << endl;
    }
    if (q.size() == 4) {
        cout << "Pass, queue size is 4"  << endl;
    }
    else{
        cout << "Fail, queue size is not 4" << endl;
    }
    if (q.peek() == 1) {
        cout << "Pass, queue peek is 1" << endl;
    }
    else{
        cout << "Fail, queue peek is not 1" << endl;
    }
    if (q.dequeue() == 1) {
        cout << "Pass, queue dequeue is 1" << endl;
    }
    else{
        cout << "Fail, queue dequeue is not 1" << endl;
    }
    if (q.size() == 3) {
        cout << "Pass, queue size is 3" << endl;
    }
    else{
        cout << "Fail, queue size is not 3" << endl;
    }
    if (q.peek() == 2) {
        cout << "Pass, queue peek is 2" << endl;
    }
    else{
        cout << "Fail, queue peek is not 2" << endl;
    }
    for (int i = 0; i < 1000; i++) {
        q.enqueue(i);
    }
    if (q.size() == 1003) {
        cout << "Pass, queue size is 1003" << endl;
    }
    else{
        cout << "Fail, queue size is not 1003" << endl;
    }
}
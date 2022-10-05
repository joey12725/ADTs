#include <iostream>
#include "Stack.h"
using namespace std;

template<typename T>
class ArrayStack : public Stack<T> {
    public:
        ArrayStack() : max_size{10}, top{0}, data{new T[10]} {}
        ArrayStack(const ArrayStack &s) : max_size{s.max_size}, top{s.top}, data{new T[s.max_size]} {
            for (int i = 0; i < top; i++) {
                data[i] = s.data[i];
            }
        }
        Stack<T> &operator=(const ArrayStack<T> &rhs) {
            if (this != &rhs) {
                delete [] data;
                max_size = rhs.max_size;
                top = rhs.top;
                data = new T[max_size];
                for (int i = 0; i < top; i++) {
                    data[i] = rhs.data[i];
                }
            }
            return *this;
        }
        ~ArrayStack() {
            delete [] data;
        };
        void push(const T &t) {
            if (top == max_size) {
                T *tmp = new T[max_size * 2];
                for (int i = 0; i < max_size; i++) {
                    tmp[i] = data[i];
                }
                delete [] data;
                data = tmp;
                max_size *= 2;
            }
            data[top] = t;
            ++top;
        };
        T pop() {
            if (isEmpty()) {
                throw "Stack is empty";
            }
            return data[--top];
        };
        T peek() const {
            if (isEmpty()) {
                throw "Stack is empty";
            }
            return data[top - 1];
        };
        bool isEmpty() const {
            return top == 0;
        };
        int size() const {
            return top;
        };
        void print() const {
            for (int i = 0; i < top; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        };
    private:
        int max_size;
        int top;
        T *data;
};

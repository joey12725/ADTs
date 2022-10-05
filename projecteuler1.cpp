#include <iostream>
using namespace std;

int sumOfMultiplesOf3Or5(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    cout << "The answer is " << sumOfMultiplesOf3Or5(1000) << endl;
    return 0;
}
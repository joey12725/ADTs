#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<cstdlib>
#include "ArrayStack.h"
#include "ArrayQueue.h"

using std::ofstream;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::rand;

void fillRandomIntStack(int numElems,ArrayStack<int> &s,vector<int> &v) {
	for(int i=0; i<numElems; ++i) {
		v.push_back(rand());
		s.push(v.back());
	}
}

void fillRandomStringStack(int numElems,ArrayStack<string> &s,vector<string> &v) {
	for(int i=0; i<numElems; ++i) {
		string str(1+rand()%10,32+rand()%70);
		v.push_back(str);
		s.push(v.back());
	}
}

ArrayStack<int> makeRandomIntStack(int numElems,vector<int> &v) {
	ArrayStack<int> ret;
	fillRandomIntStack(numElems,ret,v);
	return ret;
}

ArrayStack<string> makeRandomStringStack(int numElems,vector<string> &v) {
	ArrayStack<string> ret;
	fillRandomStringStack(numElems,ret,v);
	return ret;
}

bool testIntStack(int numElems) {
	vector<int> nums;
	ArrayStack<int> s = makeRandomIntStack(numElems,nums);

	while(!s.isEmpty()) {
		if(nums.back()!=s.pop()) return false;
		nums.pop_back();
	}
	for(int i=0; i<10; ++i) {
		fillRandomIntStack(numElems/(i+1),s,nums);
		while(!s.isEmpty()) {
			if(nums.back()!=s.pop()) return false;
			nums.pop_back();
		}
	}
	return true;
}

bool testStringStack(int numElems) {
	vector<string> nums;
	ArrayStack<string> s = makeRandomStringStack(numElems,nums);

	while(!s.isEmpty()) {
		if(nums.back()!=s.pop()) return false;
		nums.pop_back();
	}
	for(int i=0; i<10; ++i) {
		fillRandomStringStack(numElems/(i+1),s,nums);
		while(!s.isEmpty()) {
			if(nums.back()!=s.pop()) return false;
			nums.pop_back();
		}
	}
	return true;
}

void fillRandomIntQueue(int numElems,ArrayQueue<int> &q,deque<int> &v) {
	for(int i=0; i<numElems; ++i) {
		v.push_back(rand());
		q.enqueue(v.back());
	}
}

void fillRandomStringQueue(int numElems,ArrayQueue<string> &q,deque<string> &v) {
	for(int i=0; i<numElems; ++i) {
		string str(1+rand()%10,32+rand()%70);
		v.push_back(str);
		q.enqueue(v.back());
	}
}

ArrayQueue<int> makeRandomIntQueue(int numElems,deque<int> &v) {
	ArrayQueue<int> ret;
	fillRandomIntQueue(numElems,ret,v);
	return ret;
}

ArrayQueue<string> makeRandomStringQueue(int numElems,deque<string> &v) {
	ArrayQueue<string> ret;
	fillRandomStringQueue(numElems,ret,v);
	return ret;
}

bool testIntQueue(int numElems) {
	deque<int> nums;
	ArrayQueue<int> q = makeRandomIntQueue(numElems,nums);

	while(!q.isEmpty()) {
		if(nums.front()!=q.dequeue()) return false;
		nums.pop_front();
	}
	for(int i=0; i<10; ++i) {
		fillRandomIntQueue(numElems/(i+1),q,nums);
		while(!q.isEmpty()) {
			if(nums.front()!=q.dequeue()) return false;
			nums.pop_front();
		}
	}
	return true;
}

bool testStringQueue(int numElems) {
	deque<string> nums;
	ArrayQueue<string> q = makeRandomStringQueue(numElems,nums);

	while(!q.isEmpty()) {
		if(nums.front()!=q.dequeue()) return false;
		nums.pop_front();
	}
	for(int i=0; i<10; ++i) {
		fillRandomStringQueue(numElems/(i+1),q,nums);
		while(!q.isEmpty()) {
			if(nums.front()!=q.dequeue()) return false;
			nums.pop_front();
		}
	}
	return true;
}

int runTests() {
	ofstream out("time.txt");
	std::srand(42);

	cout << "Starting timing." << endl;
	double start = clock();

	cout << "Testing the stack." << endl;

	if(!testIntStack(10)) {
		cout << "Failed stack at 10." << endl;
		return 2;
	}
	if(!testIntStack(10000)) {
		cout << "Failed stack at 10000." << endl;
		return 2;
	}
	if(!testIntStack(10000000)) {
		cout << "Failed stack at 10000000." << endl;
		return 2;
	}
	if(!testStringStack(10)) {
		cout << "Failed string stack at 10." << endl;
		return 2;
	}
	if(!testStringStack(10000)) {
		cout << "Failed string stack at 10000." << endl;
		return 2;
	}

	cout << "Testing the queue." << endl;

	if(!testIntQueue(10)) {
		cout << "Failed queue at 10." << endl;
		return 2;
	}
	if(!testIntQueue(10000)) {
		cout << "Failed queue at 10000." << endl;
		return 2;
	}
	if(!testIntQueue(10000000)) {
		cout << "Failed queue at 10000000." << endl;
		return 2;
	}
	if(!testStringQueue(10)) {
		cout << "Failed string queue at 10." << endl;
		return 2;
	}
	if(!testStringQueue(10000)) {
		cout << "Failed string queue at 10000." << endl;
		return 2;
	}

	ArrayStack<int> as1;
	as1.push(1);
	as1.push(2);
	as1.push(3);
	as1.push(4);
	ArrayStack<int> as2{as1};
	if(as2.pop()!=4) {
		cout << "Failed copy test 1." << endl;
		return 2;
	}
	as2.push(99);
	if(as1.pop()!=4) {
		cout << "Failed copy test 2." << endl;
		return 2;
	}
	

	out << (clock()-start)/CLOCKS_PER_SEC << endl;
	out.close();
	cout << "Done timing." << endl;
}

int main(int argc,char **argv) {
	int res = runTests();
	cout << "Tests passed." << endl;
	return res;
}
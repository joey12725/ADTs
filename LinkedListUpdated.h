#include <iostream>;

template<typename T>
class LinkedList {
	struct Node {
		Node() {};
		T data;
		Node *prev, *next;
	};
	Node sentinel;
	int ct;
	public:
		typedef T value_type;

		class iterator {
			Node *loc;
			public:
				iterator() :loc(nullptr){}
				iterator(Node* l)  {loc = l; }
				//iterator(const iterator &i):loc(i.loc) {}
				T& operator*() {return loc->data; }
				bool operator==(const iterator &i) { return loc == i.loc; }
				bool operator!=(const iterator &i) { return !(*this == i); }
				iterator &operator=(const iterator &i) { loc = i.loc; return *this; }
				iterator &operator++() { loc = loc->next; return *this; }
				iterator &operator--() { loc = loc->prev; return *this; }
				const T &operator[](int index) const {
					Node *temp = loc;
					for (int i = 0; i < index; i++) {
						temp = temp->next;
					}
					return temp->data;
				}; 
				iterator operator++(int) { 
					iterator clone(loc);
					loc = loc->next;
					return clone;
				 }
				iterator operator--(int) {
					iterator clone(loc);
					loc = loc->prev;
					return clone;
				}
				friend class LinkedList;
		};
		class const_iterator {
			const Node *loc;
			public:
				const_iterator() :loc(nullptr){}
				const_iterator(const Node* l)  {loc = l; }
				const T& operator*() {return loc->data; }
				bool operator==(const const_iterator &i) { return loc == i.loc; }
				bool operator!=(const const_iterator &i) { return !(*this == i); }
				const_iterator &operator=(const const_iterator &i) { loc = i.loc; return *this; }
				const_iterator &operator++() { loc = loc->next; return *this; }
				const_iterator &operator--() { loc = loc->prev; return *this; }
				const T &operator[](int index) const {
					const Node *temp = loc;
					for (int i = 0; i < index; i++) {
						temp = temp->next;
					}
					return temp->data;
				};
				const_iterator operator++(int) { 
					const_iterator clone(loc);
					loc = loc->next;
					return clone;
				 }
				const_iterator operator--(int) {  
					const_iterator clone(loc);
					loc = loc->prev;
					return clone;
				}
				friend class LinkedList;
			
		};

		LinkedList():ct(0) {
			sentinel.next = &sentinel;
			sentinel.prev = &sentinel;
		}
		~LinkedList() {
			Node *rover = sentinel.next;
			for (int i = 0; i != ct; ++i) {
				rover = rover->next;
				delete (rover->prev);
			}
		}
		void push_back(const T &t);
		iterator insert(iterator position,const T &t) {
			std::cout << "inserting before: " << *position << std::endl;
			Node* orig = position.loc;
			Node* n = new Node();
			n->data = t;
			n->next = orig;
			n->prev = orig->prev;
			orig->prev->next = n; //n->prev->next = n
			orig->prev = n;
			++ct;
			return iterator(n); 
		}
		iterator erase(iterator position) {
			Node* orig = position.loc;
			orig->prev->next = orig->next;
			orig->next->prev = orig->prev;
			iterator ret(orig->next);
			delete orig;
			--ct;
			return ret;
		}
		iterator clear() {
			Node *rover = sentinel.next;
			for (int i = 0; i != ct; ++i) {
				rover = rover->next;
				delete (rover->prev);
			}
			sentinel.next = &sentinel;
			sentinel.prev = &sentinel;
			ct = 0;
			return iterator(&sentinel);
		}
		void pop_back() {
			Node *last = sentinel.prev;
			last->prev->next = &sentinel;
			sentinel.prev = last->prev;
			iterator ret(last->next);
			delete last;
			--ct;
		}
		iterator print() {
			Node *rover = sentinel.next;
			for (int i = 0; i != ct; ++i) {
				std::cout << rover->data << " ";
				rover = rover->next;
			}
			std::cout << std::endl;
			return iterator(rover);
		}

		int size() const {
			return ct;
		}
		const_iterator cbegin() const {
			return const_iterator(sentinel.next);
		}
		const_iterator cend() const {
			return const_iterator(&sentinel);
		}
		iterator begin() { return iterator(sentinel.next); }
		iterator end() { return iterator(&sentinel); }
};

template<typename T>
void LinkedList<T>::push_back(const T &t) {
	Node *n = new Node();
	n->data = t;
	n->prev = sentinel.prev;
	n->next = &sentinel;

	sentinel.prev = n; //n->next->prev = n;
	n->prev->next = n;
	++ct;
}

void runTests() { 
	LinkedList<int> ll;
	for(int i = 0; i < 30; ++i) {
		ll.push_back(i);
	}
	ll.print();
	for (int i = 0; i < 30; ++i) {
		ll.pop_back();
	}
	if (ll.size() == 0) {
		std::cout << "size is 0 after popping all items" << std::endl;
	}
	else {
		std::cout << "size is not 0" << std::endl;
	}
	for (int i = 0; i < 30; ++i) {
		ll.push_back(i);
	}
	ll.clear();
	if (ll.size() == 0) {
		std::cout << "size is 0 after clear" << std::endl;
	}
	else {
		std::cout << "size is not 0 after clear" << std::endl;
	}	
	std::
}
int main() { runTests(); return 0; }
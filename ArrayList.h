#include <iostream>

template<typename T>
class ArrayList {
	private:
		int ct;
		T* data;
		int max_size;
	public:
	// Types
	// value_type
	typedef T value_type;
	// iterator
	class iterator {
		T* loc;
		public:
		iterator(T *l) : loc(l) {};
		iterator() {
			std::cout << "iterator ()\n";
		};
		iterator(const iterator &i) {
			loc = i.loc;
		};
		T &operator*() { return *loc; };
		bool operator==(const iterator &i) const { return loc == i.loc; };
		bool operator!=(const iterator &i) const { return !(loc == i.loc); };
		iterator &operator=(const iterator &i) {};
		iterator &operator++() { ++loc; return *this; };
		iterator &operator--() {--loc; return *this;};
		iterator operator++(int) {
			iterator tmp(*this);
			++loc;
			return tmp;
		};
		iterator operator--(int) {
			iterator tmp(*this);
			--loc;
			return tmp;
		};
	};
	// const_iterator
	class const_iterator {
		T* loc;
		public:
		const_iterator(T *l):loc(l) {};
		const_iterator() { std::cout << "const_iterator()\n"; };
		const_iterator(const const_iterator &i) {};
		~const_iterator() {}
		T &operator*() { 
			return *loc; 
		};
		bool operator==(const const_iterator &i) const {return loc == i.loc; };
		bool operator!=(const const_iterator &i) const { return !(*this == i); };
		const_iterator &operator=(const const_iterator &i) {};
		const_iterator &operator++() { ++loc; return *this; };
		const_iterator &operator--() {};
		const_iterator operator++(int) {};
		const_iterator operator--(int) {};
	};

	// General Methods
	ArrayList():ct{0},  max_size{10} , data{new T[max_size]} {};
	ArrayList(const ArrayList &that) {};
	ArrayList<T> &operator=(const ArrayList<T> &al) {};

	~ArrayList() { delete [] data;};
	void push_back(const T &t) {
		ct += 1;
		data[ct] = t;
	}; // add to the end.
	void pop_back() 
		{
			ct -= 1;
		}; // remove last element.
	int size() const {
		return ct;
	};
	void clear() {
		ct = 0;
	};
	void insert(const T &t,int index) {
		/*if (index > ct){
			std::cout << "Index not in order";
			exit(0);
		}*/
	
		for (int i = ct; i != index; --i) {
			data[i] = data[i-1];
		}
		data[index] = t;
		++ct;}; // insert this element before the given index.	
	const T &operator[](int index) const {
		if (index >= ct){
			std::cout << "Index out of bounds";
		}
		
		return data[index];}; // get the element at index.
	T &operator[](int index) {
		if (index  > ct){
			std::cout << "Index out of bounds";
		}
		
		return data[index];
	}; // get the element at index.
	void remove(int index) {
		for (int i = ct; i != index; --i) {
			data[i-1] = data[i];
		}
		--ct;
	}; // remove the item at the given index.
	void print() const {
		for (int i = 0; i != ct; ++i) {
			std::cout << i << ": " << data[i] << std::endl;
		}
	}

	iterator begin() { return iterator(data);};
	const_iterator begin() const { return const_iterator(data); };
	iterator end() { return iterator(data+ct); };
	const_iterator end() const { return const_iterator(data+ct); };
	const_iterator cbegin() const { return const_iterator(data); };
	const_iterator cend() const { return const_iterator(data+ct); };
};
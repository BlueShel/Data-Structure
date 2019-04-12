#include<iostream>
using namespace std;
class Stack
{
public:
	Stack() {
		size = 0;
		capacity = 1;
		data = new int[capacity];
	};
	void push(const int & d) {
		if (size + 1>=capacity) {
			resize(2 * capacity);
		}
		data[size++] = d;
	}
	void pop() {
		if (size > 0) {
			--size;
		}
	}
	
	int top() {
		return data[size - 1];
	}
	int size() {
		return size;
	}
	bool empty() {
		return size == 0;
	}
	~Stack() {
		delete data;
	};

private:
	int size;
	int capacity;
	int *data;
	void resize(int new_capacity) {
		int *new_data = new int[new_capacity];
		for (int i = 0; i < size; i++)
		{
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		capacity = new_capacity;
	}
};
int main() {
	return 0;
}
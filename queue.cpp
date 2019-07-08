//First in first out    --queue
/*
队头和队尾： 允许元素插入的一端称为队尾，允许元素删除的一端称为队头
入队：队列的插入操作
出队：队列的删除操作
*/
//用两个栈实现一个序列
//一个栈stackPush用来放入，一个栈stackPop用来弹出。放数据的时候直接放到stackPush中，弹出时，若stackPop不为空，直接弹出，若为空且stackPush不为空，则将stackPush数据依次弹出压入stackPop后再从stackPop中弹出
#include<stack>
using namespace std;
template <typename T>
class Queue
{
public:
	Queue();
	~Queue();
	void push(T val) {
		stackPush.push(val);
	}
	void pop() {
		if (!stackPop.empty()) {
			stackPop.pop();
		}
		else
		{
			if (!stackPush.empty())
			{
				while (!stackPush.empty())
				{
					stackPop.push(stackPush.top());
					stackPop.pop();
				}
			}
		}
	}
	bool empty() {
		return stackPop.empty() && stackPush.empty();
	}
	T top() {
		if (!stackPop.empty()) {
			return stackPop.top();
		}
		else
		{
			if (!stackPush.empty())
			{
				while (!stackPush.empty())
				{
					stackPop.push(stackPush.top());
					stackPop.top();
				}
			}
		}
		
	}
private:
	stack<T> stackPop, stackPush;
};

template<typename T>Queue<T>::Queue()
{
}
template<typename T>Queue<T>::~Queue()
{
}
int main() {
	return 0;
}

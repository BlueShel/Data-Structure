//First in first out    --queue
/*
��ͷ�Ͷ�β�� ����Ԫ�ز����һ�˳�Ϊ��β������Ԫ��ɾ����һ�˳�Ϊ��ͷ
��ӣ����еĲ������
���ӣ����е�ɾ������
*/
//������ջʵ��һ������
//һ��ջstackPush�������룬һ��ջstackPop���������������ݵ�ʱ��ֱ�ӷŵ�stackPush�У�����ʱ����stackPop��Ϊ�գ�ֱ�ӵ�������Ϊ����stackPush��Ϊ�գ���stackPush�������ε���ѹ��stackPop���ٴ�stackPop�е���
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

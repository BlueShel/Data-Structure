#include<iostream>
using namespace std;
class List
{
public:
	List() {
		length = 0;
		head = nullptr;
		tail = nullptr;
	};
	~List() {
		//从头开始删
		Node *p = head;
		while (head!=nullptr)
		{
			head = head->next;
			delete p;
			p = head;
		}
	};
	void insert_front(const int &d);//从头结点插入
	void insert_back(const int &d);//从尾结点插入
	void insert_pos(const int &d, const int &p);//从指定位置插入
	void deleteNode(const int &p);//删除指定数据的节点
	void update_data(const int &d, const int &pos);//修改指定数据
	void reverse();//反转链表
	void print();//打印链表
private:
	//节点结构
	struct Node
	{
		int data;
		Node *next;
		//初始化
		Node(const int &d):data(d),next(nullptr) {}
	};
	Node *head;//创建头结点
	Node *tail;//创建尾节点
	int length;//当前链表长度
};
void List::insert_front(const int &d){
	if (length==0) {
		head = tail = new Node(d);
	}
	else
	{
		Node *p = new Node(d);
		p->next = head;
		head = p;
	}
	length++;
}
void List::insert_back(const int &d) {
	if (length == 0) {
		tail = head = new Node(d);
	}
	else
	{
		tail->next = new Node(d);
		tail = tail->next;
	}
	length++;
}
void List::insert_pos(const int &d, const int &p) {
	if (p <= 0) {
		insert_front(d);
	}
	else if (p >= length) {
		insert_back(d);
	}
	else
	{
		Node *p1, *p2;
		p1 = head;
		p2 = new Node(d);
		for (int i=0; i < p-1; i++) {
			p1 = p1->next;
		}
		p2->next= p1->next;
		p1->next = p2;
		length++;
	}
}
void List::deleteNode(const int &p) {
	if (p<0 || p>length - 1) {
		return;
	}
	Node *p1,*p2;
	if (p==0)
	{
		p1 = head;
		if (length == 1) {
			head = tail = nullptr;
		}
		else
		{
			head = head->next;
		}
		delete p1;
	}
	else
	{
		p1 = head;
		for (int i = 0; i < p-1; i++)
		{
			p1 = p1->next;
		}
		p2 = p1->next;
		p1->next = p2->next;
		if (p2->next==nullptr) {
			tail = p1;
		}
		delete p2;
	}
	length--;
}
void List::update_data(const int &d, const int &p) {
	if (p<0 || p>length-1) {
		return;
	}
	Node *p1 = head;
	for (int i = 0; i < p; i++)
	{
		p1 = p1->next;
	}
	p1->data = d;
}
void List::print() {
	for (Node *p = head;p;p=p->next) {
		cout << p->data << endl;
	}
}
void List::reverse() {
	Node *p1, *p2, *p3;
	p1 = head;
	p2 = head->next;
	head->next = nullptr;
	while (p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head = p1;
}


int main() {
	List list;
	list.insert_front(2);
	list.insert_front(1);
	list.insert_front(3);
	list.print();
	list.insert_pos(5, 2);
	list.print();
	getchar();
	return 0;
}
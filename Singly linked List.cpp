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
		//��ͷ��ʼɾ
		Node *p = head;
		while (head!=nullptr)
		{
			head = head->next;
			delete p;
			p = head;
		}
	};
	void insert_front(const int &d);//��ͷ������
	void insert_back(const int &d);//��β������
	void insert_pos(const int &d, const int &p);//��ָ��λ�ò���
	void deleteNode(const int &p);//ɾ��ָ�����ݵĽڵ�
	void update_data(const int &d, const int &pos);//�޸�ָ������
	void reverse();//��ת����
	void print();//��ӡ����
private:
	//�ڵ�ṹ
	struct Node
	{
		int data;
		Node *next;
		//��ʼ��
		Node(const int &d):data(d),next(nullptr) {}
	};
	Node *head;//����ͷ���
	Node *tail;//����β�ڵ�
	int length;//��ǰ������
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
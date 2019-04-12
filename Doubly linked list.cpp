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
		Node *p = head;
		while (head!=nullptr)
		{
			head = head->next;
			delete p;
			p = head;
		}
		head = tail = nullptr;
	};
	void insert_front(const int &d);
	void insert_back(const int &d);
	void insert_pos(const int &d, const int &p);
	void delete_node(const int &p);
	void update_node(const int &p, const int &d);

private:
	struct Node
	{
		int data;
		Node *prev;
		Node *next;
		Node(const int &d) :data(d), prev(nullptr), next(nullptr) {};
	};
	Node *head;
	Node *tail;
	int length;//Á´±í³¤¶È
};
void List::insert_front(const int &d) {
	if (length == 0) {
		head = tail = new Node(d);
	}
	else
	{
		Node *p = new Node(d);
		p->next = head;
		head->prev = p;
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
		Node *p = new Node(d);
		tail->next = p;
		p->prev = tail;
		tail = p;
	}
}
void List::insert_pos(const int &d, const int &p) {
	if(p<=0){
		insert_front(d);
	}
	else if(p>=length)
	{
		insert_back(d);
	}
	else
	{
		Node *p1, *p2;
		p1 = head;
		p2 = new Node(d);
		for (int i = 0; i < p - 1; i++) {
			p1 = p1->next;
		}
		p2->next = p1->next;
		p1->next->prev = p2;
		p1->next = p2;
		p2->prev = p1;
		length++;
	}
}
void List::delete_node(const int &p) {
	if (p<0 || p>length-1) {
		return;
	}
	Node *p1, *p2;
	if(p==0){
		p1 = head;
		if (length == 1) {
			head = tail = nullptr;
		}
		else
		{
			head = head->next;
			head->prev = nullptr;
		}
		delete p1;
	}
	else
	{
		p1 = head;
		for (int i = 0; i < length-1; i++)
		{
			p1 = p1->next;
		}
		p2 = p1->next;
		p1->next = p2->next;
		if (p2->next == nullptr) {
			tail = p1;
		}
		else
		{
			p2->next->prev = p1;
		}
		delete p2;
	}
	length--;
}
void List::update_node(const int &p, const int &d) {
	if (p<0 || p>length - 1) {
		return;
	}
	else
	{
		Node *p1 = head;
		for (int i = 0; i < length; i++)
		{
			p1 = p1->next;
		}
		p1->data = d;
	}
}

int main() {

	return 0;
}
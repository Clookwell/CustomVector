#include <iostream>

template<class T>
class List {
private:
	class Node {
	public:
		T data;
		Node* next;
	};
	int size;
	Node* head;

public:

	void push_back(T value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = nullptr;
		if (head == nullptr) {
			head = newNode;
			size = 1;
		}
		else {
			Node* temp;
			for (temp = head; temp->next != nullptr; temp = temp->next)
				;
			temp->next = newNode;
			size++;
		}
	}

	void pop_front() {
		if (head == nullptr)
			return;
		else {
			Node* temp = head;
			head = head->next;
			delete temp;
			size--;
		}
	}

	int get_size() { return size; }

	List() : head(nullptr), size(0) {}
	List(const List& l) : head(nullptr), size(0) {
		Node* temp = l.head;
		while (temp != nullptr) {
			this->push_back(temp->data);
			temp = temp->next;
		}
	}
	~List() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void clear() { 
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		head = nullptr;
		size = 0;
	}
};

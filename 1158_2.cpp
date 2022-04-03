#include <iostream>
using namespace std;

class CircularList;

class Node {
	friend class CircularList;
private:
	int data;
	Node* link;
};

class CircularList {
public:
	void Add(int); // 초기값 정렬
	int Delete(int); // k번째 수를 출력하고 delete하기.
	void Set(); // 초기값 정렬 후 current 위치 설정.
	CircularList() {
		size = 0;
		current = NULL;
	}
	int getSize(){
		return size;
	}
private:
	Node* current;
	int size;
	Node* last; // Node에 data와 link만을 prevent를 사용하지 않기 위해 last를 설정. (k가 1일때 필요)
};

void CircularList::Add(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	size++;

	if (!current){
		current = newNode;
		current->link = current;
	}
	else {
		newNode->link = current->link;
		current->link = newNode;
		current = current->link;
	}
	last = newNode;
}

int CircularList::Delete(int kTh) {
	size--;
	for (int i = 0; i < kTh - 2; i++) {
		current = current->link;
	}

	Node* deleteNode;
	if (kTh == 1) { // last의 link를 이어주어야함.
		deleteNode = current;
		last->link = last->link->link;
	}
	else { // current의 link를 이어주어야함.
		deleteNode = current->link;
		current->link = current->link->link;
	}

	current = current->link;
	int deleteNumber = deleteNode->data;
	delete deleteNode;
	return deleteNumber;
}

void CircularList::Set() {
	current = current->link;
}

int main() {

	int n, k;
	cin >> n >> k;

	CircularList cl;
	for (int i = 1; i < n + 1; i++) {
		cl.Add(i);
	}

	cl.Set();
	cout << "<";
	
	while (cl.getSize()) {
		if (cl.getSize() == 1) {
			cout << cl.Delete(k) << ">";
		}
		else {
			cout << cl.Delete(k) << ", ";
		}
	}
	return 0;
}
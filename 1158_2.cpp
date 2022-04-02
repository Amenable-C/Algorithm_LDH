#include <iostream>
using namespace std;

class CircularList;

class Node {
	friend class CircularList;
private:
	int data;
	Node* link;
	Node* prevent;
};

class CircularList {
public:
	void Add(int);
	int Delete(int);
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
};

void CircularList::Add(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	size++;

	if (!current){
		current = newNode;
		current->link = current;
		current->prevent = current;
	}
	else {
		current->link = current->link->link;
		current->link = newNode;
		current->prevent = current;
		
		
		newNode->link = current->link;
		current->link = newNode;
	}
}

int CircularList::Delete(int kTh) {

	for (int i = 0; i < kTh - 1; i++) {
		prevent->link = current->link;
		current->link->
		current->link = current->link->link;

	}
	
	/*delete nextNode;*/

	/*prevent->link = current->link;

	int returnNum = current->data;
	delete current;
	size--;
	return returnNum;*/
	return 1;
}

int main() {

	int n, k;
	cin >> n >> k;

	CircularList cl;
	for (int i = 1; i < n + 1; i++) {
		cl.Add(i);
	}

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
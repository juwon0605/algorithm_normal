/*
03-2. 리스트 3(중복 노드 모두 제거)

리스트
중복을 허용하며 순서가 있는 연속된 데이터를 표현하는 자료구죠.
배열과 달리 사용하는 중에 크기가 자동으로 조절된다.

ArrayList
추가 및 삭제 O(1) 하지만 최악의 경우에는 O(N)
조회 O(1)

LinkedList
추가 및 삭제 O(1)
조회 O(N)
*/

/*
문제 3) 중복 노드 모두 제거
	정렬된 연결 리스트에서 중복되는 모든 노드 제거하는 코드를 작성하라.

	예) 1 -> 2 -> 2 -> 3   =>  1 -> 3
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
	int data;
	Node* next = NULL;
};

class SingleLinkedList {
public:
	Node* head = new Node();
	int size = 0;

	void insert(int data);
	void print();
	void removeDuplicatesAll();
	void removeDuplicatesAll2();
};
void SingleLinkedList::insert(int data) {
	if (size == 0) {
		head->data = data;
		head->next = NULL;
	}
	else {
		Node* current = new Node();
		current->data = data;
		current->next = NULL;
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = current;
	}
	size++;
}
void SingleLinkedList::print() {
	Node* temp = head;
	/*
	for (int i = 0; i < size; i++) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	*/
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

/*
풀이 1)
	순회하면서 temp(= current->next...)->data != current->data일때 pre->next = temp한다. 
	current(=temp) -> data != current(=temp) -> next -> data일때 pre = current한다.

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

void SingleLinkedList::removeDuplicatesAll() {
	Node* pre = head;
	Node* current = head;
	while (current->next != NULL) {
		Node* temp = current;
		while (temp != NULL && current->data == temp->data) {
			temp = temp->next;
		}
		pre->next = temp;
		current = temp;
		if (current != NULL && current->next != NULL &&
			current->data != current->next->data) {
			pre = current;
		}
	}
}

/*
풀이 2)
	(+정렬되어 있지 않다면)
	한 번 전체 순회하여 unordered_map에 count한 뒤, count >= 2인 노드를 전부 삭제한다.
	중복 검사는 Node* current와 Node* temp만 사용하면 되지만,
	전부 삭제하기 위해서는 Node* pre가 필요하다.
	
	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

void SingleLinkedList::removeDuplicatesAll2() {
	unordered_map<int, int> uM;
	Node* temp = head;
	while (temp != NULL) {
		if (uM.find(temp->data) != uM.end()) {
			uM.find(temp->data)->second += 1;
		}
		else {
			uM.insert(make_pair(temp->data, 1));
		}
		temp = temp->next;
	}
	Node* pre = head;
	Node* current = head;
	while (current != NULL) {
		temp = current;
		while (temp != NULL && uM.find(temp->data)->second >= 2) {
			temp = temp->next;
		}
		if (current != temp) {
			pre->next = temp;
			current = temp;
		}
		else {
			current = current->next;
		}
		if (current != NULL && uM.find(current->data)->second == 1) {
			pre = current;
		}
	}
}

int main() {
	SingleLinkedList list1;
	list1.insert(1), list1.insert(2), list1.insert(2), list1.insert(3);
	list1.print();
	cout << endl;

	//list1.removeDuplicatesAll();
	list1.removeDuplicatesAll2();
	list1.print();
	cout << endl;

	return 0;
}
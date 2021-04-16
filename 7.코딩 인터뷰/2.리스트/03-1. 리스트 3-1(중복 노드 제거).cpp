/*
03-1. 리스트 3-1(중복 노드 제거)

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
문제 3-1) 중복 노드 제거
	정렬된 연결 리스트에서 중복된 노드를 제거하는 함수를 구현하라.

	예) 1 -> 1 -> 1 -> 2 -> 3-> 3   =>   1 -> 2 -> 3
*/

/*
출제 의도
	난이도: 쉬움
	연결 리스트 순회할 수 있는가?
	재귀를 사용해서 문제를 풀 수 있는가?
	정렬되지 않은 연결 리스트에서 중복 노드 제거하기.
*/

#include<iostream>
#include<unordered_set>
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
	void removeDuplicates();
	void removeDuplicates(int);
	void removeDuplicates2();
	void recursion(Node*);
	void removeDuplicates3();
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
풀이 1-1)
	순회하면서 temp(= current->next...)->data != current->data일때 current->next = temp한다. 

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

void SingleLinkedList::removeDuplicates() {
	Node* current = head;
	while (current != NULL) {
		Node* temp = current;
		while (temp != NULL && temp->data == current->data) {
			temp = temp->next;
		}
		current->next = temp;
		current = temp;
	}
}

/*
풀이 1-2)
	순회하면서 pre->data != current->data일때 pre->next = current한다.

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

void SingleLinkedList::removeDuplicates(int K) {
	Node* pre = head;
	Node* current = head;
	while (current != NULL) {
		if (pre->data != current->data) {
			pre->next = current;
			pre = current;
		}
		else {
			current = current->next;
		}
	}
	if (pre->next != NULL) {
		pre->next = NULL;
	}
}

/*
풀이 2)
	중복 노드를 제거하는 재귀함수를 구현한다. (재귀방향 = 순회)
	각 위치에서 중복을 제거하고 다음 위치로 넘어간다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

void SingleLinkedList::removeDuplicates2() {
	recursion(head);
}
void SingleLinkedList::recursion(Node* current) {
	if (current->next == NULL) {
		return;
	}
	else {
		if (current->data == current->next->data) {
			current->next = current->next->next;
			recursion(current);
		}
		else {
			recursion(current->next);
		}
	}
}

/*
풀이 3)
	(+정렬되어 있지 않다면)
	순회하며 unordered_set 자료구조를 사용하여 중복을 확인한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

void SingleLinkedList::removeDuplicates3() {
	unordered_set<int> uS;
	Node* pre = NULL;
	Node* current = head;
	while (current != NULL) {
		if (uS.find(current->data) != uS.end()) {
			pre->next = current->next;
		}
		else {
			uS.insert(current->data);
			pre = current;
		}
		current = current->next;
	}
}

int main() {
	SingleLinkedList list1;
	list1.insert(1), list1.insert(1), list1.insert(1), list1.insert(2), list1.insert(3), list1.insert(3);
	list1.print();
	cout << endl;

	//list1.removeDuplicates();
	//list1.removeDuplicates(1);
	//list1.removeDuplicates2();
	list1.removeDuplicates3();
	list1.print();
	cout << endl;

	return 0;
}
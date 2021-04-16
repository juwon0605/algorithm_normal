/*
01. 리스트 1(문자열 뒤집기)

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
문제 1) LinkedList 뒤집기
	단일 연결 리스트를 뒤집는 함수를 구현하라.

	예) 1 -> 2 -> 3   =>  3 -> 2 -> 1
*/

/*
출제 의도
	난이도: 쉬움(순회)~보통(재귀)
	연결 리스트 데이터 구조를 이해하고 있는가?
	재귀(recursion)와 순회(iteration)을 모두 활용할 수 있는가?
*/

#include<iostream>
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
	void reverse();
	void reverse2();
	Node* recursion(Node*);
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
	순회하며 포인터 방향을 뒤집는다.

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

void SingleLinkedList::reverse() {
	Node* current = head;
	Node* pre = NULL;
	Node* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	}
	head = pre;
}

/*
풀이 2)
	포인터 방향을 뒤집는 재귀함수를 구현한다. (재귀방향 = 역순회)
	각 위치에서 next를 호출해서 next->next = current로 방향을 뒤집는다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

void SingleLinkedList::reverse2() {
	Node* tail = recursion(head);
	tail->next = NULL;
}
Node* SingleLinkedList::recursion(Node* current) {
	if (current->next == NULL) {
		head = current;
		return current;
	}
	else {
		Node* next = recursion(current->next);
		next->next = current;
		return current;
	}
}

int main() {
	SingleLinkedList list;
	for (int i = 1; i <= 3; i++) {
		list.insert(i);
	}
	list.print();
	cout << endl;

	list.reverse();
	list.print();
	cout << endl;

	list.reverse2();
	list.print();
	cout << endl;
	return 0;
}
/*
02-2. 리스트 2-2(중간 노드 찾기)

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
문제 2-2) 중간 노드 찾기
	연결 리스트의 중간 노드를 찾는 코드를 작성하라.

	예) findFromLast(1 -> 2 -> 3 -> 4) 2를 return한다.
	예) findFromLast(1 -> 2 -> 3 -> 4 -> 5) 3을 return한다.

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
	int findMiddle();
	int findMiddle2();
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
	(size를 안다면) 순회하면서 중간 노드를 찾아 return한다.

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

int SingleLinkedList::findMiddle() {
	Node* temp = head;
	int k = (size % 2 == 0 ? size / 2 - 1 : size / 2);
	while (k--) {
		temp = temp->next;
	}
	return temp->data;
}

/*
풀이 2)
	(size를 모른다면) left, right 포인터를 2개 선언해서 위치를 left->next, right->next->next 한다.
	오른쪽 포인터가 끝나는 지점 일 때의 왼쪽 포인터의 data를 return한다.

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

int SingleLinkedList::findMiddle2() {
	Node* left = head;
	Node* right = head;
	while (right->next != NULL) {
		right = right->next;
		if (right == NULL || right->next == NULL) break;
		right = right->next;
		left = left->next;
	}
	return left->data;
}

int main() {
	SingleLinkedList list1, list2;
	for (int i = 1; i <= 4; i++) {
		list1.insert(i);
		list2.insert(i);
	}
	list2.insert(5);
	list1.print();
	cout << endl;
	list2.print();
	cout << endl;

	cout << list1.findMiddle() << endl;
	cout << list2.findMiddle() << endl;
	cout << list1.findMiddle2() << endl;
	cout << list2.findMiddle2() << endl;
	return 0;
}
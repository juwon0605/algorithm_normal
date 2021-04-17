/*
04-1. 리스트 4-1(사이클 판단)

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
문제 4-1) 사이클 판단
	주어진 연결 리스트가 원형 연결 리스트인지 단일 연결 리스트인지 확인하는 함수를 구현하라.

	예) 1 -> 2 -> 3 -> 1   => true
	예) 1 -> 2 -> 3 -> 2   => true
	예) 1 -> 2 -> 3          => false
*/

/*
출제 의도
	난이도: 보통
	연결 리스트를 순회할 수 있는가?
	해시를 활용할 수 있는가?
	최적의 솔루션을 찾을 수 있는가?
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
	bool hasCycle();
	bool hasCycle2();
	bool hasCycle3();
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
	순회하면서 각 Node에서 자기 자신으로 돌아오는 경우가 있는지 확인한다.
	이 경우 뒤의 Node끼리 Cycle이 있으면 무한루프가 발생한다!
	(잘못된 풀이법이라는걸 언급하고 넘어가는 것이 좋다)

	시간 복잡도: --
	공간 복잡도: --
*/

/*
풀이 2)
	unordered_set 자료구조를 활용하여 중복이 발생하는지 확인한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

bool SingleLinkedList::hasCycle2() {
	unordered_set<Node*> uS;
	Node* current = head;
	while (current != NULL) {
		if (uS.find(current) != uS.end()) {
			return true;
		}
		else {
			uS.insert(current);
		}
		current = current->next;
	}
	return false;
}

/*
풀이 3)
	서로 다른 속도로 움직이는 두 포인터를 사용하여 겹침이 발생하는지 확인한다.

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

bool SingleLinkedList::hasCycle3() {
	Node* slow = head;
	Node* fast = head;
	while (1) {
		for (int i = 0; i < 2; i++) {
			fast = fast->next;
			if (fast == NULL) return false;
			if (fast == slow) return true;
		}
		slow = slow->next;
	}
	return false;
}

int main() {
	SingleLinkedList list1, list2, list3;
	for (int i = 1; i <= 3; i++) {
		list1.insert(i);
		list2.insert(i);
		list3.insert(i);
	}
	Node* tail = list1.head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = list1.head;

	tail = list2.head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = list2.head->next;

	cout << list1.hasCycle3() << endl;
	cout << list2.hasCycle3() << endl;
	cout << list3.hasCycle3() << endl;
	return 0;
}
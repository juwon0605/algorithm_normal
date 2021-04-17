/*
04-2. 리스트 4-2(사이클 시작 지점 찾기)

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
문제 4-2) 사이클 시작 지점 찾기
	결 리스트에서 순회가 시작하는 노드를 찾는 코드를 작성하라..

	예) 1 -> 2 -> 3-> 4-> 5 -> 3 이 주어진 경우 3을 찾아야 한다.
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
	int hasCycle();
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
풀이 )
	서로 다른 속도로 움직이는 두 포인터를 사용하여 겹침이 발생하는지 확인한다.
	노드의 시작점부터 사이클 시작 지점까지의 거리를 m, 사이클의 길이를 n,
	사이클의 시작 지점부터 겹친 노드까지의 거리를 k라고 할때
	두 Node 포인터의 이동 거리는 아래와 같다.
	slow:  i = m + pn + k
	fast: 2i = m + qn + k
	i * 2 = 2i로 두 식을 연립하면 m = (q-qp)n - k가 성립한다.
	m은 사이클의 시작점이고 (q-qp)n - k도 사이클의 시작점이다.
	따라서 slow와 fast가 겹칩이 발생했을때, slow를 노드의 시작점에 위치하게 하고 fast는 그대로 둔다.
	slow와 fast 포인터를 한 노드씩 움직이게 할때, m번째에 두 포인터는 다시 겹치게 되고
	겹치는 지점이 사이클의 시작지점이 된다.

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

int SingleLinkedList::hasCycle() {
	Node* slow = head;
	Node* fast = head;
	while (1) {
		for (int i = 0; i < 2; i++) {
			fast = fast->next;
			if (fast == NULL) return 0;	// No Cycle
		}
		slow = slow->next;
		if (fast == slow) break;
	}
	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow->data;
}

int main() {
	SingleLinkedList list1, list2, list3;
	for (int i = 1; i <= 5; i++) {
		list1.insert(i);
		list2.insert(i);
		list3.insert(i);
	}
	Node* tail = list1.head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = list1.head->next->next;

	tail = list2.head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = list2.head;

	cout << list1.hasCycle() << endl;
	cout << list2.hasCycle() << endl;
	cout << list3.hasCycle() << endl;
	return 0;
}
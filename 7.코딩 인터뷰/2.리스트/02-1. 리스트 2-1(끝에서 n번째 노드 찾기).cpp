/*
02-1. 리스트 2-1(끝에서 n번째 노드 찾기)

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
문제 1) 끝에서 n번째 노드 찾기
	단일 연결 리스트의 끝에서 n번째에 위치한 노드를 찾는 함수를 구현하라.

	예) findFromLast(1 -> 2 -> 3 -> 4, 2), 끝에서 2번째에 위치한 3을 리턴한다.
*/

/*
출제 의도
	난이도: 보통
	링크드 리스트 특징을 이해하는가?
	최적화를 시도하는가?
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
	int findFromLast(int);
	int findFromLast2(int);
	int findFromLast3(int);
	int findFromLast4(int);
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
	(size를 안다면) 순회하면서 끝에서 n번째 노드를 찾아 return한다.

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

int SingleLinkedList::findFromLast(int k) {
	if (k > size) return -1;
	Node* temp = head;
	for (int i = 0; i < size - k; i++) {
		temp = temp->next;
	}
	return temp->data;
}

/*
풀이 2)
	(size를 모른다면) unordered_map을 사용하여 순회하며 insert한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

int SingleLinkedList::findFromLast2(int k) {
	Node* temp = head;
	unordered_map<int, int> uM;
	int idx = 0;
	while (temp != NULL) {
		uM.insert(make_pair(idx++, temp->data));
		temp = temp->next;
	}
	if (k > uM.size()) return -1;
	return uM.find(uM.size() - k)->second;
}

/*
풀이 3)
	(size를 모른다면) size를 구한 뒤에, 순회하면서 끝에서 n번째 노드를 찾아 return한다.

	시간 복잡도: O(N)	(O(N) + O(N))
	공간 복잡도: O(1)
*/

int SingleLinkedList::findFromLast3(int k) {
	Node* temp = head;
	int cnt = 0;
	while (temp != NULL) {
		cnt++;
		temp = temp->next;
	}
	temp = head;
	for (int i = 0; i < cnt - k; i++) {
		temp = temp->next;
	}
	return temp->data;
}

/*
풀이 4)
	(size를 모른다면) k위치 만큼 차이나는 포인터를 2개 선언해서
	오른쪽 포인터가 끝나는 지점 일 때의 왼쪽 포인터의 data를 return한다.

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

int SingleLinkedList::findFromLast4(int k) {
	Node* left = head;
	Node* right = head;
	for (int i = 0; i < k; i++) {
		right = right->next;
	}
	while (right != NULL) {
		left = left->next;
		right = right->next;
	}
	return left->data;
}

int main() {
	SingleLinkedList list;
	for (int i = 1; i <= 4; i++) {
		list.insert(i);
	}
	list.print();
	cout << endl;

	cout << list.findFromLast(2) << endl;
	cout << list.findFromLast2(2) << endl;
	cout << list.findFromLast3(2) << endl;
	cout << list.findFromLast4(2) << endl;
	return 0;
}
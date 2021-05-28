/*
02. 큐 2(LRU 캐시 구현)

큐(Queue)
스택과 비슷한 데이터 구조이지만, 데이터 삽입과 삭제가 각기 다른 쪽에서 이루어지는 정렬된 리스트이다.
가장 처음에 삽입된 데이터가 제일 먼저 삭제된다. (FIFO)
가장 마지막에 삽입된 데이터가 제일 마지막에 삭제된다. (LILO)

큐 오퍼레이션
EnQueue: 큐에 데이터 넣기
DeQueue: 큐에서 데이터 빼기

큐 구현
(동적) 원형 배열
연결 리스트

오퍼레이션 별 시간 복잡도
EnQueue: O(1)
DeQueue: O(1)

자바의 Queue 인터페이스
add(E e): 넣을 수 있으면 넣고 true를 리턴, 더이상 큐에 넣을 수 없을 때는 IllegalStateException을 던진다.
offer(E e): 넣을 수 있으면 넣고 true를 리턴, 넣을 수 없는 경우에는 false 리턴.
E remove(): 꺼낼 수 있으면 꺼내주고 꺼낼 것이 없으면 NoSuchElementException을 던진다.
E poll(): 꺼낼 수 있으면 꺼내주고 없으면 null 리턴.
E element(): 큐의 head에 들어있는 값을 리턴하지만 큐에서 빼지는 않는다. 큐에 데이터가 없으면 NoSuchElementException을 던진다.
E peek(): 큐의 head에 들어있는 값을 리턴하지만 큐에서 빼지는 않는다. 큐에 데이터가 없으면 null 리턴.

*/

/*
출제 의도
	난이도: 보통에서 어려움
	LRU 캐시 개념을 알고 있거나 이해할 수 있는가?
	LRU 오퍼레이션을 효율적으로 구현할 수 있는가?
	Queue와 HashSet 또는 HashMap을 활용할 수 있는가?
*/

/*
문제 2) LRU 캐시 구현
	최대 n개 만큼의 가장 최근에 접근한 데이터를 캐싱하는 LRU (least recently used) 캐시를 구현하라.

	입력값 number는 1부터 100까지의 숫자가 랜덤하게 입력된다. 그 중에 최대 n (1보다 크고 9보다 작은)개 만큼의 데이터만 캐시할 수 있다. n개를 넘는 새로운 값이 들어오면 그 중에서 가장 오래전에 접근한 데이터를 삭제하고 number를 캐시에 추가한다.

	다음 오퍼레이션을 구현하라.
	query(int number): number에 해당하는 입력값을 캐시에 추가한다.
	print() 현재 캐시하고 있는 데이터를 출력한다.

	예) 1 2 3 1 4 5 2 2 1
*/

#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

#define cacheSize 3

/*
풀이 1)
	deque를 사용해서 구현한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

class Cache1
{
public:
	void query(int number) {
		iter = find(number);
		if (iter != cache.end()) {
			cache.erase(iter);
			cache.push_front(number);
		}
		else {
			if (cache.size() == cacheSize) {
				cache.erase(cache.end());
			}
			cache.push_front(number);
		}
	}

	void print() {
		for (int i = 0; i < cache.size(); i++) {
			cout << cache[i] << " ";
		}
		cout << endl;
	}

	deque<int>::iterator find(int number) {
		iter = cache.begin();
		for (int i = 0; i < cache.size(); i++) {
			if (*iter == number) return iter;
			iter++;
		}
		return cache.end();
	}

private:
	deque<int> cache;
	deque<int>::iterator iter;
};

/*
풀이 2)
	unordered map와 double linked list를 사용해서 구현한다.

	시간 복잡도: O(1)
	공간 복잡도: O(N)
*/

class Node {
public:
	int data;
	Node* pre = NULL;
	Node* next = NULL;
};

class Cache2 {
public:
	void query(int number) {
		iter = uMap.find(number);
		if (iter != uMap.end()) {
			redirect(iter->second);
			addToHead(iter->second);
			uMap.erase(iter);
		}
		else {
			Node* nodeToAdd = new Node();
			nodeToAdd->data = number;
			if (uMap.size() == cacheSize) {
				iter = uMap.find(tail->data);
				redirect(*tail);
				uMap.erase(iter);
			}
			addToHead(*nodeToAdd);
			//uMap.insert(make_pair<number, *nodeToAdd>);
			uMap[number] = *nodeToAdd;
		}
	}

	void print() {
		Node* current = head;
		while (current != NULL) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	void redirect(Node target) {
		// target의 앞의 Node redirect
		if (target.pre != NULL) {
			target.pre->next = target.next;
		}
		else {
			head = target.next;
		}
		// target의 뒤의 Node redirect
		if (target.next != NULL) {
			target.next->pre = target.pre;
		}
		else {
			tail = target.pre;
		}
	}

	void addToHead(Node target) {
		target.pre = NULL;
		target.next = head;
		if (head != NULL) {
			head->pre = &target;
		}
		head = &target;
		if (tail == NULL) {
			tail = head;
		}
	}

private:
	Node* head;
	Node* tail;
	unordered_map<int, Node> uMap;
	unordered_map<int, Node>::iterator iter;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int example[] = { 1, 2, 3, 1, 4, 5, 2, 2, 1 };
	//Cache1 cache;
	Cache2 cache;
	for (int i = 0; i < sizeof(example) / sizeof(example[0]); i++) {
		cache.query(example[i]);
		cache.print();
	}
	return 0;
}
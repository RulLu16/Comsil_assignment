#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* link;
	Node(T element) {
		data = element;
		link = 0;
	}
};

template <typename T>
class LinkedList
{
protected:
	Node<T> *first;
	int current_size;
public:
	LinkedList() {
		first = 0;
		current_size = 0;
	};
	int GetSize() { return current_size; };
	void Insert(T element);
	virtual bool Delete(T& element);
	void Print();
};

template <typename T>
void LinkedList<T>::Insert(T element) {
	Node<T>* newnode = new Node<T>(element);
	newnode->link = first;
	first = newnode;
	current_size++;
}

template <typename T>
bool LinkedList<T>::Delete(T& element) {
	if (first == 0) return false;
	Node<T>* current = first, *previous = 0;
	while (1) {
		if (current->link == 0)
		{
			if (previous) previous->link = current->link;
			else
				first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}
	element = current->data;
	delete current;
	current_size--;
	return true;
}

template <typename T>
void LinkedList<T>::Print() {
	if (first == 0) return;
	int i = 1;
	Node<T>* current = first;
	while (1)
	{
		if (current->link == 0)
		{
			cout << "[" << i << "|" << current->data << "]" << endl;
			break;
		}
		else
		{
			cout << "[" << i << "|" << current->data << "]" << "->";
			current = current->link;
			i++;
		}
	}
}

template <typename T>
class Stack : public LinkedList<T> {
	using LinkedList<T>::first;
	using LinkedList<T>::current_size;
public:
	bool Delete(T& element);
};

template <typename T>
bool Stack<T>::Delete(T& element) {
	if (first == 0) return false;
	Node<T> *current = first;
	first = current->link;
	delete current;
	current_size--;
	return true;
}
/*int main() {
	double dVal;
	string strVal;
	LinkedList<double> dList;
	LinkedList<string> strList;

	dList.Insert(3.14);
	dList.Insert(123456);
	dList.Insert(-0.987654);
	dList.Print();
	dList.Delete(dVal);
	cout << "삭제된 마지막 원소: " << dVal << endl;
	dList.Print();
	dList.Insert(777.777);
	dList.Print();
	dList.Delete(dVal);
	cout << "삭제된 마지막 원소: " << dVal << endl;
	dList.Delete(dVal);
	cout << "삭제된 마지막 원소: " << dVal << endl;
	dList.Print();
	dList.Delete(dVal);
	cout << "삭제된 마지막 원소: " << dVal << endl;
	dList.Print();

	strList.Insert("This");
	strList.Insert("is a");
	strList.Insert("Template");
	strList.Insert("Example");
	strList.Print();
	strList.Delete(strVal);
	cout << "삭제된 마지막 원소: " << strVal << endl;
	strList.Insert("Class");
	strList.Print();

	return 0;
}*/
void prnMenu(){
	cout<<"*******************************************"<<endl;
	cout<<"* 1. 삽입    2. 삭제    3. 출력   4. 종료 *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;
	cout<<"원하시는 메뉴를 골라주세요: ";
}

int main(){
	    int mode, selectNumber, tmpItem;
		LinkedList<int> *p;
		bool flag = false;

		cout<<"자료구조 선택(1: Stack, Other: Linked List): ";
		cin>>mode;
						    
		if(mode == 1)
			p = new Stack<int>();    // 정수를 저장하는 스택
			
		else
			p = new LinkedList<int>();


		do{
			prnMenu();
			cin>>selectNumber;
			
			switch(selectNumber){ 
				case 1:
					cout<<"원하시는 값을 입력해주세요: ";
					cin>>tmpItem;    p->Insert(tmpItem);
					cout<<tmpItem<<"가 삽입되었습니다."<<endl;
					break;
					
				case 2:
					if(p->Delete(tmpItem)==true)
						cout<<tmpItem<<"가 삭제되었습니다."<<endl;
						
					else cout<<"비어있습니다. 삭제 실패"<<endl;
					break;
					
				case 3:
					cout<<"크기: "<<p->GetSize()<<endl;
					p->Print();
					break;
					
				case 4:
					flag = true;     break;
					
				default:
					cout<<"잘못 입력하셨습니다."<<endl;
					break;
			
			}
			
			if(flag) break;
			
		} while(1);
		
		return 0;
}
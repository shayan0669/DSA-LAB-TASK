#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		
		Node(int val){
			data = val;
			next = NULL;
		}
};

class LinkedList{
	private:
		Node* head;
	public:
		LinkedList(){
			head= NULL;			
		}
		void append(int val){
			Node* newNode = new Node(val);
			if(head == NULL){
				head = newNode;
				return;
			}
			Node* temp =head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
		void display(){
			Node* temp = head;
			while(temp != NULL){
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout<< "NULL"<< endl;
		}
		void moveKNodesToEnd(int k){
			if(head == NULL || k <=0) return;
			
			Node* temp = head;
			int count = 1;
			
			while(count < k && temp != NULL){
				temp = temp->next;
				count++;
			}
			if(temp == NULL || temp->next == NULL) return;
			
			Node* kthNode = temp;
			Node* newHead = temp->next;
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next= head;
			head = newHead;
			kthNode->next = NULL;
		}
		void initializeWithValues() {
        append(10);
        append(20);
        append(30);
        append(40);
        append(50);
        append(60);
        append(70);
};

int main() {
    LinkedList list;
    list.initializeWithValues();
    cout << "Original Linked List:" << endl;
    list.display();
    int k;
    cout << "\nEnter the number of nodes to move to the end: ";
    cin >> k;
    list.moveKNodesToEnd(k);
    cout << "\nLinked List after moving first " << k << " nodes to the end:" << endl;
    list.display();
    return 0;
}
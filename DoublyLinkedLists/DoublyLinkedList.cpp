// DoublyLinkedList.cpp : 

#include "pch.h"
#include <iostream>
using namespace std;

template <typename T>
struct Generic_Node {
	T data;
	struct Generic_Node *next;
	struct Generic_Node *prev;
};

template <typename T>
class LinkedList {
private:
	Generic_Node<T> *head, *tail;

public:
	LinkedList<T>() {
		head = NULL;
		tail = NULL;
	}

	
	bool isEmpty();
	void display();
	void createNode(const T& t);
	void insert_position(int pos, const T& t);
	void remove_position(int pos);
	void delete_first();
	void delete_last();
};

/* We make a temporary node and pass the address of the head node to it.Now we want 
* to print all the nodes on the screen.So we need a loop which runs as many times as nodes exist.
* Every node contains the address of the next node so the temporary node walks through the 
* whole linked list.If the temporary node becomes equal to NULL then the loop would be terminated.
*/

template <typename T>
void LinkedList<T>::display() {

	Generic_Node<T> *displayNode = new Generic_Node<T>;

	displayNode = head;

	while (displayNode != NULL) {
		std::cout << displayNode->data << "\t";
		displayNode = displayNode->next;
	}
}

	template <typename T>
	bool LinkedList<T>::isEmpty() {
		return head == NULL;
	};

	template <typename T>
	void LinkedList<T>::createNode(const T& t) {
		Generic_Node<T> *temp = new Generic_Node<T>;
		temp->data = t;
		temp->next = NULL;
		
		if (isEmpty()) {
			head = temp;
			tail = temp;
			temp = NULL;

		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	// We are adding the new node before the desired position node.

	template <typename T>
	void LinkedList<T>::insert_position(int pos, const T& value) {

		Generic_Node<T> *pre = new Generic_Node<T>;
		Generic_Node<T> *cur = new Generic_Node<T>;
		Generic_Node<T> *temp = new Generic_Node<T>;

		cur = head;

		for (int i = 1; i < pos; i++) {
			pre = cur;
			cur = cur->next;
		}

		temp->data = value;
		pre->next = temp;
		temp->next = cur;
		
	}

	template <typename T>
	void LinkedList<T>::remove_position(int pos) {
		Generic_Node<T> *previous = new Generic_Node<T>;    // predecessor
		Generic_Node<T> *current = new Generic_Node<T>;    // successor 

		current = head;
		
		for (int i = 1; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}
		  
		previous->next = current->next;
		
	}


	// Declare a temp pointer and pass the address of the first node, i.e. head to this pointer.
	// Declare the second node of the list as head as it will be the first node of linked list after deletion.
    // Delete the temp node.

	template <typename T>
	void LinkedList<T>:: delete_first() {

		Generic_Node<T> *temp = new Generic_Node<T>;

		temp = head;
		head = head->next;

		delete temp;

	}

	/* The previous node will point to the second to the last node and 
	*  the current node will point to the last node, i.e. node to be deleted. 
	*  We would delete this node and make the previous node as the tail.
	*/
	template <typename T>
	void LinkedList<T>::delete_last() {
		
		Generic_Node<T> *current = new Generic_Node<T>;
		Generic_Node<T> *previous = new Generic_Node<T>;
		
		current = head;

		while (current->next != NULL) {
			previous = current;
			current = current->next;
		}

		tail = previous;
		previous->next = NULL;

		delete current;

	}


int main()
{
	LinkedList<int> newLinkedList;
	
	newLinkedList.createNode(25);
	newLinkedList.createNode(50);
	newLinkedList.createNode(90);
	newLinkedList.createNode(40);

	cout << "\n--------------------------------------------------\n";
	cout << "---------------Displaying All nodes---------------";
	cout << "\n--------------------------------------------------\n";

	newLinkedList.display();

	cout << "\n--------------------------------------------------\n";
	cout << "-------------Inserting At Particular--------------";
	cout << "\n--------------------------------------------------\n";
	newLinkedList.insert_position(4, 60);
	newLinkedList.display();

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Deleting At Particular--------------";
	cout << "\n--------------------------------------------------\n";

	newLinkedList.remove_position(2);
	newLinkedList.display();

	cout << "\n--------------------------------------------------\n";
	cout << "----------------Deleting At Start-----------------";
	cout << "\n--------------------------------------------------\n";
	newLinkedList.delete_first();
	newLinkedList.display();

	cout << "\n--------------------------------------------------\n";
	cout << "-----------------Deleting At End-------------------";
	cout << "\n--------------------------------------------------\n";

	newLinkedList.delete_last();
	newLinkedList.display();

	return 0;
}
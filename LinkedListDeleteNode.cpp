#include <iostream>
#include <stdlib.h>
#include <stdio.h>


//to delete a node we need 2 things
/*
1)fix the links
2)free the space taken by the node
*/

struct Node {
	int data;
	struct Node* next;
};

Node* head;//global accessible to all

//insert an integer at end of list
void Insert(int data, int n){
	
}

//print all elements in the list
void Print(){
	
}

//delete node at position n
void Delete(int n){
	//n-1 node
	struct Node* temp1 = head;
	//special case if we want to delete the head node
	if (n == 1) {
		head = temp1->next;//head now points to second node
		free(temp1);
		return;//for n!=1 we should not execute the code below
	}
	int i;
	//to go to the n-1 node we need to use a loop
	for (i = 0; i < n - 2; i++) {
		temp1 = temp1->next;
		//temp1 points to n-1 Node
		struct Node* temp2 = temp1->next;//nth node
		temp1->next = temp2->next;//adjust the link part of n-1 node to point at n+1 node
		//temp2 stores the nth node referenced to the nth node so we can make a call to free
		free(temp2);//free deallocates where our memory is allocated through malloc
		
	}
}
int main()
{
	head = NULL;//empty list
	Insert(2,0);
	Insert(4,0);
	Insert(6,0);
	Insert(5,0);//List : 2,4,6,5 cause we are always inserting from the end
	Print();
	int n;
	std::cout << "Enter a position ";
	scanf_s("%d", &n);
	Delete(n);
	Print();

}

//Linked list Data Structure implementation 
//Learning from the best https://www.youtube.com/watch?v=B31LgI4Y4DQ&list=PLWKjhJtqVAbmUE5IqyfGYEYjrZBYzaT4m&index=8
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    Node* next;//points to the next list
};

//pointer to pointer is **
void Insert(Node** head, int x) {
    Node* temp = (Node*)malloc(sizeof(Node));//malloc returns a pointer variable to node
    temp->data = x;//dereferencing the data
    temp->next = NULL;
    if (*head != NULL) temp->next = *head;
    *head = temp;//head is no longer null but now has the value of temp
    
    //we are making a node
    //we have the variables temp where we store the address
    //temp will take some space in the memory
    
}

void Print(Node* head) {
    //Node* temp = head;//set the address of the head node
    std::cout << "List is: ";
    while (head != NULL) {
        std::cout << " "<< head->data;//print the value
        head = head->next;//this statement will keep going to the next node
    }
    std::cout << " " << std::endl;
}

int main()
{
    Node* head = NULL;//empty list
    std::cout << "How many numbers?" << std::endl;
    int n, i, x;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        std::cout << "Enter the number" << std::endl;
        scanf_s("%d", &x);
        Insert(&head,x);//head is already a pointer to node
        Print(head);
    }
}

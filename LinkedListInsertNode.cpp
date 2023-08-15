#include <iostream>
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;//data of type integer
    struct Node* next;//next of type pointer to node
    //make a pointer to node that will always store the address of the first head node
};

//the only wa we can access a malloc variable is through pointers?
struct Node* head;//global variable 
void Print() {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << " " << temp->data;
        temp = temp->next;
    }
    std::cout << "";
}
void Insert(int data, int n) {
    //to make a node we will have to make a call to malloc
    //struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*)); this is the C way
    Node* temp1 = new Node();//this c++ way which is much more cleaner
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1) {
        //we want to set the link field of the newly created node if n == 1
        //as whatever the existing head is
        temp1->next = head;
        //then adjust this variable to point to the new head
        //which will be this newly created node
        head = temp1;
        //we will not execute any further that is why we will be returning
        return;
    }
    //our n-1 logic
    Node* temp2 = head;
    //we will run a loop that will go through the n-1 node
    //we will the run the loop at n - 2 because right now we are pointing to head line 30 
    //which is the first node
    for (int i = 0; i < n - 2; i++) {
        temp2 = temp2->next;//this -2 times will be pointing to temp2 to n-1 at node
    }
    temp1->next = temp2->next;//we need to set the next link field of newly created node
    //as the link field of this n-1 node
    //then we can adjust the link of the n-1 node to point to our newly created node
    temp2->next = temp1;
    
}


int main()
{
    head = NULL;//the list is empty
    Insert(2, 1);// List: 2
    Insert(3, 2);//List: 2, 3
    Insert(4, 1);//List: 4, 2, 3
    Insert(5, 2);//List: 4, 5, 2, 3
    Print();

      
}

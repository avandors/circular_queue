#include <stdio.h>
#include <stdlib.h>

//create a structure of node
typedef struct node{
	struct node* prev;
	int data;
	struct node* next;
}node_t;

//make a head of doubly linked list as the public
node_t *head;

//Take out LL in console
void printlist(node_t* head){
	node_t* tempo = head;
	while(tempo!=NULL){
		printf("%d ,",tempo->data);
		tempo = tempo->next;
	}	
}

//when take value and position create node a link in to doubly LL
void insertNode(node_t *head, int value, int position){
	int real_pos = position -2;
	node_t *trvs = head;

	int i=0;
	while(i!=real_pos){
		trvs = trvs->next;
		i++;
	}

	//create node
	node_t *newnode;
	newnode = (node_t*)malloc(sizeof(node_t));
	newnode->data = value;


	//link newnode to the doubly linked list
	newnode->next = trvs->next;
	trvs->next->prev = newnode;

	trvs->next = newnode;
	newnode->prev = trvs;
}

//main user accesible area
int main(){
	//take count of element from user to create LL
	int n;
	printf("Enter the count of elements: ");
	scanf("%d",&n);

	// create newnode pointer node and temp node for traverse LL
	node_t *newnode,*temp;
	head=NULL;

	//create linked list according to the user input
	int i=0; 
	while(i<n){
		newnode=(node_t*)malloc(sizeof(node_t));
		printf("Enter the %dth value: ",i+1);
		scanf("%d",&newnode->data);

		if(head==NULL){
			head=temp=newnode;
		}else{
			temp->next = newnode;
			newnode->prev = temp;
			temp=newnode;
			newnode->next = NULL;
		}
		i++;
	}


	printf("\n\n\n");
	printlist(head);
	printf("\n\n");

	//take input value and position from user
	int input,pos;
	printf("Input: ");
	scanf("%d",&input);
	printf("Position: ");
	scanf("%d",&pos);

	//pass input value and position to the operation
	printf("\n\n\n");
	insertNode(head,input,pos);
	printlist(head);
	printf("\n\n");

	return 0;
}



#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}Node;

typedef struct stack
{
	Node* top; 
}Stack;

Node* createNode(int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void createStack(Stack* p)
{
	p->top=NULL;
}

void display(Stack* p)
{

	if(p->top==NULL)
	{
		printf("stack is empty\n");
		return;
	}

	Node* t = p->top;
	while(t!=NULL)
	{
		printf("%d ", t->data);
		t = t->next;
	}
}

void push(Stack* p, int data)
{
	Node* temp = createNode(data);
	if(p->top==NULL)
	{
		p->top = temp;
	}
	else
	{
		temp->next = p->top;
		p->top = temp;
	}
	
}

void pop(Stack* p)
{
	if(p->top==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	
	Node* t = p->top;
	{
		p->top = p->top->next;
		free(t);
	}
}



int main()
{
	Stack q;
	createStack(&q);

	int data,choice;

	while(1)
	{
		printf("choose one:\n 1. display\n 2. push\n 3. pop\n 4. exit\n");
		scanf("%d",&choice);

		if(choice==4)
			break;

		switch(choice)
		{
			case 1:
				display(&q);
				break;
			case 2:
				printf("enter data:");
				scanf("%d",&data);
				push(&q,data);
				break;
			case 3:
				pop(&q);
				break;
		}
	}

	return 0;
}


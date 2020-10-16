#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next; 
}Node;

typedef struct head
{
	int cnt;
	Node* hd;
}head;

void initHead(head* p)
{
	p->cnt = 0;
	p->hd = NULL;
}

Node* createNode(int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void display(head* p)
{
	printf("Size of linked list:%d\n",p->cnt);

	if(p->hd==NULL)
	{
		printf("List is empty\n");

	}
	else
	{
		Node* t = p->hd;
		while(t!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		} 
	}
	printf("\n");
}

void addFirst(head* p, int data)
{
	Node* temp = createNode(data);

	if(p->hd==NULL)
	{
		p->hd = temp;
	}
	else
	{
		temp->next = p->hd;
		p->hd = temp;
	}
	p->cnt++;
}

void addi(head* p, int data, int pos)
{
	if(pos<1||pos>(p->cnt)+1)
	{
		printf("Invalid position\n");
		return;
	}

	Node* t = p->hd;
	Node* temp = createNode(data);
	if(pos==1)
	{
		if(p->hd==NULL)
		{
			p->hd = temp;
		}
		else
		{
			temp->next = p->hd;
			p->hd = temp;
		}
	}

	else if(pos==p->cnt+1)
	{
		while(t->next!=NULL)
		{
			t = t->next;
		}
		t->next = temp;
	}
	else
	{
		while(pos--)
		{
			if(pos==1)
			{
				temp->next = t->next;
				t->next = temp;
				return;
			}
			else
				t = t->next;
		}
	}
	p->cnt++;
}

void addLast(head* p, int data)
{
	Node* t = p->hd;
	Node* temp = createNode(data);

	if(p->hd==NULL)
	{
		p->hd = temp;
	}
	else
	{
		while(t->next!=NULL)
		{
			t = t->next;
		}
		t->next = temp;
	
	}
	p->cnt++;
}

void delFirst(head* p)
{
	if(p->hd==NULL)
	{
		printf("List is empty\n");
		return;
	}
	
	Node* t = p->hd;
	p->hd = t->next;
	p->cnt--;
	free(t);
}

void deli(head* p,int pos)
{
	if(pos<1||pos>p->cnt)
	{
		printf("Invalid position\n");
		return;
	}

	if(p->hd==NULL)
	{
		printf("List is empty\n");
		return;
	}

	Node* t = p->hd; 

	if(pos==1)
	{
		Node* t = p->hd;
		p->hd = t->next;
		p->cnt--;
		free(t);
	}
	else if(pos==p->cnt)
	{
		while(t->next->next!=NULL)
		{
			t = t->next;
		}
		free(t->next);
		t->next = NULL;
		p->cnt--;
	}
	else
	{
		while(pos--)
		{
			if(pos==1)
			{
				Node* temp = t->next;
				t->next = temp->next;
				free(temp);
				return;
			}
			else
			{
				t = t->next;
			}
		}

		p->cnt--;
	}
}

void delLast(head* p)
{	
	if(p->hd==NULL)
	{
		printf("List is empty\n");
		return;
	}

	if(p->hd->next==NULL)
	{
		free(p->hd);
		p->hd=NULL;
		p->cnt--;
		return;
	}
	
	Node* t = p->hd;

	while(t->next->next!=NULL)
	{
		t = t->next;
	}
	free(t->next);
	t->next = NULL;
	p->cnt--;

}

void revlist(head* p)
{
	Node* prev = NULL;
	Node* curr = p->hd;
	Node* next = NULL;

	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;

		prev=curr;
		curr=next;
	}

	p->hd=prev;

}

void disprev(Node* p)
{
	if(p==NULL)
	{
		printf("list is empty\n");
		return;
	}

	Node* t = p;
	if(t!=NULL)
	{
		disprev(t->next);
	}
	printf("%d ", t->data);
}

int main()
{
	head q;
	initHead(&q);

	int data;
	int pos;
	int choice;

	while(1)
	{
		printf("Choose one:\n 1. Display linked list\n 2. Add at first\n 3. Add at ith\n 4. Add at last\n 5. Delete first\n 6. Delete ith\n 7. Delete last\n 8. Exit\n 9. Reverse list\n 10. Display reverse list\n");
		scanf("%d", &choice);

		if(choice==8)
		{
			break;
		}

		switch(choice)
		{
			case 1:
				display(&q);	
				break;
			case 2:
				printf("Enter data:\n");
				scanf("%d",&data);
				addFirst(&q,data);
				break;
			case 3:
				printf("Enter data:\n");
				scanf("%d",&data);
				printf("Enter position\n");
				scanf("%d",&pos);
				addi(&q,data,pos);
				break;
			case 4:
				printf("Enter data:\n");
				scanf("%d",&data);
				addLast(&q,data);
				break;
			case 5:
				delFirst(&q);
				break;
			case 6:
				printf("Enter position\n");
				scanf("%d",&pos);
				deli(&q,pos);
				break;
			case 7:
				delLast(&q);
				break;
			case 9:
				revlist(&q);
				break;
			case 10:
				disprev(q.hd);
				break;

		}
	}
	return 0;
}

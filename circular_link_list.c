#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}Node;

typedef struct head
{
	int cnt;
	Node* hd;
}head;

void init(head* p)
{
	p->hd = NULL;
	p->cnt = 0;
}

Node* createNode(int data)
{
	Node* temp =(Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void display(head* p)
{
	printf("size:%d\n", p->cnt);
	if(p->hd==NULL)
	{
		printf("list is empty\n");
		return;
	}

	Node* t = p->hd;

	do
	{
		printf("%d ", t->data);
		t = t->next;
	}while(t!=p->hd);

	printf("\n");

}

void addf(head* p, int data)
{
	Node* temp = createNode(data);
	Node* t = p->hd;

	if(p->hd==NULL)
	{
		p->hd = temp;
		temp->next = p->hd;

	}

	else
	{	
		while(t->next!=p->hd)
		{
			t = t->next;
		}

		t->next = temp;
		temp->next = p->hd;
		p->hd = temp;
	}

	p->cnt++;

}

void addl(head* p, int data)
{
	Node* temp = createNode(data);
	Node* t = p->hd;
	if(p->hd==NULL)
	{
		p->hd = temp;
		temp->next = p->hd;
	}
	else
	{
		while(t->next!=p->hd)
		{
			t = t->next;
		}
		temp->next = t->next;
		t->next = temp;
	}

	p->cnt++;

}

void addi(head* p, int pos, int data)
{
	if(pos<1||pos>p->cnt+1)
	{
		printf("invalid pos\n");
		return;
	}

	Node* temp = createNode(data);
	Node* t = p->hd;

	if(pos==1)
	{
		if(p->hd==NULL)
		{
			p->hd = temp;
			temp->next = p->hd;
		}
		else
		{
			while(t->next!=p->hd)
			{
				t = t->next;
			}
			temp->next = p->hd;
			t->next = temp;
			p->hd = temp;
		}
	}
	else if(pos==p->cnt+1)
	{
		while(t->next!=p->hd)
		{
			t = t->next;
		}
		temp->next = p->hd;
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
			{
				t = t->next;
			}
		}
	}

	p->cnt++;

}

void delf(head* p)
{
	Node* t =p->hd;
	if(p->hd==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else if(p->hd->next==p->hd)
	{
		p->hd=NULL;
		free(t);
	}
	else
	{
		while(t->next!=p->hd)
		{
			t = t->next;
		}
		Node* t1 = p->hd;
		t->next = p->hd->next;
		p->hd = p->hd->next;
		free(t1);
	}

	p->cnt--;
}

void dell(head* p)
{
	Node* t = p->hd;
	if(p->hd==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else if(p->hd->next==p->hd)
	{
		p->hd=NULL;
		free(t);
	}
	else
	{
		while(t->next->next!=p->hd)
		{
			t = t->next;
		}
		Node* t1 = t->next;
		free(t1);
		t->next = p->hd;
	}
	p->cnt--;
}

void deli(head* p, int pos)
{
	Node* t = p->hd;
	Node* t1 = p->hd;
	if(pos<1||pos>p->cnt)
	{
		printf("invalid pos\n");
		return;
	}
	else if(pos==1)
	{
		if(p->hd==NULL)
		{
			printf("list is empty\n");
		}
		else if(p->hd->next==p->hd)
		{
			p->hd=NULL;
			free(t);
		}
		else
		{
			while(t->next!=p->hd)
			{
				t = t->next;
			}
			t->next = p->hd->next;
			p->hd = t->next;
			free(t1);
		}

	}
	else if(pos==p->cnt)
	{
		while(t->next->next!=p->hd)
		{
			t = t->next;
		}
		Node* t1 = t->next;
		t->next = p->hd;
		free(t1);

	}
	else
	{
		while(pos--)
		{
			if(pos==1)
			{
				Node* t1 = t->next;
				t->next = t->next->next;
				free(t1);
			}
			else
			{
				t = t->next;
			}
		}
	}
	p->cnt--;
}

int main()
{

	head* q;
	init(&q);

	int data,pos,choice;

	while(1)
	{
		printf("choose one:\n 1. display\n 2. add first\n 3. add last\n 4. add ith\n 5. del first\n 6. del last\n 7. del ith\n 8. exit\n");
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
				printf("enter data:\n");
				scanf("%d", &data);
				addf(&q,data);
				break;
			case 3:
				printf("enter data:\n");
				scanf("%d", &data);
				addl(&q,data);
				break;
			case 4:
				printf("enter pos:\n");
				scanf("%d",&pos);
				printf("enter data:\n");
				scanf("%d",&data);
				addi(&q,pos,data);
				break;
			case 5:
				delf(&q);
				break;
			case 6:
				dell(&q);
				break;
			case 7:
				printf("enter pos:");
				scanf("%d",&pos);
				deli(&q,pos);
				break;


		}
	}

	return 0;
}












#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* add_to_empty(struct node *tail,int data)
{
	struct node *temp=(struct node*)malloc (sizeof (struct node));
	temp->data=data;
	temp->next=temp;
	tail=temp;
	return tail;
	
}


 struct node* add_at_end(struct node *tail , int data)
 {
 	struct node *temp= (struct node*)malloc(sizeof(struct node));
	 temp->data=data;
	 temp->next=tail->next;
	 tail->next=temp;
	 tail=tail->next;
	 return tail;
	  
 }


struct node* create_list(struct node *tail)
{
	int n,data,i;
	printf("Enter the no. of nodes\n");
	scanf("%d",&n);
	
	if (n==0)
	return tail;
	else
	{
		printf("Enter the data of node 1 =");
		scanf("%d",&data);
		tail=add_to_empty(tail,data);
		
		for(i=1;i<n;i++)
		{
			
		printf("Enter the data of node %d =",i+1);
		scanf("%d",&data);
		tail=add_at_end(tail,data);
		}
	}
	return tail;
}

void print_data(struct node *tail)
{
	struct node *ptr;
	ptr=tail->next;
	if(ptr==NULL)
	printf("list is empty\n");
	else
	{
		do
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}while(ptr!=tail->next);
		
	}
}


int  count_data(struct node *tail)
{
	int count=0;
	struct node *ptr;
	ptr=tail;
	if(ptr==NULL)
	{
	printf("list is empty\n");
	return count =0;
	}
	else
	{
		 do{
		 	count++;
		 	ptr=ptr->next;
		 }while(ptr!=tail);
	}
	return count;
}

void print_nth_node(struct node *tail,int count)
{
	
	
	int n;
	printf("Enter the node to be printed from end \n");
	scanf("%d",&n);
	if (n>count)
	{
		printf("entered postion is not exist\n");
	}
	
	else{
	
	struct node *temp2=tail;
	int pos= (count-(n-1));
	while(pos!=1)
	{
		temp2=temp2->next;
		pos--;
	}
	temp2=temp2->next;
	printf("the node at postion %d from end is %d",n,temp2->data);
}
}

int main()
{
	struct node *tail=NULL;
	tail=create_list(tail);
	print_data(tail);
	int count=0;
	count=count_data(tail);
	printf("count =%d\n",count);
	print_nth_node(tail,count);
 } 

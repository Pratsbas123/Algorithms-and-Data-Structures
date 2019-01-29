// Insert Head and Nodes in Linked List
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

void first(struct node* head,int n)
{
    head->data=n;
    head->next=NULL;
}

void addNode(struct node *link,int n)
{
    node *x = new node;
    x->data=n;
    x->next=NULL;
    while(link)
    {
        if(link->next==NULL)
        {
            link->next=x;
            return;
        }
        link=link->next;
    }
}

void display(struct node *link)
{
    while(link)
    {
        cout<<link->data<<" ";
        link=link->next;
    }
    cout<<endl;
}

int main()
{
	struct node *link = new node;
	first(link,10);
	display(link);
	addNode(link,20);
	display(link);
	addNode(link,30);
	display(link);
	addNode(link,35);
	display(link);
	addNode(link,40);
	display(link);
	return 0;
}

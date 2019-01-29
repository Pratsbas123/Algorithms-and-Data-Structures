// Insert node at front and delete a node
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
/* Edit following
struct Node *searchNode(struct Node *head, int n) {
	Node *cur = head;
	while(cur) {
		if(cur-&gt;data == n) return cur;
		cur = cur-&gt;next;
	}
	cout &lt;&lt; "No Node " &lt;&lt; n &lt;&lt; " in list.\n";
}

bool deleteNode(struct Node **head, Node *ptrDel) {
	Node *cur = *head;
	if(ptrDel == *head) {
		*head = cur-&gt;next;
		delete ptrDel;
		return true;
	}

	while(cur) {
		if(cur-&gt;next == ptrDel) {
			cur-&gt;next = ptrDel-&gt;next;
			delete ptrDel;
			return true;
		}
		cur = cur-&gt;next;
	}
	return false;
}
*/
void first(struct node *link,int n)
{
    link->data=n;
    link->next=NULL;
}

void frontIns(struct node **link,int n)
{
    node *x=new node;
    x->data=n;
    x->next=*link;
    *link=x;
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
    struct node *link=new node;
    first(link,10);
    display(link);
    for(int i=15;i<=30;i+=5)
    {
        addNode(link,i);
        display(link);
    }
    int dat;
    cout<<endl<<"Inserting front"<<endl;
    cout<<"Enter data: ";
    cin>>dat;
    frontIns(&link,dat);
    display(link);
    /*
    cout<<"Delete data: ";
    cin>>dat;
    delnode(link,dat);
    display(link);
    */
    return 0;
}

#include<iostream>
using namespace std;

struct Node {
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root=NULL;

void Insert(int key)	{
	struct Node *t=root;
	struct Node *r=NULL, *p;
	if(root==NULL)	{
		p = new Node;
		p->data = key;
		p->lchild=p->rchild=NULL;
		root=p;
		return;
		}
	while(t!=NULL)	{
		r=t;
		if(key>t->data)
			t=t->rchild;
		else if(key<t->data)
			t=t->lchild;
		else
			return;
		}
	p = new Node;
	p->data = key;
	p->lchild=p->rchild=NULL;
	if(key<r->data)
		r->lchild=p;
	else
		r->rchild=p;	
	}
	
void inorder(struct Node *p)	{
	if(p)	{
		inorder(p->lchild);
		cout<<p->data<<" ";
		inorder(p->rchild);
	}
}
struct Node * Search(int key)	{
	struct Node *t=root;
	while(t!=NULL)	{
		if(key>t->data)
			t=t->rchild;
		else if(key<t->data)
			t=t->lchild;
		else
			return t;
	}
	return t;
}

//DELETE A NODE

//Height of the Tree
int Height(struct Node *p)	{
	int r, l;
	if(p==NULL)
		return 0;
	else	{
		l=Height(p->lchild);
		r=Height(p->rchild);
		return l>r?l+1:r+1;
	}	
}

//Inorder Predecessor
struct Node *InPre(struct Node *p )	{
	while(p && p->rchild!=NULL)
		p=p->rchild;
	return p;
}

//Inorder Successor
struct Node *InSucc(struct Node *p)	{
	while(p && p->lchild!=NULL)
		p=p->lchild;
	return p;
}

struct Node *Delete(struct Node *p, int key)	{
	struct Node *q;
	if(p==NULL)
		return NULL;
	if(p->lchild==NULL && p->rchild==NULL)	{
		if(p==root)
			root=NULL;
		delete(p);
		return NULL;
	}
	if(p->data<key)	
		p->rchild=Delete(p->rchild, key);
	else if(p->data>key)
		p->lchild=Delete(p->lchild, key);
	else	{
		if(Height(p->lchild)<Height(p->rchild))	{
			q=InPre(p->lchild);
			p->data=q->data;
			p->lchild=Delete(p->lchild, q->data);
		}
		else	{
			q=InSucc(p->rchild);
			p->data=q->data;
			p->rchild=Delete(p->rchild, q->data);
		}
	}
	return p;	
}
	
int main()	{
	Insert(10);
	Insert(5);
	Insert(20);
	Insert(8);
	Insert(30);
	inorder(root);
	cout<<endl;
	cout<<"Found at "<<Search(20);
	Delete(root, 20);
	cout<<endl;
	inorder(root); 
}

//Only either preorder or post order is required to generate a BST as inorder of a BST is always a sorted array of elemets
#include<bits/stdc++.h>
using namespace std;

struct Node	{
	int data;
	struct Node *lchild;
	struct Node *rchild;
}*root=NULL;

struct Stack	{
	int capacity;
	int top;
	Node** array;
}stack;

struct Stack* create(int size)	{
	Stack* stack = new Stack();
	stack->top == INT_MAX;
	stack->capacity=size;
	stack->array = new Node*[stack->capacity*sizeof(Node*)];
	return stack;
}

int isFull(Stack* stack)	{
	return stack->top == stack->capacity-1;
}

int isEmpty(Stack* stack)	{
	return stack->top == -1;
}
void push(Stack* stack, Node* x)	{
	if(isFull(stack))	{
		cout<<"Overflow";
		return;
		}
	else	
		stack->array[ ++stack->top] = x;
}

struct Node* pop(Stack* stack)	{
	if(isEmpty(stack))	{
		cout<<"Underflow";
		return NULL;
		}
	else
		return stack->array[stack->top--];
	}

struct Node* peek(Stack* stack)	{
	return stack->array[stack->top];
}

struct Node* newNode(int item)	{
	struct Node *t = new Node;
	t->data = item;
	t->lchild = t->rchild = NULL;
	return t;
}

struct Node* BST_pre(int pre[], int n)	{
	Stack* stack = create(n);
	int i = 0;
	struct Node *t, *p;
	root = newNode(pre[i]);
	i++;
	p = new Node;
	p=root;
	while(i<n)	{
		if(pre[i]<p->data)	{
			t = newNode(pre[i]);
			i++;
			p->lchild = t;
			push(stack, p);
			p = t;	
		}
		else	{
			if(pre[i]>p->data && pre[i]<peek(stack)->data)	{
				t = newNode(pre[i]);
				i++;
				p->rchild = t;
				p = t;
			}
			else
				p=pop(stack);
		}
	}	
}
void Inorder(struct Node *p)	{
	if(p==NULL)	
		return;
	Inorder(p->lchild);
	cout<<p->data<<" ";
	Inorder(p->rchild);
}

void Postorder(struct Node *p)	{
	if(p==NULL)	
		return;
	Postorder(p->lchild);
	Postorder(p->rchild);
	cout<<p->data<<" ";
}

int main()	{
	int a[] = {30, 20, 10, 15, 25, 40, 50, 45};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<"Only preorder is required to generate a BST as inorder of a BST is always a sorted array ->\n\n";
	cout<<"Given Preorder\n";
	for(int i = 0; i < n; i++)	{
		cout<<a[i]<<" ";
	}
	cout<<"\n\n";
	BST_pre(a, n);
	cout<<"Postorder from Preorder\n";
	Postorder(root);
	cout<<"\n\n";
	cout<<"Inorder i.e Sorted elements\n";
	Inorder(root);
	return 0;
}

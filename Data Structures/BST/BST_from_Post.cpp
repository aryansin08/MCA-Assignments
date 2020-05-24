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
	stack->top == INT_MIN;
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

struct Node* BST_post(int post[], int n)	{
	Stack* stack = create(n);
	int i = n-1;
	struct Node *t, *p;
	root = newNode(post[i]);
	i--;
	p = new Node;
	p=root;
	while(i>=0)	{
		if(post[i]>p->data)	{
			t = newNode(post[i]);
			i--;
			p->rchild = t;
			push(stack, p);
			p = t;
		}
		else	{
			if(post[i]<p->data && post[i]>peek(stack)->data)	{
				t = newNode(post[i--]);
				p->lchild = t;
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

void Preorder(struct Node *p)	{
	if(p==NULL)
		return;
	cout<<p->data<<" ";
	Preorder(p->lchild);
	Preorder(p->rchild);
}

int main()	{
	
	int b[] = {10, 25, 20, 45, 40, 60, 75, 100, 80, 70, 50};
	int k = sizeof(b)/sizeof(b[0]);
	cout<<"Only postorder is required to generate a BST as inorder of a BST is always a sorted array ->\n\n";
	cout<<"Given Preorder\n";
	for(int i = 0; i < k; i++)	{
		cout<<b[i]<<" ";
	}
	cout<<"\n\n";
	BST_post(b, k);
	cout<<"Postorder from Preorder\n";
	Preorder(root);
	cout<<"\n\n";
	cout<<"Inorder i.e Sorted elements\n";
	Inorder(root);
	return 0;
}

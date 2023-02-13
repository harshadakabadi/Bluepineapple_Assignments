#include<stdio.h>
#include<stdlib.h>

/*-------------------------------Create Node-----------------------------------------------------------------*/
int arr[100],i=0;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	int height;
	
};
/*-------------------------------Function To calculate height-----------------------------------------------------------------*/

int height(struct Node *N){
	if(N==NULL)
	return 0;
	return N->height;
}
/*-------------------------------Function To calculate maximum-----------------------------------------------------------------*/

int max(int a, int b){
	return (a > b) ? a : b;
}

/*-------------------------------function To create node-----------------------------------------------------------------*/

struct Node * newNode(int data)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

/*-------------------------------calculate balance factor-----------------------------------------------------------------*/

int getBalance(struct Node *N) {
	if(N == NULL)
	{
		return 0;
	}
	return height(N->left) - height(N->right);
}

/*-------------------------------min value node-----------------------------------------------------------------*/

struct Node *minValueNode(struct Node *node)
{
	struct Node *current = node;
	while( current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

/*-------------------------------left rotate-----------------------------------------------------------------*/

struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *temp = y->left;
	y->left = x;
	x->right = temp;
	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;
	return y;
		
}
/*-------------------------------Right rotate-----------------------------------------------------------------*/

struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *temp = x->right;
	x->right = y;
	y->left = temp;
	y->height = max(height(y->left),height(y->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;
	return x;
		
}

/*-------------------------------Insert Node-----------------------------------------------------------------*/

struct Node *insertNode(struct Node *node , int data)
{
	if(node == NULL)
	{
		return (newNode(data));
	}
	if(data < node->data)
	{
		node->left = insertNode(node->left ,data);
	}
	else if(data > node->data)
	{
		node->right = insertNode(node->right ,data);
	}
	else
		return node;
		
	node->height = 1 + max(height(node->left),height(node->right));
	int balance = getBalance(node);
	
	if(balance > 1 && data < node->left->data) //RR
	{
		return rightRotate(node);
	}
	if(balance < -1 && data > node->right->data) //LL
	{
		return leftRotate(node);
	}
	if(balance > 1 && data > node->left->data)   //LR
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance < -1 && data < node->right->data)  //RL
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

struct Node *deleteNode(struct Node *root,int data)
{
	if(root == NULL)
		return root;
	if(data < root->data)
		root->left = deleteNode(root->left,data);
	else if(data > root->data)
		root->right = deleteNode(root->right,data);
	else
	{
			if((root->left==NULL) || (root->right == NULL))
		   {
				struct Node *temp=root->left ? root->left:root->right;
				if(temp == NULL)
				{
					temp=root;
					root=NULL;
				}
				else
				{
					*root=*temp;
				}
				free(temp);
	    	}
	        else
			{
			struct Node *temp=minValueNode(root->right);
			root->data = temp->data;
			root->right=deleteNode(root->right,temp->data);
			}
	}
	if(root==NULL)
	{
		return root;
	}
	root->height = 1 + max(height(root->left),height(root->right));
	int balance = getBalance(root);
	return rightRotate(root);
	if(balance > 1 && getBalance(root->left) >= 0)
	{
		return rightRotate(root);
	}
	if(balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);
	if(balance < -1 && getBalance(root->right) > 0)
	{
		root->right=rightRotate(root->left);
		return leftRotate(root);
	}
	return root;
}

void preorder(struct Node *root)
{
	if(root!=NULL)
	{
	//	printf("%d  ",root->data);
		arr[i++]=root->data;
		preorder(root->left);
		preorder(root->right);
	}
}

void testPreOrder(int n,int num[],int expectedOutcome[])
{
	struct Node * root=NULL;
	int count=0,i;
	for(i=0;i<n;i++)
	{
		root = insertNode(root,num[i]);
	}
	preorder(root);
	for(i=0;i<n;i++)
	{
		if(arr[i]==expectedOutcome[i])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if(count==n)
	{
		printf("\nsuccessful for insert\n");
	}
	else
	{
		printf("\nunsuccessful for insert\n");
	}
}

int main()
{
	/*struct Node *root = NULL;
	int val,ch;
	while(1)
	{
		printf("\n1.Insert Node\n2.Delete Node\n3.Display\n4.EXIT\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				printf("Enter value :");
				scanf("%d",& val);
				root = insertNode(root,val);
				break;
			case 2: 
				printf("Enter value :");
				scanf("%d",& val);
				root = deleteNode(root,val);
				break;
			case 3:
				printf("\nPreOrder :");
				preorder(root);
				break;
			case 4:
				exit(0);
				break;
		}
	}*/
	FILE *ptr;
    ptr = fopen("AVL_file.txt", "r");

    //read file into array
    int i,n;

	fscanf(ptr,"%d",&n);
	int ExpectedArray[n],num[n];
	for (i = 0; i < n; i++)
    {
        fscanf(ptr, "%d", &num[i]);
    }
    for (i = 0; i < n; i++)
    {
        fscanf(ptr, "%d", &ExpectedArray[i]);
    }
	testPreOrder(n,num,ExpectedArray);	
	return 0;
}


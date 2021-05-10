/*
 * Binary Search Tree #2
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>//



typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

/* for stack */
#define MAX_STACK_SIZE		20
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20
Node* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

Node* deQueue();
void enQueue(Node* aNode);


int initializeBST(Node** h);

/* functions that you have to implement */
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */

void printStack();


int main()
{
	char command;
	int key;
	Node* head = NULL;

	do{
		printf("\nJeong jaemin    2018038067\n\n");
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;

		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;

		case 'l': case 'L':
			levelOrder(head->left);
			break;

		case 'p': case 'P':
			printStack();
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {//초기화 함수

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;

	top = -1;

	front = rear = -1;

	return 1;
}



void recursiveInorder(Node* ptr)//후위 순회법 재귀함수
{
	if(ptr) {
		recursiveInorder(ptr->left);
		printf(" [%d] ", ptr->key);
		recursiveInorder(ptr->right);
	}
}

/**
 * textbook: p 224s
 */
void iterativeInorder(Node* node)//순차방식으로 중위 순회법으로 출력한다
{
	int top=-1;
	for(;;)//무한 반복
	{
		for(; node; node=node->left)//node가 NULL 값이 나올 때 까지 스택에 추가
		{
			push(node);
		}
		node=pop(); //top에 있는 노드를 불러 온다
		if(!node) break;//만약 노드가 비었다면 반복문을 종료한다
		printf(" [%d] ", node->key); //node의 key 값을 출력한다
		node=node->right; // node->right로 node를 이동한다
	}
}

/**
 * textbook: p 225
 */
void levelOrder(Node* ptr)//레벨 순회 트리 순회
{
	if(!ptr) return;//공백트리
	enQueue(ptr);//큐에 노드를 추가해준다
	for( ; ;)//무한반복
	{
		ptr=deQueue(); //큐에 front에 있는 문자를 가지고 온다
		if(ptr)
		{
			printf(" [%d] ", ptr->key); //큐에서 가지고 온 노드의 key값을 출력한다
			if(ptr->left) //ptr->left의 노드 큐에 넣는다
			{
				enQueue(ptr->left);
			}
			if(ptr->right)//ptr->right의 노드를 큐에 넣는다
			{
				enQueue(ptr->right);
			}
		
		}
		else break;
	}
}


int insert(Node* head, int key)//삽입하는 함수
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	if (head->left == NULL) {//루트 노드에 넣는다
		head->left = newNode;
		return 1;
	}

	/* head->left is the root */
	Node* ptr = head->left;

	Node* parentNode = NULL;
	while(ptr != NULL) {

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;
	return 1;
}


int deleteNode(Node* head, int key)
{
	Node *ptr=head->left;//head->left를 ptr노드에 대입한다
	Node *parent=NULL;
	Node *child=NULL;
	Node *least_r=NULL;//두 개의 서브 트리 나올 때 오른쪽 중에서 가장 작은 노드
	Node *least_rparent=NULL;//두 개의 서브 트리 나올 때 오른쪽 중에서 가장 작은 노드의 부모노드
	while (ptr!=NULL)//ptr이 NULL이 나올 때 까지 반복한다
	{	
		if (key == ptr->key)// key 값과 해당하는 노드의 key 값이 일치할 때
		{
			 break;//while 반복문 탈출
		}
		else if (key < ptr->key)// key 값이 노드가 가지고 있는 key값 보다 작을 때
		{
			parent=ptr;//ptr 옮기기 전에 부모노드에 현재노드 주소 저장
			ptr = ptr->left; //ptr의 노드를 ptr의 왼쪽 자식 노드로 옮긴다
		}
		else// key 값이 노드가 가지고 있는 key값 보다 클 때
		{
			parent=ptr;//ptr 옮기기 전에 부모노드에 현재노드 주소 저장
			ptr = ptr->right;//ptr의 노드를 ptr의 오른쪽 자식 노드로 옮긴다
		}
	}
	if(ptr==NULL)//반복문을 돌려 해당하는 key값을 가지고 있는 노드를 찾지 못했을때
	{
		printf("\n There is no correct data\n");
	}
	else if(ptr->left==NULL&&ptr->right==NULL)//마지막 leaf노드일때
	{	
		if(ptr->key<parent->key)//제거할 ptr의 위치가 부모노드 왼쪽에 있을때
		{
			parent->left=NULL;//부모노드 왼쪽을 NULL값으로 연결한다
		}
		else//제거할 ptr의 위치가 부모노드 오른쪽에 있을때
		{
			parent->right=NULL;//부모노드 오른쪽을 NULL값으로 연결한다
		}
		free(ptr);//해당노드를 메모리 할당해제 시킨다
	}
	else if(ptr->left==NULL||ptr->right==NULL) // 하나의 서브 트리만 있을때
	{	
		child = (ptr->left != NULL) ? ptr->left : ptr->right;//삭제하고자 하는 ptr노드의 자식 노드 NUll값이 아닌 오른쪽 또는 왼쪽 노드를 child에 대입한다 
    	if (parent)//부모노드가 루트 노드가 아닐때
    	{
      		if (parent->left == ptr)//삭제하고자하는 노드가 부모노드의 왼쪽에 있을때
        		parent->left = child;//부모노드 왼쪽을 child와 연결
      		else//삭제하고자하는 노드가 부모노드의 오른쪽에 있을때
        		parent->right = child;//부모노드 오른쪽을 child와 연결
			
    	}
		else//부모노드가 루트 노드일때
		{	
			head->left=(ptr->left != NULL) ? ptr->left : ptr->right;			
		} 
		free(ptr);
	}
	else// 두 개의 서브 트리가 있을 때
	{
		least_rparent=ptr;//삭제할 ptr을 rparent에 대입
		least_r=ptr->right;//오른쪽 트리 중 최소 값을 가지고 있는 노드 변수
		while (least_r->left!=NULL)//least_r->left가 NULL이 나올 때 까지 반복한다
		{	
			least_rparent=least_r;//least_r 옮기기 전에 least_rparent에 현재노드 저장해서 부모노드로 만들어준다
			least_r = least_r->left; //least_r 의 노드를 least_r 의 왼쪽 자식 노드로 옮긴다
		}
		if (least_rparent->left == least_r)//least_rparent->left == least_r이 일치하면
        	{
			 least_rparent->left = least_r->right;//least_r가 오른쪽 트리를 가지고 있을 수도 있기에 오른쪽과 연결시킨다
			}
		else //ptr->right가 왼쪽 트리가 하나도 없어 ptr->right가 오른쪽 트리 중 가장 작을 때
        	{
			 least_rparent->right = least_r->right; //least_r의 오른쪽을 부모노드 오른쪽과 연결시킨다
			}

		/*오른쪽에서 가장 작은 노드 least_r을 찾았고 후속조치로 least_r 부모노드와 자식노드를 서로 연결 시켜주었으므로
		이제는 least_r을 삭제하고자하는 ptr의 노드 자리와 바꿔준다*/

		if (parent)//루트노드가 아닐때
		{
			if(ptr->key<parent->key)//제거할 ptr의 위치가 부모노드 왼쪽에 있을때
			{
				parent->left=least_r;//least_r을 부모노드 왼쪽과 연결한다
				least_r->left=ptr->left;//least_r노드의 left를 기존 루트노드의 left를 가리켰던 노드에 연결한다
				least_r->right=ptr->right;//least_r노드의 right를 기존 루트노드의 right를 가리켰던 노드에 연결한다
			}
			else//제거할 ptr의 위치가 부모노드 오른쪽에 있을때
			{
				parent->right=least_r;//least_r을 부모노드 오른쪽과 연결한다
				least_r->left=ptr->left;//least_r노드의 left를 기존 루트노드의 left를 가리켰던 노드에 연결한다
				least_r->right=ptr->right;//least_r노드의 right를 기존 루트노드의 right를 가리켰던 노드에 연결한다
			}
		}
		else //루트 노드일때
		{
			head->left=least_r;//루트노드를 least_r로 한다
			least_r->left=ptr->left;//least_r노드의 left를 기존 루트노드의 left를 가리켰던 노드에 연결한다
			least_r->right=ptr->right;//least_r노드의 right를 기존 루트노드의 right를 가리켰던 노드에 연결한다
		}
		free(ptr);//동적할당 해제한다
	}
	return 0;
}


void freeNode(Node* ptr)//동적할당 해제함수
{
	if(ptr)//ptr이 NULL이 아닐때 후위순회로 동적할당을 해제한다
	 {
		freeNode(ptr->left);//ptr이 NULL이 나올때 까지 왼쪽으로 이동한다
		freeNode(ptr->right);//ptr->right로 이동한다
		free(ptr);//동적할당 해제시켜준다
	}
}

int freeBST(Node* head)
{

	if(head->left == head)//동적할당 해제함수
	{
		free(head);//헤드노드를 동적할당 해제시켜준다
		return 1;
	}

	Node* p = head->left;

	freeNode(p);//freeNode함수를 호출하여 후위순회법으로 동적할당 해제시켜준다

	free(head);//헤드노드를 동적할당 해제시켜준다
	return 1;
}



Node* pop()//stack에 node나오게 하는 함수
{
	
	if (top == -1)//스택이 비어 있을 때 
		return NULL; //NULL 값을 반환한다
	else
		return stack[top--]; //현재 top에 있는 노드 주소를 반환 하고 동시에 top의 위치가 1 준다

}

void push(Node* aNode)//스택에 노드를 집어 넣는 함수
{	
	stack[++top] = aNode;//stack top에 호출된 노드 주소를 집어 넣는다
}



Node* deQueue() //큐에서 front의 값을 반환 하는 함수
{
	if(rear==-1||rear==front) //큐가 아무것도 없을 때
		return NULL;
	else
	{
		return queue[++front];//큐의 앞쪽 부터 노드 주소 반환한다 
	}

}

void enQueue(Node* aNode) //큐에 노드를 추가한다
{	 
	queue[++rear]=aNode; //큐 뒤 부터 넣어준다
}

void printStack()
{
	
}




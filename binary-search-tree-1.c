/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */
	printf("\nJeongjaemin   2018038067\n\n");

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
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
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
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
	return 1;
}



void inorderTraversal(Node* ptr)//중위순회 출력하는 함수
{	/*recursive를 통하여 최대한 왼쪽 노드 끝까지 간다음 왼쪽자식, 부모, 오른쪽자식 순으로 출력한다*/
	
	if(ptr!=NULL)
	{
		inorderTraversal(ptr->left);//자신의 함수에 ptr->left의 주소를 보내 재귀함수를 호출한다
		printf("[ %d ] ",ptr->key);//현재노드의 키값을 출력한다
		inorderTraversal(ptr->right);//자신의 함수에 ptr->right의 주소를 보내 재귀함수를 호출한다
	}
	
}

void preorderTraversal(Node* ptr)//전위순회 출력하는 함수
{/*recursive를 통하여 먼저 부모노드를 출력한 다음 왼쪽 자식노드로 계속가면서 부모노드를 먼저 출력한 다음 마지막으로 오른쪽 자식노드들을 
위로 올라오면서 출력한다*/
	if(ptr!=NULL)
	{
		printf("[ %d ] ",ptr->key);//현재 노드의 키값을 출력한다
		preorderTraversal(ptr->left);//자신의 함수에 ptr->left의 주소를 보내 재귀함수를 호출한다
		preorderTraversal(ptr->right);//자신의 함수에 ptr->right의 주소를 보내 재귀함수를 호출한다
	}
}

void postorderTraversal(Node* ptr)//후위순회 출력하는 함수
{/*resursive를 통하여 가장 밑에 있는 왼쪽 자식노드 까지 도달한 다음 올라오면서 오른쪽 자식, 부모노드 순으로 출력한다*/
	if(ptr!=NULL)
	{
		postorderTraversal(ptr->left);//자신의 함수에 ptr->left의 주소를 보내 재귀함수를 호출한다
		postorderTraversal(ptr->right);//자신의 함수에 ptr->right의 주소를 보내 재귀함수를 호출한다
		printf("[ %d ] ",ptr->key);//현재 노드의 키값을 출력한다
	}

}


int insert(Node* head, int key)//트리에 데이터를 삽입하는 함수
{
	
	Node* node = (Node*)malloc(sizeof(Node)); //노드를 동적할당 해준다.
	Node* p = head->left;//연결리스트의 첫번째 노드 주소를 p에 대입
    Node* parent=NULL;//부모노드를  포인터 변수로 선언한다
	node->key = key; //node의 키값 대입
    node->right = NULL;//node의 right를 NULL 값으로 초기화한다
	node->left = NULL;//node의 left를 NULL 값으로 초기화한다
	if(p==NULL) //만약 p가 비어있을때
	{
		 head->left=node;//head->left를 가리키는 값을 node 주소를 대입하여 루트가 된다
	}
	else
	{
		while(p!=NULL)//p가 비어있을 때 까지 반복
		{
			parent=p;//현재 p를 부모노드로 대입한다
			if(node->key<p->key) //node->key가 p->key보다 작을 때
			{
				p=p->left; // p노드 왼쪽으로 이동한다
			}	
			else //node->key가 p->key보다 클 때
			{
				p=p->right;// p노드 오른쪽으로 이동한다
			}
		}
		if(node->key<parent->key)//부모노드보다 넣으려는 값이 작을경우
		{
			parent->left=node;
		}
		else//부모노드보다 넣으려는 값이 클 경우
		{
			parent->right=node;
		}
	}
	return 0;
}

int deleteLeafNode(Node* head, int key)
{
	Node *ptr=head->left;//head->left를 ptr노드에 대입한다
	Node *parent=NULL;
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
	else//key값과 일치하는 node를 찾았지만 leaf노드가 아니었을 때
	{
		printf("\n node [%d] is not a leaf\n", ptr->key);
	}
	return 0;
}

Node* searchRecursive(Node* ptr, int key)//recursive를 통하여 해당하는 노드 주소 찾는 함수
{
	if (!ptr) //해당하는 노드가 없을 때 NULL값을 반환한다
	{
	return NULL;
	}
	else if (key == ptr->key)//해당하는 key를 가지고 있는 노드를 발견할 때 해당 노드 주소를 반환한다
	{
	 return ptr;
	}
	else if (key < ptr->key)//key값이 ptr노드가 가지고 있는 키값 보다 작을때
	{
		return searchRecursive(ptr->left, key);//재귀함수를 ptr->left주소로 호출
	}
	else//key값이 ptr노드가 가지고 있는 키값 보다 클 때
	{
		return searchRecursive(ptr->right, key);//재귀함수를 ptr->right주소로 호출
	}
}

Node* searchIterative(Node* head, int key)//iterative를 통하여 해당하는 노드 주소 찾는 함수
{	
	Node *ptr=head->left;//head->left를 ptr노드에 대입한다
	while (ptr!=NULL)//ptr이 NULL이 나올 때 까지 반복한다
	{
		if (key == ptr->key)// key 값과 해당하는 노드의 key 값이 일치할 때
		{
		 	return ptr; //해당하는 노드의 주소를 반환한다
		}
		else if (key < ptr->key)// key 값이 노드가 가지고 있는 key값 보다 작을 때
		{
			ptr = ptr->left; //ptr의 노드를 ptr의 왼쪽 자식 노드로 옮긴다
		}
		else// key 값이 노드가 가지고 있는 key값 보다 클 때
		{
			ptr = ptr->right;//ptr의 노드를 ptr의 오른쪽 자식 노드로 옮긴다
		}
	}
		return NULL;//NULL 값을 반환한다
}


int freeBST(Node* head) //메모리 할당을 해제시켜주는 함수
{ /*후위 순회 방식으로 메모리해제 시켜준다*/
	Node* ptr = head;
	if(ptr!=NULL)//ptr이 NULL일 때 까지 반복
	{
		freeBST(ptr->left);//자신의 함수에 ptr->left의 주소를 보내 재귀함수를 호출한다
		if(ptr->right!=head)//ptr이 head노드일경우 이 과정을 생략한다
		{
			freeBST(ptr->right);//자신의 함수에 ptr->right의 주소를 보내 재귀함수를 호출한다
		}
		free(ptr);//현재 노드를 메모리 할당해제 시켜준다
		ptr=NULL;//ptr의 포인터 변수 NULL값으로 지정
	}
	else//이미 비어 있을 때
	{
		printf("This is arleady empty\n");
	}	
    return 0;
}




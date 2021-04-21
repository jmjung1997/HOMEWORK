/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음
         singly-linked-list의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h);

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해 할것
        - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}


int initialize(headNode** h)//연결리스트 초기화 함수, headnode의 위치 주소를 불러와 그에 해당하는 값을 수정하기 위해 더블포인터를 사용
{
	if (*h != NULL) //h를 가리키는 값 NULL이 아닐 때
        freeList(*h);//h가 가리키는 헤드노드를 프리 시켜준다

    *h = (headNode*)malloc(sizeof(headNode)); //h가 가리키는 헤드노드에 동적할당을 해준다
	(*h)->first=NULL;//헤드노드의 first 링크를 NULL 값으로 초기화 한다 
	return 1;
}

int freeList(headNode* h)
{
	 /* h와 연결된 listNode 메모리 해제
     * headNode도 해제되어야 함.
     */
    listNode* p = h->first;

    listNode* prev = NULL;
    while (p != NULL) {//p가 NULL일 때 까지 반복한다
        prev = p; //prev에 p를 대입
        p = p->rlink; //p노드를 한칸 이동한다
        free(prev);//prev에 들어 있는 node를 메모리 할당해제 시켜준다
    }
    free(h);
    return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}




/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key)
{
	listNode* node = (listNode*)malloc(sizeof(listNode)); //노드를 동적할당 해준다.
    listNode* p = h->first;//연결리스트의 첫번째 노드 주소를 p에 대입
    node->key = key; //node의 키값 대입
    node->rlink = NULL;//node의 rlink를 NULL 값으로 비워둔다
	node->llink = NULL;//node의 llink를 NULL 값으로 비워둔다
    if(p==NULL)//마지막에 노드 넣으려고 하는데 연결리스트에 아무것도 없을 때
    {       
      h->first = node; //h->first를 node 위치에 연결시킨다
	  node->llink=h->first; //node->llink를 헤드노드에 연결시키다
	}
    else //연결리스트에 무엇인가 들어있을 때
    {
        while (p->rlink != NULL)//p->rlink를 가리키는 값이 NULL값이 나올 때 까지 반복한다.  
        {
            p = p->rlink;
        }
        p->rlink = node;//맨마지막에 있던 노드를 새로 추가시켜주는 노드에 연결시켜준다
		node->llink=p;
    }
    return 0;

	
}



/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h)
 {


	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key)
{
	
    listNode* node = (listNode*)malloc(sizeof(listNode)); //노드를 동적할당 해준다.
    listNode* p = h->first;//연결리스트의 첫번째 노드 주소를 p에 대입
    node->key = key; //node의 키값 대입
    node->rlink = NULL;//node의 rlink를 NULL 값으로 비워둔다
	node->llink = NULL;//node의 llink를 NULL 값으로 비워둔다
    
	node->rlink=h->first;//node rlink를 기존 p노드에 연결
    node->llink=h;//node llink를 헤드노드에 연결
	h->first=node;//h->first는 새로 추가하는 노드에 연결
	p->llink=node;//기존에 있던 노드 llink를 새로 추가할 노드에 연결 

	h->first = node;//추가할 node를 h->first에 연결한다

    return 0;
	
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {

	return 0;
}



/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {

	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {

	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {

	return 1;
}



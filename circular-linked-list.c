/*
 *  doubly circular linked list
 *
 *  Data Structures
 *
 *  Department of Computer Science
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;

/* 함수 리스트 */
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteLast(listNode* h);
int insertFirst(listNode* h, int key);
int deleteFirst(listNode* h);
int invertList(listNode* h);

int insertNode(listNode* h, int key);
int deleteNode(listNode* h, int key);

void printList(listNode* h);



int main()
{
	char command;
	int key;
	listNode* headnode=NULL;
	printf("\n\nJeong jaemin    2018038067\n\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
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


int initialize(listNode** h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(*h != NULL)
		freeList(*h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h;
	(*h)->llink = *h;
	(*h)->key = -9999;
	return 1;
}

/* 메모리 해제 */
int freeList(listNode* h)
{	
    listNode* p = h->rlink;

    listNode* prev = NULL;
    while (p != h) {//p가 NULL일 때 까지 반복한다
        prev = p; //prev에 p를 대입
        p = p->rlink; //p노드를 한칸 이동한다
        free(prev);//prev에 들어 있는 node를 메모리 할당해제 시켜준다
    }
    free(h);
    return 0;
}



void printList(listNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink;

	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}
	printf("  items = %d\n", i);


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);

	i = 0;
	p = h->rlink;
	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		p = p->rlink;
		i++;
	}

}



/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(listNode* h, int key) 
{
	listNode* node = (listNode*)malloc(sizeof(listNode)); //노드를 동적할당 해준다.
    listNode* p = h->rlink;//연결리스트의 첫번째 노드 주소를 p에 대입
    node->key = key; //node의 키값 대입
    node->rlink = node;//node의 rlink를 node 값으로 자신을 가리키게 한다
	node->llink = node;//node의 llink를 node 값으로 자신을 가리키게 한다
    if(p==h)//마지막에 노드 넣으려고 하는데 연결리스트에 아무것도 없을 때
    {       
      h->rlink= node;//헤드노드 rlink를 node에 연결시킨다
	  h->llink=node;//헤드노드 llink를 node에 연결시킨다
	  node->llink=h; //node->llink를 헤드노드에 연결시키다
	  node->rlink=h;//node->rlink를 헤드노드에 연결시키다

	}
    else //연결리스트에 무엇인가 들어있을 때
    {
        while (p->rlink != h)//p->rlink를 가리키는 값이 h 주소값이 나올 때 까지 반복한다.  
        {
            p = p->rlink;
        }
        p->rlink = node;//맨마지막에 있던 노드를 새로 추가시켜주는 노드에 연결시켜준다
		node->llink=p; //추가하는 node의 llink를 p에 연결시킨다
		node->rlink=h;//추가하는 node의 rlink를 h에 연결시킨다
		h->llink=node;//h->llink를 node에 연결시킨다
    }
    return 0;

}


/**
 * list의 마지막 노드 삭제
 */
int deleteLast(listNode* h) 
{    
	listNode* p = h->rlink;//연결리스트의 첫번째 노드 주소를 p에 대입
    if (p == h)//연결리스트에 아무것도 없을때
    {
        printf("It is empty\n");
        return 0;
    }
    else if (p->rlink == h) //연결리스트에 마지막 노드가 한개 밖에 없을 때
    {
        h->rlink = h;//h->rlink를 헤드노드 주소로 가리키게 한다
		h->llink = h;//h->llink를 헤드노드 주소로 가리키게 한다
        free(p); // 마지막 노드를 메모리 할당 해제 시켜준다

        return 0;
    }
    else
    {
        while (p->rlink!= h)//p->rlink를 가리키는 값이 헤드노드 주소값이 나올 때 까지 반복한다.  
        {
            p = p->rlink; //p를 마지막 노드상태로 이동한다
        }
      p->llink->rlink=h; //현재 p 이전 노드 rlink를 헤드노드 주소로 대입한다
	  h->llink=p->llink;//h->llink를 현재 p 이전노드 주소에 연결한다
        free(p); //마지막 노드를 메모리 할당을 해제 시켜준다.
    }
    return 1;

}


/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(listNode* h, int key) 
{
		
    listNode* node = (listNode*)malloc(sizeof(listNode)); //노드를 동적할당 해준다.
    listNode* p = h->rlink;//연결리스트의 첫번째 노드 주소를 p에 대입
    node->key = key; //node의 키값 대입
    node->rlink = node;//node의 rlink를 node 주소값으로 비워둔다
	node->llink = node;//node의 llink를 node 주소값으로 비워둔다
    if(p!=h)//이중 연결리스트에 기존 데이터가 있을때
	{
		node->rlink=p;//node rlink를 기존 p노드에 연결
    	p->llink=node;//기존에 있던 노드 llink를 새로 추가할 노드에 연결 
		node->llink=h;//node llink를 헤드노드에 연결
		h->rlink=node;//h->first는 새로 추가하는 노드에 연결
	}
	else//이중 연결리스트에 기존 데이터가 없을 때
	{
		node->llink=h;// 새로 추가할 node->llink를 헤드 노드 주소값에 연결
		node->rlink=h;//새로 추가할 node->rlink를 헤드 노드주소값에 연결
		h->rlink=node;//h->rlink를 새로 추가할 node 주소에 연결
		h->llink=node;//h->llink를 새로 추가할 node 주소에 연결
	}

	return 1;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(listNode* h)
 {
	listNode* p = h->rlink; //연결리스트의 첫번째 노드 주소를 p에 대입
    if (p == h)//연결리스트에 아무것도 없을 때
    {
        printf("It is empty\n");
    }
    else //연결리스트에 무엇인가 있을 때
    {    
    h->rlink = p->rlink; //h->rlink를 p->rlink가 가리키는 주소로 지정한다
	p->rlink->llink=h;//h->rlink->llink를 헤드주소로 지정한다
    free(p); //기존 첫번째 노드를 동적할당에서 해제 시켜준다.
    }

	return 1;

}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(listNode* h) {


	return 0;
}



/**
 *  리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 
 **/
int insertNode(listNode* h, int key) {

	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(listNode* h, int key) {

	return 0;
}



/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

 /* 필요한 헤더파일 추가 */

typedef struct Node
{
    int key;
    struct Node* link;
} listNode;

typedef struct Head {
    struct Node* first;
}headNode;


/* 함수 리스트 */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
    char command;
    int key;
    headNode* headnode = NULL;
    printf("Jeong Jaemin 2018038067\n\n");
    do {
        printf("----------------------------------------------------------------\n");
        printf("                     Singly Linked List                         \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize    = z           Print         = p \n");
        printf(" Insert Node   = i           Delete Node   = d \n");
        printf(" Insert Last   = n           Delete Last   = e\n");
        printf(" Insert First  = f           Delete First  = t\n");
        printf(" Invert List   = r           Quit          = q\n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch (command) {
        case 'z': case 'Z':
            headnode = initialize(headnode);
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

    } while (command != 'q' && command != 'Q');

    return 1;
}

headNode* initialize(headNode* h) {

    /* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
    if (h != NULL)
        freeList(h);

    /* headNode에 대한 메모리를 할당하여 리턴 */
    headNode* temp = (headNode*)malloc(sizeof(headNode));
    temp->first = NULL;
    return temp;
}

int freeList(headNode* h) {
    /* h와 연결된 listNode 메모리 해제
     * headNode도 해제되어야 함.
     */
    listNode* p = h->first;

    listNode* prev = NULL;
    while (p != NULL) {
        prev = p;
        p = p->link;
        free(prev);
    }
    free(h);
    return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key)
{

    listNode* node = (listNode*)malloc(sizeof(listNode));
    node->key = key;

    node->link = h->first;
    h->first = node;

    return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) //입력받은 키를 오름차순으로 삽입
{

    listNode* temp = (listNode*)malloc(sizeof(listNode)); //새로운 정보를 담을 노드 생성
    listNode* p = h->first; //연결리스트의 첫번째 노드 주소를 p에 대입
    temp->key = key;//입력 받은 숫자를 노드 key에 대입
    temp->link = NULL;//아직 연결되는 노드는 없으므로 NULL 값으로 연결해준다.
    if (p != NULL) //연결리스트에 어떤 정보를 담고 있는 노드가 들어가 있을 때
    {
		
        if (temp->key <= p->key) //노드를 연결리스트에 넣으려고했는데 첫번째 노드에 있는 key값보다 temp->key값이 작을 때
        {
            temp->link = p; //temp->link를 첫 번째 노드인 p의 주소에 연결
            h->first = temp;// temp의 주소를 h->first 에 대입하여 temp를 헤드노드로 지정해준다.
            return 0;
        }

        else //노드를 연결리스트에 넣으려고했는데 첫번째 노드에 있는 key값보다 temp->key값이 클 때
        {           
        
                while (p->link!=NULL)//p->link를 가리키는 값이 NULL값이 나올 때 까지 반복한다.  
                {	 
					if(p->link->key>temp->key)//현재 p의노드에서 옆에 다음 노드의 키 값이 넣으려고하는 키값보다 크다면
					{
    					temp->link=p->link; //현재 p가 가리키고 다음 노드의 주소 정보를 temp->link에 대입한다 
   						 p->link=temp; //p->link에 넣으려고 하는 노드 temp주소를 대입한다.
   						 return 0;
   					}

                    p = p->link; //p의 노드를 한 칸씩 움직인다
                }               
		} /* NULL값이 나올 때 까지 while문을 반복했음에도 기존에 있던 노드들의 키값이 넣으려고하는 키값보다 다 작을때*/ 
			p->link=temp; //연결리스트 맨 뒤에 노드를 추가해준다.
			return 0;
              
    }      

    
    else//아직 연결리스트에 아무 정보가 없어서 들어가야 할 노드가 첫번째일때
    {         
        h->first = temp; //temp의 주소를 h->first에 대입하여 첫번째 헤드노드 first가 temp를 가리키게 한다.
    }
    return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key)//연결리스트 맨 뒤에 노드를 추가해주는 함수
{   
    
    listNode* node = (listNode*)malloc(sizeof(listNode)); //노드를 동적할당 해준다.
    listNode* p = h->first;//연결리스트의 첫번째 노드 주소를 p에 대입
    node->key = key; //node의 키값 대입
    node->link=NULL;
    
    while (p->link!=NULL)//p->link를 가리키는 값이 NULL값이 나올 때 까지 반복한다.  
                {
                    p = p->link;
                }
    p->link = node;//맨마지막에 있던 노드를 새로 추가시켜주는 노드에 연결시켜준다
    return 0;
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) //연결 리스트 첫 번째 노드 삭제함수
{
    listNode *p=h->first; //연결리스트의 첫번째 노드 주소를 p에 대입
    h->first=p->link; //기존 첫 번째 node가 가리키고 있던 node를 첫 번째 노드로 지정
    free(p); //기존 첫번째 노드를 동적할당에서 해제 시켜준다.

    return 0;
}



/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) 
{

    
    return 0;

}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) 
{
   
    listNode* p = h->first;//연결리스트의 첫번째 노드 주소를 p에 대입
        
    while (p->link->link!=NULL)//p->link->link를 가리키는 값이 NULL값이 나올 때 까지 반복한다.  
                {
                    p = p->link;
                }
            p->link=NULL; //여기서 p는 마지막에서 두 번째로 있는 노드이고 가리키는 값을 NULL로 바꿔준다
            p = p->link; //p를 마지막 노드로 이동한다.
            free(p); //마지막 노드를 메모리 할당을 해제 시켜준다.
            
    return 0;
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {

    return 0;
}


void printList(headNode* h) {
    int i = 0;
    listNode* p;

    printf("\n---PRINT\n");

    if (h == NULL) {
        printf("Nothing to print....\n");
        return;
    }

    p = h->first;

    while (p != NULL)
    {
        printf("[ [%d]=%d ] ", i, p->key);
        p = p->link;
        i++;
    }

    printf("  items = %d\n", i);
}
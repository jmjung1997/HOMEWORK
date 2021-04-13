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

typedef struct Node//node를 생성시켜주는 구조체
{
    int key;
    struct Node* link;
} listNode;

typedef struct Head {//헤드노드를 생성시켜주는 구조체
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

headNode* initialize(headNode* h)//초기화 시켜주는 함수이다
{

    /* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
    if (h != NULL)
        freeList(h);

    /* headNode에 대한 메모리를 할당하여 리턴 */
    headNode* temp = (headNode*)malloc(sizeof(headNode));
    temp->first = NULL;
    return temp;
}

int freeList(headNode* h) //연결리스트를 메모리할당 해제시켜주는 함수
{
    /* h와 연결된 listNode 메모리 해제
     * headNode도 해제되어야 함.
     */
    listNode* p = h->first;

    listNode* prev = NULL;
    while (p != NULL) {//p가 NULL일 때 까지 반복한다
        prev = p; //prev에 p를 대입
        p = p->link; //p노드를 한칸 이동한다
        free(prev);//prev에 들어 있는 node를 메모리 할당해제 시켜준다
    }
    free(h);
    return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key)//노드를 연결리스트 맨처음에 집어넣을때
{

    listNode* node = (listNode*)malloc(sizeof(listNode));
    node->key = key;

    node->link = h->first;//첫 번째를 가리키고 있는 노드를 추가할 node링크에 연결
    h->first = node;//추가할 node를 h->first에 연결한다

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

            while (p->link != NULL)//p->link를 가리키는 값이 NULL값이 나올 때 까지 반복한다.  
            {
                if (p->link->key > temp->key)//현재 p의노드에서 옆에 다음 노드의 키 값이 넣으려고하는 키값보다 크다면
                {
                    temp->link = p->link; //현재 p가 가리키고 다음 노드의 주소 정보를 temp->link에 대입한다 
                    p->link = temp; //p->link에 넣으려고 하는 노드 temp주소를 대입한다.
                    return 0;
                }

                p = p->link; //p의 노드를 한 칸씩 움직인다
            }
        } /* NULL값이 나올 때 까지 while문을 반복했음에도 기존에 있던 노드들의 키값이 넣으려고하는 키값보다 다 작을때*/
        p->link = temp; //연결리스트 맨 뒤에 노드를 추가해준다.
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
    node->link = NULL;
    if(p==NULL)//마지막에 노드 넣으려고 하는데 연결리스트에 아무것도 없을 때
    {       
      h->first = node;      
    }
    else
    {
        while (p->link != NULL)//p->link를 가리키는 값이 NULL값이 나올 때 까지 반복한다.  
        {
            p = p->link;
        }
        p->link = node;//맨마지막에 있던 노드를 새로 추가시켜주는 노드에 연결시켜준다
    }
    return 0;
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) //연결 리스트 첫 번째 노드 삭제함수
{
    listNode* p = h->first;
    if (p == NULL)//연결리스트에 아무것도 없을 때
    {
         printf("It is empty\n");
        return 0;
    }
    else 
    {
    listNode* p = h->first; //연결리스트의 첫번째 노드 주소를 p에 대입
    h->first = p->link; //기존 첫 번째 node가 가리키고 있던 node를 첫 번째 노드로 지정
    free(p); //기존 첫번째 노드를 동적할당에서 해제 시켜준다.
    }
    return 0;
}



/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key)
{
    listNode* p = h->first;
    if (p == NULL)//연결리스트에 아무것도 없을때
    {
         printf("It is empty\n");
        return 0;
    }

    else if (p->key == key)
    {
        h->first = p->link; //기존 첫 번째 node가 가리키고 있던 node를 첫 번째 노드로 지정
        free(p); //삭제하고자하는 키값과 일치하는 노드를 삭제한다.
        return 0;
    }
    else
    {
        while (p->link->link != NULL)//p->link->link를 가리키는 값이 NULL값이 나올 때 까지 반복한다.  
        {
            if (p->link->key == key)
            {
                p->link = p->link->link;
                return 0;             
                           
            }         
            p = p->link; //p의 노드를 한 칸씩 움직인다
        }
       
        printf("There is no correct key\n");
        return 0;

    }
}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h)
{

    listNode* p = h->first;//연결리스트의 첫번째 노드 주소를 p에 대입
    if (p == NULL)//연결리스트에 아무것도 없을때
    {
        printf("It is empty\n");
        return 0;
    }
    else if (p->link == NULL) //연결리스트에 마지막 노드가 한개 밖에 없을 때
    {
        h->first = NULL;
        free(p); // 마지막 노드를 메모리 할당 해제 시켜준다

        return 0;
    }
    else
    {
        while (p->link->link != NULL)//p->link->link를 가리키는 값이 NULL값이 나올 때 까지 반복한다.  
        {
            p = p->link;
        }
        p->link = NULL; //여기서 p는 마지막에서 두 번째로 있는 노드이고 가리키는 값을 NULL로 바꿔준다
        p = p->link; //p를 마지막 노드로 이동한다.
        free(p); //마지막 노드를 메모리 할당을 해제 시켜준다.
    }
    return 0;
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h)//연결 리스트를 뒤짚는 함수
{
    listNode *p = h->first; //현재노드를 가리킨다.
    listNode* pre=NULL; //이전 노드를 가리킨다
    listNode* next=NULL; //다음 노드를 가리킨다.
    while (p != NULL) // 현재노드를 가리키는게 NULL값이 나오도록 반복한다
    {
        next = p->link;//next는 현재 p노드 다음 노드를 가리킨다
        p->link=pre ;//현재노드의 랑크를 전 노드를 향하게 한다
        pre= p; //pre를 현재노드를 가리키게 한다
        p=next; //현재 p노드를 다음 노드를 가키게한다.
    }
    h->first= pre; //첫번째 헤드 노드를 pre가 향하는 노드로 설정한다. next와 p 둘다 NULL값이 되므로 남은 것은 pre가 가리키는 노드 밖에 없다.

    return 0;
}


void printList(headNode* h) // 연결리스트를 출력해주는 함수 
{
    int i = 0; 
    listNode* p;

    printf("\n---PRINT\n");

    if (h == NULL) {//헤드노드가 가리키는 값이 아무것도 없을 때
        printf("Nothing to print....\n");
        return;
    }

    p = h->first;//헤드노드의 firtst를 가리키는 값을 이제 p라고 하겠다

    while (p != NULL) //p가 NULL이 아닐 때 까지 반복한다
    {
        printf("[ [%d]=%d ] ", i, p->key);
        p = p->link; //기존 p가 가리키는 주소를 이제 p라고 하겠다
        i++;
    }

    printf("  items = %d\n", i); //item의 갯수 출력하기
}
/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>
 /* �ʿ��� ������� �߰� */

typedef struct Node//node�� ���������ִ� ����ü
{
    int key;
    struct Node* link;
} listNode;

typedef struct Head {//����带 ���������ִ� ����ü
    struct Node* first;
}headNode;


/* �Լ� ����Ʈ */
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

headNode* initialize(headNode* h)//�ʱ�ȭ �����ִ� �Լ��̴�
{

    /* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
    if (h != NULL)
        freeList(h);

    /* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
    headNode* temp = (headNode*)malloc(sizeof(headNode));
    temp->first = NULL;
    return temp;
}

int freeList(headNode* h) //���Ḯ��Ʈ�� �޸��Ҵ� ���������ִ� �Լ�
{
    /* h�� ����� listNode �޸� ����
     * headNode�� �����Ǿ�� ��.
     */
    listNode* p = h->first;

    listNode* prev = NULL;
    while (p != NULL) {//p�� NULL�� �� ���� �ݺ��Ѵ�
        prev = p; //prev�� p�� ����
        p = p->link; //p��带 ��ĭ �̵��Ѵ�
        free(prev);//prev�� ��� �ִ� node�� �޸� �Ҵ����� �����ش�
    }
    free(h);
    return 0;
}



/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key)//��带 ���Ḯ��Ʈ ��ó���� ���������
{

    listNode* node = (listNode*)malloc(sizeof(listNode));
    node->key = key;

    node->link = h->first;//ù ��°�� ����Ű�� �ִ� ��带 �߰��� node��ũ�� ����
    h->first = node;//�߰��� node�� h->first�� �����Ѵ�

    return 0;
}


/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) //�Է¹��� Ű�� ������������ ����
{

    listNode* temp = (listNode*)malloc(sizeof(listNode)); //���ο� ������ ���� ��� ����
    listNode* p = h->first; //���Ḯ��Ʈ�� ù��° ��� �ּҸ� p�� ����
    temp->key = key;//�Է� ���� ���ڸ� ��� key�� ����
    temp->link = NULL;//���� ����Ǵ� ���� �����Ƿ� NULL ������ �������ش�.
    if (p != NULL) //���Ḯ��Ʈ�� � ������ ��� �ִ� ��尡 �� ���� ��
    {

        if (temp->key <= p->key) //��带 ���Ḯ��Ʈ�� ���������ߴµ� ù��° ��忡 �ִ� key������ temp->key���� ���� ��
        {
            temp->link = p; //temp->link�� ù ��° ����� p�� �ּҿ� ����
            h->first = temp;// temp�� �ּҸ� h->first �� �����Ͽ� temp�� ������ �������ش�.
            return 0;
        }

        else //��带 ���Ḯ��Ʈ�� ���������ߴµ� ù��° ��忡 �ִ� key������ temp->key���� Ŭ ��
        {

            while (p->link != NULL)//p->link�� ����Ű�� ���� NULL���� ���� �� ���� �ݺ��Ѵ�.  
            {
                if (p->link->key > temp->key)//���� p�ǳ�忡�� ���� ���� ����� Ű ���� ���������ϴ� Ű������ ũ�ٸ�
                {
                    temp->link = p->link; //���� p�� ����Ű�� ���� ����� �ּ� ������ temp->link�� �����Ѵ� 
                    p->link = temp; //p->link�� �������� �ϴ� ��� temp�ּҸ� �����Ѵ�.
                    return 0;
                }

                p = p->link; //p�� ��带 �� ĭ�� �����δ�
            }
        } /* NULL���� ���� �� ���� while���� �ݺ��������� ������ �ִ� ������ Ű���� ���������ϴ� Ű������ �� ������*/
        p->link = temp; //���Ḯ��Ʈ �� �ڿ� ��带 �߰����ش�.
        return 0;

    }


    else//���� ���Ḯ��Ʈ�� �ƹ� ������ ��� ���� �� ��尡 ù��°�϶�
    {
        h->first = temp; //temp�� �ּҸ� h->first�� �����Ͽ� ù��° ����� first�� temp�� ����Ű�� �Ѵ�.
    }
    return 0;
}

/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key)//���Ḯ��Ʈ �� �ڿ� ��带 �߰����ִ� �Լ�
{

    listNode* node = (listNode*)malloc(sizeof(listNode)); //��带 �����Ҵ� ���ش�.
    listNode* p = h->first;//���Ḯ��Ʈ�� ù��° ��� �ּҸ� p�� ����
    node->key = key; //node�� Ű�� ����
    node->link = NULL;
    if(p==NULL)//�������� ��� �������� �ϴµ� ���Ḯ��Ʈ�� �ƹ��͵� ���� ��
    {       
      h->first = node;      
    }
    else
    {
        while (p->link != NULL)//p->link�� ����Ű�� ���� NULL���� ���� �� ���� �ݺ��Ѵ�.  
        {
            p = p->link;
        }
        p->link = node;//�Ǹ������� �ִ� ��带 ���� �߰������ִ� ��忡 ��������ش�
    }
    return 0;
}


/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) //���� ����Ʈ ù ��° ��� �����Լ�
{
    listNode* p = h->first;
    if (p == NULL)//���Ḯ��Ʈ�� �ƹ��͵� ���� ��
    {
         printf("It is empty\n");
        return 0;
    }
    else 
    {
    listNode* p = h->first; //���Ḯ��Ʈ�� ù��° ��� �ּҸ� p�� ����
    h->first = p->link; //���� ù ��° node�� ����Ű�� �ִ� node�� ù ��° ���� ����
    free(p); //���� ù��° ��带 �����Ҵ翡�� ���� �����ش�.
    }
    return 0;
}



/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key)
{
    listNode* p = h->first;
    if (p == NULL)//���Ḯ��Ʈ�� �ƹ��͵� ������
    {
         printf("It is empty\n");
        return 0;
    }

    else if (p->key == key)
    {
        h->first = p->link; //���� ù ��° node�� ����Ű�� �ִ� node�� ù ��° ���� ����
        free(p); //�����ϰ����ϴ� Ű���� ��ġ�ϴ� ��带 �����Ѵ�.
        return 0;
    }
    else
    {
        while (p->link->link != NULL)//p->link->link�� ����Ű�� ���� NULL���� ���� �� ���� �ݺ��Ѵ�.  
        {
            if (p->link->key == key)
            {
                p->link = p->link->link;
                return 0;             
                           
            }         
            p = p->link; //p�� ��带 �� ĭ�� �����δ�
        }
       
        printf("There is no correct key\n");
        return 0;

    }
}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h)
{

    listNode* p = h->first;//���Ḯ��Ʈ�� ù��° ��� �ּҸ� p�� ����
    if (p == NULL)//���Ḯ��Ʈ�� �ƹ��͵� ������
    {
        printf("It is empty\n");
        return 0;
    }
    else if (p->link == NULL) //���Ḯ��Ʈ�� ������ ��尡 �Ѱ� �ۿ� ���� ��
    {
        h->first = NULL;
        free(p); // ������ ��带 �޸� �Ҵ� ���� �����ش�

        return 0;
    }
    else
    {
        while (p->link->link != NULL)//p->link->link�� ����Ű�� ���� NULL���� ���� �� ���� �ݺ��Ѵ�.  
        {
            p = p->link;
        }
        p->link = NULL; //���⼭ p�� ���������� �� ��°�� �ִ� ����̰� ����Ű�� ���� NULL�� �ٲ��ش�
        p = p->link; //p�� ������ ���� �̵��Ѵ�.
        free(p); //������ ��带 �޸� �Ҵ��� ���� �����ش�.
    }
    return 0;
}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h)//���� ����Ʈ�� ��¤�� �Լ�
{
    listNode *p = h->first; //�����带 ����Ų��.
    listNode* pre=NULL; //���� ��带 ����Ų��
    listNode* next=NULL; //���� ��带 ����Ų��.
    while (p != NULL) // �����带 ����Ű�°� NULL���� �������� �ݺ��Ѵ�
    {
        next = p->link;//next�� ���� p��� ���� ��带 ����Ų��
        p->link=pre ;//�������� ��ũ�� �� ��带 ���ϰ� �Ѵ�
        pre= p; //pre�� �����带 ����Ű�� �Ѵ�
        p=next; //���� p��带 ���� ��带 ��Ű���Ѵ�.
    }
    h->first= pre; //ù��° ��� ��带 pre�� ���ϴ� ���� �����Ѵ�. next�� p �Ѵ� NULL���� �ǹǷ� ���� ���� pre�� ����Ű�� ��� �ۿ� ����.

    return 0;
}


void printList(headNode* h) // ���Ḯ��Ʈ�� ������ִ� �Լ� 
{
    int i = 0; 
    listNode* p;

    printf("\n---PRINT\n");

    if (h == NULL) {//����尡 ����Ű�� ���� �ƹ��͵� ���� ��
        printf("Nothing to print....\n");
        return;
    }

    p = h->first;//������� firtst�� ����Ű�� ���� ���� p��� �ϰڴ�

    while (p != NULL) //p�� NULL�� �ƴ� �� ���� �ݺ��Ѵ�
    {
        printf("[ [%d]=%d ] ", i, p->key);
        p = p->link; //���� p�� ����Ű�� �ּҸ� ���� p��� �ϰڴ�
        i++;
    }

    printf("  items = %d\n", i); //item�� ���� ����ϱ�
}
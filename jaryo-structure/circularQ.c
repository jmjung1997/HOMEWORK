/*
 * circularQ.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType* createQueue();
int freeQueue(QueueType* cQ);
int isEmpty(QueueType* cQ);
int isFull(QueueType* cQ);
void enQueue(QueueType* cQ, element item);
void deQueue(QueueType* cQ, element* item);
void printQ(QueueType* cQ);
void debugQ(QueueType* cQ);
element getElement();

int main(void)
{
	QueueType* cQ = createQueue();
	element data;
	char command;

	do {
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ, &data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
			freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');


	return 1;
}

QueueType* createQueue()
{
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

int freeQueue(QueueType* cQ)
{
	if (cQ == NULL) return 1;
	free(cQ);
	return 1;
}

element getElement()
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType* cQ) //큐가 비어 있는지 확인하는 함수
{
	if (cQ->rear - cQ->front == 0)return 1;// front와 rear가 같다면 큐가 비어있다.
	return 0;
}

/* complete the function */
int isFull(QueueType* cQ) //큐가 가득 차 있는지 확인하는 함수
{   /*rear-front or front-rear가 MAX_QUEUE_SIZE-1이면 큐가 가득차 있다.*/
	if (cQ->rear - cQ->front == MAX_QUEUE_SIZE-1 || cQ->rear - cQ->front == MAX_QUEUE_SIZE-1)return 1;
	return 0;
}


/* complete the function */
void enQueue(QueueType* cQ, element item) // 큐에 데이터를 추가 하는 함수
{
	if (isFull(cQ) == 1) //만약 isFull을 호출하여 1이 반환되면 큐는 가득 차 있음

	{
		printf("Circular Queue is full !");
		return;
	}
	else//rear을 하나 추가한 뒤 데이터를 큐에 저장한다. 
		cQ->rear = (cQ->rear + 1) % MAX_QUEUE_SIZE;
		cQ->queue[cQ->rear] = item;
}

/* complete the function */
void deQueue(QueueType* cQ, element* item) // 큐를 front부터 제거하는 함수
{
	if (isEmpty(cQ) == 1) //isEmpty를 호출하여 비어있으면 다음을 출력한다. 
	{ 
		printf("Circular Queue is empty !");
	}
	
	else
	{		/*사실살 데이터는 남아있지만 front의 수를 증가시켜 front의 인덱스를 바꾸어 준다.*/
		cQ->front = (cQ->front+ 1) % MAX_QUEUE_SIZE;
	}


}





void printQ(QueueType* cQ)
{
	int i, first, last;

	first = (cQ->front + 1) % MAX_QUEUE_SIZE;
	last = (cQ->rear + 1) % MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while (i != last) {
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType* cQ)
{

	printf("\n---DEBUG\n");
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf(" [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}



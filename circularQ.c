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
typedef struct {                     /* QueueType 구조체 선언*/
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
	QueueType* cQ = createQueue(); //큐 생성하기 
	element data;
	char command;
	printf("\n\n[----- [Jeong Jae Min] [2018038067] -----]\n\n");
	do {
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");



		printf("Command = ");
		scanf(" %c", &command); /*명령어 입력 받기*/

		switch (command) {
		case 'i': case 'I': //cQ에 데이터 집어 넣기
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D'://cQ에 데이터 삭제
			deQueue(cQ, &data);
			break;
		case 'p': case 'P': //cQ 데이터 출력하기
			printQ(cQ);
			break;
		case 'b': case 'B': //cQ 디버그 상태 보여주기
			debugQ(cQ);
			break;
		case 'q': case 'Q': //cQ 배열 동적 할당 해제
			freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');


	return 1;
}

QueueType* createQueue() //큐를 생성해주는 함수
{
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType)); //동적 배열을 통하여 생성한다
	cQ->front = 0; /* full일때 와 empty일때 를 구별하기 위해 front 하나를 빈공간으로 둔다*/
	cQ->rear = 0;
	return cQ;
}

int freeQueue(QueueType* cQ) // cQ동적할당 해제하기
{
	if (cQ == NULL) return 1;
	free(cQ);
	return 1;
}

element getElement() //큐에 데이터를 입력 받는 함수
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
	if (cQ->rear - cQ->front == MAX_QUEUE_SIZE - 1 || cQ->rear - cQ->front == MAX_QUEUE_SIZE - 1)return 1;
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
	{		/*사실상 데이터는 남아있지만 front의 수를 증가시켜 front의 인덱스를 바꾸어 준다.*/
		cQ->front = (cQ->front + 1) % MAX_QUEUE_SIZE;
	}


}





void printQ(QueueType* cQ)  // 큐를 출력해주는 함수
{
	int i, first, last;

	first = (cQ->front + 1) % MAX_QUEUE_SIZE; // font는 빈공간 이므로 1만큼 증가시켜 first를 설정한다
	last = (cQ->rear + 1) % MAX_QUEUE_SIZE; //rear 까지 출력하기 위해 last 값을 1 증가 시켜 출력한다

	printf("Circular Queue : [");

	i = first;
	while (i != last) {  // 원형큐를 출력한다
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % MAX_QUEUE_SIZE; // 원형큐 이므로 인덱스 번호는 MAX_QUEUE_SIZE-1까지 순환한다

	}
	printf(" ]\n");
}


void debugQ(QueueType* cQ) //원형큐의 원소를 디버그 해주는 함수
{

	printf("\n---DEBUG\n");
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (i == cQ->front) {
			printf("  [%d] = front\n", i); //front 인덱스 출력
			continue;
		}
		printf(" [%d] = %c\n", i, cQ->queue[i]); //각 인덱스에 해당하는 값 출력

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear); // front와 rear 인덱스 출력
}



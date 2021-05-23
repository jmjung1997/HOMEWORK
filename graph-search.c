#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 if necessary */

# define MAX_VERTEX 10
#define stack_size 10
#define MAX_QUEUE_SIZE 11

typedef struct node
{
	int vertex;
	struct node* next;
}Node;


typedef struct
{
	int visit[MAX_VERTEX];
	Node* nearlist[MAX_VERTEX];
	int n;
}Graph;



void initilizeGraph(Graph* g);
void printGraph(Graph* g);
void insertvertex(Graph* g);
void insertEdge(Graph* g, int v1, int v2);

void freeGraph(Graph* g);

/*DFS에 필요한 함수*/
void DFS(Graph* g, int v);
void push(int n);
int pop();
int stack[stack_size] = { 0, };
int top = -1;
int queue_empty();
int queue_full();


void Print_Graph();


/*BFS에 필요한 함수*/
void BFS(Graph* g,int v);
int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

int deleteq();
void addq(int v);



int main()
{
	char command;
	int n1, n2;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	int v;
	int v2;
	printf("\nJeongjaemin      2018038067\n\n");
	do {
		printf("\n----------------------------------------------------------------\n");
		printf("                        Graph  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph    = z                               \n");
		printf(" Insert  Vertex      = i         Insert Edge          = e \n");
		printf(" Depth First Search  = d         Breath First Search = b\n");
		printf(" Print Graph         = p         Quit                = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) 
		{
		case 'z': case 'Z':
			initilizeGraph(G);
			break;
		case 'i': case 'I':
			insertvertex(G);
			break;
		case 'b': case 'B':
			printf("Start number = ");
			scanf(" %d", &v);
			BFS(G, v);			
			break;
		case 'e': case 'E':
			printf("Enter the vertices to connect only once: (v1, v2) ");
			scanf(" %d", &n1);
			scanf(" %d", &n2);
			insertEdge(G, n1, n2);
			insertEdge(G, n2, n1);
			break;
		case 'd': case 'D':
			printf("Start number = ");
			scanf(" %d", &v);
			DFS(G, v);
			break;
		case 'p': case 'P':
			Print_Graph(G);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');
	free(G);
	return 1;
}


void initilizeGraph(Graph* g)//초기화 함수
{
	g->n = 0;//vertex 갯수 0
	for (int n = 0; n < MAX_VERTEX; n++)//인접리스트 배열 NULL 값으로 초기화
	{
		g->nearlist[n] = NULL;
	}

}

void insertvertex(Graph* g)//vertex의 갯수를 정하는 함수
{
	if (g->n >= MAX_VERTEX)//설정할 수 있는 vertex의 수를 초과할 때
	{
		printf("\nover number of vertex .\n");
		return;
	}
	g->n++;//vertex갯수 한개를 늘린다
	printf("number of vertex: %d\n", g->n);
}

void insertEdge(Graph* g, int v1, int v2)
{
	Node* vertexnode;
	Node* sort;//인접리스트를 오름차순으로 정렬하기 위한 변수
	sort = g->nearlist[v1];//정점의 첫 번째 노드를 가리키는 값을 대입
	if (v1 >= g->n || v2 >= g->n)
	{
		printf("\nThere are no vertices to fit in..\n");
		return;
	}
	vertexnode = (Node*)malloc(sizeof(Node));
	vertexnode->vertex = v2;

	if (sort != NULL)// 인접리스트에 어떤 노드가 들어가 있을 때 
	{
		if (sort->vertex >= vertexnode->vertex) //인접리스트 첫번째노드가 추가하려는 vertex보다클때
		{
			vertexnode->next = g->nearlist[v1]; //vertexnode->next를 원래 첫번째 인접 노드에 연결시킨다
			g->nearlist[v1] = vertexnode;//첫번째 인접 노드를 vertexnode로 지정한다
			return ;
		}
		else//인접리스트 첫번째노드가 추가하려는 vertex보다 작을때
		{
			while (sort->next != NULL)//ort->next를 가리키는 값이 NULL값이 나올 때 까지 반복한다.  
			{
				if (sort->next->vertex >= vertexnode->vertex)//현재 sort노드의 옆 노드의 vertex값이 넣으려고하는 vertex값보다 크거나 같다면
				{
					vertexnode->next = sort->next;
					sort->next = vertexnode;
					return ;
				}
				sort = sort->next; //sort 노드를 한 칸씩 움직인다
			}

			sort->next = vertexnode;//vertex노드를 맨마지막에 삽입한다
			vertexnode->next = NULL;
			return ;
		}
	}

	else//인접리스트에 아무것도 없을때
	{
		vertexnode->next = g->nearlist[v1];
		g->nearlist[v1] = vertexnode;
	}

	return ;
}



void DFS(Graph* g, int v)//깊이우선탐색
{
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		g->visit[i] = 0;         //탐색한 정점 표시할 배열 모두 0으로 초기화
	}


	Node* d;
	push(v);
	g->visit[v] = 1;         //첫 방문 노드 1로 초기화
	printf("%d", v);


	while (is_empty() != 1) //Stack 비워질때까지 반복
	{

		v = pop();//v를 pop();
		d = g->nearlist[v];//vertex정점의 인접노드를 d에 대입      

		while (d)//d가 0일때까지 반복한다 
		{
			if (g->visit[d->vertex] == 0) //노드를 한번도 방문한 적 없을 때
			{
				v = d->vertex;//V를 현재 인접노드로 바꿔준다
				push(v);//V를 집어넣는다   
				g->visit[v] = 1;//방문체크 배열을 1로 바꿔준다 
				printf("%d", v);//v를 출력   
				d = g->nearlist[v];//현재 VERTEX에 대한 인접노드로 d를 지정한다
			}
			else//노드가 방문한 적 있을 때
			{

				d = d->next; //다음 인접 정점으로 바꿔준다
			}
		}
	}
}

void BFS(Graph* g, int v)//너비 우선 탐색
{
	Node* w;
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		g->visit[i] = 0;         //방문한 vertex 배열 인덱스 모두 0으로 초기화
	}
	printf("%5d", v); /* print */
	g->visit[v] = 1;//방문체크 배열을 1로 바꿔준다   
	addq(v); /* enqueue */
	while (queue_empty() != 1) {
		v = deleteq(); /* dequeue */
		for (w = g->nearlist[v]; w; w = w->next)//한 정점에 붙어있는 노드들을 NULL값이 나올때까지 이동하면서 반복한다
		{
			if (!g->visit[w->vertex])//방문했던 노드가 아니라면
			{
				printf("%5d", w->vertex);//해당vertex출력
				addq(w->vertex);//큐에 추가한다
				g->visit[w->vertex] = 1;//방문체크해준다
			}
		}
	}
}

void push(int n)//스택 push함수
{
	if (is_full() == 1) {
		printf("STACK is FULL\n");
		return;
	}
	stack[++top] = n;//스택에 top을 쌓는다
}

int pop() {//스택에서 호출함수
	if (is_empty() == 1) {
		printf("STACK is empty");
		return 0;
	}
	return stack[top--];
}


int is_empty() {//스택이 비어있는지 체크하는 함수
	if (top == -1) {//비어있으면 1을 반환   
		return 1;
	}
	return 0;//차 있으면 0을 반환
}


int is_full() {//스택에서 가득차 있는지 체크하는 함수
	if (top >= stack_size - 1) { //가득차있으면 1을 반환     
		return 1;
	}
	return 0;//그렇치 않으면 0을 반환
}

int queue_empty() {//큐가 비어 있는지 확인하는 함수
	if (front == rear) {
		printf("\nQueue is empty\n");
		return 1;
	}
	return 0;
}

int queue_full() {      //큐가 가득차 있는지 체크하는 함수
	if ((rear + 1) % MAX_QUEUE_SIZE == front) {         //큐가 꽉 찼으면 1 리턴
		printf("Queue is full\n");
		return 1;
	}
	return 0;
}

int deleteq() //큐에서 front의 값을 반환 하는 함수
{
	int val = 0;
	if (queue_empty() == 1) {      //비었으면 탈출
		return 1;
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	val = queue[front];
	return val;


}
void addq(int v)//큐를 추가시켜주는 함수
{
	if (queue_full() == 1)
	{      //꽉찼으면 탈출
		return;
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	queue[rear] = v;
	//큐 뒤 부터 넣어준다
}

void Print_Graph(Graph* g)//그래프 출력함수
{
	Node* p;//노드를 담을 포인터변수
	for (int i = 0; i < g->n; i++)//vertex 갯수 만큼 반복한다
	{
		printf("adjlist of vertex %d: ", i);//vertex출력
		p = g->nearlist[i];//해당 vertex의 인접노드 p에 대입
		while (p != NULL) {  //해당 vertex에 인접노드 NULL값이 나올때까지 반복
			printf(", %d", p->vertex);
			p = p->next;       //다음 노드로 이동
		}
		printf("\n");
	}
}



#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 if necessary */

# define MAX_VERTEX 10
#define stack_size 10
typedef struct node
{
	int vertex;
	struct node* next;
}Node;


typedef struct
{
	Node* nearlist[MAX_VERTEX];
	int visit[MAX_VERTEX];   
	int n;
}Graph;



void initilizeGraph(Graph* g);
void printGraph(Graph* g);
void insertvertex(Graph* g);
void insertEdge(Graph* g, int v1, int v2);

void DFS(Graph* g, int v);
void freeGraph(Graph* g);

/*DFS에 필요한 함수*/
void push(int n) ;
int pop();
int stack[stack_size] = { 0, };
int top = -1;
int is_empty();
int is_full();

/*BFS에 필요한 함수*/
void Print_Graph();

int main()
{
	char command;
	int n1, n2;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	int v;

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

		switch (command) {
		case 'z': case 'Z':
			initilizeGraph(G);
			break;
		case 'i': case 'I':
			insertvertex(G);
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
				scanf_s("%d", &v);
				DFS(G, v);
				break;
			/*case 'e': case 'E':
				deleteLast(headnode);
				break;
			case 'f': case 'F':
				printf("Your Key = ");
				scanf_s("%d", &key);
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
				break;*/
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}


void initilizeGraph(Graph*g)
{
	g->n = 0;
	for (int n = 0; n < MAX_VERTEX; n++)
	{
		g->nearlist[n] = NULL;
	}

}

void insertvertex(Graph*g)
{
	if (g->n  >= MAX_VERTEX)
	{
		printf("\nover number of vertex .\n");
		return;
	}
	g->n++;
	printf("number of vertex: %d\n",g->n);
}

void insertEdge(Graph* g, int v1, int v2)
{
	Node* vertexnode;
	Node* sort;//인접리스트를 오름차순으로 정렬하기 위한 변수
	sort=g->nearlist[v1];//정점의 첫 번째 노드를 가리키는 값을 대입
	if (v1 >= g->n || v2 >= g->n)
	{
		printf("\nThere are no vertices to fit in..\n");
		return;
	}
	vertexnode = (Node*)malloc(sizeof(Node));
	vertexnode->vertex = v2;

	if (sort!= NULL)// 인접리스트에 어떤 노드가 들어가 있을 때 
    {
		if (sort->vertex>=vertexnode->vertex ) //인접리스트 첫번째노드가 추가하려는 vertex보다클때
        {
            	vertexnode->next = g->nearlist[v1]; //vertexnode->next를 원래 첫번째 인접 노드에 연결시킨다
				g->nearlist[v1] = vertexnode;//첫번째 인접 노드를 vertexnode로 지정한다
         	   return 0;
        }
		else//인접리스트 첫번째노드가 추가하려는 vertex보다 작을때
		{
        while (sort->next!= NULL)//ort->next를 가리키는 값이 NULL값이 나올 때 까지 반복한다.  
            {
                if (sort->next->vertex>= vertexnode->vertex)//현재 sort노드의 옆 노드의 vertex값이 넣으려고하는 vertex값보다 크거나 같다면
                {	
					vertexnode->next=sort->next;
					sort->next=vertexnode;
					return 0;
                }
                sort = sort->next; //sort 노드를 한 칸씩 움직인다
            }
         
      	sort->next =vertexnode ;//vertex노드를 맨마지막에 삽입한다
		vertexnode->next=NULL; 
        return 0;
		}
	}

    else//인접리스트에 아무것도 없을때
    {
        vertexnode->next = g->nearlist[v1];
		g->nearlist[v1] = vertexnode;
    }

	return 0;
}



void DFS(Graph* g, int v) 
{
   for (int i = 0; i < MAX_VERTEX; i++)
    {
      g->visit[i] = 0;       
   	}

   Node* d;           
   push(v);   
   g->visit[v] = 1;      
   printf("%d", v);

   while (is_empty() != 1) 
   {
      v = pop();
      d= g->nearlist[v];      

      while (d) 
	  {
         if (g->visit[d->vertex] == 0) 
		 {         
            push(v);
            push(d->vertex);
            g->visit[d->vertex] = 1;
            printf("%3d", d->vertex);
            v = d->vertex;
            d = g->nearlist[v];
         }
         else d= d->next;        
      }
   }
}

void push(int n) {
   if (is_full() == 1) {
      printf("STACK is FULL\n");
      return;
   }
   stack[++top] = n;
}

int pop() {
   if (is_empty() == 1) {
      printf("STACK is empty");
      return 0;
   }
   return stack[top--];
}


int is_empty() {
   if (top == -1) {   
      return 1;
   }
   return 0;
}


int is_full() {
   if (top >= stack_size - 1) {      
      return 1;   
   }
   return 0;
}

void print_graph(Graph* g) 
{
  
}

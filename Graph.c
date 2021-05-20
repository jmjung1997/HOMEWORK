
#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 if necessary */

# define MAX_VERTEX 10
typedef struct node
{
	int vertex;
	struct node* next;
}Node;


typedef struct
{
	Node* graph[MAX_VERTEX];
	int visited;
	int n;
}Graph;



void initilizeGraph(Graph* g);
void printGraph(Graph* g);
void insertvertex(Graph* g, int n);
void insertEdge(Graph* g, int v1, int v2);
void freeGraph(Graph* g);



int main()
{
	char command;
	int n1, n2;
	Graph* G = (Graph*)malloc(sizeof(Graph));

	printf("\n정재민      2018038067\n\n");
	do {
		printf("----------------------------------------------------------------\n");
		printf("                        Graph  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph    = z                               ");
		printf(" \nInsert  Vertex      = i         Insert Edge          = e \n");
		printf(" Depth First Search  = d         Breath First Search = b\n");
		printf(" Print Graph         = p         Quit                = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf_s(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			initilizeGraph(&G);
			break;
		case 'i': case 'I':
			insertvertex(&G, G->n);
			break;
		case 'e': case 'E':
			printf("연결시킬 노드를 입력하세요: (v1, v2)");
			scanf_s(" %d", &n1);
			scanf_s(" %d", &n2);
			insertEdge(&G, n1, n2);
			break;

			/*case 'n': case 'N':
				printf("Your Key = ");
				scanf_s("%d", &key);
				insertLast(headnode, key);
				break;
			case 'e': case 'E':
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


void initilizeGraph(Graph** g)
{
	(*g)->n = 0;
	for (int n = 0; n < MAX_VERTEX; n++)
	{
		(*g)->graph[n] = NULL;
	}

}

void insertvertex(Graph** g, int n)
{
	if ((((*g)->n) + 1) > MAX_VERTEX)
	{
		printf("\n정점의 개수를 초과하였습니다.\n");
		return;
	}
	(*g)->n++;

}

void insertEdge(Graph** g, int v1, int v2)
{
	Node* vertexnode;
	if (v1 >= (*g)->n || v2 >= (*g)->n)
	{
		printf("\n 그래프에 없는 정점입니다.\n");
		return;
	}
	vertexnode = (Node*)malloc(sizeof(Node));
	vertexnode->vertex = v2;
	vertexnode->next = (*g)->graph[v1];
	(*g)->graph[v1] = vertexnode;
}

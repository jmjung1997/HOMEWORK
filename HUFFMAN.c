#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct node {
   char character;
   int cnt;
   struct node* next;
   struct node* left;
   struct node* right;
} Node;

Node *head=0;

int add(Node* add_node);
Node* HuffmanTree( );
void inorderTraversal(Node* cur);
void push(int n);
int pop();
void showAll();
void showCode();
void characterNum(char* buf_count);
void createVertex(char t);
Node* findsmallest();
Node* findcharacter(char g);
void freeNode(Node* ptr);
void printList(Node* h);

int stack[100];
int top = -1;
int main()
{
	char buf[100];
	printf("Put the string to encode: ");
    scanf("%s", buf);
	characterNum(buf);

   Node*tree = HuffmanTree();
   inorderTraversal(tree);
   printf("clear");
   return 0;
}



Node* HuffmanTree( )
{
   
   while (1)
   {
      Node* first = findsmallest();   // 빈도수 제일 낮은 것을 뽑는다.
      Node* second = findsmallest();

      if (second == 0)   // 마지막에 트리만 뽑힌다.
      {
         return first;
      }
      Node*new = (Node*)malloc(sizeof(Node));
      new->next = 0;
      new->left = first;
      new->right = second;
  
      new->cnt = first->cnt + second->cnt;

      add(new);   // 트리 전체를 구성원으로 넣는다.
   
   }
   
}


void inorderTraversal(Node* cur)
{
   if (cur == 0)
   {
      pop();
      return;
   }
   push(0);
   inorderTraversal(cur->left);
   if (cur->left == 0 && cur->right == 0)
   {
      printf("%c : ",cur->character);
      showCode();
   }
   push(1);
   inorderTraversal(cur->right);
   pop();
}

void push(int n)
{
   top += 1;
   stack[top] = n;
}

int pop()
{
   int result = stack[top];
   top -= 1;
   return result;
}


void showAll()
{
   Node*temp =NULL;
   while (temp != 0)
   {
      printf("%c : %d\n", temp->character, temp->cnt);
      temp = temp->next;
   }
}

void showCode()
{
   for (int i = top-1; i >= 0; i--)
   {
      printf("%d", stack[i]);
   }
   printf("\n");
}


void characterNum(char* buf_count)
{
   char v;
   for (int i = 0; i < 99; i++)
   {
      if (buf_count[i] == '\0')
      {
         return;
      }
      v = buf_count[i];
      if (findcharacter(v) == 0)
      {
         createVertex(v);
      }
      else
      {
         Node*find =findcharacter(v);
         find->cnt += 1;
      }
   }
}

void createVertex(char t)
{   
   Node*new = (Node*)malloc(sizeof(Node));
   new->character = t;
   new->cnt = 1;
   new->left = 0; 
   new->right = 0;
   new->next = 0;

   add(new);
}

int add(Node* add_node)
{
	
   if (head == NULL)
   {
      head= add_node;
      return 0;
   }

   Node*p=head;
   if (p->cnt >= add_node->cnt) //노드를 연결리스트에 넣으려고했는데 첫번째 노드에 있는 cnt값보다 add_node->cnt 값이 작을 때
        {
            add_node->next = p; 
            head=add_node;
            return 0;
        }
   else
        {
		//노드를 연결리스트에 넣으려고했는데 첫번째 노드에 있는 cnt값보다 add_node->cnt 값이 클 때
        
            while (p->next != NULL)//p->next를 가리키는 값이 NULL값이 나올 때 까지 반복한다.  
            {
                if (p->next->cnt >= add_node->cnt)//현재 p의노드에서 옆에 다음 노드의 cnt값이 넣으려고하는 cnt값보다 크다면
                {
					     add_node->next = p->next;
                    p->next =add_node; //현재 p가 가리키고 다음 노드의 주소 정보를 add_node에 대입한다 
                    return 0;
                }
                p = p->next; //p의 노드를 한 칸씩 움직인다
            }
          /* NULL값이 나올 때 까지 while문을 반복했음에도 기존에 있던 노드들의 키값이 넣으려고하는 키값보다 다 작을때*/
        p->next = add_node; //연결리스트 맨 뒤에 노드를 추가해준다.
        return 0;
	      }
}     


Node* findsmallest()
{
   Node*short_node = head;
   if (head == 0)
   {
      return 0;
   }
	head=head->next;
   return short_node;
}
    
Node* findcharacter(char g)
{
   Node *temp = head;
   while (temp != 0)
   {
      if (temp->character == g)
      {
         return temp;
      }
      temp = temp->next;
   }
   return 0;
}





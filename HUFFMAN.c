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

int sorting(Node* add_node)
{

}


int add(Node* add_node)//
{
	if(head==0)
   {
      head=add_node;
   }
   Node*temp=head;
   while (temp->next)
   {
      temp=temp->next;
   }
   temp->next=add_node;
   
}     


Node* findsmallest()
{
   
    int short_num =0;
    Node* short_node = head;

    if (head == 0)
    {
        return 0;
    }

    Node* temp = head;
    while (temp != 0)
    {
        if (temp->cnt < short_num)
        {
            short_node = temp;
            short_num = temp->cnt;
        }
        temp = temp->next;
    }

    if (short_node == head)
    {
        head = head->next;
    }
    else
    {
        Node* prev = head;
        while (prev->next != short_node)
        {
            prev = prev->next;
        }
        prev->next = short_node->next;
    }

    short_node->next = 0;
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





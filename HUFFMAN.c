#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define max 100
#define ALPHABET 27



typedef struct node {
   int frequency;
   char character;
   struct node* left;
   struct node* right;
} Node;

Node **heap;
int lastheap=0;

void insert_heap(Node *item) {
    int here = ++(hp->heap_size);
    while ((here != 1) && (item->frequency < hp->heap[here / 2]->frequency)) {
        hp->heap[here] = hp->heap[here / 2];
        here /= 2;
    }
    hp->heap[here] = item;
}

Node* deleteData(heaptype* hp) {
    int parent, child;
    Node* item;
    Node* temp;

    item=hp->heap[1];
    temp=hp->heap[(hp->heap_size)--];
    parent=1;
    child=2;


    while (child <= hp->heap_size)
   {

      if ((child <= hp->heap_size) && (hp->heap[child]->frequency > hp->heap[child + 1]->frequency))

         child++;

      if (temp->frequency < hp->heap[child]->frequency) break;

      hp->heap[parent] = hp->heap[child];

      parent = child;

      child *= 2;

   }
   hp->heap[parent]=temp;
   return item;

}

Node*create_tree(Node*left, Node*right)
{
   Node *node=(Node*)malloc(sizeof(Node));
   node->left=left;
   node->right=right;
   return node;

}


void delete_tree(Node*head)
{
   if(head==NULL)return;
   delete_tree(head->left);
   delete_tree(head->right);
   free(head);
}

void huffmantree(int Big_char[],int small_char[], int n)
{
   Node *first;
   Node *second;
   
  while(1)
  {
     first=delete_tree();
     second=delete_tree();
  
   if(second)
  {
     break;
  }
  Node* newone=(Node*)malloc(sizeof(Node));
  newone->frequency=first->frequency+second->frequency;
  newone->left=first;
  newone->right=second;

  insert_heap(newone);
  }

}

void make_heap(int i, int freq[])
{
   Node *cur= (Node*)malloc(sizeof(Node));
   cur->character=(char)(i+65);
   cur->frequency=freq;
}

int countcharater(int freq[])//출현빈도수 1이상인 갯수를 센다
{
   int cnt=0;
   for(int i=0;i<26;i++)
   {
      if(freq[i]>0)
      {
         cnt++;
      }
   }
}

int main()
{
    int i=0;
    int cnt=0;
    int cnt_big=0;
    int cnt_small=0;
    int Freq_big[ALPHABET]={0};
    int freq_small[ALPHABET]={0};
    char str[100];
    printf("Input String : ");
    scanf("%s", str);
   while (1)
   {
      
      if(str[i]=='\0') break;
      j=str[i];
      if(0<=(j-65)&&(j-65)<=25)
      {
         Freq_big[j-65]+=1;      
      }
      else if(32<=(j-65)&&(j-65)<57)
      {
         freq_small[-65]+=1;
      }
      i++;
   }
   cnt_big=countchara(Freq_big);
   cnt_small=countchara(freq_small);
   cnt=cnt_small+cnt_big;
   heap=(Node**)malloc((cnt+1)*sizeof(Node*));
  huffmantree( Freq_big, freq_small, ALPHABET);
    return 0;
}
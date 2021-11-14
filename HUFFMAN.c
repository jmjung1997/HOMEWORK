#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define max 100
#define ALPHABET 27



typedef struct node {
   int frequency;
   int character;
   struct node* left;
   struct node* right;
} Node;


typedef struct heap_array{
  Node *newnode;
  int freq;
}element;

typedef struct heap
{
   element heap[max];
   int heap_size;
}heaptype;


void initHeap(heaptype* hp) {
    hp->heap_size = 0;
}

void insert_heap(heaptype* hp, element item) {
    int here = ++(hp->heap_size);
    while ((here != 1) && (item.freq < hp->heap[here / 2].freq)) {
        hp->heap[here] = hp->heap[here / 2];
        here /= 2;
    }
    hp->heap[here] = item;
}

element deleteData(heaptype* hp) {
    int parent, child;
    element item, temp;

    item=hp->heap[1];
    temp=hp->heap[(hp->heap_size)--];
    parent=1;
    child=2;


    while (child <= hp->heap_size)
   {

      if ((child <= hp->heap_size) && (hp->heap[child].freq) > hp->heap[child + 1].freq)

         child++;

      if (temp.freq < hp->heap[child].freq) break;

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
  if
}

int main()
{
    int i=0;
    int j=0;
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
         freq_small[j-65]+=1;
      }
      i++;
   }
   
    huffmantree( Freq_big, freq_small, ALPHABET);
    return 0;
}
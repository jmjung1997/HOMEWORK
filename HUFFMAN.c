#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define ALPHABET 26
#define MAX 100


typedef struct node {
    int frequency;
    char character;
    struct node* left;
    struct node* right;
} Node;

Node** heap;
int lastheap = 0;
char codetable[MAX];
int codetable_index = -1;
char* huffmancode[200];
void searchcode(Node* temp, char c);
char result[][50] = { 0, };
void decoding_print(int index);
void add_heap(Node* newnode)
{
    lastheap++;
    heap[lastheap] = newnode;
    int here = lastheap;
    int parent = lastheap / 2;

    while (parent >= 1)
    {
        if (heap[parent]->frequency > heap[here]->frequency)
        {
            Node* temp = heap[parent];
            heap[parent] = heap[here];
            heap[here] = temp;
            here = parent;
            parent = here / 2;
        }
        else
        {
            break;
        }
    }
}

Node* delete_heap()
{
    int parent = 1;
    int child = 2;


    if (lastheap <= 0)
    {
        printf("result\n\n");
        return 0;
    }

    Node* return_node = heap[1];
    Node* temp = heap[lastheap--];

    while (child <= lastheap)
    {

        if ((child <= lastheap) && (heap[child]->frequency > heap[child + 1]->frequency))

            child++;

        if (temp->frequency < heap[child]->frequency) break;

        heap[parent] = heap[child];

        parent = child;

        child *= 2;

    }
    heap[parent] = temp;
    return return_node;

}




void huffmantree()
{
    Node* first = 0;
    Node* second = 0;

    while (1)
    {
        first = delete_heap();
        second = delete_heap();

        if (second == 0)
        {
            break;
        }
        Node* newone = (Node*)malloc(sizeof(Node));
        newone->frequency = first->frequency + second->frequency;
        newone->left = first;
        newone->right = second;
        newone->character = 0;
        add_heap(newone);
    }
    memset(huffmancode, 0, sizeof(huffmancode));
    searchcode(first->left, '0');//first는 허프만트리의 root 노드를 가리킨다. 
    searchcode(first->right, '1');

}

void searchcode(Node* temp, char c)
{
    codetable_index++;
    codetable[codetable_index] = c;
    codetable[codetable_index + 1] = NULL;

    if (temp->left == 0 && temp->right == 0)
    {
        // 문자에 해당하는 허프만 코드 저장하는 함수
        char* Huffcode = (char*)malloc(strlen(codetable) + 1);
        strcpy(Huffcode, codetable);
        huffmancode[(int)temp->character] = Huffcode;
    }
    else
    {
        searchcode(temp->left, '0');
        searchcode(temp->right, '1');
    }
    codetable[codetable_index] = NULL;
    codetable_index--;
    return;

}





void make_heap(int i, int freq[])
{
    Node* cur = (Node*)malloc(sizeof(Node));

    cur->character = (char)(i + 65);
    cur->frequency = freq[i];
    cur->left = 0;
    cur->right = 0;
    add_heap(cur);
}

void delete_tree(Node* head)
{
    if (head == NULL)return;
    delete_tree(head->left);
    delete_tree(head->right);
    free(head);
}

void encoding_print(char str_[])
{
    int i = 0;
    int j = 0;
    int index = -1;
    while (1)
    {

        if (str_[i] == '\0') break;
        j = str_[i];
        printf("%s", huffmancode[j]);
        result[++index][20] = huffmancode[j];
        i++;
    }

    printf("\n\ndecoding to....\n\n");
    decoding_print(index);
    return;
}

void decoding_print(int index)
{
    char decode_result[100];

    for (int i = 0; i < index; i++)
    {
        if (result[i][50] == 0)
        {
            return;
        }
        for (int j = 65; j <= 122; j++)
        {
            if (result[i][50] == huffmancode[j])
            {
                decode_result[i]=(char)j;
            }
        }
    }
    printf("%s",decode_result);
    return;
}



int main()
{
    int i = 0;
    int j = 0;
    int Freq_big[ALPHABET] = { 0 };
    int freq_small[ALPHABET + 32] = { 0 };
    char str[100];
    heap = (Node**)malloc(MAX * sizeof(Node*));
    memset(heap, 0, MAX * sizeof(Node*));
    printf("Input String : ");
    scanf("%s", str);
    while (1)
    {

        if (str[i] == '\0') break;
        j = str[i];
        if (0 <= (j - 65) && (j - 65) <= 25)
        {
            Freq_big[j - 65] += 1;
        }
        else if (32 <= (j - 65) && (j - 65) <= 57)
        {
            freq_small[j - 65] += 1;

        }
        else
        {
            printf("알파벳만 입력해주세요 \n");
            break;
        }
        i++;
    }

    for (int i = 0; i < ALPHABET; i++)
    {
        if (Freq_big[i] > 0)
        {
            make_heap(i, Freq_big);
        }
    }
    for (int i = 32; i < ALPHABET + 32; i++)
    {
        if (freq_small[i] > 0)
        {
            make_heap(i, freq_small);
        }
    }
    huffmantree();

    printf("encoding to....\n\n");
    encoding_print(str);

    return 0;

}
// Huffman Encoding in C 
//---------------------------------------------------
// Created by Jithin K C
//----------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 50

//----------------------------------------------------

struct mnode {
  char item;
  unsigned freq;
  struct mnode *left, *right;
  struct mnode *ty[100],*dt;
};

struct mheap {
  unsigned size;
  unsigned capacity;
  struct mnode **array;
};
//----------------------------------------------------
// Print the array
//----------------------------------------------------
void disparray(int arr[], int n, char s) {
  int i;
  

  printf("%c = ", s);
  for (i = 0; i < n; ++i)
    {
     
       printf("%d",arr[i]);
      
    }
    printf("\n");

    
}
//----------------------------------------------------
// Create nodes
//----------------------------------------------------
struct mnode *newNode(char item, unsigned freq) {
  struct mnode *temp = (struct mnode *)malloc(sizeof(struct mnode));

  temp->left = temp->right = NULL;
  temp->item = item;
  temp->freq = freq;

  return temp;
}
//----------------------------------------------------
// Create min heap
//----------------------------------------------------
struct mheap *createMinH(unsigned capacity) {
  struct mheap *minHeap = (struct mheap *)malloc(sizeof(struct mheap));

  minHeap->size = 0;

  minHeap->capacity = capacity;

  minHeap->array = (struct mnode **)malloc(minHeap->capacity * sizeof(struct mnode *));
  return minHeap;
}
//----------------------------------------------------
// Function to swap
//----------------------------------------------------
void swapMinHNode(struct mnode **a, struct mnode **b) {
  struct mnode *t = *a;
  *a = *b;
  *b = t;
}
//----------------------------------------------------
// Heapify
//----------------------------------------------------
void minHeapify(struct mheap *minHeap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;

  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;

  if (smallest != idx) {
    swapMinHNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}
//----------------------------------------------------
// Check if size if 1
//----------------------------------------------------
int checkSizeOne(struct mheap *minHeap) {
  return (minHeap->size == 1);
}
//----------------------------------------------------
// Extract min
//----------------------------------------------------
struct mnode *extractMin(struct mheap *minHeap) {
  struct mnode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];

  --minHeap->size;
  minHeapify(minHeap, 0);

  return temp;
}
//----------------------------------------------------
// Insertion function
//----------------------------------------------------
void insertMinHeap(struct mheap *minHeap, struct mnode *minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && minHeapNode->freq <= minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minHeap->array[i] = minHeapNode;
}
//----------------------------------------------------
//building min heap
//----------------------------------------------------
void buildMinHeap(struct mheap *minHeap)
{
  int n = minHeap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    minHeapify(minHeap, i);
}

int isLeaf(struct mnode *root) {
  return !(root->left) && !(root->right);
}

//----------------------------------------------------
//creating min heap tree
//----------------------------------------------------
struct mheap *createAndBuildMinHeap(char item[], int freq[], int size)
{
  struct mheap *minHeap = createMinH(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(item[i], freq[i]);

  minHeap->size = size;
  buildMinHeap(minHeap);

  return minHeap;
}

//----------------------------------------------------
//tree building function
//----------------------------------------------------
struct mnode *buildHuffmanTree(char item[], int freq[], int size) 
{
  struct mnode *left, *right, *top;
  struct mheap *minHeap = createAndBuildMinHeap(item, freq, size);

  while (!checkSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    top = newNode('$', left->freq + right->freq);

    top->left = left;
    top->right = right;

    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

//----------------------------------------------------
//display function 
//----------------------------------------------------
void printheap(struct mnode *root, int arr[], int top, char t) {
    
  if (root->left) {
    arr[top] = 0;
    printheap(root->left, arr, top + 1,t);
  }
  if (root->right) {
    arr[top] = 1;
    printheap(root->right, arr, top + 1,t);
  }
  if (isLeaf(root)) {
      if(root->item==t)
      {
    
    disparray(arr, top,root->item);
      }
  }
}
//----------------------------------------------------
// Huff-main function
//----------------------------------------------------

void huff(char item[], int freq[], int size, char *jk) 
{
  struct mnode *root = buildHuffmanTree(item, freq, size);

  int arr[MAX_TREE_HT], top = 0,i;

 for(i=0;i<size;i++)
 {
  printheap(root, arr, top, jk[i]);
 }
}
//----------------------------------------------------
// Frequency of strings
//----------------------------------------------------
int fr(char *g,int *ch,int i)
{
    char string[100];
   int c = 0, count[26] = {0}, x;

   printf("Enter a string:");
   fgets(string,sizeof(string),stdin);


   while (string[c] != '\0' && string[c] !='\n' && string[c] !=' ' ) {
   /** Considering characters from 'a' to 'z' only and ignoring others. */

      if (string[c] >= 'a' && string[c] <= 'z') {
         x = string[c] - 'a';
         count[x]++;
      }

      c++;
   }

   for (c = 0; c < 26; c++)
   {
   
            if(count[c]!=0)
            {
       
         g[i] = c + 'a';
         
         ch[i]=count[c];
         i=i+1;
            }
   }
 
return i;
}
//----------------------------------------------------
// string Sort 
//----------------------------------------------------
void ss(char *ch)
 {
   char temp;

   int i, j;
   int n = strlen(ch);

   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (ch[i] > ch[j]) {
            temp = ch[i];
            ch[i] = ch[j];
            ch[j] = temp;
         }
      }
   }

 }
//-----------------------------------------------------
// Main function
//----------------------------------------------------
int main() 
{
    
   char g[100],jk[100];
  int ch[100],i=0,j=0;

  i=fr(g,ch,i);

  strcpy(jk,g);

  ss(jk);
  
  huff(g, ch, i,jk);

return 0;
    
}

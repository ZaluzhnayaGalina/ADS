/*
 * online_five.c
 *
 * Created by Ivan I. Ovchinnikov
 * at day 031 of year 2019 (Jan 31), 19:53
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define T char
// #define SZ 1000
// T Stack[SZ];
// int idx = -1;

// void push(T i) {
//   if (idx < SZ)
// 	Stack[++idx] = i;
//   else
// 	printf("%s\n", "Stack overflow");
// }

// T pop() {
//   if (idx != -1)
// 	return Stack[idx--];
//   else
// 	printf("%s\n", "Stack is empty");
//   return -1;
// }

typedef struct Node {
  T data;
  struct Node *next;
} Node;

typedef struct List {
  Node *head;
  int size;
} Stack;

int push(Stack *st, T val) {
  Node *temp = (Node*) malloc(sizeof(Node));
  if (temp == NULL) return 0;

  temp->data = val;
  temp->next = st->head;

  st->head = temp;
  st->size++;
  return 1;
}

T popStack(Stack *st) {
  if (st->size == 0)
	return -1;

  Node* current = st->head;
  T result = st->head->data;
  st->head = st->head->next;
  st->size--;
  free(current);
  return result;
}

typedef struct DNode {
  T data;
  struct DNode *prev;
  struct DNode *next;
} DNode;

typedef struct DList {
  DNode *head;
  DNode *tail;
  int size;
} DStack;

void dpush(DStack *s, T value) {
  DNode* temp = (DNode*) malloc(sizeof(DNode));
  if (temp == NULL) return;

  temp->data = value;
  temp->next = s->head;
  temp->prev = NULL;

  if (s->head == NULL)
	s->tail = temp;
  else
	s->head->prev = temp;

  s->head = temp;
  s->size++;
}

T dpop(DStack *s) {
  if (s->size == 0)
	return -1;

  DNode *temp = s->head;
  T result = s->head->data;
  s->head = s->head->next;

  if (s->size > 1)
	s->head->prev = NULL;
  else
	s->tail = NULL;

  free(temp);
  s->size--;
  return result;
}
char* decToBinary(int dec)
{
	Stack s;
	s.size=0;
	s.head=NULL;
	while(dec>0)
	{
		push(&s,dec%2);
		printf("%d\n", s.size);
		dec=dec/2;
	}
	char* res = (char*)malloc(sizeof(char)*s.size);
	for(int i=0; i<s.size;i++)
		res[i]=popStack(&s);
	return res;
}
int checkSequence(char* sequence, int size)
{
	Stack s;
	s.size=0;
	s.head=NULL;
	
	for(int i=0; i<size;i++)
	{
		if (sequence[i]=="(" ||sequence[i]=="["||sequence[i]=="{")
			push(&s, sequence[i]);
		if (sequence[i]=")"&&popStack(&s)=="(")
			continue;
		if (sequence[i]="]"&&popStack(&s)=="[")
			continue;
		if (sequence[i]="}"&&popStack(&s)=="{")
			continue;
		return 0;
		
	}
	
}
int main(int argc, const char** argv)
{
	char* res =	decToBinary(5);
	printf("257=%s\n",res );
	return 0;
}

/*
 * online_seven.c
 *
 * Created by Ivan I. Ovchinnikov
 * at day 038 of year 2019 (Feb 07), 19:53
 */
#include <stdio.h>
#include <stdlib.h>
#define T GraphNode
typedef struct GraphNode {
  int data;
  int index;
  int used;
  struct Stack* children;
} GraphNode;
typedef struct Node {
	T data;
	struct Node *next;
} Node;

typedef struct List {
	Node *head;
	int size;
} Stack;

int push(Stack *st, T val) {
	Node *temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) return 0;

	temp->data = val;
	temp->next = st->head;

	st->head = temp;
	st->size++;
	return 1;
}

T popStack(Stack *st) {
	if (st->size == 0)
		return;

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

typedef struct DQueue {
	DNode *head;
	DNode *tail;
	int size;
} DQueue;

void enqueue(DQueue *q, T value) {
	DNode* temp = (DNode*)malloc(sizeof(DNode));
	if (temp == NULL) return;

	temp->data = value;
	temp->next = NULL;
	temp->prev = q->tail;

	if (q->tail == NULL)
		q->head = temp;
	else
		q->tail->next = temp;

	q->tail = temp;
	q->size++;
}

T dequeue(DQueue *s) {
	if (s->size == 0)
		return;

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

DQueue q; //graph queue
int widthTravers(GraphNode *start, GraphNode *stop) {
  enqueue(&q, start);
  start->used = 1;
  while (q->size != 0) {
	GraphNode current = dequeue(&q);
	if (current.data == stop->data) {
	  return 1;
	}

	while (current->children.size != 0) {
	  GraphNode child = popStack(current->children);
	  if (child.used != 1){
		enqueue(q, child);
		child.used=1;
	  }
	}
  }
  //clear all flags
  return 0;
}

const int w = 12;
const int h = 9;
const int OBSTACLE = -1;
const int UNVISITED = -2;
int grid[h][w]
int len;
int pointX[h * w];
int pointY[w * h];
// init grid (set all unvisited)
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int lee(int sx, int sy, int ex, int ey) {
  int x, y, vector, dist, stop;
  if (sx == ex && sy == ey) return 0;
  if (grid[sy][sx] == OBSTACLE || grid[ey][ex] == OBSTACLE) return 0;

  dist = 0;
  grid[sy][sx] = dist;
  do {
	stop = 1;
	for (y = 0; y < h; y++) {
	  for (x = 0; x < w; x++) {
		if (grid[y][x] == dist) {
		  for (vector = 0; vector < 4; vector++) {
			int nextX = x + dx[vector];
			int nextY = y + dy[vector];
			if (nextX >= 0 && nextX < w &&
				nextY >= 0 && nextY < h &&
				grid[nextY][nextX] == UNVISITED){
			  stop = 0;
			  grid[nextY][nextX] = dist + 1;
			}			  
		  }
		}
	  }
	}
	dist++;
  } while (!stop && grid[ey][ex] == UNVISITED);

  if (grid[ey][ex] == UNVISITED) return 0;

  len = grid[ey][ex];
  x = ex;
  y = ey;
  while (dist > 0) {
	pointX[dist] = x;
	pointY[dist] = y;
	dist--;
	for (vector = 0; vector < 4; vector++) {
	  int nextX = x + dx[vector];
	  int nextY = y + dy[vector];
	  if (nextX >= 0 && nextX < w &&
		  nextY >= 0 && nextY < h &&
		  grid[nextY][nextX] == dist) {
		x = nextX;
		y = nextY;
	  }
	}
  }
  return 1;
}

int main(int argc, const char** argv)
{
	q.head=NULL;
	q.tail = NULL;
	
	return 0;
}

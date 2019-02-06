/*
* online_six.c
*
* Created by Ivan I. Ovchinnikov
* at day 035 of year 2019 (Feb 04), 20:21
*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define T int

#define SIZE 10
typedef struct TreeNode {
	T data;
	struct TreeNode *left;
	struct TreeNode *right;
} Node;

void preOrderTravers(Node *root) {
	if (root) {
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}
int tree_i = 0;
Node* tree(int amount, int* array) {
	Node *node;
	int nL;
	int nR;
	if (amount == 0) {
		node = NULL;
	}
	else {
		int value;
		//тут мы читаем из файла или массива данные внутрь переменной value
		value = array[tree_i];
		node = (Node*)malloc(sizeof(Node));		
		node->data = value;
		if (amount == 1)
		{
			node->left = NULL;
			node->right = NULL;
			return node;
		}
		tree_i++;
		nL = amount / 2;
		nR = amount - nL;
		node->left = tree(nL, array);
		node->right = tree(nR, array);
	}
	return node;
}

int main(int argc, const char** argv) {

	int arr[SIZE];
	srand(time(NULL));
	for (int i = 0; i<SIZE; i++)
	{
		arr[i] = rand() % 100;
	}
	Node *root = tree(SIZE, arr);
	preOrderTravers(root);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node *left;
	struct Node *right;
};

struct Node *bst(struct Node* root, int data);
void inOrderTraversal(struct Node* head);
void Free(struct Node* node);
struct Node *create(int data);

int main(int argc, char* argv[argc + 1]){
	if(argc != 2){
		printf("insufficient arguments\n");
		return 0;
	}

	FILE *f = fopen(argv[1], "r");
	if( f == NULL){
		printf("Error\n");
		return 0;
	}
	struct Node *root = NULL;
	char a; int num;
	while(fscanf(f, "%c\t%d\n", &a, &num) != EOF){
		if( a == 'i'){
			root = bst(root, num);
		}
	}
	
	inOrderTraversal(root);
	fclose(f);
	Free(root);
	return 0;
}

struct Node *create(int data){
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode -> val = data;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}

struct Node *bst(struct Node* root, int data){
	if(root == NULL){
		return create(data);
	}
	if(root -> val == data){
		return root;
	}
	else if(root -> val > data){
		root -> left = bst(root -> left, data);
	}
	else{
		root -> right = bst(root -> right, data);
	}
	
	return root;
}

void inOrderTraversal(struct Node *head){
	if (head == NULL){
		return;
	}
	
	inOrderTraversal(head -> left);
	
	inOrderTraversal(head -> right);

	printf("%d\t", head -> val);

}
void Free(struct Node *node){
	if(node != NULL){
		Free(node -> left);
		Free(node -> right);
		free(node);
	}
}

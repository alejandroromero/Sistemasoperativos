#include<stdlib.h>
#include<stdio.h>

struct arbol_el {
   int val;
   struct arbol_el * right, * left;
};

typedef struct arbol_el node;

void insert(node ** arbol, node * item) {
   if(!(*arbol)) {
      *arbol = item;
      return;
   }
   if(item->val<(*arbol)->val)
      insert(&(*arbol)->left, item);
   else if(item->val>(*arbol)->val)
      insert(&(*arbol)->right, item);
}

void printout(node * arbol) {
   if(arbol->left) printout(arbol->left);
   printf("%d\n",arbol->val);
   if(arbol->right) printout(arbol->right);
}

void main() {
   node * curr, * root;
   int i;

   root = NULL;



  for(i=1;i<=10;i++) {
        curr = (node *)malloc(sizeof(node));
        curr->left = curr->right = NULL;
        printf("add a number\n");
        scanf("%d", &curr->val);
        insert(&root, curr);
        printf("new array looks like:\n" );
        printout(root);
    }
}
/**********************************
 *  Copyright@ Daipayan Bhowal
 *  Developed by Daipayan Bhowal
 *  Made in India
 *  Date 18-06-2021
**********************************/
#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *left;
  int data;
  struct node *right;
};
/* compress node structure aka linked list by daipayan */
struct node_c
{
  int data;
  struct node_c *next;
};
struct node_c **leafnode_ptr; // a dynamic array that stores the leafnode
static int i=0;
void compdp_trav(struct node* ptr, struct node* prev,struct node_c* previousnode)
{
  struct node* left = ptr->left;
  struct node* right = ptr->right;

 /* Creating a duplicate node with different linked list structure node_c by daipayan*/
  struct node_c* new_node = (struct node_c*) malloc(sizeof(struct node_c));
  new_node->data = ptr->data;
  /* For first node set next as NULL by daipayan */
  if(prev = NULL)
    new_node->next = NULL;
  else
    new_node->next = previousnode;

  /* If its a leafnode then store it in a table, increment the static counter and terminate the algorithm by daipayan*/
  if(ptr->left == NULL && ptr->right == NULL)
  {
      leafnode_ptr[i] = new_node;
      i++;
      return;
  }
  /* Traverse both left and right by daipayan */
  if(ptr->left)
  compdp_trav(left,ptr,new_node);

  if(ptr->right)
  compdp_trav(right,ptr,new_node);

}
void linklist_dptr(struct node_c** ptr, int count)
{
   int k=0;
  for(k=0; k<count; k++)
  {
   /* fetch from leafnode_ptr  table */
   struct node_c* nd = ptr[k];
   printf("\nlinkedlist traversal!\n");
   /* traverse individual node*/
   while(nd)
   {
      printf("%d\n", nd->data);
      nd = nd->next;
   }
  }
}

int main()
{
    /* Creation of tree structure manually*/
    struct node* first = (struct node*) malloc(sizeof(struct node));
    first->data = 20;

    first->left = (struct node*) malloc(sizeof(struct node));
    first->left->data = 10;

    first->right = (struct node*) malloc(sizeof(struct node));
    first->right->data = 25;

    first->left->left = (struct node*) malloc(sizeof(struct node));
    first->left->left->data = 5;

    first->left->right = (struct node*) malloc(sizeof(struct node));
    first->left->right->data = 15;

    first->right->right = (struct node*) malloc(sizeof(struct node));
    first->right->right->data = 30;
    /* Initalize the leafnode structure */
    leafnode_ptr = (struct node_c**) malloc(sizeof(struct node_c**));
    /* Start the compression by traversal of tree */
    compdp_trav(first,NULL,NULL);

    printf("pointer is:%p %p %p count:%d",leafnode_ptr[0], leafnode_ptr[1], leafnode_ptr[2],i);
    /* print the tree by traversing the linkedlist */
    linklist_dptr(leafnode_ptr,i);
    return 0;
}

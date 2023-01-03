/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// struct ListNode* middleNode(struct ListNode* head){
// }

#include <stdio.h>
#include <stdlib.h>

// node structure
typedef struct Node NODE;
struct Node
{
    int data;
    NODE *next;
};

// create list
NODE *createList(NODE *start)
{

    // get info
    int data = 0;
    printf("Enter -1 to terminate\n");
    printf("Enter data : ");
    scanf("%d", &data);

    // terminating condition
    while (data != -1)
    {

        // create node
        NODE *new = (NODE *)malloc(sizeof(NODE));
        new->data = data;
        new->next = NULL;

        // insert mode
        if (start == NULL) // terminal condition
            start = new;

        else
        {
            NODE *ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = new;
        }

        // get data
        printf("Enter data : ");
        scanf("%d", &data);
    }
    return start;
}

// display list function
void displayList(NODE *start)
{
    while (start != NULL)
    {
        printf("%d->", start->data);
        start = start->next;
    }
    printf("NULL\n");
}

// return miidle of the list (if found two then return the last one)
NODE *middleNode(NODE *start)
{

    NODE *ptr = start;
    int n = 1;

    // count number of nodes
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        n++;
    }

    ptr = start;
    int count = 1;

    // get address of middle element
    while (count != (n / 2) + 1)
    {
        ptr = ptr->next;
        count++;
    }

    return ptr;
}

int main()
{
    NODE *start = NULL;
    start = createList(start);
    displayList(start);
    NODE *ptr = middleNode(start);
    printf("%d\n", ptr->data);
    displayList(ptr);

    return 0;
}

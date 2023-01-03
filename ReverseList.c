#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

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

    while (data != -1)
    {
        // create node
        NODE *new = (NODE *)malloc(sizeof(NODE));
        new->data = data;
        new->next = NULL;

        // add node
        if (start == NULL)
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

// display list
void displayList(NODE *start)
{
    NODE *ptr = start;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// reverse list
NODE *reverseList(NODE *start)
{
    NODE *ptr = start;

    // terminal condition
    if (start == NULL)
        return start;

    else
    {

        NODE *ptr1 = ptr->next;
        if (ptr1 != NULL)
            start->next = ptr1->next;

        // traverse list until ptr2 gets NULL
        while (start->next != NULL)
        {
            ptr1->next = ptr;
            ptr = ptr1;
            ptr1 = start->next;
            start->next = start->next->next;
        }

        // reverse last node
        if (ptr1 != NULL)
        {
            ptr1->next = ptr;
            ptr = ptr1;
        }
    }
    return ptr;
}

int main()
{
    NODE *start = NULL;
    start = createList(start);  // create list
    displayList(start);         // display list
    start = reverseList(start); // get head of reversed list
    displayList(start);         // display reversed list

    return 0;
}
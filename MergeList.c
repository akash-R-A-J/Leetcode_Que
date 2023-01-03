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

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{

    NODE *start = (NODE *)malloc(sizeof(NODE));
    if (list1 == NULL)
        return list2;

    else if (list2 == NULL)
        return list1;

    else
    {
        NODE *ptr1 = list1;
        NODE *ptr2 = list2;
        NODE *ptr = start;

        while (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1->data == ptr2->data)
            {
                ptr->next = ptr1;
                ptr1 = ptr1->next;
                ptr = ptr->next;

                ptr->next = ptr2;
                ptr2 = ptr2->next;
                ptr = ptr->next;
            }
            else if (ptr1->data < ptr2->data)
            {
                ptr->next = ptr1;
                ptr = ptr->next;
                ptr1 = ptr1->next;
            }
            else if (ptr2->data < ptr1->data)
            {
                ptr->next = ptr2;
                ptr = ptr->next;
                ptr2 = ptr2->next;
            }
        }

        if (ptr1 == NULL)
        {
            while (ptr2 != NULL)
            {
                ptr->next = ptr2;
                ptr = ptr->next;
                ptr2 = ptr2->next;
            }
        }
        else
        {
            while (ptr1 != NULL)
            {
                ptr->next = ptr1;
                ptr = ptr->next;
                ptr1 = ptr1->next;
            }
        }
    }

    start = start->next;

    return start;
}

int main()
{
    // list 1
    NODE *list1 = NULL;
    list1 = createList(list1);
    displayList(list1);

    // list 2
    NODE *list2 = NULL;
    list2 = createList(list2);
    displayList(list2);

    // merged list
    NODE *list = NULL;
    list = mergeTwoLists(list1, list2);
    printf("OUTPUT\n");
    displayList(list);

    return 0;
}
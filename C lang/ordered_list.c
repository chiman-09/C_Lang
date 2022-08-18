#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int ele;
    struct node *link;
} node_t;

typedef struct mylist_t
{
    struct node *head;
} mylist_t;

void initialize(mylist_t *mlist);

void display(mylist_t *mlist);

void insert(mylist_t *mlist, int ele);

void free_list(mylist_t *mlist);

void remove_key(mylist_t *mlist, int key);

int main()
{
    mylist_t mlist; // structure variable
    initialize(&mlist);
    printf("do u want to insert elements to nodes in the list?");
    char c = getchar();
    fflush(stdin);
    while (c == 'y')
    {
        printf("enter the element to be inserted to the nodes in the list\n");
        int ele;
        scanf("%d", &ele);
        fflush(stdin);
        insert(&mlist, ele);
        printf("do u want to insert more elements?");
        c = getchar();
        fflush(stdin);
    }
    display(&mlist);
    printf("do u want to delete elements to nodes in the list?");
    char d = getchar();
    fflush(stdin);
    while (d == 'y')
    {
        printf("enter the element to be deleted from the list\n");
        int key;
        scanf("%d", &key);
        fflush(stdin);
        remove_key(&mlist, key);
        printf("do u want to delete more elements?\n");
        d = getchar();
        fflush(stdin);
    }

    display(&mlist);
    free_list(&mlist);
    mlist.head = NULL;
    return 0;
}

void initialize(mylist_t *mlist)
{
    mlist->head = NULL;
}

void display(mylist_t *mlist)
{
    node_t *present = mlist->head;
    if (mlist->head == NULL)
    {
        printf("There are no nodes to display");
    }
    else
    {
        while (present != NULL)
        {
            printf("%d\t", present->ele);
            present = present->link;
        }
    }
}

void insert(mylist_t *mlist, int ele)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->ele = ele;
    temp->link = NULL;
    if (mlist->head == NULL)
    { // no nodes
        mlist->head = temp;
    }
    else
    {
        int max = 0;
        node_t *present = mlist->head;
        node_t *previous = NULL;
        while (present != NULL && present->ele < ele) // Traversal
        {
            previous = present;
            present = present->link;
        }
        if (previous == NULL)
        {
            temp->link = present;
            mlist->head = temp;
        }
        else
        {
            temp->link = present;
            previous->link = temp;
        }
    }
}

void free_list(mylist_t *mlist)
{
    if (mlist->head == NULL)
    {
        printf("No nodes to delete");
    }
    else
    {
        node_t *p = mlist->head;
        node_t *d;
        while (p != NULL)
        {
            d = p;
            printf("node to be deleted has element: %d\n", d->ele);
            p = p->link;
            free(d);
        }
    }
}

void remove_key(mylist_t *mlist, int ele)
{
    node_t *present = mlist->head;
    node_t *previous = NULL;
    int flag = 1;
    if (mlist->head == NULL)
    {
        printf("No elemnts in the linked list");
    }
    else
    {
        while (present != NULL && flag)
        {
            if (present->ele == ele)
            {
                previous->link = present->link;
                printf("Key: %d  found deleting\n", present->ele);
                free(present);
                flag = 0;
            }
            else
            {
                previous = present;
                present = present->link;
            }
        }
        if (present == NULL)
        {
            printf("Key does not exist in the list");
        }
    }
}

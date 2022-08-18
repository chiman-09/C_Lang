#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct component
{
    int info;
    int priority;
} COMPO;

typedef struct node
{
    struct component c;
    struct node *link;
} NODE;

typedef struct priorityQ
{
    struct node *head;
} Q;

void initialize(Q *);

void enqueue(Q *pqueue, COMPO *cp)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->c = *cp;
    if (pqueue->head == NULL)
    {
        pqueue->head = temp;
        temp->link = NULL;
    }
    else
    {
        NODE *present = pqueue->head;
        temp->link = present;
        pqueue->head = temp;
        present = pqueue->head;
    }
}

void dequeue(Q *pqueue)
{
    NODE *temp;
    int max = 0;
    NODE* present = pqueue->head;
    NODE* previous = NULL;
    NODE* prev_max;
    while(present->link != NULL){
        if(present->c.priority>max){
            prev_max = previous;
            previous = present;
            present = present->link;
        }
    }

}

void display()
{
}

int main()
{
    int choice;
    scanf("%d", &choice);
    fflush(stdin);
    Q *head;
    COMPO compo;
    initialize(head);
    do
    {
        switch (choice)
        {
        case 1:
            scanf("%d%d", compo.info, compo.priority);
            fflush(stdin);
            enqueue(head, &compo);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }
        scanf("%d", &choice);
    } while (choice != 4);
    return 0;
}

void initialize(Q *queue)
{
    queue->head = NULL;
}
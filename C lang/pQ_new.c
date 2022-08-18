#include <stdio.h>
#include <stdlib.h>

typedef struct component
{
    int info;
    int priority;
} COMPO;

typedef struct node
{
    COMPO compo;
    struct node *link;
} NODE;

typedef struct priority_Q
{
    NODE *head;
} p_Q;

void initialize(p_Q *);
void enqueu(p_Q *, COMPO *);
void dequeu(p_Q *);
void display(p_Q *);

int main()
{
    p_Q pq;
    COMPO compo;
    initialize(&pq);
    int choice;
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
        case 1:
            scanf("%d %d", &(compo.info), &(compo.priority));
            enqueu(&pq, &compo);
            break;
        case 2:
            dequeu(&pq);
            break;
        case 3:
            display(&pq);
            break;
        default:
            printf("EXIT");
        }
        scanf("%d", &choice);
    } while (choice < 4);

    return 0;
}

void initialize(p_Q *pq)
{
    pq->head = NULL;
}

void enqueu(p_Q *pq, COMPO *compo)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->compo = *compo;
    temp->link = pq->head;
    pq->head = temp;
}

void dequeu(p_Q *pq)
{
    if (pq->head == NULL)
    {
        printf("No Elements");
    }
    else
    {
        NODE *present = pq->head;
        NODE *previous = NULL;
        NODE *prev_max = NULL;
        int max = 0;
        COMPO c;
        NODE *temp;
        while (present != NULL)
        {
            if (present->compo.priority >= max)
            {
                max = present->compo.priority;
                prev_max = previous;
            }
            previous = present;
            present = present->link;
        }

        if (prev_max->link == NULL)
        {
            temp = pq->head;
            pq->head = temp->link;
            c.info = temp->compo.info;
            free(temp);
        }
        else
        {
            temp = prev_max->link;
            c.info = temp->compo.info;
            prev_max->link = temp->link;
            free(temp);
        }
        printf("deleted %d", c.info);
    }
}

void display(p_Q *pq)
{
    if (pq->head == NULL)
    {
        printf("No Elements");
    }
    else
    {
        NODE *p = pq->head;
        while (p != NULL)
        {
            printf("%d %d", p->compo.info, p->compo.priority);
            p = p->link;
        }
    }
}
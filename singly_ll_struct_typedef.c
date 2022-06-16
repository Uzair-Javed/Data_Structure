#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int value;
    Node* next;
};

void print(Node* list);

int main()
{
    Node* n1 = malloc(sizeof *n1);
    Node* n2 = malloc(sizeof *n2);

    n1->value = 100;
    n1->next = n2;
    n2->value = 200;
    n2->next = n3;
    n3->value = 300;
    n3->next = n4;
    n4->value = 400;
    n4->next = n5;
    n5->value = 500;
    n5->next = NULL;

    print(n1);
    return 0;
}

void print(Node* list)
{
    Node* p;
    p = list;
    while (p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
}

/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  School of Computer Science
 *  at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

/* 필요한 헤더파일 추가 if necessary */

typedef struct Node
{
    int key;
    struct Node *llink;
    struct Node *rlink;
} listNode;

typedef struct Head
{
    struct Node *first;
} headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음 */
int initialize(headNode **h);

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해할 것
        - 이중 포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode *h);

int insertNode(headNode *h, int key);
int insertLast(headNode *h, int key);
int insertFirst(headNode *h, int key);
int deleteNode(headNode *h, int key);
int deleteLast(headNode *h);
int deleteFirst(headNode *h);
int invertList(headNode *h);

void printList(headNode *h);

int main()
{
    char command;
    int key;
    headNode *headnode = NULL;

    do
    {
        printf("----------------------------------------------------------------\n");
        printf("                     Doubly Linked  List                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize    = z           Print         = p \n");
        printf(" Insert Node   = i           Delete Node   = d \n");
        printf(" Insert Last   = n           Delete Last   = e\n");
        printf(" Insert First  = f           Delete First  = t\n");
        printf(" Invert List   = r           Quit          = q\n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch (command)
        {
        case 'z':
        case 'Z':
            initialize(&headnode);
            break;
        case 'p':
        case 'P':
            printList(headnode);
            break;
        case 'i':
        case 'I':
            printf("Your Key = ");
            scanf("%d", &key);
            insertNode(headnode, key);
            break;
        case 'd':
        case 'D':
            printf("Your Key = ");
            scanf("%d", &key);
            deleteNode(headnode, key);
            break;
        case 'n':
        case 'N':
            printf("Your Key = ");
            scanf("%d", &key);
            insertLast(headnode, key);
            break;
        case 'e':
        case 'E':
            deleteLast(headnode);
            break;
        case 'f':
        case 'F':
            printf("Your Key = ");
            scanf("%d", &key);
            insertFirst(headnode, key);
            break;
        case 't':
        case 'T':
            deleteFirst(headnode);
            break;
        case 'r':
        case 'R':
            invertList(headnode);
            break;
        case 'q':
        case 'Q':
            freeList(headnode);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while (command != 'q' && command != 'Q');

    return 1;
}

int initialize(headNode **h)
{

    return 1;
}

int freeList(headNode *h)
{
    return 0;
}

void printList(headNode *h)
{
    int i = 0;
    listNode *p;

    printf("\n---PRINT\n");

    if (h == NULL)
    {
        printf("Nothing to print....\n");
        return;
    }

    p = h->first;

    while (p != NULL)
    {
        printf("[ [%d]=%d ] ", i, p->key);
        p = p->rlink;
        i++;
    }

    printf("  items = %d\n", i);
}

/**
 * list에 key를 마지막에 삽입
 */
int insertLast(headNode *h, int key)
{

    return 0;
}

/**
 * list의 마지막 노드를 삭제
 */
int deleteLast(headNode *h)
{

    return 0;
}

/**
 * list 의 첫번째에 key를 삽입
 */
int insertFirst(headNode *h, int key)
{
    return 0;
}

/**
 * list의 첫 번째를 삭제
 */
int deleteFirst(headNode *h)
{

    return 0;
}

/**
 * 리스트의 순서를 반대로 함
 */
int invertList(headNode *h)
{

    return 0;
}

/* 由ъ뒪�몃� 寃��됲븯��, �낅젰諛쏆� key蹂대떎 �곌컪�� �섏삤�� �몃뱶 諛붾줈 �욎뿉 �쎌엯 */
int insertNode(headNode *h, int key)
{

    return 0;
}

/**
 * list에서 key를 가지는 노드를 삭제
 */
int deleteNode(headNode *h, int key)
{

    return 1;
}

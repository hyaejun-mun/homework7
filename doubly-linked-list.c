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

typedef struct Node // 좌우 노드를 가리키도록 설정 -> 양방향 접근 가능.
{
    int key;
    struct Node *llink;
    struct Node *rlink;
} listNode;

typedef struct Head // 리스트의 시작을 의미함.
{
    struct Node *first;
} headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음 */
int initialize(headNode **h); // 이중포인터인 이유:

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
    if (*h != NULL) // 새로 시작해야 하므로, 비어 있지 않으면 비워 주어야 함.
        freelist(*h);
    // 'h가 가리키는 곳'에 동적 할당함.
    *h = (headNode *)malloc(sizeof(headNode));
    (*h)->first = NULL;
    return 1;
}

int freeList(headNode *h)   // 동적할당된 부분은 h가 가리키는 곳이므로
{                           // h가 가리키는 곳까지만 와도 모두 해제 가능함.
    listNode *p = h->first; // 먼저 동적할당된 노드들부터 할당 해제해 주어야 함.
    listNode *prev = NULL;
    while (p != NULL) // 현재 p는 첫 번째 원소를 가리키는 중.
    {
        prev = p;
        p = p->link;
        free(prev); // 하나씩 지나가면서 해제해줌.
    }
    free(h); // h도 동적할당되었으므로, 해제해줌.
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
    // key를 가지는 노드를 동적할당한다.
    listNode *input = (listNode *)malloc(sizeof(listNode));
    input->key = key;
    input->rlink = NULL;
    input->llink = NULL;
    // h가 비어 있으면, 그냥 앞에 추가한다.
    if (h->first == NULL)
    {
        h->first = input;
        return 0;
    }
    // 마지막으로 이동하여, 서로 연결해준다.
    listNode *p = h->first;
    while (p->rlink != NULL)
    {
        p = p->rlink;
    }
    p->rlink = input;
    input->llink = p;
    return 0;
}

/**
 * list의 마지막 노드를 삭제
 */
int deleteLast(headNode *h)
{
    // 리스트가 이미 비어 있으면, 실행할 수 없다.
    if (*h == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }
    listNode *p = h->first;
    listNode *prev = NULL;
    // 리스트에 노드가 하나만 있으면, 그것을 삭제한다.
    if (p->rlink == NULL)
    {
        h->first = NULL;
        free(p);
        return 0;
    }
    // 리스트의 끝 노드까지 이동한 후, 할당 해제해 준다.
    while (p->rlink != NULL)
    {
        prev = p;
        p = p->rlink;
    }
    prev->rlink = NULL;
    free(p);
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

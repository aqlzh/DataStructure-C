#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#define LENGTH(a)  (sizeof(a)/sizeof(a[0]))   

typedef struct _ENode   //±ß
{
    int ivex;
    struct _ENode* next_edge;
}ENode, * PENode;

typedef struct _VNode  // µã
{
    char data;
    ENode* first_edge;
}VNode;

typedef struct _LGraph
{
    int vexnum;
    int edgnum;
    VNode vexs[MAX];
}LGraph;

int get_position(LGraph g, char ch)
{
    int i;
    for (i = 0; i < g.vexnum; i++)
        if (g.vexs[i].data == ch)
            return i;
    return -1;
}

void link_last(ENode* list, ENode* node)
{
    ENode* p = list;
    while (p->next_edge)
        p = p->next_edge;
    p->next_edge = node;
}

LGraph* create_example_lgraph()
{
    char c1, c2;
    char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    char edges[][2] = {
    {'A', 'B'},
    {'B', 'C'},
    {'B', 'E'},
    {'B', 'F'},
    {'C', 'E'},
    {'D', 'C'},
    {'E', 'B'},
    {'E', 'D'},
    {'F', 'G'} };
    int vlen = LENGTH(vexs);
    int elen = LENGTH(edges);
    int i, p1, p2;
    ENode* node1, * node2;
    LGraph* pG;
    if ((pG = (LGraph*)malloc(sizeof(LGraph))) == NULL)
        return NULL;
    memset(pG, 0, sizeof(LGraph));

    pG->vexnum = vlen;
    pG->edgnum = elen;
    for (i = 0; i < pG->vexnum; i++)
    {
        pG->vexs[i].data = vexs[i];
        pG->vexs[i].first_edge = NULL;
    }

    for (i = 0; i < pG->edgnum; i++)
    {
        c1 = edges[i][0];
        c2 = edges[i][1];
        p1 = get_position(*pG, c1);
        p2 = get_position(*pG, c2);

        node1 = (ENode*)calloc(1, sizeof(ENode));
        node1->ivex = p2;
        if (pG->vexs[p1].first_edge == NULL)
            pG->vexs[p1].first_edge = node1;
        else
            link_last(pG->vexs[p1].first_edge, node1);
        node2 = (ENode*)calloc(1, sizeof(ENode));
        node2->ivex = p1;
        if (pG->vexs[p2].first_edge == NULL)
            pG->vexs[p2].first_edge = node2;
        else
            link_last(pG->vexs[p2].first_edge, node2);
    }
    return pG;
}

void DFS(LGraph G, int i, int* visited)
{
    ENode* node;
    visited[i] = 1;
    printf("%2c", G.vexs[i].data);
    node = G.vexs[i].first_edge;
    while (node != NULL)
    {
        if (!visited[node->ivex])
            DFS(G, node->ivex, visited);
        node = node->next_edge;
    }
}

void DFSTraverse(LGraph G)
{
    int i;
    int visited[MAX];
    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    for (i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
            DFS(G, i, visited);
    }
    printf("\n");
}

void BFS(LGraph G)
{
    int head = 0;
    int rear = 0;
    int queue[MAX];
    int visited[MAX];
    int i, j, k;
    ENode* node;

    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    for (i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            printf("%2c", G.vexs[i].data);
            queue[rear++] = i;
        }
        while (head != rear)
        {
            j = queue[head++];
            node = G.vexs[j].first_edge;
            while (node != NULL)
            {
                k = node->ivex;
                if (!visited[k])
                {
                    visited[k] = 1;
                    printf("%2c", G.vexs[k].data);
                    queue[rear++] = k;
                }
                node = node->next_edge;
            }
        }
    }
    printf("\n");
}

int main()
{
    LGraph* pG;
    pG = create_example_lgraph();
    DFSTraverse(*pG);
    BFS(*pG);
    return 0;
}

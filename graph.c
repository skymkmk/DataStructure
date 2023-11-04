#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

VNode *newVertices(const int length, const int data[]) {
    VNode * newVertice = (VNode *)malloc(sizeof(VNode) * length);
    for (int i = 0; i < length; i++) {
        newVertice[i].data = data[i];
        newVertice[i].first = NULL;
    }
    return newVertice;
}

void setEdge(VNode *const vertices, const int vertice, const int adjvex) {
    ENode* node = (ENode*)malloc(sizeof(ENode));
    node->adjvex = adjvex;
    node->next = NULL;
    if (vertices[vertice].first == NULL) vertices[vertice].first = node;
    else {
        ENode* p = vertices[vertice].first;
        while (p->next != NULL) p = p-> next;
        p->next = node;
    }
}

graph generateGraphFromFile(const char filename[]) {
    FILE* fp = fopen(filename, "r");
    int length;
    fscanf(fp, "%d", &length);
    int *data = (int*)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) fscanf(fp, "%d", &data[i]);
    VNode * vertices = newVertices(length, data);
    int adjvex;
    char c;
    for (int i = 0; i < length; i++) {
        while (1) {
            fscanf(fp, "%d", &adjvex);
            setEdge(vertices, i, adjvex - 1); // Use adjvex - 1 to adapt the array starting from 0
            c = fgetc(fp);
            if (c == '\n' || c == EOF) break;
        }
    }
    fclose(fp);
    graph freshGraph;
    freshGraph.length = length;
    freshGraph.vertices = vertices;
    return freshGraph;
}

void printGraph (const graph theGrpah) {
    for (int i = 0; i < theGrpah.length; i++) {
        printf("%d ", theGrpah.vertices[i].data);
        if (theGrpah.vertices[i].first == NULL) printf("\n");
        else {
            ENode* p = theGrpah.vertices[i].first;
            do {
                printf("-> %d ", p->adjvex + 1);
                p = p->next;
            } while (p != NULL);
        }
        printf("\n");
    }
}
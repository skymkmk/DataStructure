#include "dijkstra.h"
#include "stack.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void updateDist(int *const dist, const int *const S, const int SLength, const graph theGraph, int *const path, const pair cumWeight) {
    ENode *p = theGraph.vertices[S[SLength - 1]].first;
    while (p != NULL) {
        int flag = 1;
        for (int i = 0; i < SLength; i++) {
            if (S[i] == p->adjvex) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            if (dist[p->adjvex] > cumWeight.value + p->weight) {
                dist[p->adjvex] = cumWeight.value + p->weight;
                path[p->adjvex] = cumWeight.index;
            }
        }
        p = p->next;
    }
}

// 注意 sorce 下标都是从 0 开始的
dijkstraResult dijkstra(const graph theGraph, const int source) {
    dijkstraResult result;
    result.length = theGraph.length;
    result.path = (int*)malloc(sizeof(int) * result.length);
    for (int i = 0; i < result.length; i++) result.path[i] = -1;
    int *S = (int*)malloc(sizeof(int) * theGraph.length);
    int *dist = (int*)malloc(sizeof(int) * theGraph.length);
    for (int i = 0; i < result.length; i++) dist[i] = INT_MAX;
    pair cumWeight;
    cumWeight.index = source;
    cumWeight.value = 0;
    // 进行 path 求解
    for (int i = 1; i < theGraph.length; i++) {
        // 初始化 dist
        updateDist(dist, S, i, theGraph, result.path, cumWeight);
        pair theMin = minArray(dist, result.length);
        S[i] = theMin.index;
        cumWeight.index = theMin.index;
        cumWeight.value = theMin.value;
        dist[theMin.index] = INT_MAX;
    }
    return result;
}

void printShortestPath(const dijkstraResult result, const graph theGraph, const int source, const int target) {
    LStack stack = newStack(target);
    while (stack->data != source) {
        if (result.path[stack->data] != -1) push(&stack, result.path[stack->data]);
        else {
            printf("找不到路径！");
            return;
        }
    }
    int psrc = pop(&stack), pdst;
    printf("%d", psrc + 1);
    while (stack != NULL) {
        pdst = pop(&stack);
        printf(" --%d-> %d", findWeight(theGraph, psrc, pdst), pdst + 1);
        psrc = pdst;
    }
    printf("\n");
}
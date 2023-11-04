#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "graph.h"

typedef struct dijkstraResult {
    int length;
    int *path;
} dijkstraResult;

dijkstraResult dijkstra(const graph theGraph, const int source);
LStack shortestPath(const graph theGraph, const dijkstraResult result, const int source, const int target);
void printShortestPath(const dijkstraResult result, const graph theGraph, const int source, const int target);
#endif
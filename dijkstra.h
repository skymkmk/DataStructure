#include "graph.h"

typedef struct dijkstraResult {
    int length;
    int *path;
} dijkstraResult;

dijkstraResult dijkstra(const graph theGraph, const int source);
void printShortestPath(const dijkstraResult result, const graph theGraph, const int source, const int target);
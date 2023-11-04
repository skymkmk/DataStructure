#include "dijkstra.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

pair getEccentricity(const graph theGraph, const int vertice) {
    int *pathLength = (int*)malloc(sizeof(int) * theGraph.length);
    dijkstraResult result = dijkstra(theGraph, vertice);
    for (int i = 0; i < theGraph.length; i++) {
        if (i == vertice) pathLength[i] = -1;
        else pathLength[i] = getShortestLength(theGraph, result, vertice, i);
    }
    return maxArray(pathLength, theGraph.length);
}

int getCenter(const graph theGraph) {
    pair *eccentricities = (pair*)malloc(sizeof(pair) * theGraph.length);
    pair maxEccentricity;
    maxEccentricity.index = -1;
    maxEccentricity.value = INT_MAX;
    for (int i = 0; i < theGraph.length; i++) {
        pair eccentricity = getEccentricity(theGraph, i);
        if (eccentricity.value == -1) eccentricities[i] = maxEccentricity;
        else eccentricities[i] = eccentricity;
    }
    return minPairs(eccentricities, theGraph.length).index;
}
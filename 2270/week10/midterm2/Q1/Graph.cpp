#include "Graph.hpp"
#include <vector>
using namespace std;

/*
 * adds a vertex to the graph
 */
void Graph::addVertex(int n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->key = n;
        vertices.push_back(v);
    }
}

/*
 * adds an edge between two vertices (directed graph)
 */
void Graph::addEdge(int src, int dest){
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->key == src) {
            for(int j = 0; j < vertices.size(); j++) {
                if(vertices[j]->key == dest && i != j) {
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

void isVertexABossHelper(vertex *vert){
    if(vert->visited){
        return;
    }
    vert->visited = true;
    for(int i = 0; i < vert->adj.size(); i++){
        if(!vert->adj.at(i).v->visited){
            isVertexABossHelper(vert->adj.at(i).v);
        }
    }
}

void undoIsVertexABossHelper(vertex *vert){
    if(!vert->visited){
        return;
    }
    vert->visited = false;
    for(int i = 0; i < vert->adj.size(); i++){
        if(vert->adj.at(i).v->visited){
            undoIsVertexABossHelper(vert->adj.at(i).v);
        }
    }
}

/*
 * Complete the following function which checks if vert is a boss vertex
 */
bool Graph::isVertexABoss(vertex *vert) {
    isVertexABossHelper(vert);
    for(int i = 0; i < vertices.size(); i++){
        if(!vertices.at(i)->visited){
            undoIsVertexABossHelper(vert);
            return false;
        }
    }
    return true;
}

/*
 * Complete the following function which checks if the graph is a Boss
 */
bool Graph::isGraphABoss() {
    for(int i = 0; i < vertices.size(); i++){
        if(isVertexABoss(vertices.at(i))){
            return true;
        }
    }
    return false;
}

#include "Graph.hpp"
#include <iostream>

using namespace std;

void Graph::addEdge(string v1, string v2){
    vertex* vert1;
    vertex* vert2;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices.at(i)->name == v1){
            vert1 = vertices.at(i);
        }
        if(vertices.at(i)->name == v2){
            vert2 = vertices.at(i);
        }
    }
    adjVertex vert1adj;
    vert1adj.v = vert1;
    adjVertex vert2adj;
    vert2adj.v = vert2;
    vert1->adj.push_back(vert2adj);
    vert2->adj.push_back(vert1adj);
}
void Graph::addVertex(string name){
    vertex* newboi = new vertex;
    newboi->name = name;
    vertices.push_back(newboi);
}
void Graph::displayEdges(){
    for(int i = 0; i < vertices.size(); i++){
        cout << vertices.at(i)->name << " -->";
        for(int j = 0; j < vertices.at(i)->adj.size(); j++){
            cout << " " << vertices.at(i)->adj.at(j).v->name;
        }
        cout << endl;
    }
}
void Graph::breadthFirstTraverse(string sourceVertex){
    vertex* vStart;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices.at(i)->name == sourceVertex){
            vStart = vertices.at(i);
            break;
        }
    }
    vector<vertex*> queue;
    queue.push_back(vStart);
    cout<< "Starting vertex (root): " << vStart->name << "->";
    vStart->visited = true;
    int maxStops = 1;
    for(int iter = 0; iter < maxStops; iter++){
        for(int i = 0; i < queue[iter]->adj.size(); i++){
            if(!queue[iter]->adj[i].v->visited){
                queue.push_back(queue.at(iter)->adj.at(i).v);
                queue[iter]->adj[i].v->distance = queue.at(iter)->distance + 1;
                maxStops++;
            }
        }
        queue[iter]->visited = true;
        if(!(queue[iter]->name == sourceVertex)){
            cout <<" "<<queue[iter]->name<<"("<<queue[iter]->distance<<")";
        }
    }
}
void touchConnectedComponents(vertex* vStart){
    vector<vertex*> queue;
    queue.push_back(vStart);
    vStart->visited = true;
    int maxStops = 1;
    for(int iter = 0; iter < maxStops; iter++){
        for(int i = 0; i < queue[iter]->adj.size(); i++){
            if(!queue[iter]->adj[i].v->visited){
                queue.push_back(queue.at(iter)->adj.at(i).v);
                maxStops++;
            }
        }
        queue[iter]->visited = true;
    }
}
int Graph::getConnectedBuildings(){
    int numBuildings = 0;
    for(int i = 0; i < vertices.size(); i++){
        if(!vertices[i]->visited){
            touchConnectedComponents(vertices[i]);
            numBuildings++;
        }
    }
    return numBuildings;
}
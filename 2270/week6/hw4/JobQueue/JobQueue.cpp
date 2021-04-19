#include <iostream>
#include "JobQueue.hpp"

using namespace std;

JobQueue::JobQueue(){
    queueFront = 0;
    queueEnd = 0;
    counter = 0;
}
bool JobQueue::isEmpty(){
    if(counter == 0){
        return true;
    }
    return false;
}
bool JobQueue::isFull(){
    if(counter == 20){
        return true;
    }
    return false;
}
void JobQueue::enqueue(std::string job){
    if(!isFull()){
        queue[queueEnd] = job;
        queueEnd = (queueEnd + 1) % 20;
        counter++;
    }
    else{
        cout << "Queue full, cannot add new job" << endl;
    }
}
void JobQueue::dequeue(){
    if(!isEmpty()){
        queueFront = (queueFront + 1) % 20;
        counter--;
    }
    else{
        cout << "Queue empty, cannot dequeue a job" << endl; 
    }
}
std::string JobQueue::peek(){
    if(!isEmpty()){
        return queue[queueFront];
    }
    else{
        cout << "Queue empty, cannot peek" << endl;
        return "";
    }
}
int JobQueue::queueSize(){
    return counter;
}
#include<iostream>
using namespace std;

#define MAXSIZE 5

typedef struct CircularQueue {
    int front;
    int rear;
    int data[MAXSIZE];
} CircularQueue;

bool QueueInit(CircularQueue &cq) {
    cq.front = 0;
    cq.rear = 0;
    return true;
}

bool IsFull(CircularQueue cq) {
    if ((cq.rear+1)%MAXSIZE ==cq.front) {
        return true;
    }
    return false;
}

bool IsEmpty(CircularQueue cq) {
    if (cq.front == cq.rear) {
        return true;
    }
    return false;
}

bool EnQueue(CircularQueue &cq,int x) {
    if(IsFull(cq)) {
        return false;
    }
    cq.data[cq.rear] = x;
    cq.rear = (cq.rear+1)%MAXSIZE;
    return true;
}

bool DeQueue(CircularQueue &cq,int &x) {
    if(IsEmpty(cq)) {
        return false;
    }
    x = cq.data[cq.front];
    cq.front = (cq.front+1)%MAXSIZE;
    return true;
}

bool QueueGetFront(CircularQueue cq,int &x) {
    if(IsEmpty(cq)) {
        return false;
    }
    x = cq.data[cq.front];
    cq.front = (cq.front+1)%MAXSIZE;
    cq.front = (cq.front+1)%MAXSIZE;
    return true;
}

bool ClearQueue(CircularQueue &cq) {
    cq.front = 0;
    cq.rear = 0;
    return true;
}

int main() {
    CircularQueue cq;
    QueueInit(cq);
    EnQueue(cq,1);
    EnQueue(cq,2);
    EnQueue(cq,3);
    int x = 0;
    DeQueue(cq,x);
    DeQueue(cq,x);
    EnQueue(cq,4);
    EnQueue(cq,5);
    EnQueue(cq,6);
    int i = cq.front;
    while(i != cq.rear) {
        cout <<cq.data[i]<<" ";
        i = (i+1)%MAXSIZE;
    }
    return 0;
}



#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkQueue {
    Node *front;
    Node *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
    Q.front = nullptr;
    Q.rear = nullptr;
}

bool IsEmpty(LinkQueue Q) {
   return Q.front == nullptr;
}

bool EnQueue(LinkQueue &Q,int x) {
   Node *p = new Node;
   p->data = x;
   p->next = nullptr;
   if(IsEmpty(Q)) {
       Q.front = p;
       Q.rear = p;
   }
   else {
       Q.rear->next = p;
       Q.rear = p;
   }
   return true;
}

bool DeQueue(LinkQueue &Q,int &x) {
    if(IsEmpty(Q)) {
        return false;
    }
    x = Q.front->data;
    Node *p = Q.front;
    Q.front = Q.front->next;
    if(Q.front == nullptr) {
        Q.rear = nullptr;
    }
    delete p;
    return true;
}

bool GetFront(LinkQueue Q,int &x) {
    if(IsEmpty(Q)) {
        return false;
    }
    x = Q.front->data;
    return true;
}

void DestroyQueue(LinkQueue &Q) {
    while (Q.front != nullptr) {
        Node *p = Q.front;
        Q.front = Q.front->next;
        delete p;
    }
    Q.rear = nullptr;
}

int main() {
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,1);
    EnQueue(Q,2);
    EnQueue(Q,3);
    int x;
    GetFront(Q,x);
    cout << x << endl;
    DeQueue(Q,x);
    GetFront(Q,x);
    cout << x << endl;
    DeQueue(Q,x);
    DeQueue(Q,x);
    DeQueue(Q,x);
    DestroyQueue(Q);
    return 0;
}

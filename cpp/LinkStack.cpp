#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    Node *next;
} Node, *LinkStack;

void StackInit(LinkStack &L) {
    L = nullptr;
}

bool IsEmpty(LinkStack L) {
    if (L == nullptr) {
        return true;
    }
    return false;
}

bool NodePush(LinkStack &L,int x) {
    Node* p = new Node;
    p->data = x;
    p->next = L;
    L = p;
    return true;
}

bool NodePop(LinkStack &L,int &x) {
    if (IsEmpty(L)) {
        return false;
    }
    Node* p = L;
    x = L->data;
    L = L->next;
    delete p;
    return true;
}

bool StackGetTop(LinkStack L,int &x) {
    if (IsEmpty(L)) {
        return false;
    }
    x = L->data;
    return true;
}

void StackDestroy(LinkStack &L) {
    while (L != nullptr) {
        Node* p = L;
        L = L->next;
        delete p;
    }
}

int main() {
    LinkStack L;
    StackInit(L);
    for(int i = 1;i <= 5;i++) {
        NodePush(L,i);
    }
    int top;
    StackGetTop(L,top);
    cout << "Top element: " << top << endl;
    for(int i = 1;i <= 5;i++) {
        int x;
        NodePop(L,x);
        cout << "本次pop的元素: " << x << endl;
    }
    StackDestroy(L);
    if (IsEmpty(L)) {
        cout << "栈为空" << endl;
    }
    return 0;
}



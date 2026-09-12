#include<iostream>
#include <cstring>
using namespace std;

typedef char ElemType;
typedef struct Node {
    ElemType data;
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

bool NodePush(LinkStack &L,ElemType x) {
    Node* p = new Node;
    p->data = x;
    p->next = L;
    L = p;
    return true;
}

bool NodePop(LinkStack &L,ElemType &x) {
    if (IsEmpty(L)) {
        return false;
    }
    Node* p = L;
    x = L->data;
    L = L->next;
    delete p;
    return true;
}

bool StackGetTop(LinkStack L,ElemType &x) {
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

bool bracketCheck(char str[],int len) {
    LinkStack L;
    StackInit(L);
    for(int i=0;i<len;i++) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            NodePush(L,str[i]);
            continue;
        }
        else {
            if(IsEmpty(L)) {
                return false;
            }
        }
        ElemType s;
        NodePop(L,s);
        if(str[i] == ')' && s != '(') {
            return false;
        }
        if(str[i] == ']' && s != '[') {
            return false;
        }
        if(str[i] == '}' && s != '{') {
            return false;
        }   
    }
    if(!IsEmpty(L)) {
        return false;
    }
    return true;
}

int main() {
    char str1[] = {"{[()]}([{}]){[(])}"};
    char str2[] = {"{[()]}([{}])"};
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    cout<<bracketCheck(str1,len1)<<endl;
    cout<<bracketCheck(str2,len2)<<endl;
    return 0;
}



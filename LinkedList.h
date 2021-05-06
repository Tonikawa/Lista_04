
//  Created by Gabriel Batista Cristiano on 04/05/21.
//

#ifndef LinkedList_h
#define LinkedList_h

struct Node
{
int data;
Node* next;
};

struct LinkedList
{
int count;
Node* head;
Node* tail;
};

LinkedList* Create();

void Insert(LinkedList* list, int n);

void Append(LinkedList* list, int n);

Node* RemoveHead(LinkedList* list);

Node* RemoveTail(LinkedList* list);

Node* RemoveNode(LinkedList* list, int value);

Node* GetNode(Node* n, int value);

Node* GetHead(Node* n);

Node* GetTail(Node* n);

int Count();

bool IsEmpty(LinkedList* list);

void Clear(LinkedList* list);

void DestroyNode(Node* n);

void DestroyList(LinkedList* list);

void Print(LinkedList* list);

#endif /* LinkedList_h */

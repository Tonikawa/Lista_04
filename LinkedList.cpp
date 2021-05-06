
// Gabriel Batista Cristiano TIA: 32090722
// Julia Carvalho de Souza Castro TIA: 32022290

#include <iostream>
#include <clocale>
#include "LinkedList.h"

LinkedList* Create()
{
    //cria/aloca memória para uma nova lista
    LinkedList *list= new LinkedList;
    //tamanho da lista começa com zero
    list->count=0;
     //head começa com valor nulo
    list->head=nullptr;
    //tail começa com valor nulo
    list->tail=nullptr;
    //retorna a nova lista
    return list;
}

void Insert(LinkedList* list, int data)
{
    //cria/aloca novo nó node
    Node* n= new Node;
    //node->data = data
    n->data=data;
    //node é o primeiro nó da lista, então node->next aponta para head (node->next = head)
    n->next = list->head;
    //se lista estiver vazia
    if (list->count==0)
    {
        //tail aponta para node
        list->tail=n;
    }
    //head aponta para node
    list->head=n;
    //aumenta o tamanho da lista
    list->count = list->count+1;
}
void Append(LinkedList* list, int data)
{
    // cria/aloca novo nó node
    Node* n= new Node;
    //node->data = data
    n->data=data;
    //node é o último nó da lista, então node->next é nulo (temp->next = nullptr)
    n->next = nullptr;
    //se lista estiver vazia
    if (list->count==0)
    {
        //head e tail apontam para node
        list->head=n;
        list->tail=n;
    }
    else
    {
    //tail aponta para node
    list->tail = n;
       
    //aumenta o tamanho da lista
    list->count = list->count+1;
    }

}

Node* RemoveHead(LinkedList* list)
{
//    cria nó toRemove que aponta para head
    Node* toRemove = list->head;
//    se existe só um nó na lista (head é igual à tail)
    if  (list->head == list->tail)
        {
//        não há mais nós na lista (head e tail viram nulo)
            list->head=nullptr;
            list->tail=nullptr;
        }
    else
        {
//        head agora aponta para o segundo nó (head->next)
            list->head = list->head->next;
        }
//    diminui tamanho da lista
    list->count = list->count-1;
//    retorna toRemove
    return toRemove;
}

Node* RemoveTail(LinkedList* list)
{
//    se existe só um nó na lista
    if (list->count == 1)
        {
//        remove e retorna nó usando
            return RemoveHead(list);
        }
//    percorre a lista até chegar em tail
    Node* toRemove = list->head;
    Node* previous = nullptr;
    while(toRemove != nullptr)
        {
            previous = toRemove;
            toRemove = toRemove->next;
        }
//    previous->next aponta para nulo
    previous->next = nullptr;
//    tail aponta para penúltimo nó
//    (previous)
    list->tail = previous;
//    diminui tamanho da lista
    list->count = list->count-1;
//    retorna toRemove
    return toRemove;
}

Node* RemoveNode(LinkedList* list, int value)
{
    //cria nó toRemove que começa em head
    Node* toRemove = list->head;
    //cria nó previous que começa como nulo
    Node* previous = nullptr;
    //enquanto toRemove não for nulo e valor de toRemove não é value
    while(toRemove != nullptr && toRemove->data != value)
    {
        //previous aponta para toRemove
        previous->next = toRemove;
        //toRemove aponta para o próximo nó da lista (toRemove->next)
        toRemove = toRemove->next;
    }
    //se toRemove for nulo, retorna nulo
    if (toRemove == nullptr)
    {
        return nullptr;
    }
    //se toRemove for head, remove e retorna nó usando RemoveHead()
    else if (toRemove == list->head)
    {
        return RemoveHead(list);
    }
    //se toRemove for tail, remove e retorna nó usando RemoveTail()
    else if (toRemove == list->tail)
    {
        return RemoveTail(list);
    }
    //senão
    else
    {
    //previous->next aponta para toRemove->next
    previous->next = toRemove->next;
    //diminui tamanho da lista
    list->count = list->count-1;
    //retorna toRemove
    return toRemove;
    }
}

Node* GetNode(LinkedList* list, int value)
{
    //cria nó n que aponta para head
    Node* n = list->head;
    //enquanto não chegou ao fim da lista (node não é nulo)
    while (n!= nullptr)
    {
        //se node tem valor value
        if (n->data==value)
        {
            //retorna node
            return n;
        }
        //node aponta para node->next
        n = n->next;
    }
    //retorna nulo, já que nó com valor value não foi encontrado
    return nullptr;
}

Node* GetHead(LinkedList* list)
{
    //retorna no head
    return list->head;
}
Node* GetTail(LinkedList* list)
{
    //retorna no tail
    return list->tail;
}
int Count(LinkedList* list)
{
    //retorna tamanho da lista
    return list->count;
}
bool IsEmpty(LinkedList* list)
{
    //vazio quando head for igual a nulo e tail for igual a nulo(ou quando tamanho for zero)
    return list->count == 0;
}

void Clear(LinkedList* list)
{
//    cria nó node que começa em head
    Node* n = list->head;
//    cria nó next que começa como nulo
    Node* next = nullptr;
//    enquanto node não for nulo
    while(n != nullptr)
    {
//        next aponta para node->next
        next = n->next;
//        libera memória alocada para node
        delete n;
        n = nullptr;
//        node aponta para next
        n = next;
    }

}

void DestroyNode(Node* n)
{
    delete n;
    n = nullptr;
}

void DestroyList(LinkedList* list)
{
    delete list;
    list = nullptr;
}

void Print(LinkedList* list)
{
    Node* aux = list->head;
    while(aux != nullptr)
    {
        std:: cout << aux->data << " ";
        aux = aux->next;
    }
    delete aux;
    aux = nullptr;
}

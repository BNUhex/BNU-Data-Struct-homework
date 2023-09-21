#include <iostream>



struct SetList
{
    int data;
    SetList* next;
};
SetList* initSetList()
{
    SetList* first=new SetList;
    first->next=NULL;
    return first;
}
void insertbuild(SetList* first)
{
    int n;
    SetList* temp=first->next;
    std::cout<<"Input the set"<<std::endl;
    while (std::cin>>n)
    {
        temp->data=n;
        temp->next=new SetList;
        temp=temp->next;
    }
    temp=NULL;
    
}
int isInside(SetList* first,int x)
{
    SetList* temp=first->next;
    while (temp!=NULL)
    {
        if (temp->data==x)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

void insert(SetList* first,int x)
{
    if (isInside(first,x))
    {
        return;
    }
    SetList* temp=new SetList;
    temp->data=x;
    temp->next=NULL;
    SetList* go=first;
    while (go->next!=NULL)
    {
        go=go->next;
    }
    go->next=temp;
}
void del(SetList* first,int x)
{
    if (!isInside(first,x))
    {
        return;
    }
    SetList* prego=first;
    SetList* go=first->next;
    while (go!=NULL)
    {
        if (go->data==x)
        {
            prego->next=go->next;
            delete go;
            return;
        }
        prego=go;
        go=go->next;
    }
}
void delsame(SetList* first)
{
    SetList* go=first->next;
    while(go!=NULL)
    {
        if(isInside(go->next,go->data))
        {
            del(go,go->data);
        }
        else
        {
            go=go->next;
        }
    }
}
SetList* Union(SetList* A,SetList* B)
{
    SetList* C=initSetList();
    SetList* go=A->next;
    while (go!=NULL)
    {
        insert(C,go->data);
        go=go->next;
    }
    go=B->next;
    while (go!=NULL)
    {
        insert(C,go->data);
        go=go->next;
    }
    return C;
}
SetList* Intersection(SetList* A,SetList* B)
{
    SetList* C=initSetList();
    SetList* go=A->next;
    while (go!=NULL)
    {
        if (isInside(B,go->data))
        {
            insert(C,go->data);
        }
        go=go->next;
    }
    return C;
}
SetList* Difference(SetList* A,SetList* B)
{
    SetList* C=initSetList();
    SetList* go=A->next;
    while (go!=NULL)
    {
        if (!isInside(B,go->data))
        {
            insert(C,go->data);
        }
        go=go->next;
    }
    return C;
}
void printset(SetList* first)
{
    SetList* go=first->next;
    while (go!=NULL)
    {
        std::cout<<go->data<<" ";
        go=go->next;
    }
    std::cout<<std::endl;
}
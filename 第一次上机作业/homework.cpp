#include<iostream>

#include <fstream>
#include <string>
std::string input =R"("")";
std::string output=R"("")";
struct node{
    int data;
    node *next;
};
 struct head{
    int num;
    int data;
    node *next;
};

void creat_table(head first){
    std::ifstream inputFile(input);
    if(!inputFile.is_open()){
        std::cout<<"Error opening file"<<std::endl;
        exit(1);
    }
    int num;
    node *flag;
    first.next=new node;
    flag=first.next;


    while(inputFile>>num){
        first.num++;

        flag->data=num;
        flag->next=new node;
        flag=flag->next;
    }
    delete flag;
}

node* delmin(head first){
    if (first.next==NULL){
        std::cout<<"Error: empty table"<<std::endl;
        return NULL;
    }
   node* prestay=first.next;
   node* stay=first.next;
   node* go=first.next;
   while(go->next!=NULL){
       if(go->next->data<stay->data){
           prestay=go;
           stay=go->next;
       }
       go=go->next;
   }
   if(prestay==stay){//由于头结点和其他节点的数据类型不同，要单独对第一个进行处理
       first.next=stay->next;
       first.num--;
       return stay

   }
    prestay=stay->next;
    first.num--;
    return stay;

}
node* deli(head first,int i){
    if(i>first.num||i<1){
        std::cout<<"Error: i is invalid"<<std::endl;
        return NULL;
    }
    if (i==1){
        node* temp=first.next;
        first.next=first.next->next;
        first.num--;
        return temp;
    }
    node* prego=first.next;
    node*go=prego->next;
    i--;
    while(--i){
        prego=go;
        go=go->next;
    }
    prego->next=go->next;
    first.num--;
    return go;

}
node* inserti(head first,int i,int data){
    if(i>first.num||i<1){
        std::cout<<"Error: i is invalid"<<std::endl;
        return NULL;
    }
    node* temp=new node;
    temp->data=data;
    if(i==1){
        temp->next=first.next;
        first.next=temp;
        first.num++;
        return temp;
    }
    node* go=first.next;
    i=i-2;
    while(i--){
        go=go->next;
    }
    temp->next=go->next;
    go->next=temp;
    first.num++;
    return temp;
}
void delx(head first,int x){
    if (first.next->data==x){
        node* temp=first.next;
        first.next=first.next->next;
        delete temp;
        first.num--;
        return;
    }
    
    node* prego=first.next;
    node* go=prego->next;
    while(go!=NULL){
        if(go->data==x){
            prego->next=go->next;
            delete go;
            go=prego->next;
            first.num--;
        }
        else{
            prego=go;
            go=go->next;
        }
}}
void delst(head &first,int s,int t){
    if(s>=t||first.next==NULL){
        std::cout<<"Error: s>=t or empty list"<<std::endl;
        return;
    }
    go=first.next;
    for(int i=1;i<=first.num;i++){
        if(go->data>s&&go->data<t){
            node* temp=go;
            go=go->next;
            deli(first,i);
        }
        else{
            go=go->next;
        }    
    }
}

#include<iostream>

// #include <fstream>
#include <string>
// std::string input =R"("")";
// std::string output=R"("")";
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
    first.next=NULL;
    first.num=0;
    int num;
    node* go=first.next;

    while(std::cin>>num){
        go->data=num;
        go=go->next;
        first.num++;
    }
    go->next=NULL;
    // std::ifstream inputFile(input);
    // if(!inputFile.is_open()){
    //     std::cout<<"Error opening file"<<std::endl;
    //     exit(1);
    // }
//     int num;
//     node *flag;
//     first.next=new node;
//     flag=first.next;    node* go=first.next;
//     while(go->next!=NULL){
//         go=go->next;
//     }
//     go->next=second.next;
//     first.num+=second.num;
//     delete second.next;
// }


//     while(inputFile>>num){
//         first.num++;

//         flag->data=num;
//         flag->next=new node;
//         flag=flag->next;
//     }
//     delete flag;
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
       return stay;

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
    node* go=first.next;
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
void dels2t(head &first,int s,int t){
    delst(first,s,t);
}
head mergelist(head &first,head second){
    node* gofirst;
    node* gosecond;
    head combine;
    node* gocombine;
    combine.next=new node;
    while(gofirst->next!=NULL&&gosecond->next!=NULL){
        if(gofirst->data<gosecond->data){
            gocombine->next=gofirst;
            gocombine=gocombine->next;
            gofirst=gofirst->next;
        }
        else{
            gocombine->next=gosecond;
            gocombine=gocombine->next;
            gosecond=gosecond->next;
        }
    }
    combine.num=first.num+second.num;
    node* delnode=combine.next;
    combine.next=gocombine->next->next;//头节点和普通节点不一致特有的处理
    delete delnode;
    return combine;
}
void delsame(head &first){
    if(first.next==NULL){
        std::cout<<"Error: empty list"<<std::endl;
        return;
    }
    node* prego=first.next;
    node* go=prego->next;
    while(go!=NULL){
        if(go->data==prego->data){
            prego->next=go->next;
            delete go;
            go=prego->next;
            first.num--;
        }
        else{
            prego=go;
            go=go->next;
        }
    }
}
void printlist(head first){
    node* go=first.next;
    while(go!=NULL){
        std::cout<<go->data<<" ";
        go=go->next;
    }
    std::cout<<std::endl;
}


int main(){
    head first;
    head second;
    creat_table(first);
    creat_table(second);
    printlist(first);
    printlist(second);
    head combine=mergelist(first,second);
    printlist(combine);
    return 0;
}
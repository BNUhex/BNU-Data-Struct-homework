#include "SetList.h"

int main(){
    SetList* A=initSetList();
    SetList* B=initSetList();
    SetList* C=initSetList();
    
    insertbuild(A);
    insertbuild(B);
    std::cout<<"A: ";
    printset(A);
    std::cout<<"\nB: ";
    printset(B);
    C=Union(A,B);
    std::cout<<"\nA U B: ";
    printset(C);
    C=Intersection(A,B);
    std::cout<<"\nA ^ B: ";
    printset(C);
    C=Difference(A,B);
    std::cout<<"\nA - B: ";
    printset(C);
    C=Difference(B,A);
    std::cout<<"\nB - A: ";
    printset(C);
    return 0;
}
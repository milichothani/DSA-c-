/*Write C++ program for storing binary number using doubly linked lists. Write functions
a)To compute 1‘s and 2‘s complement
b)Add two binary numbers */



#include<iostream>
using namespace std;
class binary;
class node{
  node *prev;
  bool n;
  node *next;
public:
  node(){
  prev=next=NULL;
}
node (bool b){
  n=b;
  prev=next=NULL;
}
friend class binary;
};
class binary{
  node *start;
public:
  binary(){
    start=NULL;
}
void generatebinary(int num){
  bool rem;
  node *p;
  rem=num%2;
  start=new node(rem);
  num=num/2;
while(num!=0){
  rem=num%2;
  num=num/2;
  p=new node(rem);
  p->next=start;
  start->prev=p;
  start=p;
  }
}
void displaybinary(){
  node *t;
  t=start;
while(t!=NULL){
  cout<<t->n;
  t=t->next;
  } 
} 
void onescomp(){
  node *t;
  t=start;
while(t!=NULL){
  if(t->n==0){
    t->n=1;
}
  else{
    t->n=0;
}
t=t->next;
} 
 } 
void twoscomp(){
  onescomp();
  bool carry=1;
  node *t;
  t=start;
while(t->next!=NULL){
  t=t->next;
}
while(t!=NULL){
  if(t->n==1&& carry==1){
    t->n=0;
    carry=1;
}
  else if(t->n==0&& carry==1){
    t->n=1;
    carry=0;
  }
  else if(carry==0)
    break;
    t=t->prev;
}
displaybinary();
}
binary operator +(binary n1){
  binary sum;
  node *a=start;
  node *b=n1.start;
// bit *s=sum.start;
  bool carry=false;
while(a->next!=NULL)
  a=a->next;
while(b->next!=NULL)
  b=b->next;
while(a!=NULL && b!=NULL){
  sum.addbitatbegining((a->n)^(b->n)^carry);
carry=((a->n&& b->n) || (a->n&& carry) || (b->n && carry));
a=a->prev;
b=b->prev;
}
while(a!=NULL){
  sum.addbitatbegining(a->n^carry);
  a=a->prev;
}
while(b!=NULL){
  sum.addbitatbegining(b->n^carry);
  b=b->prev;
}
sum.addbitatbegining(carry);
  return sum;
}
bool addbitatbegining(bool val){
node *nodee=new node(val);
if(start==NULL){
  start=nodee;
}
else{
  nodee->next=start;
  start->prev=nodee;
  start=nodee;
}
return true;
  }
};
int main(){
int num1,num2;
binary n1,n2,n3;
int ch, op; do{
cout<<"\n..........MENU..........";
cout<<"\n1. Generate the binary: ";
cout<<"\n2. One's compliment: ";
cout<<"\n3. Two's compliment: ";
cout<<"\n4. Addition: ";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch){
  case 1:
    cout<<"\nEnter the number in decimal format: ";
    cin>>num1;
    n1.generatebinary(num1);
    cout<<"Binary representation: ";
    n1.displaybinary();
    break;
  case 2:
    cout<<"\nEnter the number in decimal format: ";
    cin>>num1;
    n1.generatebinary(num1);
    cout<<"\nBinary representation: ";
    n1.displaybinary();
    cout<<"\nOne's compliment: ";
    n1.onescomp();
    n1.displaybinary();
    break;
  case 3:
    cout<<"\nEnter the number in decimal format: ";
    cin>>num1;
    n1.generatebinary(num1);
    cout<<"\nBinary representation: ";
    n1.displaybinary();
    cout<<"\nTwo's compliment: ";
    n1.twoscomp();
    break;
  case 4:
    cout<<"\nEnter two number: ";
    cin>>num1>>num2;
    n1.generatebinary(num1);
    n2.generatebinary(num2);
    n1.displaybinary(); cout<<" + ";
    n2.displaybinary(); cout<<" = ";
    n3=n1+n2; n3.displaybinary();
    break; default:
    cout<<"\nINVALID CHOICE!!!";
    break;
}
cout<<"\nDo you want to perform again? press 1 for yes, else press 0: ";
cin>>op;
}while(op==1);
    return 0;
}

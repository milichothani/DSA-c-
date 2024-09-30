/*Queues are frequently used in computer programming, and a typical example is the creation of a job
queue by an operating system. If the operating system does not use priorities, then the jobs are
processed in the order they enter the system. Write C++ program for simulating job queue. Write
functions to add job and delete job from queue*/

#include<iostream>
using namespace std;

class eleven{
    public:
    int queue[20];
    int front = -1;
    int rear = -1;
void enqueue(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    if((front==-1 && rear==-1)){
        front =rear=0;
        queue[rear]=n;
    }
    else if(rear>-1 && rear<n){
        rear++;
        queue[rear]=n;
    }
    else{
        cout<<"Value inserted!!!"<<endl;
    }
    display();
    }
void dequeue(){
    int temp;
    if((front==0 && rear==0) || (front==rear)){
        temp=queue[front];
        front=rear=-1;
    }
    else if(front<rear){
        temp=queue[front];
        front++;
    }
    cout<<temp<<" is deleted from the queue!"<<endl;
    cout<<"\nRemaining elements are: "<<endl;
    display();
}
void display(){
    for(int i=front;i<=rear;i++){
        cout<<" "<<queue[i]<<endl;
    }
}

};

int main(){
    int op, ch;
    eleven M;
    
    do{
   
        cout<<"\n...........MENU.............";
        cout<<"\n1. Enqueue";
        cout<<"\n2. Dequeue";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch){
        case 1:
           M.enqueue();
           break; 
        
        case 2:
            M.dequeue();
            break;
        
        case 3:
            cout<<"INVALID CHOICE!!!!";
            break;
        
        }
         cout<<"Do you want to perform agaian?  PRESS 1 if yes else press 0: ";
    cin>>op; 
   
       
    
    }while(op==1);
    return 0;
   
}

//expected output:
/* ...........MENU.............
1. Enqueue
2. Dequeue
Enter your choice: 1
Enter the value of n: 7
 7
Do you want to perform agaian?  PRESS 1 if yes else press 0: 1

...........MENU.............
1. Enqueue
2. Dequeue
Enter your choice: 1
Enter the value of n: 8
 7
 8
Do you want to perform agaian?  PRESS 1 if yes else press 0: 1

...........MENU.............
1. Enqueue
2. Dequeue
Enter your choice: 1
Enter the value of n: 9
 7
 8
 9
Do you want to perform agaian?  PRESS 1 if yes else press 0: 1

...........MENU.............
1. Enqueue
2. Dequeue
Enter your choice: 1
Enter the value of n: 6
 7
 8
 9
 6
Do you want to perform agaian?  PRESS 1 if yes else press 0: 1

...........MENU.............
1. Enqueue
2. Dequeue
Enter your choice: 2
7 is deleted from the queue!

Remaining elements are:
 8
 9
 6
Do you want to perform agaian?  PRESS 1 if yes else press 0: 0
PS C:\Users\admin\Downloads\DSA assignments> */

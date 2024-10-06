/*Assignment on pinnacle club for deleting, inseritng , searching memebers, secretary and president*/




#include<iostream>
#include<string.h>
using namespace std;
class node{
    public:
    char name[50];
    int PRN;
    node*next;
};
class SLL{
    node *head, *last;
    node *temp, *temp1;
    public:
    int count;
    void create(){
        int ch;
        do{
            if(head==NULL){
                temp=new node;
                cout<<"\nEnter PRN and name of PRESIDENT: ";
                cin>>temp->PRN>>temp->name;
                temp->next=NULL;
                head=temp;
                cout<<"\nEnter PRN and name of SECRETARY: ";
                cin>>temp->PRN>>temp->name;
                temp->next=NULL;
                last=temp;
                head->next=last;
                count=count+2;
                cout<<"\nEnter PRN and name of members: ";
                cin>>temp->PRN>>temp->name;
                temp->next=NULL;
                head=temp;
                temp->next=head;
                count=count+2;
                }
            else{
                temp1=head;
                while(temp1->next!=last){
                    temp1=temp1->next;
                    temp=new node;
                    cout<<"\nEnter PRN and name of memebers: ";
                    cin>>temp->PRN>>temp->name;
                    temp->next=NULL;
                    last=temp;
                    count++;
                }
                
                    
            }
            cout<<"\nDO YOU WANT TO ADD MORE NODE? PRESS 1 IF YES ELSE PRESS 0: ";
            cin>>ch;    
        }while(ch==1);
    }
    void display(){
        if(head==NULL){
            cout<<"\nCREATE A LINKED LIST FIRST!!!"<<endl;
        }
        else{
            temp=head;
            cout<<"\nPRESIDENT OF CLUB IS\n";
            cout<<temp->PRN<<"\t"<<temp->name<<endl;
            temp=temp->next;
            cout<<"\nAll members of club are\n";
            while(temp->next=NULL){
                cout<<temp->PRN<<"\t"<<temp->name<<endl;
            }
            cout<<"\nSECRETARY of club is\n";
            cout<<temp->PRN<<"\t"<<temp->name<<endl;
        }
    }
    void insertnode(){
        int c;
        if(head==NULL){
            cout<<"\nCREATE A LINK FIRST!!!!"<<endl;
            create();
        }
        else{
            cout<<"\n........MENU FOR INSERTING NODE..........";
            cout<<"\n1. Add the PRESIDENT";
            cout<<"\n2. Add the SECRETARY";
            cout<<"\n3. Add the member of club";
            cin>>c;
            switch(c){
                case 1:
                temp=new node;
                cout<<"\nEnter the PRN and name of President: ";
                cin>>temp->PRN>>temp->name;
                temp->next=NULL;
                temp->next=head;
                head=temp;
                break;
                case 2:
                temp=new node;
                cout<<"\nEnter the PRN and name of secretary: ";
                cin>>temp->PRN>>temp->name;
                temp->next=NULL;
                last->next=temp;
                last=temp;
                break;
                case 3:
                create();
                default:
                cout<<"INVALID CHOICE!!!!!"<<endl;
                break;
            }
            
        }
    }
    void deletenode(){
        int n;
        if(head==NULL){
            cout<<"\nCREATE A LINKED LIST FIRST!!!!"<<endl;
            create();
        }
        else{
            cout<<"\n............MENU FOR DELETION.............";
            cout<<"\n1. Delete the PRESIDENT";
            cout<<"\n2. Delete the SECRETARY";
            cout<<"\n3. Delete the MEMBER";
            cin>>n;
            switch(n){
                case 1:
                if(head==last){
                    head=last=NULL;
                }
                else{
                    temp=head;
                    head=head->next;
                    delete temp;
                }
                break;
                case 2:
                if(head==last){
                    head=last=NULL;
                }
                else{
                    temp=head;
                    while(temp->next!=last){
                        temp=temp->next;
                    }
                    delete last;
                    temp->next=NULL;
                    last=temp;
                }
                break;
                case 3:
                if(head==last){
                    head=last=NULL;
                }
                break;
                default:
                cout<<"INVALID CHOICE!!!!!"<<endl;
                break;
            }
        }
    } 
    void linksearch(){
        int key, flag=0;
        if(head==NULL){
            cout<<"\nCREATE A LINKED LIST FIRST!!!!"<<endl;
        }
        else{
            temp=head;
            cout<<"\nEnter the PRN of the student you want to serach: ";
            cin>>key;
            while(temp!=NULL){
                if(key==temp->PRN){
                    cout<<"FOUND!!!"<<endl;\
                    flag=1;
                    break;
                }
                temp=temp->next;
            }
        }
        if(flag==0){
            cout<<"NOT FOUND!!!!!"<<endl;
        }
    }  
    SLL(){    //default constructor
        count=0;
        head=NULL;
        last=NULL;
    } 
};
int main(){

    int ch, op;
    SLL obj;
    do{
        cout<<"\n.............MENU..............";
        cout<<"\n1. CREATE";
        cout<<"\n2. DISPLAY";
        cout<<"\n3. SEARCH";
        cout<<"\n4. Display total memebers ";
        cout<<"\n5. Insert a new node";
        cout<<"\n6. DELETE";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
            obj.create();
            break;
            case 2:
            obj.display();
            break;
            case 3:
            obj.linksearch();
            break;
            case 4:
            cout<<"Total memebrs of PINNACLE CLUB are: "<<obj.count-2;
            break;
            case 5:
            obj.insertnode();
            break;
            case 6:
            obj.deletenode();
            break;
            default:
            cout<<"INVALID CHOICE!!!!!!"<<endl;
            break;
        }
        cout<<"DO you want to perform again? press 1 if yes else press 0: ";
        cin>>op;
    }while(op==1);
    return 0;
}

//list implementation of queue
#include<iostream>
#include<stdlib.h>
#define max 10


using namespace std;
int avail = 0;

struct nodetype
{
    int info,next;
}node[max];

int getnode(){
    int p;
    if(avail == -1){
        cout<<"overflow";
        exit(1);

    }
    p = avail;
    avail = node[avail].next;
    node[p].next = -1;
    return(p);
}

void freenode(int p){
    node[p].next = avail;
    avail=p;
    return;
}

void display(int f){
    cout<<"\n\n============================================"<<endl;
    if(f!=-1){
    cout<<"NODE"<<"\t\tINFO"<<endl;
    for(int i=f;i!=-1;i=node[i].next){
        cout<<i<<"\t\t"<<node[i].info<<endl;
    }}
    else{cout<<"Empty Queue"<<endl;}
    cout<<"============================================"<<endl;

}

class Queue{
    private:
        int front, rear;
    public:
        Queue():front(-1),rear(-1){};


        bool isempty(){
            if(front==-1)
                return true;
            else
                return false;
        }



        void enqueue(){
            int ptr;
            ptr = getnode();
            cout<<"Enter an integer:";
            cin>>node[ptr].info;
            if(rear==-1)
                front = ptr;
            else
                node[rear].next=ptr;
            rear=ptr;
        }

        int dequeue(){
            int delval,ptr;
            if(isempty()){
                cout<<"underflow";
                exit(1);
            }
            else{
                delval=node[front].info;
                ptr=front;
                front=node[front].next;
                if(front==-1)
                    rear=-1;
                freenode(ptr);
                return delval;
            }
        }
        int getfront(){
            return front;
        }

};

int main(){
    for(int i=0;i<max;i++){
        if(i==max-1){
            node[i].next=-1;
        }
        else{
            node[i].next=i+1;
        }
    }
    int choose=1;
    int val,pos;
    Queue Q;
    while(choose!=0){
        cout<<"\nmenu:"<<endl;
        cout<<"==========="<<endl;
        cout<<"1 .Enqueue"<<endl;
        cout<<"2 .Dequeue"<<endl;
        cout<<"3 .Display Queue"<<endl;
        cout<<"0 .Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choose;
        switch(choose){
        case 1:
            Q.enqueue();
            display(Q.getfront());
            break;
        case 2:
            val=Q.dequeue();
            display(Q.getfront());
            cout<<val<<" is dequeued"<<endl;
            break;
        case 3:
            display(Q.getfront());
            break;
        case 0:

            break;
        }
    }
    return 0;

}

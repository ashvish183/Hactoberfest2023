#include<iostream>
using namespace std;
#include<string.h>
#include<math.h>
#define max 100 
char infix [max];
template<class Y>
class st{public:
//int stack[max];
Y stack[max]; 
char postfix[max];
int top=-1;
int space(char c){
    if(c==' '||c=='\t') return 1;
    else return 0;
}
int precedence(char symbol){
    switch(symbol){
        case '^': return 3;
        case '/': case '*': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}
void display(){
    int i=0;
    cout<<"The equivalent postfix expression is: ";
    while(postfix[i]){cout<<postfix[i++];}cout<<endl;
}
void push(char c){
    if(top==max-1){
        cout<<"Overflow state"; return;
    }
    top++;
    stack[top]=c;
}
void push1(int a){
if(top==max-1){
        cout<<"Overflow state"; return;
    }
    top++;
    stack[top]=a;
}
/*template<typename X>
void push(X a){
if(top==max-1){
        cout<<"Overflow state"; return;
    }
    top++;
    stack[top]=
*/
char pop(){
    char c;
    if(top==-1){
        cout<<"Overflow state"; exit(1);
    }
    c=stack[top];
    top=top-1;
    return c;
}
int pop1(){int c;
    if(top==-1){
        cout<<"Overflow state"; exit(1);
    }
    c=stack[top];
    top=top-1;
    return c;}
/*template<typename T>
T pop(){
    T c;
    if(top==-1){
        cout<<"Overflow state"; exit(1);
    }
    c=stack[top];
    top=top-1;
    return c;
}*/
int isempty(){
    if(top==-1) return 1;
    else return 0;
}
void intopost(){
    int i,j=0;
    char next;
    char symbol;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(!space(symbol)){
            switch(symbol){
                case '(':
                push(symbol);
                break;
                case ')':
                while((next=pop())!='(')
                postfix[j++]=next;
                break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                while(!isempty()&&precedence(stack[top])>=precedence(symbol))
                postfix[j++]=pop();
                push(symbol);
                break;
                default: //for operands
                postfix[j++]=symbol;

            }
        }
    }
    while(!isempty())
    postfix[j++]=pop();
    postfix[j]='\0';
}

//evaluation
int eval(){
    int i,a,b;
    for(i=0;i<strlen(postfix);i++){
        if(postfix[i]>='0'&& postfix[i]<='9') //comparison with the help of ascii
        //ascii of 0 is 48 and 9 is 57 thus(0 to 9) ascii is from (48 to 57)
        {
            push1(postfix[i]-'0'); //to covert char from char to int
        }
        else{
            a=pop1(); b=pop1();
            switch(postfix[i]){
                case '+':
                push1(b+a); break;
                case '-':
                push1(b-a); break;
                case '*':
                push1(b*a); break;
                case '/':
                push1(b/a); break;
                case '^':
                push1(pow(b,a)); break;
            }
        }
    } return pop1();
}};
int main(){int ans;
    cout<<"Enter the infix expression: ";
    gets(infix);
    st<char> s;
    
    s.intopost();
    s.display();
    st<int> s1;
    s1.intopost();
    ans=s1.eval();
    cout<<"Answer after evaluationg is:"<<ans;
    return 0;
}

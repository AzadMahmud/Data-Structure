#include<iostream>
#include<stack>
using namespace std;

int tops = -1;
int st[1001];
class mystack{
public:
    void push(char data){
        if(tops == 1001-1){
            cout<<"stack is full"<<endl;
            return;
        }
        st[++tops] = data;
    }
    void pop(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return;
        }
        tops--;
    }
    char top(){
        if(tops==-1){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return st[tops];
    }
    bool isempty(){
        if(tops == -1){
            return true;
        }
        else return false;
    }

};
//postfix evaluation
int EvaluatePostfix(string c){
   stack<int>s; 
   for(int i = 0; i<c.length(); i++){
        if(c[i] == ' ' || c[i]== ','){
            continue;
        }
        else if(c[i] >= '0' && c[i] <= '9'){
            int num = 0;
            while(c[i] >= '0' && c[i] <= '9'){
                num = (num*10)+(int)(c[i]-'0');
                i++;
        }
            i--;
            s.push(num);
        }
        else if(c[i]>='a'&&c[i]<='z'||c[i]>='A'&&c[i]<='Z'){
        
            cout<<"Enter the value of the "<<c[i]<<":"<<endl;
            int value;
            cin>>value;
            s.push(value);
        
        }
        else{
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();
            switch(c[i])
            {
                case '+':
                    s.push(val1+val2);
                    break;
                case '-':
                    s.push(val1-val2);
                    break;
                case '*':
                    s.push(val1*val2);
                    break;
                case '/':
                    s.push(val1/val2);
                    break;
            }
            }
   }
   return s.top();
}
// infix to postfix evaluation

int prece(char c){
    if(c=='^') return 3;
    else if(c=='/'||c=='*') return 2;
    else if(c=='+'||c=='-') return 1;
    else return -1;
}
string InfixToPostfix(string exp, mystack st){
    // stack<char>st;
    string result;

    for(int i= 0; i<exp.length(); i++){
        char c = exp[i];
        if(exp[i]==' '|| exp[i]==',') continue;
        else if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
            result+=c;
            result+=","; 
        }
        else if(c=='('){
            st.push('(');
        }
        else if(c==')'){
            while(st.top()!='('){
                result+=st.top();
                result+=",";
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.isempty()&&prece(exp[i])<=prece(st.top())){
                result+=st.top();
                result+=",";
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.isempty()){
        result+=st.top();
        result+=",";
        st.pop();
    }
    // cout<<result<<endl;

    
    return result;
}

int main(){
    mystack sck;
    string expression;
    getline(cin,expression);
    string postfix = InfixToPostfix(expression,sck);
    // InfixToPostfix(expression);
    cout<<postfix<<endl;
    int infix = EvaluatePostfix(postfix);
    cout<<"ans: "<<infix<<endl;
}

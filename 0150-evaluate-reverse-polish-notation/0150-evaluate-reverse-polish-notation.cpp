// #include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a, b, c;
        char token;
        for(int i=0;i<tokens.size();i++){
            if (testOperator(tokens[i])){
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                c = doOperation(tokens[i][0], b, a);
                s.push(c);
            }
            else {     
                
                s.push(stoi(tokens[i]));
            }       
        }
        return s.top();
    };
    
private:
    bool testOperator(string str){
        char op = str[0];
        if (op=='+' || op=='-' || op=='*' || op=='/'){
            if (str.length()!=1){
                return false;
            }
            return true;
        }
        else
            return false;
    };
    int doOperation(char ss, int a, int b){
        int result;
        switch(ss){
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;                             
        }
        return result; 
    };
};
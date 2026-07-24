class Solution {
private:
    stack<int>operand;
public:
    int evalRPN(vector<string>& tokens) {
        for(auto c: tokens)
        {
            if(c=="+")
            {
                int o1 = operand.top();operand.pop();
                int o2 = operand.top();operand.pop();
                operand.push(o1+o2);
            }
            else if(c=="-")
            {
                int o1 = operand.top();operand.pop();
                int o2 = operand.top();operand.pop();
                operand.push(o2-o1);
            }
            else if(c=="*")
            {
                int o1 = operand.top();operand.pop();
                int o2 = operand.top();operand.pop();
                operand.push(o1*o2);
            }
            else if(c=="/")
            {
                int o1 = operand.top();operand.pop();
                int o2 = operand.top();operand.pop();
                operand.push(o2/o1);
            }
            else{
                operand.push(stoi(c));
            }
        }
        return operand.top();
    }
};

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack{};
        
        for (const std::string& token : tokens) {
            if (token == "+" ) {
                int b{stack.top()}; stack.pop();
                int a{stack.top()}; stack.pop();
                stack.push(a + b);
            } 
            else if (token == "-") {
                int b{stack.top()}; stack.pop();
                int a{stack.top()}; stack.pop();
                stack.push(a - b);
            } 
            else if (token == "*") {
                int b{stack.top()}; stack.pop();
                int a{stack.top()}; stack.pop();
                stack.push(a * b);
            } 
            else if (token == "/") {
                int b{stack.top()}; stack.pop();
                int a{stack.top()}; stack.pop();
                stack.push(a / b); 
            } 
            else {
                stack.push(std::stoi(token)); 
            }
        }
        
        return stack.top();
    }
};
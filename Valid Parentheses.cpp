class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        for(int i = 0;i < s.size();++i)
        {
            switch(s[i])
            {
                case '(':
                    Stack.push(')');break;
                case '[':
                    Stack.push(']');break;
                case '{':
                    Stack.push('}');break;
                default:
                    if(Stack.size() == 0)
                        return false;
                    char c = Stack.top();
                    Stack.pop();
                    if(c != s[i])
                        return false;
            }
        }
        return Stack.size() == 0;
        
    }
};


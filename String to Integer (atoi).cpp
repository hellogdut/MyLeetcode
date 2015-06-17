#define INT_MIN     -2147483648
#define INT_MAX      2147483647
class Solution {
public:
    int myAtoi(string str) {
        const char *cstr = str.c_str();
        int result = 0;
        int flag = 0;
        if (cstr == 0)
            return 0;
        int i = 0;
        while (cstr[i] != '\0')
        {
            if (cstr[i] == '+' || cstr[i] == '-' || cstr[i] == '.' || (cstr[i] >= '0' && cstr[i] <= '9'))
                break;
            else if (cstr[i] >= 'A' && cstr[i] <= 'z')
                return 0;
            else
                i++;
        }

        if (cstr[i] == '+')
        {
            flag = 1;
            i++;
        }
        else if (cstr[i] == '-')
        {
            flag = -1;
            i++;
        }
        else if (cstr[i] == '.')
            return result;
        if (!flag)
            flag = 1;
        for (; cstr[i] != '\0'; ++i)
        {
            int digit = cstr[i] - '0';
            if (digit >= 0 && digit <= 9)
            {
                if (flag == -1){
                    if (-result < (INT_MIN + digit) / 10)
                        return INT_MIN;
                }
                else{
                    if (result >(INT_MAX - digit) / 10)
                        return INT_MAX;
                }

                result = result * 10 + digit;
            }
            else
            {
                break;
            }
        }
        return flag * result;
    }
};

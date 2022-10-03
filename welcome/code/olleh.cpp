#include <iostream>
#include <stack>
#include <string>
using namespace std;
void reverseWords(std::string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); ++i) {
        if (isalpha(str[i])|| isdigit(str[i]))
            st.push(str[i]);
        else {
            while (st.empty() == false) {
                cout << st.top();
                st.pop();
            }
            cout << str[i];
        }
    }

    while (st.empty() == false) {
        cout << st.top();
        st.pop();
    }
}
int main()
{
    string str;
    getline(cin,str);
    reverseWords(str);
    return 0;
}

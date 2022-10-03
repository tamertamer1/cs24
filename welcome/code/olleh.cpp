#include <iostream>
#include <stack>
using namespace std;
void reverseWords(string str)
{
    stack<char> st;
    for (unsigned int i = 0; i < str.length(); ++i) {
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


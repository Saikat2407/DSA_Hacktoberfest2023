// Question: 01 --> Balanced Parenthesis
// Question: 02 --> Next Greater Element (NGE) using stack

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> m = {{'[', -1}, {'{', -2}, {'(', -3}, {')', 3}, {'}', 2}, {']', 1}};

string isBalanced(string s)
{
    stack<char> st;
    for (char bracket : s)
    {
        if (m[bracket] < 0)
        { // m[bracket] gives an mapped integer
            st.push(bracket);
        }
        else
        {
            if (st.empty())
                return "NO";
            char top = st.top();
            st.pop();
            if (m[top] + m[bracket] != 0)
                return "NO";
        }
    }

    if (st.empty())
        return "YES";
    else
        return "NO";
}

int main()
{

    // Balanced Parenthesis:   (inputs:-)
    // 3
    // {[()]}
    // {[(])}
    // {{[[(())]]}}

    /*(Question: 01)
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }
    */

    /*(Question: 01)
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        stack<char> st;
        for(char bracket : s){
            if(bracket=='[' || bracket=='{' || bracket=='(' )
                st.push(bracket);
            else if(bracket==']' && st.top()=='[' && !st.empty())
                st.pop();
            else if(bracket=='}' && st.top()=='{' && !st.empty())
                st.pop();
            else if(bracket==')' && st.top()=='(' && !st.empty())
                st.pop();
        }

        if(st.empty())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    */

    // ----------------------------------------------------------------------------------------------------------------------

    /*(Question: 02)  --> O(n^2) using two for-loops.
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){    // O(n^2) ....better to use stacks
        int next = -1;
        for(int j=i+1; j<n; j++){
            if(arr[j] > arr[i]){
                next = arr[j];
                break;
            }
        }
        cout<< next <<" ";
    }
    */

    
    
    /* (Question: 02)  --> O(n^2) using two for-loops.
    #include <bits/stdc++.h>
    using namespace std;

    int main(){

        vector<int> v = {4, 5, 2, 25, 7, 8};
        for (int i = 0; i < v.size(); i++){
            bool gt = false;
            for (int j = i; j < v.size(); j++){
                if (v[j] > v[i]){
                    cout << v[j] << " ";
                    gt = true;
                    break;
                }
            }
            if (!gt)
                cout << -1 << " ";
        }

        return 0;
    }
    */


    // (Question: 02)  --> O(n) using stacks.
    

    return 0;
}
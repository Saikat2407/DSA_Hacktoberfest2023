// CORRECT CODE USING UNORDERED_MAP

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function template for C++

/*
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    void check(Node *root, int k, int &count, int sum, unordered_map<int, int> &mp)
    {
        if (root == NULL)
            return;

        //first time add root->data to sum
        sum += root->data;

        //count me baki ke elements dalte raho
        count += mp[sum - k];

        if (sum == k)
            count++;

        mp[sum]++;

        check(root->left, k, count, sum, mp);
        check(root->right, k, count, sum, mp);

        mp[sum]--;
    }
    int sumK(Node *root, int k)
    {
        int count = 0;
        unordered_map<int, int> mp;
        check(root, k, count, 0, mp);
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    string tc;
    getline(cin, tc);
    int t = stoi(tc);

    while (t--)
    {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);

        string key;
        getline(cin, key);
        int k = stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends

// //Giving TLE CODE

// //{ Driver Code Starts
// // Initial template for C++

// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val)
//     {
//         data = val;
//         left = right = NULL;
//     }
// };

// // Function to Build Tree
// Node *buildTree(string str)
// {
//     // Corner Case
//     if (str.length() == 0 || str[0] == 'N')
//         return NULL;

//     // Creating vector of strings from input
//     // string after spliting by space
//     vector<string> ip;

//     istringstream iss(str);
//     for (string str; iss >> str;)
//         ip.push_back(str);

//     // Create the root of the tree
//     Node *root = new Node(stoi(ip[0]));

//     // Push the root to the queue
//     queue<Node *> queue;
//     queue.push(root);

//     // Starting from the second element
//     int i = 1;
//     while (!queue.empty() && i < ip.size())
//     {

//         // Get and remove the front of the queue
//         Node *currNode = queue.front();
//         queue.pop();

//         // Get the current Node's value from the string
//         string currVal = ip[i];

//         // If the left child is not null
//         if (currVal != "N")
//         {

//             // Create the left child for the current Node
//             currNode->left = new Node(stoi(currVal));

//             // Push it to the queue
//             queue.push(currNode->left);
//         }

//         // For the right child
//         i++;
//         if (i >= ip.size())
//             break;
//         currVal = ip[i];

//         // If the right child is not null
//         if (currVal != "N")
//         {

//             // Create the right child for the current Node
//             currNode->right = new Node(stoi(currVal));

//             // Push it to the queue
//             queue.push(currNode->right);
//         }
//         i++;
//     }

//     return root;
// }

// // } Driver Code Ends
// // User function template for C++

// /*
// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };
// */
// class Solution
// {
// public:
//     void solve(Node *root, int k, int &count, vector<int> path)
//     {
//         // base case
//         if (root == NULL)
//         {
//             return;
//         }

//         path.push_back(root->data);

//         // left ke liye call
//         solve(root->left, k, count, path);
//         // right kr liye
//         solve(root->right, k, count, path);

//         // check for K sum
//         int size = path.size();
//         int sum = 0;
//         // piche se check karte aao
//         for (int i = size - 1; i >= 0; i--)
//         {
//             sum += path[i]; // sum nikal lo

//             if (sum == k)
//             {
//                 count++;
//             }
//         }

//         // jab waps jaoge tab last wale ko pop bhi karna padega
//         path.pop_back();
//     }

//     int sumK(Node *root, int k)
//     {
//         vector<int> path;
//         int count = 0;

//         solve(root, k, count, path);

//         return count;
//     }
// };

// //{ Driver Code Starts.

// int main()
// {
//     string tc;
//     getline(cin, tc);
//     int t = stoi(tc);

//     while (t--)
//     {
//         string s, ch;
//         getline(cin, s);
//         Node *root = buildTree(s);

//         string key;
//         getline(cin, key);
//         int k = stoi(key);
//         Solution ob;
//         cout << ob.sumK(root, k) << "\n";
//     }
//     return 0;
// }
// // } Driver Code Ends

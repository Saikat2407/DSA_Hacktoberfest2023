//Leetcode Solution of Merge K Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    priority_queue <pair<int,ListNode*>,vector <pair<int,ListNode*>>,greater<pair<int,ListNode*>>> p1;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i=0;i<lists.size();i++)
        {
            if (lists[i])
            {
                p1.push({lists[i]->val,lists[i]});
            }
        }
        vector <int> arr (lists.size());
        ListNode* head = new ListNode();
        ListNode* ans = head;
        while (p1.size())
        {
            auto it = p1.top();
            p1.pop();
            ListNode* node = new ListNode();
            node->val = it.first;
            head->next=node;
            head=node;
            
            if (it.second->next!=nullptr)
            {
                p1.push({it.second->next->val,it.second->next});
            }
        }
        return ans->next;
        
    }
};
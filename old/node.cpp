
#include<bits/stdc++.h>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> st;
        st.
        ListNode *temp = head;
        while(temp!=NULL) {
            st.push_back(temp);
            temp = temp->next;
        }
        for(int i = 1;i<=n;i++) {
            st.
        }
        
        
    }
};
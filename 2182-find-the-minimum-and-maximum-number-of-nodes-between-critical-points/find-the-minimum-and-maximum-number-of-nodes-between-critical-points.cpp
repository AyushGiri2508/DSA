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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return ans;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* forw = head->next->next;
        int pos = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        while (forw != NULL) {
            bool critical = false;
            if (prev->val > curr->val && curr->val < forw->val) {
                critical = true;
            }
            if (prev->val < curr->val && curr->val > forw->val) {
                critical = true;
            }
            if (critical) {
                if (first == -1) {
                    first = pos;
                }
                if (last != -1) {
                    minDist = min(minDist, pos - last);
                }

                last = pos;
            }
            prev = curr;
            curr = forw;
            forw = forw->next;
            pos++;
        }
        if (first == -1 || first == last) {
            return ans;
        }
        ans[0] = minDist;
        ans[1] = last - first;
        return ans;
    }
};
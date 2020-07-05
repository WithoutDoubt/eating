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
class Solution {   // 错的
    
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        ListNode* temp;

        while( l1 != NULL || l2 != NULL){

            if(l1 != NULL && l2 != NULL){
                if(l1->val < l2->val){
                    temp = l1->next;
                    p->next = l1;
                    p->next->next = NULL;
                    l1 = temp;
                    p = p->next;
                }else{
                    temp = l2->next;
                    p->next = l2;
                    p->next->next = NULL;
                    l2 = temp;
                    p=p->next;
                }

            }else if(l1 != NULL){
                p->next = l1;
            }else if(l2 != NULL){
                p->next = l2;
            }

        }

        return dummy->next;

        
        
    }
};

//
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);

        ListNode* prev = dummy;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return dummy->next;
    }
};

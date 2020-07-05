/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);

        ListNode *p, *last;
        p = head; // p = head, p 指针里面存的是 head指针 里面的值（内存地址）

        while (p != NULL)
        {

            last = p->next; // 存下来 p->next

            p->next = dummy->next;
            dummy->next = p;

            p = last;
        }
        return dummy->next;
    }
};

/// 错的
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // 找到m
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *p;
        ListNode *node;

        p = head;

        while (n)
        {
            node = head->next;

            if (!m)
            {
                p = p->next;
            }
            else // 反转
            {
                node->next = p->next;
                p->next = node;
            }

            // head = head->next;
            // p = p->next;

            n--;
            m--;
        }

        return dummy->next;
    }
};
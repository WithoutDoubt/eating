/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
*/

class Solution_1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(target - nums[i]) == m.end())
            {
                m[nums[i]] = i;
            }
            else
            {
                return {m[target - nums[i]], i};
            }
        }
        return {};
    }

}

class Soulutin_1
{ //        JAVA
public
    int[] twoSum(int[] nums, int target)
    {

        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++)
        {

            if (map.containsKey(target - nums[i]))
            {

                return new int[]{map.get(target - nums[i]), i};
            }
            else
            {
                map.put(nums[i]) = i;
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}

/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

class Solution_2
{
    /*
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
     */
public:
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode(-1);
        ListNode h = head;
        int sum = 0;
        bool carry = false;

        while (list1 != NULL || list2 != NULL)
        {
            if (list1 != NULL)
            {
                sum += list1->val;
                list1 = list1->next;
            }

            if (list2 != NULL)
            {
                sum += list2->val;
                list1 = list2->next;
            }

            if (carry)
                sum++;

            h->next = new ListNode(sum % 10);
            h = h->next;

            carry = sum >= 10 ? true : false;
            sum = 0;
        }

        if (carry)
            h->next = new ListNode(1);

        return head->next; // 头指针法
    }
};
}

class Solution_2
{
    /**      Java
 *
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public
    ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
        ListNode head = new ListNode(0);
        ListNode h = head;
        int carry = 0;

        while (l1 != null || l2 != null)
        {
            int x = (l1 != null) ? l1.val : 0;
            int y = (l2 != null) ? l2.val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            h.next = new ListNode(sum % 10);
            h = h.next;
            if (l1 != null)
                l1 = l1.next;
            if (l2 != null)
                l2 = l2.next;
        }
        if (carry > 0)
            h.next = new ListNode(carry);
        return head.next;
    }

}

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
*/

class Solution_3
{
    // 滑动窗口 c++
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> occ;
        int n = s.size();

        int rk = 0, ans = 0;

        for (int left = 0; left < n; left++)
        { //左边left
            if (left != 0)
            {
                occ.erase(s[left - 1]);
            }

            while (rk < n && !occ.count(s[rk]))
            {
                occ.insert(s[rk]);
                rk++;
            }
            ans = max(ans, rk - left);
        }
        return ans;
    }
}

class Solution_3_1
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> window;
        int left = 0;
        int right = 0;
        int res = 1;
        while (right < s.size())
        {
            char c1 = s[right];
            window[c1]++;
            right++;

            // 有重复数字就开始移动left
            while (window[c1] > 1)
            {
                char c2 = s[left];
                window[c2]--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
}

class Solution_3_2
{
public:
    int lengthOfLongesetSubstring(string s)
    {
        int start = 0;
        int end = 0;
        int length = 0;
        int result = 0;

        int sSize = s.size();

        while (end < sSize)
        { // 第一个循环
            char tmp = s[end];

            for (int i = start; i < end; i++)
            {
                if (tmp == s[i])
                {
                    start = i + 1;
                    length = end - start;
                    break;
                }
            }
            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
}

// 滑动窗口的框架
while (right < n)
{
    window.add(s[right]);
    right++;

    while (s in window)
    {
        res = min(res, window);
        window.remove(s[left])
            left++;
    }
}

class Solution_huadongchangkou
{
public:
    string huadongchuangkou()
    {
        string s, t;
        int left = 0;
        int right = 0;
        string res = s;

        unordered_map<char, int> window;
        unordered_map<char, int> needs;

        for (char c : t)
            needs[c]++;
        int match = 0; // 统计有多少个字母符合

        while (right < s.size())
        {
            char c1 = s[right];
            if (needs.count(c1))
            { //字母不是想要的，就 right ++
                window[c1]++;
                if (window[c1] == needs[c1])
                    match++;
            }
            else
            {
                right++;
            }

            while (match == needs.size())
            { //优化整个滑动窗口
                //res = minLen(res,window);  // 更新最小子串的位置和长度
                if (right - left < minLen)
                {
                    start = left;
                    minLen = right - left;
                }

                char c2 = s[left];

                if (needs.count(c2))
                {                 // 字母是想要的，就要随着left移动，移除字母
                    window[c2]--; // 移除window
                    if (window[c2] < needs[c2])
                        match--;
                }
                else
                { // 否则说明可以移动left
                    left++;
                }
            }
        }
        return res; //
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
}

/* 给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。 */

class Solution_124
{
    /*
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x),left(NULL),right(NULL){}
    };

*/

public:
    int ans = INT_MIN; // 全局变量

    int maxPathSum(TreeNode *root)
    {
        helper(root);
        return ans;
    }

    int helper(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));

        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }
}



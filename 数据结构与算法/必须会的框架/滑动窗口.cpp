/*
https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/

*/

void sliding Window(string s, string t)
{
    unordered_map<char, int> need, window;
    for (char c : t)
        need[c]++;

    int left = 0;
    int right = 0;
    int valid = 0;

    while (right < s.size())
    {
        char c = s[right]; // c 是将要移入的字符
        right++;

        // 进行窗口内数据的一系列更新
        // ……
        while (window needs shrink)
        {                     // 如何判断windows 是否需要shrink
            char d = s[left]; // d 是将要移除的字符
            left++;
            // 窗口内数据更新
            // ……
        }
    }
}
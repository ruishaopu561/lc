
01. 判定字符是否唯一
```
输入: s = "leetcode"
输出: false 

输入: s = "abc"
输出: true
```
实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
```cpp
class Solution {
public:
    bool isUnique(string astr) {
        int mask = 0;
        for(int i=0; i<astr.size(); i++)
        {
            int move_bit = astr[i]-'a';
            if((mask & (1<< move_bit)) != 0){
                return false;
            }else{
                mask |= (1<<move_bit);
            }
        }
        return true;
    }
};
```
02. 判定是否互为字符重排
给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
```
输入: s1 = "abc", s2 = "bca"
输出: true 

输入: s1 = "abc", s2 = "bad"
输出: false
```
```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int *a = new int[52];
        for(int i=0; i<52; i++){
            a[i]=0;
        }
        
        for(int i=0; i<s1.size(); i++){
            a[s1[i] - 'a']++;
        }
        
        for(int i=0; i<s2.size(); i++){
            a[s2[i] - 'a']--;
        }
        
        for(int i=0; i<52; i++){
            if(a[i] != 0){
                return false;
            }
        }

        return true;
    }
};
```
04. 回文排列
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
回文串不一定是字典当中的单词。
```
输入："tactcoa"
输出：true（排列有"tacocat"、"atcocta"，等等）
```
```cpp
class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        int char_sum[128]{}; //统计每个字符出现的次数
        for (const char &ch : s)
            char_sum[ch]++;           //该字符出现了，那么就+1
        int count = 0;                //出现次数为奇数的字符计数
        for (int i = 0; i < 128; ++i) //从前向后寻找出现次数为奇数的字符的个数
        {
            if (char_sum[i] % 2 == 1)
            {
                count++;
                if (count > 1) //出现次数为奇数的字符超过一个，返回false
                    return false;
            }
        }
        return true; //出现次数为奇数的字符个数为一个或0个，可行
    }
};
```
05. 一次编辑
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
```
输入: 
first = "pale"
second = "ple"
输出: True

输入: 
first = "pales"
second = "pal"
输出: False
```
```cpp
class Solution
{
public:
    bool oneEditAway(string first, string second)
    {
        int length = first.size() - second.size();
        if (length > 1 || length < -1)
        {
            cout << length << endl;
            return false;
        }

        length = length < 0 ? first.size() : second.size();
        for (int i = 0; i < length; i++)
        {
            if (first[i] == second[i])
            {
                continue;
            }
            if (first.size() > second.size())
            {
                return first.substr(i + 1) == second.substr(i);
            }
            else if (first.size() < second.size())
            {
                return first.substr(i) == second.substr(i + 1);
            }
            else
            {
                return first.substr(i + 1) == second.substr(i + 1);
            }
        }

        return true;
    }
};
```
06. 字符串压缩
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。
```
输入："aabcccccaaa"
输出："a2b1c5a3"

输入："abbccd"
输出："abbccd"
解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
```
```cpp
class Solution
{
public:
    string compressString(string S)
    {
        string target = "";
        int p = 0, i = 0;
        char cur = S[p];
        for (; i < S.size(); i++)
        {
            if (S[i] == cur)
            {
                continue;
            }
            target += cur + to_string(i - p);
            p = i;
            cur = S[i];
        }
        target += cur + to_string(i - p);

        return target.size() < S.size() ? target : S;
    }
};
```
07. 旋转矩阵
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
    [参考链接](https://leetcode-cn.com/problems/rotate-matrix-lcci/solution/c-tu-jie-yuan-di-cao-zuo-ji-bai-shuang-bai-vv-by-t/)
```
给定 matrix = 
[[1,2,3],
 [4,5,6],
 [7,8,9]],
原地旋转输入矩阵，使其变为:
[[7,4,1],
 [8,5,2],
 [9,6,3]]
```
```cpp
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int row = n / 2, col = n % 2 == 0 ? n / 2 : n / 2 + 1;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                swap(matrix[i][j], matrix[j][n - i - 1]);
                swap(matrix[n - i - 1][n - j - 1], matrix[n - j - 1][i]);
                swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
            }
        }
    }
};
```
14. 分割链表
编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。
```
输入: head = 3->5->8->5->10->2->1, x = 5
输出: 3->1->2->10->5->5->8
```
```cpp
// 遍历链表，将大于等于的和小于的分开成链表，然后合并即可。
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small_start = NULL, *small = NULL, *big_start = NULL, *big = NULL, *p = head;
        while (p)
        {
            if (p->val < x)
            {
                if (!small)
                {
                    small = p;
                    small_start = p;
                }
                else
                {
                    small->next = p;
                    small = small->next;
                }
            }
            else
            {
                if (!big)
                {
                    big = p;
                    big_start = p;
                }
                else
                {
                    big->next = p;
                    big = big->next;
                }
            }
            p = p->next;
        }
        if (big)
        {
            big->next = NULL;
        }
        if (small)
        {
            small->next = big_start;
            return small_start;
        }
        else
        {
            return big_start;
        }
    }
};
```
44. 下一个数
下一个数。给定一个正整数，找出与其二进制表达式中1的个数相同且大小最接近的那两个数（一个略大，一个略小）。
```
输入：num = 2（或者0b10）
输出：[4, 1] 或者（[0b100, 0b1]）

输入：num = 1
输出：[2, -1]

提示:
  num的范围在[1, 2147483647]之间；
  如果找不到前一个或者后一个满足条件的正数，那么输出 -1。
```
```cpp
class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        vector<int> result;
        int index = 0, count = 0;
        while(index < 31 && (num>>index & 3) != 1){
            count += (num>>index & 1);
            index++;
        }

        if(index >= 31){
            result.push_back(-1);
        }else{
            int tmp = num >> index << index;
            tmp += (1<<index) + (1<<count)-1;
            result.push_back(tmp);
        }

        index = 0;
        count = 0;
        while(index < 31 && (num>>index & 3) != 2){
            count += (num>>index & 1);
            index++;
        }

        if(index >= 31){
            result.push_back(-1);
        }else{
            int tmp = num >> index <<index;
            tmp += -(1<<index) + ((1<<count)-1<<index-count);
            result.push_back(tmp);
        }

        return result;
    }
};
```
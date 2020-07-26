### #1.两数之和
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:
> 给定 nums = [2, 7, 11, 15], target = 9
>因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

+ 提示：这题无法排序解，因为排序之后的索引与原先不同。
    + 哈希虽然是时间、空间均为O(n)的算法，但是哈希的get本身有一定的复杂度
    + 只能用暴力法。
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> out;

        for(int i=0; i<len-1; i++){
            for(int j=i+1; j<len; j++){
                if(nums[i]+nums[j]== target){
                    out.push_back(i);
                    out.push_back(j);
                    return out;
                }
            }
        }
        return out;
    }
};
```

### #2.两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
> 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
> 输出：7 -> 0 -> 8
> 原因：342 + 465 = 807

+ 提示：算法简单，O(2n)级，注意考虑几个特殊情况就好

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h = new ListNode(0);
        ListNode *p = h;

        int c = 0, val = 0;
        while(l1 && l2){
            val = (l1->val+l2->val+c) % 10;
            ListNode* tmp = new ListNode(val);
            p->next = tmp;
            p = p->next;
            c = (l1->val+l2->val+c) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            val = (l1->val+c) % 10;
            ListNode* tmp = new ListNode(val);
            c=(l1->val+c) / 10;
            p->next = tmp;
            p = p->next;
            l1 = l1->next;
        }

        while(l2){
            val = (l2->val+c) % 10;
            ListNode* tmp = new ListNode(val);
            c =(l2->val+c) / 10;
            p->next = tmp;
            p = p->next;
            l2 = l2->next;
        }

        if(c!=0){
            ListNode* tmp = new ListNode(c);
            p->next = tmp;
        }

        return h->next;
    }
};
```

### #3.最长连续子串
```c++
class Solution {
public:
    bool containKey(string s, char c){
        int len = s.size();
        for(int i=0; i<len; i++){
            if(s[i]==c){
                return true;
            }
        }
        return false;
    }

    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len<=1){
            return len;
        }

        string tmp = ""+s[0];
        int maxCount = 1, count = 1;
        for(int i=1; i<len; i++){
            if(!containKey(tmp, s[i])){
                count++;
                tmp+=s[i];
            } else {
                maxCount = maxCount >= count ? maxCount : count;
                if(i == len-1){
                    return maxCount;
                }else{
                    tmp = ""+s[i];
                    i++;
                }
            }
        }

        return maxCount;
    }
};
```
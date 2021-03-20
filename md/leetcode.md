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
### #15. 三数之和
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        sort(nums.begin(), nums.begin()+size);

        for(int i=0; i<size-2; i++) {
            // 排除 nums[i] 相同的情况
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int j = i+1, k = size-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    k--;
                    continue;
                }
                else if (sum==0) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    result.push_back(tmp);
                }
                // 排除 nums[j] 相同的情况
                int p = j+1;
                while(p<size && nums[j]==nums[p]){
                    p++;
                }
                j = p;
            }
        }
        return result;
    }
};
```
### #19. 删除链表的倒数第 N 个结点
```cpp
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){return NULL;}

        ListNode *fast = head;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        ListNode *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        // 删除头结点
        if(!fast){
            return head->next;
        }
        // 删除其他节点
        ListNode *tmp = slow->next;
        slow->next = tmp->next;
        delete(tmp);
        return head;
    }
};
```
### #29. 两数相除
```c++
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0){ return 0; }
        else if(divisor == 1) {
            return dividend;
        }else if(divisor == -1){
            return (dividend == INT_MIN)?INT_MAX:-dividend;
        }

        long a = dividend;
        long b = divisor;
        int sign = (a>0 && b>0) || (a<0 && b<0);
        a = a>0 ? a : -a;
        b = b>0 ? b : -b;
        long res = div(a, b);
        return sign ? (res>INT_MAX ? INT_MAX : res) : -res;
    }

    long div(long a, long b) {
        if (a<b) { return 0; }
        long tb = b, count = 1;
        while(tb + tb <= a) {
            count += count;
            tb += tb;
        }
        return count + div(a - tb, b);
    }
};
```
### #179. 最大数
```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ret = "";
        int size = nums.size();
        vector<string> result;
        for(int i=0; i<size; i++){
            bool insert = false;
            string numsi = to_string(nums[i]);
            for(int j=0; j<result.size(); j++){
                // 这里参数输入值得思考，判断两个 string 的大小只要拼接一下就好
                if(ifLarge(numsi+result[j], result[j]+numsi)){
                    result.insert(result.begin() + j, numsi);
                    insert = true;
                    break;
                }
            }
            if(!insert)
                result.push_back(numsi);
        }

        for(int i=0; i<size; i++) {
            ret += result[i];
        }
        // 去除开头的 '0'
        int i=0;
        while(ret[i]=='0'){
            i++;
        }
        return ret.substr(i) == ""? "0": ret.substr(i);
    }

    // 输入是两个等长数组，根据 ascii 码判断大小
    bool ifLarge(string s, string t){
        int size = t.size();
        for(int i=0; i < size; i++){
            if(s[i] < t[i]) {return false;}
            else if(s[i] > t[i]) {return true;}
        }

        return true;
    }
};
```
### #274. H 指数
```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        sort(citations.begin(), citations.begin()+size);

        for (int i=0; i<size; i++) {
            int h = size-i;
            if (citations[i] >= h) {
                return h;
            }
        }

        return 0;
    }
};
```
### #443. 压缩字符串
```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
       int n = chars.size();
        int w = 0;
        int b = 0;
        for (int i = 0; i < n; ++i)
        {
            // 如果是最后一个元素 或者 发现非连续元素，我们需要填写数字
            if (i+1 == n || chars[i+1] != chars[i])
            {
                // 设置字符为当前起点的字符
                chars[w++] = chars[b];
                // 判断是否要压缩：出现至少2次才压缩
                if (i > b)
                {
                    string numStr = to_string(i - b + 1);
                    for (char c : numStr)
                    {
                        chars[w++] = c;
                    }
                }
                // 更新起点到下一个开始的位置
                b = i + 1;
            }
        }

        return w;
    }
};
```
### #456. 132模式
```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int size = nums.size();
        int two = INT_MIN; // 保存第二大的值

        for (int i=size-1; i>=0; i--) {
            if (nums[i] >= two) {
                while (!s.empty() && s.top() < nums[i]) {
                    two = s.top();
                    s.pop();
                }
                s.push(nums[i]); // 保存最大的值
            } else {
                // 当 two 是 INT_MIN 时，不可能进入这里
                // 能进入这里的时候已经说明找到局部的最大
                // 和第二大了
                return true;
            }
        }

        return false;
    }
};
```
### #576. 出界的路径数
```cpp
// Solution 1 纯 dp，会超时
const int MOD = 1e9+7;
class Solution {
public:
    int count = 0;
    int findPaths(int m, int n, int N, int i, int j) {
        findAllPaths(m, n, N, i, j);
        return count;            
    }

    void findAllPaths(int m, int n, int N, int i, int j){
        if(N < 0){ return; }
        if(i<0 || i>=m || j<0 || j>=n){
            count= (count+1) % MOD;
            return;
        }
        findAllPaths(m, n, N-1, i-1, j);
        findAllPaths(m, n, N-1, i+1, j);
        findAllPaths(m, n, N-1, i, j-1);
        findAllPaths(m, n, N-1, i, j+1);
    }
};

// Solution 2 dfs + dp
const int MOD = 1e9 + 7;
long dp[55][55][55];
int m, n, limit;
class Solution {
public:
    int count = 0;
    int findPaths(int _m, int _n, int N, int i, int j) {
        memset(dp, -1, sizeof(dp));
        m = _m;
        n = _n;
        limit = N;
        return dfs(i, j, 0);
    }

    long dfs(int i, int j, int s){
        // 次数超了
        if(s > limit){ return 0; }
        // 边界外到边界的点需要 1
        if(i<0 || i>=m || j<0 || j>=n){
            return 1;
        }
        // 还没算过，算一下
        if(dp[i][j][s] == -1)
            dp[i][j][s] = (dfs(i+1, j, s+1) + dfs(i-1, j, s+1) + dfs(i, j+1, s+1) + dfs(i, j-1, s+1)) % MOD;
        return dp[i][j][s];
    }
};
```
### #622. 设计循环队列
```cpp
class MyCircularQueue {
public:
    int *q;
    int cap, size, head, tail;
    MyCircularQueue(int k) {
        cap = k;
        size = 0;
        head = -1;
        tail = -1;
        q = new int[cap];
    }

    bool enQueue(int value) {
        if(isFull()){ return false; }
        tail = (tail+1)%cap;
        q[tail] = value;
        head = (size==0)? tail: head;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){ return false; }
        head = (head+1)%cap;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1: q[head];
    }
    
    int Rear() {
        return isEmpty() ? -1: q[tail];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```
### #713. 乘积小于K的子数组
滑动窗口，详见[链接](https://leetcode-cn.com/problems/subarray-product-less-than-k/solution/cheng-ji-xiao-yu-kde-zi-shu-zu-by-leetcode/)
```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0, size = nums.size();
        
        long s = 1;
        int left = 0;
        for(int right=0; right<size; right++){
            s *= nums[right];
            while(left <= right){
                if(s >= k) {
                    s /= nums[left++];
                }else{
                    count += right-left+1;
                    break;
                }
            }
        }

        return count;
    }
};
```
### #799. 香槟塔
```cpp
class Solution {
public:
    int rows, cols;
    double champagneTower(int poured, int query_row, int query_glass) {
        rows = query_row + 2;
        cols = query_row + 2;
        vector<vector<double> > dp(rows, vector<double>(cols, 0));
        dp[0][0] = poured;
        for(int i=0; i<=query_row; i++){
            for(int j=0; j<=query_row; j++){
                if(dp[i][j]>1){
                    double c = dp[i][j]-1;
                    dp[i][j] = 1.0;
                    dp[i+1][j] += c/2;
                    dp[i+1][j+1] += c/2;
                }
            }
        }
        return dp[query_row][query_glass];
    }
};
```
### #833. 字符串中的查找与替换
```cpp
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int size = indexes.size();
        map<int, int> rep;
        for(int i=0; i<size; i++){
            if(S.substr(indexes[i], sources[i].size()) == sources[i]){
                rep[indexes[i]] = i;
            }
        }

        int offset = 0;
        for(map<int, int>::iterator iter=rep.begin(); iter!=rep.end(); iter++){
            S = S.substr(0, indexes[iter->second]+offset) + targets[iter->second] + S.substr(indexes[iter->second]+offset+sources[iter->second].size());
            offset += targets[iter->second].size() - sources[iter->second].size();
        }

        return S;
    }
};
```
### #855. 考场就座
```cpp
class ExamRoom {
public:
    int  n;
    set<int> s;
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        if(s.empty()){
            s.insert(0);
            return 0;
        }
        int pos = 0, maxSize = 0, pre = -1;
        for(int cur: s) {
            int mid = (cur - pre) / 2;
            if(mid > maxSize) {
                maxSize = mid;
                pos = (pre==-1) ? 0 : pre + mid;
            }
            pre = cur;
        }
        if (n-pre-1 > maxSize) {
            pos = n-1;
        }
        s.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
```
### #923. 三数之和的多种可能
```cpp
const int MOD = 1000000007;
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<int, int> results;
        int size = arr.size();
        for(int i=0; i<size; i++) {
            results[arr[i]]++;
        }

        long count = 0;
        for(int i=0; i<=target/3; i++) {
            for(int j=i; j<=(target-i)/2; j++) {
                int k = target-i-j;
                if(results[i]>0 && results[j]>0 && results[k]>0) {
                    long val = results[i];
                    if (i==j && j==k) {
                        count = (count + val* (val-1) *(val-2)/6 )%MOD;
                    } else if(i==j) {
                        count = (count + val* (val-1) *results[k]/2 )%MOD;
                    } else if(j==k) {
                        count = (count + val * results[j] *(results[j]-1)/2)%MOD;
                    } else {
                        count = (count + val * results[j] * results[k])%MOD;
                    }
                }
            }
        }
        return count;
    }
};
```
### #962. 最大宽度坡
单调递减栈
```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        int size = A.size();
        for(int i=0; i<size; i++){
            if(s.empty() || A[i] < A[s.top()]){
                s.push(i);
            }
        }

        int ans = 0;
        // 大于 ans 是优化的结果, i 比 ans 小的话就没用了
        for(int i=size-1; i>=ans; i--){
            while(!s.empty() && A[i]>=A[s.top()]){
                ans = (ans>i-s.top()) ? ans : i-s.top();
                s.pop();
            }
        }

        return ans;
    }
};
```
### #1015. 可被 K 整除的最小整数
```cpp
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K%2==0||K%5==0) return -1;
        int length = 1, rem = 0;
        while(true){
            rem = (rem*10+1)%K;
            if(rem==0) break;
            length++;
        }
        return length;
    }
};
```
### #1124. 表现良好的最长时间段
```cpp
class Solution {
public:
    int longestWPI(vector<int>& hours) {
    int res = 0, len = hours.size();
        vector<int> dp(len+2,INT_MAX);
        for(int i = 0,j = 0; i < len; ++i){
            j += (hours[i] > 8? 1:-1);
            if(j > 0){
                res = i+1;
            }else{
                res = max(res, i-dp[-j+1]); // 当 j 为负时，减去最前几个总和为 j-1 的就可以使得中间的成为 1，再和 res 比较一下，取最长的
                dp[-j] = min(dp[-j], i); // 记录总和为 -j 的最短前 i 个
            }
        }
        return res;
    }
};
```
### #1191. K 次串联后最大子数组之和
[解析](https://leetcode-cn.com/problems/k-concatenation-maximum-sum/solution/dong-tai-gui-hua-by-jason-2-36mr/)

个人觉得这题的难点在于怎么求解单个数组的最大子数组之和，即解析中提到的`Kadane算法`。
```cpp
const int MOD = 1000000000+7;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int N = arr.size();
        long long ans = 0;
        long long r = 0;
        long long S = 0;
        // 此循环求出了单个数组的最大子数组的值
        for(int i=0; i<N; i++) {
            r = max(r+arr[i],(long long)arr[i]);
            ans = max(ans, r);
            S += arr[i];
        }

        if (k==1) {
            return ans;
        }

        long long ans1 = ans;
        for(int i=0; i<N; i++){
            r = max(r+arr[i], (long long)arr[i]);
            ans1 = max(ans1, r);
        }

        if(k==2){
            return ans1 % MOD;
        }

        return (S > 0) ? ((ans1 % MOD + ((k-2) * S) % MOD) % MOD) : ans1 % MOD;
    }
};
```
### #1239. 串联字符串的最大长度
这道题重在重复字符的判断上，不用哈希表而改用位压缩是一个很大的改进
```cpp
class Solution {
public:
    int maxLength(vector<string>& arr) {
        return dfs(arr, 0, 0);
    }

    int dfs(vector<string>& arr, int index, int m) {
        if(index == arr.size()){return 0;}

        int t = m;
        if(isUnique(arr[index], t)){
            int len1 = arr[index].size() + dfs(arr, index+1, t);
            int len2 = dfs(arr, index+1, m);
            return len1 > len2 ? len1 : len2;
        }
        return dfs(arr, index+1, m);
    }

    bool isUnique(string child, int &t){
        for(char c: child){
            int i = c-'a';
            if(t & (1<<i)){
                return false;
            }
            t |= (1<<i);
        }
        return true;
    }
};
```
### #1361. 验证二叉树
```cpp
class Solution {
public:
    map<int, int> result;
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int sum = 0;
        for(int i=0; i<n; i++){
            if(leftChild[i] > -1){
                if(result[leftChild[i]] > 0){return false;}
                result[leftChild[i]]=1;
                sum += leftChild[i];
            }
            if(rightChild[i] > -1){
                if(result[rightChild[i]] > 0){return false;}
                result[rightChild[i]]=1;
                sum += rightChild[i];
            }
        }
        if(result.size() != n-1){return false;}

        result.clear();
        return dfs(leftChild, rightChild, n*(n-1)/2-sum) && result.size()==n;
    }

    bool dfs(vector<int>& leftChild, vector<int>& rightChild, int index){
        if(index == -1) {return true;}
        if(result[index] > 0){return false;}

        result[index] = 1;

        int left = leftChild[index], right = rightChild[index];
        return dfs(leftChild, rightChild, left) && dfs(leftChild, rightChild, right);
    }
};
```
### #1367. 二叉树中的列表
```cpp
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head){return true;}
        if(!root){return false;}
        if(head->val==root->val){
            return isEqual(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
        }else{
            return isSubPath(head, root->left) || isSubPath(head, root->right);            
        }
    }

    bool isEqual(ListNode*head, TreeNode*root){
        if(!head){return true;}
        if(!root){return false;}
        return head->val==root->val && (isEqual(head->next, root->left) || isEqual(head->next, root->right));
    }
};
```
### #1386. 安排电影院座位
```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b00001111; // 用 bit 来定义，减少内存使用，注意学习
        int mid = 0b11000011;
        int right = 0b11110000;

        map<int, int> output;
        int len = reservedSeats.size();
        for(int i=0; i<len; i++) {
            int row = reservedSeats[i][0], col = reservedSeats[i][1];
            if(col>=2 && col <= 9){
                output[row] |= (1<<(col-2)); // 记录信息
            }
        }

        int count = (n-output.size()) * 2; // 一排能坐两个家庭的
        map<int, int>::iterator iter = output.begin();
        while(iter != output.end()){
            if(((left|iter->second) == left) || ((mid|iter->second) == mid) || ((right|iter->second) == right)){
                count++;
            }
            iter++;
        }
        return count;
    }
};
```
### #1401. 圆和矩形是否有重叠
有理论公式的
```cpp
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double x0 = (x1+x2)/2.0;
        double y0 = (y1+y2)/2.0;

        vector<double> p = {abs(x_center-x0), abs(y_center-y0)};
        vector<double> q = {x2-x0, y2-y0};

        vector<double> u = {max(p[0]-q[0], 0.0), max(p[1]-q[1], 0.0)};
        return u[0]*u[0] + u[1]*u[1] <= radius*radius;
    }
};
```
### #1432. 改变一个整数能得到的最大差值
```cpp
class Solution {
public:
    int maxDiff(int num) {
        string value = to_string(num);
        int i=0, size = value.size(), a, b;
        while(value[i]=='9'){ i++; }
        char s = value[i];
        for(; i<size; i++){
            if(value[i] == s){ value[i] = '9'; }
        }

        for(int i=1; i<size; i++){
            if(value[i] == value[0]){ value[i] = '9'; }
        }
        value[0] = '9';
        a = stoi(value);

        value = to_string(num);
        if(value[0]=='1') {
            int i=0;
            while(value[i]<='1'){ i++; }
            char s = value[i];
            for(; i<size; i++){
                if(value[i] == s) { value[i] = '0';}
            }
        } else {
            char s = value[0];
            for(int i=0; i<size; i++){
                if(value[i] == s){
                    value[i] = '1';
                }
            }
        }
        b = stoi(value);
        return a-b;
    }
};
```
### #1487. 保证文件名唯一
哈希表记录唯一的文件名及k
```cpp
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string, int> filenames;
        vector<string> ret;

        int size = names.size();
        for(int i=0; i<size; i++){
            if(filenames.find(names[i]) == filenames.end()){
                filenames[names[i]] = 1;
                ret.push_back(names[i]);
            }else{
                string newName = names[i] + '('+ to_string(filenames[names[i]]++) + ')';
                while(filenames.find(newName)!= filenames.end()){
                    newName = names[i] + '('+ to_string(filenames[names[i]]++) + ')';                    
                }
                filenames[newName] = 1;
                ret.push_back(newName);
            }
        }

        return ret;
    }
};
```
### #1567. 乘积为正数的最长子数组长度
维护记录最大正数长度和最大负数长度的数组，利用动态规划一次线性遍历得到最大值。[详细解释](https://leetcode-cn.com/problems/maximum-length-of-subarray-with-positive-product/solution/cheng-ji-wei-zheng-shu-de-zui-chang-zi-shu-zu-ch-3/)
```cpp
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int size = nums.size();
        vector<int> pos(size, 0), neg(size, 0);

        if(nums[0]>0){
            pos[0] = 1;
        }else if(nums[0]<0){
            neg[0] = 1;
        }

        int max_s = pos[0];
        for(int i=1; i<size; i++) {
            if(nums[i] > 0){
                pos[i] = pos[i-1]+1;
                neg[i] = (neg[i-1]==0) ? 0 : neg[i-1]+1;
            } else if(nums[i] == 0){
                pos[i] = 0;
                neg[i] = 0;
            } else {
                pos[i] = (neg[i-1]==0) ? 0 : neg[i-1]+1;
                neg[i] = pos[i-1]+1;
            }
            max_s = (max_s>=pos[i])?max_s:pos[i];
        }
        return max_s;
    }
};
```
### #1577. 数的平方等于两数乘积的方法数
没什么特殊方法，想办法减少存储和无效计算就可以了。
用两个哈希表记录每个数组中两两乘积的结果，然后再判断另一个数组中是否存在符合的值
```cpp
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<long, long> t1, t2;
        int s1 = nums1.size(), s2 = nums2.size();
        for(int i=0; i<s1; i++){
            for(int j=i+1; j<s1; j++){
                long tmp = nums1[i];
                t1[tmp*nums1[j]]++;
            }
        }

        for(int i=0; i<s2; i++){
            for(int j=i+1; j<s2; j++){
                long tmp = nums2[i];
                t2[tmp*nums2[j]]++;
            }
        }

        int count = 0;
        for(int i=0; i<s2; i++){
            long tmp = nums2[i];
            if(t1[tmp*tmp] > 0) {
                count+=t1[tmp*tmp];
            }
        }

        for(int i=0; i<s1; i++){
            long tmp = nums1[i];
            if(t2[tmp*tmp] > 0) {
                count+=t2[tmp*tmp];
            }
        }

        return count;
    }
};
```
### #1658. 将 x 减到 0 的最小操作数
方法：滑动窗口
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size(), sum = 0;
        for(int i=0; i<size; i++) {
            sum += nums[i];
        }

        if(sum < x){ return -1; }
        if(sum == x){ return size; }

        int count = sum -x, left=0, right=0, indexs = -1;
        sum = nums[right];
        while(right < size) {
            if(sum > count){
                sum -= nums[left];
                left++;
                continue;
            }
            else if(sum == count){
                indexs = indexs <(right-left+1)? (right-left+1): indexs;
            }
            right++;
            sum+=nums[right];
        }
        return (indexs==-1)?-1:size-indexs;
    }
};
```
### #1705. 吃苹果的最大数目
优先级队列，按照顺序拿拿放放就可以了，主要利用优先级队列优先级最高先出的性质即可。
注意学习这个数据结构的用法。
```cpp
#define PII pair<int, int>
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int maxSum = 0;
        int size = apples.size();
        priority_queue<PII, vector<PII>, greater<PII> > save;
        for(int i=0; i<size || !save.empty(); i++) {
            // 丢掉过期的
            while(!save.empty() && save.top().first == i){
                save.pop();
            }
            // 放入今天的
            if(i<size && apples[i]!=0) {
                save.push(make_pair(i+days[i], apples[i]));
            }
            // 有没过期的话就可以吃
            if(!save.empty()) {
                PII tmp = save.top();
                save.pop();
                tmp.second--;
                maxSum++;
                if(tmp.second>0){
                    save.push(tmp);
                }
            }
        }

        return maxSum;
    }
};
```
### #1744. 你能在你最喜欢的那天吃到你最喜欢的糖果吗
```c++
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<long> target;
        vector<bool> answer;

        int candyTypes = candiesCount.size(), querySum = queries.size();
        target.push_back(0);
        for(int i=1; i<=candyTypes; i++){
            target.push_back(target[i-1] + candiesCount[i-1]);
        }

        for(int i=0; i<querySum; i++){
            long sum = queries[i][2];
            sum *=  queries[i][1]+1;

            if(sum > target[queries[i][0]] && target[queries[i][0]+1]>queries[i][1]) {
                answer.push_back(true);
            }else{
                answer.push_back(false);
            }
        }

        return answer;
    }
};
```
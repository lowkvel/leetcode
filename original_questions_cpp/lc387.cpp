/*
    字符串中的第一个唯一字符

    给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

    示例：
        s = "leetcode"
        返回 0

        s = "loveleetcode"
        返回 2
    
    提示：你可以假定该字符串只包含小写字母。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <unordered_map>
# include <queue>

using namespace std;

class Solution {
public:
    // hash with frequency
    int firstUniqChar(string s) {
        unordered_map<int, int> umap;

        for (char c: s)
            umap[c]++;                          // frequence++

        for (int i = 0; i < s.size(); i++)      // loop through original string
            if (umap[s[i]] == 1)
                return i;

        return -1;
    }

    // hash with index
    int firstUniqChar2(string s) {
        unordered_map<int, int> umap;

        for (int i = 0; i < s.size(); i++)
            if (umap.count(s[i]) == 0)
                umap[s[i]] = i;                             // index recorded
            else
                umap[s[i]] = -1;                            // index removed

        int index = s.size();
        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++) 
            if (it->second != -1 && it->second < index)     // find smallest index
                index = it->second;
        
        if (index == s.size())                              // all repeated elements
            index = -1;

        return index;
    }

    // queue
    int firstUniqChar3(string s) {
        unordered_map<char, int> umap;
        queue<pair<char, int> > q;
        
        for (int i = 0; i < s.size(); ++i) 
            if (umap.count(s[i]) == 0) {                            // unseen char met
                umap[s[i]] = i;                                     // char with index added into map
                q.push(make_pair(s[i], i));                         // unseen <char, index> pushed into queue
            } else {                                                // seen char met
                umap[s[i]] = -1;                                    // char with index set to -1 in map
                while (!q.empty() && umap[q.front().first] == -1)   // pop front elements with index -1 in map from queue (delayed deletion here)
                    q.pop();
            }

        return q.empty() ? -1 : q.front().second;
    }
};

int main() {
    Solution *s = new Solution();

    printf("%d\n", s->firstUniqChar3("leetcode"));
    printf("%d\n", s->firstUniqChar3("loveleetcode"));
}

/*


*/

# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    // map
    char firstUniqChar(string s) {
        unordered_map<char, bool> umap;
        for (char c: s)                             // first loop on s, length could be huge
            umap[c] = (umap.find(c) == umap.end());
        for (char c: s)                             // second loop on s, length could be huge
            if (umap[c])
                return c;
        return ' ';
    }

    // hashed map
    char firstUniqChar(string s) {
        vector<char> keys;
        unordered_map<char, bool> umap;
        for (char c: s) {                           // first loop on s, length could be huge
            if (umap.find(c) == umap.end())
                keys.push_back(c);
            umap[c] = (umap.find(c) == umap.end());
        }
        for (char c: keys)                          // second loop on keys, length is limited to 26 max
            if (umap[c])
                return c;
        return ' ';
    }
};

int main() {

}
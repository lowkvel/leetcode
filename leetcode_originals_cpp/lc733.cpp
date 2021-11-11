/*
    733. 图像渲染

    有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。
    给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。
    为了完成上色工作，
        从初始坐标开始，
        记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，
        接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，
        ……，重复该过程。
        将所有有记录的像素点的颜色值改为新的颜色值。
    最后返回经过上色渲染后的图像。

    示例 1:

    输入: 
        image = [[1,1,1],
                 [1,1,0],
                 [1,0,1]]
        sr = 1, sc = 1, newColor = 2
    输出: 
        [[2,2,2],
         [2,2,0],
         [2,0,1]]
    解析: 
        在图像的正中间，(坐标(sr,sc)=(1,1)),
        在路径上所有符合条件的像素点的颜色都被更改成2。
        注意，右下角的像素没有更改为2，
        因为它不是在上下左右四个方向上与初始点相连的像素点。
    注意:
        image 和 image[0] 的长度在范围 [1, 50] 内。
        给出的初始点将满足 0 <= sr < image.length 和 0 <= sc < image[0].length。
        image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535]内。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/flood-fill
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>
# include <queue>
# include <stack>

using namespace std;

class Solution {
public:
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // right, down, left, up

    // breadth-first search, using queue
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor == newColor)
            return image;

        queue<pair<int, int> > q;                                   // bfs here
        q.push(make_pair(sr, sc));                                  // source point added into queue
        image[sr][sc] = newColor;                                   // change source point's color
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + direction[i][0];
                int ny = y + direction[i][1];
                if (nx >= 0 && nx < image.size() &&
                    ny >= 0 && ny < image[0].size() &&
                    image[nx][ny] == originalColor) {
                        q.push(make_pair(nx, ny));                  // new point added into queue
                        image[nx][ny] = newColor;                   // set new point to visited
                    }
            }
        }

        return image;
    }

    // breadth-first search, using recursion
    vector<vector<int> > floodFill2(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor == newColor)
            return image;
        floodFill2_bfs(image, sr, sc, originalColor, newColor);
        return image;
    }

    void floodFill2_bfs(vector<vector<int> > &image, int x, int y, int oc, int nc) {

    }

    // depth-first search, using stack
    vector<vector<int> > floodFill3(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor == newColor)
            return image;

        stack<pair<int, int> > s;                                   // dfs here
        s.push(make_pair(sr, sc));
        image[sr][sc] = newColor;
        while (!s.empty()) {
            int x = s.top().first;
            int y = s.top().second;
            s.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + direction[i][0];
                int ny = y + direction[i][1];
                if (nx >= 0 && nx < image.size() &&
                    ny >= 0 && ny < image[0].size() &&
                    image[nx][ny] == originalColor) {
                        s.push(make_pair(nx, ny));
                        image[nx][ny] = newColor;
                    }
            }
        }

        return image;
    }

    // depth-first search, using recursion
    vector<vector<int> > floodFill4(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor == newColor)
            return image;
        floodFill4_dfs(image, sr, sc, originalColor, newColor);
        return image;
    }

    void floodFill4_dfs(vector<vector<int> > &image, int x, int y, int oc, int nc) {
        if (image[x][y] == oc)
            image[x][y] = nc;
            for (int i = 0; i < 4; i++) {
                int nx = x + direction[i][0];
                int ny = y + direction[i][1];
                if (nx >= 0 && nx < image.size() &&
                    ny >= 0 && ny < image[0].size() &&
                    image[nx][ny] == oc) 
                        floodFill4_dfs(image, nx, ny, oc, nc);
            }
    }
};

int main() {
    Solution *s = new Solution();

    vector<vector<int> > v;
    int a1[3] = {1,1,1}; vector<int> v1(a1, a1 + 3); v.push_back(v1);
    int a2[3] = {1,1,0}; vector<int> v2(a2, a2 + 3); v.push_back(v2);
    int a3[3] = {1,0,1}; vector<int> v3(a3, a3 + 3); v.push_back(v3);
    
    s->floodFill(v, 1, 1, 2);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d, ", v[i][j]);
        printf("\n");
    }
}
/*
    旋转数组的最小数字

    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
    输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
    例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

    示例 1：
        输入：[3,4,5,1,2]
        输出：1
    
    示例 2：
        输入：[2,2,2,0,1]
        输出：0

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() == 0)
            return 0;

        int min = numbers[0];
        for (int i = 0; i < numbers.size(); i++)
            if (numbers[i] < min)
                min = numbers[i];

        return min;
    }

    // binary search
    /*
        我们考虑搜索范围中的最后一个元素 x：
            在最小值右侧的元素，它们的值一定都小于等于 x，
            在最小值左侧的元素，它们的值一定都大于等于 x。
    */
    int minArray2(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] < numbers[right])      // right hand side is discarded
                right = mid;
            else if (numbers[mid] > numbers[right]) // left hand side is discarded 
                left = mid + 1;
            else                                    // one element to the left
                right = right - 1;
        }

        return numbers[left];
    }
};

int main() {

}
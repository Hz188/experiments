/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        back_track_2(nums, 0, path, res);
        // back_track(nums, 0, path, res);
        return res;
    }

    //答案视角
    void back_track(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);

        for(int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            back_track(nums, i+1, path, res);
            path.pop_back();
        }
    }
    //输入视角
    void back_track_2(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res){
        if(start == nums.size()) {
            res.push_back(path);
            return;
        }

        back_track_2(nums, start+1, path, res);//没选nums[start]
        path.push_back(nums[start]);
        back_track_2(nums, start+1, path, res);//选了nums[start]
        path.pop_back();
    }
    
};
// @lc code=end


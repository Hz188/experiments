/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class RandomizedSet {
private:
    vector<int> nums{};     // 存储元素的值
    unordered_map<int, int> val_to_index{};     // 记录每个元素对应在 nums 中的索引

public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        // 若 val 已存在，不用再插入
        if (val_to_index.count(val)) {
            return false;
        }
        // 若 val 不存在，插入到 nums 尾部，
        // 并记录 val 对应的索引值
        val_to_index[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        // 若 val 不存在，不用再删除
        if (!val_to_index.count(val)) {
            return false;
        }
        // 先拿到 val 的索引
        int index = val_to_index[val];
        // 将最后一个元素对应的索引修改为 index
        val_to_index[nums.back()] = index;
        // 交换 val 和最后一个元素
        swap(nums[index], nums.back());
        // 在数组中删除元素 val
        nums.pop_back();
        // 删除元素 val 对应的索引
        val_to_index.erase(val);
        return true;
    }
    
    int getRandom() {
        // 随机获取 nums 中的一个元素
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end


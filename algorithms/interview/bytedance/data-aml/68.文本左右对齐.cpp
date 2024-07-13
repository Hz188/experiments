/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<pair<vector<string>, int>> lines;
        vector<string> line;
        int cnt = 0;
        for (auto& word: words) {
            if(cnt + line.size() + word.size() > maxWidth) {
                lines.emplace_back(line, cnt);
                line.clear();
                cnt = 0;
            }
            cnt += word.size();
            line.push_back(word);
        }
        lines.emplace_back(line, cnt);
        vector<string> ans;
        for(int i = 0; i < lines.size(); ++i) {
            auto& [line, total] = lines[i];
            string str{};
            if(i == lines.size() - 1 || line.size() == 1) {
                for(auto& word: line) {
                    str += str.empty() ? word : ' ' + word;
                }
                str += string(maxWidth - str.length(), ' ');
            } else {
                int empty_size = maxWidth - total;
                int gap_size = empty_size / (line.size() - 1);
                int k = empty_size % (line.size() - 1);
                for(int j = 0; j < line.size(); ++j) {
                    if(j == line.size() - 1) str += line[j];
                    else str += line[j] + string(gap_size, ' ');
                    if(j < k) str += ' ';
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};
// @lc code=end

/*
    模拟题：实现题目的描述
        首要任务就是步骤拆解，将混沌的自然语言做整理
        其中的核心能力：将问题表述分步骤拆解 step1 -> step2 -> ... 
    step1：将单词分成多行，每行单词加间隔不超过maxWidth
        这种将一个数组分成多组的操作，有一个通用的流程
            init group, groups  初始化结果、临时组
            init condition      初始化分割条件
            for every element:  遍历每个元素
                if judge(group, condition, element): 判断加入这个元素后是否满足分割条件
                    put group into groups 满足则加入结果，重置临时组，重置条件
                    reset group, condition
                put element into group 当前元素放入临时组
                change condition by element 改变条件
            put group into groups 将还没处理完的临时组放入结果
        这段伪代码非常通用，适用于所有按顺序分组的过程
    step2：遍历分完组后的结果，对每一组分情况进行填充，从易到难三种情况
        1. 最后一行，左对齐填充即可
        2. 只有一个单词，因为没有间隔，所以填充方式还是左对齐
        3. 多个单词，填充方式为均匀分配空格
            要想均匀：需要知道空格的数量和间隔的数量
                empty = maxWidth - 单词长度和
                gaps = 单词个数-1
                gap = empy / gap 除不尽的话，余数k就是前面k个额外多一个空格


        

*/
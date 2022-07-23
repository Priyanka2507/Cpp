#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int> &nums, vector<vector<int>> &ans, int i, int j, vector<int> &util)
{
    if (i == nums.size())
    {
        ans.push_back(util);
        util.pop_back();
        return;
    }
    util.push_back(nums[i]); //include current
    subsets(nums, ans, i + 1, j + 1, util);
    subsets(nums, ans, i + 1, j, util); //do not include current
}

int main()
{
    vector<int> nums{1, 2, 3,4,5};
    vector<vector<int>> ans;
    vector<int> util;
    subsets(nums, ans, 0, 0, util);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
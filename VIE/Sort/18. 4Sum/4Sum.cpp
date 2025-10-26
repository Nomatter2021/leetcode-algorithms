class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end()); // Sắp xếp mảng
        int n{static_cast<int>(nums.size())}, l, r; // Tạo các biến vị trí trên mảng
        long long int T, need, Target{target}; // Tạo các biến tính toán
        std::vector <std::vector <int>> rs; // Tạo vector trả kết quả
        std::vector <int> sum; // Tạo vector chứa bộ 4
        for(int i{0}; i < n - 3; i++) // Vòng lặp đầu tiên cố định i
        {
            if(i > 0 && nums[i] == nums[i - 1]) // Điều kiện bỏ trùng lặp
            {
                continue;
            };
            for(int j{i + 1}; j < n - 2; j++) // Vòng lặp thứ 2 cố định j đây là lúc biến 4Sum thành 3Sum
            {
                if(j > i + 1 && nums[j] == nums[j - 1]) // Điều kiện bỏ trùng lặp
                {
                    continue;
                };
                l = j + 1;
                r = n - 1;
                need =  Target - (nums[i] + nums[j]); // Tạo vị trí tương đối giữa target và 2 đầu mút
                while(l < r) // Bắt đầu thuật toán 3Sum
                {
                    T = nums[l] + nums[r];
                    if(T > need)
                    {
                        --r;
                    }
                    else if(T < need)
                    {
                        ++l;
                    }
                    else
                    {
                        sum.push_back(nums[i]);
                        sum.push_back(nums[j]);
                        sum.push_back(nums[l]);
                        sum.push_back(nums[r]);
                        rs.push_back(sum);
                        sum.clear();
                        ++l;
                        --r;
                        while(l < r && nums[l] == nums[l - 1])
                        {
                            ++l;
                        };
                    };
                };
            };
        }
        return rs; // Trả kết quả
    }
};
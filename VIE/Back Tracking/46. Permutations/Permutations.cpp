class Solution {
public:

    std::vector<std::vector<int>> BackTracking (std::vector<int>& nums, std::vector<std::vector<int>>& rs, int n) // Hàm đệ quy
    {
        if(n == 0) // Điều kiện dừng
        {
            rs.push_back(nums);
            return rs;
        }
        else
        {
            for(int i{0}; i < n; i++) // Điều kiện phân nhánh
            {
                std::swap(nums[i], nums[n]); // 
                Solution::BackTracking(nums, rs, n - 1); // Xuống tầng thứ n - 1
                std::swap(nums[i], nums[n]);
            };
        }
        return Solution::BackTracking(nums, rs, n - 1); // Truy cập nhánh n - 1
    };

    vector<vector<int>> permute(vector<int>& nums) { // Hàm chính
        std::sort(nums.begin(), nums.end()); // Sắp xếp theo chiều tăng dần để làm dãy đơn điệu
        std::vector<std::vector<int>> rs; // Khởi tạo vector trả kết quả
        int n{static_cast<int>(nums.size() - 1)}; // Khởi tạo biến n là độ dài của dãy nums
        Solution::BackTracking(nums, rs, n); // Bắt đầu đệ quy
        return rs; // Trả kết quả
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int rs, T, n{static_cast<int> (nums.size())}, l, r; // Khai báo các biến cần dùng
        std::sort(nums.begin(), nums.end()); // Sắp xếp mảng
        rs = nums[0] + nums[1] + nums[2]; // Gán giá trị đầu tiên dúng để so sánh
        for(int i{0}; i < n - 2; ++i)
        {
            l = i + 1;
            r = n - 1;
            if(i > 0 && nums[i] == nums[i - 1]) // Loại bỏ trùng lặp ở i
            {
                continue;
            };
            while(l < r) // Tạo vòng lặp để di chuyển l và r
            {
                T = nums[i] + nums[l] + nums[r]; // Tính tổng 3 số ở vị trí i, l, r
                if(T - target == 0) // So sánh nếu T là target
                {
                    rs = T;
                    break;
                }
                else if(std::abs(T - target) < std::abs(rs - target)) // So sánh khoảng cách giữa rs và T với target
                {
                    rs = T;
                }
                else if(T - target < 0) // Ước lượng khoảng cách giữa T với target
                {
                    ++l;
                }
                else // Ước lượng khoảng cách giữa T với target
                {
                    --r;
                };
            };
            if(rs - target == 0) // Ngắt sớm nếu tìm được target
            {
                break;
            };
        };
        return rs; // Trả kết quả
    };
};
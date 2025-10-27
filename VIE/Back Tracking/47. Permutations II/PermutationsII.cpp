class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // Sắp xếp mảng tăng dần
        std::vector<std::vector <int>> rs; // Khởi tạo vector dùng để trả kết quả
        int n{static_cast<int>(nums.size() - 1)}, i{n - 1}, p; // Khởi tạo các biến cần thiết
        rs.push_back(nums); // Nhận hoán vị đầu tiên là chính dãy số
        if(n == 0) // Điều kiện đặc biệt khi dãy số chỉ có 1 số
        {
            return rs;
        };
        if(n == 1) // Điều kiện đặc biệt khi dãy số có 2 số
        {
            if(nums[0] == nums[1]) // 2 số giống nhau chỉ không sinh ra hoán vị mới
            {
                return rs;
            }
            else // 2 số khác nhau tạo thêm 1 hoán vị
            {
                std::swap(nums[0], nums[1]);
                rs.push_back(nums);
                return rs;
            }; 
        };
        while(i >= 0) // Dùng thuật toán sinh hoán vị tiếp theo theo thứ tự từ điển
            {
                if(nums[i] < nums[i + 1])
                {
                    for(int j{n}; j > i; j--)
                        {
                            if(nums[j] > nums[i])
                            {
                                std::swap(nums[i], nums[j]);
                                break;
                            };
                        };
                    std::reverse(nums.begin() + i + 1, nums.end());
                    rs.push_back(nums);
                    i = n - 1; // Hoàn trả i về ban đầu để bắt đầu vòng sinh hoán vị tiếp theo
                }
                else // Giảm i để tạo điều kiện kết thúc lặp while và i = 0 khi dãy đã đơn điệu không còn điểm gãy
                {
                    --i;
                };
            };
        return rs; // Trả kết quả
    }
};
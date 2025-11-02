    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            std::vector <int> rs(2, -1); // Tạo vector trả kết quả
            int l{0}, r{static_cast<int>(nums.size()) - 1}, m, p{-1}; // Các biến cần thiết
            if(nums.size() == 0) return rs; // Điều kiện đặc biệt nếu mảng rổng thì trả kết quả -1, -1
            if(nums.size() == 1) // Điều kiện đặc biệt nếu mảng chỉ có 1 độ dài
            {
                if(nums[0] == target)
                {
                    rs.clear();
                    rs.emplace_back(0);
                    rs.emplace_back(0);
                    return rs;
                };
                return rs;
            }
            while(l <= r) // Duyệt mảng
            {
                m = (r+l)/2;
                if(nums[m] == target) // Điều kiện dừng khi tìm được target
                {
                    p = m;
                    break;
                }
                if(m > 0 && nums[l] <= target && nums[m] > target) r = m - 1; // Điều kiện nếu target nằm trong mảng bên trái thì giảm biên để loại bỏ mảng bên phải
                else l = m + 1; // Ngược lại nếu target nằm bên phải thì tăng biên bên trái để loại bỏ mảng bên trái
            }
            if(p != - 1) // Nếu p khác -1 nghĩa là tìm được target nên dùng 2 con trỏ để mở rộng phạm vi từ vị trí m để tìm đầu vào cuối xuất hiện target
            {
                rs.clear();
                l = p;
                r = p;
                while(l > 0) // Tìm biên bên trái
                {
                    if(nums[l] == nums[l - 1]) --l;
                    else break;
                };
                while(r + 1 < static_cast<int>(nums.size())) // Tìm biên bên phải
                {
                    if(nums[r] == nums[r + 1]) ++r;
                    else break;
                };
                rs.emplace_back(l);
                rs.emplace_back(r);
            };
            return rs; // Trả kết quả.
        }
    };
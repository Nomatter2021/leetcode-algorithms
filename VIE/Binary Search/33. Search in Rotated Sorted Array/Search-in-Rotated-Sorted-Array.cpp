class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l{0}, r{static_cast<int>(nums.size()) - 1}, m; //Tạo các biến cần thiết
        while(l <= r) //Lặp duyệt mảng
        {
            m = (l+r)/2; // Vị trí giữa mảng để chia mảng thành 2 mảng con
            if(nums[m] == target) return m; // Điều kiện ngắt sớm nếu giá trị tại m = target
            if(nums[l] <= nums[m]) // Xác định mảng bên phải là mảng thuận
            {
                if(nums[l] <= target && nums[m] > target) r = m - 1; // Target nằm trong mảng này thì giảm bên biên trái để bỏ toàn bộ mảng con bên trái
                else l = m + 1; // Ngược lại thì tăng biên bên phải để bỏ toàn bộ mảng con bên phải
            }
            else // Mảng bên trái là mảng thuận
            {
                if(nums[m] < target && nums[r] >= target) l = m + 1; // Target nằm trong mảng này thì tăng biên bên phải để bỏ toàn bộ mảng con bên phải
                else r = m - 1; // Ngược lại giảm biên bên trái để bỏ toàn bộ mảng con bên trái
            };
        };
        return -1; // Không tìm được nên trả -1
    }
};
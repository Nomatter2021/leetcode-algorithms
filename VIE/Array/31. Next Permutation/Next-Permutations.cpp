class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n{static_cast<int>(nums.size()-1)}, i{n - 1}, j{n}; // Khởi tạo biến cần thiết
        if(n == 1) // Ngắt sớm ở trường hợp đặc biệt chỉ có 2 số
        {
            std::reverse(nums.begin(), nums.end());
        }
        else
        {
            for(i; i >= 0; i--) // Khởi tạo vòng lặp i di chuyển từ phải qua trái để tìm cặp số mà ở đó số bên trái bé hơn số bên phải
            {
                if(nums[i] < nums[i + 1])
                {
                    for(j; j > i; j--) // Khởi tạo vòng lặp j để tìm tiếp số đầu tiên trong các dãy số bên phải lớn hơn số vừa tìm được
                    {
                        if(nums[i] < nums[j])
                        {
                            std::swap(nums[i], nums[j]); // Đổi vị trí 2 số cho nhau
                            break;
                        };
                    };
                    std::reverse(nums.begin() + i + 1, nums.end()); / Đảo ngược toàn bộ dãy số từ vị trí i + 1
                    break;
                };
                if(i == 0) // Điều kiện đặt biệt nếu i == 0 nghĩa là đây là hoán vị nhỏ nhất nên đảo ngược toàn bộ dãy số.
                {
                    std::reverse(nums.begin(), nums.end());
                };
            };
        };
    };
};
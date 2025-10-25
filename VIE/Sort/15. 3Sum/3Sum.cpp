class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // Sắp xếp mảng nums
        std::vector <std::vector <int>> rs; // Tạo vector trả kết quả
        std::vector <int> sum; // Khởi tạo vector chứa kết quả tổng 3 số = 0
        long long int T{0}; // Khởi tạo biến chứa kết quả tổng 3 số
        for(int i{0}; i < nums.size() - 2; ++i) // Tạo vòng lặp duyệt mảng
        {
            int l{i + 1}; // Đầu mút trái
            int r{static_cast<int>(nums.size()) - 1}; // Đầu mút phải
            if(nums[i] > 0) // Ngắt vòng lặp sớm
            {
                break;
            }
            else if(i >= 1 && nums[i] == nums[i - 1]) // Tìm giá trị bị trùng của i
            {
                continue;
            }
            else
            {
                while(l < r) // Vòng lặp di chuyển l và r để tìm tổng 0
                {
                    T = nums[i] + nums[l] + nums[r];
                    if(T < 0) // Di chuyển l nếu tổng < 0
                    {
                        ++l;
                    }
                    else if (T > 0) // Di chuyển l nếu tổng > 0
                    {
                        --r;
                    }
                    else // Nhận kết quả
                    {
                        sum.push_back(nums[i]);
                        sum.push_back(nums[l]);
                        sum.push_back(nums[r]);
                        rs.push_back(sum); // push back kết quả vào vector dùng để return kết quả
                        ++l;
                        --r;
                        sum.clear(); // xóa dữ liệu cũ chuẩn bị cho vòng dữ liệu mới
                        while(l < r && nums[r] == nums[r + 1]) // Tìm giá trị bị trùng của r
                        {
                            --r;
                        };
                    };
                };
                    while(l < r && nums[l] == nums[l - 1]) // Tìm giá trị bị trùng của l
                    {
                        ++l;
                    };

            };
        };
        return rs; // Trả kết quả
    };

};

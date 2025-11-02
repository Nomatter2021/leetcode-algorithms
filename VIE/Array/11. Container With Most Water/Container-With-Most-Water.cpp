class Solution {
public:
    int maxArea(vector<int>& height) {
        int rs{0}, l{0}, r{static_cast<int>(height.size()) - 1}; // Khai báo các biến cần thiết
        while(l < r) // Tạo lặp để duyệt height
        {
            if(height[l] < height[r]) // Tìm bên nào nhỏ hơn
            {
                if(rs < height[l]*(r-l)) rs = height[l]*(r-l); // Lưu kết quả tốt hơn
                ++l; // Di chuyển l về phải
            }
            else
            {
                if(rs < height[r]*(r-l)) rs = height[r]*(r-l); // Lưu kết quả tốt hơn
                --r; // Di chuyển r về trái            };
        };
        return rs; // Trả kết quả
    }
};
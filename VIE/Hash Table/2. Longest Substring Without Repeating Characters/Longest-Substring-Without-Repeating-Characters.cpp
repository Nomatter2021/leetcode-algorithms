class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector <int> HashT(256, -1); // Tạo bảng băm
        int rs{0}, i{0}; // Các biến cần thiết
        unsigned char c; // Khóa của bảng băm
        for(int j{0}; j < static_cast<int>(s.size()); j++)
        {
            c = static_cast<unsigned char>(s[j]); // Băm khóa
            if(HashT[c] >= i) i = HashT[c] + 1; // Kiểm tra lần gặp cuối và lần gặp hiện tại nằm trong khoảng [i, j]. Nếu lần gặp hiện tại > i nghĩa là đã từng chạm mặt nhảy cóc đến vị trí lần cuối cùng gặp + 1
            HashT[c] = j; // Ghi nhận lần gặp hiện tại
            rs = std::max(rs, j - i + 1); //Lấy độ dài chuỗi ký tự hiện tại so với chuỗi trước đó
        };
        return rs; // Trả kết quả
    };
};
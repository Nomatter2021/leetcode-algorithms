class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const std::string HashT[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // Tạo bảng băm tĩnh
        std::vector <std::string> rs, rsn; // Vector thao tác với kết quả
        int n{static_cast<int>(digits.size())}, ds, d_point; // Biến độ dài và key
        for(int i{0}; i < n; i++) // Duyệt input digits
        {
            d_point = static_cast<int>(digits[i] - '0'); // Cast char sang int
            ds = static_cast<int>(HashT[d_point].size()); // Lấy độ dài value trong bảng băm
            if(i == 0) // Tầng đầu tiên
            {
                rs.reserve(ds);
                for(char c: HashT[d_point])
                {
                    rs.emplace_back(std::string(1, c));
                };
                continue;
            };
            for(std::string j: rs) // Bắt đầu duyệt đến tầng 2 -> độ dài chuỗi digits
            {
                rsn.reserve(ds*static_cast<int>(rs.size())); // Mở rộng độ dài vector
                for(char c: HashT[d_point])
                {
                    rsn.emplace_back(j + std::string(1, c)); // Thêm kết quả vào chuỗi tạm thời
                };
            };
            rsn.swap(rs); // swap 2 vector với nhau
            rsn.clear(); // Dọn vector kết quả tạm thời để mở vòng với
        };
        return rs; // Trả kết quả
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n{static_cast<int>(s.size())}, l, r, len{1}, p{0}; // Khai báo các biến cần thiết
        if(n == 1) return s; // Trường hợp đặc biệt chuỗi 1 ký tự
        if(n == 2) // Trường hợp đặc biệt chuỗi 2 ký tự
        {
            if(s[0] != s[1]) return s.substr(0, 1);
            else return s;
        };
        for(int i{0}; i <= n - 1; i++) // Dò đối xứng qua tâm
        {
            l = i - 1;
            r = i + 1;
            while(l >= 0 && r < n) // Mở rộng chuỗi đối xứng
            {
                if(s[l] != s[r]) break;
                if(s[l] == s[r] && r - l >= len)
                {
                    len = r - l + 1;
                    p = l;
                }
                --l;
                ++r;
            };
        };
        for(int i{0}; i <= n - 1; i++) // Dò đối xứng qua trục dựa trên len đã tìm được bằng đối xứng qua tâm
            {
                if(i + (len/2) > n) break; // Loại bỏ những chuỗi gần biên không có cơ hội lớn hơn độ dài hiện tại
                l = (i + i + len)/2;
                r = (i + i + len)/2 + 1;
                while(l >= 0 && r < n) // Mở rộng chuỗi
                    {
                        if(s[l] != s[r]) break;
                        if(s[l] == s[r] && r - l >= len)
                        {
                            len = r - l + 1;
                            p = l;
                            i = 0;
                        };
                        --l;
                        ++r;
                    };
            };
        return s.substr(p, len); // Trả kết quả
    };
};
    
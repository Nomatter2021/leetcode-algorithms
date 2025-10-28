class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      std::vector<std::vector<std::string>> rs; // Tạo vector trả kết quả
        std::unordered_map<std::string, std::vector<std::string>> HashT; // Tạo bảng băm
        std::string key; // Tạo key
        for(auto& i: strs) // Duyệt vector strs
            {
                key = i;
                std::sort(key.begin(), key.end()); // Băm key
                HashT[key].emplace_back(i); // Nhóm kết quả
            };
        for(auto& i : HashT) // Di chuyển kết quả từ bảng băm sang vector trả kết quả
            {
                rs.emplace_back(std::move(i.second));
            };
        return rs; // Trả kết quả
    };
};

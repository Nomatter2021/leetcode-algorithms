# 47. Permutations II
## Đề bài
Cho 1 dãy số nums có thể xuất hiện giá trị lặp, hãy trả về các hoán vị và các hoán vị không thể lặp lại nhau.

*Ví dụ 1:*

Đầu vào: nums = [1,1,2]

Đầu ra: [[1,1,2], [1,2,1], [2,1,1]]

*Ví dụ 2:*

Đầu vào: nums = [1,2,3]

Đầu ra: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*Giới hạn:*
- 1 <= nums.length <= 8
- -10 <= nums[i] <= 10

## Giải thích thuật toán

Bài toán này ta có thể sử dụng thuật toán đệ quy sau đó cắt các nhánh xuất hiện trùng lặp, tuy nhiên như bài Permutations mình có nói là đệ quy tốn chi phí bộ nhớ và thời gian quá nhiều.

Nên bài này mình sẽ sử dụng thuật toán phát sinh hoán vị theo thứ tự từ điển để tối ưu thời gian thực thi cũng như bộ nhớ. Bạn có thể tham khảo thuật toán này dưới link tham khảo.

Bước 1: Khởi tạo các biến cần thiết

Bước 2: Ghi nhận dãy số ban đầu như hoán vị đầu tiên.

Bước 3: Xét điều kiện đặc biệt đầu tiên n == 0.

Bước 4: Xét điều kiện đặc biệt thứ 2 là n == 1.

Bước 5: Dùng thuật toán sinh hoán vị theo thứ tự từ điển để tạo toàn bộ hoán vị khả thi.

Bước 6: Trả kết quả.

## Kết quả LeetCode

![Kết quả submissions](./PermutationsII.jpg)

## Thảo luận

Thuật toán này có độ phức tạp O(n*n!) và cho ra chi phí bộ nhớ và tốc độ xử lý đạt mức lý tưởng.

## Tham khảo

[Source Code C++](./Permutations.cpp)

[Bài 47. Permutations II](../46.%20Permutations/Permutations-algorithms.md)

[Bài 31. Next Permutation](../../Array/31.%20Next%20Permutation/Next-Permutations-algorithms.md)


-Chúc các bạn thành công-

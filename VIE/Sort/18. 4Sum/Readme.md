# 18. 4Sum
## Đề bài

Cho trước một day số nums có n số nguyên, hãy trả lại kết quả những bộ tứ độc nhất gồm [nums[a]], [nums[b]], [nums[c]], [nums[d]] với:

- 0 <= a, b, c, d < n

- a, b, c và d không trùng lặp vị trí.

- nums[a] + nums[b] + nums[c] + nums[d] == target

Ví dụ 1:

Đầu vào: nums = [1,0,-1,0,-2,2], target = 0

Đầu ra: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Ví dụ 2:

Đầu vào: nums = nums = [2,2,2,2,2], target = 8

Đầu ra: [[2,2,2,2]]

Giới hạn:

- 1 <= nums.length <= 200

-10^9 <= nums[i] <= 10^9

10^9 <= target <= 10^9

## Phân tích dữ liệu

Bài toán 4Sum có thể xem là bài toán biến thể của 3Sum với cấu trúc dữ liệu và điều kiện ràng buộc đầu vào giống nhau, chỉ khác ở chỗ thay vì có 3 biến a, b, c thì ta lại thêm 1 biến d.

Do sự tương đồng về cấu trúc nên ta có thể dùng phương pháp giải của bài 3Sum bằng cách nhóm a và b thành 1 rồi c và d lại rồi chuyển thành dạng 3Sum.

Ta có: a + b + c + d = target (1)

Gọi: k = a + b (2)

với a và b là hằng số

(1)(2) => k + c + d = target (3)

Gọi: Need = c + d (4)

(3)(4) => k + Need = target

=> Need = target - k (5).

Gọi T = c + d (6)

Với c và d là các biến thay đổi được.

(4)(5)(6) => a + b + c + d = target khi T = need = c + d (7)

(7) => c = need - d (8)

(8) => c là phần cần bù cho d để đạt need, tương tự như 3Sum ta đặt d ở cuối dãy và c ở đầu dãy để tạo không gian tối ưu ccho c bù phần d còn thiếu.

- Nếu T > need nghĩa là phần bù bị lố nên ta hạ d để tạo thêm không gian.
- Nếu T < need nghĩa là phần bù không đủ nên ta tăng thêm d.
- nếu T == need ghi nhận đây là cái cần tìm

## Giải thích thuật toán

Bài toán 4Sum có thể xem là một dạng nâng cao của bài toán 3Sum. Tại sao tôi lại nói vậy? Bởi vì chúng ta có thể giải quyết bài toán bằng cách cố định sô a và duyệt 3Sum với bộ 3 b, c, d. 

Bước 1: Sắp xếp mảng đã cho theo thứ tự tăng dần.

Bước 2: Tạo các biến vị trí trên mảng gồm n (độ dài mảng), l (đầu mút trái), r (đầu mút phải).

Bước 3: Tạo các biến tính toán need = targer - (nums[i] + nums[j]), T = nums[l] + nums[r], Target (dùng để ép target ban đầu về long long int).

Bước 4: Tạo vector rs dùng để trả kết quả.

Bước 5: Tạo vector sum để chứa bộ 4.

** Trong vòng lặp for (i) **

Bước 6: Tạo điều kiện loại bỏ trùng lặp với i > 0 và nums[i] == nums[i - 1]

** Trong vòng lặp for (j) **

Bước 7: Dùng thuật toán 3Sum để tìm các cặp bộ 3 có tổng == target (Lưu ý phải di chuyển đầu mút dựa trên khoảng cách giữa T và need, tham khảo thuật toán 3Sum ở link trong mục tham khảo).

Bước 8: Trả kết quả.

## Kết quả LeetCode
![Kết quả submissions](./4Sum.jpg)

## Thảo luận
Thuật toán này có độ phức tạp O(n^3) nhanh hơn các sử dụng 4 vòng lặp nhưng vẫn đảm bảo được kết quả cuối cùng.


## Tham khảo

[Source code C++](./4Sum.cpp)

[Thuật toán 3Sum](../15.%203Sum/Readme.md)

[Sourcode 3Sum C++](../15.%203Sum/3Sum.cpp)


-Chúc các bạn thành công-






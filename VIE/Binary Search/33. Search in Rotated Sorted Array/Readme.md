# 33. Search in Rotated Sorted Array

## Đề bài

Mảng nums ban đầu được sắp xếp tăng dần, sau đó có thể bị xoay tại một vị trí nào đó.
Nhiệm vụ: tìm vị trí của phần tử target trong mảng đã xoay (nếu có), nếu không thì trả về -1.
Yêu cầu: thuật toán phải chạy trong thời gian O(log n).

Ví dụ 1:

Đầu vào: nums = [4,5,6,7,0,1,2], target = 0

Đầu ra: 4

Ví dụ 2:

Đầu vào: nums = [4,5,6,7,0,1,2], target = 3

Đầu ra: -1

Ví dụ 3:

Đầu vào: nums = [1], target = 0

Đầu ra: -1

Giới hạn:

- 1 <= nums.length <= 5000

- -10^4 <= nums[i] <= 10^4

- Tất cả giá trị của nums không bị lặp

- nums là mảng tăng dần và có khả năng có vị trí bị xoay chiều

- -10^4 <= target <= 10^4


## Giải thích thuật toán

Bài toán tìm số trong dãy không khó có thể nó đây là bài cơ bản khi ta học về vòng lặp, tuy nhiên thứ nâng tầm bài toán lại yêu cầu độ phức tạp O(logn) bởi duyệt tuần tự độ phức tạp là O(n) luôn > O(logn).

Để giải quyết vấn đề độ phức tạp ta có thể dùng kỹ thuật duyệt nhị phân, nhị phân là 0 hoặc 1 (true hoặc false) nó là cách ta chia dãy cần duyệt thành 2 phần và xét điều kiện để loại bỏ 1 nữa và nhận 1 nữa kết quả.

Đối với bài toán này có yếu tố, có thể xuất hiện đoạn bị xoay chiều nghĩa là đầu mảng < hơn cuối mảng. Dựa trên dữ kiện này ta có thể xác định điều kiện loại bỏ 1 nữa còn lại đó là trong mảng tăng dần không bị đảo ngược, mảng này có chứa target hay không? Nếu không có thì loại bỏ và tiếp tục chia đôi mảng còn lại và lặp lại cho đến khi không lặp lại được nữa.

Bước 1: Tạo 3 biến gồm: Biên bên phải, biên bên trái, vị trí giữa.

Bước 2: Tạo lặp l < để bắt đầu duyệt mảng

*Trong lặp while*

Bước 3: Xét mảng con bên phải hay là bên trái là mảng thuận chiều.

Bước 4: Bên trong mảng thuận chiều xác định target có bên trong hay không nếu không có thì target nằm trong mảng còn lại.

Bước 5: Loại bỏ mảng dựa trên việc dịch chuyển biên.

Bước 6: Trả kết quả

## Kết quả leetcode

![Kết quả submissions](./Container-With-Most-Water.jpg)

## Thảo luận

Duyệt nhị phân là cách tối ưu để tìm kiếm trong một mảng đơn điệu, nếu mảng không đơn điệu thì tôi không đề xuất sử dung bởi độ khó tìm điều kiện rất lớn.

## Tham khảo

[Source code C++](./Search-in-Rotated-Sorted-Array.cpp)

-Chúc các bạn thành công-
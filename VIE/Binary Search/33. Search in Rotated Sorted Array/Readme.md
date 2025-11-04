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

## Phân tích dữ liệu

Bài toán cho ta 1 dãy số tăng tuyến tính có thể xuất hiện điểm k bất kỳ vị trí nào trong dãy từ điểm k trở về cuối dãy sẽ bị đảo chiều giảm tuyến tính, hãy tìm số trong dãy số đó.

Bản chất của bài toán là tìm đường nhanh nhất dẫn đến vị trí của số càn tìm trong dãy số đã cho.

Đây là dãy số tăng tuyến tính và tính chất của dãy số tăng tuyến tính.

Gọi n là độ dài dãy số và i là vị trí nằm trên dãy số:

a(i) <= a(i + 1) <= a(n) (1)

Dựa trên (1) nếu target nằm trong dãy thì ta có:

a(i) <= target <= a(n) (2)

Tuy nhiên, sự xuất hiện của k và dãy đảo ngược sau k dẫn đến sự xuất hiện của điểm gãy mà tại vị trí k toàn bộ phía sau k bị đảo ngược tính chất giảm dần.

a(i) <= a(i + 1) <= a(k) >= a(n) (3)

Nếu target nằm trong k thì dựa trên (3) ta có:

a(k) >= target >= a(n) (4)

(1)(2)(3)(4) => có thể sử dụng phương pháp loại trừ làm con tăng tốc độ phát hiện số trong dãy lên 1/2 lần. Bằng cách chia đôi dãy và so sánh biên.

Nếu a(i) <= a(n/2) ta có được dãy tăng.

Nếu a(i) >= a(n/2) ta có dãy giảm.

(3)(4) => Để xác định target nằm trong dãy nào để loại bỏ dãy số còn lại.

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

![Kết quả submissions](./Search-in-Rotated-Sorted-Array.jpg)

## Thảo luận

Duyệt nhị phân là cách tối ưu để tìm kiếm trong một mảng đơn điệu, nếu mảng không đơn điệu thì tôi không đề xuất sử dung bởi độ khó tìm điều kiện rất lớn.

## Tham khảo

[Source code C++](./Search-in-Rotated-Sorted-Array.cpp)


-Chúc các bạn thành công-



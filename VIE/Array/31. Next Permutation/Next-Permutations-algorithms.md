# 31. Next Permutation
## Đề bài
Hoán vị của một dãy số là cách ta sắp xếp lại thứ tự giá trị ở các vị trí khác nhau.

- Ví dụ: ta có dãy arr = [1, 2, 3], thứ tự các hoán vị có thể phát sinh là arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

Hoán vị kế tiếp của một mảng số nguyên là hoán vị lớn hơn kế tiếp theo thứ tự từ điển của mảng đó. Cụ thể hơn, nếu ta liệt kê tất cả các hoán vị của mảng và sắp xếp chúng theo thứ tự từ điển, thì hoán vị kế tiếp là hoán vị đứng ngay sau hoán vị hiện tại trong danh sách đó. Nếu không tồn tại hoán vị nào lớn hơn, mảng phải được sắp xếp lại thành thứ tự nhỏ nhất có thể (tức là sắp xếp tăng dần).

- Ví dụ, hoán vị kế tiếp của arr: [1, 2, 3] sẽ là [1, 3, 2].

- Đối với arr = [2,3,1] thì sẽ là [3, 1, 2]

- Đối với ar = [3, 2, 1] đây là thứ tự lớn nhất nên hoán vị của nó là [1, 2, 3]


*Ví dụ 1:*

Đầu vào: nums = [1,2,3]

Đầu ra: [1,3,2]

*Ví dụ 2:*

Đầu vào: nums = [3,2,1]

Đầu ra: [1,2,3]

*Ví dụ 3:*

Đầu vào: nums = [1,1,5]

Đầu ra: [1,5,1]

*Giới hạn:*

- 1 <= nums.length <= 100

- 0 <= nums[i] <= 100

## Giải thích thuật toán

Thuật toán sinh hoán vị theo thứ tự từ điển là một trong các thuật toán kinh điển nhất.

Ta có thể giải thích một cách đơn giản như sau, đây là các đôn các số lớn hơn di chuyển dần về trước cho đến khi dãy số giảm dần tuyến tính.

Nếu mô tả trực quan thì tôi sẽ dùng từ tạo con sóng đối xứng di chuyển từ cuối dãy đến đầu dãy như sau: [1, 2, 3, 4, 5] -> [*, *, *, 5, 4] -> [*, *, 5, 4, 3] -> [*, 5, 4, 3, 2] -> [5, 4, 3, 2, 1].

Công thức tổng quát cho thuật toán này là:

1. Tìm vị trí i có cặp số từ phải qua trái khi mà số bên trái < số bên phải.

2. Trong dãy số từ phải quá trái đến vị trí i di chuyển từ phải qua trái cho đến khi thấy số lớn hơn số ở i (phải là số đầu tiên lớn hơn chứ không phải số đầu dãy)

3. Đảo số ở 2 vị trí cho nhau

4. Đảo chiều dãy số bên phải bắt đầu từ i + 1

Các bước cụ thể như sau:

Bước 1: Khởi tạo 2 biến n, i và j với n = size dãy số - 1, i = n - 1 và j = n.

Bước 2: Khởi tạo điều kiện đặc biệt n == 1 chỉ có 2 số nên hoán vị kế tiếp chỉ cần đảo vị trí các số cho nhau, ngắt sớm đỡ tốn chi phí.

Bước 3: Khởi tạo for i để tìm điểm gãy nơi mà vị trí số bên trái < số bên phải. Bạn phải lưu ý i đang = n - 1 nghĩa là ta đang duyệt từ phải qua trái đây là chiều nghịch nên --i mới đúng.

*Trong for i*

Bước 4: Xét điều kiện nếu số bên trái < số bên phải thì lại tạo 1 vòng lặp for j để tìm số đầu tiên > số đang ở vị trí i.

*Trong for j*

Bước 5: Xét điều kiện số nums[i] < nums[j] thì đảo 2 số cho nhau rồi ngắt vòng lặp (Bởi vì chỉ chọn số đầu tiên > nums[i] nên không ngắt để nó chạy tiếp sẽ bị sai)

Bước 6: Đảo chiều các số từ vị trí i + 1 đến cuối dãy rồi ngắt vòng lặp.

Bước 7: Xét điều kiện i == 0 đây là lúc dãy số đã ở vị trí hoán vị cuối cùng nên vòng for i chạy cho đến khi i = 0 mà không thao tác gì cả, ta chỉ cần đảo chiều dãy số này sẽ cho ra hoán vị cần tìm.

## Kết quả LeetCode

![Kết quả submissions](./Next-Permutations.jpg)

## Thảo luận

Đây là thuật toán kinh điển có độ phức tạp O(n) bởi chỉ duyệt dãy số 1 lần rồi sau đó swap vị trí là xong

## Tham khảo

[Source code C++](./Next-Permutations.cpp)

-Chúc các bạn thành công-


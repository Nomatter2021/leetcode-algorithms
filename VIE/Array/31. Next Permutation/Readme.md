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

## Phân tích dữ liệu

Đề bài cho ta 1 dãy số và hãy tìm hoán vị kế tiếp của dãy số đó.

Nếu chúng ta xem dãy số đó là 1 con số thì nums{1, 2, 3} chính là số 123.

Gọi a là số 123 hoán vị kế tiếp dựa trên những số đã có là số kế tiếp > a nhưng có khoảng cách gần a nhất.

 [1, 2, 3] có 6 hoán vị bao gồm:

 - 123
 - 132
 - 213
 - 231
 - 312
 - 321

Nếu ta lấy 132 - 123 thì hiệu 2 số là 9 nhỏ hơn hiệu của 213 - 123 là 90, cách nhau 81 đơn vị.

Đây là phương thức phát sinh hoán vị theo thứ tự từ điển, số kế tiếp không được nhỏ hơn số hiện tại. Bởi vì theo dãy từ điển mục phía sau luôn lớn hơn mục phía trước.

Dựa trên cấu trúc số toán học cơ bản ta có:

Đơn vị  < hàng chục < hàng trăm < hàng nghìn

Đây là thứ tự sắp xếp của từ điển. Tuy nhiên, mỗi khi ta thay đối số ở 1 vị trí thì giá trị của số luôn thay đổi tùy thuộc vài vị trí ở hàng nào.

Thế nên luôn phải đẩy số lớn nhất tính từ hàng đơn vị dài lên về sau cùng và đôn số đầu tiên > số đang duyệt tính từ hàng đơn vị lên về trước.

Như thế khi nghịch đảo dãy số phía sau, ta có thể khống chế nó là thứ tự sắp xếp nhỏ nhất của số khi hoán đổi vị trí. Vì số nhỏ bị đẩy lên hàng có giá trị cao dẫn đến làm nhỏ giá trị vốn có, thay thì 900 thì chỉ còn 200.

ví dụ: 127,654

Duyệt từ hàng đơn vị dài lên ta thấy ở hàng chục nghìn và hàng nghìn có 2 < 7 và phía sau tính từ hàng đơn vị có số đầu tiên là 4 > 2 ta hoán đổi và nghịch đảo thứ tự sau hàng nghìn.

- 127,654 -> 147,652 -> 142,567

Để tìm số tiếp theo > 127,654 ta phải thay đổi hàng chục nghìn nhưng chỉ có thể tăng thấp nhất có thể nên ta chọn 4 thay vì 6, 5, 4 hay 7. Và phải đẩy số 2 về cuối để khi nghịch đảo 2 nằm ở hàng dưới chục nghìn là nghin tạo ra số bé nhất có thể là 142,567.

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



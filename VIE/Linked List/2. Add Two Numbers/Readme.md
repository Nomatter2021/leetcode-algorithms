# 2. Add Two Numbers
## Đề bài
Cho 2 danh sách liên kết không rỗng chứa 2 dãy số đảo ngược. Mỗi node là một số đơn. Hãy cộng 2 số lại với nhau và trả về kết quả là một danh sách liên kết

*Ví dụ 1:*

Đầu vào:  l1 = [2,4,3], l2 = [5,6,4]

Đầu ra: [7,0,8]

*Giải thích*

[2,4,3] = 342

[5,6,4] = 465

342 + 465 = 807.

*Ví dụ 2:*

Đầu vào: l1 = [0], l2 = [0]

Đầu ra: [0]

*Ví dụ 3:*

Đầu vào: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]

Đầu ra: [8,9,9,9,0,0,0,1]

*Giới hạn:*

- Độ dài danh sách trong khoảng [1, 100]

- 0 <= node <= 9

- Node đầu tiên không được chứa giá trị = 0

## Phân tích dữ liệu

Bài toán cho ta 2 danh sách liên kết và cộng 2 danh sách lại thành 1 danh sách mới.

Đây là bài toán cộng số hạng ta đã được học từ tiểu học, cộng 2 số bắt cặp theo hạng từ hàng đơn vị dài lên. Mỗi khi tổng 2 số lớn hơn 10 sẽ ghi nhận số ở hàng đơn vị rồi nhớ 1 để tham gia tính toán ở hạng tiếp theo.

Lý do bởi mỗi hạng có trọng số là 10 hàng chục lớn hơn gấp 10 lần hàng đơn vị và hàng trăm gấp 10 lần hàng chục, cho nên khi tổng lớn hơn 10 ta phải nâng hạng của số để số đó tham gia tính toán ở hạng có cùng trọng số.

## Giải thích thuật toán

Đây là phép tính cộng cơ bản chúng ta đã học khi còn tiểu học, cộng từ hàng đơn vị nếu tổng hàng đơn vị > 10 thì lấy giá trị đơn vị và nhờ giá trị hàng chục. Khi cộng tiếp 2 số ở hàng tiếp theo thì cộng thêm cả số nhớ cho đến khi số nhớ = 0 và đi hết toàn bộ số trong hàng.

Bước 1: Tạo node đầu tiên dùng để truy cập vào danh sách và trả về kết quả cuối cùng.

Bước 2: Tạo node đang đứng đây là node tiếp theo của Head (Bắt đầu thực hiện tính toán từ đây).

Bước 3: Khởi tạo các biến tính toán cần dùng;

Bước 4: Khởi tạo vòng lặp while với  điều kiện (danh sách 1 phải khác nullptr, danh khác 2 phải khác nullptr và số nhớ phải khác 0) điều kiện dừng là 2 danh sách đi đến node cuối cùng và số nhớ = 0.

*Trong lặp while*

Bước 5: tái tạo 2 biến dùng để chứa giá trị của các node trong 2 danh sách.

Bước 6: Xác nhận danh sách 1 đã đến node cuối chưa? Nếu chưa thì gáng số a = giá trị của node hiện tại và di chuyển danh sách sang node tiếp theo (Làm như vậy thì đến vòng lặp tiếp theo mới xác định được có nên gáng tiếp giá trị hay dừng?)

Bước 7: Làm như bước 6 với danh sách 2.

Bước 8: Tính tổng số của 2 danh sách và số nhớ.

Bước 9: Số nhớ = tổng đã tính / 10 (chia 10 lấy phần nguyên nếu số > 10 thì sẽ trả về số nhớ. Ví dụ: 15 thì chia 10 sẽ ra 1.5 lấy 1)

Bước 10: Tạo node tiếp theo với giá trị = tổng % 10 (chia 10 lấy phần dư. Ví dụ: 15 thì chia 10 sẽ ra 1.5 lấy 5)

Bước 11: Di chuyển đến node tiếp theo.

Bước 12: Trả kết quả node kết tiếp của node đầu tiên đã khởi tạo. (Bởi vì tôi dùng new nên khi khởi tạo nó tạo node tiếp theo chứ không phải node đầu nên phải trả giá trị node tiếp theo nếu không sẽ bị dư 1 số 0 ban đầu)

## Kết quả LeetCode

![Kết quả submissions](./Add-Two-Numbers.jpg)

## Thảo luận

Đây là bài nền tảng của danh sách liên kết, giúp chúng ta hiểu hơn về việc khởi tạo node mới và di chuyển giữa các node như thế nào.

## Tham khảo

[Source code C++](./Add-Two-Numbers.cpp)

-Chúc các bạn thành công-


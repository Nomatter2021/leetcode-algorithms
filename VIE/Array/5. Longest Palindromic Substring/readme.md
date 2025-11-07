# 5. Longest Palindromic Substring

## Đề bài

Cho một chuỗi ký tự s, hãy trả về chuỗi ký tự con bên trong s có tính chất đối xứng và là chuỗi con dài nhất trong tập hợp các chuỗi đối xứng.


*Ví dụ 1:*

Đầu vào: s = "babad"

Đầu ra: "bab"

*Ví dụ 2:*

Đầu vào: s = "cbbd"

Đầu ra: "bb"

*Giới hạn:*

- 1 <= s.length <= 1000

- s chỉ chứa những chữ cái tiếng Anh thường

## Phân tích dữ liệu

Đề cho ta một chuỗi ký tự và chúng ta phải tìm chuỗi đối xứng.

- Gọi C là điểm nằm trên đường thẳng s tại với bán kính Ri mà khi thực hiện ánh xạ từ C đến Ri' có độ dài tương tự thì các giá trị giá trị trên bán kính Ri' phải tương đồng tuyệt đối với các vị trí có cùng khoảng cách trên Ri (1).

- Gọi d là đường thẳng vuông góc với đoạn thẳng ij nằm trên s sao cho id và dj bằng nhau và khi ánh xạ đoạn id đến dj toàn bộ giá trị trên các điểm phải tương đồng nhau tuyệt đối và có cùng khoảng cách đến đường thẳng d (2).

(1)(2) Kết luận mọi vị trí hoặc 2 vị trí liền kề đều có thể trở thành tâm đối xứng nếu s[i] == s[i + 1] (Đối xứng qua trục) hoặc s[i - 1] == s[i + 1] (Đối xứng qua tâm).

Dựa trên tính chất đối xứng trên ta có thể tái sử dụng độ dài lớn nhất ghi nhận được để tìm đối xứng qua trục khả dĩ có thể đạt độ dài bằng với hiện tại hoặc lớn hơn.

Gọi D là đường kính của hình tròn tâm C với D bằng độ dài chuỗi đối xứng qua tâm và C nằm trên đường thẳng d vuông góc đi qua 2 điểm trên chuỗi.

Nếu đoạn thẳng này có khả năng là chuỗi đối xứng thì tại vị trí l (left) và r (right) cách đường thẳng d gần nhất sẽ tương đồng.

Gọi i là vị trí hiện tại:

- l = (2i + len)/2

- r = l + 1

Từ 2 điểm này mở rộng ra có thể tìm được chuỗi đối xứng có độ dài bằng hoặc lớn hơn độ dài hiện tại.

## Giải thích thuật toán

Giải bài toán này không khó, chỉ cần tìm các chuỗi đối xứng qua tâm và đối xứng qua trục chọn chuỗi dài nhất là được.

Tuy nhiên, đây là cách tìm 2 loại tâm và lồng 2 vòng lặp vào nhau nên độ phức tạp của thuật toán vẫn là O(n²) đối với những case tệ nhất.

Bước 1: Khởi tạo các biến cần thiết

Bước 2: Xác nhận nếu là chuỗi 1 ký tự thì trả về s

Bước 3: Xác nhận nếu 2 ký tự thì so sánh, nếu s[0] == s[1] thì trả về s còn không thì s[0]

Bước 4: Dùng lặp for i với i là tâm để mở rộng chuỗi.

*Trong for*

Bước 5: Gán l = i - 1 và r = i + 1.

Bước 6: Mở rộng chuỗi nếu s[l] == s[r] thì so sánh với len hiện tại nếu lớn hơn thì cập nhật vị trí và độ dài

Bước 7: tiếp tục mở rộng 2 đầu quanh tâm.

Bước 8: Dùng lặp for i để tìm đối xứng qua trục

*Trong for*

Bước 9: Xác định nếu i + (len/2) > n thì ngắt (dùng bán kính vì nếu dùng đường kính sẽ lọc qua tay bỏ lỡ nghiệm)

Bước 10: Gán l = (2i + len)/2 và r = l + 1

Bước 11: Mở rộng chuỗi nếu s[l] == s[r] thì so sánh với len hiện tại nếu lớn hơn thì cập nhật vị trí và độ dài sau đoa reset i = 0 (reset i vì điều kiện duyệt lúc này đã thau đổi len đã dài hơn vì thế các vị trí i lúc trước trở nên tiềm năng)

Bước 12: Trả kết quả

## Kết quả LeetCode

![Kết quả submissions](./Longest-Palindromic-Substring.jpg)

## Thảo luận

Với biện pháp tìm độ dài chuỗi đối xứng qua tâm sau đó dùng độ dài này áp lực để loại bỏ các chuỗi có tâm không có khả năng phát triển độ dài bằng hoặc hơn hiện tại sẽ rút ngắn thời gian chạy vô ích nhưng vẫn không vượt quá O(n²) nếu muốn hạ bậc độ phức tạp cần dùng hướng tiếp cận khác.

-Chúc các bạn thành công-

# 49. Group Anagrams
## Đề bài
Cho một mảng chuỗi ký tự strs, hãy nhóm lại các từ là hoán vị của nhau.

*Ví dụ 1:*

Đầu vào:  strs = ["eat","tea","tan","ate","nat","bat"]

Đầu ra: [["bat"],["nat","tan"],["ate","eat","tea"]]

*Giải thích*

- bat của có chính bản thân nó

- nat và tan là 2 hoán vị của 3 chữ cái [n, a, t]

- ate, eat, tea là 3 hoán vị của 3 chữ cái [a, t, e]

*Ví dụ 2:*

Đầu vào: strs = [""]

Đầu ra: [[""]]

*Ví dụ 3:*

Đầu vào: strs = ["a"]

Đầu ra: [["a"]]

*Giới hạn:*

- 1 <= strs.length <= 10^4

- 0 <= strs.length[i] <= 100

- strs[i] là chữ cái tiếng Anh thường.

## Phân tích dữ liệu

Bài toán cho chúng ta 1 vector chứa chuỗi ký tự và tìm các hoán vị của cùng 1 chuỗi và nhóm lại với nhau.

Đây là bài toán dưới góc nhìn phân loại của máy tính, máy tính không thể nhận diện ký tự như con người. Chúng chỉ nhận diện kỷ tự thông qua mã nhị phân 8 bits thông qua ánh xạ của bảng mã ASCII.

Từ việc ánh xạ ký tự về mã thập phân rồi chuyển về chuỗi mã nhị phân, ta có thể tận dụng bước trung gian là mã thập phân để sort chuỗi.

s1 = "aab" = ['a', 'a', 'b'] = [97, 97, 98]

s2 = "baa" = ['b', 'a', 'a'] = [98, 97, 97]

Mảng ánh xạ về thập phân là số và số thì có số lớn và số bé từ đó kỹ thuật sort hoàn toàn thực hiện được. chuỗi sau khi sort sẽ là:

s1 = [97, 97, 98]

s2 = [97, 97, 98]

rồi so sánh bắt cặp nếu giống nhau hoàn toàn từ độ dài đến giá trị mỗi vị trí thì nó là hoán vị của nhau.

## Giải thích thuật toán

Đây là bài toán HashTable (Bảng băm) với khóa chính là các chữ tái tạo và giá trị là tập hợp các hoán vị của những chữ cái đó (đặc biệt các chữ cái này có thể lặp lại trong).

Vậy nên cái điểm thắc của bài chính là làm sao để hash key và key này phải bắt được các hoán vị để nhóm chúng vào nhau, ban đầu tôi muốn thử sử dụng phương pháp sinh hoán vị theo thứ tự từ điển rồi sau đó dò với strs để nhóm chúng lại với nhau. Nhưng phương pháp này cho độ phức tạp quá lớn với O(n^2*n!).

Sau khi loại trừ phương pháp sinh hoán vị thì các tối ưu nhất vẫn là sort chuỗi ký tự bởi các từ đều được cấu thành từ các chữ cái giống nhau nên khi sort đều cho ra một kết quả duy nhất là thứ tự chữ cái nằm theo bảng chữ cái.

Bước 1: Tạo các biến cần thiên bao gồm 1 vector rs trả kết quả, 1 unorder_map đóng vai trò là bảng băm, 1 chuỗi ký tự key.

Bước 2: Duyệt vector strs.

*Trong for duyệt strs*

Bước 3: Gán key = giá trị ở vị trí hiện tại. (Nếu bạn sort giá trị ở vị trí hiện tại luôn thì bạn sẽ đánh mất từ ban đầu nên bắt buộc phải gán key để bảo toàn cấu trúc ban đầu)

Bước 4: Sắp xếp key.

Bước 5: emplace_back giá trị ở vị trí hiện tại vào key trong bảng băm (Bạn có thể dùng câu lệnh unordered_map[key] để tạo 1 key chưa có giá trị rồi sau đó dùng hàm emplace_back của vector để thêm giá trị vào vector, emplace_back sẽ thêm thẳng mà không cần cấp phát bộ nhớ rồi sao chép chuỗi mới thêm vào vector)

Bước 6: Duyệt bảng băm để di dời phần value sáng vector rs để trả kết quả

Bước 7: Trả kết quả.

## Kết quả LeetCode

![Kết quả submissions](./Group-Anagrams.jpg)

## Thảo luận

Với cách làm này ta có độ phức tạp O(n*klog(k)) với n là độ dài strs và k là độ dài của chuỗi con trong strs. Tối ưu hơn cách sinh toàn bộ hoán vị dự tính ban đầu, k*log(k) là độ phức tạp khi sort để hash key bạn có thể tối ưu thuật toán hơn bằng cách tối ưu hash key. Tạm thời mình vẫn chưa tìm ra cách hiệu quả hơn sort.


## Tham khảo

[Source code C++](./Group-Anagrams.cpp)


-Chúc các bạn thành công-


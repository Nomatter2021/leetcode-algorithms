# 34. Find First and Last Position of Element in Sort Array

## Đề bài

Mảng nums được sắp xếp tăng dần. Hãy tìm vị trí bắt đầu và kết thúc của giá trị target. Nếu không tồn tại, trả về [-1, -1]. Thuật toán phải có độ phức tạp O(log n).

Ví dụ 1:

Đầu vào: nums = [5,7,7,8,8,10], target = 8

Đầu ra: [3,4]

Ví dụ 2:

Đầu vào: nums = [5,7,7,8,8,10], target = 6

Đầu ra: [-1,-1]

Ví dụ 3:

Đầu vào: nums = [], target = 0

Đầu ra: [-1,-1]

Giới hạn:

- 0 < = nums.length <= 10^5

- 10^-9 <= nums[i] <= 10^9

- 0 <= height[i]<= 10^4

- nums là mảng tăng đơn điệu

- -10^9 <= target <= 10^9

## Giải thích thuật toán

Đây là bài toán nối tiếp của bài biến thể của bài 33. Search in Rotated Sorted Array sau khi được vị trí của target thì ta dùng kỹ thuật 2 con trỏ để mở rộng phạm vi mảng về trái và phải để xác định vị trí đầu vào cuối xuất hiện target.

Bước 1: Tạo vector trả kết quả.

Bước 2: Tạo các biến tính toán cần thiết.

Bước 4: Dùng kỹ thuật search nhị phân để tìm target

Bước 5: Dùng kỹ thuật 2 con trỏ để mở rộng biên từ vị trí xuất hiện target.

Bước 6: Trả kết quả.

## Kết quả leetcode

![Kết quả submissions](./Container-With-Most-Water.jpg)

## Thảo luận

Đây không phải là một bài khó nếu bạn nắm vững kỹ thuật search nhị phân và 2 con trỏ. Bạn có thể tham khảo kỹ thuật 2 con trỏ ở bài 11. Container With Most Water và search nhị phânở bài 34. Find First and Last Position of Element in Sorted Array. Tuy nhiên, điều kiện đầu vào mỗi bài khác nhau nên tham khảo không nên bê toàn bộ điều kiện và sẽ bị sai. 

## Tham khảo

[Source code C++](./Find-First-and-Last-Position-of-Element-in-Sorted-Array.cpp)

[11. Container With Most Water](../../Array/11.%20Container%20With%20Most%20Water/Readme.md)

[34. Find First and Last Position of Element in Sorted Array](../34.%20Find%20First%20and%20Last%20Position%20of%20Element%20in%20Sorted%20Array/Readme.md)

-Chúc các bạn thành công-
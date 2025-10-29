/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Head = new ListNode(0); // Tạo node đầu tiên
        ListNode* Current = Head; // Tạo vị trí node hiện tại
        int a, b, add, carry{0}; // Các biến tính toán
        while(l1 != nullptr || l2 != nullptr || carry != 0) // Vòng lặp duyệt danh sách
            {
                a = 0, b = 0; // Khởi tạo lại biến tính toán
                if(l1) // Xác nhận danh sách 1 đã đến node cuối cùng chưa
                {
                    a = l1 -> val;
                    l1 = l1 -> next;
                };
                if(l2) // Xác nhận danh sách 2 đã đến node cuối cùng chưa
                {
                    b = l2 -> val;
                    l2 = l2 -> next;
                };
                add = a + b + carry; // Tính tổng 2 số và số nhớ
                carry = add/10; // Ghi nhận số nhớ hàng chục
                Current -> next = new ListNode(add%10); // Ghi lại hàng đơn vị vào node tiếp theo
                Current = Current -> next; // Di chuyển đến node tiếp theo
            };
        return Head -> next; // Trả kết quả.
    }
};
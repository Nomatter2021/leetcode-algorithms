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
    ListNode* swapPairs(ListNode* head) {
        ListNode Head(0); // Khởi tạo node đầu tiên
        Head.next = head; // Link node tiếp theo với head để bắt đầu thao tác
        ListNode* Past = &Head; // Tạo node quá khứ
        while(Past -> next != nullptr && Past -> next -> next != nullptr) // Điều kiện dừng khi node hiện tại và tương lai gần khác null
            {
                ListNode* Present; // Khởi tạo node hiện tại
                ListNode* Future; // Khởi tạo node tương lai gần
                Present = Past -> next; // Link node hiện tại với node tiếp theo của node quá khứ
                Future = Present -> next; // Link node tương lai gần với node tiếp theo của node hiện tại
                Present -> next = Future -> next; // nối hiện tại với tương lai xa
                Future -> next = Present; // Nối tương lai gần với hiện tại
                Past -> next = Future; // Nối quá khứ với tương lai gần
                Past = Present; // di chuyển node tiếp theo quá khứ thành hiện tại
            };
        return Head.next; // Trả kết quả
    }
};
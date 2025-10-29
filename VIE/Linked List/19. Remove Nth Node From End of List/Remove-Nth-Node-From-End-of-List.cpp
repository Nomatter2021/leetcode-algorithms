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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Head = new ListNode(0); // Tạo node đầu tiên
        Head -> next = head; // Node tiếp theo để bắt đầu làm việc
        ListNode* Hed = Head; // Node 2 di chuyển sau
        ListNode* Tal = Head; // Node 1 di chuyển trước
        for(int i{0}; i < n; i++) // Di chuyển Node 1 n bước
            {
                Tal = Tal -> next;
            };
        if(Tal == nullptr) // Điều kiện đặc biệt
        {
            Hed = nullptr;
            return Head -> next;
        }
        while(Tal -> next != nullptr) // Di chuyển song song Node 1 và Node 2
            {
                Tal = Tal -> next;
                Hed = Hed -> next;
            };
        Hed -> next = Hed -> next -> next; // Loại bỏ vị trí chỉ định
        return Head -> next; // Trả kết quả
    }
};
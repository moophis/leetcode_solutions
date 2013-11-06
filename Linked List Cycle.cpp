class Solution {
public:
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *cur = head;
        ListNode *behind = head;
        
        if (head == nullptr)
            return false;
        
        while ((cur = cur->next) != nullptr &&
                   (cur = cur->next) != nullptr) {
            if (cur == behind) {
                return true;
            } else {
                behind = behind->next;
            }          
        }
        
        return false;
    }
};
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
class Solution
{
public:
    bool palindrome = true;
    ListNode *normal = new ListNode;
    void check(ListNode *reverse)
    {
        if (reverse == NULL)
            return;
        check(reverse->next);
        if (normal->val != reverse->val)
            palindrome = false;
        normal = normal->next;
    }

    bool isPalindrome(ListNode *head)
    {
        normal = head;
        check(head);
        return palindrome;
    }
};
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
    void reverse(ListNode *node, ListNode *&headPointer)
    {
        if(headPointer == NULL || headPointer->next == NULL) return;
        if (node->next == NULL)
        {
            headPointer = node;
            return;
        }
        reverse(node->next, headPointer);
        node->next->next = node;
        node->next = NULL;
    }
    ListNode *reverseList(ListNode *head)
    {
        reverse(head, head);
        return head;
    }
};
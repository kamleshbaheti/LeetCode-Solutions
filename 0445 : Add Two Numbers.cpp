/*
      Algorithm : Linked List Iteration
      Language : C++
      Time Complexity : O(n)
      Space Complexity : O(n)
      Date of Submission : 17/March/2023
*/


class Solution 
{
private:
    ListNode *reverse(ListNode* q)
    {
        ListNode *p = NULL;
        ListNode *temp = q->next;
        while(temp != NULL)
        {
            q->next = p;
            p = q;
            q = temp;
            temp = q->next;
        }
        q->next = p;
        return q;
    }
    ListNode *func(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = NULL;
        int carry = 0, sum = 0;
        while(l1 || l2 || carry)
        {
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            if(carry != 0)
            {
                sum += carry;
            }
            ListNode* List = new ListNode(sum%10);
            List->next = temp;
            temp = List;
            carry = sum/10;
            sum = 0;
        }
        return temp;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* List1 = reverse(l1);
        ListNode* List2 = reverse(l2);
        return func(List1, List2);
    }
};

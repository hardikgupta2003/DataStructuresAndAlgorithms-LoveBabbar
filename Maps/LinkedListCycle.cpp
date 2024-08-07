#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // solution with map
        unordered_map<ListNode *, bool> mp;
        ListNode *temp = head;

        while (temp != NULL)
        {

            if (mp.find(temp) != mp.end())
            {
                return true;
            }
            else
            {
                mp[temp] = true;
            }
            temp = temp->next;
        }
        return false;
    }
};
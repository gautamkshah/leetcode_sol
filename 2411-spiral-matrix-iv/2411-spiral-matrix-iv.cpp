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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode *head)
{
    vector<vector<int>> ans(n, vector<int>(m, -1));
    int lr = 0, hr = n - 1; int lc = 0, hc = m - 1;
    int i = 0, j = 0;
    bool left = true, right = false, up = false, down = false;
    int c=0;
    while (head != NULL)
    {
        cout<<i<<" "<<j<<endl;
        ans[i][j] = head->val;
        if (left)
        {
            if (j == hc)
            {
                i++;
                left = false;
                down = true;
                lr++;
            }
            else
            {
                j++;
            }
        }
        else if (right)
        {
            if (j == lc)
            {
                up = true;
                right = false;
                i--;
                hr--;
            }
            else
            {
                j--;
            }
        }
        else if (down)
        {
            if (i == hr)
            {
                down = false;
                right= true;
                j--;
                hc--;
            }else{
                i++;
            }
        }
        else if (up)
        {
            if (i == lr)
            {
                up = false;
                left = true;
                j++;
                lc++;
            }else{
                i--;
            }
        }
        head = head->next;
        c++;
    }
    return ans;
}
    

};
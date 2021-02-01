#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *newhead = head->next;
        head->next = swapPairs(newhead->next);
        newhead->next = head;
        return newhead;
    }
};

ListNode* newListnode(int val){
    ListNode *node = new ListNode;
    node->val = val;
    node->next = nullptr;
    return node;
}

ListNode* VecToListnode(vector<int> v, int len, int index){
    if (index >= len) return nullptr;

    ListNode* node = newListnode(v[index]);
    index++;
    node->next = VecToListnode(v, len, index);

    return node;
}

void Printlistnode(ListNode* nodehead){
    if (nodehead == nullptr){
        cout << endl;
        return;
    }
    cout << nodehead->val << " ";
    Printlistnode(nodehead->next);
}

int main(){
    int n;
    while (cin >> n){
        vector<int> vec(n);
        for (int i=0; i<n; i++){
            cin >> vec[i];
        }
//        ListNode *node = new ListNode;
        ListNode* node = VecToListnode(vec, n, 0);

//        ListNode *swapednode = new ListNode;
        ListNode* swapednode = Solution().swapPairs(node);

        Printlistnode(swapednode);
    }
    return 0;
}

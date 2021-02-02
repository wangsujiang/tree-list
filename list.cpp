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
};

ListNode* newListnode(int val){
    ListNode *node = new ListNode;
    node->val = val;
    node->next = nullptr;
    return node;
}

ListNode* VecToListnode(vector<int> &v, int index){
    int len = v.size();
    if (index >= len) return nullptr;

    ListNode* node = newListnode(v[index]);
    index++;
    node->next = VecToListnode(v, index);

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

// INPUT LENGTH KNOWN:
int main(){
    int n;
    while (cin >> n){
        vector<int> vec(n);
        for (int i=0; i<n; i++){
            cin >> vec[i];
        }

        ListNode* node = VecToListnode(vec, 0);

        //ListNode* swapednode = Solution().swapPairs(node);

        //Printlistnode(swapednode);
    }
    return 0;
}


// INPUT LENGTH UNKNOWN:
int main(){
    string input;
    while (getline(cin, input)){
        istringstream iss1(input);
        vector<int> vec1, vec2;
        int val;
        while (iss1 >> val){
            vec1.push_back(val);
        }
        getline(cin, input);
        istringstream iss2(input);
        while (iss2 >> val){
            vec2.push_back(val);
        }
        ListNode *l1 = VecToListnode(vec1, 0);
        ListNode *l2 = VecToListnode(vec2, 0);

        //ListNode *ans = mergeTwolists(l1, l2);

        //Printlistnode(ans);
    }
}

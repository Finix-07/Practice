#include <iostream>
#include <vector>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nodesBetweenCriticalPoints(ListNode* head) {

    vector<int> result;
    int index = 1;
    int cp = 0;
    int lastCPindex = 0;
    ListNode* prev;
    ListNode* curr;
    int minDistance = INT_MAX;
    int maxDistance = 0;
    prev = head;
    curr = head->next;


    while(curr->next != nullptr){

        int currdiff = 0;
        if ((curr->val < curr->next->val && curr->val < prev->val) || (curr->val > curr->next->val && curr->val > prev->val)){
            if (cp == 0){
                maxDistance += index;
                lastCPindex = index;
                curr = curr->next;
                prev = prev->next;
                index++;
                cp++;
                continue;
            }
            currdiff = index - lastCPindex;
            minDistance = min(minDistance,currdiff);
            lastCPindex = index;
            cp++;
        }
        curr = curr->next;
        prev = prev->next;
        index++;
    }
    maxDistance -= lastCPindex;
    maxDistance *= -1;

    if (cp < 2){
        result.push_back(-1);
        result.push_back(-1);
    }
    else{
        result.push_back(minDistance);
        result.push_back(maxDistance);
    }

    return result;

}
int main(){
    printf("Hello");
    return 0;
}
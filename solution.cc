// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

// Return a deep copy of the list.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> myMap;
        RandomListNode *newHead = NULL;
        while(head) {
            RandomListNode *newNode = NULL;
            if(myMap.count(head)) {
                newNode = myMap[head];
            } else {
                newNode = new RandomListNode(head->label);
                myMap[head] = newNode;
            }
            if(!newHead) newHead = newNode;
            if(head->next) {
                RandomListNode *newNext = NULL;
                if(myMap.count(head->next)) {
                    newNext = myMap[head->next];
                } else {
                    newNext = new RandomListNode(head->next->label);
                    myMap[head->next] = newNext;
                }
                newNode->next = newNext;
            }
            if(head->random) {
                RandomListNode *newRandom = NULL;
                if(myMap.count(head->random)) {
                    newRandom = myMap[head->random];
                } else {
                    newRandom = new RandomListNode(head->random->label);
                    myMap[head->random] = newRandom;
                }
                newNode->random = newRandom;
            }
            head = head->next;
        }
        return newHead;
    }
};

// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = nullptr;
//         random = nullptr;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Create new nodes and insert them after each original node
        Node* curr = head;
        while (curr != nullptr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Assign random pointers for the new nodes
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the new list from the original list
        curr = head;
        Node* newHead = head->next;
        Node* copy = newHead;
        while (curr != nullptr) {
            curr->next = curr->next->next;
            if (copy->next != nullptr) {
                copy->next = copy->next->next;
            }
            curr = curr->next;
            copy = copy->next;
        }

        return newHead;
    }
};

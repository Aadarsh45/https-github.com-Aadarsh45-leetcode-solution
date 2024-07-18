/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertNode(Node* head){
        Node* temp = head;
        while(temp!= nullptr){
             Node* new_node = new Node(temp->val);
             new_node->next = temp->next;
             temp->next = new_node;
             temp = temp->next->next;
            
             
        }
    }
    void getPointers(Node* head){
        
        Node* temp = head;
        while(temp!=nullptr){
            Node* copy = temp->next;
           
            if(temp->random!=NULL){
                copy->random = temp->random->next;
            }
            
            temp = temp->next->next;
        }
      
    }
    Node* getCopy(Node* head){
        Node* dummy = new Node(-1);
        Node* res = dummy;
        
        Node* temp = head;
        while(temp!=nullptr){
            res->next = temp->next;
            res = res->next;
            
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    
    Node* copyRandomList(Node* head) {
        insertNode(head);
        getPointers(head);
        return getCopy(head);
        
        
    }
};
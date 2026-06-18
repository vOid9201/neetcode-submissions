class Node {

public:
    int value;
    Node* next;
    
    Node(int value){
        this->value = value;
        this->next = NULL;
    }
};

class LinkedList {

private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    int get(int index) {
        Node* curr = this->head;
        while(curr != NULL){
            if(index == 0) return curr->value;
            curr = curr->next;
            index --;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* temp = new Node(val);
        if(this->head == NULL && this->tail == NULL)
            this->head = temp , this->tail = temp;
        else
            temp->next = this->head , this->head = temp;    
        size ++;
    }
    
    void insertTail(int val) {
        Node* temp = new Node(val);
        if(this->head == NULL && this->tail == NULL)
            this->tail = temp , this->head = temp;
        else 
            this->tail->next = temp , this->tail = temp;
        size ++ ;
    }

    bool remove(int index) {
        Node* curr = this->head;
        if(index >= size) return false;
        while(curr != NULL){
            if(index == 0){
                this->head = curr->next;
                return true;
            }
            if(index == 1){
                curr->next = (curr->next)->next;
                if(curr->next == NULL) this->tail = curr;
                return true; 
            }
            curr = curr->next;
            index --;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = this->head;
        while(curr != NULL){
            res.push_back(curr->value);
            curr = curr->next;
        }
        return res;
    }
};

class Node{

public:
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        this->next = NULL;
    }
};

class LinkedList{

private:

    int size;
    Node* head;
    Node* tail;

public:

    LinkedList(){
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    int get(int i){
        if(i>=this->size) return -1;
        Node* curr = this->head;
        while(i >= 1){
            curr = curr->next;
            i--;
        }
        return curr->value;
    }
    void insertHead(int val){
        Node* temp = new Node(val);
        if(this->size == 0) this->head = temp , this->tail = temp;
        else temp->next = this->head , this->head = temp;
        this->size++;
    }
    void insertTail(int val){
        Node* temp = new Node(val);
        if(this->size == 0) this->tail = temp , this->head = temp;
        else this->tail->next = temp , this->tail = temp;
        this->size ++;
    }
    bool remove(int i){
        if(i>=this->size) return false;
        Node* curr = this->head;
        if(i == 0) this->head = curr->next;
        else{
            while(i > 1){
                curr = curr->next;
                i--;
            }
            curr->next = curr->next->next;
            if(curr->next == NULL) this->tail = curr;
        }
        this->size --;
        return true;
    }
    vector<int> getValues(){
        vector<int> res;
        Node* curr = this->head;
        while(curr != NULL){
            res.push_back(curr->value);
            curr = curr->next;
        }
        return res;
    }

};
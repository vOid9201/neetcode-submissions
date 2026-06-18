class LinkedList {
class Node {
    public:
        int value ;
        Node* next;
        Node(int value){
            this->value = value;
            this->next = NULL;
        }
};

private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int get(int index) {
        if(index >= size) return -1;
        int x = 0;
        Node* temp = head;
        while(x<index){
            temp = temp->next;
            x++;
        }
        return temp->value;
    }

    void insertHead(int val) {
        Node* temp = new Node(val);
        if(size == 0)
            head = temp , tail = temp;
        else{
            temp->next = head;
            head = temp;
        }
        size ++; 
        return;
    }
    
    void insertTail(int val) {
        Node* temp = new Node(val);
        if(size == 0)
            head = temp , tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size ++ ;
        return ;
    }

    bool remove(int index) {
        if(index >= size) return false;
        //head removal
        if(index == 0)
            head = head->next;
        else{
            Node* temp = head;
            for(int i=0;i<index-1;i++){
                temp = temp->next;
            }
            temp->next = (temp->next)->next;
            if(index == size - 1) tail = temp;
        }
        size --;
        return true;

    }

    vector<int> getValues() {
        vector<int> res(size);
        Node* temp = head;
        for(int i=0;i<size;i++){
            res[i] = temp->value;
            temp = temp->next;
        }
        return res;
    }
};

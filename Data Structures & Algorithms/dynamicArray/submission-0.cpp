class DynamicArray {
private:
    int capacity ;
    int size ;
    int* arr = NULL;
public:
    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        arr = new int[capacity];
    }


    int get(int i) {
        return this->arr[i];
    }

    void set(int i, int n) {
        this->arr[i] = n;
    }

    void pushback(int n) {
        if( !(this->size < this->capacity) )
            this->resize();
        this->arr[size] = n;
        this->size ++  ;
        return ;
    }

    int popback() {
        return this->arr[--this->size];
    }

    void resize() {
        this->capacity = 2*this->capacity;
        int* temp_arr = new int[this->capacity];
        for(int i =0;i<size;i++){
            temp_arr[i] = this->arr[i];
        }
        delete[] arr;
        arr = temp_arr;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }
};

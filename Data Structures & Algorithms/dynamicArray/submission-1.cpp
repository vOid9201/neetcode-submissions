class DynamicArray {

private:
    int size;
    int capacity;
    int* arr;

public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    int get(int i) {
        return this->arr[i];
    }

    void set(int i, int n) {
        this->arr[i] = n;
    }

    void pushback(int n) {
        if(this->size == this->capacity) resize();
        this->arr[this->size] = n;
        this->size++;
    }

    int popback() {
        return this->arr[--this->size];
    }

    void resize() {
        this->capacity = 2*this->capacity;
        int* temp_arr = new int[this->capacity];
        for(int i=0;i<this->size;i++) temp_arr[i] = this->arr[i];
        delete arr;
        arr = temp_arr;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }   
};

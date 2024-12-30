class DynamicArray {
public:
    int cur_len;
    int cur_cap;
    int* darr;
    DynamicArray(int capacity) {
        darr = (int*)malloc(capacity * sizeof(int));
        cur_cap = capacity;
        cur_len = 0;
    }

    int get(int i) {
        return darr[i];
    }

    void set(int i, int n) {
        darr[i] = n;
    }

    void pushback(int n) {
        //check if we need to resize
        if(cur_len == cur_cap)
            resize();
        cur_len++;
        darr[cur_len - 1] = n;
    }

    int popback() {
        int val = darr[cur_len - 1];
        cur_len--;
        return val;
    }

    void resize() {
        int* tmp = darr;
        darr = (int*)malloc(2*cur_cap*sizeof(int));
        for(int i = 0; i < cur_cap; i++){
            darr[i] = tmp[i];
        }
        free(tmp);
        cur_cap *= 2;
    }

    int getSize() {
        return cur_len;
    }

    int getCapacity() {
        return cur_cap;
    }
};

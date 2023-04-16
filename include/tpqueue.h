// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T* array;
    int first, last, num;
 public:
    TPQueue() : last(0), first(0), num(0) {
        array = new T[size];
    }
    bool isEmpty() const {
        return 0 == num;
    }
    bool isFull() const {
        return num == size;
    }
    void push(const T& value) {
        if (isFull()) {
            throw std::string("full!");
        } else {
            int n = last;
            array[last % size] = value;
            T temp = array[n % size];
            while (array[(n - 1) % size].prior < array[n % size].prior \
            && first < n) {
                temp = array[n % size];
                array[n % size] = array[(n - 1) % size];
                array[(n - 1) % size] = temp;
                n--;
            }
            num++;
            last++;
        }
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("empty!");
        } else {
            num--;
            return array[first++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_

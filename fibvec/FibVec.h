#include <iostream>
using namespace std;

class FibVec{
    public:
            FibVec();
            ~FibVec();
            size_t capacity() const;
            size_t count() const;
            void insert (int value,size_t index );
            int lookup(size_t index) const;
            int pop();
            void push(int value);
            int remove(size_t index);
            
            
    private:
            int *point;
            int size;
            int elm;
            size_t sizecomp;
            int nextFibonacci(int n) const;
            void resize(int new_size);
            int previousFibonacci(int n) const;
};

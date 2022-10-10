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
            void pop();
            void push(int value);
            void remove(size_t index);
            
            
    private:
            int *point;
            int size;
            int elm;
            int nextFibonacci(int n) const;
};
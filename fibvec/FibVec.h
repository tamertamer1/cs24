using namespace std;
#include <cstddef>
class FibVec{
    public:
            FibVec();
            ~FibVec();
            size_t capacity() const;
            size_t count() const;
            void insert (int value,size_t index );
            int lookup(size_t index);
            void pop();
            void push(int value);
            void remove(size_t index);
            
    private:
            int *point;
};

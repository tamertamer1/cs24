#include "Heap.h"
#include <vector>
#include <stdexcept>
Heap::Heap(size_t capacity){
   mCount=0;
   mCapacity=capacity;
   Entry Arr[mCapacity];
   mData=Arr;
};
Heap::Heap(const Heap& other){

};
Heap::Heap(Heap&& other){
    
};
Heap::~Heap(){

};

size_t Heap::capacity() const{
    return mCapacity;
};
size_t Heap::count() const{
    return mCount;
};
const Heap::Entry& Heap::lookup(size_t index) const{
    if (index<(mCount-1)){
        return mData[index];
    }
    else{
        throw std::out_of_range("Index out of range.");
    }
};
Heap::Entry Heap::pop(){
    if (mCount!=0){
        size_t minscoreind=0;
        Entry minent;
        float minscore=mData[0].score;
        for (size_t i=0;i<mCount;i++){
            if(mData[i].score<minscore){
                minscore=mData[i].score;
                minscoreind=i;
                minent=mData[i];
            }
        }
        for(size_t i=minscoreind+1;i<mCount;i++){
            mData[i-1]=mData[i];
        }
        mCount=mCount-1;
        return minent;
    }
    else{
        throw std::underflow_error("No Items in heap.");
    }

};
Heap::Entry Heap::pushpop(const std::string& value, float score){
    Entry minentr;
    return minentr;
};
void Heap::push(const std::string& value, float score){
    
};
const Heap::Entry& Heap::top() const{
    if (mCount!=0){
        Entry minentr;
        float minscore=mData[0].score;
        for (size_t i=0;i<mCount;i++){
            if(mData[i].score<minscore){
                minscore=mData[i].score;
                minentr=mData[i];
            }
        }
        return minentr;
    }
    else{
        throw std::underflow_error("No Items in heap.");
    }
};

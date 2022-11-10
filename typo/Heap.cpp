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
    if (index<(mCount)){
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
    if(mCount<mCapacity){
        Entry newent;
        newent.score=score;
        newent.value=value;
        mData[mCount]=newent;
        mCount++;
        size_t currind=mCount;
        while((currind)>0 && mData[size_t((currind-1)/2)].score>mData[currind].score){
            Entry tempent=mData[size_t((currind-1)/2)];
            mData[size_t((currind-1)/2)]=mData[currind];
            mData[currind]=tempent;
            currind=size_t((currind-1)/2);
        }
    }
    else{
        throw std::overflow_error("No place in heap.");
    }
};
const Heap::Entry& Heap::top() const{
    if (mCount!=0){
        size_t minscoreind=0;
        float minscore=mData[0].score;
        for (size_t i=0;i<mCount;i++){
            if(mData[i].score<minscore){
                minscoreind=i;
                minscore=mData[i].score;
            }
        }
        return mData[minscoreind];
    }
    else{
        throw std::underflow_error("No Items in heap.");
    }
};

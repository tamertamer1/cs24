#include "Heap.h"
#include <vector>
#include <stdexcept>
Heap::Heap(size_t capacity){
   mCount=0;
   mCapacity=capacity;
   mData= new Entry[mCapacity];
};
Heap::Heap(const Heap& other){
    mData= new Entry[other.mCapacity];
    mCount=other.mCount;
    mCapacity=other.mCapacity;
    for (size_t i=0;i<other.mCount;i++){
        mData[i]=other.mData[i];
    }
};
Heap::Heap(Heap&& other){
    mData= new Entry[other.mCapacity];
    mCount=other.mCount;
    mCapacity=other.mCapacity;
    for (size_t i=0;i<other.mCount;i++){
        mData[i]=other.mData[i];
    }
    other.mCount=0;
    other.mCapacity=0;
    delete [] other.mData;
};
Heap::~Heap(){
    delete [] mData;
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
        float minscore=mData[0].score;
        for (size_t i=0;i<mCount;i++){
            if(mData[i].score<minscore){
                minscoreind=i;
                minscore=mData[i].score;
            }
        }
        Entry minent;
        minent=mData[minscoreind];
        mData[minscoreind]=mData[mCount-1];
        mCount=mCount-1;
        size_t currind=minscoreind;
         while(((currind*2+1)<mCount)||(((currind*2+2)<mCount))){
            if((currind*2+2)<mCount){
                if( (mData[currind*2+1].score<mData[currind].score) || (mData[currind*2+2].score<mData[currind].score)){
                    if( mData[currind*2+1].score<= mData[currind*2+2].score){
                        Entry tempent=mData[currind*2+1];
                        mData[currind*2+1]=mData[currind];
                        mData[currind]=tempent;
                        currind=currind*2+1;
                    }
                    else{
                        Entry tempent=mData[currind*2+2];
                        mData[currind*2+2]=mData[currind];
                        mData[currind]=tempent;
                        currind=currind*2+2;
                    }
                }
                else{
                    break;
                }
            }
            else{
                if(mData[currind*2+1].score<mData[currind].score){
                    Entry tempent=mData[currind*2+1];
                    mData[currind*2+1]=mData[currind];
                    mData[currind]=tempent;
                    currind=currind*2+1;
                }
                else{
                    break;
                }
            }
        }
        return minent;
    }
    else{
        throw std::underflow_error("No Items in heap.");
    }

};
Heap::Entry Heap::pushpop(const std::string& value, float score){
    if (mCount!=0){
        size_t minscoreind=0;
        float minscore=mData[0].score;
        for (size_t i=0;i<mCount;i++){
            if(mData[i].score<minscore){
                minscoreind=i;
                minscore=mData[i].score;
            }
        }
        Entry minent;
        minent=mData[minscoreind];
        Entry tempent;
        tempent.score=score;
        tempent.value=value;
        mData[minscoreind]=tempent;
        size_t currind=minscoreind;

        while(((currind*2+1)<mCount)||(((currind*2+2)<mCount))){
            if((currind*2+2)<mCount){
                if( (mData[currind*2+1].score<mData[currind].score) || (mData[currind*2+2].score<mData[currind].score)){
                    if( mData[currind*2+1].score<= mData[currind*2+2].score){
                        Entry tempent=mData[currind*2+1];
                        mData[currind*2+1]=mData[currind];
                        mData[currind]=tempent;
                        currind=currind*2+1;
                    }
                    else{
                        Entry tempent=mData[currind*2+2];
                        mData[currind*2+2]=mData[currind];
                        mData[currind]=tempent;
                        currind=currind*2+2;
                    }
                }
                else{
                    break;
                }
            }
            else{
                if(mData[currind*2+1].score<mData[currind].score){
                    Entry tempent=mData[currind*2+1];
                    mData[currind*2+1]=mData[currind];
                    mData[currind]=tempent;
                    currind=currind*2+1;
                }
                else{
                    break;
                }
            }
        }
        return minent;
    }
    else{
        throw std::underflow_error("No Items in heap.");
    }
};
void Heap::push(const std::string& value, float score){
    if(mCount<mCapacity){
        Entry newent;
        newent.score=score;
        newent.value=value;
        mData[mCount]=newent;
        mCount++;
        size_t currind=mCount-1;
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

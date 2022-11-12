#include "Dictionary.h"
#include <cmath>
Dictionary:: Dictionary(std::istream& stream){
    std::string line;
    while(getline(stream,line)){
        if (line[0]!='#' && line.length() > 0){
            if(islower(line[0])){
                mWords.push_back(line);
            }
        }
    }
};

Heap Dictionary::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    Heap worheap(maxcount);
    for (std::string word:mWords){
        if(word.length()==points.size()){
            float wordscore=0;
             for (size_t i=0;i<word.length();i++){
                Point Keybpt= QWERTY[word[i]-'a'];
                float chardist=sqrt(pow(Keybpt.x-points[i].x,2)+pow(Keybpt.y-points[i].y,2));
                float charscore=(1/(10*pow(chardist,2)+1));
                wordscore=wordscore+charscore;
             }
            float totscore=wordscore/3;
            if(totscore>=cutoff){
                if(worheap.count()<worheap.capacity()){
                    worheap.push(word,totscore);
                }
                else{
                    if(totscore>worheap.top().score){
                        worheap.pushpop(word,totscore);
                    }
                }
            }
        }
    }
};


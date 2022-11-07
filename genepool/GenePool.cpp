#include "GenePool.h"
#include <string>
#include <sstream>
#include <vector>
GenePool::GenePool(std::istream& stream){
    std::string line;
    while(getline(stream,line)){
        if (line[0]!='#' && line.length() > 0){
            std::stringstream ss(line);
            std::string geneval;
            Person* mone= nullptr;
            Person* done= nullptr;
            vector<std::string> vals;
            while(getline(ss,geneval,'\t')){
                vals.push_back(geneval);
            }
            Gender gend;
            mone= find(vals[2]);
            done= find(vals[3]);
            if(vals[1] == "male"){
                gend = Gender::MALE;
            }
            else {
                gend = Gender::FEMALE;
            }
            std::set<Person*> eset;
            genepoolmap[vals[0]]= new Person(mone,done,vals[0],gend,eset);
            if (mone!=nullptr){
                mone->chilset.insert(find(vals[0]));
            }
            if (done!=nullptr){
                done->chilset.insert(find(vals[0]));
            }
        }
    };
    
};
GenePool::~GenePool(){
    for(auto i:genepoolmap){
        delete i.second;}
        genepoolmap.clear();
    
};
Person* GenePool::find(const std::string& name) const{
    if (genepoolmap.count(name)){
         return genepoolmap.at(name);
    }
   return nullptr;
};


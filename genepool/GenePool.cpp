#include "GenePool.h"
#include <string>
#include <sstream>
#include <vector>
GenePool::GenePool(std::istream& stream){
    std::string line;
    while(getline(stream,line)){
        if (line[0]!='#' && !line.empty()){
            std::stringstream ss(line);
            std::string geneval;
            Person* mom=nullptr;
            Person* dad=nullptr;
            vector<std::string> vals;
            while(getline(ss,geneval,'\t')){
                vals.push_back(geneval);
            }
            mom->data=vals[2];
            dad->data=vals[3];
            Gender gend;
            if(vals[1] == "male"){
                gend = Gender::MALE;
            }
            else {
                gend = Gender::FEMALE;
            }
            genepoolmap[vals[0]]= new Person(mom,dad,vals[0],gend);
            }
        };
};
GenePool::~GenePool(){

};
Person* GenePool::find(const std::string& name) const{
    return genepoolmap.at(name);
};


#include "Person.h"
// Person Member Functions


const std::string& Person::name() const{
    return this->data;
};
Gender Person::gender() const{
    return this->gend;
};
Person* Person::mother(){
    return this->mom;
};
Person* Person::father(){
    return this->dad;
};
std::set<Person*> Person::ancestors(PMod pmod){
    std::set<Person*> myset;
    return myset;
};
std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> bros;
    std::set<Person*> sibs;
    sibs=siblings(pmod,smod);
    for (Person* person:sibs){
        if (person->gend==Gender::MALE){
            bros.insert(person);
        }
    }
    return bros;

};
std::set<Person*> Person::children(){
    return this->chilset;
};
std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::daughters(){
    std::set<Person*> childrenset=children();
    std::set<Person*> daughtset;
    for (Person* person: childrenset){
        if (person->gend==Gender::FEMALE){
            daughtset.insert(person);
        } 
    }
    return daughtset;

};
std::set<Person*> Person::descendants(){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::grandchildren(){
    std::set<Person*> gcset;
    std::set<Person*> childrenset=children();
    for (Person* person:childrenset){
        std::set<Person*> ccset=person->chilset;
        for (Person* gc : ccset){
            gcset.insert(gc);
        }
    }
    return gcset;

};
std::set<Person*> Person::granddaughters(){
    std::set<Person*> grchildren;
    std::set<Person*> gdaughts;
    for (Person* gc: grchildren){
        if(gc->gend==Gender::FEMALE){
            gdaughts.insert(gc);
        }
    }
    return gdaughts;

};
std::set<Person*> Person::grandfathers(PMod pmod){
    std::set<Person*> gfs;
    if (pmod==PMod::MATERNAL){
       gfs.insert(mother()->dad);
    }
    else if (pmod==PMod::PATERNAL){
       gfs.insert(father()->dad);
    }
    else{
        gfs.insert(mother()->dad);
        gfs.insert(father()->dad);
    }
    return gfs;

};
std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> gms;
    if (pmod==PMod::MATERNAL){
       gms.insert(mother()->mom);
    }
    else if (pmod==PMod::PATERNAL){
       gms.insert(father()->mom);
    }
    else{
        gms.insert(mother()->mom);
        gms.insert(father()->mom);
    }
    return gms;

};
std::set<Person*> Person::grandparents(PMod pmod){
    std::set<Person*> gps;
    if (pmod==PMod::MATERNAL){
       gps.insert(mother()->mom);
       gps.insert(mother()->dad);
    }
    else if (pmod==PMod::PATERNAL){
       gps.insert(father()->mom);
       gps.insert(father()->dad);
    }
    else{
        gps.insert(mother()->mom);
        gps.insert(mother()->dad);
        gps.insert(father()->mom);
        gps.insert(father()->dad);
    }
    return gps;

};
std::set<Person*> Person::grandsons(){
    std::set<Person*> grchildren;
    std::set<Person*> gsons;
    for (Person* gc: grchildren){
        if(gc->gend==Gender::MALE){
            gsons.insert(gc);
        }
    }
    return gsons;

};
std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    std::set<Person*> sibs;
    std::set<Person*> nephs;
    sibs=siblings(pmod,smod);
    for (Person* sib:sibs){
        for(Person* sibson:sib->sons()){
            nephs.insert(sibson);
        }
    }
    return nephs;

};
std::set<Person*> Person::nieces(PMod pmod, SMod smod){
    std::set<Person*> sibs;
    std::set<Person*> niece;
    sibs=siblings(pmod,smod);
    for (Person* sib:sibs){
        for(Person* sibdaught:sib->daughters()){
            niece.insert(sibdaught);
        }
    }
    return niece;

};
std::set<Person*> Person::parents(PMod pmod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    std::set<Person*> sibs;
    if (pmod==PMod::ANY && smod==SMod::ANY){
        std::set<Person*> mchild;
        std::set<Person*> dchild;
        mchild=mother()->chilset;
        dchild=father()->chilset;
        sibs=mchild;
        for (Person* child:dchild){
            if(sibs.find(child) == sibs.end()){
                sibs.insert(child);
            }
        }
        sibs.erase(this);
    }
    else if (pmod==PMod::MATERNAL && smod!=SMod::HALF){
        std::set<Person*> mchild;
        mchild=mother()->chilset;
        sibs=mchild;
        sibs.erase(this);
    }
    else if (pmod==PMod::PATERNAL && smod!=SMod::HALF){
        std::set<Person*> dchild;
        dchild=father()->chilset;
        sibs=dchild;
        sibs.erase(this);
    }
    else if (pmod==PMod::MATERNAL && smod==SMod::HALF){
        std::set<Person*> mchild;
        std::set<Person*> dchild;
        mchild=mother()->chilset;
        dchild=father()->chilset;
        sibs=mchild;
        for (Person* child:dchild){
            if(sibs.count(child)){
                sibs.erase(child);
            }
        }
        sibs.erase(this);
    }
    else if (pmod==PMod::PATERNAL && smod==SMod::HALF){
        std::set<Person*> mchild;
        std::set<Person*> dchild;
        mchild=mother()->chilset;
        dchild=father()->chilset;
        sibs=dchild;
        for (Person* child:mchild){
            if(sibs.count(child)){
                sibs.erase(child);
            }
        }
        sibs.erase(this);
    }
    else if (pmod==PMod::ANY && smod==SMod::HALF){
        std::set<Person*> mhlfsibs;
        std::set<Person*> phlfsibs;
        mhlfsibs=siblings(PMod::MATERNAL,SMod::HALF);
        phlfsibs=siblings(PMod::PATERNAL,SMod::HALF);
        for (Person* phs:phlfsibs){
            sibs.insert(phs);
        }
        for (Person* mhs:mhlfsibs){
            sibs.insert(mhs);
        }
    }
    else if(smod==SMod::FULL){
        std::set<Person*> allsibs;
        std::set<Person*> hfsibs;
        allsibs=siblings(PMod::ANY,SMod::ANY);
        hfsibs=siblings(PMod::ANY,SMod::HALF);
        sibs=allsibs;
        for(Person* sib:hfsibs){
            if (sibs.find(sib) != sibs.end()){
                sibs.erase(sib);
            }
        }
    }

    return sibs;

};
std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    std::set<Person*> sis;
    std::set<Person*> sibs;
    sibs=siblings(pmod,smod);
    for (Person* person:sibs){
        if (person->gend==Gender::FEMALE){
            sis.insert(person);
        }
    }
    return sis;

};
std::set<Person*> Person::sons(){
    std::set<Person*> childrenset=children();
    std::set<Person*> sonset;
    for (Person* person: childrenset){
        if (person->gend==Gender::MALE){
            sonset.insert(person);
        } 
    }
    return sonset;
};
std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    std::set<Person*> myset;
    return myset;

};


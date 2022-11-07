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
    std::set<Person*> ancs;
    if (pmod==PMod::MATERNAL){
        std::set<Person*> anct;
        if(mother()!=nullptr){
            anct.insert(mother());
            ancs.insert(mother());
        }
        
        std::set<Person*> anctt;
        while (!anct.empty()){
            anct.clear();
            for (Person* anc:ancs){
                for(Person* ancp:anc->parents()){
                    if (!ancs.count(ancp)){
                        ancs.insert(ancp);
                        anct.insert(ancp);
                    }
                } 
            }
        }
    }
    else if(pmod==PMod::PATERNAL){
        std::set<Person*> anct;
        if(father()!=nullptr){
        anct.insert(father());
        ancs.insert(father());
        }
       
        std::set<Person*> anctt;
        while (!anct.empty()){
            anct.clear();
            for (Person* anc:ancs){
                for(Person* ancp:anc->parents()){
                    if (!ancs.count(ancp)){
                        ancs.insert(ancp);
                        anct.insert(ancp);
                    }
                } 
            }
        }
    }
    else{
        std::set<Person*> anct;
        anct=parents();
        ancs=parents();
        std::set<Person*> anctt;
        while (!anct.empty()){
            anct.clear();
            for (Person* anc:ancs){
                for(Person* ancp:anc->parents()){
                    if (!ancs.count(ancp)){
                        ancs.insert(ancp);
                        anct.insert(ancp);
                    }
                } 
            }
        }
    }

    return ancs;
};
std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    std::set<Person*> auntset;
    if(pmod==PMod::MATERNAL){
        if(mother()!=nullptr){
             auntset=mother()->sisters(PMod::ANY,smod);
        }
       
    }
    else if(pmod==PMod::PATERNAL){
        if (father()!=nullptr){
            auntset=father()->sisters(PMod::ANY,smod);
        }
    }
    else{
        if(mother()!=nullptr){
             auntset=mother()->sisters(PMod::ANY,smod);
        }
        if (father()!=nullptr){
            std::set<Person*> fsibs=father()->sisters(PMod::ANY,smod);
            for (Person* fasib:fsibs){
                auntset.insert(fasib);
                }
        }

}
    return auntset;

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
    std::set<Person*> couset;
    if (pmod==PMod::MATERNAL){
        std::set<Person*> msibs;
        if(mother()!=nullptr){
            msibs=mother()->siblings(PMod::ANY,smod);
            for(Person* sib:msibs){
                std::set<Person*> sibschid;
                sibschid=sib->children();
                for (Person* cous:sibschid){
                    couset.insert(cous);
                }
            }    
        }
    }
    else if (pmod==PMod::PATERNAL){
        std::set<Person*> fsibs;
        if(father()!=nullptr){
            fsibs=father()->siblings(PMod::ANY,smod);
            for(Person* sib:fsibs){
                std::set<Person*> sibschid;
                sibschid=sib->children();
                for (Person* cous:sibschid){
                    couset.insert(cous);
                }
            }    
        }
    }
    else{
        std::set<Person*> mcousset; 
        std::set<Person*> pcousset;
        mcousset=cousins(PMod::MATERNAL,smod);
        pcousset=cousins(PMod::PATERNAL,smod);
        couset=mcousset;
        for(Person* pcous:pcousset){
            couset.insert(pcous);
        }
    }
    return couset;

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
    std::set<Person*> desc;
    std::set<Person*> desct;
    desct=children();
    desc=children();
    while (!desct.empty()){
        desct.clear();
        for (Person* des:desc){
            for(Person* desp:des->children()){
                if (!desc.count(desp)){
                    desc.insert(desp);
                    desct.insert(desp);
                }
            } 
        }
    }

return desc;
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
    grchildren=grandchildren();
    for (Person* gc: grchildren){
        if(gc->gend==Gender::FEMALE){
            gdaughts.insert(gc);
        }
    }
    return gdaughts;

};
std::set<Person*> Person::grandfathers(PMod pmod){
    std::set<Person*> gms;
    if (pmod==PMod::MATERNAL){
        if(mother()!=nullptr && mother()->father()!=nullptr){
            gms.insert(mother()->dad);
        }
       
    }
    else if (pmod==PMod::PATERNAL){
       if(father()!=nullptr && father()->father()!=nullptr){
            gms.insert(father()->dad);
        }
    }
    else{
       if(mother()!=nullptr && mother()->father()!=nullptr){
            gms.insert(mother()->dad);
        }
        if(father()!=nullptr && father()->father()!=nullptr){
            gms.insert(father()->dad);
        }
    }
    return gms;
};
std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> gms;
    if (pmod==PMod::MATERNAL){
        if(mother()!=nullptr && mother()->mother()!=nullptr){
            gms.insert(mother()->mom);
        }
       
    }
    else if (pmod==PMod::PATERNAL){
       if(father()!=nullptr && father()->mother()!=nullptr){
            gms.insert(father()->mom);
        }
    }
    else{
       if(mother()!=nullptr && mother()->mother()!=nullptr){
            gms.insert(mother()->mom);
        }
        if(father()!=nullptr && father()->mother()!=nullptr){
            gms.insert(father()->mom);
        }
    }
    return gms;

};
std::set<Person*> Person::grandparents(PMod pmod){
    std::set<Person*> gps;
    std::set<Person*> gms;
    std::set<Person*> gfs;
    gms=grandmothers(pmod);
    gfs=grandfathers(pmod);
    for (Person* gp :gfs){
        gps.insert(gp);
    }
    for (Person* gm :gms){
        gps.insert(gm);
    }
    return gps;

};
std::set<Person*> Person::grandsons(){
    std::set<Person*> grchildren;
    std::set<Person*> gsons;
    grchildren=grandchildren();
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
    std::set<Person*> parts;
    if(pmod==PMod::ANY){
        if (mother()!=nullptr){
            parts.insert(mother());
        }
        if (father()!=nullptr){
            parts.insert(father());
        }
    }
    else if (pmod==PMod::MATERNAL){
        if (mother()!=nullptr){
            parts.insert(mother());
        }
    }
    else if (pmod==PMod::PATERNAL){
        if (father()!=nullptr){
            parts.insert(father());
        }
    }
    return parts;

};
std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    std::set<Person*> sibs;
    if (pmod==PMod::ANY && smod==SMod::ANY){
        std::set<Person*> mchild;
        std::set<Person*> dchild;
        if (mother()!=nullptr){
            mchild=mother()->chilset;
            sibs=mchild;
        }
        if (father()!=nullptr){
            dchild=father()->chilset;
            for (Person* child:dchild){
                if(!sibs.count(child)){
                    sibs.insert(child);
                }
            }
        }
        if (!sibs.empty()){
            sibs.erase(this);
        }
        
    }
    else if (pmod==PMod::MATERNAL && smod!=SMod::HALF){
        std::set<Person*> mchild;
        if (mother()!=nullptr){
            mchild=mother()->chilset;
            sibs=mchild;
            sibs.erase(this);
        }
    }
    else if (pmod==PMod::PATERNAL && smod!=SMod::HALF){
        std::set<Person*> dchild;
        if (father()!=nullptr){
            dchild=father()->chilset;
            sibs=dchild;
            sibs.erase(this);
        }
    }
    else if (pmod==PMod::MATERNAL && smod==SMod::HALF){
        std::set<Person*> mchild;
        std::set<Person*> dchild;
        if (mother()!=nullptr){
            mchild=mother()->chilset;
            sibs=mchild;
        }
        if(father()!=nullptr){
            dchild=father()->chilset;
            for (Person* child:dchild){
                if(sibs.count(child)){
                    sibs.erase(child);
                }
            }
        }
        if(!sibs.empty()){
            sibs.erase(this);
        }
        
    }
    else if (pmod==PMod::PATERNAL && smod==SMod::HALF){
        std::set<Person*> mchild;
        std::set<Person*> dchild;
        if (father()!=nullptr){
            dchild=father()->chilset;
            sibs=dchild;
        }
        if(mother()!=nullptr){
            mchild=mother()->chilset;
            for (Person* child:mchild){
                if(sibs.count(child)){
                    sibs.erase(child);
                }
            }
        }
        if(!sibs.empty()){
            sibs.erase(this);
        }
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
    std::set<Person*> uncset;
    if(pmod==PMod::MATERNAL){
        if(mother()!=nullptr){
            uncset=mother()->brothers(PMod::ANY,smod);
        }
    }
    else if(pmod==PMod::PATERNAL){
        if (father()!=nullptr){
            uncset=father()->brothers(PMod::ANY,smod);
        }
    }
    else{
        if(mother()!=nullptr){
            uncset=mother()->brothers(PMod::ANY,smod);
        }
        if (father()!=nullptr){
            std::set<Person*> fsibs=father()->brothers(PMod::ANY,smod);
            for (Person* fasib:fsibs){
             uncset.insert(fasib);
            }
        }
    }
    return uncset;
};


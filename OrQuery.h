//
// Created by john on 5/17/19.
//

#ifndef CPPPRIMERQUERYE_ORQUERY_H
#define CPPPRIMERQUERYE_ORQUERY_H


#include "BinaryQuery.h"

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&,const Query&);
    OrQuery(const Query& left,const Query& right)
        : BinaryQuery(left,right,"|")
    {}
    QueryResult eval(const TextQuery&)const;
};

inline Query operator|(const Query& lhs,const Query& rhs){
    return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

#endif //CPPPRIMERQUERYE_ORQUERY_H

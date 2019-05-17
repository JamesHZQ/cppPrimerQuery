//
// Created by john on 5/17/19.
//

#ifndef CPPPRIMERQUERYE_ANDQUERY_H
#define CPPPRIMERQUERYE_ANDQUERY_H

#include "BinaryQuery.h"

class AndQuery:public BinaryQuery {
friend Query operator&(const Query&,const Query&);
AndQuery(const Query& left, const Query& right)
    :BinaryQuery(left,right,"&")
{}

QueryResult eval(const TextQuery&)const;
};

inline
Query operator&(const Query& lhs,const Query& rhs){
    return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}


#endif //CPPPRIMERQUERYE_ANDQUERY_H

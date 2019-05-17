//
// Created by john on 5/16/19.
//

#ifndef CPPPRIMERQUERYE_NOTQUERY_H
#define CPPPRIMERQUERYE_NOTQUERY_H


#include "Query.h"

class NotQuery: public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query& q):query(q){}
    std::string rep()const{
        return "~("+query.rep()+")";
    }
    QueryResult eval(const TextQuery&)const;
    Query query;
};

inline Query operator~(const Query& operand){
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}


#endif //CPPPRIMERQUERYE_NOTQUERY_H

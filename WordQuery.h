//
// Created by john on 5/16/19.
//

#ifndef CPPPRIMERQUERYE_WORDQUERY_H
#define CPPPRIMERQUERYE_WORDQUERY_H


#include "Query_base.h"

class WordQuery: public Query_base {
    friend class Query;
    WordQuery(const std::string& s):query_word(s){};

    QueryResult eval(const TextQuery& t)const{
        return t.query(query_word);
    }
    std::string rep()const{
        return query_word;
    }
    std::string query_word;
};


#endif //CPPPRIMERQUERYE_WORDQUERY_H

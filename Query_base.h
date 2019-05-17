//
// Created by john on 5/16/19.
//

#ifndef CPPPRIMERQUERYE_QUERY_BASE_H
#define CPPPRIMERQUERYE_QUERY_BASE_H


#include "TextQuery.h"

class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep()const = 0;
};


#endif //CPPPRIMERQUERYE_QUERY_BASE_H

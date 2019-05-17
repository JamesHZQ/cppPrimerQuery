//
// Created by john on 5/16/19.
//

#include "NotQuery.h"

using namespace std;

QueryResult NotQuery::eval(const TextQuery& text) const {
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no >>();
    auto beg = result.begin(),end = result.end();
    auto sz = result.get_file()->size();
    for(size_t n = 0;n!=sz;++n){
        if(beg==end||*beg != n)
            ret_lines->insert(n);
        else if(beg != end)
            ++beg;
    }
    return QueryResult(rep(),ret_lines,result.get_file());
}
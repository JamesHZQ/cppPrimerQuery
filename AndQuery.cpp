//
// Created by john on 5/17/19.
//

#include "AndQuery.h"
#include <algorithm>
using namespace std;

QueryResult AndQuery::eval(const TextQuery& text) const {
    auto left = lhs.eval(text),right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no >>();
    set_intersection(left.begin(),left.end(),right.begin(),right.end(),
                        inserter(*ret_lines,ret_lines->begin()));
    return QueryResult(rep(),ret_lines,left.get_file());
}

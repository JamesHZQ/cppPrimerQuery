//
// Created by john on 5/16/19.
//

#ifndef CPPPRIMERQUERYE_TEXTQUERY_H
#define CPPPRIMERQUERYE_TEXTQUERY_H

#include "QueryResult.h"

#include <map>
#include <fstream>
#include <sstream>

class TextQuery {
public:
    using line_no = QueryResult::line_no ;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,std::shared_ptr<std::set<line_no>>> wm;
};


#endif //CPPPRIMERQUERYE_TEXTQUERY_H

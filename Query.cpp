//
// Created by john on 5/17/19.
//

#include "Query.h"

std::ostream& operator<<(std::ostream& os, const Query& query){
    return os<<query.rep();
}
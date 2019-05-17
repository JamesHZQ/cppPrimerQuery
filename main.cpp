#include <iostream>
#include <stack>
#include <cctype>
//#include "TextQuery.h"
#include "Query.h"
#include "AndQuery.h"
#include "NotQuery.h"
#include "OrQuery.h"
using namespace std;
//const map<char,int> opMap{make_pair('|')};
vector<string> bolanExp(string& originExp){
    stack<char> s;
    vector<string> bExp;
    auto it = originExp.begin();
    while(it!=originExp.end()){
        if(*it=='|'||*it=='&'||*it=='~'||*it=='('||*it==')'){
            if(s.empty())
                s.push(*it);
            else{
                if(*it=='(')
                    s.push('(');
                else if(*it==')'){
                    while(!s.empty()&&s.top()!='('){
                        bExp.push_back(string(1,s.top()));
                        s.pop();
                    }
                    s.pop();
                }else{
                    if(*it=='~'){
                        if(s.top()=='~')
                            bExp.push_back(string(1,'~'));
                        else
                            s.push('~');
                    }else{
                        if(s.top()=='~'){
                            bExp.push_back(string(1,'~'));
                            s.pop();
                            if(!s.empty()&&(s.top()=='&'|s.top()=='|'))
                                bExp.push_back(string(1,s.top())),s.pop();
                            s.push(*it);
                        }else if(s.top()=='('){
                            s.push(*it);
                        }else{
                            bExp.push_back(string(1,s.top()));
                            s.pop();
                            s.push(*it);
                        }
                    }
                }
            }
            ++it;
        } else{
            auto itt = it;
            while(it!=originExp.end()&&isalnum(*it)){
                ++it;
            }
            bExp.push_back(string(itt,it));
        }
    }
    while(!s.empty()){
        bExp.push_back(string(1,s.top()));
        s.pop();
    }
    return bExp;
}
Query getAnswer(vector<string>& bExp){
    stack<Query> s;
    for(auto &a:bExp){
        if(a=="|"||a=="&"||a=="~"){
            switch (a[0]){
                case '~':
                {
                    auto temp = ~s.top();
                    s.pop();
                    s.push(temp);
                }
                    break;
                case '&':
                {
                    auto temp = s.top();
                    s.pop();
                    temp = s.top()&temp;
                    s.pop();
                    s.push(temp);
                }
                break;
                case '|':
                {
                    auto temp = s.top();
                    s.pop();
                    temp = s.top()|temp;
                    s.pop();
                    s.push(temp);
                }
                break;
                default:
                    break;
            }
        }else{
            s.push(Query(a));
        }
    }
    return s.top();
}
//int main() {
//    ifstream in("../data");
//    TextQuery tq(in);
//    string s;
//    while(cin>>s){
//        auto res = tq.query(s);
//        print(cout,res);
//    }
//
//    return 0;
//}
int main(){
    ifstream in("../data");
    TextQuery tq(in);
    vector<string> v;
//    string s="man&~(can|is)";
    string s;
    while(cin>>s){
        v=bolanExp(s);
        Query res = getAnswer(v);
        auto outRes = res.eval(tq);
        print(cout,outRes);
    }

//    Query q = (Query(string("man")) | Query(string("thing")));
//    auto res = q.eval(tq);
//    print(cout,res);

    return 0;
}
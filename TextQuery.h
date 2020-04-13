#ifndef TextQueryHelp
#define TextQueryHelp

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#include <set>

using std::string;
using std::vector;
using std::shared_ptr;

class QueryResult;
// The "h" file "define name" must not be same with the identifier.!
class TextQuery {
public:
    using LineNo = vector<string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> input;
    std::map<string, shared_ptr<std::set<LineNo>>> result;
};

class QueryResult {
public:
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(const string& s, shared_ptr<std::set<TextQuery::LineNo>> set,
        shared_ptr<vector<string>> v)
        : word(s), nos(set), input(v)
        {}
private:
    string word;
    shared_ptr<std::set<TextQuery::LineNo>> nos;
    shared_ptr<vector<string>> input;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif
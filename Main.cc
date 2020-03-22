#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <functional>
#include <array>
#include <numeric>
#include <list>
#include <stack>
#include <iterator> // for the istream_iterator
#include <forward_list>
#include <map>
#include <set>
#include <utility>
#include <memory>
#include <isstream>
using std::cin;
using std::cout;
using std::endl;
using std::count_if;
using std::string;
using std::vector;
using std::bind;
using std::placeholders::_1;
using std::placeholders::_2;
using std::list;
using std::stack;
using std::forward_list;
using std::map;
using std::set;
using std::multiset;
using std::shared_ptr;
using std::unique_ptr;
using std::allocator;
using std::ifstream;

class QueryResult;
class TextQuery {
    public:
        using line_no = std::vector<string>::size_type;
        TextQuery(std::ifstream&);
        QueryResult query(const std::string&) const;
    private:
        std::shared_ptr<std::vector<std::string>> file;
        std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;                   
};

TextQuery::TextQuery(ifstream &is):file(new vector<string>)
{
    string text;
    while(getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        string word;
        while(line >> word)
        {
            auto &lines = wm[word];
            if(!lines)
                lines.reset(new setMline_no>);
            lines->insert(n);
        }
    }
}

class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
    public:
        QueryResult(std::string s,
            std::shared_ptr<std::set<line_no>> p,
            std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f){};
    private:
        std::string sought;
        std::shared_ptr<std::set<line_no>> lines;
        std::shared_ptr<std::vector<std::string>> file;
};

QueryResult
TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while(true){
        cout << "enter word to look for, or q to quit:";
        string s;
        if(!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

ostream &print(ostream & os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " " << endl;
    for(auto num : *qr.lines)
        os << "\t(line " << num + 1 << ")" << *(qr.file->begin() + num) << endl;
    return os;
}

int main(int argc, char *argv[])
{

} 
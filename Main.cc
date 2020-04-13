#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>
#include <string>
#include <set>
#include "TextQuery.cc"

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::LineNo;
    virtual ~Query_base() = default;
private:
    // virtual function memebre with "=0" is pure virtual function
    // can't inialized.
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

class Query
{
    // these operators need access to the shared_ptr constructor
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&);
    // interface functions:call the corresponding Query_base operations
    QueryResult eval(const TextQuery &t) const {
        return q->eval(t);
    }
    std::string rep() const {
        return q->rep();
    }
private:
    Query(std::shared_ptr<Query_base> query): q(query){}
    std::shared_ptr<Query_base> q;
};

std::ostream &
operator<<(std::ostream &os, const Query &query)
{
    // Query::rep makes a virtual call through its Query_base pointer to rep()
    return os << query.rep();
}

class WordQuery : public Query_base
{
    friend class Query;
    WordQuery(const std::string &s): query_word(s){}
    // concreate class: WordQuery defines all inherited pure virtual functions
    QueryResult eval(const TextQuery &t) const 
        {return t.query(query_word);}
    std::string rep() const { return query_word;}
    std::string query_word;
};

inline
Query::Query(const std::string &s):q(new WordQuery(s)) {}

class NotQuery: public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q) : query(q) {}
    // concrete class: NotQuery defines all inherited pure virtual functions
    std::string rep() const {return "~(" + query.rep() +
        ")";}
    QueryResult eval(const TextQuery&) const;
    Query query;
};
inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s):
        lhs(l), rhs(r), opSym(s){}
    // abstract class: BinaryQuery doestn't define eval
    std::string rep() const {
        return "(" + lhs.rep() + " " 
            + opSym + " "
                + rhs.rep() + ")";
    }
    Query lhs, rhs; // right- and left-hand operands
    std::string opSym; // name of the operator
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "&"){}
    // concrete class: AndQuery inherits rep and defines the remaining pure virtual
    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery 
{
    friend Query operator|(const Query &, const Query&);
    OrQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "|"){}
    QueryResult eval(const TextQuery&) const;
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery& text) const
{
    // virtual calls through the OrQuery members, lhs and rhs
    // the calls to eval return the QueryResult for each operand
    auto right = rhs.eval(text), left = lhs.eval(text);
    // copy the line numbers from the left-hand operand into the result set
    auto ret_lines =
        make_shared<set<line_no>>(left.begin(), left.end());
    // insert lines from the right-hand operand
    ret_lines->insert(right.begin(), right.end());
    // return the new QueryResult representing the union of lhs and rhs
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery& text) const 
{
    // virtual call to eval through the Query operand
    auto result = query.eval(text);
    // start out with an empty result set
    auto ret_lines = make_shared<set<line_no>>();
    // we have to iterate through the lines on which our operand appears
    auto beg = result.begin(), end = result.end();
    // for each line in the input file, if that line is not in result,
    // add that line number to ret_lines
    auto sz = result.get_file()->size();
    for(size_t n = 0; n != sz; ++n){
        // if we haven't processed all the lines in result
        // check whether this line is present
        if(beg == end || *beg  != n)
            ret_lines->insert(n);// if not in result, add this line
        else if (beg != end)
            ++beg; // otherwise get the next line number in result if there is one
        /*
        This part is beautiful to extract the 'not' element
        But the premise is the first element of 'sz' is small than the first element of 'result'
        And both of them are sorted
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}
int main(int argc, char *argv[])
{
    // Query q = Query("fiery") & Query("bird") | Query("wind");
    return 0;
}
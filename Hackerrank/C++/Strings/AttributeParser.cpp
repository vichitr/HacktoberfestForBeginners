#include <limits>
#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <map>
using namespace std;

class HRMLTag
{
public:
    HRMLTag(const string name, const bool close)
    {
        _name = name;
        _close = close;
    }
    string getName() { return _name; }
    bool isClosingTag() { return _close; }
    map<string, string> &getAttr() { return _attributes; }
    vector<HRMLTag> &getNestedTags() { return _nested; }

private:
    bool _close;
    string _name;
    map<string, string> _attributes;
    vector<HRMLTag> _nested;
};
HRMLTag parseTag(const string str)
{
    const string PATTERN = "^<(\\w+)((?:[\\ \\t]*\\w+[\\ \\t]*=[\\ \\t]*\"[^\"]*\")*)[\\ \\t]*>|<\\/(\\w+)\\>$";
    regex outerRegex(PATTERN);
    const string ATTRIB_PATTERN = "[\\ \\t]*(\\w+)[\\ \\t]*=[\\ \\t]*\"([^\"]*)\"";
    regex innerRegex(ATTRIB_PATTERN);
    smatch outerMatch;
    if (regex_match(str, outerMatch, outerRegex))
    {
        HRMLTag result(outerMatch.str(3).empty() ? outerMatch.str(1) : outerMatch.str(3), !outerMatch.str(3).empty());
        smatch innerMatch;
        string innerStr = outerMatch.str(2);
        sregex_iterator beginIt = sregex_iterator(innerStr.begin(), innerStr.end(), innerRegex);
        sregex_iterator endIt = sregex_iterator();
        for (sregex_iterator it = beginIt; it != endIt; ++it)
            result.getAttr().insert(make_pair((*it).str(1), (*it).str(2)));
        return result;
    }
    return HRMLTag("", true);
}
string getQuery(vector<HRMLTag> vec, string q)
{
    const string QUERY_NOT_FOUND = "Not Found!";
    const string PATTERN = "\\.?(\\w+)|\\~(\\w+)";
    regex re(PATTERN);
    sregex_iterator beginIt = sregex_iterator(q.begin(), q.end(), re);
    sregex_iterator endIt = sregex_iterator();
    HRMLTag *currentTag = nullptr;
    for (sregex_iterator it = beginIt; it != endIt; ++it)
    {
        if ((*it).str(2).empty())
        {
            vector<HRMLTag>::iterator resultIt = find_if(
                (currentTag ? currentTag->getNestedTags().begin() : vec.begin()),
                (currentTag ? currentTag->getNestedTags().end() : vec.end()),
                [it](HRMLTag tag) {
                    return tag.getName().compare((*it).str(1)) == 0;
                });
            if (resultIt == (currentTag ? currentTag->getNestedTags().end() : vec.end()))
                return QUERY_NOT_FOUND;
            else
                currentTag = &(*resultIt);
        }
        else
        {
            map<string, string>::iterator resultIt = find_if(currentTag->getAttr().begin(), currentTag->getAttr().end(), [it](const pair<string, string> &p) {
                return p.first.compare((*it).str(2)) == 0;
            });
            if (resultIt == currentTag->getAttr().end())
            {
                return QUERY_NOT_FOUND;
            }
            else
            {
                return (*resultIt).second;
            }
        }
    }
    return QUERY_NOT_FOUND;
}
int main()
{
    unsigned int n, q;
    cin >> n >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<HRMLTag> vec;
    stack<HRMLTag *> st;
    for (unsigned int i = 0; i < n; ++i)
    {
        string str;
        getline(cin, str);
        if (st.empty())
        {
            vec.push_back(parseTag(str));
            st.push(&vec.back());
        }
        else
        {
            st.top()->getNestedTags().push_back(parseTag(str));
            if (st.top()->getNestedTags().back().isClosingTag())
            {
                st.pop();
            }
            else
            {
                st.push(&(st.top()->getNestedTags().back()));
            }
        }
    }
    for (unsigned int i = 0; i < q; ++i)
    {
        string q;
        getline(cin, q);
        cout << getQuery(vec, q) << endl;
    }
    return 0;
}
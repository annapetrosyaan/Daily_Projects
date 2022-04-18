#ifndef _ANALYZER_H_
#define _ANALYZER_H_

#include <fstream>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

namespace Helper{

class Analyzer
{
public:
    Analyzer();
    Analyzer(const Analyzer&) = delete;
    Analyzer& operator=(const Analyzer&) = delete;
    Analyzer(Analyzer&&) = delete;
    Analyzer& operator=(Analyzer&&) = delete;
    ~Analyzer();
public:
    bool generator() noexcept;
private:
    void parser() noexcept;
    void find_foo() noexcept;
    void accumulate() noexcept;
private:
    std::fstream inout;
    std::vector<std::string> tokens;
    std::vector<std::pair<std::string,int>> m_func;  // function name,argument count
    int m_var;
    int m_spec;
    int m_class;
    int m_dir;
};

} // namespace Helper

#endif // _ANALYZER_H_
#include "Analyzer.h"

namespace Helper{
  std::vector<std::string> foo_keys {"void", "return", "(", ")"};

  std::set<std::string> vars {"int", "double", "long", "bool", "char", "void"};

  std::set<std::string> specifiers {"const", "volatile", "private:", "public:"};
} // namespace Helper

Helper::Analyzer::Analyzer() : m_var{},m_spec{},m_class{}
{
  inout.open("text.cpp");
  if(!inout.is_open())
  {
    std::cerr << "file is not open! " << std::endl;
    exit(0);
  }
  parser();
}

void Helper::Analyzer::parser() noexcept
{
  std::string line;
  std::copy(std::istream_iterator<std::string>(inout),
    std::istream_iterator<std::string>(), std::back_inserter(tokens));
  accumulate();
}

void Helper::Analyzer::find_foo() noexcept
{
  //functions
  int open{}, close{};
  std::string str = "";
  while(std::find((tokens.begin() + open +1), tokens.end(), "(") != tokens.end())
  {
    open = std::find((tokens.begin() + open + 1), tokens.end(), "(") - tokens.begin();
    close = std::find((tokens.begin() + close + 1), tokens.end(), ")") - tokens.begin();
     
    str = tokens[open - 1];

    if(close - open != 1)
    {
      int temp = std::count(tokens.begin() + open, tokens.begin()+close,",") + 1;
      m_func.push_back(std::make_pair(str,temp)); 
    } else {
      m_func.push_back(std::make_pair(str , 0));
    }
  } 
}

void Helper::Analyzer::accumulate() noexcept
{
  m_dir = std::count(tokens.begin(),tokens.end(),"#include");
  m_class = std::count(tokens.begin(),tokens.end(),"class");
  find_foo();
  m_var = std::count_if(tokens.begin(),tokens.end(),
    [](const std::string& s){ 
      if(vars.find(s) != vars.end()) 
      {
        return true;
      } return false;
    } );
  m_spec = std::count_if(tokens.begin(),tokens.end(),
    [](std::string s) {  
      if(specifiers.find(s) != specifiers.end()) 
      {
        return true;
      } return false;
    } );
}

bool Helper::Analyzer::generator() noexcept
{
  std::ofstream write("result.txt");
  write <<"Directives count: "<< m_dir << "\n";
  write <<"Classes count: "<< m_class << "\n";
  write <<"Variables count: "<< m_var << "\n";

  for(int i = 0 ; i < m_func.size() ; ++i)
  {
    write << "Function name: " << m_func[i].first << "  ";
    write << "Arguments count: " << m_func[i].second <<"\n";
  }
  write << "Specifiers count: " << m_spec <<"\n";
  write.close();
  return 1;
}

Helper::Analyzer::~Analyzer()
{
  inout.close();
}
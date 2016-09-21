#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>


class TextQuery {
  public:
    typedef std::vector<std::string>::size_type line_no;

    void ReadFile(std::ifstream& in) {
      StoreFile(in);
      LoadMap();
    }

    std::set<line_no> GetWordLine(const std::string& word) const;

    std::string TextLine(line_no) const;

    std::string QueryWord(const std::string& word) const;
  private:
    void StoreFile(std::ifstream& in);
    void LoadMap();

    std::vector<std::string> m_text_;
    std::map<std::string, std::set<line_no>> m_word_map_;
};


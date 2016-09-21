#include <sstream>
#include "TextQuery.h"

std::string TextQuery::QueryWord(const std::string& word) const {
  std::set<TextQuery::line_no> line_nos = GetWordLine(word);

  std::string result;
  for (TextQuery::line_no no: line_nos) {
   result += (TextLine(no) + "\n");
  }
  return result;
}

std::set<TextQuery::line_no> TextQuery::GetWordLine(const std::string& word) const {
  auto iter = m_word_map_.find(word);
  if (iter != m_word_map_.end()) {
    return iter->second;
  } else {
    std::set<TextQuery::line_no> result;
    return result;
  }
}

std::string TextQuery::TextLine(TextQuery::line_no line_num) const {
  if (line_num >= 0 && line_num < m_text_.size()) {
    std::stringstream ss;
    ss <<"(line " << line_num+ 1 <<" ) " << m_text_[line_num];
    return ss.str();
  } else {
    return "";
  }
}

void TextQuery::StoreFile(std::ifstream& in) {
  std::string line;
  while(std::getline(in, line)) {
   m_text_.push_back(line);
   line.clear();
  }
}

void TextQuery::LoadMap() {
  std::string word;
  for (TextQuery::line_no i = 0; i < m_text_.size(); ++i) {
   std::stringstream line(m_text_[i]);
    while (line >> word) {
      auto word_iter = m_word_map_.find(word);
      if (word_iter != m_word_map_.end()){
           word_iter->second.insert(i);
      } else {
         m_word_map_.insert(std::make_pair(word,
	                       std::set<TextQuery::line_no>{i}));
      }
    }  // end while(line >> word)
  }  // end for (std::string line : m_text_)
}

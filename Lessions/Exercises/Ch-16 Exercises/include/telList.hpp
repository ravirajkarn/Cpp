#pragma once

#include <print>
#include <string>
#include <vector>

struct Element {
  std::string name;
  std::string telNum;
};

class TelList {
 private:
  std::vector<Element> directory;
  int count;

 public:
  TelList() {}
  ~TelList() {};
  int getCount() const { return directory.size(); }
  Element* retrieve(int i) {
    return (i >= 0 && i < directory.size() - 1) ? &directory[i] : nullptr;
  }


  bool append(const std::string& name, const std::string& telNum);
  bool erase(const std::string& name);
  int search(const std::string& name);
  void print();
  int print(const std::string& name);
  int getNewEntries();
};

int TelList::search(const std::string& name){
    
}
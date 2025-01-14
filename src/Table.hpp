#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "AVL_Tree.hpp"

class Table {
  private:
    std::vector<AVL_Tree> categories;

  public:
    Table();
    ~Table();
};
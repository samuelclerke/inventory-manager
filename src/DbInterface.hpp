#pragma once
#include <iostream>
#include <fstream>
#include <string>

class DbInterface {
  private:

  public:
    DbInterface();

    void createDb(std::string db_name) {
      std::ofstream database_file(db_name);

      if (database_file.is_open()) {
        std::cout << "Database \"" << db_name << "\" created successfully." << std::endl;
      } else {
        std::cerr << "Unable to create database \"" << db_name << "\"." << std::endl;
      }
    };
    
    ~DbInterface();
};
#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Application {
  private:

  public:
    Application() {
      #if defined(_WIN32) && defined(__x86_64__)
        std::cout << "\033[36mOS: Windows\033[0m\n"<< "\033[36mArchitecture: x86\033[0m" << std::endl;
      #elif defined(_WIN32) && defined(__arm__)
        std::cout << "\033[36mOS: Windows\033[0m\n"<< "\033[36mArchitecture: ARM\033[0m" << std::endl;
      #elif defined(__linux__) && defined(__x86_64__)
        std::cout << "\033[36mOS: Linux\033[0m\n"<< "\033[36mArchitecture: x86\033[0m" << std::endl;
      #elif defined(__linux__) && defined(__arm__)
        std::cout << "\033[36mOS: Linux\033[0m\n"<< "\033[36mArchitecture: ARM\033[0m" << std::endl;
      #elif defined(__APPLE__) && defined(__x86_64__)
        std::cout << "\033[36mOS: MacOS\033[0m\n"<< "\033[36mArchitecture: x86\033[0m" << std::endl;
      #elif defined(__APPLE__) && defined(__arm__)
        std::cout << "\033[36mOS: MacOS\033[0m\n"<< "\033[36mArchitecture: ARM\033[0m" << std::endl;
      #else
        std::cout << "\033[36mRunning on Unknown Environment.\033[0m" << std::endl;
      #endif
    };

    ~Application() {};

    bool run() {
      std::cout << "\n------------------------------------\n" << "\033[33mWelcome to InvManager\033[0m" << "\n------------------------------------\n" << std::endl;
      std::string in_username, in_password;

      // Open (read-only) login.info file to compare with in_username and in_password.
      std::ifstream loginInfo("login.info");

      // Checks for inability to open file. Thus creates one of desired name.
      if (!loginInfo.is_open()) {
          #if defined(__linux__)
            system("chmod +x createLoginInfo.sh");
            int returnCode = system("./createLoginInfo.sh");

            if (returnCode == 0) {
              std::cout << "\033[32mSUCCESS: login.info created.\033[0m" << std::endl;
            }
          #endif
      }

      // Prompt user for Username and Password to access the application.
      std::cout << "Username: ";
      std::cin >> in_username;

      std::cout << "Password: ";
      std::cin >> in_password;

      while(1) {
        int returnCode = login(loginInfo, in_username, in_password);

        if (returnCode <= 0) {
          exit(0);
        } else if (returnCode == 0) {
          return false;
        }
      }
      
    }

    int login(std::ifstream &file, std::string &username, std::string &password) {
      if (file.is_open()) {
          std::cout << "Comparing Username and Password...\n" << std::endl;

          std::string out_username, out_password;
          getline(file, out_username);
          getline(file, out_password);
          file.close();

          if (out_username == username && out_password == password) {
              std::cout << "Login successful!" << std::endl;
              return 0;
          } else {
              std::cout << "NOTICE: Username or Password is incorrect!" << std::endl;
              return 1;
          }
      } else {
          std::cerr << "ERROR: Unable to open 'login.info' file. Please ensure it exists and is accessible." << std::endl;
          return 2;
      }

      // Error
      return -1;
    };
};
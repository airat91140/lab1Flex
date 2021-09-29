//
// Created by airat on 15.09.2021.
//

#ifndef LAB1_DIALOGUE_H
#define LAB1_DIALOGUE_H

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <FlexLexer.h>
#include <sstream>
#include <chrono>

namespace lab1 {

    class Dialogue {
    private:
        char **strings;
        int strNum;
        bool isFast; // if true - the input is from cmd arguments and output is to cmd
        std::ofstream out;
        std::ifstream in;
        std::map<std::string, int> table;

        void runFast();

        std::list<std::string> runFromSource();

        static std::string formResult(const std::string &str, int result);

        void incStat(const std::string &hash);

    public:
        Dialogue(int argc, char *argv[]);

        void run();

        ~Dialogue();

        std::string genInacceptedStr(int len);

        std::string genAcceptedStr(int len);

        void runTiming();
    };
}

#endif //LAB1_DIALOGUE_H

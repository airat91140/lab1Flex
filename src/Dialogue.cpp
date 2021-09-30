//
// Created by airat on 15.09.2021.
//

#include "Dialogue.h"

using std::chrono::steady_clock;

namespace lab1 {
    Dialogue::Dialogue(int argc, char *argv[]) {
        if (argc > 1) {
            isFast = true;
            strings = argv;
            strNum = argc;
        } else {
            isFast = false;
            strings = nullptr;
            strNum = 0;

            std::string answer;
            std::cout << "Input from file? (y/n)" << std::endl;
            std::getline(std::cin, answer);
            if (answer == "y") {
                std::cout << "Enter filename" << std::endl;
                std::getline(std::cin, answer);
                in.open(answer, std::ios::in);
                if (!in)
                    throw std::invalid_argument("Invalid filename");
            }

            std::cout << "Output to file? (y/n)" << std::endl;
            std::getline(std::cin, answer);
            if (answer == "y") {
                std::cout << "Enter filename" << std::endl;
                std::getline(std::cin, answer);
                out.open(answer, std::ios::in); //checking whether file exists
                if (out.good()) {
                    std::string tmp;
                    std::cout << "File already exists. Rewrite it? (y/n)" << std::endl;
                    std::getline(std::cin, tmp);
                    if (tmp == "y") {
                        out.close();
                    } else {
                        in.close();
                        out.close();
                        throw std::invalid_argument("File exists");
                    }
                }
                out.open(answer, std::ios::out | std::ios::trunc);
            }
        }
    }

    void Dialogue::run() {
        if (isFast) {
            runFast();
        } else {
            std::list<std::string> result;
            result = runFromSource();
            for (const auto &it: result) {
                (out.is_open() ? out : std::cout) << it << std::endl;
            }
            (out.is_open() ? out : std::cout) << std::endl;
            for (const auto &it: table) {
                (out.is_open() ? out : std::cout) << it.first << ": " << it.second << std::endl;
            }
        }
    }

    void Dialogue::runFast() {
        if (strcmp(strings[1], "-t") == 0) {
            runTiming();
            return;
        }
        std::stringstream lines;
        for (int i = 1; i < strNum; ++i) {
            lines << strings[i] << std::endl;
        }
        yyFlexLexer checker(&lines);
        int res;
        for (int i = 1; i < strNum; ++i) {
            res = checker.yylex();
            std::cout << formResult(strings[i], res) << std::endl;
            if (res)
                incStat(checker.YYText());
        }
        for (const auto &iter : table)
            std::cout << iter.first << ": " << iter.second << std::endl;
    }

    std::list<std::string> Dialogue::runFromSource() {
        int res;
        if (!in.is_open())
            std::cout << "Enter your strings below" << std::endl;
        std::list<std::string> result;
        yyFlexLexer checker(in.is_open() ? &in : &std::cin);
        do {
            res = checker.yylex();
            if (res == -1)
                break;
            result.push_back(formResult("", res));
            if (res == 1)
                incStat(checker.YYText());
        } while(res >= 0);
        return result;
    }

    Dialogue::~Dialogue() {
        if (in.is_open())
            in.close();
        if (out.is_open())
            out.close();
    }

    std::string Dialogue::formResult(const std::string &str, int result) {
        return str + "  ~  " + (result ? "correct " : "incorrect");
    }

    void Dialogue::incStat(const std::string &hash) {
        try {
            ++table.at(hash);
        }
        catch (std::exception &ex) {
            table.insert({hash, 1});
        }
    }

    void Dialogue::runTiming() {
        steady_clock::duration duration = steady_clock::duration::zero();
        steady_clock::time_point t;
        std::stringstream str;
        srand(time(nullptr));
        yyFlexLexer checker(&str);
        for (int l = 1000000; l <= 10000000; l += 500000) {
            {
                duration = steady_clock::duration::zero();
                str << genAcceptedStr(l) << std::endl;
                t = std::chrono::steady_clock::now();
                checker.yylex();
                duration += std::chrono::steady_clock::now() - t;
            }
            {
                str << genInacceptedStr(l) << std::endl;
                t = std::chrono::steady_clock::now();
                checker.yylex();
                duration += std::chrono::steady_clock::now() - t;
            }
            std::cout/* << "symbols: " */<< 50 + l * 2 << " "/*" time: "*/ << duration.count() << std::endl;
        }
    }

// ed2k://|file|имя_файла|размер_файла|хэш_файла|/
    std::string Dialogue::genAcceptedStr(int len) {
        std::string str = "ed2k://|file|";
        str.reserve(50 + len * 2 );
        for (int i = 0; i < len; ++i) {
            str += rand() % ('z' - 'a' + 1) + (rand() & 1 ? 'a' : 'A');
        }
        str += '|';
        for (int i = 0; i < len; ++i) {
            str += rand() % ('9' - '0' + 1) + '0';
        }
        str += '|';
        for (int i = 0; i < 32; ++i) {
            str += (rand() & 1) ? ((rand() % ('9' - '0' + 1)) + '0') : (rand() % ('f' - 'a' + 1) + (rand() & 1 ? 'a' : 'A')); //generating random hash
        }
        str += "|/";
        return str;
    }

    std::string Dialogue::genInacceptedStr(int len) {
        std::string str;
        str.reserve(50 + len * 2);
        for (int i = 0; i < 50 + len * 2; ++i) {
            str += rand() % ('~' - '(' + 1) + '(';
        }
        return str;
    }
}

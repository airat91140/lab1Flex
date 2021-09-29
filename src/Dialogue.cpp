//
// Created by airat on 15.09.2021.
//

#include "Dialogue.h"


namespace lab1 {
    /*Dialogue::Dialogue(int argc, char *argv[]) {
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
                (out.is_open() ? out : std::cout) << it.first.getHash() << ": " << it.second << std::endl;
            }
        }
    }

    void Dialogue::runFast() {
        if (strcmp(strings[1], "-t") == 0) {
            CheckStr Checker;
            Checker.runTiming();
            return;
        }
        CheckStr checker;
        for (int i = 1; i < strNum; ++i) {
            checker.check(strings[i]);
            incStat(checker.getHash());
            std::cout << formResult(strings[i], checker) << std::endl;
        }
    }

    std::list<std::string> Dialogue::runFromSource() {
        if (!in.is_open())
            std::cout << "Enter your strings below" << std::endl;
        std::string line;
        std::list<std::string> result;
        CheckStr checker;
        while (std::getline(in.is_open() ? in : std::cin, line)) {
            checker.check(line);
            if (checker.getIsAccepted())
                incStat(checker.getHash());
            result.push_back(formResult(line, checker));
        }
        return result;
    }

    Dialogue::~Dialogue() {
        if (in.is_open())
            in.close();
        if (out.is_open())
            out.close();
    }

    std::string Dialogue::formResult(const std::string &str, const CheckStr &checker) {
        bool result = checker.getIsAccepted();
        return str + "  ~  " + (result ? "correct " : "incorrect");
    }

    void Dialogue::incStat(const Hash &hash) {
        try {
            ++table.at(hash);
        }
        catch (std::exception &ex) {
            table.insert({hash, 1});
        }
    }*/
}
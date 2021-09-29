//
// Created by airat on 12.09.2021.
//

#ifndef LAB1_HASH_H
#define LAB1_HASH_H

#include <string>

namespace lab1 {
    class Hash {
    private:
        std::string str; // field in which hash is stored
        int max; // number of letters in hash
    public:
        Hash(const char *str, int max);

        [[nodiscard]] bool isUnderOrEqMax() const; // return true if number of letter in hash <= max

        [[nodiscard]] bool isEqMax() const; // return true if number of letter in hash == max

        [[nodiscard]] int getLen() const; // returns the len of hash

        [[nodiscard]] int getMax() const;

        void setMax(int max_);

        explicit Hash(int max_ = 32);

        void append(char c); // pushes one char at the end of hash

        void reset(); // emptifies string

        [[nodiscard]] std::string getHash() const;

        bool operator==(const Hash &other) const;

        bool operator<(const Hash &other) const;
    };
}

#endif //LAB1_HASH_H

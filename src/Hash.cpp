//
// Created by airat on 12.09.2021.
//

#include "Hash.h"

namespace lab1 {

    void Hash::append(char c) {
        str.push_back(c);
    }

    void Hash::reset() {
        str = "";
        str.reserve(max);
    }

    std::string Hash::getHash() const {
        return str;
    }

    Hash::Hash(int max_) : max(max_) {
        str.reserve(max_);
    }

    bool Hash::isUnderOrEqMax() const {
        return str.length() <= max;
    }

    bool Hash::isEqMax() const {
        return str.length() == max;
    }

    int Hash::getLen() const {
        return str.length();
    }

    int Hash::getMax() const {
        return max;
    }

    void Hash::setMax(int max_) {
        Hash::max = max_;
    }

    bool Hash::operator==(const Hash &other) const {
        return this->str == other.str;
    }

    bool Hash::operator<(const Hash &other) const {
        return this->str < other.str;
    }

    Hash::Hash(const char *str, int max) {
        this->str = str;
        this->max = max;
    }
}
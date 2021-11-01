#include "Tokenizer.h"

#include <cctype>
#include <string_view>


bool plex::Tokenizer::isDelimiter(std::string_view ch) const {
    for (const auto &elem: plex::Tokenizer::Delimiter) {
        if (ch == elem) {
            return true;
        }
    }
    return false;
}

bool plex::Tokenizer::isIdentifier(std::string_view ch) const {
    if (ch.size() <= 0) {
        return false;
    } else if (ch.at(0) == '_' || std::isalpha(ch.at(0))) {
        for (const auto &elem: ch) {
            if (std::isalnum(elem) || elem == '_') {
                continue; 
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

bool plex::Tokenizer::isKeyword(std::string_view ch) const {
    for (const auto &elem: plex::Tokenizer::Keyword) {
        if (ch == elem) {
            return true;
        }
    }
    return false;
}

bool plex::Tokenizer::isLiteral(std::string_view ch) const {
    if (ch.size() <= 0) {
        return false;
    } else if (ch.at(0) == '"') {
        for (const auto &elem: ch) {
            if (std::isalnum(elem)) {
                continue; 
            } else {
                return false;
            }
        }
    } else {
        for (const auto &elem: ch) {
            if (std::isdigit(elem)) {
                continue; 
            } else {
                return false;
            }
        }
    }
    return true;
}


bool plex::Tokenizer::isOperator(std::string_view ch) const {
    for (const auto &elem: plex::Tokenizer::Operator) {
        if (ch == elem) {
            return true;
        }
    }
    return false;
}

bool plex::Tokenizer::isSymbol(std::string_view ch) const {
    for (const auto &elem: plex::Tokenizer::Symbol) {
        if (ch == elem) {
            return true;
        }
    }
    return false;
}

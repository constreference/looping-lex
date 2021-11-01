#include "Tokenizer.h"
#include "Lexer.h"

#include <fstream>
#include <sstream>
#include <vector>

#include <omp.h>


namespace lexer {
    template <typename T>
    void split(const std::string &in, char delim, T result) {
        std::istringstream iss(in);
        std::string token;
        while (std::getline(iss, token, delim)) {
            *result++ = token;
        }
    }

    std::vector<std::string> split(const std::string &in, char delim) {
        std::vector<std::string> tokens;
        split(in, delim, std::back_inserter(tokens));
        return tokens;
    }  
}; // namespace lexer


plex::Lexer::Lexer(const std::filesystem::path &path) {
    this->t = new Tokenizer;
    if (std::filesystem::is_regular_file(path)) {
        std::ifstream f(path, std::ios::in);
        const auto filesize = std::filesystem::file_size(path);
        contents.resize(filesize, '\0');
        f.read(contents.data(), filesize);
    }
}

plex::Lexer::Lexer(const std::filesystem::path& path, bool accelerate) : accelerate(accelerate) {
    this->t = new Tokenizer;
    if (std::filesystem::is_regular_file(path)) {
        std::ifstream f(path, std::ios::in);
        const auto filesize = std::filesystem::file_size(path);
        contents.resize(filesize, '\0');
        f.read(contents.data(), filesize);
    }
}

void plex::Lexer::scanline(const std::string &line) {
    std::vector<std::string> tokens = lexer::split(line, ' ');
    std::string buffer;
    for (const auto &token: tokens) {
        if (token.empty()) {
            continue;
        }
        buffer.append(token + ": ");
        if (isKeyword(token)) {
            buffer.append("T_KEYWORD\n");
        } else if (isOperator(token)) {
            buffer.append("T_OPERATOR\n");
        } else if (isSymbol(token)) {
            buffer.append("T_SYMBOL\n");
        } else if (isIdentifier(token)) {
            buffer.append("T_IDENTIFIER\n");
        } else if (isLiteral(token)) {
            buffer.append("T_LITERAL\n");
        } else {
            buffer.append("T_UNKNOWN\n");
        }
    }
}

void plex::Lexer::pscan() {
    std::vector<std::string> lines = lexer::split(contents, '\n');
    #pragma omp parallel for
    for (const auto &line: lines)  {
        scanline(line);
    }
}

void plex::Lexer::scan() {
    std::vector<std::string> lines = lexer::split(contents, '\n');
    for (const auto &line: lines)  {
        scanline(line);
    }
}

void plex::Lexer::Scan() {
    if (accelerate) {
        pscan();
    } else {
        scan();
    }
}


plex::Lexer::~Lexer() {
    delete t;
}

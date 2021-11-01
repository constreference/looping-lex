#pragma once

#include "Tokenizer.h"

#include <filesystem>
#include <string>


namespace plex {
    class Lexer : protected Tokenizer {
        private:
            Tokenizer *t;
            std::string contents; //<! file contents
            bool accelerate;
            void scanline(const std::string &line);
            void scan();
            void pscan();

        public:
            Lexer(const std::filesystem::path& p);
            Lexer(const std::filesystem::path& p, bool accelerate);
            ~Lexer();
            void Scan();
    };
}

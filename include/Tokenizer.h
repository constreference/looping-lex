#pragma once

#include <string_view>


namespace plex { 

    class Tokenizer {
        private:
            static constexpr std::string_view Delimiter[] {
                " ",
                "\t",
                "\n",
                ","
            };


            static constexpr std::string_view Keyword[] {
                "if",
                "else",
                "switch",
                "case",
                "for",
                "while",
                "if",
                "else", 
                "int",
                "float",
                "double",
                "long",
                "short",
                "do",
                "char",
                "return",
                "auto",
                "struct",
                "union",
                "break",
                "const",
                "unsigned",
                "switch",
                "continue",
                "signed",
                "void",
                "case", 
                "enum",
                "register",
                "typedef",
                "default",
                "goto",
                "extern",
                "static",
                "volatile"
            };
        
            static constexpr std::string_view Operator[] {
                "+",
                "-",
                "/",
                "*",
                "%",
                "<",
                ">",
                "=", 
                "!",
                "&",
                "|",
                "^",
                "<<",
                ">>",
                "sizeof"
            };
        
        
            static constexpr std::string_view Symbol[] {
                "(",
                ")",
                "{",
                "}",
                ";",
                "[",
                "]"
            };
        
        protected: 
            bool isDelimiter(std::string_view ch) const;
            bool isIdentifier(std::string_view ch) const;
            bool isKeyword(std::string_view ch) const;
            bool isLiteral(std::string_view ch) const;
            bool isOperator(std::string_view ch) const;
            bool isSymbol(std::string_view ch) const;
    };
}

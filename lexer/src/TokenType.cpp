#include "TokenType.h"

namespace dem {
    namespace lexer {
        std::ostream &operator<<(std::ostream &output, const TokenType &tokenType) {
            std::string str;

            switch(tokenType) {
                case TokenType::BOOL:
                    str = "BOOL";
                    break;
                case TokenType::TEXT:
                    str = "TEXT";
                    break;
                case TokenType::NUMBER:
                    str = "NUMBER";
                    break;
                case TokenType::COMMA:
                    str = "COMMA";
                    break;
                case TokenType::PERIOD:
                    str = "PERIOD";
                    break;
                case TokenType::POSITIVE:
                    str = "POSITIVE";
                    break;
                case TokenType::NEGATIVE:
                    str = "NEGATIVE";
                    break;
                case TokenType::PLUS:
                    str = "PLUS";
                    break;
                case TokenType::MINUS:
                    str = "MINUS";
                    break;
                case TokenType::TIMES:
                    str = "TIMES";
                    break;
                case TokenType::DIVIDE:
                    str = "DIVIDE";
                    break;
                case TokenType::MOD:
                    str = "MOD";
                    break;
                case TokenType::EXP:
                    str = "EXP";
                    break;
                case TokenType::TEQ:
                    str = "TEQ";
                    break;
                case TokenType::EQ:
                    str = "EQ";
                    break;
                case TokenType::NEQ:
                    str = "NEQ";
                    break;
                case TokenType::TNEQ:
                    str = "TNEQ";
                    break;
                case TokenType::SM:
                    str = "SM";
                    break;
                case TokenType::SMEQ:
                    str = "SMEQ";
                    break;
                case TokenType::LR:
                    str = "LR";
                    break;
                case TokenType::LREQ:
                    str = "LREQ";
                    break;
                case TokenType::NOT:
                    str = "!";
                    break;
                case TokenType::AND:
                    str = "AND";
                    break;
                case TokenType::OR:
                    str = "OR";
                    break;
                case TokenType::FOR:
                    str = "FOR";
                    break;
                case TokenType::IN:
                    str = "IN";
                    break;
                case TokenType::ELSE:
                    str = "ELSE";
                    break;
                case TokenType::NEW:
                    str = "NEW";
                    break;
                case TokenType::IF:
                    str = "IF";
                    break;
                case TokenType::WHILE:
                    str = "WHILE";
                    break;
                case TokenType::CONTINUE:
                    str = "CONTINUE";
                    break;
                case TokenType::BREAK:
                    str = "BREAK";
                    break;
                case TokenType::RETURN:
                    str = "RETURN";
                    break;
                case TokenType::TRACK:
                    str = "TRACK";
                    break;
                case TokenType::START:
                    str = "START";
                    break;
                case TokenType::END:
                    str = "END";
                    break;
                case TokenType::OPEN:
                    str = "OPEN";
                    break;
                case TokenType::CLOSE:
                    str = "CLOSE";
                    break;
                case TokenType::BRACKET_OPEN:
                    str = "BRACKET_OPEN";
                    break;
                case TokenType::BRACKET_CLOSE:
                    str = "BRACKET_CLOSE";
                    break;
                case TokenType::PLAY:
                    str = "PLAY";
                    break;
                case TokenType::FUNCTION:
                    str = "FUNCTION";
                    break;
                case TokenType::VAR:
                    str = "VAR";
                    break;
                case TokenType::TERMINATOR:
                    str = "TERMINATOR";
                    break;
                case TokenType::ASSIGNMENT:
                    str = "ASSIGNMENT";
                    break;
                case TokenType::IDENTIFIER:
                    str = "IDENTIFIER";
                    break;
                case TokenType::UNKNOWN:
                    str = "UNKNOWN";
                    break;
            }

            return output << str;
        }
    }
}

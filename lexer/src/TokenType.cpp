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
                case TokenType::IN_ARRAY:
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
                case TokenType::NOTE:
                    str = "NOTE";
                    break;
                case TokenType::ACCIDENTAL:
                    str = "ACCIDENTAL";
                    break;
                case TokenType::CHORD:
                    str = "CHORD";
                    break;
                case TokenType::DURATION:
                    str = "DURATION";
                    break;
                case TokenType::HARMONY:
                    str = "HARMONY";
                    break;
                case TokenType::MEASURE:
                    str = "MEASURE";
                    break;
                case TokenType::TUPLET:
                    str = "TUPLET";
                    break;
                case TokenType::TIE:
                    str = "TIE";
                    break;
                case TokenType::ATTACK:
                    str = "ATTACK";
                    break;
                case TokenType::DECAY:
                    str = "DECAY";
                    break;
                case TokenType::COMBINE:
                    str = "COMBINE";
                    break;
                case TokenType::KEY:
                    str = "KEY";
                    break;
                case TokenType::INSTRUMENT:
                    str = "INSTRUMENT";
                    break;
                case TokenType::VOICE:
                    str = "VOICE";
                    break;
                case TokenType::LAYER:
                    str = "LAYER";
                    break;
                case TokenType::TEMPO:
                    str = "TEMPO";
                    break;
                case TokenType::PITCH:
                    str = "PITCH";
                    break;
                case TokenType::PRESSURE:
                    str = "PRESSURE";
                    break;
                case TokenType::POLY_PRESSURE:
                    str = "POLY_PRESSURE";
                    break;
                case TokenType::CONTROLLER:
                    str = "CONTROLLER";
                    break;
                case TokenType::TIME:
                    str = "TIME";
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
                case TokenType::PLAY_START:
                    str = "PLAY_START";
                    break;
                case TokenType::PLAY_END:
                    str = "PLAY_END";
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
                case TokenType::ENDOFFILE:
                    str = "EOF";
                    break;
                case TokenType::SINGLECOMMENT:
                    str = "SINGLECOMMENT";
                    break;
                case TokenType::MULTICOMMENT:
                    str = "MULTICOMMENT";
                    break;
            }

            return output << str;
        }
    }
}

#include <sstream>
#include "factory/SymbolFactory.h"

namespace dem {
    namespace parser {
        bool SymbolFactory::expect(std::deque<lexer::Token> &tokens, lexer::TokenType tokenType, ParseResults &results, bool pop) {
            if(accept(tokens, tokenType, pop))
                return true;

            std::stringstream ss;
            if(tokens.empty()) {
                ss << "Expected '" << tokenType << "', but found nothing.";
                addError(results, lexer::Token::NULL_TOKEN, ss.str());
                return false;
            }

            ss << "Expected '" << tokenType << "', but found " << tokens.front().type();
            addError(results, tokens.front(), ss.str());
            return false;
        }

        bool SymbolFactory::accept(std::deque<lexer::Token> &tokens, lexer::TokenType tokenType, bool pop) {
            if(tokens.front().is(tokenType)) {
                if(pop)
                    tokens.pop_front();
                return true;
            }
            return false;
        }

        void SymbolFactory::addError(ParseResults &results, lexer::Token token, const std::string &description) {
            addError(ParseError::Type::T_ERROR, results, token, description);
        }

        void SymbolFactory::addWarning(ParseResults &results, lexer::Token token, const std::string &description) {
            addError(ParseError::Type::T_WARNING, results, token, description);
        }

        void SymbolFactory::addError(ParseError::Type type, ParseResults &results, lexer::Token token, const std::string &description) {
            std::cout << "[" << token.line() << ":" << token.column() << "]" << "ERROR: " << description << std::endl;
            results.addError(ParseError(type, token, description));
        }
    }
}

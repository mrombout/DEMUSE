#include <sstream>
#include <stack>
#include "exception/ParsingException.h"
#include "factory/NewInstanceFactory.h"
#include "factory/IdentifierFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/FunctionDefinitionFactory.h"
#include "factory/NoteFactory.h"
#include "symbol/expression/ThisExpression.h"
#include "symbol/expression/AdditionExpression.h"
#include "symbol/expression/SubtractionExpression.h"
#include "symbol/expression/MultiplicationExpression.h"
#include "symbol/expression/DivisionExpression.h"
#include "symbol/expression/ModuloExpression.h"
#include "symbol/expression/CallExpression.h"
#include "symbol/expression/MemberExpression.h"
#include "symbol/expression/BoolLiteral.h"
#include "symbol/expression/TextLiteral.h"
#include "symbol/expression/AndCondition.h"
#include "symbol/expression/EqualCondition.h"
#include "symbol/expression/LargerThanCondition.h"
#include "symbol/expression/LargerThanOrEqualCondition.h"
#include "symbol/expression/NotEqualCondition.h"
#include "symbol/expression/OrCondition.h"
#include "symbol/expression/SmallerThanCondition.h"
#include "symbol/expression/SmallerThanOrEqualCondition.h"
#include "symbol/expression/StrictEqualCondition.h"
#include "symbol/expression/StrictNotEqualCondition.h"
#include "symbol/expression/UnaryExpression.h"
#include "symbol/expression/AssignmentExpression.h"
#include "symbol/expression/ExponentExpression.h"
#include "symbol/expression/ArrayAccessExpression.h"
#include "symbol/expression/FunctionDefinition.h"
#include "symbol/Identifier.h"

namespace dem {
    namespace parser {
        const std::map<lexer::TokenType, OperatorInfo> ExpressionFactory::BINARY_OPS = {
            { lexer::TokenType::ASSIGNMENT, { 1, Associativity::RIGHT } },
            { lexer::TokenType::OR,         { 2, Associativity::LEFT } },
            { lexer::TokenType::AND,        { 3, Associativity::LEFT } },
            // TODO: { lexer::TokenType::BW_OR,  3 }
            // TODO: { lexer::TokenType::BW_XOW, 4 }
            // TODO: { lexer::TokenType::BW_AND, 5 },
            { lexer::TokenType::EQ,         { 6, Associativity::LEFT } },
            { lexer::TokenType::NEQ,        { 6, Associativity::LEFT } },
            { lexer::TokenType::TEQ,        { 6, Associativity::LEFT } },
            { lexer::TokenType::TNEQ,       { 6, Associativity::LEFT } },
            { lexer::TokenType::SM,         { 7, Associativity::LEFT } },
            { lexer::TokenType::LR,         { 7, Associativity::LEFT } },
            { lexer::TokenType::SMEQ,       { 7, Associativity::LEFT } },
            { lexer::TokenType::LREQ,       { 7, Associativity::LEFT } },
            // TODO: { lexer::TokenType::BW_SHIFT_LEFT,   8 },
            // TODO: { lexer::TokenType::BW_SHIFT_RIGHT,   8 },
            // TODO: { lexer::TokenType::BW_U_SHIFT_RIGHT,   8 },
            { lexer::TokenType::PLUS,       { 9, Associativity::LEFT } },
            { lexer::TokenType::MINUS,      { 9, Associativity::LEFT } },
            { lexer::TokenType::TIMES,      { 10, Associativity::LEFT } },
            { lexer::TokenType::DIVIDE,     { 10, Associativity::LEFT } },
            { lexer::TokenType::MOD,        { 10, Associativity::LEFT } },
            { lexer::TokenType::EXP,        { 11, Associativity::RIGHT } },
        };

        Expression *ExpressionFactory::produce(std::deque <lexer::Token> &tokens, ParseResults &results) {
            return gobbleExpression(tokens, results);
        }

        Expression *ExpressionFactory::gobbleExpression(std::deque<lexer::Token> &deque, ParseResults &results) {
            Expression *expression = gobbleBinaryExpression(deque, results);
            // TODO: if(deque.front().is(lexer::TokenType::QMARK)) // support for ternary expressions
            return expression;
        }

        Expression *ExpressionFactory::gobbleBinaryExpression(std::deque<lexer::Token> &deque, ParseResults &results) {
            Expression *left = gobbleToken(deque, results);
            lexer::TokenType biop = gobbleBinaryOp(deque);

            if(!left) {
                std::stringstream ss;
                ss << "Expected expression, but found '" << deque.front().type() << "'";
                addError(results, deque.front(), ss.str());
                return left;
            }
            if(biop == lexer::TokenType::UNKNOWN)
                return left;

            Expression *right = gobbleToken(deque, results);
            if(!right) {
                std::stringstream ss;
                ss << "Expected expression after " << biop;
                addError(results, deque.front(), ss.str());
            }
            std::vector<ExprInfo> stack = { ExprInfo(left), ExprInfo(biop), ExprInfo(right) };

            unsigned int prec = 0;
            while((biop = gobbleBinaryOp(deque)) != lexer::TokenType::UNKNOWN) {
                prec = binaryPrecedence(biop);

                if(prec == 0)
                    break;

                ExprInfo biopInfo = ExprInfo(biop);

                Expression *node = nullptr;
                while(stack.size() > 2 && prec <= binaryPrecedence(stack.at(stack.size() - 2).tokenType) && associativity(stack.at(stack.size() - 2).tokenType) == Associativity::LEFT) {
                    right = stack.back().expression;
                    stack.pop_back();

                    biop = stack.back().tokenType;
                    stack.pop_back();

                    left = stack.back().expression;
                    stack.pop_back();

                    node = createBinaryExpression(biop, left, right);
                    stack.push_back(ExprInfo(node));
                }

                node = gobbleToken(deque, results);
                if(!node) {
                    std::stringstream ss;
                    ss << "Expected expression after " << biop;
                    addError(results, deque.front(), ss.str());
                }
                stack.push_back(biopInfo);
                stack.push_back(ExprInfo(node));
            }

            // TODO: Use stack functionality for this loop, it's prettier and easier to understand
            int i = stack.size() - 1;
            Expression *node = stack[i].expression;
            while(i > 1) {
                node = createBinaryExpression(stack.at(i - 1).tokenType, stack[i - 2].expression, node);
                i -= 2;
            }

            return node;
        }

        Expression *ExpressionFactory::gobbleToken(std::deque<lexer::Token> &deque, ParseResults &results) {
            if(deque.front().is(lexer::TokenType::NUMBER) || deque.front().is(lexer::TokenType::PERIOD)) {
                // A period can start off a numeric literal (i.e. `.5`)
                return gobbleNumericLiteral(deque);
            } else if(deque.front().is(lexer::TokenType::TEXT)) {
                return gobbleStringLiteral(deque);
            } else if(deque.front().is(lexer::TokenType::BOOL)) {
                return gobbleBoolLiteral(deque);
            } else if(deque.front().is(lexer::TokenType::IDENTIFIER) || deque.front().is(lexer::TokenType::OPEN) || deque.front().is(lexer::TokenType::THIS_T)) {
                // `foo`, `bar.baz`
                return gobbleVariable(deque, results);
            } else if(deque.front().is(lexer::TokenType::BRACKET_OPEN)) {
                return gobbleArray(deque, results);
            } else if(deque.front().is(lexer::TokenType::FUNCTION)) {
                return FunctionDefinitionFactory::produce(deque, results);
            } else if(deque.front().is(lexer::TokenType::NOTE)) {
                return NoteFactory::produce(deque, results);
            } else if(deque.front().is(lexer::TokenType::NEW)) {
                return NewInstanceFactory::produce(deque, results);
            } else {
                if(isUnaryOperator(deque.front())) {
                    lexer::Token token = deque.front();
                    deque.pop_front();

                    return new UnaryExpression(token, gobbleToken(deque, results));
                }
            }

            return nullptr;
        }

        /**
         * Search for the operation portion of the string (e.g. `+`, `===`)
         * Start by taking the longest possible binary operation (3 characters: `===`, `!==`, `>>>`) and move down
         * from 3 to 2 to 1 character until a matching binary operation is found then return at binary operation.
         */
        lexer::TokenType ExpressionFactory::gobbleBinaryOp(std::deque<lexer::Token> &deque) {
            if(deque.empty())
                return lexer::TokenType::UNKNOWN;

            if(BINARY_OPS.count(deque.front().type()) == 1) {
                lexer::Token token = deque.front();

                deque.pop_front();
                return token.type();
            }
            return lexer::TokenType::UNKNOWN;
        }

        /**
         * Parse simple numeric literals: `12`, `3.5`, `.5`. Do this by using a string to keep track of everything in
         * the numeric literal and then calling `parseFloat` on that string.
         */
        NumberLiteral * ExpressionFactory::gobbleNumericLiteral(std::deque<lexer::Token> &deque) {
            NumberLiteral *numberLiteral = new NumberLiteral(deque.front(), std::stod(deque.front().content()));
            deque.pop_front();

            return numberLiteral;
        }

        /**
         * Parses a string literal, starting with single or double quotes with basic support for escape
         * codes (e.g. `"hello world", 'this is \nJSEP'`.
         */
        Expression *ExpressionFactory::gobbleStringLiteral(std::deque<lexer::Token> &deque) {
            std::string content = deque.front().content();

            // replace escaped characters
            replaceAll(content, "\\'",  "\'");
            replaceAll(content, "\\\"",   "\"");
            replaceAll(content, "\\?",  "\?");
            replaceAll(content, "\\\\", "\\");
            replaceAll(content, "\\a",  "\a");
            replaceAll(content, "\\b",  "\b");
            replaceAll(content, "\\f",  "\f");
            replaceAll(content, "\\n",  "\n");
            replaceAll(content, "\\r",  "\r");
            replaceAll(content, "\\t",  "\t");
            replaceAll(content, "\\v",  "\v");
            // TODO: Support for \nnn (arbitrary octal value)
            // TODO: Support for \Xnn (arbitrary hexadecimal value)
            // TODO: Support for \Unnnn (universal character name)
            // TODO: Support for \Unnnnnnnn (universal character name)

            TextLiteral *textLiteral = new TextLiteral(deque.front(), content.substr(1, content.size() - 2));
            deque.pop_front();

            // TODO: Do we support \r, \n, \t, etc?

            return textLiteral;
        }

        Expression *ExpressionFactory::gobbleBoolLiteral(std::deque<lexer::Token> &deque) {
            BoolLiteral *boolLiteral = new BoolLiteral(deque.front(), deque.front().content() == "true");
            deque.pop_front();

            return boolLiteral;
        }

        /**
         * Gobble a non-literal variable name. This variable name may include properties e.g. `foo`, `bar.baz`,
         * `foo['bar'].baz`.
         *
         * It also gobbles function calls e.g. `Math.acos(obj.angle)`.
         */
        Expression *ExpressionFactory::gobbleVariable(std::deque<lexer::Token> &deque, ParseResults &results) {
            Expression *node = nullptr;
            if(deque.front().is(lexer::TokenType::OPEN)) {
                node = gobbleGroup(deque, results);
            } else {
                node = gobbleIdentifier(deque);
            }

            while(deque.front().is(lexer::TokenType::PERIOD) || deque.front().is(lexer::TokenType::BRACKET_OPEN) || deque.front().is(lexer::TokenType::OPEN)) {
                if(deque.front().is(lexer::TokenType::PERIOD)) {
                    expect(deque, lexer::TokenType::PERIOD, results);
                    node = new MemberExpression(node, gobbleIdentifier(deque), false);
                } else if(deque.front().is(lexer::TokenType::BRACKET_OPEN)) {
                    expect(deque, lexer::TokenType::BRACKET_OPEN, results);
                    node = new ArrayAccessExpression(node, gobbleExpression(deque, results), true);
                    expect(deque, lexer::TokenType::BRACKET_CLOSE, results);
                } else if(deque.front().is(lexer::TokenType::OPEN)) {
                    expect(deque, lexer::TokenType::OPEN, results);
                    node = new CallExpression(node, gobbleArguments(deque, lexer::TokenType::CLOSE, results));
                    //expect(deque, lexer::TokenType::CLOSE);
                }
            }

            return node;
        }

        /**
         * Responsible for parsing a group of things within parenthesis `()`.
         *
         * This function assumes that it needs to gobble the opening parenthesis and then tries to gobble everything
         * within that parenthesis, assuming that the next thing is should see is the close parenthesis. If not, then
         * the expression probably doesn't have a `)`.
         */
        Expression *ExpressionFactory::gobbleGroup(std::deque<lexer::Token> &deque, ParseResults &results) {
            expect(deque, lexer::TokenType::OPEN, results);

            Expression *node = gobbleExpression(deque, results);
            if(expect(deque, lexer::TokenType::CLOSE, results)) {
                return node;
            }

            return nullptr;
        }

        /**
         * Gobbles only identifiers e.g. `foo`, `_value`, `$x1`. Also this function checks if that identifier is a
         * literal e.g. `true`, `false`, `null` or `this`
         */
        Expression *ExpressionFactory::gobbleIdentifier(std::deque<lexer::Token> &deque) {
            if(deque.front().is(lexer::TokenType::IDENTIFIER)) {
                Identifier *identifier = new Identifier(deque.front(), deque.front().content());
                deque.pop_front();

                return identifier;
            } else if(deque.front().is(lexer::TokenType::BOOL)) {
                BoolLiteral *boolLiteral = new BoolLiteral(deque.front(), deque.front().content() == "true");
                deque.pop_front();
                // TODO: How about the gobbleBool method? This else if can be removed

                return boolLiteral;
                // TODO: Null literal
                // TODO: This literal
            } else if(deque.front().is(lexer::TokenType::THIS_T)) {
                ThisExpression *thisExpression = new ThisExpression(deque.front());
                deque.pop_front();

                return thisExpression;
            }

            // TODO: Throw exception?
            return nullptr;
        }

        /**
         * Responsible for parsing Array literals `[1, 2, 3]`
         * This function assumes that is needs to gobble the opening bracket and then tries to gobble the expression
         * as arguments.
         */
        ArrayLiteral * ExpressionFactory::gobbleArray(std::deque<lexer::Token> &deque, ParseResults &results) {
            expect(deque, lexer::TokenType::BRACKET_OPEN, results);

            return new ArrayLiteral(gobbleArguments(deque, lexer::TokenType::BRACKET_CLOSE, results));
        }

        /**
         * Gobbles a list of arguments within the context of a function call or array literal. This function also
         * assumes that the opening character `(` or `[` has already been gobbled, and gobbles expressions and commas
         * until the terminator character is encountered.
         *
         * e.g. `foo(bar, baz)`, `my_func()`, or `[bar, baz]`
         */
        std::vector<Expression *> ExpressionFactory::gobbleArguments(std::deque<lexer::Token> &deque, lexer::TokenType termination, ParseResults &results) {
            std::vector<Expression*> expressions;

            do {
                if(deque.front().is(termination)) {
                    deque.pop_front();
                    return expressions;
                }
                expressions.push_back(ExpressionFactory::produce(deque, results));
            } while(accept(deque, lexer::TokenType::COMMA));

            expect(deque, termination, results);

            return expressions;
        }

        /**
         * Returns the precedence of a binary operator or `0` if it isn't a binary operator.
         */
        unsigned int ExpressionFactory::binaryPrecedence(lexer::TokenType tokenType) {
            if(BINARY_OPS.count(tokenType) == 1)
                return BINARY_OPS.at(tokenType).precedence;
            return 0;
        }

        Associativity ExpressionFactory::associativity(lexer::TokenType tokenType) {
            if(BINARY_OPS.count(tokenType) == 1)
                return BINARY_OPS.at(tokenType).associativity;
            return Associativity::LEFT;
        }

        /**
         * Utility function (gets called from multiple places)
         *
         * Also note that `a && b` and `a || b` are *logical* expression, not binary expressions
         */
        Expression *ExpressionFactory::createBinaryExpression(lexer::TokenType op, Expression *left, Expression *right) {
            try {
                if(op == lexer::TokenType::PLUS) {
                    return new AdditionExpression(left, right);
                } else if(op == lexer::TokenType::MINUS) {
                    return new SubtractionExpression(left, right);
                } else if(op == lexer::TokenType::TIMES) {
                    return new MultiplicationExpression(left, right);
                } else if(op == lexer::TokenType::DIVIDE) {
                    return new DivisionExpression(left, right);
                } else if(op == lexer::TokenType::MOD) {
                    return new ModuloExpression(left, right);
                } else if(op == lexer::TokenType::AND) {
                    return new AndCondition(left, right);
                } else if(op == lexer::TokenType::EQ) {
                    return new EqualCondition(left, right);
                } else if(op == lexer::TokenType::LR) {
                    return new LargerThanCondition(left, right);
                } else if(op == lexer::TokenType::LREQ) {
                    return new LargerThanOrEqualCondition(left, right);
                } else if(op == lexer::TokenType::NEQ) {
                    return new NotEqualCondition(left, right);
                } else if(op == lexer::TokenType::OR) {
                    return new OrCondition(left, right);
                } else if(op == lexer::TokenType::SM) {
                    return new SmallerThanCondition(left, right);
                } else if(op == lexer::TokenType::SMEQ) {
                    return new SmallerThanOrEqualCondition(left, right);
                } else if(op == lexer::TokenType::TEQ) {
                    return new StrictEqualCondition(left, right);
                } else if(op == lexer::TokenType::TNEQ) {
                    return new StrictNotEqualCondition(left, right);
                } else if(op == lexer::TokenType::ASSIGNMENT) {
                    return new AssignmentExpression(left, right);
                } else if(op == lexer::TokenType::EXP) {
                    return new ExponentExpression(left, right);
                }
            } catch(const std::invalid_argument &e) {
                // TODO: HACK: Retrow instead of wrap
                throw ParsingException(left->token(), std::string(e.what()));
            }

            throw ParsingException(left->token(), "Operator not supported.");
        }

        bool ExpressionFactory::isUnaryOperator(lexer::Token &token) {
            return token.is(lexer::TokenType::PLUS)
                || token.is(lexer::TokenType::MINUS)
                || token.is(lexer::TokenType::NOT);
        }

        void ExpressionFactory::replaceAll(std::string &subject, const std::string &search, const std::string &replace) {
            size_t pos = 0;
            while((pos = subject.find(search, pos)) != std::string::npos) {
                subject.replace(pos, search.length(), replace);
                pos += replace.length();
            }
        }
    }
}
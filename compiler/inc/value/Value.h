#ifndef DEMUSE_VALUE_H
#define DEMUSE_VALUE_H

#include <string>
#include <typeinfo>
#include "symbol/play/Note.h"

namespace dem {
    namespace compiler {
        class Variable;
    }
}

namespace dem {
    namespace compiler {
        /**
         * \brief Represents a value
         *
         * Anything both lvalues and rvalue implement this iterface. This interface ensured that all different data
         * types in DEMUSE can be converted to different data types and that the correct operators can be applied to
         * these values.
         *
         * Though any implementers of this interface may for any method throw an exception when such a operator is not
         * allowed. For example, it would not make sense to String by an Array, the "divide" method may throw an
         * exception is such a case.
         */
        class Value {
        public:
            virtual ~Value() { }

            /**
             * \brief Add value b to value a (thus a + b)
             */
            virtual Value *add(Value *b) = 0;

            /**
             * \brief Subtract value b from value a (thus a - b)
             */
            virtual Value *subtract(Value *b) = 0;

            /**
             * \brief Multiply value b with value a (thus a * b)
             */
            virtual Value *multiply(Value *b) = 0;

            /**
             * \brief Divide value a by value b (thus a / b)
             */
            virtual Value *divide(Value *b) = 0;

            /**
             * \brief Calculates the remainder of the division a by b (thus a % b)
             */
            virtual Value *modulo(Value *b) = 0;

            /**
             * \brief Performs the exponentation with b as the exponent (thus a ^ b)
             */
            virtual Value *exponent(Value *b) = 0;

            /**
             * \brief Converts the value to a number
             */
            virtual double asNumber() const = 0;

            /**
             * \brief Converts the value to a boolean
             */
            virtual bool asBool() const = 0;

            /**
             * \brief Converts the value to a string
             */
            virtual std::string asString() const = 0;

            /**
             * \brief Converts the value to a note
             */
            virtual parser::Note asNote() const = 0;

            virtual bool operator==(const Value &other) = 0;
            virtual bool operator!=(const Value &other) = 0;
            virtual bool operator<(const Value &other) = 0;
            virtual bool operator<=(const Value &other) = 0;
            virtual bool operator>(const Value &other) = 0;
            virtual bool operator>=(const Value &other) = 0;

            /**
             * \brief Access this object with an index (called when script performs "A[4]")
             */
            virtual Value *operator[](const int index) = 0;

            /**
             * \brief Access this object with an index (called when script performs "A.foo")
             */
            virtual Variable *operator[](const std::string &index) = 0;

            /**
             * \briefs Calls this object (called when script performs "a()")
             */
            virtual Value * operator()();

            virtual bool strictEqual(const Value &other) {
                if(typeid(*this).name() != typeid(other).name())
                    return false;
                return *this == other;
            }

            virtual bool strictNotEqual(const Value &other) {
                if(typeid(*this).name() != typeid(other).name())
                    return true;
                return *this != other;
            }
        };
    }
}

#endif //DEMUSE_VALUE_H

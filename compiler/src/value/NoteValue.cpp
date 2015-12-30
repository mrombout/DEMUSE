#include "exception/RuntimeException.h"
#include "value/NoteValue.h"

namespace dem {
    namespace compiler {
        NoteValue::NoteValue(parser::Note note) :
            mNote(note) {

        }

        Value *NoteValue::add(Value *b) {
            throw RuntimeException("Notes do not support addition operations.");
        }

        Value *dem::compiler::NoteValue::subtract(Value *b) {
            throw RuntimeException("Notes do not support subtraction operations.");
        }

        Value *NoteValue::multiply(Value *b) {
            throw RuntimeException("Notes do not support multiplication operations.");
        }

        Value *NoteValue::divide(Value *b) {
            throw RuntimeException("Notes do not support division operations.");
        }

        Value *NoteValue::modulo(Value *b) {
            throw RuntimeException("Notes do not support modulo operations.");
        }

        Value *NoteValue::exponent(Value *b) {
            throw RuntimeException("Notes do not support exponent operations.");
        }

        double dem::compiler::NoteValue::asNumber() const {
            return mNote.midiNote();
        }

        bool dem::compiler::NoteValue::asBool() const {
            return mNote.midiDuration() > 0;
        }

        std::string dem::compiler::NoteValue::asString() const {
            return mNote.toString();
        }

        parser::Note NoteValue::asNote() const {
            return mNote;
        }

        bool NoteValue::operator==(const Value &other) {
            throw RuntimeException("Booleans do not support '==' operations.");
        }

        bool NoteValue::operator!=(const Value &other) {
            throw RuntimeException("Booleans do not support '!=' operations.");
        }

        bool NoteValue::operator<(const Value &other) {
            throw RuntimeException("Booleans do not support '<' operations.");
        }

        bool NoteValue::operator<=(const Value &other) {
            throw RuntimeException("Booleans do not support '<=' operations.");
        }

        bool NoteValue::operator>(const Value &other) {
            throw RuntimeException("Booleans do not support '>' operations.");
        }

        bool NoteValue::operator>=(const Value &other) {
            throw RuntimeException("Booleans do not support '>=' operations.");
        }

        Value *NoteValue::operator[](const int index) {
            throw RuntimeException("Booleans do not support '[]' operations.");
        }

        Variable *NoteValue::operator[](const std::string &index) {
            throw RuntimeException("Booleans do not support '.' operations.");
        }
    }
}

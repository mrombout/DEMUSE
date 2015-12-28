#include "value/NoteValue.h"

namespace dem {
    namespace compiler {
        NoteValue::NoteValue(parser::Note note) :
            mNote(note) {

        }

        Value *NoteValue::add(Value *b) {
            throw "Can't add to note"; // TODO: Throw proper error
        }

        Value *dem::compiler::NoteValue::subtract(Value *b) {
            throw "Can't subtract from note"; // TODO: Throw proper error
        }

        Value *NoteValue::multiply(Value *b) {
            throw "Can't multiply note"; // TODO: Throw proper error
        }

        Value *NoteValue::divide(Value *b) {
            throw "Can't divide by note"; // TODO: Throw proper error
        }

        Value *NoteValue::modulo(Value *b) {
            throw "Can't modulo note"; // TODO: Throw proper error
        }

        Value *NoteValue::exponent(Value *b) {
            throw "Can't exponent note"; // TODO: Throw proper error
        }

        double dem::compiler::NoteValue::asNumber() const {
            return mNote.midiNote();
        }

        bool dem::compiler::NoteValue::asBool() const {
            return mNote.midiDuration() > 0;
        }

        std::string dem::compiler::NoteValue::asString() const {
            return std::to_string(mNote.note());
        }

        parser::Note NoteValue::asNote() const {
            return mNote;
        }

        bool NoteValue::operator==(const Value &other) {
            throw "Can't compare yet"; // TODO: Throw proper error
        }

        bool NoteValue::operator!=(const Value &other) {
            throw "Can't compare yet"; // TODO: Throw proper error
        }

        bool NoteValue::operator<(const Value &other) {
            throw "Can't compare yet"; // TODO: Throw proper error
        }

        bool NoteValue::operator<=(const Value &other) {
            throw "Can't compare yet"; // TODO: Throw proper error
        }

        bool NoteValue::operator>(const Value &other) {
            throw "Can't compare yet"; // TODO: Throw proper error
        }

        bool NoteValue::operator>=(const Value &other) {
            throw "Can't compare yet"; // TODO: Throw proper error
        }

        Value *NoteValue::operator[](const int index) {
            throw "Can't access note as array"; // TODO: Throw proper error
        }

        Variable *NoteValue::operator[](const std::string &index) {
            throw "Can't access note as object"; // TODO: Throw proper error
        }
    }
}

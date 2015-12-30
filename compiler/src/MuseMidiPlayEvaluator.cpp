#include <iostream>
#include "MuseMidiPlayEvaluator.h"
#include "value/Variable.h"

namespace dem {
    namespace compiler {
        MuseMidiPlayEvaluator::MuseMidiPlayEvaluator(ExpressionEvaluator &evaluator) :
            mEvaluator(evaluator),
            mTime(0) {
            mMidiFile.absoluteTicks();
            mMidiFile.addTrack(2);

            // add silence
            mMidiMessage.setCommand(0x90, 0, 0);
            mMidiFile.addEvent(1, mTime, mMidiMessage);

            mMidiMessage.setCommand(0x80, 0, 0);
            mMidiFile.addEvent(1, mTime += mTPQ * 4, mMidiMessage);
        }

        void MuseMidiPlayEvaluator::play(parser::Play &play, Scope *scope) {
            mScope = scope;

            mTPQ = scope->variable(new parser::Identifier(lexer::Token(lexer::TokenType::IDENTIFIER, "tempo", lexer::TokenPosition()), "tempo")).asNumber();
            mMidiFile.setTicksPerQuarterNote(mTPQ);

            play.accept(*this);
        }

        void MuseMidiPlayEvaluator::write(const std::string &fileName) {
            mMidiFile.write(fileName);
        }

        bool MuseMidiPlayEvaluator::visitEnter(parser::Play &play) {
            std::cout << "ENTER - Play" << std::endl;

            return true;
        }

        bool MuseMidiPlayEvaluator::visitLeave(parser::Play &play) {
            std::cout << "LEAVE - Play" << std::endl;

            // add silence
            mMidiMessage.setCommand(0x80, 0, 0);
            mMidiFile.addEvent(1, mTime += mTPQ * 4, mMidiMessage);

            return true;
        }

        bool MuseMidiPlayEvaluator::visit(parser::Note &note) {
            std::cout << "START - Note(" << mTime << ")" << std::endl;

            // note on
            mMidiMessage.setCommand(0x90, note.midiNote(), note.note() == 'R' ? 0 : 127);
            mMidiFile.addEvent(1, mTime, mMidiMessage);

            // note off
            mMidiMessage[0] = 0x80;
            mMidiFile.addEvent(1, mTime += mTPQ * note.midiDuration(), mMidiMessage);

            return true;
        }

        bool MuseMidiPlayEvaluator::visit(parser::Identifier &identifier) {
            std::cout << "START - Identifer" << std::endl;

            Variable &variable = mScope->variable(&identifier);
            variable.asNote().accept(*this);

            return false;
        }

        bool MuseMidiPlayEvaluator::visitEnter(parser::Harmony &harmony) {
            std::cout << "ENTER - Harmony(" << mTime << ")" << std::endl;

            int maxDelta = 0;
            for(parser::Expression *note : harmony.notes()) {
                int curTime = mTime;
                note->accept(*this);
                int delta = mTime - curTime;
                if(delta > maxDelta)
                    maxDelta = delta;
                mTime = curTime;
            }

            mTime += maxDelta;

            return false;
        }

        bool MuseMidiPlayEvaluator::visitLeave(parser::Harmony &harmony) {
            std::cout << "LEAVE - Harmony" << std::endl;

            return true;
        }

        bool MuseMidiPlayEvaluator::visitEnter(parser::Instrument &instrument) {
            std::cout << "ENTER - Instrument" << std::endl;

            Value *value = mEvaluator.evaluate(mScope, *instrument.instrumentExpression());
            mMidiMessage.setCommand(0xC0, value->asNumber());
            mMidiFile.addEvent(1, mTime, mMidiMessage);

            return true;
        }

        bool MuseMidiPlayEvaluator::visitLeave(parser::Instrument &instrument) {
            std::cout << "LEAVE - Instrument" << std::endl;

            return true;
        }
    }
}

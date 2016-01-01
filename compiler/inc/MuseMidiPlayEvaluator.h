#ifndef DEMUSE_MUSEMIDIPLAYEVALUATOR_H
#define DEMUSE_MUSEMIDIPLAYEVALUATOR_H

#include "MidiFile.h"
#include "Visitor.h"
#include "Scope.h"
#include "ExpressionEvaluator.h"

namespace dem {
    namespace compiler {
        class MuseMidiPlayEvaluator : public parser::Visitor {
        public:
            MuseMidiPlayEvaluator(ExpressionEvaluator &evaluator);

            void play(parser::Play &play, Scope *scope);
            void write(const std::string &fileName);

            void setTrack(const parser::Track &track);

            virtual bool visitEnter(parser::Play &play) override;
            virtual bool visitLeave(parser::Play &play) override;

            virtual bool visitEnter(parser::Harmony &harmony) override;
            virtual bool visitLeave(parser::Harmony &harmony) override;

            virtual bool visitEnter(parser::Instrument &instrument) override;
            virtual bool visitLeave(parser::Instrument &instrument) override;

            virtual bool visit(parser::Note &note) override;
            virtual bool visit(parser::Identifier &identifier) override;

        private:
            ExpressionEvaluator &mEvaluator;

            Scope *mScope;

            MidiFile mMidiFile;
            MidiMessage mMidiMessage;

            int mTime;
            int mTPQ;

            const parser::Track *mTrack;
        };
    }
}

#endif //DEMUSE_MUSEMIDIPLAYEVALUATOR_H

#ifndef DEMUSE_PLAYCOMPILER_H
#define DEMUSE_PLAYCOMPILER_H

#include "Visitor.h"
#include <jdksmidi/world.h>
#include <jdksmidi/track.h>
#include <jdksmidi/multitrack.h>
#include <jdksmidi/filereadmultitrack.h>
#include <jdksmidi/fileread.h>
#include <jdksmidi/fileshow.h>
#include <jdksmidi/filewritemultitrack.h>

namespace dem {
    namespace parser {
        class PlayEvaluator : public Visitor {
        public:
            void play(parser::Play &play);

            virtual bool visitEnter(parser::Play &play) override;
            virtual bool visitLeave(parser::Play &play) override;

            virtual bool visit(parser::Note &note) override;

        private:
            jdksmidi::MIDITimedBigMessage mMsg;
            unsigned char mChan;
            unsigned char mNote;
            unsigned char mVelocity;
            unsigned char mCtrl;
            unsigned char mVal;

            jdksmidi::MIDIClockTime mTime;
            jdksmidi::MIDIClockTime mDelta;
        };
    }
}

#endif //DEMUSE_PLAYCOMPILER_H

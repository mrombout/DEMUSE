#include <iostream>
#include "MusePlayEvaluator.h"
#include "jdksmidi/world.h"
#include "jdksmidi/track.h"
#include "jdksmidi/multitrack.h"
#include "jdksmidi/filereadmultitrack.h"
#include "jdksmidi/fileread.h"
#include "jdksmidi/fileshow.h"
#include "jdksmidi/filewritemultitrack.h"

namespace dem {
    namespace compiler {
        PlayEvaluator::PlayEvaluator() :
            mChan(0),
            mNote(0),
            mVelocity(0),
            mCtrl(0),
            mVal(0),
            mTime(0),
            mDelta(100),
            mTracks(2),
            mTrk(0) {
            mTracks.SetClksPerBeat(100);

            mTime = 0;
            mMsg.SetTime( mTime );

            mTrk = 0;

            mMsg.SetTimeSig( 4, 2 );
            mTracks.GetTrack(mTrk)->PutEvent( mMsg );

            //int tempo = 100000;

            //mMsg.SetTempo( tempo );
            mTracks.GetTrack(mTrk)->PutEvent( mMsg );

            mTracks.GetTrack(mTrk)->PutTextEvent(mTime, jdksmidi::META_TRACK_NAME, "LibJDKSmidi create_midifile.cpp example by VRM");

            mTrk = 1;

            mTracks.GetTrack(mTrk)->PutTextEvent(mTime, jdksmidi::META_TRACK_NAME, "Church Organ");

            mMsg.SetControlChange ( mChan = 0, mCtrl = 0xA, mVal = 0 );
            mTracks.GetTrack(mTrk)->PutEvent( mMsg );

            mMsg.SetControlChange ( mChan = 1, mCtrl, mVal = 64 );
            mTracks.GetTrack(mTrk)->PutEvent( mMsg );

            mMsg.SetControlChange ( mChan = 2, mCtrl, mVal = 127 );
            mTracks.GetTrack(mTrk)->PutEvent( mMsg );

            mMsg.SetProgramChange( mChan = 0, mVal = 19 );
            mTracks.GetTrack(mTrk)->PutEvent( mMsg );

            mMsg.SetProgramChange( mChan = 1, mVal );
            mTracks.GetTrack(mTrk)->PutEvent( mMsg );

            mMsg.SetProgramChange( mChan = 2, mVal );
            mTracks.GetTrack(mTrk)->PutEvent( mMsg );
        }

        void PlayEvaluator::play(parser::Play &play) {
            play.accept(*this);
        }

        void PlayEvaluator::write() {
            const char *outfile_name = "output.mid";
            jdksmidi::MIDIFileWriteStreamFileName out_stream(outfile_name);

            // then output the stream like my example does, except setting num_tracks to match your data

            if( out_stream.IsValid() ) {
                // the object which takes the midi tracks and writes the midifile to the output stream
                jdksmidi::MIDIFileWriteMultiTrack writer(&mTracks, &out_stream);

                // write the output file
                if (writer.Write(2)) {
                    std::cout << "\nOK writing file " << outfile_name << std::endl;
                } else {
                    std::cerr << "\nError writing file " << outfile_name << std::endl;
                }
            } else {
                std::cerr << "\nError opening file " << outfile_name << std::endl;
            }
        }

        bool PlayEvaluator::visitEnter(parser::Play &play) {
            std::cout << "START - Play" << std::endl;

            mTrk = 1;

            return true;
        }

        bool PlayEvaluator::visitLeave(parser::Play &play) {
            std::cout << "STOP - Play" << std::endl;

            return true;
        }

        bool PlayEvaluator::visit(parser::Note &note) {
            std::cout << "START - Note" << std::endl;

            mMsg.SetTime(mTime += mDelta);
            mMsg.SetNoteOn(mChan = 0, mNote = toMidiNote(note), mVelocity = 100);
            mTracks.GetTrack(mTrk)->PutEvent(mMsg);

            int duration = mDelta * 4;
            if(note.duration() == 'h') {
                duration = mDelta * 2;
            } else if(note.duration() == 'q') {
                duration = mDelta;
            }

            mMsg.SetTime(mTime += duration);
            mMsg.SetNoteOff(mChan, mNote, mVelocity);
            mTracks.GetTrack(mTrk)->PutEvent(mMsg);

            return true;
        }

        int PlayEvaluator::toMidiNote(parser::Note &note) const {
            int midiNote = 0;

            // note base values (octave 0)
            if(note.note() == 'C') {
                midiNote = 0;
            } else if(note.note() == 'D') {
                midiNote = 2;
            } else if(note.note() == 'E') {
                midiNote = 4;
            } else if(note.note() == 'F') {
                midiNote = 5;
            } else if(note.note() == 'G') {
                midiNote = 7;
            } else if(note.note() == 'A') {
                midiNote = 9;
            } else if(note.note() == 'B') {
                midiNote = 11;
            }

            // octave (every octave adds 12)
            midiNote += (note.octave() * 12);

            // accidental
            if(note.accidental() == '#') {
                midiNote += 1;
            } else if(note.accidental() == 'b') {
                midiNote -= 1;
            }

            return midiNote;
        }
    }
}

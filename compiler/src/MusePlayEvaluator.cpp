#include <iostream>
#include "MusePlayEvaluator.h"

namespace dem {
    namespace compiler {
        MusePlayEvaluator::MusePlayEvaluator() :
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

            mMsg.SetTempo( 1000000 * 60 / 120 );
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

        void MusePlayEvaluator::play(parser::Play &play) {
            play.accept(*this);
        }

        void MusePlayEvaluator::write() {
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

        bool MusePlayEvaluator::visitEnter(parser::Play &play) {
            std::cout << "START - Play" << std::endl;

            mTrk = 1;

            return true;
        }

        bool MusePlayEvaluator::visitLeave(parser::Play &play) {
            std::cout << "STOP - Play" << std::endl;

            return true;
        }

        bool MusePlayEvaluator::visit(parser::Note &note) {
            std::cout << "START - Note" << std::endl;

            mMsg.SetNoteOn(mChan = 0, mNote = toMidiNote(note), mVelocity = 100);
            mTracks.GetTrack(mTrk)->PutEvent(mMsg);

            jdksmidi::MIDIClockTime duration = mDelta * 4; // default to whole
            if(note.duration() == 'h') {        // half
                duration = mDelta * 2;
            } else if(note.duration() == 'q') { // quater
                duration = mDelta;
            } else if(note.duration() == 'i') { // eighth
                duration = mDelta / 2;
            } else if(note.duration() == 's') { // sixteenth
                duration = mDelta / 2 / 2;
            } else if(note.duration() == 't') {  // thirty-second
                duration = mDelta / 2 / 2 / 2;
            } else if(note.duration() == 'x') { // sixty-fourth
                duration = mDelta / 2 / 2 / 2 / 2;
            } else if(note.duration() == 'o') { // one-twenty-eighth
                duration = mDelta / 2 / 2 / 2 / 2 / 2;
            }

            mMsg.SetTime(mTime += duration);
            mMsg.SetNoteOff(mChan, mNote, mVelocity);
            mTracks.GetTrack(mTrk)->PutEvent(mMsg);

            return true;
        }

        bool MusePlayEvaluator::visitEnter(parser::Harmony &harmony) {
            std::cout << "START - Harmony" << std::endl;

            return false;
        }

        int MusePlayEvaluator::toMidiNote(parser::Note &note) const {
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

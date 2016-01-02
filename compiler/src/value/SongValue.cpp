#include "value/function/PrintFunction.h"
#include "value/NumberValue.h"
#include "value/SongValue.h"

namespace dem {
    namespace compiler {
        SongValue::SongValue() {
            lexer::Token token{lexer::TokenType::IDENTIFIER, "N/A", lexer::TokenPosition()};

            // standard library
            declareVariable(new parser::Identifier(token, "print"),  new PrintFunction(this));
            declareVariable(new parser::Identifier(token, "Object"), new ObjectValue(this));

            // standard play library
            declareVariable(new parser::Identifier(token, "tempo"),  new NumberValue(120));

            // midi instruments
            //// Pianoforte
            declareVariable(new parser::Identifier(token, "GRAND_PIANO"),       new NumberValue(1));
            declareVariable(new parser::Identifier(token, "BRITE_PIANO"),       new NumberValue(2));
            declareVariable(new parser::Identifier(token, "ELEC_GRAND_PIANO"),  new NumberValue(3));
            declareVariable(new parser::Identifier(token, "HONKY_TONK_PIANO"),  new NumberValue(4));
            declareVariable(new parser::Identifier(token, "ELEC_PIANO1"),       new NumberValue(5));
            declareVariable(new parser::Identifier(token, "ELEC_PIANO2"),       new NumberValue(6));
            declareVariable(new parser::Identifier(token, "HARPSICHORD"),       new NumberValue(7));
            declareVariable(new parser::Identifier(token, "CLAVINET"),          new NumberValue(8));

            //// Chromatic percussion
            declareVariable(new parser::Identifier(token, "CELESTA"),           new NumberValue(9));
            declareVariable(new parser::Identifier(token, "GLOCKEN"),           new NumberValue(10));
            declareVariable(new parser::Identifier(token, "MUSICBOX"),          new NumberValue(11));
            declareVariable(new parser::Identifier(token, "VIBES"),             new NumberValue(12));
            declareVariable(new parser::Identifier(token, "MARIMBA"),           new NumberValue(13));
            declareVariable(new parser::Identifier(token, "XYLOPHONE"),         new NumberValue(14));
            declareVariable(new parser::Identifier(token, "TUBULAR_BELLS"),     new NumberValue(15));
            declareVariable(new parser::Identifier(token, "DULCIMER"),          new NumberValue(16));

            //// Organ
            declareVariable(new parser::Identifier(token, "DRAWBAR_ORGAN"),     new NumberValue(17));
            declareVariable(new parser::Identifier(token, "PERCUSSIVE_ORGAN"),  new NumberValue(18));
            declareVariable(new parser::Identifier(token, "ROCK_ORGAN"),        new NumberValue(19));
            declareVariable(new parser::Identifier(token, "CHURCH_ORGAN"),      new NumberValue(20));
            declareVariable(new parser::Identifier(token, "REED_ORGAN"),        new NumberValue(21));
            declareVariable(new parser::Identifier(token, "ACCORDION"),         new NumberValue(22));
            declareVariable(new parser::Identifier(token, "HARMONICA"),         new NumberValue(23));
            declareVariable(new parser::Identifier(token, "TANGO ACCORDION"),   new NumberValue(24));

            //// Guitar
            declareVariable(new parser::Identifier(token, "NYLON_GUITAR"),      new NumberValue(25));
            declareVariable(new parser::Identifier(token, "STEEL_GUITAR"),      new NumberValue(26));
            declareVariable(new parser::Identifier(token, "JAZZ_GUITAR"),       new NumberValue(27));
            declareVariable(new parser::Identifier(token, "CLEAN_GUITAR"),      new NumberValue(28));
            declareVariable(new parser::Identifier(token, "MUTE_GUITAR"),       new NumberValue(29));
            declareVariable(new parser::Identifier(token, "OVERDRIVE_GUITAR"),  new NumberValue(30));
            declareVariable(new parser::Identifier(token, "DIST_GUITAR"),       new NumberValue(31));
            declareVariable(new parser::Identifier(token, "GUITAR_HARMONICS"),  new NumberValue(32));

            //// Bass
            declareVariable(new parser::Identifier(token, "ACOUSTIC_BASS"),     new NumberValue(33));
            declareVariable(new parser::Identifier(token, "FINGERED_BASS"),     new NumberValue(34));
            declareVariable(new parser::Identifier(token, "PICK_BASS"),         new NumberValue(35));
            declareVariable(new parser::Identifier(token, "FRETLESS_BASS"),     new NumberValue(36));
            declareVariable(new parser::Identifier(token, "SLAP_BASS1"),        new NumberValue(37));
            declareVariable(new parser::Identifier(token, "SLAP_BASS2"),        new NumberValue(38));
            declareVariable(new parser::Identifier(token, "SYNTH_BASS1"),       new NumberValue(39));
            declareVariable(new parser::Identifier(token, "SYNTH_BASS2"),       new NumberValue(40));

            //// Strings
            declareVariable(new parser::Identifier(token, "VIOLIN"),            new NumberValue(41));
            declareVariable(new parser::Identifier(token, "VIOLA"),             new NumberValue(42));
            declareVariable(new parser::Identifier(token, "CELLO"),             new NumberValue(43));
            declareVariable(new parser::Identifier(token, "CONTRABASS"),        new NumberValue(44));
            declareVariable(new parser::Identifier(token, "TREMOLO_STRINGS"),   new NumberValue(45));
            declareVariable(new parser::Identifier(token, "PIZZICATO_STRINGS"), new NumberValue(46));
            declareVariable(new parser::Identifier(token, "HARP"),              new NumberValue(47));
            declareVariable(new parser::Identifier(token, "TIMPANI"),           new NumberValue(48));

            //// Ensemble
            declareVariable(new parser::Identifier(token, "STRINGS1"),          new NumberValue(49));
            declareVariable(new parser::Identifier(token, "STRINGS2"),          new NumberValue(50));
            declareVariable(new parser::Identifier(token, "SYNTH_STRINGS1"),    new NumberValue(51));
            declareVariable(new parser::Identifier(token, "SYNTH_STRINGS2"),    new NumberValue(52));
            declareVariable(new parser::Identifier(token, "CHOIR_AAH"),         new NumberValue(53));
            declareVariable(new parser::Identifier(token, "VOICE_OOH"),         new NumberValue(54));
            declareVariable(new parser::Identifier(token, "SYNTH_VOICE"),       new NumberValue(55));
            declareVariable(new parser::Identifier(token, "ORCHESTRAL_HIT"),    new NumberValue(56));

            //// Brass
            declareVariable(new parser::Identifier(token, "TRUMPET"),           new NumberValue(57));
            declareVariable(new parser::Identifier(token, "TROMBONE"),          new NumberValue(58));
            declareVariable(new parser::Identifier(token, "TUBA"),              new NumberValue(59));
            declareVariable(new parser::Identifier(token, "MUTE_TRUMPET"),      new NumberValue(60));
            declareVariable(new parser::Identifier(token, "FRENCH_HORN"),       new NumberValue(61));
            declareVariable(new parser::Identifier(token, "BRASS_SECTION"),     new NumberValue(62));
            declareVariable(new parser::Identifier(token, "SYNTH_BRASS1"),      new NumberValue(63));
            declareVariable(new parser::Identifier(token, "SYNTH_BRASS2"),      new NumberValue(64));

            //// Reed
            declareVariable(new parser::Identifier(token, "SOPRANO_SAX"),       new NumberValue(65));
            declareVariable(new parser::Identifier(token, "ALTO_SAX"),          new NumberValue(66));
            declareVariable(new parser::Identifier(token, "TENOR_SAX"),         new NumberValue(67));
            declareVariable(new parser::Identifier(token, "BARITON_SAX"),       new NumberValue(68));
            declareVariable(new parser::Identifier(token, "OBOE"),              new NumberValue(69));
            declareVariable(new parser::Identifier(token, "ENGLISH_HORN"),      new NumberValue(70));
            declareVariable(new parser::Identifier(token, "BASSOON"),           new NumberValue(71));
            declareVariable(new parser::Identifier(token, "CLARINET"),          new NumberValue(72));

            //// Flutes
            declareVariable(new parser::Identifier(token, "PICCOLO"),           new NumberValue(73));
            declareVariable(new parser::Identifier(token, "FLUTE"),             new NumberValue(74));
            declareVariable(new parser::Identifier(token, "RECORDER"),          new NumberValue(75));
            declareVariable(new parser::Identifier(token, "PANFLUTE"),          new NumberValue(76));
            declareVariable(new parser::Identifier(token, "BOTTLE"),            new NumberValue(77));
            declareVariable(new parser::Identifier(token, "SHAKUHACHI"),        new NumberValue(78));
            declareVariable(new parser::Identifier(token, "WHISTLE"),           new NumberValue(79));
            declareVariable(new parser::Identifier(token, "OCARINA"),           new NumberValue(80));

            //// Lead Synth
            declareVariable(new parser::Identifier(token, "SQUARE_LEAD"),       new NumberValue(81));
            declareVariable(new parser::Identifier(token, "SAWTOOTH_LEAD"),     new NumberValue(82));
            declareVariable(new parser::Identifier(token, "CALIOPE_LEAD"),      new NumberValue(83));
            declareVariable(new parser::Identifier(token, "CHIFF_LEAD"),        new NumberValue(84));
            declareVariable(new parser::Identifier(token, "CHARANG_LEAD"),      new NumberValue(85));
            declareVariable(new parser::Identifier(token, "VOICE_LEAD"),        new NumberValue(86));
            declareVariable(new parser::Identifier(token, "FIFTH_LEAD"),        new NumberValue(87));
            declareVariable(new parser::Identifier(token, "BASS_LEAD"),         new NumberValue(88));

            //// Synth Pads
            declareVariable(new parser::Identifier(token, "NEW_PAGE_PAD"),      new NumberValue(89));
            declareVariable(new parser::Identifier(token, "WARM_PAD"),          new NumberValue(90));
            declareVariable(new parser::Identifier(token, "POLY_SYNTH_PAD"),    new NumberValue(91));
            declareVariable(new parser::Identifier(token, "CHOIR_PAD"),         new NumberValue(92));
            declareVariable(new parser::Identifier(token, "BOWED_PAD"),         new NumberValue(93));
            declareVariable(new parser::Identifier(token, "METAL_PAD"),         new NumberValue(94));
            declareVariable(new parser::Identifier(token, "HALO_PAD"),          new NumberValue(95));
            declareVariable(new parser::Identifier(token, "SWEEP_PAD"),         new NumberValue(96));

            //// Effects
            declareVariable(new parser::Identifier(token, "RAIN"),              new NumberValue(97));
            declareVariable(new parser::Identifier(token, "SOUNDTRACK"),        new NumberValue(98));
            declareVariable(new parser::Identifier(token, "CRYSTAL"),           new NumberValue(99));
            declareVariable(new parser::Identifier(token, "ATMOSPHERE"),        new NumberValue(100));
            declareVariable(new parser::Identifier(token, "BRIGHT"),            new NumberValue(101));
            declareVariable(new parser::Identifier(token, "GOBLINS"),           new NumberValue(102));
            declareVariable(new parser::Identifier(token, "ECHOES"),            new NumberValue(103));
            declareVariable(new parser::Identifier(token, "SCIFI"),             new NumberValue(104));

            //// Ethnic
            declareVariable(new parser::Identifier(token, "SITAR"),             new NumberValue(105));
            declareVariable(new parser::Identifier(token, "BANJO"),             new NumberValue(106));
            declareVariable(new parser::Identifier(token, "SHAMISEN"),          new NumberValue(107));
            declareVariable(new parser::Identifier(token, "KOTO"),              new NumberValue(108));
            declareVariable(new parser::Identifier(token, "KALIMBA"),           new NumberValue(109));
            declareVariable(new parser::Identifier(token, "BAGPIPE"),           new NumberValue(110));
            declareVariable(new parser::Identifier(token, "FIDDLE"),            new NumberValue(111));
            declareVariable(new parser::Identifier(token, "SHANAI"),            new NumberValue(112));

            //// Percussion
            declareVariable(new parser::Identifier(token, "TINKLE_BELL"),       new NumberValue(113));
            declareVariable(new parser::Identifier(token, "AGOGO"),             new NumberValue(114));
            declareVariable(new parser::Identifier(token, "STEEL_DRUM"),        new NumberValue(115));
            declareVariable(new parser::Identifier(token, "WOODBLOCK"),         new NumberValue(116));
            declareVariable(new parser::Identifier(token, "TAIKO_DRUM"),        new NumberValue(117));
            declareVariable(new parser::Identifier(token, "MELODIC_TOM"),       new NumberValue(118));
            declareVariable(new parser::Identifier(token, "SYNTH_DRUM"),        new NumberValue(119));
            declareVariable(new parser::Identifier(token, "REV_CYMBAL"),        new NumberValue(120));

            //// Sound Effects
            declareVariable(new parser::Identifier(token, "FRET_NOISE"),        new NumberValue(121));
            declareVariable(new parser::Identifier(token, "BREATH_NOISE"),      new NumberValue(122));
            declareVariable(new parser::Identifier(token, "SEASHORE"),          new NumberValue(123));
            declareVariable(new parser::Identifier(token, "TWEET"),             new NumberValue(124));
            declareVariable(new parser::Identifier(token, "TELEPHONE"),         new NumberValue(125));
            declareVariable(new parser::Identifier(token, "HELICOPTER"),        new NumberValue(126));
            declareVariable(new parser::Identifier(token, "APPLAUSE"),          new NumberValue(127));
            declareVariable(new parser::Identifier(token, "GUNSHOT"),           new NumberValue(128));
        }
    }
}
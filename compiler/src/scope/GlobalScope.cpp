#include "GlobalScope.h"
#include "value/function/PrintFunction.h"
#include "value/NumberValue.h"

namespace dem {
    namespace compiler {
        GlobalScope::GlobalScope() : Scope(nullptr) {
            // standard library
            declareVariable(new parser::Identifier("print"),  new PrintFunction());
            declareVariable(new parser::Identifier("Object"), new ObjectValue());

            // standard play library
            declareVariable(new parser::Identifier("tempo"),  new NumberValue(120));

            // midi instruments
            //// Pianoforte
            declareVariable(new parser::Identifier("GRAND_PIANO"),       new NumberValue(1));
            declareVariable(new parser::Identifier("BRITE_PIANO"),       new NumberValue(2));
            declareVariable(new parser::Identifier("ELEC_GRAND_PIANO"),  new NumberValue(3));
            declareVariable(new parser::Identifier("HONKY_TONK_PIANO"),  new NumberValue(4));
            declareVariable(new parser::Identifier("ELEC_PIANO1"),       new NumberValue(5));
            declareVariable(new parser::Identifier("ELEC_PIANO2"),       new NumberValue(6));
            declareVariable(new parser::Identifier("HARPSICHORD"),       new NumberValue(7));
            declareVariable(new parser::Identifier("CLAVINET"),          new NumberValue(8));

            //// Chromatic percussion
            declareVariable(new parser::Identifier("CELESTA"),           new NumberValue(9));
            declareVariable(new parser::Identifier("GLOCKEN"),           new NumberValue(10));
            declareVariable(new parser::Identifier("MUSICBOX"),          new NumberValue(11));
            declareVariable(new parser::Identifier("VIBES"),             new NumberValue(12));
            declareVariable(new parser::Identifier("MARIMBA"),           new NumberValue(13));
            declareVariable(new parser::Identifier("XYLOPHONE"),         new NumberValue(14));
            declareVariable(new parser::Identifier("TUBULAR_BELLS"),     new NumberValue(15));
            declareVariable(new parser::Identifier("DULCIMER"),          new NumberValue(16));

            //// Organ
            declareVariable(new parser::Identifier("DRAWBAR_ORGAN"),     new NumberValue(17));
            declareVariable(new parser::Identifier("PERCUSSIVE_ORGAN"),  new NumberValue(18));
            declareVariable(new parser::Identifier("ROCK_ORGAN"),        new NumberValue(19));
            declareVariable(new parser::Identifier("CHURCH_ORGAN"),      new NumberValue(20));
            declareVariable(new parser::Identifier("REED_ORGAN"),        new NumberValue(21));
            declareVariable(new parser::Identifier("ACCORDION"),         new NumberValue(22));
            declareVariable(new parser::Identifier("HARMONICA"),         new NumberValue(23));
            declareVariable(new parser::Identifier("TANGO ACCORDION"),   new NumberValue(24));

            //// Guitar
            declareVariable(new parser::Identifier("NYLON_GUITAR"),      new NumberValue(25));
            declareVariable(new parser::Identifier("STEEL_GUITAR"),      new NumberValue(26));
            declareVariable(new parser::Identifier("JAZZ_GUITAR"),       new NumberValue(27));
            declareVariable(new parser::Identifier("CLEAN_GUITAR"),      new NumberValue(28));
            declareVariable(new parser::Identifier("MUTE_GUITAR"),       new NumberValue(29));
            declareVariable(new parser::Identifier("OVERDRIVE_GUITAR"),  new NumberValue(30));
            declareVariable(new parser::Identifier("DIST_GUITAR"),       new NumberValue(31));
            declareVariable(new parser::Identifier("GUITAR_HARMONICS"),  new NumberValue(32));

            //// Bass
            declareVariable(new parser::Identifier("ACOUSTIC_BASS"),     new NumberValue(33));
            declareVariable(new parser::Identifier("FINGERED_BASS"),     new NumberValue(34));
            declareVariable(new parser::Identifier("PICK_BASS"),         new NumberValue(35));
            declareVariable(new parser::Identifier("FRETLESS_BASS"),     new NumberValue(36));
            declareVariable(new parser::Identifier("SLAP_BASS1"),        new NumberValue(37));
            declareVariable(new parser::Identifier("SLAP_BASS2"),        new NumberValue(38));
            declareVariable(new parser::Identifier("SYNTH_BASS1"),       new NumberValue(39));
            declareVariable(new parser::Identifier("SYNTH_BASS2"),       new NumberValue(40));

            //// Strings
            declareVariable(new parser::Identifier("VIOLIN"),            new NumberValue(41));
            declareVariable(new parser::Identifier("VIOLA"),             new NumberValue(42));
            declareVariable(new parser::Identifier("CELLO"),             new NumberValue(43));
            declareVariable(new parser::Identifier("CONTRABASS"),        new NumberValue(44));
            declareVariable(new parser::Identifier("TREMOLO_STRINGS"),   new NumberValue(45));
            declareVariable(new parser::Identifier("PIZZICATO_STRINGS"), new NumberValue(46));
            declareVariable(new parser::Identifier("HARP"),              new NumberValue(47));
            declareVariable(new parser::Identifier("TIMPANI"),           new NumberValue(48));

            //// Ensemble
            declareVariable(new parser::Identifier("STRINGS1"),          new NumberValue(49));
            declareVariable(new parser::Identifier("STRINGS2"),          new NumberValue(50));
            declareVariable(new parser::Identifier("SYNTH_STRINGS1"),    new NumberValue(51));
            declareVariable(new parser::Identifier("SYNTH_STRINGS2"),    new NumberValue(52));
            declareVariable(new parser::Identifier("CHOIR_AAH"),         new NumberValue(53));
            declareVariable(new parser::Identifier("VOICE_OOH"),         new NumberValue(54));
            declareVariable(new parser::Identifier("SYNTH_VOICE"),       new NumberValue(55));
            declareVariable(new parser::Identifier("ORCHESTRAL_HIT"),    new NumberValue(56));

            //// Brass
            declareVariable(new parser::Identifier("TRUMPET"),           new NumberValue(57));
            declareVariable(new parser::Identifier("TROMBONE"),          new NumberValue(58));
            declareVariable(new parser::Identifier("TUBA"),              new NumberValue(59));
            declareVariable(new parser::Identifier("MUTE_TRUMPET"),      new NumberValue(60));
            declareVariable(new parser::Identifier("FRENCH_HORN"),       new NumberValue(61));
            declareVariable(new parser::Identifier("BRASS_SECTION"),     new NumberValue(62));
            declareVariable(new parser::Identifier("SYNTH_BRASS1"),      new NumberValue(63));
            declareVariable(new parser::Identifier("SYNTH_BRASS2"),      new NumberValue(64));

            //// Reed
            declareVariable(new parser::Identifier("SOPRANO_SAX"),       new NumberValue(65));
            declareVariable(new parser::Identifier("ALTO_SAX"),          new NumberValue(66));
            declareVariable(new parser::Identifier("TENOR_SAX"),         new NumberValue(67));
            declareVariable(new parser::Identifier("BARITON_SAX"),       new NumberValue(68));
            declareVariable(new parser::Identifier("OBOE"),              new NumberValue(69));
            declareVariable(new parser::Identifier("ENGLISH_HORN"),      new NumberValue(70));
            declareVariable(new parser::Identifier("BASSOON"),           new NumberValue(71));
            declareVariable(new parser::Identifier("CLARINET"),          new NumberValue(72));

            //// Flutes
            declareVariable(new parser::Identifier("PICCOLO"),           new NumberValue(73));
            declareVariable(new parser::Identifier("FLUTE"),             new NumberValue(74));
            declareVariable(new parser::Identifier("RECORDER"),          new NumberValue(75));
            declareVariable(new parser::Identifier("PANFLUTE"),          new NumberValue(76));
            declareVariable(new parser::Identifier("BOTTLE"),            new NumberValue(77));
            declareVariable(new parser::Identifier("SHAKUHACHI"),        new NumberValue(78));
            declareVariable(new parser::Identifier("WHISTLE"),           new NumberValue(79));
            declareVariable(new parser::Identifier("OCARINA"),           new NumberValue(80));

            //// Lead Synth
            declareVariable(new parser::Identifier("SQUARE_LEAD"),       new NumberValue(81));
            declareVariable(new parser::Identifier("SAWTOOTH_LEAD"),     new NumberValue(82));
            declareVariable(new parser::Identifier("CALIOPE_LEAD"),      new NumberValue(83));
            declareVariable(new parser::Identifier("CHIFF_LEAD"),        new NumberValue(84));
            declareVariable(new parser::Identifier("CHARANG_LEAD"),      new NumberValue(85));
            declareVariable(new parser::Identifier("VOICE_LEAD"),        new NumberValue(86));
            declareVariable(new parser::Identifier("FIFTH_LEAD"),        new NumberValue(87));
            declareVariable(new parser::Identifier("BASS_LEAD"),         new NumberValue(88));

            //// Synth Pads
            declareVariable(new parser::Identifier("NEW_PAGE_PAD"),      new NumberValue(89));
            declareVariable(new parser::Identifier("WARM_PAD"),          new NumberValue(90));
            declareVariable(new parser::Identifier("POLY_SYNTH_PAD"),    new NumberValue(91));
            declareVariable(new parser::Identifier("CHOIR_PAD"),         new NumberValue(92));
            declareVariable(new parser::Identifier("BOWED_PAD"),         new NumberValue(93));
            declareVariable(new parser::Identifier("METAL_PAD"),         new NumberValue(94));
            declareVariable(new parser::Identifier("HALO_PAD"),          new NumberValue(95));
            declareVariable(new parser::Identifier("SWEEP_PAD"),         new NumberValue(96));

            //// Effects
            declareVariable(new parser::Identifier("RAIN"),              new NumberValue(97));
            declareVariable(new parser::Identifier("SOUNDTRACK"),        new NumberValue(98));
            declareVariable(new parser::Identifier("CRYSTAL"),           new NumberValue(99));
            declareVariable(new parser::Identifier("ATMOSPHERE"),        new NumberValue(100));
            declareVariable(new parser::Identifier("BRIGHT"),            new NumberValue(101));
            declareVariable(new parser::Identifier("GOBLINS"),           new NumberValue(102));
            declareVariable(new parser::Identifier("ECHOES"),            new NumberValue(103));
            declareVariable(new parser::Identifier("SCIFI"),             new NumberValue(104));

            //// Ethnic
            declareVariable(new parser::Identifier("SITAR"),             new NumberValue(105));
            declareVariable(new parser::Identifier("BANJO"),             new NumberValue(106));
            declareVariable(new parser::Identifier("SHAMISEN"),          new NumberValue(107));
            declareVariable(new parser::Identifier("KOTO"),              new NumberValue(108));
            declareVariable(new parser::Identifier("KALIMBA"),           new NumberValue(109));
            declareVariable(new parser::Identifier("BAGPIPE"),           new NumberValue(110));
            declareVariable(new parser::Identifier("FIDDLE"),            new NumberValue(111));
            declareVariable(new parser::Identifier("SHANAI"),            new NumberValue(112));

            //// Percussion
            declareVariable(new parser::Identifier("TINKLE_BELL"),       new NumberValue(113));
            declareVariable(new parser::Identifier("AGOGO"),             new NumberValue(114));
            declareVariable(new parser::Identifier("STEEL_DRUM"),        new NumberValue(115));
            declareVariable(new parser::Identifier("WOODBLOCK"),         new NumberValue(116));
            declareVariable(new parser::Identifier("TAIKO_DRUM"),        new NumberValue(117));
            declareVariable(new parser::Identifier("MELODIC_TOM"),       new NumberValue(118));
            declareVariable(new parser::Identifier("SYNTH_DRUM"),        new NumberValue(119));
            declareVariable(new parser::Identifier("REV_CYMBAL"),        new NumberValue(120));

            //// Sound Effects
            declareVariable(new parser::Identifier("FRET_NOISE"),        new NumberValue(121));
            declareVariable(new parser::Identifier("BREATH_NOISE"),      new NumberValue(122));
            declareVariable(new parser::Identifier("SEASHORE"),          new NumberValue(123));
            declareVariable(new parser::Identifier("TWEET"),             new NumberValue(124));
            declareVariable(new parser::Identifier("TELEPHONE"),         new NumberValue(125));
            declareVariable(new parser::Identifier("HELICOPTER"),        new NumberValue(126));
            declareVariable(new parser::Identifier("APPLAUSE"),          new NumberValue(127));
            declareVariable(new parser::Identifier("GUNSHOT"),           new NumberValue(128));
        }
    }
}
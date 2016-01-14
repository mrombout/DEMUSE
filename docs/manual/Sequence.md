# Sequence

This chapter explains how to use sequences, how to use them effectively, and
explains a little it about the internal working to have a deeper understanding
of how to use DEMUSE sequences. This will enable you to create music using a 
simple system that should be quite familiar with users that are used to music
trackers and its features.

\section introduction Introduction

A DEMUSE scripts compiled to a music format (currently only `.midi`), this is
done from script using sequences. Without them DEMUSE doesn't really do
anything useful at all.

For example, to play a simple C note, the following script could be used:

```
track 1 {
    <<C>>;
}
```

The DEMUSE compiler will create a new `.midi` file containing a single note
that will be played for a whole note (default) on a (default) measure of 4/4
using a (default) speed of 120.

\section parts Parts

A DEMUSE sequence is built out of several Notes, a Note in DEMUSE is an entity
that has a note, an octave, an accidental and a length. Each of these entities
is seperated by a space. Other command other than notes are also available and
explained in this chapter.

\subsection notes Notes

A note begins with with a note, a note is represents by the following letters
which should be familiar: `C`, `D`, `E`, `F`, `G`, `A`, `B`. A character for
a rest (`R`) is also available.

A note may be followed by an octave, an accidental and finally a duration.

```
track 1 {
    <<C>>;
}
```

\subsection accidental Accidental

You can indicate that a note is sharp of flat by using the `#` character to
represent a sharp, or a `b` character to represent a flat. One of these
characters must be placed immediatly after a note. For example a B-flat would
be represented as `Bb`.

You can also explicitely mark a note as natural using the `n` character. Notes
are natural by default, so in most cases marking notes as natural is not
necessary.

```
track 1 {
    <<Bb>>;
}
```

\subsection octave Octave

You may optionally specify an octave for the note, which is represented by a
number from 0 to 10. For example, `C6` plays a C note in the sixth octave. If
no octave is specified, the default for a note wil be the fifth octave.

```
track 1 {
    <<C6>>;
}
```

\subsection duration Duration

Duration inicates how long a note should be played. It must be place after a
Note (and after the octave or accidental if they are present). The default
duration of a note is `q`, a quarter-note.

```
| Duration            | Character |
| ------------------- | --------- |
| (w)hole             | w         |
| (h)alf              | h         |
| (q)uarter           | q         |
| e(i)ghth            | i         |
| (s)ixteenth         | s         |
| (t)hirty-second     | t         |
| si(x)ty-fourth      | x         |
| (o)ne-twenty-eighth | o         |
```

For example, a C6 note, half duration would be `C6h`.

```
track 1 {
    <<Cq Cq Cq Cq | Ch Ch | C>>;
}
```

\subsection instrument Instrument

The music produced by JFugue uses MIDI to render audio that is played with
instruments from the Java Sound soundbank. The MIDI specification describes
128 different instruments, and more may be supported with additional sound
banks. Most MIDI devices use the same deifnition for the first 128instruments,
although the quality of the sound varies by device and by soundbank. 
 
DEMUSE defaults to the first instrument in the MIDI soundbank. Which is marked
as being a `Piano`.

```
track 1 {
    <<I[5] C>>;
}
```

\subsection tempo Tempo

The tempo is set in `BPM` and defaults to 120BPM. The tempo is a variable in
the global `Song` object. Since it's global the tempo variable can be set form
anywhere.

A sequence uses the most recent tempo that is set. Changing the tempo mid-way
will not chance the tempo of other notes already "played" in another sequence.

```
tempo = 220;

track 1 {
    <<Cq Cq Ch>>;
}
```
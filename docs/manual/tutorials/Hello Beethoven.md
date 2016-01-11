# Hello Beethoven!

The "Hello World!" tutorial isn't really that interesting. Fortunatly, DEMUSE can do quite a lot more than that, one of
the things is create music! Well, not really, you are the one that creates the music, but DEMUSE is quite a tool to do
that in a non-traditional, but very fun way.

Start with creating a new DEMUSE file, say `HelloBeethoven.muse`. Again, DEMUSE scripts often end with the `.muse`
extension, but this is not required in any way.

When you are creating music with DEMUSE you are required to create a least one track, so lets create on now.

```
track 1 {

}
```

A track is a simple mean to organize your song, but are also useful to play multiple notes simultaneously for formats
that do not support simultaneous notes on the same track (such as the .mod format). You can learn more about tracks in
later tutorials.

In order to play a note in your first track you must use a `sequence`. A `sequence` is one of more notes between the
"<<" and ">>" characters. So add the following `sequence` to `track 1` and compile and play your script.

```
track 1 {
    <<Eq Eq Fq Gq | Gq Fq Eq Dq | Cq Cq Dq Eq | Eq Dq Dh | Eq Eq Fq Gq | Gq Fq Eq Dq | Cq Cq Dq Eq | Dq Cq Ch>>;
}
```

You now know the true power of DEMUSE and are on your way to become the next great DEMUSE composer!
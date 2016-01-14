# Tutorials

This page contains a number of tutorials that will help you get familiar with
the tools and the language itself.

\section hello_world Hello World!
## Hello World!

No programming language is worth anything without a "Hello World" tutorial. Hence, in a dire effort to make DEMUSE more
only slight more relevant that an oven roasted potato with chives, here's one for DEMUSE too!

First, create a new file, say `HelloWorld.muse`. DEMUSE scripts often end with the `.muse` extension, but this is not
required in any way.

Since DEMUSE is a simple language, a program that prints "Hello World" is just a single line, and a rather boring one
too.

```
print("Hello World!");
```

It's rather simple, and very underwhelming indeed. If you paid really close attention to the console window after you
compiled this little program you noticed the string "Hello World!" somewhere hidden between the other lines. This is
because DEMUSE actually compiled to a music format such as .mod or .mid. There is no actual runtime and thus the only
place for DEMUSE to print that line is during compilation! The 'print()' function is mainly used for debugging
purposes.

\section hello_beethoven Hello Beethoven!
## Hello Beethoven!

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
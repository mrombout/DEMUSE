# Hello World!

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

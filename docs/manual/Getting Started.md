Welcome to DEMUSE For Beginners! If this is your first time programming, it's
recommended to start with a more reliable, secure and serious language, also 
known as a "real" programming language. DEMUSE is a toy language originally
developed as an exercise to learn about compilers and pogramming languages, and
today still is nothing more than that.

If however, you are not beginning programming, and for some unknown reason, are
still interested in learning more about DEMUSE, keep on reading!

\section installing Installing

Everything that is needed to run (the compiler) DEMUSE scripts and develop 
DEMUSE scripts (the ide) are available for Windows as an installer or zip, or
for Linux as a .deb, .rpm and .tar.gz file. Installing is very straight forward
as DEMUSE doesn't need anything other that that what is provided in the
aforementioned installation packages.

If you do need help, or if something is working as it's supposed to be, feel
free to create a new issue on the DEMUSE repository on GitHub.

\section running Running

DEMUSE comes with it's own IDE which offers very basic coding notepad
functionality like syntax highlighting, very basic autocompletion and a run
button that will compile your DEMUSE script and plays the resulting sound file.

However the IDE is completely optional, instead any plain text editor can be
used to edit DEMUSE files. Simple pass your script to the `compiler.exe` inside
your chosen DEMUSE installation directory to compile your scripts into a sound
file.

\subsection running_ide Running a DEMUSE script from the IDE

When pressing the `play` button in the ide the compiler builds the script
opened in the active tab. Next the default program for `.midi` files is
started with the resulting output file. On Windows this program is the Windows
Media Player. Though any other program that can work with `.midi` files will
work.

\subsection running_cmd Running a DEMUSE script from something else

A script can simple be compiled by passing it as the first argument of the
`compiler.exe` in the installation directory of your DEMUSE installation.

```
./compiler "my_first_script.muse"
```

\section learning Learning

There is a list of tutorials available on the Tutorials page. The online
documentation also provides a list of all objects and functions available in
the language. And finally, a range of example programs are also available on
the Examples page.

\section faq Frequently Asked Questions

You question might have already been answered on the FAQ page. If it isn't feel
free to create a new issue on the DEMUSE Github repository or contact me
directly through e-mail.
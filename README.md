
# howbigis
## Overview

As its name suggests, "howbigis" is a simple utility for getting a file's size

Today, I took on the [2020 Reset64 4KB Craptastic Game Competition](http://www.ausretrogamer.com/2020-reset64-4kb-craptastic-game-competition/), a hilarious programming challenge where you try to build a funny game in only 4 KB.  I was writing a Makefile for it and wanted a way to quickly get the size of my compiled program.  Yes, I know, I could run "ls -l", but that gives you a bunch of extra stuff I didn't need or want, and it's formatted in bytes.  This is much simpler.

## Compiling

I used a Makefile, mostly because I'm trying to learn to use Makefiles, but you could just as easily copy its contents and paste them into your terminal.  This program is written in standard C and has third-party dependencies.  I built it on Linux, but you could just as easily add the files to a Visual Studio project and compile for Windows, or (Mac folks please correct me if I'm wrong) import into X-Code and compile for Mac.

## Documentation

```howbigis [file] [format]
    file    The name/path of the file
    format  The format to use.  Valid formats are:
            -b (bytes)
            -k (kilobytes)
            -m (megabytes)
            -g (gigabytes)
            If no format is used, it will choose
            whatever makes the most sense.
Examples:
    howbigis ./pic.png -k
    howbigis ./ubuntu.iso -g
    howbigis /var/www/html/index.php```

## Unlicense

This is freed software.  Period.

## Contributing

I don't know how many more features this program realistically needs, but there plenty of other things it could do.  Some ideas I can think of are:

* Adding support for terabytes and petabytes - I don't know what file could possibly be that humongous, but still, it could be done.
* Doing the calculation in bits rather than bytes (dividing by 1000 rather than 1024).  I know some measurements are done that way, though I'm not sure why.  Isn't that connection speeds or something?  Either way, again, it could be done.
* Better docs?  I kind of think these are pretty thorough, but then again I don't speak Korean, or Farsi, or German..  Maybe adding docs in other languages?  Again, I don't know why (it seems browsers can translate now), but again, it could be done.

Bottom line, you're welcome to contribute, or fork it and add features if you want.  That's what freed software is all about.

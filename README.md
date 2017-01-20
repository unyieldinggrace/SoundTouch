# SoundTouch
## What is SoundTouch?
SoundTouch is a library for adjusting the pitch and tempo of audio.  Originally written by Olli Parviainen and released under the LGPL.  The code in this repository is forked from version 1.9.2.  The original SoundTouch is available from https://www.surina.net/soundtouch

## Why this fork?
The version of SoundTouch I was working with provided only a C++ API for Linux, and only a C API on Windows.  I was developing a cross-platform app and I wanted to be able to use one interface on both Windows and Linux.  I have modified some files in the `source/SoundTouchDLL` directory (which contains the wrapper code for the C API).  The modifications enable the shared library for the C API to be built on Linux.  By doing this, my app can use the C API on both platforms.

## How do I compile it?
### Windows
To compile SoundTouch on Windows, use the `make-win.bat` script in the root directory (you must have Visual Studio installed, and you will probably have to run `vcvars32.bat` from the `bin` directory of your Visual Studio installation before `make-win.bat` will work.

This will build everything you need, including `libSoundTouchDLL.dll` which is what you will link against on Windows.

### Linux
Starting in the project root directory, run the following commands:

```bash
./bootstrap
./configure
make
sudo make install
```
This will build and install all the libraries and executables defined in the original SoundTouch distribution.  This includes the core C++ library `libSoundTouch.so`.  After this, run:
```bash
cd source/SoundTouchDLL
make
sudo make install
sudo ldconfig
```
This will build the file `libSoundTouchC.so` and copy it to `/usr/local/lib/libSoundTouchC.so`.

Your application will need to link against both `libSoundTouchC.so` *and* `libSoundTouch.so`.  Do this by specifying `-lSoundTouchC -lSoundTouch` on the command line.  For example:

```g++ -o myapp main.cpp -lSoundTouchC -lSoundTouch```

### Both Platforms
On both Windows and Linux, your application will have to use `#include "SoundTouchDLL.h"` rather than just `#include "SoundTouch.h"`.  Yes, it is still called `SoundTouchDLL.h` on Linux ;)  That header is found in the `source/SoundTouchDLL` directory of this repo, but it is *not* installed to `/usr/local/include/soundtouch` by default like the other header files.  You can either copy it there, or add an include directory to your compile command (e.g. `g++ -o myapp -I/path/to/SoundTouch/source/SoundTouchDLL -lSoundTouchC -lSoundTouch`).

Backlin's QMK lib
=================
Instructions mostly written for my own poor memory.

Only developed for Mac.


## Setup
Copy into subfolder `scr` of keymap dir.

Add all `*.c` files to `rules.mk`.
This will append them to the inputs of the `Makefile` recipe in the QMK root.

```
SRC += src/backlin.c src/macro.c src/magnet.c src/rgbmatrix.c
```

`#include "src/backlin.h"` in `keymap.c`.

Compile, flash.

Configure MacOS to recognize keyboard as a standard Swedish ISO keyboard with input source "Swedish".

### GoLand
Check the head of `src/macro.c` for keyboard shortcut setup.

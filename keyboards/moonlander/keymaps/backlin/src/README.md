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


## Optional features

### Box drawing layer
Add a second input source "Unicode Hex Input".
You should now have 2 sources: Swedish and Unicode.
Anything else won't work properly.

```
#define CB_BOXDRAW_ENABLE
```

This runs as a macro hack to avoid having to plow through https://github.com/qmk/qmk_firmware/blob/master/docs/feature_unicode.md 

### Secrets manager

```
#define CB_SECRET_1 testtest
```

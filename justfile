help:
    qmk -h

# https://docs.qmk.fm/newbs_getting_started
setup_macos:
    curl -fsSL https://install.qmk.fm | sh
    qmk setup

link:
    ln -sf keyboards/zsa/moonlander/keymaps/backlin moonlander
    ln -sf keyboards/preonic/keymaps/backlin preonic

compile-preonic:
    qmk compile -kb preonic/rev3 -km backlin

flash-preonic:
    qmk flash -kb preonic/rev3 -km backlin

compile-moonlander:
    qmk compile -kb zsa/moonlander -km backlin

flash-moonlander:
    qmk flash -kb zsa/moonlander -km backlin

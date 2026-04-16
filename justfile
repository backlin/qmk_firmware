help:
    qmk -h

# https://docs.qmk.fm/newbs_getting_started
setup_macos:
    curl -fsSL https://install.qmk.fm | sh
    qmk setup

compile-preonic:
    qmk compile -kb preonic/rev3 -km backlin

flash-preonic:
    qmk flash preonic_rev3_backlin.bin

compile-moonlander:
    qmk compile -kb moonlander -km backlin

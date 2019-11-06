ergodox-layout
==============
## How to make
```
$ git clone git@github.com:aikiyy/ergodox-layout.git
$ git clone git@github.com:qmk/qmk_firmware.git

# cp mysetting file
$ cp -r ergodox-layout/mysetting qmk_firmware/keyboards/ergodox_ez/keymaps

# make
$ cd qmk_firmware
$ make clean && make keyboard=ergodox_ez keymap=mysetting
```

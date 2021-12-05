ergodox-layout
==============
## How to make
```
$ git clone git@github.com:aikiyy/ergodox-layout.git
$ git clone git@github.com:qmk/qmk_firmware.git

$ cp -r ergodox-layout/mysetting qmk_firmware/keyboards/ergodox_ez/keymaps

$ cd qmk_firmware
$ util/docker_build.sh ergodox_ez:mysetting
```

## Load
https://www.pjrc.com/teensy/loader_mac.html
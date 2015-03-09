#!/bin/bash

make -j4 modules_install
make -j4 install
update-initramfs -c -k 3.19.0-buddythreads
update-grub

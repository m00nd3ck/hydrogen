#!/bin/bash
make clean
make kernel_x86
rm *.o
qemu-system-i386 -kernel kernel.mkern -m size=16M -serial stdio
rm kernel.mkern
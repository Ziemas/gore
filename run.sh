#!/usr/bin/env bash

make -C ee
make -C iop

mkdir -p bin
cp ee/main.elf bin/
cp iop/gore.irx bin/

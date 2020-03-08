#!/bin/bash
set -x
cd build
pkill worldserver
pkill authserver

cmake ../ \
	-DCMAKE_INSTALL_PREFIX=/home/$USER/wow_server \
	-DCONF_DIR=/home/$USER/wow_server \
	/
make -j $(nproc) install



Debian
====================
This directory contains files used to package amsterdamcoind/amsterdamcoin-qt
for Debian-based Linux systems. If you compile amsterdamcoind/amsterdamcoin-qt yourself, there are some useful files here.

## amsterdamcoin: URI support ##


amsterdamcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install amsterdamcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your amsterdamcoinqt binary to `/usr/bin`
and the `../../share/pixmaps/amsterdamcoin128.png` to `/usr/share/pixmaps`

amsterdamcoin-qt.protocol (KDE)


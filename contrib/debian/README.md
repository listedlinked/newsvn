
Debian
====================
This directory contains files used to package newsvnd/newsvn-qt
for Debian-based Linux systems. If you compile newsvnd/newsvn-qt yourself, there are some useful files here.

## newsvn: URI support ##


newsvn-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install newsvn-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your newsvnqt binary to `/usr/bin`
and the `../../share/pixmaps/newsvn128.png` to `/usr/share/pixmaps`

newsvn-qt.protocol (KDE)


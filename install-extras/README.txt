This folder will contain some files used during the installation process of the library, compilers and softwares needed in the project.

[filename :
explanation]

build_arm_toolchain.sh :
This file is used in step 1 of the nxtOSEK installation in Linux (http://lejos-osek.sourceforge.net/installation_linux.htm). In the tutorial the shell file is configured to install binutils-2.20 instead of binutils-2.20.1. However the version 2.20 is not available. Therefore this shell on our repository is configured to use binutils-2.20.1

tool_gcc.mak :
This file is used in step 1 of the nxtOSEK installation in Linux (http://lejos-osek.sourceforge.net/installation_linux.htm).
The tutorial says you should set the path of your GNUARM. 
You ALSO need to comment the following lines of the file:
#ifndef NEXTTOOL_ROOT
#NEXTTOOL_ROOT = /cygdrive/C/cygwin/nexttool
#endif

bricxcc_src_33719.zip :
This file is used in step 4 of the nxtOSEK installation in Linux (http://lejos-osek.sourceforge.net/installation_linux.htm).
In step 4, build bricxcc froum source and use this .zip files (http://sourceforge.net/projects/bricxcc/files/bricxcc_source/bricxcc%203.3.7.19/)

# C++BuilderX Version: 1.0.0.1786
# Generated GNU Makefile
# Do not modify, as your changes will be lost on re-export

# User Defined Variables:
ifndef BCBX
  BCBX := C:\CBuilderX
endif
# End User Defined Variables

# Start of configurations
# If the user specified no configuration on the command line, set a default:
ifndef CFG
  CFG := Debug Build
endif
ifeq ($(CFG),Debug Build)
  BUILD_DIR := windows\Debug_Build
  Debug Build := 1
endif
ifeq ($(CFG),Release Build)
  BUILD_DIR := windows\Release_Build
  Release Build := 1
endif
ifneq ($(CFG),Debug Build)
  ifneq ($(CFG),Release Build)
    $(error An incorrect configuration was specified)
  endif
endif
# End of configurations

ifeq ($(CFG),Debug Build)
  # Default build target if none specified:
default: builddir windows\Debug_Build\bookexample.exe

all: default

windows\Debug_Build\Welcome.obj: Welcome.cpp
	bcc32 -D_DEBUG -g100 -j25 -Od -r- -k -y -v -vi- -tWC -c -I$(BCBX)\include -o$(BUILD_DIR)\Welcome.obj   Welcome.cpp

windows\Debug_Build\bookexample.exe: windows\Debug_Build\Welcome.obj
	ilink32 -D -ap -Tpe -x -Gn -v -L$(BCBX)\lib  c0x32.obj windows\Debug_Build\Welcome.obj,$(BUILD_DIR)\bookexample.exe,,cw32.lib import32.lib,,

builddir:
	-mkdir windows
	-mkdir windows\Debug_Build

clean:
	-del windows\Debug_Build\Welcome.obj
	-del windows\Debug_Build\Welcome.csm
	-del windows\Debug_Build\bookexample.exe
	-del windows\Debug_Build\bookexample.map
	-del windows\Debug_Build\bookexample.ilc
	-del windows\Debug_Build\bookexample.ilf
	-del windows\Debug_Build\bookexample.ils
	-del windows\Debug_Build\bookexample.tds
	-del windows\Debug_Build\bookexample.ild

endif
ifeq ($(CFG),Release Build)
  # Default build target if none specified:
default: builddir windows\Release_Build\bookexample.exe

all: default

windows\Release_Build\Welcome.obj: Welcome.cpp
	bcc32 -g100 -j25 -O2 -k- -vi -tWC -c -I$(BCBX)\include -o$(BUILD_DIR)\Welcome.obj   Welcome.cpp

windows\Release_Build\bookexample.exe: windows\Release_Build\Welcome.obj
	ilink32 -ap -Tpe -x -Gn -L$(BCBX)\lib  c0x32.obj windows\Release_Build\Welcome.obj,$(BUILD_DIR)\bookexample.exe,,cw32.lib import32.lib,,

builddir:
	-mkdir windows
	-mkdir windows\Release_Build

clean:
	-del windows\Release_Build\Welcome.obj
	-del windows\Release_Build\Welcome.csm
	-del windows\Release_Build\bookexample.exe
	-del windows\Release_Build\bookexample.map
	-del windows\Release_Build\bookexample.ilc
	-del windows\Release_Build\bookexample.ilf
	-del windows\Release_Build\bookexample.ils
	-del windows\Release_Build\bookexample.tds
	-del windows\Release_Build\bookexample.ild

endif

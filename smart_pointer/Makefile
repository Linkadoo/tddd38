#
# Makefile for smart_pointer, compiled with GNU GCC.
#
## Targets:
#
## daw   - desired and working (shall compile and work properly)
# uanw  - undesired and not working (shall not compile)
# # todo  - to do
# # clean - deletes certain compilation products
# # zap   - deletes *everything*, except source code and make files
# #
# # Require module prog/gcc/4 on IDA's Solaris system. Environment variable
# # GCC4_V is set to the current GCC version (e.g. 4.7.1).
# #
#
# #CCC      = g++
CCC      = gccfilter -c -a g++
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra -Werror
LDFLAGS  = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

all:
		@ echo "make one of: daw, uanw, todo, clean or zap"

daw: smart_pointer.h smart_pointer-test.cc
		$(CCC) $(CCFLAGS) $(LDFLAGS) -DDESIRED_AND_WORKING \
					-o desired-and-working smart_pointer-test.cc

uanw: smart_pointer.h smart_pointer-test.cc
		$(CCC) $(CCFLAGS) $(LDFLAGS) -DUNDESIRED_AND_NOT_WORKING \
					-o undesired-and-not-working smart_pointer-test.cc

todo: smart_pointer.h smart_pointer-test.cc
		$(CCC) $(CCFLAGS) $(LDFLAGS) -DTO_DO -o todo smart_pointer-test.cc

clean:
		@ \rm -f *.o *.gch core

zap: clean
		@ \rm -rf *~ desired-and-working undesired-and-not-working todo

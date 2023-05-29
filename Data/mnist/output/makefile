PROGRAM = main

SRCS = brianlib/randomkit/randomkit.c code_objects/neurongroup_2_group_variable_set_conditional_codeobject.cpp code_objects/neurongroup_2_stateupdater_codeobject.cpp code_objects/neurongroup_2_stateupdater_codeobject_1.cpp code_objects/statemonitor_codeobject.cpp code_objects/statemonitor_codeobject_1.cpp main.cpp network.cpp objects.cpp run.cpp synapses_classes.cpp
H_SRCS = brianlib/clocks.h brianlib/common_math.h brianlib/dynamic_array.h code_objects/neurongroup_2_group_variable_set_conditional_codeobject.h code_objects/neurongroup_2_stateupdater_codeobject.h code_objects/neurongroup_2_stateupdater_codeobject_1.h code_objects/statemonitor_codeobject.h code_objects/statemonitor_codeobject_1.h network.h objects.h run.h synapses_classes.h
OBJS = ${SRCS:.cpp=.o}
OBJS := ${OBJS:.c=.o}
OPTIMISATIONS = -Ibrianlib/randomkit -I/usr/local/Caskroom/miniconda/base/envs/brian2/include -I/usr/local/Caskroom/miniconda/base/envs/brian2/lib/python3.9/site-packages/brian2/synapses -w -O3 -ffast-math -fno-finite-math-only -march=native -std=c++11
CXXFLAGS = -c -Wno-write-strings $(OPTIMISATIONS) -I.  
LFLAGS =  -Lbrianlib/randomkit -L/usr/local/Caskroom/miniconda/base/envs/brian2/lib -Wl,-rpath,/usr/local/Caskroom/miniconda/base/envs/brian2/lib 
DEPS = make.deps

all: $(PROGRAM)

.PHONY: all clean

$(PROGRAM): $(OBJS) $(DEPS) makefile
	$(CXX) $(OBJS) -o $(PROGRAM) $(LFLAGS)

clean:
	rm $(OBJS) $(PROGRAM) $(DEPS)

make.deps: $(SRCS) $(H_SRCS)
	$(CXX) $(CXXFLAGS) -MM $(SRCS) > make.deps
	
ifneq ($(wildcard $(DEPS)), )
include $(DEPS)
endif

%.o : %.cpp makefile
	$(CXX) $(CXXFLAGS) $< -o $@
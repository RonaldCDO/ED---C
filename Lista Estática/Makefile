#Project Name	
PROJ_NAME=Lista_estatica

#.c Files
C_SOURCE=$(wildcard ./source/*.c)

#.h Files
H_SOURCE=$(wildcard ./source/*.h)

#Object Files
OBJ=$(subst .c,.o,$(subst source,objects,$(C_SOURCE)))

#Compilator
CC=gcc

#Compilator Flags
CC_FLAGS=-c        \
         -W        \
         -Wall     \
         -pedantic \
         
#Remove Command
RM=rm -rf

#
#Linking and Compiling
#
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC Linker' 
	$(CC) $^ -o $@ 
	@ echo 'Finished building binary'

./objects/%.o: ./source/%.c ./source/%.h
	@echo 'Building target using GCC Compiler'
	$(CC) $< $(CC_FLAGS) -o $@ 
	@echo ' ' 

./objects/main.o: ./source/main.c $(H_SOURCE)
	@echo 'Building target using GCC Compiler'
	$(CC) $< $(CC_FLAGS) -o $@ 
	@echo ' ' 

objFolder:
	@ mkdir -p objects

clean: 
	@ $(RM) ./objects/*.o $(PROJ_NAME) *~ 
	@ rmdir objects

.PHONY: all clean

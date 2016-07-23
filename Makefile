CXX = g++-5
CXXFLAGS = -std=c++14 -Werror=vla -Wall -MMD
OBJECTS = ai.o atkpot.o cell.o character.o defpot.o dragon.o dwarf.o elf.o gamehandler.o gamemap.o goblin.o gold.o hppot.o human.o item.o main.o merchant.o npc.o orc.o pc.o phoenix.o potion.o sprite.o stairs.o stationary.o textui.o troll.o vampire.o werewolf.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

default: ${EXEC}

debug: CXXFLAGS += -DDEBUG -g
debug: ${EXEC}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm *.o *.d ${EXEC}

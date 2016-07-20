#include "gamehandler.h"
#include <cstdlib>

int main(int argc, const char *argv[])
{
    GameHandler gh;
    if(argc < 2) {
        cout << "Please provide the floor layout" << endl;
        exit(0);
    }
    gh.play(argv[1]);
}

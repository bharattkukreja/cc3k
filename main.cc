#include "gamehandler.h"
#include "gamemap.h"
#include "textui.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, const char *argv[])
{
    GameMap g;
    TextUI ui(cin, cout);
    GameHandler gh(g, ui);
    if(argc < 2) 
        gh.play("layout.txt");
    else    
        gh.play(argv[1]);
}

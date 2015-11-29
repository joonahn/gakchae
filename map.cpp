#include "map.h"

Map::Map(MainWindow *_mainwindow)
{
    //Initialize & Load RC1 stage
    mainwindow = _mainwindow;
    me = new Character(this, this, 0);
    for(int i = 0;i<JUNWI_NUM;i++)
    {
        //ERROR Saejunwi(this,x,y)
        //Initial Junwi Position Needed
        junwis[asdf] = new Saejunwi();
    }
}

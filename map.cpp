#include "map.h"
#include "game.h"

Game * game;

int rc1_mapdata[20][70] = {
    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 1, 7, 1, 7, 1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 7, 7, 1, 7, 1, 7, 1, 7, 1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 7, 5, 4, 4, 4, 4, 4, 7, 7, 7, 7, 4, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 4, 4, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 7, 6, 4, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 1, 7, 1, 7, 1, 7, 7, 4, 7, 7, 7, 7, 7, 4, 5, 6, 5, 6, 5, 6, 5, 6, 5, 4, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7},
    {7, 7, 7, 7, 7, 7, 5, 4, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 4, 5, 1, 7, 1, 7, 1, 7, 1, 7, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 4, 7, 4, 7, 7, 7, 4, 7, 7, 7, 4, 7, 7},
    {7, 7, 7, 7, 7, 7, 6, 4, 2, 7, 7, 7, 7, 7, 4, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 4, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 7, 7, 4, 4, 7, 4, 7, 7, 7, 4, 7, 7, 7, 4, 7, 7},
    {7, 7, 7, 7, 7, 7, 5, 4, 7, 7, 7, 7, 7, 7, 4, 7, 7, 4, 4, 4, 4, 4, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 2, 7, 7, 7, 4, 2, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 7, 7, 4, 7, 7, 7, 4, 7, 7, 7, 4, 7, 7},
    {7, 7, 7, 7, 7, 7, 6, 4, 2, 7, 7, 7, 7, 7, 4, 7, 7, 4, 4, 4, 5, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 4, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 4, 7, 7, 7, 4, 7, 7, 7, 4, 7, 7},
    {7, 7, 7, 7, 7, 7, 5, 4, 7, 7, 7, 7, 7, 7, 4, 7, 7, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 2, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 7, 7, 7, 4, 7, 7},
    {7, 7, 7, 7, 7, 7, 6, 4, 2, 7, 7, 7, 7, 7, 4, 5, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 4, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 4, 7, 7, 4, 7, 7, 7, 7, 4, 7, 7},
    {7, 7, 7, 7, 7, 7, 5, 4, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 5, 6, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 2, 7, 7, 7, 4, 2, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 5, 5, 4, 7, 7, 7, 7, 4, 7, 7},
    {7, 7, 7, 7, 7, 7, 6, 4, 2, 7, 7, 7, 7, 7, 7, 4, 4, 4, 6, 5, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 4, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 4, 4, 4, 4, 7, 7, 7, 7, 8, 7, 7},
    {7, 7, 7, 7, 7, 7, 5, 4, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 2, 7, 7, 7, 4, 2, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 4, 5, 5, 4, 7, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 7, 6, 4, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 4, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 4, 5, 6, 5, 6, 5, 6, 5, 6, 5, 4, 7, 7, 7, 7, 7, 4, 7, 7, 4, 7, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 7, 5, 4, 4, 4, 4, 4, 7, 0, 7, 0, 7, 0, 7, 7, 4, 4, 5, 7, 1, 7, 1, 7, 1, 7, 1, 7, 4, 7, 1, 7, 7, 4, 7, 7, 1, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 4, 6, 6, 4, 7, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 7, 7, 0, 7, 0, 7, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 0, 7, 0, 7, 0, 7, 0, 7, 4, 7, 7, 1, 7, 7, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 7, 0, 7, 7, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 7, 0, 7, 0, 7, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}
};

int rc2_mapdata[20][70]={
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 },
    { 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 1, 1, 1, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 },
    { 7, 7, 7, 7, 7, 7, 4, 7, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6, 6, 0, 0, 0, 7, 7, 7, 4, 7, 7, 5, 5, 0, 0, 0, 7, 7, 4, 7, 7, 5, 5, 7, 4, 4, 4, 4, 4, 4, 7, 7, 7 },
    { 7, 7, 8, 7, 7, 7, 4, 7, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 4, 7, 7, 7, 0, 0, 0, 7, 6, 6, 4, 6, 6, 6, 7, 7, 7, 7, 7, 4, 7, 7, 5, 5, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 4, 7, 7, 7 },
    { 7, 7, 4, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 5, 5, 7, 7, 4, 2, 7, 7, 7, 7, 7, 6, 6, 6, 4, 7, 6, 6, 6, 7, 7, 7, 3, 4, 2, 7, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 5, 5, 7, 4, 2, 7, 7, 7, 4, 7, 7, 7 },
    { 7, 7, 4, 7, 7, 7, 4, 7, 7, 7, 7, 7, 5, 5, 7, 4, 7, 5, 5, 7, 4, 7, 5, 5, 7, 3, 4, 2, 7, 7, 7, 7, 6, 6, 6, 7, 4, 7, 7, 6, 6, 6, 7, 7, 3, 4, 2, 7, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 5, 5, 3, 4, 2, 7, 7, 7, 4, 7, 7, 7 },
    { 7, 7, 4, 7, 7, 7, 4, 7, 7, 7, 7, 7, 5, 5, 3, 4, 2, 5, 5, 3, 4, 2, 5, 5, 7, 3, 4, 2, 7, 7, 7, 6, 6, 6, 7, 7, 4, 7, 7, 7, 6, 6, 6, 7, 7, 4, 7, 7, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 5, 5, 3, 4, 2, 7, 7, 7, 4, 7, 7, 7 },
    { 7, 7, 4, 7, 7, 7, 4, 2, 7, 7, 7, 7, 5, 5, 3, 4, 2, 5, 5, 3, 4, 2, 5, 5, 7, 3, 4, 7, 7, 7, 6, 6, 6, 7, 7, 7, 4, 7, 7, 7, 7, 6, 6, 6, 7, 4, 7, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 4, 7, 7, 7, 7, 4, 7, 7, 7 },
    { 7, 7, 4, 7, 7, 7, 4, 2, 7, 7, 7, 7, 5, 5, 7, 4, 7, 5, 5, 7, 4, 7, 5, 5, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 4, 7, 7, 7, 7, 4, 7, 7, 7 },
    { 7, 7, 4, 7, 7, 7, 4, 2, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 5, 5, 7, 7, 4, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7 },
    { 7, 7, 4, 7, 7, 7, 4, 7, 7, 7, 7, 4, 5, 5, 0, 0, 0, 5, 5, 3, 4, 7, 7, 7, 7, 7, 4, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 7, 7, 0, 0, 0, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 7, 7, 7, 4, 7, 7, 7 },
    { 7, 7, 4, 7, 7, 7, 4, 7, 7, 7, 7, 4, 5, 5, 7, 7, 7, 5, 5, 3, 4, 7, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 7, 7, 7, 4, 7, 7, 7 },
    { 7, 7, 4, 4, 4, 4, 4, 7, 1, 1, 7, 4, 5, 5, 7, 7, 7, 5, 5, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 6, 6, 7, 7, 7, 7, 7, 7, 7, 4, 2, 7, 7, 7, 7, 7, 5, 5, 7, 7, 7, 7, 7, 7, 5, 5, 4, 2, 7, 7, 4, 7, 7, 7 },
    { 7, 7, 7, 7, 4, 7, 4, 4, 4, 4, 4, 4, 5, 5, 7, 7, 7, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 6, 6, 7, 7, 7, 7, 7, 7, 7, 4, 2, 7, 7, 7, 7, 7, 5, 5, 7, 7, 7, 7, 7, 7, 5, 5, 4, 2, 7, 7, 4, 7, 7, 7 },
    { 7, 7, 7, 7, 4, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 6, 6, 7, 7, 7, 7, 7, 7, 7, 4, 2, 7, 7, 7, 7, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 2, 7, 7, 4, 7, 7, 7 },
    { 7, 7, 7, 7, 4, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 7, 4, 7, 1, 1, 1, 7, 6, 6, 7, 7, 1, 1, 1, 7, 7, 4, 7, 7, 7, 7, 7, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 7, 7, 7, 9, 7, 7, 7 },
    { 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 1, 1, 1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 7, 7 },
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7 },
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 },
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 }

};

Map::Map(QMainWindow *_mainwindow,QWidget *parent):QWidget(parent)
{
    int floor2=201,floor1=101;
    insol[0]=rand()%148+101;
    if(insol[0]>168)
        insol[0]+=32;
    if(insol[0]>257)
        insol[0]++;
    insol[1]=insol[0];
    while(insol[0]==insol[1]){
        insol[1]=rand()%148+101;
        if(insol[1]>168)
            insol[1]+=32;
        if(insol[1]>257)
            insol[1]++;
    }
    insol[2]=insol[1];
    while(insol[2]==insol[1]||insol[2]==insol[0]){
        insol[2]=rand()%148+101;
        if(insol[2]>168)
            insol[2]+=32;
        if(insol[2]>257)
            insol[2]++;
    }
    for(int i = 0;i<3;i++)
        qDebug(QString::number(insol[i]).toStdString().c_str());
    insol2pwd=rand()%9000+1000;
    //Initialize & Load RC1 stage
    mainwindow = dynamic_cast<Ui::MainWindow*>(_mainwindow);
    //Initialize Tiles
    for(int i = 0;i<20;i++)
        for(int j = 0;j<70;j++)
        {
            /*j is X axis coordination, i is j axis coordination */
            if(rc1_mapdata[i][j]<4){
                if(floor2==insol[0])
                    mapData[i][j]=new Room(this,this,static_cast<TileType>(rc1_mapdata[i][j]),j,i,floor2++,INSOL1,0);
                else if(floor2==insol[1])
                    mapData[i][j]=new Room(this,this,static_cast<TileType>(rc1_mapdata[i][j]),j,i,floor2++,INSOL2,insol2pwd);
                else if(floor2==insol[2])
                    mapData[i][j]=new Room(this,this,static_cast<TileType>(rc1_mapdata[i][j]),j,i,floor2++,INSOL3,0);
                else{
                    int k;
                    if(rand()%2==0)
                        k=3;
                    else if(rand()%2==0)
                        k=4;
                    else
                        k=5;
                    if(rand()%4==0)
                        mapData[i][j]=new Room(this,this,static_cast<TileType>(rc1_mapdata[i][j]),j,i,floor2++,static_cast<ROOMTYPE>(k),rand()%9000+1000);
                    else
                        mapData[i][j]=new Room(this,this,static_cast<TileType>(rc1_mapdata[i][j]),j,i,floor2++,static_cast<ROOMTYPE>(k),0);
                }
            }
            else
                mapData[i][j] = new Tile(this, this, static_cast<TileType>(rc1_mapdata[i][j]), j, i);
            if(rc2_mapdata[i][j]<4){
                if(floor1==insol[0])
                    mapData2[i][j]=new Room(this,this,static_cast<TileType>(rc2_mapdata[i][j]),j,i,floor1++,INSOL1,0);
                else if(floor1==insol[1])
                    mapData2[i][j]=new Room(this,this,static_cast<TileType>(rc2_mapdata[i][j]),j,i,floor1++,INSOL2,insol2pwd);
                else if(floor1==insol[2])
                    mapData2[i][j]=new Room(this,this,static_cast<TileType>(rc2_mapdata[i][j]),j,i,floor1++,INSOL3,0);
                else{
                    int k;
                    if(rand()%2==0)
                        k=3;
                    else if(rand()%2==0)
                        k=4;
                    else
                        k=5;
                    if(rand()%4==0)
                        mapData2[i][j]=new Room(this,this,static_cast<TileType>(rc2_mapdata[i][j]),j,i,floor1++,static_cast<ROOMTYPE>(k),rand()%9000+1000);
                    else
                        mapData2[i][j]=new Room(this,this,static_cast<TileType>(rc2_mapdata[i][j]),j,i,floor1++,static_cast<ROOMTYPE>(k),0);
                }
            }
            else
                mapData2[i][j] = new Tile(this, this, static_cast<TileType>(rc2_mapdata[i][j]), j, i);
            mapData2[i][j]->setVisible(false);
        }

    //in pixel coordination
    me = new Character(this,this,5,350,750);

    //Initial Junwi Position Needed, in pixel coordination
    junwis[0] = new SJW(this, this, 350,150,DOWN,0);
    junwis[1] = new SJW(this, this, 2950,350,DOWN,0);
    junwis[2] = new SJW(this, this, 1250,800,LEFT,1);
    junwis[3] = new SJW(this, this, 1300,300, RIGHT,1);
    junwis[4] = new SJW(this, this, 1850,300, UP,2);
    junwis[5] = new SJW(this, this, 3050,450, RIGHT,2);

    //MenuStrip Init
    menu = new Menustrip(this, 1000, 1000, RC_STAGE1);





    this->setGeometry(0,0,740,515);



    placeObject();
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveall()));
    connect(me,SIGNAL(catched()),this,SLOT(caught()));
    connect(menu,SIGNAL(gameset()),this,SLOT(caught())); //game over.
    story=0;
    friendnum=0;
    stage=2;
    npcdialog=NULL;
    message=new Message(this,0);
    connect(message,SIGNAL(end()),this,SLOT(messageend()));
    message->setFocus();
}

Character *Map::getCharacter()
{
    return me;
}

Tile *Map::getTile(int x, int y)
{
    if(y>=0 && x>=0)
        if(y<20 && x<70){
            if(stage==2)
                return mapData[y][x];
            else
                return mapData2[y][x];
        }
    return (Tile *)0;
}

//This function places map tiles, my character, saejunwis
void Map::placeObject()
{
    int my_x, my_y, screen_center_x, screen_center_y;
    me->setGeometry((740-50)/2, (515-50)/2, 50, 50);
    my_x = me->getx();
    my_y = me->gety();
    screen_center_x = ((740-50)/2);
    screen_center_y = ((515-50)/2);
    if(stage==2){
        for(int i = 0;i<20;i++)
            for(int j = 0;j<70;j++)
            {
                mapData[i][j]->move((j<<6)-(j<<4)+(j<<1) - my_x + screen_center_x
                                        ,(i<<6)-(i<<4)+(i<<1) - my_y + screen_center_y);
            }

    }
    else
        for(int i=0;i<20;i++)
            for(int j=0;j<70;j++){
                mapData2[i][j]->move((j<<6)-(j<<4)+(j<<1) - my_x + screen_center_x
                                    ,(i<<6)-(i<<4)+(i<<1) - my_y + screen_center_y);
            }
    for(int i = 0;i<6;i++)
    {
        junwis[i]->setGeometry(junwis[i]->getx() - my_x + screen_center_x,
                           junwis[i]->gety() - my_y + screen_center_y, 50, 50);
    }
}

SJW *Map::getJunwi(int index)
{
    return junwis[index];
}

void Map::changeStage()
{
    if(stage==2){
        menu->setStage(1);
        stage=1;
        for(int i=0;i<20;i++)
            for(int j=0;j<70;j++){
                mapData[i][j]->setVisible(false);
                mapData2[i][j]->setVisible(true);
            }
        me->setx(100);
        me->sety(200);
        junwis[0]->setx(300);
        junwis[0]->sety(300);
        junwis[0]->changedir(DOWN);
        junwis[1]->setx(2000);
        junwis[1]->sety(50);
        junwis[1]->changedir(LEFT);
        junwis[2]->setx(850);
        junwis[2]->sety(450);
        junwis[2]->changedir(RIGHT);
        junwis[3]->setx(2250);
        junwis[3]->sety(650);
        junwis[3]->changedir(UP);
        junwis[4]->setx(450);
        junwis[4]->sety(800);
        junwis[4]->changedir(RIGHT);
        junwis[5]->setx(1300);
        junwis[5]->sety(300);
        junwis[5]->changedir(DOWN);
    }
    else{
        stage=2;
        menu->setStage(0);
        for(int i=0;i<20;i++)
            for(int j=0;j<70;j++){
                mapData2[i][j]->setVisible(false);
                mapData[i][j]->setVisible(true);
            }
        me->setx(3350);
        me->sety(550);
        junwis[0]->sety(150);
        junwis[0]->setx(350);
        junwis[0]->changedir(DOWN);
        junwis[1]->sety(350);
        junwis[1]->setx(2950);
        junwis[1]->changedir(DOWN);
        junwis[2]->sety(800);
        junwis[2]->setx(1250);
        junwis[2]->changedir(LEFT);
        junwis[3]->sety(300);
        junwis[3]->setx(1300);
        junwis[3]->changedir(RIGHT);
        junwis[4]->sety(300);
        junwis[4]->setx(1850);
        junwis[4]->changedir(UP);
        junwis[5]->sety(450);
        junwis[5]->setx(3050);
        junwis[5]->changedir(RIGHT);
    }
    placeObject();
}

void Map::finishRC()
{
    timer->stop();
    for(int i=0;i<20;i++)
        for(int j=0;j<70;j++){
            delete mapData[i][j];
            delete mapData2[i][j];
        }
    for(int i=0;i<6;i++)
        delete junwis[i];
    delete me;
    game = new Game(3000,menu->getTime());
    game->show();
}

void Map::keyPressEvent(QKeyEvent *event)
{
        switch(event->key())
        {
        case Qt::Key_Left:
            me->changedir(LEFT);
            break;
        case Qt::Key_Right:
            me->changedir(RIGHT);
            break;
        case Qt::Key_Up:
            me->changedir(UP);
            break;
        case Qt::Key_Down:
            me->changedir(DOWN);
            break;
        case Qt::Key_Space:
        {
            Tile* tmp=me->getspacebar();
            if(tmp==NULL)
                break;
            if(tmp->gettype()==stairs)
                changeStage();
            else if(tmp->gettype()==door){
                if(story==3)
                    finishRC();
                else{
                    message=new Message(this,2);
                    message->setFocus();
                    connect(message,SIGNAL(end()),this,SLOT(messageend()));
                }
            }
            else{
                timer->stop();
                npcdialog=new Npcdialog(this,dynamic_cast<Room*>(tmp));
            }
            break;
        }
        default:
            event->ignore();
            break;
        }
}

int Map::getPasswd()
{
    return insol2pwd;
}

Menustrip *Map::getMenu()
{
    return menu;
}

int Map::getstory()
{
    return story;
}

void Map::nextstory()
{
    story++;
    qDebug(QString::number(story).toStdString().c_str());
}

void Map::moveall()
{
    for(int i=0;i<6;i++)
        junwis[i]->moveSJW();
    me->move();
    me->check();
    placeObject();
}

void Map::caught()
{
    reset();
    Room* tmp=new Room(this,this,rup,1,1,111,TRAP,0);
    npcdialog=new Npcdialog(this,tmp);
}

void Map::reset()
{
    if(stage==1)
        for(int i=0;i<20;i++)
            for(int j=0;j<70;j++){
                mapData[i][j]->setVisible(true);
                mapData2[i][j]->setVisible(false);
            }
    me->sety(750);
    me->setx(350);
    me->changedir(NONE);
    junwis[0]->sety(150);
    junwis[0]->setx(350);
    junwis[0]->changedir(DOWN);
    junwis[1]->sety(350);
    junwis[1]->setx(2950);
    junwis[1]->changedir(DOWN);
    junwis[2]->sety(800);
    junwis[2]->setx(1250);
    junwis[2]->changedir(LEFT);
    junwis[3]->sety(300);
    junwis[3]->setx(1300);
    junwis[3]->changedir(RIGHT);
    junwis[4]->sety(300);
    junwis[4]->setx(1850);
    junwis[4]->changedir(UP);
    junwis[5]->sety(450);
    junwis[5]->setx(3050);
    junwis[5]->changedir(RIGHT);
    stage=2;
    menu->setStage(0);
}

void Map::resume()
{    
    bool tmp=npcdialog->isTrap();
    delete npcdialog;
    npcdialog=NULL;
    placeObject();
    if(tmp)
        callmessage2();
    else{
        timer->start(20);
        this->setFocus();
    }
}

void Map::messageend()
{
    delete message;
    timer->start(20);
    this->setFocus();
}

void Map::gameover()
{

}

void Map::callmessage2()
{
    message=new Message(this,1);
    connect(message,SIGNAL(end()),this,SLOT(messageend()));\
    message->setFocus();
    menu->setTime(menu->getTime()-60);
}

Ui::MainWindow *Map::getWindow()
{
    return mainwindow;
}

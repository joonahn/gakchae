#include "map.h"

int rc1_mapdata[20][70] = {
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 4, 0, 0, 0, 3, 4, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 5, 4, 4, 4, 4, 4, 1, 1, 1, 3, 4, 5, 1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 4, 2, 0, 0, 0, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 0, 3, 4, 4, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 6, 4, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 1, 1, 1, 1, 1, 1, 3, 4, 2, 7, 7, 7, 3, 4, 5, 6, 5, 6, 5, 6, 5, 6, 5, 4, 2, 7, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 5, 4, 7, 7, 7, 0, 0, 3, 4, 2, 0, 7, 4, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 7, 7, 7, 3, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 2, 7, 3, 4, 2, 4, 0, 0, 0, 4, 7, 7, 7, 4, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 6, 4, 7, 7, 7, 7, 7, 3, 4, 2, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 4, 0, 0, 0, 0, 4, 2, 7, 7, 7, 3, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 2, 1, 4, 4, 2, 4, 7, 7, 7, 4, 7, 7, 7, 4, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 5, 4, 7, 7, 7, 7, 7, 3, 4, 2, 7, 4, 4, 4, 4, 4, 5, 0, 0, 0, 0, 0, 0, 0, 7, 7, 4, 7, 7, 7, 3, 4, 2, 7, 7, 7, 3, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 4, 4, 4, 0, 7, 4, 7, 7, 7, 4, 7, 7, 7, 4, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 6, 4, 7, 7, 7, 7, 7, 3, 4, 2, 7, 4, 4, 4, 5, 4, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 3, 4, 2, 7, 7, 7, 3, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 0, 0, 0, 7, 7, 4, 1, 1, 1, 4, 7, 7, 7, 4, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 5, 4, 7, 7, 7, 7, 7, 3, 4, 2, 7, 4, 4, 4, 4, 4, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 3, 4, 4, 4, 4, 4, 4, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 7, 7, 7, 4, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 6, 4, 7, 7, 7, 7, 7, 3, 4, 5, 4, 4, 4, 4, 4, 4, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 3, 4, 2, 7, 7, 7, 3, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 1, 1, 1, 1, 1, 4, 7, 7, 4, 7, 7, 7, 7, 4, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 5, 4, 7, 7, 7, 7, 7, 3, 4, 4, 4, 4, 5, 6, 4, 4, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 3, 4, 2, 7, 7, 7, 3, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 4, 7, 7, 7, 7, 4, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 6, 4, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 6, 5, 4, 4, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 3, 4, 2, 7, 7, 7, 3, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 0, 0, 0, 0, 0, 4, 4, 4, 4, 7, 7, 7, 7, 8, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 5, 4, 7, 7, 7, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 3, 4, 2, 7, 7, 7, 3, 4, 2, 7, 7, 7, 7, 7, 7, 7, 3, 4, 7, 7, 7, 7, 3, 4, 5, 5, 4, 7, 7, 7, 7, 7, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 6, 4, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 3, 4, 2, 7, 7, 7, 3, 4, 5, 6, 5, 6, 5, 6, 5, 6, 5, 4, 7, 7, 7, 7, 3, 4, 7, 7, 4, 7, 7, 7, 7, 7, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 5, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 4, 2, 1, 1, 1, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 3, 4, 6, 6, 4, 7, 7, 7, 7, 7, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 1, 1, 1, 1, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 3, 4, 4, 4, 4, 4, 4, 4, 2, 0, 7, 7, 7, 7, 7, 7, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, },
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, }
};

int rc2_mapdata[20][70]={
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 },
    { 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 1, 1, 1, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 },
    { 7, 7, 7, 7, 7, 7, 4, 7, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6, 6, 0, 0, 0, 7, 7, 7, 4, 7, 7, 5, 5, 0, 0, 0, 7, 7, 4, 7, 7, 5, 5, 7, 4, 4, 4, 4, 4, 4, 7, 7, 7 },
    { 7, 7, 9, 7, 7, 7, 4, 7, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 4, 7, 7, 7, 0, 0, 0, 7, 6, 6, 4, 6, 6, 6, 7, 7, 7, 7, 7, 4, 7, 7, 5, 5, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 4, 7, 7, 7 },
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
    { 7, 7, 7, 7, 4, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 7, 4, 7, 1, 1, 1, 7, 6, 6, 7, 7, 1, 1, 1, 7, 7, 4, 7, 7, 7, 7, 7, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 7, 7, 7, 8, 7, 7, 7 },
    { 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 1, 1, 1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 7, 7 },
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7 },
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 },
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 }

};

Map::Map(QMainWindow *_mainwindow,QWidget *parent):QWidget(parent)
{
    //Initialize & Load RC1 stage
    mainwindow = dynamic_cast<Ui::MainWindow*>(_mainwindow);

    //Initialize Tiles
    for(int i = 0;i<20;i++)
        for(int j = 0;j<70;j++)
        {
            /*j is X axis coordination, i is j axis coordination */
            mapData[i][j] = new Tile(this,this, static_cast<TileType>(rc1_mapdata[i][j]), j, i);
            mapData2[i][j] = new Tile(this, this, static_cast<TileType>(rc2_mapdata[i][j]), j, i);
            mapData2[i][j]->setVisible(false);
        }



    //in pixel coordination
    me = new Character(this,this,5,350,750);

    //Initial Junwi Position Needed, in pixel coordination
    junwis[0] = new SJW(this, this, 350,150,DOWN);
    junwis[1] = new SJW(this, this, 2950,350,DOWN);
    junwis[2] = new SJW(this, this, 1250,800,LEFT);
    junwis[3] = new SJW(this, this, 1300,300, RIGHT);
    junwis[4] = new SJW(this, this, 1850,300, UP);
    junwis[5] = new SJW(this, this, 3050,200, RIGHT);

    //MenuStrip Init
    menu = new Menustrip(this, 1000, 1000);

    placeObject();
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveall()));
    timer->start(20);
    connect(me,SIGNAL(catched()),this,SLOT(reset()));
}

Character *Map::getCharacter()
{
    return me;
}

Tile *Map::getTile(int x, int y)
{
    if(y>=0 && x>=0)
        if(y<20 && x<70)
            return mapData[y][x];
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
    for(int i = 0;i<20;i++)
        for(int j = 0;j<70;j++)
        {
                mapData[i][j]->move((j<<6)-(j<<4)+(j<<1) - my_x + screen_center_x
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

void Map::keyboardInput(QKeyEvent *event)
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
    default:
        event->ignore();
        break;
    }

}

void Map::moveall()
{
    for(int i=0;i<6;i++)
        junwis[i]->moveSJW();
    me->move();
    me->check();
    placeObject();
}

void Map::reset()
{
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
    junwis[5]->sety(200);
    junwis[5]->setx(3050);
    junwis[5]->changedir(RIGHT);
}

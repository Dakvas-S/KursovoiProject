#include "funkts.h"
void author(authorization A) {
    while (A.CK) {
        A.couttextA(1);
        switch (A.vibauth()) {
        case 1: { A.getin();break; }
        case 2: { A.sinin();break; }
        default: { A.couttextA(4);break; }
        }
        A.sisans();
        A.ohist();
    };
       
}

void menuus(authorization A) {
    switch (A.m) {
    case 0:{}
    case 1: {}
    }
}
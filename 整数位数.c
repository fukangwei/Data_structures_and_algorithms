#include "math.h"

int digit_num ( int num ) {
    int i = 1;

    for ( ;; ) {
        if ( num / ( int ) pow ( 10, i ) == 0 ) {
            return i;
        }

        i++;
    }
}
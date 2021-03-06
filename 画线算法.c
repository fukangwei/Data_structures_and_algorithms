#define uint  unsigned int
#define uchar unsigned char

void GUI_Line ( uint x1, uint y1, uint x2, uint y2, uint color ) {
    uint t;
    int xerr = 0, yerr = 0, delta_x, delta_y, distance;
    int incx, incy;
    uint row, col;
    delta_x = x2 - x1;
    delta_y = y2 - y1;
    col = x1;
    row = y1;

    if ( delta_x > 0 ) {
        incx = 1;
    } else {
        if ( delta_x == 0 ) {
            incx = 0;
        } else {
            incx = -1;
            delta_x = -delta_x;
        }
    }

    if ( delta_y > 0 ) {
        incy = 1;
    } else {
        if ( delta_y == 0 ) {
            incy = 0;
        } else {
            incy = -1;
            delta_y = -delta_y;
        }
    }

    if ( delta_x > delta_y ) {
        distance = delta_x;
    } else {
        distance = delta_y;
    }

    for ( t = 0; t <= distance + 1; t++ ) {
        GUI_Point ( col, row, color ); /* 画点 */
        xerr += delta_x;
        yerr += delta_y;

        if ( xerr > distance ) {
            xerr -= distance;
            col += incx;
        }

        if ( yerr > distance ) {
            yerr -= distance;
            row += incy;
        }
    }
}
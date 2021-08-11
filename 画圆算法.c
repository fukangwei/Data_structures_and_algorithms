#define uint  unsigned int
#define uchar unsigned char

void plotC ( uchar x, uchar y, uchar xc, int yc, uint yc_colour ) {
    GUI_Point ( xc + x, yc + y, yc_colour );
    GUI_Point ( xc + x, yc - y, yc_colour );
    GUI_Point ( xc - x, yc + y, yc_colour );
    GUI_Point ( xc - x, yc - y, yc_colour );
    GUI_Point ( xc + y, yc + x, yc_colour );
    GUI_Point ( xc + y, yc - x, yc_colour );
    GUI_Point ( xc - y, yc + x, yc_colour );
    GUI_Point ( xc - y, yc - x, yc_colour );
}

void GUI_Circle ( uchar xc, uchar yc, uchar r, uint circle_colour ) {
    int x, y, d;
    y = r;
    d = 3 - ( r + r );
    x = 0;

    while ( x <= y ) {
        plotC ( x, y, xc, yc, circle_colour );

        if ( d < 0 ) {
            d += ( x + x + x + x ) + 6;
        } else {
            d += ( ( x - y ) + ( x - y ) + ( x - y ) + ( x - y ) ) + 10;
            y = y - 1;
        }

        x = x + 1;
    }
}
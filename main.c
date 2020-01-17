#include "con_lib.h"
#include <stdlib.h>
#include <time.h>
// MAP
// x right left, y up down
// width height w,h
//MUST DO : ANTRASTE
//return void'ai, ++ QUESTIONS
void draw_box(int x, int y, int w, int h)
{
    for (int i = 0; i < w; i++)
    {
        con_set_pos(x + i, y);
        printf("_");

        for(int k=1; k<19; k++)
        {
            con_set_pos(x + i, y+k);
            printf(".");
            //BOOLEAN ARRAY
            //ENUM
        }
        con_set_pos(x + i, y + h - 1);
        printf("_");
    }
    for (int i = 1; i < h; i++)
    {
        con_set_pos(x, y + i);
        printf("|");

        con_set_pos(x + w - 1, y + i);
        printf("|");
    }
    return 0;
}
void rnd(dir1_x)
{
    dir1_x = rand() %  0+ -1;
}
void movement(int old_x, int old_y,int old1_x,int old1_y,int pos1_x,int pos_x,int pos1_y, int pos_y, int dir1_x, int dir_x, int dir1_y, int dir_y)
{
    while (1)
    {
        //GHOST MOVEMENT
        if(pos1_x==37)
        {
            dir1_x = -1;
            dir1_y = rand()%1+ -1;
        }
        if(pos1_x==0)
        {
            dir1_x = 1;
            dir1_y = 1;
        }


        int key = 0;



        // Nuskaitomi mygtukai
        while (key = con_read_key())
        {
            switch(key)
            {
            case 'w' :
                dir_x= 0;
                dir_y = -1;
                break;
            case 's' :
                dir_x = 0;
                dir_y = 1;
                break;
            case 'a' :
                dir_x = -1;
                dir_y = 0;
                break;
            case 'd' :
                dir_x = 1;
                dir_y = 0;
                break;
            case 'q' :
                return 0;
                break;
            default :
                dir_x= 0;
                dir_y = 0;
            }
            //switch!!! - DONE
        }
        // Atnaujinama X pozicija <- ->; uzfiksuotos zemelapio sienos
        pos_x += dir_x;
        if (pos_x < 1)
            pos_x = 1;
        else if (pos_x > 38) //REIKSMES
            pos_x = 38;

        // Atnaujinama Y pozicija ^; uzfiksuotos zemelapio sienos
        pos_y += dir_y;
        if (pos_y < 1)
            pos_y = 1;
        else if (pos_y > 18)
            pos_y = 18;



        // Atnaujinama X pozicija <- ->; uzfiksuotos zemelapio sienos
        pos1_x += dir1_x;
        if (pos1_x < 1)
            pos1_x = 0;
        else if (pos1_x > 38)
            pos1_x = 38;

        // Atnaujinama Y pozicija ^; uzfiksuotos zemelapio sienos
        pos1_y += dir1_y;
        if (pos1_y < 1)
            pos1_y = 0;
        else if (pos1_y > 17)
            pos1_y = 17;





        // Sena zaidejo pozicija istrinama
        con_set_color(COLOR_BLACK, COLOR_GRAY);
        con_set_pos(old_x, old_y);
        printf(" ");
        // NAUJA, UZPILDYTA ZAIDEJO POZICIJA

        con_set_color(COLOR_ORANGE, COLOR_ORANGE);
        con_set_pos(pos_x, pos_y);

        printf("#");
        fflush(stdout);
        // Sena GHOST pozicija  istrinama
        con_set_color2(COLOR_BLACK, COLOR_GRAY);
        con_set_pos2(old1_x, old1_y);
        printf(".");
        fflush(stdout);
        // NAUJA GHOST pozicija uzpildoma
        con_set_color2(COLOR_RED, COLOR_RED);
        con_set_pos2(pos1_x, pos1_y);
        printf("#");
        fflush(stdout);
        //senos koordinates
        old_x = pos_x;
        old_y = pos_y;

        //senos koordinates
        old1_x = pos1_x;
        old1_y = pos1_y;
        // delay 0.08 sek
        con_sleep(0.08);

        //jeigu susiliecia GHOST ir CHAR
        if((pos1_x+1 == pos_x  && pos1_y+1 == pos_y ))
        {

            return 0;
        }

    }
}
int main()
{

    srand ( time(NULL) );
    // Paslepia ivedamus simbolius
    con_show_echo(0);
    // Paslepia cursoriu
    con_show_cursor(0);

    // Sena pozicija
    int old_x = 10, old_y = 10;
    //Sena GHOST pozicija
    int old1_x = 0, old1_y = 0;
    // Judejimo kryptis
    int dir_x = 1, dir_y = 0;

    //GHOST direction
    int dir1_x = 1, dir1_y = 0;

    // Dabartine pozicija
    int pos_x = 10, pos_y = 10;
    //Random pasirinkta GHOST pozicija
    int pos1_x = rand() % 38 + 1, pos1_y = rand() % 18 + 1;

    // Dezes piesimas
    con_clear();
    draw_box(0, 0, 40, 20);
    movement( old_x,  old_y, old1_x, old1_y, pos1_x, pos_x, pos1_y,  pos_y,  dir1_x,  dir_x, dir1_y,  dir_y);


}



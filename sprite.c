void    drawsprites()
{
    int dx;
    int dy;
    int i;
 
    i = 0;
    while (i < sprcount)
    {
        dx = g_spr[i].x - g_player.x;
        dy = g_spr[i].y - g_player.y;
        g_player.dir = g_ray[g_file.win_x / 2].dir;
        g_spr[i].angle = atan2(dy, dx);
        while (g_spr[i].angle - g_player.dir > M_PI)
            g_spr[i].angle -= 2 * M_PI;
        while (g_spr[i].angle - g_player.dir < -M_PI)
            g_spr[i].angle += 2 * M_PI;
        g_spr[i].size = (g_file.win_x / g_spr[i].dis) * 64;
        g_spr[i].xp = (g_spr[i].angle - g_player.dir) * g_file.win_x / (M_PI / 3) + (g_file.win_x / 2 - g_spr[i].size / 2);
        drawsingsp(i);
        i++;
    }
}
 
 
void    drawsingsp(int k)
{
    float i;
    float   j;
    int col;
    float stp;
    int m;
    int l;
 
    i = 0;
    m = 0;
    l = 0;
    j = 0;
    stp = 64.0 / g_spr[k].size;
    while (l < g_spr[k].size)
    {
        while (m < g_spr[k].size)
        {
            if (!((col = get_txt_color(0, j, i)) == 0) && distwall_sprite(m + g_spr[k].xp, k))
                addpxl(m + g_spr[k].xp, l + g_file.win_y / 2 - g_spr[k].size / 2, col);
            j += stp;
            m++;
        }
        j = 0;
        m = 0;
        i += stp;
        l++;
    }
}
 
 
 
typedef struct  s_sprite
{
    int xm;
    int ym;
    float x;
    float y;
    float dis;
    float angle;
    float size;
    float xp;
    float yp;
    //int v;
}               t_sprite;
 
 

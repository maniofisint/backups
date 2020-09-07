#include <iostream>
#include <conio.h>

using namespace std;
#define clear() printf("\033[H\033[J")
class snake
{
private:
    int width;
    int height;

public:
    snake();
};

snake :: snake ()
{
    

}
char map[20][40] = {
        "# # # # # # # # # # #",
        "#                   #",
        "#                   #",
        "#                   #",
        "#                   #",
        "#                   #",
        "#                   #",
        "#                   #",
        "#                   #",
        "# # # # # # # # # # #"
        };

void print()
{
    for ( int i = 0 ; i < 10 ; i++ ){
        for ( int j = 0 ; j<21 ; j++ )
            cout << map[i][j];
        cout << endl ;
    }
}
struct pos 
{
    int x , y;
};

void add (pos man)
{
    map[man.x][man.y] = '@';
}
void remove (pos man)
{
    map[man.x][man.y] = ' ';
}
int main()
{
    pos man = { 1 , 1};
    add (man);

    char in;
    in = getchar();
    cout << in << endl;
    while ( in != 'e')
    {
        remove(man);

        in = getchar();

        if ( in == 'e' )
            exit(0);
        else if ( in == 'w' )
            man.x--;
        else if ( in == 's' )
            man.x++;
        else if ( in == 'a' )
            man.y--;
        else if ( in == 'd' )
            man.y++;

        add(man);
        clear();
        print();
    }
    

}


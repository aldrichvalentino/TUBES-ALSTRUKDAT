#include "gambar.h"
#include "color.h"
#include <stdio.h>

 
void PrintCoolBS ()
{
	printf("%s\n",COLOR_WHITE"                      ;");
    printf("%s\n","                      @");
    printf("%s\n","                      @.");
    printf("%s\n","                      @,");
    printf("%s\n","                      @'");
    printf("%s\n","                      @#");
    printf("%s\n","                      @@");
    printf("%s\n","                      @@");
    printf("%s\n","                      @@");
    printf("%s\n","                      @@");
    printf("%s",COLOR_LRED"     @@@@@@@@`        ");
    printf("%s\n",COLOR_WHITE"@@ ");
    printf("%s",COLOR_LRED"    @@@@@#@@@         ");
    printf("%s",COLOR_WHITE"@@");
    printf("%s\n",COLOR_LRED"    `                                                 @@@@@");
    printf("%s","   @,,@@  @@          ");
    printf("%s",COLOR_WHITE"@@");
    printf("%s\n",COLOR_LRED"     @            .;       ;                    +`     @@`:@`");
    printf("%s","     ,@@ @@'  ##@@@@  ");
    printf("%s",COLOR_WHITE"@@");
    printf("%s\n",COLOR_LRED"  `#@@#  @@@ @@@ @@##@;  @@@@   #@@@   ,@'  @@ @@@     @@#  `");
    printf("%s","     `@@@@@   +@# @@+ ");
    printf("%s",COLOR_WHITE"@@");
    printf("%s\n",COLOR_LRED" #@@@@@  :@+ ;@#@@@@@@@,#@  @   @@@@'  #@   @:  @@     @@@@.");
    printf("%s","     `@@@@@@  #@# @@  ");
    printf("%s",COLOR_WHITE"@@");
    printf("%s\n",COLOR_LRED" @@@     .@   @`#,@@+   +@@;   @@` @@  @@   @@  @#      @@@@@");
    printf("%s","     ,@@##@@@ @@'@@   ");
    printf("%s",COLOR_WHITE"@@");
    printf("%s\n",COLOR_LRED"`@@  +#` :@@@@@`  @@     @@@@ `@#  #@+ @@   @@  @;     ; @@@@:");
    printf("%s","     #@@   @@ @@@@@+  ");
    printf("%s",COLOR_WHITE"@@");
    printf("%s\n",COLOR_LRED" @@   @@ #@@ ;@,  @@    ` #@@@@@,  ,@@ @@. :@@  @;  @ @@  +@@#");
    printf("%s","     @@@  ;@@ @@@@@@  ");
    printf("%s",COLOR_WHITE"@@");
    printf("%s\n",COLOR_LRED" @@@  `@;@@# @@#  @@   .@+ .@@'@@@@@@; #@@+@@' `@++@@+@@@++@@.");
    printf("%s","     @@@@@@@: @@@ @@  ");
    printf("%s",COLOR_WHITE":@");
    printf("%s\n",COLOR_LRED"  @@@@@@ @@@ @@@  @@   @@@@@@+ +@@@@;   @@@@#  @@@@@@# ;@@@@#");
    printf("%s","    +@@@@@@+       @@ ");
    printf("%s",COLOR_WHITE"#@");
    printf("%s\n",COLOR_LRED"   `,  @                  ##                             .`");
    printf("%s\n",COLOR_WHITE"                    ,@@@");
    printf("%s\n",COLOR_WHITE"                     `@@`");
    printf("%s\n",COLOR_WHITE"                      +@");
    printf("%s",COLOR_CYAN"  @@@@      @@@@      ");
    printf("%s",COLOR_WHITE"@@@");
    printf("%s\n",COLOR_CYAN"     @@@      @@@@      #@@@      +@@@;     ;@@@@     ,@@@@");
    printf("%s"," @@@@`   '@@@@@'  ");
    printf("%s",COLOR_BROWN".;;,;;;;;'");
    printf("%s\n",COLOR_CYAN" @@@    #@@@@@;   ,@@@@@@   `@@@@@@    @@@@@@    @@@@@@    @@");
    printf("%s"," @@     @@@@@         ");
    printf("%s",COLOR_BROWN"@:");
    printf("%s\n",COLOR_CYAN"   , @     @@@@@     @@@@@  `  +@@@@     ;@@@@,     @@@@@     @@@");
    printf("%s"," @@    @@@@@@         ");
    printf("%s",COLOR_BROWN"+:");
    printf("%s\n",COLOR_CYAN"     @   `@@@@@@    @@@@@@    @@@@@@    @@@@@@:   ;@@@@@@   `@@@@");
    printf("%s"," @@@#@@@@@@@@@#@      ");
    printf("%s",COLOR_BROWN"@;");
    printf("%s\n",COLOR_CYAN"     @@#@@@@@@@@@#@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@");
    printf("%s"," @@@@@@@@@@@@@@@      ");
    printf("%s",COLOR_BROWN"'+");
    printf("%s\n",COLOR_CYAN"     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    printf("%s\n",COLOR_BROWN"                      @+");
    printf("%s\n","                      ;;");
    printf("%s\n","                     ;@+;");
    printf("%s\n","                     .@:+");
    printf("%s\n","                     `::"COLOR_RESET);
}

void PrintWin()
{
	printf("%s\n","\033[01;31m  *****      ****    ****      **    *****     *******      *****    **********   *******");
	printf("%s\n","\033[01;32m**         **    **  ** **     **  **          **    **    **   **       **      **");    
	printf("%s\n","\033[01;33m**         **    **  **  **    **  **          **    **   **     **      **      **");
	printf("%s\n","\033[01;34m**         **    **  **   **   **  **    ****  *******    *********      **       *******");
	printf("%s\n","\033[01;35m**         **    **  **    **  **  **     **   **    **   **     **      **             **");
	printf("%s\n","\033[01;36m**         **    **  **     ** **  **     **   **     **  **     **      **             **");
	printf("%s\n","\033[01;37m  *****      ****    **      ****    *****     **     **  **     **      **       *******");
	printf("\n");
	printf("%s\n","\033[01;31m     **    **    ****    **    **        **              **	**	****	  **");
	printf("%s\n","\033[01;32m      **  **   **    **  **    **        **              **	**	** **	  **");
	printf("%s\n","\033[01;33m       ****    **    **  **    **        **              **	**	**  **	  **");
	printf("%s\n","\033[01;34m        **     **    **  **    **        **      **      **	**	**   **   **");
	printf("%s\n","\033[01;35m        **     **    **  **    **         **     **     **	**	**    **  **");
	printf("%s\n","\033[01;36m        **     **    **  **    **          **    **    **	**	**     ** **");
	printf("%s\n","\033[01;37m        **       ****      ****              ****  ****		**	**      ****");
	printf("\033[30;0m %c");
}

void PrintLose()
{
	printf("%s\n","\033[22;31m**    **     ****    **    **        **          ****     *******    *******");
	printf("%s\n","\033[01;31m **  **    **    **  **    **        **        **    **  **          **");
	printf("%s\n","\033[22;31m  ****     **    **  **    **        **        **    **  **          **");
	printf("%s\n","\033[01;31m   **      **    **  **    **        **        **    **   *******    *****");
	printf("%s\n","\033[22;31m   **      **    **  **    **        **        **    **         **   **");	
	printf("%s\n","\033[01;31m   **      **    **  **    **        **        **    **         **   **");
	printf("%s\n","\033[22;31m   **        ****      ****          ********    ****     *******    *******");
	printf("\033[30;0m %c");
}


# 42-so-long

[x] Map components
[x] Validate map extension .ber
[x] Validate map walls
[x] Validate retangular map
[x] Validate map elements
[x] You don’t need to check if there’s a valid path in the map.
[x] Validate Map at least one exit, one collectible, one starting position.
[x] Init window with right size
[x] Print sprites on screen
[x] Close window when click on "X"
[x] Close window when hit ESC
[] Validate SIGSERV on game exit (quit the program cleanly.)
[] Check if all local functions are static
[] Validate norminette
[] Add header42

Move
[x] Move character (WASD)
[x] The player must be able to move up,down,left,right
[x] Player cannot move into walls
[x] Count coins
[x] Show steps on terminal
[x] Collect coins
[x] At every move the current number of movements must be displayed in the shell.
[x] Allow exit into sprite E only if collected all C
[x] Validate invalid_map_wall map

## Allowed functions

• open, close, read, write,
printf, malloc, free, perror,
strerror, exit

• All functions of the MinilibX

## Material

[minilibx](https://harm-smits.github.io/42docs/libs/minilibx)

[minilib linux](https://github.com/42Paris/minilibx-linux)

[notion](https://bumpy-truffle-c97.notion.site/SoLong-13550c956d2f4d288b6a73a97ee7bccb)

`LINUX_FLAGS = -L $(LIBS)minilibx-linux -lmlx -lm -lX11 -lXext`

`set -x DISPLAY (grep nameserver /etc/resolv.conf | sed 's/nameserver //')":0"`

Simple commando without make file

`gcc -Wall -Wextra -Werror -I mlx -L mlx -lmlx -lXext -lX11 -lm -lz ./src/main.c ./mlx/libmlx.a && ./a.out`

If you use fish instead of bash:

```sh
echo "set -x DISPLAY localhost:0.0" >> ~/.config/fish/config.fish
To have the configuration changes take effect, restart fish, or run:
. ~/.config/fish/config.fish
```

Nao há necessidade de adequar a minilibx à norma. Apenas o código que você desenvolveu.

# 42-so-long

- [] Validate with norm
- [] All heap allocated memory space must be properly freed when necessary. No leaks
will be tolerated
- [] The map will be constructed with 3 components walls, collectibles, and free space.


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
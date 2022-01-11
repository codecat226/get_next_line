#short shell script to automate compilation. BUFFER_SIZE can be changed.
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c && ./a.out
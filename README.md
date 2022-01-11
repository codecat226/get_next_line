# get_next_line

get_next_line is a function which returns a line read from a fd (file descriptor).
When the function is called in a loop, the text available on the fd is returned one line at a time until EOF.

## 42

This is a project which is part of the 42 curriculum. For the full subject pdf click [here](./en-subject.pdf).

### Getting started

* Clone this repo and cd into it
* Modify test.txt if changing output text is desired
* If test.txt modified, modify the len in main.c to match the number of lines in test.txt 

### Executing program

* BUFFER_SIZE can be modified to change the buffer size of the read calls in the function. 

To run the program:
* To compile and run manually:

```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c && ./a.out
```

* To compile and run using run.sh:
```
bash run.sh
```

## Acknowledgments

42 curriculum for providing the project

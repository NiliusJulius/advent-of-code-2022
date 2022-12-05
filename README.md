# advent-of-code-2022
Advent of Code 2022 written for use on a Game Boy

Use [GBDK 2020 4.1.1](https://github.com/gbdk-2020/gbdk-2020/releases/tag/4.1.1 "GBDK 2020 4.1.1")

Update make.bat and run it to build the rom.

## regex
In order to use input files, they will have to be converted (mostly to arrays).
The following regexes can be used to convert your input (using Notepad++).

### Day 1
| Search | Replace |
|--------|---------|
| ^$     | 0       |
| $      | ,       |
| \z     | \n0     |

### Day 2
First, split the left and right column into two files.

Left column:
| Search | Replace |
|--------|---------|
| [ \t]  |         |
| ^(.)$  | '$0',   |

Right column:
| Search | Replace |
|--------|---------|
| [ \t]  |         |
| ^(.)$  | '$0',   |
| X      | A       |
| Y      | B       |
| Z      | C       |

### Day 3
| Search | Replace |
|--------|---------|
| ^(.*)$ | "$0",   |

### Day 4
| Search   | Replace |
|----------|---------|
| ,        | ,\n     |
| -        | ,\n     |
| ([0-9])$ | $0,     |

### Day 5
Manually make 9 stacks padded with zeros to support all possible crates in one stack. Then put them in one big array.

On all the move commands apply the following:
| Search   | Replace |
|----------|---------|
| move\s   |         |
| \sfrom\s | ,\n     |
| \sto\s   | ,\n     |
| ([0-9])$ | $0,     |

## License
[License](../main/LICENSE)
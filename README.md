# amazed
Moving robots through the maze, while getting as many robots through as possible at the same time and in as little time as possible.

How to build:
make

How to use:
cat [name of the file] | ./amazed

The file should contain:
- The number of robots at the entrance to the labyrinth
- All rooms and their positions
- Tunnels linking each room

For example:
cat labyrinth | ./amazed

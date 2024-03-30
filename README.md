# Pipex
## Description:
The goal of this project was to imitate the behavior of the pipe operator from the terminal. In its current state it is piping an infile to an outfile with two commands with its flags.

## Usage:
**MacOs and Linux**
- `git clone https://github.com/FjjDessoyCaraballo/Pipex`
- Make the files
- Use the ```./pipex infile cmd1 cmd2 outfile```
- Profit $$$

## Current issues:
- Due to time limitations and grey area around what was asked for the project, there are a few issues that I am aware of:
  1. it is only taking two commands, while the pipe operator takes as many as it can. This was a design choice given to me by the subject of the school.
  2. self-made binaries need to be executed in a different way: ```./pipex infile ./my_binary1 ./my_binary2 outfile``` when it would just be executed normally if it is in the same directory.
  3. even though the pipe is proceeding correctly in not taking null commands into/out of the pipe, the command ```wc -l``` and its other flags are still readable in terminal, but the file is empty.
  4. the command ```grep``` is currently not handling more than a single literal string.

## Result:
- Status: <span style="color:green">Completed</span>
- Result: <span style="color:green">100%</span>

## Contact: 
- 42-email: fdessoy-@student.hive.fi
- 42-profile: [https://profile.intra.42.fr/users/fdessoy-](https://profile.intra.42.fr/users/fdessoy-)

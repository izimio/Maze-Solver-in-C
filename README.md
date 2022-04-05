# Dante

## EPITECH algorithm project 

 
The project consist of two programs :
  # Algo used : **Sidewinder**
  -  The first is generating mazes with 3 options {x, y, [perfect / inperfect]}
  # Algo used : **A***
  -  The second is solving that maze, drawing the path with 'o'

*Made with my lovely mate Plaban*

# How to use it ?

first at the root of the repository make the binaries by writting ```make``` in the prompt.

Then go to the generator folder and launch the program like so :

```./generator {x_size} {y_size} {perfect} ``` *(by default the generator creates inperfect mazes)*

Now you have a fantastic maze, to put it inside a folderm relauch the command and redirect the prints inside a file like so for example :
 
  ```./generator 20 20 > file ```
 
## Now that you have a fantastic maze inside a file time to solve it !

Just like we did for the generator, now go to the solver folder and launch the binarie like so :

```./solver {file_name} ``` *(**{file_name}** is of course the name of the file where you did put the maze)*

And now you have a fantastic solved maze printed on the standard output.

## Quick tips !

You can beautify it by piping a grep command to the solver, like so if you are using zsh or starship the path will be colored !

```./solver {file_name} | grep "o" ```

You can also use a very basic python script I wrote to print the maze very colorfuly.

To do so, you first need just like we did for the generator to redirect the solved maze on a file.

```./solver {file_name} > solved_file```

And then 

``` python3 color.py solved_file```

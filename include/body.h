#ifndef BODY_H
# define BODY_H

# include <stdio.h>
# include <stdlib.h>

/**
** @fn char **update(char **table, int width, int height);
** @brief Update function for the game of life : logical treatment.
** @param table Matrix which represent the current state of the game of life.
** @param width Width of the table.
** @param height Height of the table.
** @return Returns the matrix containg the state n+1 (next step after the one which is in table).
*/
char **update(char **table, int width, int height);

/**
** @fn void draw(char **table, int width, int height);
** @brief Draw function for the game of life : graphical treatment (display).
** @param table Matrix which represent the current state of the game of life (matrix to be drawn).
** @param width Width of the table.
** @param height Height of the table.
*/
void draw(char **table, int width, int height);


#endif /* !BODY_H */

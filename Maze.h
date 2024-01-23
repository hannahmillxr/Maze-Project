/* CSCI 200: Assignment 5: A5 - a - MAZE-ing
 *
 * Author: Hannah Miller
 * Resources used: Stack and Queue documentation
 * Hannah helped me a ton in office ours to debug my code
 */

#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


struct Position{
    /**
    * @brief A parameterized constructor that sets each data member accordingly 
    * @param r horizontal position in the maze
    * @param c vertical position in the maze
    */
    Position(int r, int c)
    {
        x = r;
        y= c;
    }

    /**
    * @brief Horizontal position in the maze, or outside list in the 2D array 
    */
    int x;

    /**
    * @brief Vertical position in the maze, or inside list in the 2D array 
    */
    int y;

};

/**
 * @brief Opens input files
 * @param in reading in from input stream in
 * @param fileName is the file to read from
 * @return bool, true if file opens correctly, otherwise false
*/
bool open_file(std:: ifstream& in, std:: string fileName);

/**
 * @brief Locates the start location in the Maze, updates the start column and row location
 * @param startR integer index of outside array
 * @param startC integer index in inside array
 * @param row integer value representing the height of the maze
 * @param col integer value representing the width of the maze
 * @param Maze The 2 demensional array of character values corresponding to the maze
*/
void find_start(int& startR, int& startC, const int row, const int col, char **Maze);

/**
 * @brief solve the maze using the bredth first search algorithm
 * @param startR integer index of outside array
 * @param startC integer index in inside array
 * @param row integer value representing the height of the maze
 * @param col integer value representing the width of the maze
 * @param Maze The 2 demensional array of character values corresponding to the maze
*/
bool solve_BFS_maze(const int startR, const int startC, const int row, const int col, char** Maze);


/**
 * @brief solve the maze using the depth first search mechanism
 * @param startR integer index of outside array
 * @param startC integer index in inside array
 * @param row integer value representing the height of the maze
 * @param col integer value representing the width of the maze
 * @param Maze The 2 demensional array of character values corresponding to the maze
*/
bool solve_DFS_maze(const int startR, const int startC, const int row, const int col, char** Maze);

/**
 * @brief Read in each character from the input file and assign it to a 2D array 
 * @param in reading in from input stream in
 * @param row integer value representing the height of the maze
 * @param col integer value representing the width of the maze
 * @return char** pointer to an element in a 2D array
*/
char** read_maze_from_file(std::ifstream& in, int row, int col );

/**
 * @brief loop through the 2D array, Maze, and print out each character value
 * @param row integer value representing the height of the maze
 * @param col integer value representing the width of the maze
 * @param Maze The 2 demensional array of character values corresponding to the maze
*/
void print_maze(int row, int col, char** Maze);

#endif
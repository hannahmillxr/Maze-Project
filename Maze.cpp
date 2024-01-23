/* CSCI 200: Assignment 5: A5 - a - MAZE-ing
 *
 * Author: Hannah Miller
 * Resources used: Stack and Queue documentation
 * Hannah helped me a ton in office ours to debug my code
 */

#include "Maze.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool open_file(ifstream& in, string fileName) //Open the input file stream for the corresponding filename. Check that the file opened correctly. 
{
    in.open(fileName);
    if (in.fail()) // check for an error in input file
    {
        return false;
    }
    else
    {
        return true;
    }
}


char** read_maze_from_file(ifstream& in, int row, int col )
{
    char** Maze = new char *[row];
    for (int i =0; i<row;i++) //for each element in inside array
    {
        Maze[i] = new char [col];
        for (int j=0;j<col;j++) //for each element in outside array
        {
            in>>Maze[i][j]; //read in and assign to maze element
        }
    }

    return Maze;
}

void print_maze(int row, int col, char **Maze)
{    
    for (int i =0; i<row;i++) //for each element in outside array
    {
        for (int j=0;j<col;j++) //for each element in inside array
        {
            cout<< Maze[i][j]; 
        }
        cout<<endl;
        cout<<endl;
    }
}

void find_start(int& startR, int& startC, const int row, const int col, char **Maze)
{
    for (int i =0; i<row;i++) //for each element in outside array
    {
        for (int j=0;j<col;j++)//for each element in inside array
        {
            if (Maze[i][j] == 'S')
            {
                startR = i;
                startC = j;
            }
        }
        cout<<endl;
    }

}

bool solve_BFS_maze(const int startR, const int startC, const int row, const int col, char** Maze)
{

    queue<Position> positionsToCheck; //create list of positions to check
    Position Start(startR, startC);
    positionsToCheck.push(Start);//initial list is start node position    

    while( positionsToCheck.size()!=0 ) //while there are still nodes to check
    {

        Position currPos = positionsToCheck.front();//get current node to check
        positionsToCheck.pop();
        if(Maze[(currPos.x)][(currPos.y)] == 'E') //check if current node is target
        {
            return true;//if yes, found!
        }
        else if(Maze[(currPos.x)][(currPos.y)] == '@'){
            continue;
        }
        else {//if no, for each neighbor if neighbor exists and is unvisited add neighbor to list to check, mark neighbor as visited
            // need to check if exists AND unvisited
            
            if (currPos.x+1 < row && currPos.y < col && (((Maze[(currPos.x+1)][(currPos.y)])=='.')||((Maze[(currPos.x+1)][(currPos.y)])=='E')))
            {
                positionsToCheck.push(Position(currPos.x+1, currPos.y));
            }
            if (currPos.x < row && currPos.y+1 < col && (((Maze[(currPos.x)][(currPos.y+1)])=='.')||((Maze[(currPos.x)][(currPos.y+1)])=='E')))
            {
                positionsToCheck.push(Position(currPos.x, currPos.y+1));
            }
            if (currPos.x-1 >= 0 && currPos.y < col && (((Maze[(currPos.x-1)][(currPos.y)])=='.')||((Maze[(currPos.x-1)][(currPos.y)])=='E')))
            {
                positionsToCheck.push(Position(currPos.x-1, currPos.y));
            }
            if (currPos.x < row && currPos.y-1 >= 0 && (((Maze[(currPos.x)][(currPos.y-1)])=='.')||(Maze[(currPos.x)][(currPos.y-1)]=='E')))
            {
                positionsToCheck.push(Position(currPos.x, currPos.y-1));
            }
            
            
        }
        if (Maze[(currPos.x)][(currPos.y)] != 'S')
        {
            Maze[(currPos.x)][(currPos.y)] = '@';
        }
        
    }

    return false;
}


bool solve_DFS_maze(const int startR, const int startC, const int row, const int col, char** Maze)
{
    stack<Position> positionsToCheck; //create list of positions to check
    Position Start(startR, startC);
    positionsToCheck.push(Start);//initial list is start node position   
    
    while( positionsToCheck.size()!=0 ) //while there are still nodes to check
    {
        Position currPos = positionsToCheck.top();//get current node to check
        positionsToCheck.pop();
        if(Maze[(currPos.x)][(currPos.y)] == 'E') //check if current node is target
        {
            return true;//if yes, found!
        }
        else if(Maze[(currPos.x)][(currPos.y)] == '@'){
            continue;
        }
        else {//if no, for each neighbor if neighbor exists and is unvisited add neighbor to list to check, mark neighbor as visited
            // need to check if exists AND unvisited
            if (currPos.x+1 < row && currPos.y < col && (((Maze[(currPos.x+1)][(currPos.y)])=='.')||((Maze[(currPos.x+1)][(currPos.y)])=='E')))
            {
                positionsToCheck.push(Position(currPos.x+1, currPos.y));
            }
            if (currPos.x < row && currPos.y+1 < col && (((Maze[(currPos.x)][(currPos.y+1)])=='.')||((Maze[(currPos.x)][(currPos.y+1)])=='E')))
            {
                positionsToCheck.push(Position(currPos.x, currPos.y+1));
            }
            if (currPos.x-1 >= 0 && currPos.y < col && (((Maze[(currPos.x-1)][(currPos.y)])=='.')||((Maze[(currPos.x-1)][(currPos.y)])=='E')))
            {
                positionsToCheck.push(Position(currPos.x-1, currPos.y));
            }
            if (currPos.x < row && currPos.y-1 >= 0 && (((Maze[(currPos.x)][(currPos.y-1)])=='.')||(Maze[(currPos.x)][(currPos.y-1)]=='E')))
            {
                positionsToCheck.push(Position(currPos.x, currPos.y-1));
            }
            
        }
        if (Maze[(currPos.x)][(currPos.y)] != 'S')
        {
            Maze[(currPos.x)][(currPos.y)] = '@';
        }
        
    }

    return false;
}

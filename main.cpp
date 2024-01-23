/* CSCI 200: Assignment 5: A5 - a - MAZE-ing
 *
 * Author: Hannah Miller
 * Resources used: Stack and Queue documentation
 * Hannah helpped me a ton in office ours to debug my code
 */

#include "Maze.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


int main (int argc, char* argv[])
{
    // check program was started correctly
    if(argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        cerr << "  filename   - file to open upon start" << endl;
        return -2;
    }

    // get filename to open
    string filename = argv[1];

    // open file for parsing
    ifstream fileIn;
    
    if( !open_file(fileIn, filename) ) {
    cerr << "Could not open file \"" << filename << "\"" << endl;
    cerr << "Shutting down" << endl;
    return -1;
    }
    cout<< "File opened successfully!"<<endl;
    // read in the maze
    int row;
    int col;
    fileIn >> row >> col;
    
    char **Maze= read_maze_from_file( fileIn, row, col );
    fileIn.close();

    int choice;
    bool correctInput = false;
    do{
        cout<<"Enter 1 to search via BFS."<<endl<< "Enter 2 to search via DFS."<<endl;
        cout<<"Choice: "<<endl;
        cin>>choice;
        if (choice!= 1 && choice!=2)
        {
            cout<< "Incorrect choice, enter 1 or 2"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
            correctInput = false;
        }
        else{
            correctInput = true;
        }
    }
    while(correctInput == false);

    int startR, startC;
    find_start(startR, startC, row, col, Maze);


    bool finish;
    if (choice == 2)
    {
        finish = solve_DFS_maze(startR, startC, row, col, Maze);
    }
    else if (choice == 1)
    {
        finish = solve_BFS_maze(startR, startC, row, col, Maze);
    }

    if (finish == false)
    {
        cout<<"End cannot be reached"<<endl;
    }
    else{
        cout << "End was reached!"<<endl;
    }

    print_maze(row, col, Maze);
    



    return 1;
    
}






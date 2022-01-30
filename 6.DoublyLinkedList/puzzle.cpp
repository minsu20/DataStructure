// --------------------------------------------------------------------
//
//  Laboratory 9, In-lab Exercise 1                        puzzle.cs
// 2020112377 컴퓨터공학과 김민수
//  (Shell) Anagram puzzle
//
//--------------------------------------------------------------------

// Simulates a puzzle in which a player attempts to unscramble a
// set of letters to form a word.

#include <iostream>
#include <string>
#include <cstring>
#include "listdbl.cpp"

using namespace std;

//--------------------------------------------------------------------
//
//  Class declaration for the Anagram Puzzle ADT
//
//--------------------------------------------------------------------

class AnagramPuzzle
{
public:

    AnagramPuzzle(string answ, string init);   // Construct puzzle
    void shiftLeft();                            // Shift letters left
    void swapEnds();                             // Swap end letters
    void display();                              // Display puzzle
    bool isSolved();                             // Puzzle solved

private:

    // Data members
    List<char> solution,   // Solution to puzzle
        puzzle;     // Current puzzle configuration
};

//--------------------------------------------------------------------

// The main() function provides the user interface to the puzzle.

void main()
{
    AnagramPuzzle mysteryWord("yes", "yse");   // Puzzle
    char move,                                // User input move
        userQuit;                            // User quits puzzle

   // Display the initial puzzle.

    mysteryWord.display();

    // Loop until puzzle solved or user quits

    userQuit = 0;
    while (!mysteryWord.isSolved() && !userQuit)
    {
        cout << "Enter move ( L/S/Q ): ";   // Get user move
        cin >> move;
        switch (move)                     // Process move
        {
        case 'L': case 'l':  mysteryWord.shiftLeft();  break;
        case 'S': case 's':  mysteryWord.swapEnds();   break;
        case 'Q': case 'q':  userQuit = 1;             break;
        default:  cout << "Invalid move" << endl;
        }
        mysteryWord.display();              // Display puzzle
    }
    if (mysteryWord.isSolved())
        cout << "Congratulations!" << endl;

    system("PAUSE");
}

//--------------------------------------------------------------------
//
//  Implementation of the Anagram Puzzle ADT
//
//--------------------------------------------------------------------

AnagramPuzzle::AnagramPuzzle(string answ, string init)

// Constructs an anagram puzzle. String answ is the solution to the
// puzzle and string init is the initial scrambled letter sequence.
    
{
    int len = answ.length();
    for (int i = 0; i < len; i++)
        solution.insert(answ[i]);

    int len2 = init.length();
    for (int i = 0; i < len2; i++)
        puzzle.insert(init[i]);
}

//--------------------------------------------------------------------

void AnagramPuzzle::shiftLeft()

// Shifts the letters left one position, the leftmost letter is moved
// to the right end of the puzzle.

{
    puzzle.gotoBeginning();
    char left = puzzle.getCursor(); //왼쪽 문자 저장
    puzzle.remove(); //왼쪽 문자 지움
    puzzle.gotoEnd(); 
    puzzle.insert(left); //맨오른쪽에 왼쪽 문자 추가
}

//--------------------------------------------------------------------

void AnagramPuzzle::swapEnds()

// Swaps the letters at the left and right ends of the puzzle.

{
    puzzle.gotoBeginning();
    char left = puzzle.getCursor(); //왼쪽 문자 저장
    puzzle.gotoEnd();
    char right = puzzle.getCursor(); //오른쪽 문자 저장
    
    puzzle.gotoBeginning();
    puzzle.replace(right); //왼쪽 문자 오른쪽 문자로 바꿈
    puzzle.gotoEnd();
    puzzle.replace(left); //오른쪽 문자 왼쪽 문자로 바꿈

}

//--------------------------------------------------------------------

void AnagramPuzzle::display()

// Displays an anagram puzzle.

{
    solution.gotoBeginning();
    cout << "Solution to the Puzzle: ";
    do {
        cout<<solution.getCursor();
    } while (solution.gotoNext());
    cout << endl;

    puzzle.gotoBeginning();
    cout << "Current String: ";
    do{
        cout << puzzle.getCursor();
    } while (puzzle.gotoNext());
    cout << endl<<endl;
}

//--------------------------------------------------------------------

bool AnagramPuzzle::isSolved()

// Returns true if a puzzle is solved. Otherwise returns false.

{
    char puzzlestr[10] = { 0, };
    char solutionstr[10] = { 0, };

    int i = 0, j = 0;

    puzzle.gotoBeginning();
    do {
         puzzlestr[i++]=puzzle.getCursor();
    } while (puzzle.gotoNext()); //puzzleList 문자열에 저장

    solution.gotoBeginning();
    do {
        solutionstr[j++] = solution.getCursor();
    } while (solution.gotoNext()); //solution List 문자열에 저장

    if (strcmp(puzzlestr, solutionstr) == 0) //비교
        return true;
    else
        return false;
}

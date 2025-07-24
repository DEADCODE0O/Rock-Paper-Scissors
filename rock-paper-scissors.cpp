#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
enum enReadPlayerChoice { Rock = 1, Paper = 2, Scissors = 3 };


int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

string ReadPlayerChoice()
{
    int choice;
    cout << "Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ";
    cin >> choice;
    switch (choice)
    {
    case enReadPlayerChoice::Rock:
        return "Rock";
    case enReadPlayerChoice::Paper:
        return "Paper";
    case enReadPlayerChoice::Scissors:
        return "Scissors";
    default:
        return "Invalid choice";
    }
}

string ReadComputerChoice()
{
    int choice = RandomNumber(1, 3);
    switch (choice)
    {
    case enReadPlayerChoice::Rock:
        return "Rock";
    case enReadPlayerChoice::Paper:
        return "Paper";
    case enReadPlayerChoice::Scissors:
        return "Scissors";
    default:
        return "Invalid choice";
    }
}

int IsPlayerWinner(string playerChoice, string computerChoice)
{
    if (playerChoice == computerChoice) {
        return 0;
    }
    else if ((playerChoice == "Paper" && computerChoice == "Rock") ||
        (playerChoice == "Rock" && computerChoice == "Scissors") ||
        (playerChoice == "Scissors" && computerChoice == "Paper")) {
        return 1;
    }
    else if ((computerChoice == "Paper" && playerChoice == "Rock") ||
        (computerChoice == "Rock" && playerChoice == "Scissors") ||
        (computerChoice == "Scissors" && playerChoice == "Paper")) {
        return -1;
    }

}

void PrintResult(string playerChoice, string computerChoice, bool isPlayerWinner, int length, int arr[3])
{
    cout << "\n-------------------------Round [" << length << "]-------------------------\n" << endl;
    cout << "Player Choice : " << playerChoice << endl;
    cout << "Computer Choice : " << computerChoice << endl;
    if (IsPlayerWinner(playerChoice, computerChoice) == 1) {
        cout << "Player wins!" << endl;
        system("color 2f");
        arr[0]++;
    }
    else if (IsPlayerWinner(playerChoice, computerChoice) == 0) {
        cout << "It's a tie!" << endl;
        system("color 6F");
        arr[1]++;
    }
    else if (IsPlayerWinner(playerChoice, computerChoice) == -1) {
        cout << "Computer wins!" << "\a" << endl;
        system("color 4F");
        arr[2]++;
    }
    cout << "\n------------------------------------------------------------\n" << endl;


}

void PrintFinalResult(int arr[3], int round)
{
    cout << "\n\n-------------------------Final Result-------------------------\n\n" << endl;
    cout << "Total Rounds Played: " << round << endl;
    cout << "Player Wins: " << arr[0] << endl;
    cout << "Ties: " << arr[1] << endl;
    cout << "Computer Wins: " << arr[2] << endl;
    if (arr[0] > arr[2]) {
        cout << "Congratulations! You are the overall winner!" << endl;
    }
    else if (arr[0] < arr[2]) {
        cout << "The computer is the overall winner!" << endl;
    }
    else {
        cout << "It's an overall tie!" << endl;
    }
    cout << "\n\n------------------------------------------------------------\n\n" << endl;
}

int ReadNumberOfRounds()
{
    int rounds;
    cout << "Enter the number of rounds: ";
    cin >> rounds;
    return rounds;
}


void PlayGame()
{
    int array[3] = { 0, 0, 0 };
    int rounds = ReadNumberOfRounds();
    for (int i = 1; i <= rounds; i++)
    {
        string playerChoice = ReadPlayerChoice();
        if (playerChoice == "Invalid choice") {
            cout << "Please enter a valid choice." << endl;
            i--;
            continue;

        }
        string computerChoice = ReadComputerChoice();
        PrintResult(playerChoice, computerChoice, IsPlayerWinner(playerChoice, computerChoice), i, array);

    }
    PrintFinalResult(array, rounds);

}
void PlayAgain()
{
    char choice;
    do {
        PlayGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {

            cout << "Thank you for playing!" << endl;

        }
    } while (choice == 'y' || choice == 'Y');


}






int main()
{
    srand((unsigned)time(NULL));

    PlayAgain();

    return 0;
}

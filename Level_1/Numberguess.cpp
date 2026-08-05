#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1; // number between 1 and 100
    int guess;
    int attempts = 0;
    cout<<"===== Welcome to Number Guessing Game ! ===="<<endl;
    cout<<"I have chosen a number between 1 and 100. "<<endl;
    cout<<"Can you guess it ? "<<endl;
    //Loop until correct guess
    do {
        cout<<"\nEnter your guess: ";
        cin>>guess;
        attempts ++;
        if(guess>randomNumber){
            cout<<"Too high! Try again."<<endl;
        } else if (guess<randomNumber){
            cout<<"Too low! Try again."<<endl;
        }else {
            cout<<"Congratulation ! You guessed the number in " << attempts <<"attempts."<<endl;
        }

    } while (guess != randomNumber);
    cout<<"Thanks for playing !"<<endl;
    return 0;
}
#include<iostream>
#include<ctime>
#include<string>

using namespace std;

void blackjack(void);
int dealCardsPlayer(int);
int dealCardsCPU(int);
int hit(int &);
void determineWinner(int, int);
int Random(int, int);
void start(void);

// current issues:
// 1. After player busts, CPU turns still runs
// 2. Picking up a card number pass 11 (example: "You picked up a card: 17")

int main(){
    char startgame = 'y' || 'n';
    std::cout<<"Welcome To BlackJack"<<endl<<"Start(y/n)?"<<endl;
    std::cin>>startgame;
    if (startgame == 'y')
        start();
    else if (startgame == 'n')
        std::cout<<"GoodBye"<<endl;
}

void start(void){
    char keepPlaying = 'y' || 'n';
    do {
        blackjack();
        std::cout<<"Play Again(y/n)?"<<endl;
        std::cin>>keepPlaying;
    }
    while(keepPlaying == 'Y' || keepPlaying == 'y');
    if (keepPlaying = 'n') { std::cout<<"Thank you for playing"<<endl; }
}

void blackjack(void){
    srand((int) time(0));
    int player = dealCardsPlayer(2);
    std::cout<<"= "<<player<<std::endl;

    int computer = dealCardsCPU(2);

    if (player == 21) { determineWinner(player, computer); } // if dealing == 21, player auto wins
    if (computer == 21) { determineWinner(player, computer); } // if dealing == 21, cpu auto wins

    hit(player);
    while((computer < 17) && (computer < 21)){
        computer += dealCardsCPU(1);
        std::cout<<"CPU hits!"<<endl;

        // if cpu hits and passes 21, player wins
        if (computer > 21){
            std::cout<<"CPU Bust!"<<std::endl;
            break; // WILL THIS BREAK STATEMENT FINISH THE GAME OR LEAVE THE WHILE LOOP????
        }
    }
  determineWinner(player, computer);
}

int dealCardsPlayer(int numberOfCards){
    int card_value = 0; 
    int return_value = 0;
    std::cout<<"Your Hand: ";
    for(int i = 1; i <= numberOfCards; i++){ 
        card_value = Random(1,11);
        std::cout<<card_value<<" ";
        return_value += card_value;
    }
    return return_value;
}

int dealCardsCPU(int numberOfCards){
    int return_value = 0;
    int value = 0;

    for (int a = 1; a <= numberOfCards; ++a){
        value = Random(1,11);
        return_value += value;
    }
    return return_value;
}

int hit(int &playerScore){
    int cardTotal = 0;
    int hitAmount = 0;
    cardTotal = playerScore;
    char wantCard = "y" || "n";
    std::cout<<"Hit?(y/n)"<<std::endl;
    std::cin>>wantCard;
    while (wantCard == 'Y' || wantCard == 'y'){
        hitAmount = Random(1,11);

        std::cout<<"You picked up a card: "<<hitAmount<<std::endl;
        cardTotal += hitAmount; // cardTotal is the current player score and add the hit amount onto the player score

        std::cout<<"Your Total is: "<<cardTotal<<std::endl;
        playerScore = cardTotal;

        if (playerScore > 21){
            std::cout<<"Player Bust!"<<std::endl;
            determineWinner(playerScore)
            }

        std::cout<<"Hit? (y/n)"<<std::endl;
        std::cin>>wantCard;
        if (wantCard == 'Y' || wantCard == 'y')
            continue; // deals another card to player
        else if (wantCard == 'N' || wantCard == 'n')
            std::cout<<"You decided to stay"<<std::endl;
            playerScore = cardTotal;
            return playerScore;
    }
}

void determineWinner(int playerScore, int CPUScore){

    if (playerScore > CPUScore){std::cout<<"You Win!"<<std::endl;} 
    if (playerScore < CPUScore) {std::cout<<"You Lose!"<<std::endl;}
    if (playerScore == CPUScore) {std::cout<<"Draw!"<<std::endl;}


    // possiblity of creating another function to print scores
    std::cout<<"Your Hand: "<<playerScore<<std::endl;
    std::cout<<"CPU Hand: "<<playerScore<<std::endl;
}

int Random(int lowerLimit, int upperLimit) { return 1 + rand() % (upperLimit - lowerLimit); }

#include <iostream>

char cards[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

int pull_random_card(){
    int size = sizeof(cards) / sizeof(cards[0]);

    int randomIndex = rand() % size;

    char card = cards[randomIndex];

    if(card >= '2' && card <= '9'){
        return card - '0';
    }
    if(card == 'T' || card == 'K' || card == 'Q' || card == 'J'){
        return 10;
    }
    if(card == 'A'){
        return 11;
    }

    return 0;
}

int player_actions(){
    int input;

    std::cout << "1. HIT\n";
    std::cout << "2. STAND\n";
    std::cout << "3. DOUBLE\n";

    std::cin >> input;

    return input;
}

void dealer_turn(){
    int dealer_card = 0;
    dealer_card += pull_random_card();

    while(dealer_card < 17){
        dealer_card += pull_random_card();
    }

    std::cout << "Dealer's total :" << dealer_card << '\n';

    if(dealer_card <= 21){
        std::cout << "Dealer stands at " << dealer_card << '\n';
    }
    else{
        std::cout << "Dealer busts at " << dealer_card << '\n';
        std::cout << "You've just won, how lucky.\n";
        return;
    }

}

void game(){
    int player_card = 0;
    player_card += pull_random_card();

    std::cout << "Your Card : " << player_card << '\n';

    int input = player_actions();

    while(input){
        if(input == 1){
            std::cout << "Hitting..\n";
            player_card += pull_random_card();
            std::cout << "Your Card : " << player_card << '\n';
            if(player_card == 21){
                std::cout << "You just won!\n";
                return;
            }
            if (player_card > 21){
                std::cout << "Oops! You busted, better luck next time~\n";
                return;
            }
            input = player_actions();
        }
        if(input == 2){
            std::cout << "It's dealer's turn now..\n";
            dealer_turn();
            return;
        }
        if(input == 3){
            std::cout << "Doubling..\n";
            player_card += pull_random_card();
            std::cout << "Your Card : " << player_card << '\n';
            dealer_turn();
            return;
        }
    }
}

int main(){
    std::cout << "===== ==================== =====\n";
    std::cout << "===== WELCOME TO BLACKJACK =====\n";
    std::cout << "===== ==================== =====\n";

    srand(time(NULL));
    game(); 

    std::cout << "===== GAME OVER =====";

    return 0;
}
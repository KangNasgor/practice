#include <iostream>
#include <random>

class Character{
    public:
        void take_damage(int amount){
            if(is_blocked == true){
                is_blocked = false;
                return;
            }
            health -= amount;
            on_health_changed();
        }

        void basic_attack(Character &target){
            target.take_damage(basic_attack_dmg);
            add_ultimate_percentage(basic_attack_dmg);
        }

        void block(){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dist(1, 100);

            int chance = 30; 

            if (dist(gen) <= chance) {
                is_blocked = true;
            }
        }

        void special_attack(Character &target){
            target.take_damage(special_attack_dmg);
            add_ultimate_percentage(special_attack_dmg);
        }

        void ultimate(Character &target){
            if(ultimate_percentage < 100){
                return;
            }
            target.take_damage(ultimate_dmg);
            ultimate_percentage = 0;
        }

        int get_health() const { return health; }
        bool get_is_dead() const { return is_dead; }
        int get_ultimate_percentage() const { return ultimate_percentage; }
        int get_mana() const { return mana; }


    private:
        int health = 100;
        int mana = 50;
        int ultimate_percentage = 0;
        int ultimate_dmg = 50;
        int basic_attack_dmg = 10;
        int special_attack_dmg = 15;
        bool is_dead = false;
        bool is_blocked = false;

        void on_health_changed(){
            if(health <= 0){
                health = 0;
                is_dead = true;
            }
        }

        void add_ultimate_percentage(int amount){
            ultimate_percentage += amount * 3;
            if(ultimate_percentage > 100){
                ultimate_percentage = 100;
            }
        }
};

int main(){

    Character player;
    Character enemy;

    int option;

    std::cout << "===== =========================================== =====\n";
    std::cout << "===== Defeat your opponent before he defeats you. =====\n";
    std::cout << "===== =========================================== =====\n";

    do{
        std::cout << "Select your action : \n";
        std::cout << "1. Basic Attack \n";
        std::cout << "2. Special Attack \n";
        std::cout << "3. Block \n";
        std::cout << "4. Ultimate : " << player.get_ultimate_percentage() << "\n";

        std::cin >> option;

        switch(option){
            case 1:
                player.basic_attack(enemy);
                break;
            case 2:
                player.special_attack(enemy);
                break;
            case 3:
                player.block();
                break;
            case 4:
                player.ultimate(enemy);
                break;
            default:
                std::cout << "Select the correct option.\n";
                break;
        }

        if(enemy.get_is_dead() == false){
            std::cout << "==========\n";
            std::cout << "Enemy health : " << enemy.get_health() <<  "\n";
            std::cout << "==========\n";
        }
        else{
            std::cout << "==========\n";
            std::cout << "Enemy health : " << enemy.get_health() <<  "\n";
            std::cout << "You've achieved victory.\n";
            std::cout << "==========\n";

            return 0;
        }

        std::cout << "==========\n";
        std::cout << "Enemy is attacking...\n";
        std::cout << "==========\n";

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, 4);

        int enemy_option = dist(gen);

        switch(enemy_option){
            case 1:
                enemy.basic_attack(player);
                break;
            case 2:
                enemy.special_attack(player);
                break;
            case 3:
                enemy.block();
                break;
            case 4:
                enemy.ultimate(player);
                break;
            default:
                break;
        }

        if(player.get_is_dead() == false){
            std::cout << "==========\n";
            std::cout << "Your health : " << player.get_health() <<  "\n";
            std::cout << "==========\n";
        }
        else{
            std::cout << "==========\n";
            std::cout << "Your health : " << player.get_health() <<  "\n";
            std::cout << "You Lost.\n";
            std::cout << "==========\n";
        }

    } while (enemy.get_is_dead() == false && player.get_is_dead() == false);

    return 0;
}
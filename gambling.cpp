#include <iostream>
#include <ctime>

void SlotMachine(char* Signs, char* Blanks);
int Win(char* Signs, char* Blanks, int &cash);



int main ()
{
    srand(time(0));

    std::string play;
    std::string SPIN;
    char Signs[] = {'%', '%', '%', '@', '@', '@', '&', '&', '&', '7', '7', '7'};  
    char Blanks[] = {' ', ' ', ' '};
    

    int cash = 2000;

    std::cout << "Do you want to play ? It' 10 $ per spin ! (PLEASE ONLY USE CAPS!) " << '\n';
    std::cin >> play;

    if(play == "N"){
        return 0;
    }

    SlotMachine(Signs, Blanks);

    do{
    cash -= 10;    
    SlotMachine(Signs, Blanks);
    std::cout << "Your ballance : " << cash << " $" << '\n';
    Win(Signs, Blanks, cash);
    std::cout << "Do you want to spin again? (Type : SPIN / PLAY / YES) " << '\n';
    std::cin >> SPIN;

    if(cash <= 0){
        std::cout << "You ran out of money !" << '\n';
        break;
    }


    }while(cash > 0 && (SPIN == "SPIN" || SPIN == "PLAY" || SPIN == "YES"));
    

    return 0;
}



void SlotMachine(char* Signs, char* Blanks){
    int slot1 = rand() % 12 ;
    int slot2 = rand() % 12 ;
    int slot3 = rand() % 12 ;

    Blanks[0] = Signs[slot1];
    Blanks[1] = Signs[slot2];
    Blanks[2] = Signs[slot3];

    std::cout << "                *&&*                   " << '\n';
    std::cout << "====================================== " << '\n';
    std::cout << "| Las Vegas           SUPER SLOT     |" << '\n';
    std::cout << "====================================== " << '\n';
    std::cout << "|           |             |          |  *" << '\n';
    std::cout << "|     " << Blanks[0] << "     |      " << Blanks[1] << "      |    " << Blanks[2] << "     |  |" << '\n';
    std::cout << "|           |             |          |p-|" << '\n';
    std::cout << "|----------------------------------- |" << '\n';
    std::cout << "|           |             |          |" << '\n';
    std::cout << "|           |             |          |" << '\n';
    std::cout << "|------------------------------------| " << '\n';

    
}

int Win(char* Signs, char* Blanks, int &cash){
    if(Blanks[0] == '%' && Blanks[1] == '%' && Blanks[2] == '%' ){
        std::cout << "Sweet !" << '\n';
        cash += 50;
    }

    else if(Blanks[0] == '%' && Blanks[1] == '%' || Blanks[1] == '%' && Blanks[2] == '%' || Blanks[0] == '%' && Blanks[2] == '%'){
        std::cout << "Sour... " << '\n';
        cash += 10;
    }

    else if(Blanks[0] == '@' && Blanks[1] == '@' && Blanks[2] == '@' ){
        std::cout << "Jolly !" << '\n';
        cash += 40;
    }

    else if(Blanks[0] == '@' && Blanks[1] == '@' || Blanks[1] == '@' && Blanks[2] == '@' || Blanks[0] == '@' && Blanks[2] == '@'){
        std::cout << " Musical ! " << '\n';
        cash += 8;
    }

    else if(Blanks[0] == '&' && Blanks[1] == '&' && Blanks[2] == '&' ){
        std::cout << "Lucky !" << '\n';
        cash += 50;
    }

    else if(Blanks[0] == '&' && Blanks[1] == '&' || Blanks[1] == '&' && Blanks[2] == '&' || Blanks[0] == '&' && Blanks[2] == '&'){
        std::cout << "Nice. " << '\n';
        cash += 5;
    }

    else if(Blanks[0] == '7' && Blanks[1] == '7' && Blanks[2] == '7' ){
        std::cout << "JACKPOT !" << '\n';
        cash += 100;
    }

    else if(Blanks[0] == '7' && Blanks[1] == '7' || Blanks[1] == '7' && Blanks[2] == '7' || Blanks[0] == '7' && Blanks[2] == '7'){
        std::cout << " So close... " << '\n';
        cash += 20;
    }

    else{
        std::cout << "Too bad... " << '\n';
    }
    return cash;
}




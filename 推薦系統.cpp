#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

//產生猜測
void Guess(int guess[10][5]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            guess[i][j] = rand() % 10;
        }
    }
}

//更新猜測
void update(int card[10][5], int guess[10][5], int input) {
    if (input > 0) {
        for (int i = 0; i < 10; i++) {
            bool check = true;
            for (int j = 0; j < 5; j++) {
                if (card[i][j] != guess[i][j]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                card[i][4] = input / 10000;
                card[i][3] = (input / 1000) % 10;
                card[i][2] = (input / 100) % 10;
                card[i][1] = (input / 10) % 10;
                card[i][0] = input % 10;
                break;
            }
        }
    }
}

//加入購物車
void addToCart(std::vector<int>& cart, int item) {
    cart.push_back(item);
    std::cout << "Item " << item << " added to cart." << std::endl;
}

//顯示購物車內容
void showCart(const std::vector<int>& cart) {
    std::cout << "Cart contains: ";
    for (int item : cart) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

//輸入答案
int main() {
    srand(time(NULL)); //設定亂數種子
    bool OK = false; //用來檢查是否猜對
    int guess[10][5]; //猜測
    int card[10][5]; //答案
    int input; //輸入
    std::vector<int> cart; //購物車

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            card[i][j] = rand() % 10;
        }
    }

    while (!OK) {
        Guess(guess);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                std::cout << guess[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cin >> input;
        update(card, guess, input);
        addToCart(cart, input);
        showCart(cart);
        OK = true;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                if (card[i][j] != guess[i][j]) {
                    OK = false;
                    break;
                }
            }
            if (OK) {
                break;
            }
        }
    }
    return 0;
}
#include <iostream>
#include <string>
#include <limits>// for std::numeric_limits

void encode(std::string& psw) {
    const std::string key = "mypassword";
    for (int i = 0; i < psw.size(); i++) {
        psw[i] += 1;
    }
    return;
}//用于计算并输出加密后的密码

void decode(std::string& psw) {
    const std::string key = "mypassword";
    for (int i = 0; i < psw.size(); i++) {
        psw[i] -= 1;
    }
    return;
}//用于计算并输出解密后的密码

void print_menu() {
    std::cout << "请选择加密或者解密" << std::endl;
    std::cout << "1.加密" << std::endl;
    std::cout << "2.解密" << std::endl;
}

void clear_screen() {
    system("cls");
}

int main() {
    char switcher = 0;
    std::string psw;
    const int max_tries = 3; // 最多尝试输入次数
    int tries = 0; // 当前已经尝试的次数
    print_menu();
    while (tries < max_tries) {
        std::cin >> switcher;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空缓冲区
        clear_screen();
        if (switcher == '1') {
            std::cout << "请输入需要加密的密码：";
            std::getline(std::cin, psw);
            encode(psw);
            std::cout << "加密后的密码为：" << psw << std::endl;
            break;
        }
        else if (switcher == '2') {
            std::cout << "请输入需要解密的密码：";
            std::getline(std::cin, psw);
            decode(psw);
            std::cout << "解密后的密码为：" << psw << std::endl;
            break;
        }
        else {
            print_menu();
            tries++;
        }
    }

    if (tries == max_tries) {
        std::cout << "输入错误次数已达到上限，程序即将退出..." << std::endl;
    }

    return 0;
}
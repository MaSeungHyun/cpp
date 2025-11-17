/*
 * 간단한 숫자 맞추기 게임
 * - 컴퓨터가 1~100 사이의 숫자를 생각
 * - 플레이어가 추측
 * - 힌트 제공 (더 큰지, 작은지)
 * - 시도 횟수 카운트
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberGuessingGame {
private:
    int secretNumber;
    int attempts;
    int maxAttempts;

public:
    NumberGuessingGame(int max = 10) : attempts(0), maxAttempts(max) {
        srand(time(0));
        secretNumber = rand() % 100 + 1;
    }
    
    void play() {
        cout << "\n==================================" << endl;
        cout << "  숫자 맞추기 게임" << endl;
        cout << "==================================" << endl;
        cout << "1부터 100 사이의 숫자를 맞춰보세요!" << endl;
        cout << "최대 시도 횟수: " << maxAttempts << "번" << endl;
        cout << "==================================" << endl;
        
        while (attempts < maxAttempts) {
            int guess;
            cout << "\n추측 (" << (attempts + 1) << "/" << maxAttempts << "): ";
            cin >> guess;
            
            attempts++;
            
            if (guess == secretNumber) {
                cout << "\n축하합니다! 정답을 맞췄습니다!" << endl;
                cout << "시도 횟수: " << attempts << "번" << endl;
                return;
            } else if (guess < secretNumber) {
                cout << "더 큰 숫자입니다!" << endl;
            } else {
                cout << "더 작은 숫자입니다!" << endl;
            }
            
            int remaining = maxAttempts - attempts;
            if (remaining > 0) {
                cout << "남은 기회: " << remaining << "번" << endl;
            }
        }
        
        cout << "\n게임 오버! 시도 횟수를 모두 사용했습니다." << endl;
        cout << "정답은 " << secretNumber << " 이었습니다." << endl;
    }
};

int main() {
    char playAgain;
    
    do {
        NumberGuessingGame game(10);
        game.play();
        
        cout << "\n다시 플레이하시겠습니까? (y/n): ";
        cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "\n게임을 종료합니다. 즐거우셨나요? 감사합니다!" << endl;
    
    return 0;
}


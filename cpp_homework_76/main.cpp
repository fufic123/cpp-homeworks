#include <iostream>
using namespace std;

class PowerSystem {
public:
    void powerOn() {
        cout << "Включение стиральной машины" << "\n";
    }


    void powerOff() {
        cout << "Выключение стиральной машины" << "\n";
    }
};

class WaterSystem {
public:
    void fillWater() {
        cout << "Наполнение водой" << "\n";
    }

    void drainWater() {
        cout << "Слив воды" << "\n";
    }
};

class SpinSystem {
public:
    void startSpin() {
        cout << "Запуск крутилки" << "\n";
    }

    void stopSpin() {
        cout << "Остановка крутилки" << "\n";
    }
};


class WashingMachineFacade {
private:
    PowerSystem powerSystem;
    WaterSystem waterSystem;
    SpinSystem spinSystem;

public:
    void startWashing() {
        powerSystem.powerOn();
        waterSystem.fillWater();
        spinSystem.startSpin();
        cout << "Старт стирки" << "\n";
    }

    void stopWashing() {
        cout << "Остановка стирки" << "\n";
        spinSystem.stopSpin();
        waterSystem.drainWater();
        powerSystem.powerOff();
    }
};



int main() {

    setlocale(0, "");

    WashingMachineFacade washingMachine;
    washingMachine.startWashing();
    washingMachine.stopWashing();

    return 0;
}
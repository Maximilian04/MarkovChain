#include "Console.hpp"

atomic_bool Console::gotInput(false);

mutex Console::input_mutex;
string Console::input; // !!! use "input_mutex" while using

void Console::start() {
    static bool isRunning(false);
    if (isRunning) return;
    isRunning = true;

    thread consoleThread([&] {
        string buffer;

        while (true) {
            cin >> buffer;

            input_mutex.lock(); //----- input_mutex zone begin -----
            input = buffer;
            gotInput.store(true);
            input_mutex.unlock(); //----- input_mutex zone end -----
        }
    });

    consoleThread.detach();
}

bool Console::hasGotInput() {
    return gotInput.load();
}

string Console::getInput() {
    string result;

    input_mutex.lock(); //----- input_mutex zone begin -----
    result = input;
    gotInput.store(false);
    input_mutex.unlock(); //----- input_mutex zone end -----

    return result;
}

string Console::waitInput() {
    while (!Console::hasGotInput());
    return Console::getInput();
}

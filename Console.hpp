#pragma once

#include <iostream>
#include <string>
#include <mutex>
#include <atomic>
#include <thread>

using namespace std;

class Console {
public:
    static void start();

    static bool hasGotInput();
    static string getInput();

    static string waitInput();
private:
    static atomic_bool gotInput;

    static mutex input_mutex;
    static string input; // !!! use "input_mutex" while using
};

#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <chrono>
#include <assert.h>
#include <string>
#include <ctime>
using namespace std;
#define SLEEP_TIME 5
#define NB_TRY 5
#define NB_TRAJET 5
#define NB_ECHEC 3

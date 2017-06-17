#include <iostream>
#include <windows.h>
#include <thread>
#define PORT 4000
#define IP_ADDRESS "192.168.1.103"
#pragma comment(lib,"ws2_32.lib")
extern char datasend[6];
extern char datarecieve[6];
extern char datasend1[6];
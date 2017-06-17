#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <thread>
USING_NS_CC;
char datasend[6] = "00000";
char datareceieve[6] = "00000";
char datasend1[6] = "00000";
myscene* sc;
DWORD WINAPI ClientRecvThread(LPVOID lpParameter)
{
	SOCKET ClientSocket = (SOCKET)lpParameter;
	int iRet = 0;
	while (true)
	{
		memset(datareceieve, 0x00, 6);
		iRet = recv(ClientSocket, datareceieve, 500, 0);
		if (iRet == 0 || iRet == SOCKET_ERROR)
		{
			std::cout << "接收消息错误！" << std::endl;
			break;
		}
		std::cout << "接收到信息为：" << datareceieve << std::endl;
		for (int i = 0; i < 6; i++)
		{
			sc->datareceievecopy[i] = datareceieve[i];
		}
		sc->receieveaction(datareceieve);
		sc->receievestop(datareceieve);
		sc->schedule(schedule_selector(myscene::updateta));
	}
	return 0;
}
//这个线程处理发送的数据
DWORD WINAPI ClientSendThread(LPVOID lpParameter)
{
	SOCKET ClientSocket = (SOCKET)lpParameter;
	int iRet = 0;
	while (true)
	{
		if (!(datasend[0] == datasend1[0] && datasend[1] == datasend1[1] && datasend[2] == datasend1[2] && datasend[3] == datasend1[3] && datasend[4] == datasend1[4]))
		{
			for (int i = 0; i < 6; i++)
			{
				datasend[i] = datasend1[i];
			}
			iRet = send(ClientSocket, datasend, 5, 0);
		}
		if (iRet == SOCKET_ERROR)
		{
			std::cout << "Server::Send Info Error!" << std::endl;
			break;
		}
	}
	datasend[4] = '0';
	return 0;
}
Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite* background = Sprite::create("myscean1.png");
	background->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(background);
	Sprite* startSpriteNormal = Sprite::create("startgame.png", Rect(516, 58, 119, 30));
	Sprite* startSpriteSelected = Sprite::create("startgame.png", Rect(376, 58, 119, 30));
	MenuItemSprite* startMenuItem =MenuItemSprite::create(startSpriteNormal, startSpriteSelected, CC_CALLBACK_1(HelloWorld::menuItemStartCallback, this));
	startMenuItem->setScale(2.0f);
	startMenuItem->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height*3 / 4);
	startMenuItem->setAnchorPoint(Vec2(0.5, 0.5));
	Menu* mu = Menu::create(startMenuItem, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu);
	return true;
}
void HelloWorld::menuItemStartCallback(Ref* pSender)
{
	sc = myscene::createScene();
	auto reScene = TransitionShrinkGrow::create(1.0f, sc);
	Director::getInstance()->pushScene(reScene);
	std::thread thread1 = std::thread(&HelloWorld::server, this);
	thread1.detach();
}
void HelloWorld::server()
{
	WSADATA Ws;
	SOCKET ServerSocket, ClientSocket;
	struct sockaddr_in LocalAddr, ClientAddr;
	int iRet = 0;
	int AddrLen = 0;
	HANDLE hThread = NULL;
	//Init windows socket
	if (WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
	{
		std::cout << "Init Windows Socket Failed::" << GetLastError() << std::endl;
	}
	//Create Socket
	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ServerSocket == INVALID_SOCKET)
	{
		std::cout << "Create Socket Failed::" << GetLastError() << std::endl;
	}
	LocalAddr.sin_family = AF_INET;
	LocalAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	LocalAddr.sin_port = htons(PORT);
	memset(LocalAddr.sin_zero, 0x00, 8);
	//Bind Socket
	iRet = bind(ServerSocket, (struct sockaddr*)&LocalAddr, sizeof(LocalAddr));
	if (iRet != 0)
	{
		std::cout << "Bind Socket Failed::" << GetLastError() << std::endl;
	}
	iRet = listen(ServerSocket, 10);
	if (iRet != 0)
	{
		std::cout << "Listen Socket Failed !" << GetLastError() << std::endl;
	}
	std::cout << "服务端已经启动！" << std::endl;
	while (true)
	{
		AddrLen = sizeof(ClientAddr);
		ClientSocket = accept(ServerSocket, (struct sockaddr*)&ClientAddr, &AddrLen);
		if (ClientSocket == INVALID_SOCKET)
		{
			std::cout << "Accept Failed::" << GetLastError() << std::endl;
		}
		std::cout << "客户端连接::" << inet_ntoa(ClientAddr.sin_addr) << ":" << ClientAddr.sin_port << std::endl;
		hThread = CreateThread(NULL, 0, ClientRecvThread, (LPVOID)ClientSocket, 0, NULL);
		if (hThread == NULL)
		{
			std::cout << "Create Thread Failed!" << std::endl;
		}
		CloseHandle(hThread);
		hThread = CreateThread(NULL, 0, ClientSendThread, (LPVOID)ClientSocket, 0, NULL);
		if (hThread == NULL)
		{
			std::cout << "Create Thread Failed!" << std::endl;
		}
		CloseHandle(hThread);
	}
	closesocket(ServerSocket);
	closesocket(ClientSocket);
	WSACleanup();
}



    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    


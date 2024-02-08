#ifndef SOCKET_WRAPPER_H
#define SOCKET_WRAPPER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <list>
#include <algorithm>

#include "RoutingTable.h"

#define SOCKET_NAME "/tmp/RTSocket"
#define BUFFER_SIZE 2048
//#define MAX_CLIENT_SUPPORTED    32

class UnixSocket{
private:
	//static int m_fd_set[MAX_CLIENT_SUPPORTED];
	std::list<int> m_fd_set; // Let us use List instead of array
	void InitFDSet();
	int m_commFD{0}; //TBD : This may not be required as we will have this as 1st element of list

	//Socket Related Operations
	int CreateSocket();
	int Bind() const;
	int Listen(int) const;
	//int Connect();

public:
	UnixSocket(); //Constructor
	virtual ~UnixSocket(); //Destructor
	UnixSocket(const UnixSocket& obj) = delete; //Copy Constructor
	UnixSocket(UnixSocket&& obj) = delete; //Move Constructor
	UnixSocket & operator =(const UnixSocket& obj) = delete; //Copy Assignment operator

	//FD Related operations
	void AddToFDSet(int);
	void RemoveFromFDSet(int);
	void RefreshFDSet();
	int GetMaxFD() const;

	//Socket Related Operations
	void HandleConnection();
	void HandleData();

	int ReadBytes();
	int WriteBytes();
};
#endif

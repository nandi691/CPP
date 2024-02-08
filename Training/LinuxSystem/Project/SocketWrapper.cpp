#include "SocketWrapper.h"

UnixSocket::UnixSocket(){
	m_fd_set.clear();
}

UnixSocket::~UnixSocket(){
	m_fd_set.clear();
}

/*UnixSocket::UnixSocket(const UnixSocket& obj){
	m_fd_set = obj.m_fd_set;
}*/

/*UnixSocket::UnixSocket(UnixSocket&& obj){
	//m_fd_set = obj.m_fd_set;
}*/

void UnixSocket::AddToFDSet(int fd){
	//Proceed only if FD does not exist in the list
	m_fd_set.push_back(fd);
}

void UnixSocket::RemoveFromFDSet(int fd){
	//Proceed only if FD exist in the list
	m_fd_set.remove(fd);
}

void UnixSocket::RefreshFDSet(){
	//TB Implemented
}

#ifndef ROUTING_TABLE_H
#define ROUTING_TABLE_H

#include <iostream>

enum Opcodes{
	CREATE,
	UPDATE,
	DELETE
};

typedef struct RoutingTableStruct{
	char * m_IPv4Address;
	char * m_netMask;
	char * m_gatewayIP;
	char * m_interface;
}RT;

class RoutingTable{
private:
	void AddEntry();
	void UpdateEntry();
	void DeleteEntry();
	RT *m_RT;
public:
	RoutingTable();
	virtual ~RoutingTable();
	RoutingTable(const RT & routingTable);
	RoutingTable(RT && routingTable);
	RT & operator =(const RT & routingTable);
	void ParseEntry(int);



};
#endif

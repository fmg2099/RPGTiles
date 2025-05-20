#include "GameObject.h"

//imprime en hexadecimal el UID Md5 del objeto
void GameObject::printUID()
{
	printf("%s : ", name.c_str() );
	for (int i = 0; i < 16; i++)
	{
		//std::cout << std::hex << result[i];
		printf("%02X", uid[i]);
	}
	printf("\n");
}
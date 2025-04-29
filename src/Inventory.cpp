#include "Inventory.h"

void Inventory::AddItem(Item* _item)
{
	currentItem = AddNode(_item);
	_item->SetInventory(this);
}

void Inventory::nextItem()
{
	if (currentItem == nullptr)
	{
		currentItem = head;
		return;
	}
	//todavia hay items en la lista
	if (currentItem->next != nullptr)
	{
		currentItem = currentItem->next;
	}
	else //ya llegamos a la cola, regresamos al head
	{
		currentItem = head;
	}
}

void Inventory::debugPrintContents()
{
	//iterar en la lista
	LLNode<Item>* iter = head;
	std::cout << "Items en inventario:" << std::endl;
	while (iter != nullptr)
	{
		std::cout << "\t" << iter->data->name << std::endl;

		iter = iter->next;
	}
}



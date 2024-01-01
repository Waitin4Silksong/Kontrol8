#pragma once
#include <iostream>
#include <cstring>
#include "Products.h"
// Header for tasks n sorting
struct Tasks
{
	Info Products[500]; // max amount of products in storage
	Info prod;
	int amount; // products in storage
	void addProd()
	{
		if (amount <= 500) {

			std::cout << "Enter product information:" << std::endl;
			std::cout << "Name: ";
			std::cin >> prod.name;
			std::cout << "Manufactory: ";
			std::cin >> prod.manuf;
			std::cout << "Price: ";
			std::cin >> prod.price;
			std::cout << "Product group: ";
			std::cin >> prod.group;
			std::cout << "Arrived at storage: ";
			std::cin >> prod.imporDate;
			std::cout << "Expire date: ";
			std::cin >> prod.exporDate;
			Products[amount++] = prod;
			std::cout << "Product successfuly added to storage.";
		}
		else {
			std::cout << "Storage is too full. Please delete something and try again.";
		}
	}
	void deleteProd(const char* prodName) // decided to do some functions with names, not numbers
	{
		for (size_t i = 0; i < amount; i++)
		{
			if (std::strstr(Products[i].name, prodName) != nullptr) {
				for (int j = i; j < amount - 1; j++)
				{
					Products[j] = Products[j + 1];
				}
				amount--;
				std::cout << "Product deleted successfuly.";
				return;
			}
			else {
				std::cout << "Incorrect input or product isn't on storage.";
			}
		}
		
	}
	void replaceProd(const char* oldProd, Info& newProd)
	{   
		if (amount > 0) {
			for (size_t i = 0; i < amount; i++)
			{
				if (std::strstr(Products[i].name, oldProd) != nullptr) {
					newProd = Products[i];
					std::cout << "Product is replaced. Please enter information for new product:" << std::endl;
					std::cout << "Name: ";
					std::cin >> newProd.name;
					std::cout << "Manufactory: ";
					std::cin >> newProd.manuf;
					std::cout << "Price: ";
					std::cin >> newProd.price;
					std::cout << "Product group: ";
					std::cin >> newProd.group;
					std::cout << "Arrived at storage: ";
					std::cin >> newProd.imporDate;
					std::cout << "Expire date: ";
					std::cin >> newProd.exporDate;
					std::cout << "Product successfuly replaced.";
					return;
				}
				else {
					std::cout << "Incorrect input or product isn't on storage.";
				}
			}
		}
	}

	void searchName(const char* prodName)
	{
		for (int i = 0; i < amount; i++)
		{
			if (std::strstr(Products[i].name, prodName) != nullptr) {
				std::cout << Products[i].name << std::endl;
				std::cout << Products[i].manuf << std::endl;
				std::cout << Products[i].price << std::endl;
				std::cout << Products[i].group << std::endl;
				std::cout << Products[i].imporDate << std::endl;
				std::cout << Products[i].exporDate << std::endl;
			}
			else {
				std::cout << "Incorrect name or product isn't on storage.";
			}
		}
	}
	void searchManuf(const char* manufName)
	{
		for (int i = 0; i < amount; i++)
		{
			if (std::strstr(Products[i].manuf, manufName) != nullptr) {
				std::cout << Products[i].name << std::endl;
				std::cout << Products[i].manuf << std::endl;
				std::cout << Products[i].price << std::endl;
				std::cout << Products[i].group << std::endl;
				std::cout << Products[i].imporDate << std::endl;
				std::cout << Products[i].exporDate << std::endl;
			}
			else {
				std::cout << "Incorrect manufactory name or product isn't on storage.";
			}
		}
	}
	void searchPrice(int price)
	{
		for (int i = 0; i < amount; i++)
		{
			if (Products[i].price == price) {
				std::cout << Products[i].name << std::endl;
				std::cout << Products[i].manuf << std::endl;
				std::cout << Products[i].price << std::endl;
				std::cout << Products[i].group << std::endl;
				std::cout << Products[i].imporDate << std::endl;
				std::cout << Products[i].exporDate << std::endl;
			}
			else {
				std::cout << "Incorrect price or product isn't on storage.";
			}
		}
	}
	void searchGroup(const char* groupName)
	{
		for (int i = 0; i < amount; i++)
		{
			if (std::strstr(Products[i].group, groupName) != nullptr) {
				std::cout << Products[i].name << std::endl;
				std::cout << Products[i].manuf << std::endl;
				std::cout << Products[i].price << std::endl;
				std::cout << Products[i].group << std::endl;
				std::cout << Products[i].imporDate << std::endl;
				std::cout << Products[i].exporDate << std::endl;
			}
			else {
				std::cout << "Incorrect group name or product isn't on storage.";
			}
		}
	}
	void searchImpDate(const char* impDate)
	{
		for (int i = 0; i < amount; i++)
		{
			if (std::strstr(Products[i].imporDate, impDate) != nullptr) {
				std::cout << Products[i].name << std::endl;
				std::cout << Products[i].manuf << std::endl;
				std::cout << Products[i].price << std::endl;
				std::cout << Products[i].group << std::endl;
				std::cout << Products[i].imporDate << std::endl;
				std::cout << Products[i].exporDate << std::endl;
			}
			else {
				std::cout << "Incorrect date or product isn't on storage.";
			}
		}
	}
	void searchExpDate(const char* expDate)
	{
		for (int i = 0; i < amount; i++)
		{
			if (std::strstr(Products[i].exporDate, expDate) != nullptr) {
				std::cout << Products[i].name << std::endl;
				std::cout << Products[i].manuf << std::endl;
				std::cout << Products[i].price << std::endl;
				std::cout << Products[i].group << std::endl;
				std::cout << Products[i].imporDate << std::endl;
				std::cout << Products[i].exporDate << std::endl;
			}
			else {
				std::cout << "Incorrect date or product isn't on storage.";
			}
		}
	}

	void sortBy() // used bubble again
	{
		int num;
		std::cout << "Sort by:" << std::endl;
		std::cout << "Price - 1";
		std::cout << "Group - 2";
		std::cin >> num;
		switch (num) {
		case 1:
			for (int i = 0; i < amount - 1; i++)
			{
				for (int j = 0; j < amount - i - 1; j++)
				{
					if (Products[j].price > Products[j + 1].price) { // Some strange error. Couldn't find anything about it
						std::swap(Products[j], Products[j + 1]);
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < amount - 1; i++)
			{
				for (int j = 0; j < amount - i - 1; j++)
				{
					if (Products[j].group > Products[j + 1].group) {
						std::swap(Products[j], Products[j + 1]);
					}
				}
			}
			break;
		default:
			std::cout << "Invalid input.";
		}
		
	}
};
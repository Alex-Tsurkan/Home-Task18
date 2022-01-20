#include "User.h"
#include "Message.h"
#include <fstream>
#include <iostream>
#include <filesystem>


namespace fs = std::filesystem;


int main()

{

	// ������ � ������ ������������/user_file
	fstream user_file = fstream("users.txt", ios::in | ios::out);
	
	if (!user_file)
	{
		// ���� ����� ��� - ������� ���
		user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);
	}

    fs::permissions("users.txt", fs::perms::owner_all, fs::perm_options::add);
    fs::permissions("users.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
	
	if (user_file) {
		User obj("Alex", "AlexTs", "12345");
		// ���������� ������ � ����
		user_file << obj << endl;
		// ��������� ������ �� �����, ��������� ������� ��� ������ � ������ �����
		user_file.seekg(0, ios_base::beg);
	    user_file >> obj;
		cout << obj << endl;
	}
	else
	{
		cout << "Could not open file users.txt !" << '\n';
		return 0;

	}

	// ������ � ������ ���������/message_file
	fstream message_file = fstream("messages.txt", ios::in | ios::out);
	if (!message_file)
	{
		// ���� ����� ��� - ������� ���
		message_file = fstream("messages.txt", ios::in | ios::out | ios::trunc);
	}

	fs::permissions("messages.txt", fs::perms::owner_all, fs::perm_options::add);
	fs::permissions("messages.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);

	if (message_file) {
		Message obj("Hello, Alex", "admin", "Alex");
		// ���������� ������ � ����
		message_file << obj << endl;
		// ��������� ������ �� �����, ��������� ������� ��� ������ � ������ �����
		message_file.seekg(0, ios_base::beg);
		message_file >> obj;
		cout << obj << endl;
	}
	else
	{
		cout << "Could not open file messages.txt !" << '\n';
		return 0;

	}


	return 0;
}
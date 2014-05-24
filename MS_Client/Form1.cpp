// ============== Schwartsune Kumiko 2014 =========================
//
// : Master Server Client
//
// ================================================================
#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);

	MS_Client::Form1 form;
	Application::Run(%form);
}



void MS_Client::Form1::WhenClosed(Object^ sender, FormClosedEventArgs^ e)
{
	client->Close();
	ConnectedToMaster = false;
}
void MS_Client::Form1::WhenLoad(Object^ sender, EventArgs^ e)
{
	ip = "192.168.0.101"; // TODO (Швартсуне Кумико): Ввод IP адреса мастер-сервера.
	ConnectedToMaster = false;
	try
	{
		client = gcnew TcpClient();
		client->Connect(ip,27016); 
		writer = gcnew StreamWriter(client->GetStream());
		reader = gcnew StreamReader(client->GetStream());
		writer->AutoFlush = true;
		ConnectedToMaster = true;
		receiveThread = gcnew Thread(gcnew ThreadStart(this, &MS_Client::Form1::ReceiveInformation)); // Thread for receive information from Master Server
		receiveThread->Start();
		
	}
	catch (Exception^ exp)
	{
		MessageBox::Show(Convert::ToString(exp));
	}

}
void MS_Client::Form1::RefreshClick(Object^ sender, EventArgs^ e)
{
	if (ConnectedToMaster)
	{
		try
		{
			writer->WriteLine("%R%"); // Send request for server
		}
		catch (Exception^ exp)
		{
			MessageBox::Show(Convert::ToString(exp));
		}
	}
}
void MS_Client::Form1::ReceiveInformation()
{
	while (ConnectedToMaster)
	{
		try
		{
			// TODO (Schwartsune Kumiko): Заполнить ListBox
			MessageBox::Show(reader->ReadLine()); // ДЕБАГ 228: Получение информации полученной в следствии бла бла бла сигнала %R$
		}
		catch (Exception^ exp)
		{
			break;
		}
	}
}
// ============== Schwartsune Kumiko 2014 =========================
//
// : Chat Server
//
// ================================================================
#include "Form3.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);

	Chat_Server::Form3 form;
	Application::Run(%form);
}


void Chat_Server::Form3::WhenClosed(Object^ sender, FormClosedEventArgs^ e)
{
	ShutDownServer(sender,e);
}
void Chat_Server::Form3::WhenLoad(Object^ sender, EventArgs^ e)
{
	btnCreate->Enabled = true;
	btnShutdown->Enabled = false;
}
void Chat_Server::Form3::ConnectToMasterServer()
{
	try
	{
		StreamReader^ readFromFile = File::OpenText(m_strMasterFile);
		masterIP = readFromFile->ReadLine();
		serverClient = gcnew TcpClient();
		serverClient->Connect(masterIP, 27016);
		StreamWriter^ writer = gcnew StreamWriter(serverClient->GetStream());
		writer->AutoFlush = true;
		log->AppendText("Sending info to Master-Server.\n");
		writer->WriteLine("%I% " + globalIP); // Server sends to Master-Server his own IP.
		log->AppendText("Succesfull.\n");
		btnCreate->Enabled = false;
		btnShutdown->Enabled = true;
	}
	catch (Exception^ exp)
	{
		MessageBox::Show(Convert::ToString(exp));
	}
}
void Chat_Server::Form3::DisconnectFromMasterServer()
{
	try
	{
		StreamWriter^ writer = gcnew StreamWriter(serverClient->GetStream());
		writer->AutoFlush = true;
		writer->WriteLine("%S% " + globalIP);
	}
	catch (Exception^ exp)
	{
	}
}
void Chat_Server::Form3::CreateServer(Object^ sender, EventArgs^ e)
{
	try
	{
		WebClient^ requestIP = gcnew WebClient();
		globalIP = requestIP->DownloadString("http://icanhazip.com/"); // читс вакабельный, гейбу звоню
		server = gcnew TcpListener(27015);
		server->Start();
		log->AppendText("Server started.\n");
		log->AppendText("Connecting to Master-Server.\n");
		ConnectToMasterServer();
	}
	catch (SocketException^ exp)
	{
		MessageBox::Show(Convert::ToString(exp));
	}
}
void Chat_Server::Form3::ShutDownServer(Object^ sender, EventArgs^ e)
{
	try
	{
		server->Stop();
		DisconnectFromMasterServer();
		serverClient->Close();
		btnCreate->Enabled = true;
		btnShutdown->Enabled = false;
		log->AppendText("Stopped.\n");
	}
	catch (Exception^ exp)
	{
	}
}
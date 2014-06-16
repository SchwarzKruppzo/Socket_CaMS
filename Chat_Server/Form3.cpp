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
		writer->WriteLine("IPc " + globalIP); // Server sends to Master-Server his own IP.
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
		writer->WriteLine("IPd " + globalIP); // нельзя через пробел делать
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
		m_bStarted = true;
		Thread^ acceptClientThread = gcnew Thread(gcnew ThreadStart(this, &Chat_Server::Form3::AcceptClients));
		acceptClientThread->Start();
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
void Chat_Server::Form3::SendMsgAll(String^ str)
{
	for each (TcpClient^ client in users)
	{
		StreamWriter^ writer = gcnew StreamWriter(client->GetStream());
		writer->AutoFlush = true;
		writer->WriteLine("MSG " + str);
	}
}
void Chat_Server::Form3::AcceptClients()
{
	while (m_bStarted) // В шахты лифта прыгали
	{
		try // Ноги себе ломали
		{
			TcpClient^ user = server->AcceptTcpClient();
			Thread^ clientThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &Chat_Server::Form3::ClientThread));
			clientThread->Start(user);
			users->Add(user);
			log->AppendText("A new user connected to chat.");
			SendMsgAll("[DEBUG|SENDING|BIG]server is here...............................................................");
		}
		catch (Exception^ exp) // Но пофиг
		{
			break;
		}
	}
}
void Chat_Server::Form3::ClientThread(Object^ data)
{
	TcpClient ^user = (TcpClient^)data;
	String^ signal;
	StreamReader^ reader = gcnew StreamReader(user->GetStream()); // Чтение биборана
	StreamWriter^ writer = gcnew StreamWriter(user->GetStream());
	writer->AutoFlush = true;
	while (m_bStarted)
	{
		try
		{
			signal = reader->ReadLine();
			if (signal->IndexOf("REFRESH") > -1)
			{
				
			}
		}
		catch (Exception^ exp)
		{
			break;
		}
	}
}
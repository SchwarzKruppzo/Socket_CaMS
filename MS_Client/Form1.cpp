// ============== Schwartsune Kumiko 2014 =========================
//
// : Master Server Client
//
// ================================================================
#include "Form1.h"
#include "ChatForm.h"
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
	ConnectedToMaster = false;
	try
	{
		StreamReader^ readFromFile = File::OpenText(m_strMasterFile);
		masterIP = readFromFile->ReadLine();
		client = gcnew TcpClient();
		client->Connect(masterIP, 27016);
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
	masterServer->Items->Clear();
	if (ConnectedToMaster)
	{
		try
		{
			writer->WriteLine("REFRESH"); // Send request for server
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
			masterServer->Items->Add(reader->ReadLine());
		}
		catch (Exception^ exp)
		{
			break;
		}
	}
}
void MS_Client::Form1::Connect(Object^ sender,EventArgs^ e)
{
	String^ ip = masterServer->GetItemText(masterServer->SelectedItem);
	MS_Client::ChatForm^ form = gcnew MS_Client::ChatForm;
	form->Show();
	form->Connect(ip);
}
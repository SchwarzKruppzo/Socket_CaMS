#include "ChatForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void MS_Client::ChatForm::Connect(String^ ip)
{
	try
	{
		client = gcnew TcpClient();
		client->Connect(ip, 27015);
		reader = gcnew StreamReader(client->GetStream());
		writer = gcnew StreamWriter(client->GetStream());
		writer->AutoFlush = true;
		Connected = true;
		this->Text = "IP: " + ip + " Topic: null";
		receiveThread = gcnew Thread(gcnew ThreadStart(this, &MS_Client::ChatForm::Receive));
		receiveThread->Start();
	}
	catch (Exception^ exp)
	{
		MessageBox::Show(Convert::ToString(exp));
	}
}
void MS_Client::ChatForm::Receive()
{
	String^ signal;
	while (Connected)
	{
		try
		{
			signal = reader->ReadLine();
			if (signal->IndexOf("MSG") > -1)
			{
				String^ msgf = signal->Substring(4);
				txtLog->AppendText(msgf);
			}
		}
		catch (Exception^ exp)
		{

		}
	}
}
void MS_Client::ChatForm::WhenClosed(Object^ sender, FormClosedEventArgs^ e)
{
	client->Close();
	Connected = false;
}
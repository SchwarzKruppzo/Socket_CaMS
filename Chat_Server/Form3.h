#pragma once

namespace Chat_Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::IO;
	using namespace System::Threading;
	using namespace System::Diagnostics;
	/// <summary>
	/// —водка дл€ Form3
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
	public:
		TcpClient^ serverClient; // Client for sending info to Master-Server

		TcpListener^ server; // Server for Chat
		String^ masterIP;
		String^ globalIP;
		String^ m_strMasterFile = "masterserver.txt";
		Form3(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnCreate;
	private: System::Windows::Forms::Button^  btnShutdown;


	protected:

	protected:

	private: System::Windows::Forms::TextBox^  log;


	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnCreate = (gcnew System::Windows::Forms::Button());
			this->btnShutdown = (gcnew System::Windows::Forms::Button());
			this->log = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnCreate
			// 
			this->btnCreate->Location = System::Drawing::Point(6, 6);
			this->btnCreate->Name = L"btnCreate";
			this->btnCreate->Size = System::Drawing::Size(90, 24);
			this->btnCreate->TabIndex = 0;
			this->btnCreate->Text = L"Create";
			this->btnCreate->UseVisualStyleBackColor = true;
			this->btnCreate->Click += gcnew System::EventHandler(this, &Form3::CreateServer);
			// 
			// btnShutdown
			// 
			this->btnShutdown->Location = System::Drawing::Point(108, 6);
			this->btnShutdown->Name = L"btnShutdown";
			this->btnShutdown->Size = System::Drawing::Size(90, 23);
			this->btnShutdown->TabIndex = 1;
			this->btnShutdown->Text = L"Shutdown";
			this->btnShutdown->UseVisualStyleBackColor = true;
			this->btnShutdown->Click += gcnew System::EventHandler(this, &Form3::ShutDownServer);
			// 
			// log
			// 
			this->log->Location = System::Drawing::Point(6, 42);
			this->log->Multiline = true;
			this->log->Name = L"log";
			this->log->Size = System::Drawing::Size(420, 270);
			this->log->TabIndex = 2;
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(432, 317);
			this->Controls->Add(this->log);
			this->Controls->Add(this->btnShutdown);
			this->Controls->Add(this->btnCreate);
			this->Name = L"Form3";
			this->Text = L"CServer:";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form3::WhenClosed);
			this->Load += gcnew System::EventHandler(this, &Form3::WhenLoad);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			 void WhenClosed(Object^ sender, FormClosedEventArgs^ e);
			 void WhenLoad(Object^ sender, EventArgs^ e);
			 void ConnectToMasterServer();
			 void CreateServer(Object^ sender, EventArgs^ e);
			 void ShutDownServer(Object^ sender, EventArgs^ e);
			 void DisconnectFromMasterServer();
};
}

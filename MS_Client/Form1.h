#pragma once

namespace MS_Client {

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
	/// —водка дл€ Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		TcpClient^ client;
		String^ masterIP;
		StreamWriter^ writer;
		StreamReader^ reader;
		Thread^ receiveThread;
		Boolean^ ConnectedToMaster;
		String^ m_strMasterFile = "masterserver.txt";
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  masterServer;
	private: System::Windows::Forms::Button^  btnRefresh;
	private: System::Windows::Forms::Button^  btnConnect;


	protected:

	protected:



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
			this->masterServer = (gcnew System::Windows::Forms::ListBox());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// masterServer
			// 
			this->masterServer->FormattingEnabled = true;
			this->masterServer->Location = System::Drawing::Point(6, 6);
			this->masterServer->Name = L"masterServer";
			this->masterServer->Size = System::Drawing::Size(210, 251);
			this->masterServer->TabIndex = 0;
			// 
			// btnRefresh
			// 
			this->btnRefresh->Location = System::Drawing::Point(6, 264);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(96, 23);
			this->btnRefresh->TabIndex = 1;
			this->btnRefresh->Text = L"Refresh";
			this->btnRefresh->UseVisualStyleBackColor = true;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &Form1::RefreshClick);
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(108, 264);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(96, 23);
			this->btnConnect->TabIndex = 2;
			this->btnConnect->Text = L"Connect";
			this->btnConnect->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(224, 294);
			this->Controls->Add(this->btnConnect);
			this->Controls->Add(this->btnRefresh);
			this->Controls->Add(this->masterServer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"Server List";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::WhenClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::WhenLoad);
			this->ResumeLayout(false);

		}
#pragma endregion
			 void WhenClosed(Object^ sender, FormClosedEventArgs^ e);
			 void WhenLoad(Object^ sender, EventArgs^ e);
			 void RefreshClick(Object^ sender, EventArgs^ e);
			 void ReceiveInformation();
	};
}

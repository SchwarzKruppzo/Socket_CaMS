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
	/// —водка дл€ ChatForm
	/// </summary>
	public ref class ChatForm : public System::Windows::Forms::Form
	{
	public:
		TcpClient^ client;
		StreamReader^ reader;
		StreamWriter^ writer;
		Thread^ receiveThread;
		Boolean^ Connected;
		ChatForm(void)
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
		~ChatForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::TextBox^  txtLog;
	private: System::Windows::Forms::SplitContainer^  splitContainer3;
	private: System::Windows::Forms::TextBox^  txtSend;
	private: System::Windows::Forms::Button^  btnSend;
	private: System::Windows::Forms::ListView^  lstUsers;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChatForm::typeid));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->txtLog = (gcnew System::Windows::Forms::TextBox());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->txtSend = (gcnew System::Windows::Forms::TextBox());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->lstUsers = (gcnew System::Windows::Forms::ListView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			resources->ApplyResources(this->statusStrip1, L"statusStrip1");
			this->statusStrip1->Name = L"statusStrip1";
			// 
			// splitContainer1
			// 
			resources->ApplyResources(this->splitContainer1, L"splitContainer1");
			this->splitContainer1->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->splitContainer2);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->lstUsers);
			// 
			// splitContainer2
			// 
			resources->ApplyResources(this->splitContainer2, L"splitContainer2");
			this->splitContainer2->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->txtLog);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->splitContainer3);
			// 
			// txtLog
			// 
			this->txtLog->BackColor = System::Drawing::SystemColors::Window;
			resources->ApplyResources(this->txtLog, L"txtLog");
			this->txtLog->Name = L"txtLog";
			this->txtLog->ReadOnly = true;
			// 
			// splitContainer3
			// 
			resources->ApplyResources(this->splitContainer3, L"splitContainer3");
			this->splitContainer3->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer3->Name = L"splitContainer3";
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->txtSend);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->btnSend);
			// 
			// txtSend
			// 
			resources->ApplyResources(this->txtSend, L"txtSend");
			this->txtSend->Name = L"txtSend";
			// 
			// btnSend
			// 
			resources->ApplyResources(this->btnSend, L"btnSend");
			this->btnSend->Name = L"btnSend";
			this->btnSend->UseVisualStyleBackColor = true;
			// 
			// lstUsers
			// 
			resources->ApplyResources(this->lstUsers, L"lstUsers");
			this->lstUsers->Name = L"lstUsers";
			this->lstUsers->UseCompatibleStateImageBehavior = false;
			// 
			// ChatForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->statusStrip1);
			this->Name = L"ChatForm";
			this->ShowInTaskbar = false;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ChatForm::WhenClosed);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel1->PerformLayout();
			this->splitContainer3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:
		void Connect(String^ ip);
		void Receive();
		void WhenClosed(Object^ sender, FormClosedEventArgs^ e);
};
}

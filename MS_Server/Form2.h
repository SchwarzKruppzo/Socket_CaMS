#pragma once

namespace MS_Server {

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
	/// —водка дл€ Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		TcpListener^ server;
		Boolean^ WaitingForClients;
		
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  log;
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
			this->log = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// log
			// 
			this->log->Location = System::Drawing::Point(6, 6);
			this->log->Multiline = true;
			this->log->Name = L"log";
			this->log->Size = System::Drawing::Size(426, 210);
			this->log->TabIndex = 0;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(437, 221);
			this->Controls->Add(this->log);
			this->Name = L"Form2";
			this->Text = L"Master Server";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form2::WhenClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form2::WhenClosed);
			this->Load += gcnew System::EventHandler(this, &Form2::WhenLoad);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void WhenClosed(Object^ sender, FormClosedEventArgs^ e);
		void WhenClosing(Object^ sender, FormClosingEventArgs^ e);
		void WhenLoad(Object^ sender, EventArgs^ e);
		void AcceptClients();
		void ClientThread(Object^ data);
	};
}

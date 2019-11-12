#pragma once
#include "MyForm.h"
#include "Registrarse.h"

using namespace std;
namespace Proyecto2PA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Resumen de Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtUsuario;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnCargarUsuario;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::LinkLabel^ linkLRegis;

	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnCargarUsuario = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->linkLRegis = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// txtUsuario
			// 
			this->txtUsuario->Location = System::Drawing::Point(65, 53);
			this->txtUsuario->Name = L"txtUsuario";
			this->txtUsuario->Size = System::Drawing::Size(114, 20);
			this->txtUsuario->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(65, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Usuario";
			// 
			// btnCargarUsuario
			// 
			this->btnCargarUsuario->Location = System::Drawing::Point(80, 79);
			this->btnCargarUsuario->Name = L"btnCargarUsuario";
			this->btnCargarUsuario->Size = System::Drawing::Size(71, 23);
			this->btnCargarUsuario->TabIndex = 2;
			this->btnCargarUsuario->Text = L"Login";
			this->btnCargarUsuario->UseVisualStyleBackColor = true;
			this->btnCargarUsuario->Click += gcnew System::EventHandler(this, &Main::btnCargarUsuario_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(41, 134);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"No estas registrado\?";
			// 
			// linkLRegis
			// 
			this->linkLRegis->AutoSize = true;
			this->linkLRegis->Location = System::Drawing::Point(157, 134);
			this->linkLRegis->Name = L"linkLRegis";
			this->linkLRegis->Size = System::Drawing::Size(56, 13);
			this->linkLRegis->TabIndex = 5;
			this->linkLRegis->TabStop = true;
			this->linkLRegis->Text = L"Pulsa aqui";
			this->linkLRegis->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Main::linkLRegis_LinkClicked);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(242, 164);
			this->Controls->Add(this->linkLRegis);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnCargarUsuario);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtUsuario);
			this->Name = L"Main";
			this->Text = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCargarUsuario_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ usuario ="..//"+txtUsuario->Text+".txt";
		try {
			StreamReader^ streamReader = gcnew StreamReader(usuario);
			MyForm^ form = gcnew MyForm();
			form->Show();
			this->Hide();
		}
		catch (System::IO::FileNotFoundException^ ae) {
			MessageBox::Show("Usuario no encontrado, Reg�strate");
		}
		catch (System::NotSupportedException ^ ae) {
			MessageBox::Show("Error en la carga del usuario");
		}
	}
private: System::Void linkLRegis_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	Registrarse^ form = gcnew Registrarse();
	form->Show();
	this->Hide();
}
};
}

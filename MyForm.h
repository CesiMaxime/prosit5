#pragma once
#include "CLserviceFichier.h"
#include "CLserviceImage.h"
#include "CLserviceFichier.h"
#include "CLserviceImage.h"


namespace test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btn_first;
	private: System::Windows::Forms::Button^ btn_previous;
	private: System::Windows::Forms::Button^ btn_next;
	private: System::Windows::Forms::Button^ btn_last;
	private: System::Windows::Forms::PictureBox^ pctBx;
	private: System::Windows::Forms::Label^ lbl_vision;
	private: System::Windows::Forms::Button^ btn_source;
	private: System::Windows::Forms::Button^ btn_destination;
	private: System::Windows::Forms::TextBox^ txt_source;
	private: System::Windows::Forms::TextBox^ txt_destination;

	private: System::Windows::Forms::GroupBox^ gpBox_typeProcessus;
	private: System::Windows::Forms::RadioButton^ rdb_effacer;
	private: System::Windows::Forms::RadioButton^ rdb_coiperEffacer;
	private: System::Windows::Forms::RadioButton^ rdb_copier;
	private: System::Windows::Forms::Button^ btn_proceder;
	private: System::Windows::Forms::TextBox^ txt_rslt;

	private: System::Windows::Forms::Label^ lbl_resultats;
	private: System::Windows::Forms::FolderBrowserDialog^ fld_source;
	private: System::Windows::Forms::FolderBrowserDialog^ fld_destination;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: array<String^>^ listeDeFichier;
	private: NS_services::CLserviceImage^ image;
	private: NS_services::CLserviceFichier^ svcFichier;
	private: int index;
	private: int nombreImages;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_first = (gcnew System::Windows::Forms::Button());
			this->btn_previous = (gcnew System::Windows::Forms::Button());
			this->btn_next = (gcnew System::Windows::Forms::Button());
			this->btn_last = (gcnew System::Windows::Forms::Button());
			this->pctBx = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_vision = (gcnew System::Windows::Forms::Label());
			this->btn_source = (gcnew System::Windows::Forms::Button());
			this->btn_destination = (gcnew System::Windows::Forms::Button());
			this->txt_source = (gcnew System::Windows::Forms::TextBox());
			this->txt_destination = (gcnew System::Windows::Forms::TextBox());
			this->gpBox_typeProcessus = (gcnew System::Windows::Forms::GroupBox());
			this->rdb_effacer = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_coiperEffacer = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_copier = (gcnew System::Windows::Forms::RadioButton());
			this->btn_proceder = (gcnew System::Windows::Forms::Button());
			this->txt_rslt = (gcnew System::Windows::Forms::TextBox());
			this->lbl_resultats = (gcnew System::Windows::Forms::Label());
			this->fld_source = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->fld_destination = (gcnew System::Windows::Forms::FolderBrowserDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBx))->BeginInit();
			this->gpBox_typeProcessus->SuspendLayout();
			this->SuspendLayout();

			// 
			// btn_first
			//
			this->btn_first->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_first->Location = System::Drawing::Point(10, 337);
			this->btn_first->Name = L"btn_first";
			this->btn_first->Size = System::Drawing::Size(75, 23);
			this->btn_first->TabIndex = 0;
			this->btn_first->Text = L"<<";
			this->btn_first->UseVisualStyleBackColor = true;

			// 
			// btn_previous
			//
			this->btn_previous->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_previous->Location = System::Drawing::Point(91, 337);
			this->btn_previous->Name = L"btn_previous";
			this->btn_previous->Size = System::Drawing::Size(75, 23);
			this->btn_previous->TabIndex = 1;
			this->btn_previous->Text = L"<";
			this->btn_previous->UseVisualStyleBackColor = true;
			this->btn_previous->Click += gcnew System::EventHandler(this, &MyForm::btn_previous_Click);

			// 
			// btn_next
			// 
			this->btn_next->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_next->Location = System::Drawing::Point(172, 337);
			this->btn_next->Name = L"btn_next";
			this->btn_next->Size = System::Drawing::Size(75, 23);
			this->btn_next->TabIndex = 2;
			this->btn_next->Text = L">";
			this->btn_next->UseVisualStyleBackColor = true;
			this->btn_next->Click += gcnew System::EventHandler(this, &MyForm::btn_next_Click);

			// 
			// btn_last
			// 
			this->btn_last->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_last->Location = System::Drawing::Point(253, 337);
			this->btn_last->Name = L"btn_last";
			this->btn_last->Size = System::Drawing::Size(75, 23);
			this->btn_last->TabIndex = 3;
			this->btn_last->Text = L">>";
			this->btn_last->UseVisualStyleBackColor = true;
			this->btn_last->Click += gcnew System::EventHandler(this, &MyForm::btn_last_Click);

			// 
			// pctBx
			// 
			this->pctBx->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctBx->Location = System::Drawing::Point(10, 27);
			this->pctBx->Name = L"pctBx";
			this->pctBx->Size = System::Drawing::Size(317, 302);
			this->pctBx->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pctBx->TabIndex = 4;
			this->pctBx->TabStop = false;

			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(278, 294);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_previous_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->index > 0)
		{
			this->index--;
			this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
		}
	}

	private: System::Void btn_next_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->index < this->listeDeFichier->Length - 1)
		{
			this->index++;
			this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
		}
	}

	private: System::Void btn_last_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = this->listeDeFichier->Length - 1;
		this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
	};
	};

}

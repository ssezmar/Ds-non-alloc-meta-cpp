#pragma once
#include <vector>
#include <sstream>
#include <msclr/marshal_cppstd.h> 





namespace Lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// ������ ��� MyForm1
	/// </summary>
	/// 

	
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:

		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

		String^ str;

		MyForm1(String^ input_str, List<int>^ data) {
			InitializeComponent();
			
			str = ConvertVectorToString(data);
			input_str = str;
			richTextBox3->Text = str; // ������������� ���������� ������
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	protected:

	private: System::Windows::Forms::Button^ button7;
		   List<int>^ vector_ = gcnew List<int>();
	
	public:
		List<int>^ GetVector() {
			return vector_;
		}
	


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox3
			// 
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->richTextBox3->Location = System::Drawing::Point(24, 40);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(623, 323);
			this->richTextBox3->TabIndex = 0;
			this->richTextBox3->Text = L"";
			this->richTextBox3->TextChanged += gcnew System::EventHandler(this, &MyForm1::richTextBox3_TextChanged);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(24, 380);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(621, 49);
			this->button7->TabIndex = 1;
			this->button7->Text = L"���������������";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm1::button7_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(657, 441);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->richTextBox3);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);

		}
#pragma endregion
	System::String^ ConvertVectorToString(List<int>^ vec) {
		// ������� ������ ��� �������� �����������
		std::string result;

		// �������� �� ���� ��������� �������
		for (Int32 i = 0; i < vec->Count; ++i) {
			// ����������� ������� ������� � ������ � ��������� ��� � ����������
			result += std::to_string(vec[i]);

			// ��������� �����������, ��������, �������, ����� ������� ��������
			if (i < vec->Count - 1) {
				result += ", ";
			}
		}

		// ����������� std::string � System::String^ � ���������� ���������
		return msclr::interop::marshal_as<System::String^>(result);
	}

	List<int>^  ConvertStringToVector(System::String^ str) {
		// ����������� System::String^ � std::string
		std::string strStd = msclr::interop::marshal_as<std::string>(str);

		// ������� ������ ��� �������� �����������
		List<int>^ result = gcnew List<int>();

		// ���������� ����� std::stringstream ��� ������� ������
		std::stringstream ss(strStd);
		int num;

		// ������ ����� �� ������ � ��������� �� � ������
		while (ss >> num) {
			result->Add(num);

			// ���� ����� ����� ���� ������ ����������� (�������, ������ � �.�.), ���������� ���
			if (ss.peek() == ',' || ss.peek() == ' ') {
				ss.ignore();
			}
		}

		return result;
	}


	private: System::Void richTextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		vector_ = ConvertStringToVector(richTextBox3->Text);
			
		this->Close();
	}
};
}

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
	/// Сводка для MyForm1
	/// </summary>
	/// 

	
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:

		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		String^ str;

		MyForm1(String^ input_str, List<int>^ data) {
			InitializeComponent();
			
			str = ConvertVectorToString(data);
			input_str = str;
			richTextBox3->Text = str; // Использование переданных данных
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
			this->button7->Text = L"Отредактировать";
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
		// Создаем строку для хранения результатов
		std::string result;

		// Проходим по всем элементам вектора
		for (Int32 i = 0; i < vec->Count; ++i) {
			// Преобразуем текущий элемент в строку и добавляем его к результату
			result += std::to_string(vec[i]);

			// Добавляем разделитель, например, запятую, после каждого элемента
			if (i < vec->Count - 1) {
				result += ", ";
			}
		}

		// Преобразуем std::string в System::String^ и возвращаем результат
		return msclr::interop::marshal_as<System::String^>(result);
	}

	List<int>^  ConvertStringToVector(System::String^ str) {
		// Преобразуем System::String^ в std::string
		std::string strStd = msclr::interop::marshal_as<std::string>(str);

		// Создаем вектор для хранения результатов
		List<int>^ result = gcnew List<int>();

		// Используем поток std::stringstream для разбора строки
		std::stringstream ss(strStd);
		int num;

		// Читаем числа из строки и добавляем их в вектор
		while (ss >> num) {
			result->Add(num);

			// Если после числа есть символ разделителя (запятая, пробел и т.д.), пропускаем его
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

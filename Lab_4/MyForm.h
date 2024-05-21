
#pragma once
#include "MyArray.h"
#include "MyVector.h"
#include "MyStack.h"
#include "MyQueue.h"
#include "MyForm1.h"
#include <vector>
#include <list>
#include <initializer_list>



MyArray<int> arr{ 44, 28, 100, 123, 123};
MyVector<int> vec{ 1, 2, 4, 2, 2, 2, 2 };
MyStack<int> st{ 1, 2, 1, 2, 5};
MyQueue<int> que{ 1, 2, 6 };

MyArray<char> arr_c;
MyVector<char> vec_c;
MyStack<char> st_c;
MyQueue<char> que_c;




namespace Lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(4) {
				L"Array", L"Vector", L"Stack",
					L"Queue"
			});
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Array", L"Vector", L"Stack", L"Queue" });
			this->comboBox1->Location = System::Drawing::Point(12, 21);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(347, 33);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"Выберите структуру";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(14, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(773, 342);
			this->label1->TabIndex = 1;
			this->label1->UseMnemonic = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 439);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(127, 80);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Редактор структуры";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(662, 439);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 80);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Информация";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(145, 439);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(125, 80);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Вариант 11";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(276, 439);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(125, 80);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Вариант 3";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(407, 439);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(125, 80);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Конвертор в ASCII";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(799, 531);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"MyForm";
			this->Text = L"Работа со структурами";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->Text == "Array") {
			label1->Text = arr.GetAllValuesAsString();
		}
		else if (comboBox1->Text == "Vector") {
			label1->Text = vec.GetAllValuesAsString();
		}
		else if (comboBox1->Text == "Stack") {
			label1->Text = st.GetAllValuesAsString();
		}
		else if (comboBox1->Text == "Queue") {
			label1->Text = que.GetAllValuesAsString();
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->Text == "Array") {
			arr.removeMostCommon();
			label1->Text = arr.GetAllValuesAsString();
		}
		else if (comboBox1->Text == "Vector") {
			vec.removeMostCommon();
			label1->Text = vec.GetAllValuesAsString();
		}
		else if (comboBox1->Text == "Stack") {
			st.removeMostCommon();
			label1->Text = st.GetAllValuesAsString();
		}
		else if (comboBox1->Text == "Queue") {
			que.removeMostCommon();
			label1->Text = que.GetAllValuesAsString();
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->Text == "Array") {
			arr.replaceOnesWithFive();
			label1->Text = arr.GetAllValuesAsString();
		}
		else if (comboBox1->Text == "Vector") {
			vec.replaceOnesWithFive();
			label1->Text = vec.GetAllValuesAsString();
		}
		else if (comboBox1->Text == "Stack") {
			st.replaceOnesWithFive();
			label1->Text = st.GetAllValuesAsString();
		}
		else if (comboBox1->Text == "Queue") {
			que.replaceOnesWithFive();
			label1->Text = que.GetAllValuesAsString();
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->Text == "Array") {
			label1->Text = arr.GetAllValuesAsASCIIString();
		}
		else if (comboBox1->Text == "Vector") {
			label1->Text = vec.GetAllValuesAsASCIIString();
		}
		else if (comboBox1->Text == "Stack") {
			label1->Text = st.GetAllValuesAsASCIIString();
		}
		else if (comboBox1->Text == "Queue") {
			label1->Text = que.GetAllValuesAsASCIIString();
		}
	}




	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ data = "Hello from Form1";
		List<int>^ shit = gcnew List<int>();
		if (comboBox1->Text == "Array") {
			for (int i = 0; i < arr.getSize(); i++) {
				shit->Add(arr[i]);
			}
			MyForm1^ form2 = gcnew MyForm1(data, shit);
			form2->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::Form2ClosedEventHandler);

			form2->Show();
		}
		else if (comboBox1->Text == "Vector") {
			for (int i = 0; i < vec.getSize(); i++) {
				shit->Add(vec[i]);
			}
			MyForm1^ form2 = gcnew MyForm1(data, shit);
			form2->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::Form2ClosedEventHandler);

			form2->Show();
		}
		else if (comboBox1->Text == "Stack") {
			std::vector<int> v = st.GetAllValuesAsVector();
			for (int i = 0; i < st.getSize(); i++) {
				shit->Add(v[i]);
			}

			MyForm1^ form2 = gcnew MyForm1(data, shit);
			form2->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::Form2ClosedEventHandler);

			form2->Show();
		}
		else if (comboBox1->Text == "Queue") {
			std::vector<int> v = que.GetAllValuesAsVector();
			for (int i = 0; i < que.getSize(); i++) {
				shit->Add(v[i]);
			}

			MyForm1^ form2 = gcnew MyForm1(data, shit);
			form2->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::Form2ClosedEventHandler);

			form2->Show();
		}

	}


		   System::Void Form2ClosedEventHandler(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
			   MyForm1^ form2 = dynamic_cast<MyForm1^>(sender);
			   List<int>^ vectorFromForm2 = form2->GetVector();
			   std::vector<int> v;
			   for (Int32 i = 0; i < vectorFromForm2->Count; i++) {
				   v.push_back(vectorFromForm2[i]);
			   }

			   if (comboBox1->Text == "Array") {

				   MyArray<int> arr2(v);
				   arr = arr2;
				   label1->Text = arr.GetAllValuesAsString();
			   }
			   else if (comboBox1->Text == "Vector") {
				   MyVector<int> arr2(v);
				   vec = arr2;
				   label1->Text = vec.GetAllValuesAsString();
			   }
			   else if (comboBox1->Text == "Stack") {
				   MyStack<int> arr2(v);
				   st = arr2;

				   label1->Text = st.GetAllValuesAsString();
			   }
			   else if (comboBox1->Text == "Queue") {
				   MyStack<int> arr2(v);
				   st = arr2;

				   label1->Text = st.GetAllValuesAsString();

			   }
		   }
		   };
	}


#include "win.h"
#include <QVBoxLayout>
#include <QMessageBox>

Win::Win(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Bib"); //заголовок окна

    frame = new QFrame(this); //создаем рамку
    frame->setFrameShadow(QFrame::Raised); //установка тени
    frame->setFrameShape(QFrame::Panel);
    inputLabel = new QLabel("Enter Number:", this); // создание метки

    inputEdit = new QLineEdit("",this); // создаем редактор ввода
    StrValidator *v=new StrValidator(inputEdit); // валидатор
    inputEdit->setValidator(v); // устанавливаем валидатор на ввод

    outputLabel = new QLabel("Result:", this); // создание метки
    outputEdit = new QLineEdit("",this); //  создание редактора ввода
    nextButton = new QPushButton("Next", this); // создаем кнопки next и exit
    exitButton = new QPushButton("Exit", this);

    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); // создание
    // менеджера компоновки для управления размещением метки и редакторов ввода в окне win
    vLayout1->addWidget(inputLabel);// добавление метки к компоновщику
    vLayout1->addWidget(inputEdit); // добавление редактора ввода к компоновщику
    vLayout1->addWidget(outputLabel); // добавление метки к компоновщику
    vLayout1->addWidget(outputEdit); // добавление редактора ввода к компоновщику
    vLayout1->addStretch(); // добавляем растяжение

    QVBoxLayout *vLayout2 = new QVBoxLayout();
    // создание менеджера компоновки для управления размещением кнопок в окне win
    vLayout2->addWidget(nextButton); // добавление кнопки
    vLayout2->addWidget(exitButton); // добавление кнопки
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();
    connect(exitButton,SIGNAL(clicked(bool)), //кнопка "выход" - закрывается окно
        this,SLOT(close()));
    connect(nextButton,SIGNAL(clicked(bool)), //кнопка "next" нажата
        this,SLOT(begin()));
    connect(inputEdit,SIGNAL(returnPressed()), //изменен ввод
        this,SLOT(calc()));
}

void Win::begin()
{
    inputEdit->clear(); //очищаем ввод
    nextButton->setEnabled(false);//отключаем кнопку
    nextButton->setDefault(false);

    inputEdit->setEnabled(true);//включаем ввод
    outputLabel->setVisible(false);//скрываем вывод
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();//устанавлен фокус на ввод
}
void Win::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();//получаем строку
    a=str.toDouble(&Ok);// преобразуем в double
    if (Ok)
    {
        r=a*a;//возводим в квадрат
        str.setNum(r); //устанавливаем в строку
        outputEdit->setText(str); //устанавливаем в текст
        inputEdit->setEnabled(false);//отключаем кнопку
        outputLabel->setVisible(true);//включаем кнопки и вывод
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else
        if (!str.isEmpty()) // если ввели не цифру
        { // выводим сообщение об ошибки
            QMessageBox msgBox(QMessageBox::Information, ("Bib"), ("Неверное значение"),
                       QMessageBox::Ok);
            msgBox.exec();
        }
}

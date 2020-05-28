#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SmtpMime"
QString login;
QString password;
QString name;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_pushButton_clicked()
{
    // This is a first demo application of the SmtpClient for Qt project

       // First we need to create an SmtpClient object
       // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

       SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

       // We need to set the username (your email address) and the password
       // for smtp authentification.

       smtp.setUser("aritest27@gmail.com");
       smtp.setPassword("77337362");

       // Now we create a MimeMessage object. This will be the email.

       MimeMessage message;

       message.setSender(new EmailAddress("aritest27.l@gmail.com", "Арсений Бойцов"));
       message.addRecipient(new EmailAddress("arsbov.@gmail.com", "Арсений Бойцов"));
       message.setSubject("Hello");

       // Now add some text to the email.
       // First we create a MimeText object.

       MimeText text;

       text.setText("Hi,This is a simple email message.");

       // Now add it to the mail

       message.addPart(&text);

       // Now we can send the mail

       smtp.connectToHost();
       smtp.login();
       smtp.sendMail(message);
       smtp.quit();

}*/

void MainWindow::on_pushButton_clicked()
{
    // This is a first demo application of the SmtpClient for Qt project

       // First we need to create an SmtpClient object
       // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

      // SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

       // We need to set the username (your email address) and the password
       // for smtp authentification.

      // smtp.setUser("aritest27@gmail.com");
      // smtp.setPassword("77337362");

       name=ui->Name_User->text();
       password=ui->password->text();
       login=ui->Login->text();
}

void MainWindow::on_pushButton_2_clicked()
{
    // Now we create a MimeMessage object. This will be the email.

    QString name2;
    QString login2;
    QString subject;
    QString text_message;

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser(login);
    smtp.setPassword(password);

    MimeMessage message;

    message.setSender(new EmailAddress(login, name));
    name2=ui->Name_getting_person->text();
    login2=ui->Login_of_getting_person->text();
    message.addRecipient(new EmailAddress(login2, name2));
    subject=ui->message_main->text();
    message.setSubject(subject);

    // Now add some text to the email.
    // First we create a MimeText object.

    MimeText text;
    text_message=ui->message_send->text();
    text.setText("Hi,This is a simple email message.");

    // Now add it to the mail

    message.addPart(&text);

    // Now we can send the mail

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
}

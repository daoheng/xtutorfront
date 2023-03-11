#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowTitle("公式识别器v0.1");
    ui->setupUi(this);
this->setWindowTitle("公式识别器v0.1");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString inputpath = ui->lineEdit->text();
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择视频"), ".", tr("Image Files(*.jpg *.png)"));
            const char *fileRealPath = filePath.toStdString().c_str();//将QString转换为char*
            qDebug()<< fileRealPath<<":图片路径路径";
//            showImage(ui->graphicsView->,fileRealPath);
    QImage *image = new QImage();
    image->load(filePath);
//    ui->label_3->setPixmap(QPixmap::fromImage(image).scaled(ui->label_3->size()));
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addPixmap(QPixmap(filePath).scaled(ui->graphicsView->size()));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

//    Ort::Env env();
//    Ort::SessionOptions ;
//    session_option.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);
//    session_option.SetExecutionMode(ExecutionMode::ORT_PARALLEL);
//    const char* model_path = "E:/code/model.onnx";
//    Ort::Session session(env,model_path,session_option);
}

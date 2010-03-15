#include "boissonnatscene.h"
#include "QFileDialog.h"
#include "QFile.h"
#include "QTextStream.h"


BoissonnatScene::BoissonnatScene()
{
}

BoissonnatScene::~BoissonnatScene()
{
}

void BoissonnatScene::buttonClicked(QString fileName)
{
    this->clear();
    points.clear();

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;


    fileCounter = 0;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        processLine(line);
        fileCounter ++;
    }

    for(int i = 0; i < points.size() -1; i++)
    {
        this->addEllipse(points.at(i).x() /2, points.at(i).y() /2, 1, 1,QPen(QColor(255, 0, 0)),QBrush(QColor(0, 250, 0)));
    }

}

void BoissonnatScene::processLine(QString line){

    if(!fileCounter == 0){

        points.append(QPointF(line.section(' ', 0, 0).toFloat(),line.section(' ', 1, 1).toFloat()));
    }
}



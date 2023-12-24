#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <fstream>
#include <QFileDialog>

using namespace std;

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
Ui::MainWindow *MainWindow::getUi() const
{
    return ui;
}
struct Point { // Структура точки
    double x;
    double y;
    int parent =-1;
};
struct Rectangle { // Струкрута прямоугольников
        double x_min;
        double x_max;
        double y_min;
        double y_max;
    };
class RRTStar {
public:
    RRTStar(int N, int k, Point Qinit, Point Qgoal,MainWindow *mainWindow,QPixmap *image, const vector<Rectangle>& externalRect)
            : N(N), k(k), Qinit(Qinit), Qgoal(Qgoal), mainWindow(mainWindow), image(image), Rect(externalRect)  {}

    Point RandomSample() { // возвращает новую случайную конфигурацию из Cfree.
        Point randomPoint;

        //Cfree
        const double minX = 0.0;
        const double maxX = 800.0;
        const double minY = 0.0;
        const double maxY = 650.0;

        // Генерация случайных координат в пределах Cfree
        randomPoint.x = minX + static_cast<double>(rand()) / RAND_MAX * (maxX - minX);
        randomPoint.y = minX + static_cast<double>(rand()) / RAND_MAX * (maxY - minY);

        return randomPoint;
    }



        bool isOverlap(const Rectangle& r1, const Rectangle& r2) {
            return (r1.x_min <= r2.x_max && r1.x_max >= r2.x_min &&
                    r1.y_min <= r2.y_max && r1.y_max >= r2.y_min);
        }

        bool CollisionFree(const Point& X, const Point& Y) { // проверяет, что путь по прямой из конфигурации X в Y не приводит к коллизиям, т.е. отрезок XY не пересекается с препятствиями из Cobs
            for (const auto& obstacle : Rect) {
                Rectangle pathSegment;

                pathSegment.x_min =  min(X.x, Y.x);
                pathSegment.x_max =  max(X.x, Y.x);
                pathSegment.y_min =  min(X.y, Y.y);
                pathSegment.y_max =  max(X.y, Y.y);

                if (isOverlap(pathSegment, obstacle)) {
                    return false;
                }
            }

            return true;
        }

    int Nearest( vector<Point>& G, Point X) { // возвращает вершину (конфигурацию) из графа G, ближайшую к конфигурации X. Если оказывается, что X близка не к одной вершине, а к ребру (т.е. что ближайшая к X конфигурация лежит на ребре графа), то в этом месте ребро делится на две части и в граф добавляется новая вершина, которая затем возвращается
        if (G.empty()) {
            return -1;
        }

        int nearestIndex = 0;
        double minDistance =  numeric_limits<double>::max();

        for (int i = 0; i < G.size(); ++i) {
            // Вычисление расстояния между текущей вершиной и X
            double distance =  sqrt( pow(G[i].x - X.x, 2) +  pow(G[i].y - X.y, 2));

            // Обновление ближайшей вершины, если расстояние меньше текущего минимума
            if (distance < minDistance) {
                minDistance = distance;
                nearestIndex = i;
            }
        }

        return nearestIndex;
    }

    Point Steer(Point X, Point Y) { // возвращает новую вершину (конфигурацию) Z из Cfree, лежащую на отрезке XY и ближайшую к Y, такую что CollisionFree(X, Z)
        Point Z;
        double maxStep = 10;
        double distanceXY =  sqrt( pow(Y.x - X.x, 2) +  pow(Y.y - X.y, 2));

        if (distanceXY == 0.0) {
            return X;
        }

        double ratio =  min(maxStep / distanceXY, 1.0);

        Z.x = X.x + ratio * (Y.x - X.x);
        Z.y = X.y + ratio * (Y.y - X.y);
        if(CollisionFree(X,Z)){
            return Z;
        }
        return X;
    }


     vector<int> Near( vector<Point>& G, Point X, int k) { // возвращает k вершин из графа G, ближайших к конфигурации X. Альтернативная версия функции может вместо числа вершин k использовать расстояние dist: тогда возвращаются все вершины графа ближе чем dist к конфигурации X.
         vector<int> nearIndices;

         vector< pair<int, double>> indexDistancePairs;

        for (int i = 0; i < G.size(); ++i) {
            double distance =  sqrt( pow(G[i].x - X.x, 2) +  pow(G[i].y - X.y, 2));
            indexDistancePairs.push_back( make_pair(i, distance));
        }

         sort(indexDistancePairs.begin(), indexDistancePairs.end(),
                  [](const  pair<int, double>& a, const  pair<int, double>& b) {
                      return a.second < b.second;
                  });

        for (int i = 0; i <  min(k, static_cast<int>(indexDistancePairs.size())); ++i) {
            nearIndices.push_back(indexDistancePairs[i].first);
        }

        return nearIndices;
    }

    double Length(Point X, Point Y) { // возвращает длину отрезка XY
        double len= sqrt(pow(Y.x - X.x,2)+pow(Y.y - X.y,2));
        return len;
    }

    Point Parent( vector<Point>& G, Point V) { //  возвращает родителя вершины V в графе G
        for(int i=G.size(); i>0;i--){
            if(G[i].x == V.x and G[i].y == V.y){
                return G[G[i].parent];
            }
        }
       return Point();
    }


    double Cost( vector<Point>& G, Point V) { // возвращает стоимость вершины V в графе G, Cost(G, V) = Cost(G, Parent(V)) + Length(Parent(V), V)
        if (V.parent == -1) {
            return 0.0;
        }

        int indexV = Index(G, V);

        if (indexV == -1 || G[V.parent].parent == -1) {
            return 0.0;
        }
        if (G[V.parent].parent == -1) {
            return Length(G[V.parent], V);
        }

        return Cost(G, G[V.parent]) + Length(G[V.parent], G[indexV]);
    }

    Point ChooseParent( vector<Point>& G, Point Qs, Point Qn,  vector<int>& Qnear) { // Выбор родителя для точки Qs
        Point Qmin = Qn;
                double Cmin = Cost(G, Qn) + Length(Qn, Qs);
                int k = 0;
                for (int Q : Qnear) {
                    if (CollisionFree(G[Q], Qs) && Cost(G, G[Q]) + Length(G[Q], Qs) < Cmin) {
                        Qmin = G[Q];
                        Cmin = Cost(G, G[Q]) + Length(G[Q], Qs);
                        k = Q;
                    }
                }

                for(int i=G.size(); i>0;i--){
                    if(G[i].x == Qs.x and G[i].y == Qs.y){
                        G[i].parent = k;
                        break;
                    }
                }
                return Qmin;
            }

     vector<Point> Update( vector<Point>& G, Point Qs,  vector<int>& Qnear,QPainter *paint) { // Перестройка путей в графе, если таковое возможно и целесообразно
        for (int Q : Qnear) {
                    if (CollisionFree(Qs, G[Q]) && Cost(G, Qs) + Length(Qs, G[Q]) < Cost(G, G[Q])) {
                        // Убираем старое ребро
                        G[Q].parent = -1;

                        // Добавляем новое ребро
                        G[Q].parent = Index(G, Qs);
                        paint->drawLine(Qs.x, Qs.y, G[Q].x, G[Q].y);
                        // Обновляем родительский индекс для всех потомков Q
                        for (int i = 0; i < G.size(); ++i) {
                            if (G[i].parent == Q) {
                                G[i].parent = Index(G, G[Q]);
                            }
                        }
                    }
                }
                return G;
            }
    int Index( vector<Point>& G, Point V) { // Возвращение индекса точки в массиве
        for (int i = 0; i < G.size(); i++) {
            if (G[i].x == V.x && G[i].y == V.y) {
                return i;
            }
        }
        return -1;
    }
    void Print(vector<Point>& Final, vector<Point>& G, Point Q,QPainter *painter){ // отображение пути оп координатам в консоль и выходной файл
        if(Q.parent != -1){
            painter->drawLine(Q.x, Q.y, Parent(G,Q).x, Parent(G,Q).y);
            Print(Final,G, Parent(G,Q),painter);
            Final.push_back(Q);
        }
        else{
            Q.parent = -1;
            Final.push_back(Q);
        }

    }
    void RRTStarAlgorithm(QPixmap *image_pixmap, QPainter *painter_bottom, QPainter *painter,vector<Point>& Final) { // функция Алгоритма RRT*
        // Инициализация графа G и добавление начальной вершины
        vector<Point> G;
        G.push_back(Qinit);

        for (int i = 1; i <= N; ++i) {


            // Генерация случайной конфигурации
            Point Qrand = RandomSample();

            // Поиск ближайшей вершины в графе
            Point Qn = G[Nearest(G, Qrand)];

            // Нахождение ближайшей точки на отрезке между Qn и Qrand
            Point Qs = Steer(Qn, Qrand);
            if(Qn.x != Qs.x and Qn.y != Qs.y) {
                // Поиск k ближайших вершин к Qs
                vector<int> Qnear = Near(G, Qs, k);

                // Добавление вершины Qs в граф G
                G.push_back(Qs);

                // Выбор родителя для Qs
                Point Qp = ChooseParent(G, Qs, Qn, Qnear);

                // Добавление ребра (Qp, Qs) в граф G
                G[Index(G,Qs)].parent = Index(G,Qp);
                painter->setPen(QPen(Qt::cyan,1));
                painter->drawLine(Qs.x, Qs.y, Qp.x, Qp.y);
                // Обновление графа G
                G = Update(G, G[G.size()-1], Qnear,painter);
            }
        }
        painter->setBrush(QBrush(Qt::yellow,Qt::SolidPattern));
        painter->setPen(Qt::black);
        QRect initcircle(Qinit.x - 2.5, Qinit.y - 2.5, 5, 5);
        painter->drawEllipse(initcircle);
        // Соединение Qgoal с графом G (добавление конечной вершины и ребра)
        double min_dist = 1000;
        int min_dist_index = -1;
        //поиск индекса точки, который максимально близко к конфигурации Qgoal и  входит в её окрестность
        for(int i = G.size();i>0;i--){
            if(Length(G[i],Qgoal)<=20){
                if(min_dist > Length(G[i],Qgoal)){
                    min_dist = Length(G[i],Qgoal);
                    min_dist_index = i;
                }
            }
        }
        Qgoal.parent = min_dist_index;
        G.push_back(Qgoal); //"Закрываем" массив последней конфигурацией Qgoal
        painter->setBrush(QBrush(Qt::cyan,Qt::SolidPattern));
        for(int i = 1;i < G.size();i++){
            QRect circles(G[i].x-2.5,G[i].y-2.5,3,3);
            painter->drawEllipse(circles);
        }
        //Отрисовываем объекты
        painter->setBrush(QBrush(Qt::red,Qt::SolidPattern));
        for(int i =0 ; i<Rect.size();i++){
            QRect Pol(Rect[i].x_min, Rect[i].y_min, Rect[i].x_max - Rect[i].x_min, Rect[i].y_max - Rect[i].y_min);
            painter->drawRect(Pol);
        }
        QRect circle(Qgoal.x-2.5,Qgoal.y-2.5,5,5);
        painter->setBrush(QBrush(Qt::magenta,Qt::SolidPattern));
        painter->drawEllipse(circle);
        //отрисовка пути
        painter->setBrush(QBrush(Qt::white,Qt::SolidPattern));
        painter_bottom->setPen(QPen(Qt::green,3));
        Print(Final,G,Qgoal,painter_bottom);
        painter->end();
        painter_bottom->end();
    }

private:
    int N; // Число сэмплов
    int k; // Число ближайших вершин к рассмотрению
    Point Qinit; // Начальная конфигурация
    Point Qgoal; // Конечная конфигурация
    vector<Rectangle> Rect; //массив фигур
    MainWindow *mainWindow; //Указатель на окно
    QPixmap *image; //указатель на рисунок
};
vector<Point> Fill_G(vector<Point>& G,ifstream &File){ // заполнение вершин из файла
    Point Q;
    File >> Q.x;
    File >> Q.y;
    G.push_back(Q);
    File >> Q.x;
    File >> Q.y;
    G.push_back(Q);
    return G;
}
vector<Rectangle> Fill_Rect(vector<Rectangle>& Rect,ifstream &File){ // Заполнение массива фигур из файла
    Rectangle Rectangls;
    Rectangls.x_min = 900;
    Rectangls.x_max = 900;
    Rectangls.y_min = 900;
    Rectangls.y_max = 900;
    Rect.push_back(Rectangls);
    while(!File.eof()){
        File >> Rectangls.x_min;
        File >> Rectangls.x_max;
        File >> Rectangls.y_min;
        File >> Rectangls.y_max;
        Rect.push_back(Rectangls);
    }
    return Rect;
}
bool PathCreated(vector<Point>& F,ofstream &File){ // Проверка на существование пути из точки А в точку Б
    for(int i=0;i<F.size();i++){
        if((F[i].parent == F[i-1].parent) || (F.size() == 1)){
            File << "Не удалось построить путь";
            return 0;
        }
    }
    return 1;
}
void Result_out(vector<Point>& F,ofstream &File){ // Вывод результата работы программы в выходной файл
    if(PathCreated(F,File)){
        int k = F.size();
        for(int i=0 ;i<k-1 ;i++){
            if(F[i].x == F[i+1].x and F[i].y == F[i+1].y){
                F.erase(F.begin()+i);
                k--;
                i--;

            }
        }
        File << "Путь был построен по координатам: "<<endl;
        for(int i =0;i<F.size();i++){
            File << "( "<< F[i].x << " ; " << F[i].y << " )"<<endl;
        }
    }
}
bool in_rect(vector<Point>& G, Rectangle R) { // Проверка на положение точки относительно фигуры
    for(int i = 0;i<G.size(); i++ ){
        if(R.x_min<=G[i].x and G[i].x<=R.x_max and R.y_min<=G[i].y and G[i].y<=R.y_max){
            return true;
        }
    }

    return false;
}

void MainWindow::Draw(string in, string out,string objects){
    vector<Point> G;
    vector<Point> Final;
    vector<Rectangle> Rect;
    ifstream fin;
    fin.open(in);
    ofstream rez;
    if (!fin.is_open()) {
        exit(0);
    }
    Fill_G(G,fin);

    ifstream Rectin;
    Rectin.open(objects);
    if (!Rectin.is_open()) {
        exit(0);
        }
    Fill_Rect(Rect, Rectin);

    int N = ui->spinBox1->value();
    int k = ui->spinBox->value();
    ui->label->clearMask();
    ui->label_2->clearMask();
    QPixmap *image_pixmap = new QPixmap(800, 650);
    QPixmap *image_pixmap_bottom = new QPixmap(800, 650);
    image_pixmap->fill(Qt::white);
    image_pixmap_bottom->fill(Qt::transparent);
    for(int i =1;i<G.size();i++){
        RRTStar rrt(N, k, G[i-1], G[i], this, image_pixmap, Rect);
        QPainter *painter = new QPainter(image_pixmap);
        QPainter *painter_bottom = new QPainter(image_pixmap_bottom);
        rrt.RRTStarAlgorithm(image_pixmap,painter_bottom,painter,Final);
        ui->label->setPixmap(*image_pixmap);
        ui->label_2->setPixmap(*image_pixmap_bottom);
        ui->label->repaint();
        ui->label_2->repaint();
    }
    rez.open(out);
    Result_out(Final,rez);
    ui->label_7->setText("Сцена построена\n");
    rez.close();
    fin.close();
}



void MainWindow::on_pushButton_clicked() // функция по нажатию кнопки "Сгенерировать"
{
    string points = ui->lineEdit->text().toStdString();
    string objects = ui->lineEdit_2->text().toStdString();
    string path_out = ui->lineEdit_3->text().toStdString();
    ui->label_7->clear();
    Draw(points,path_out,objects);
}


void MainWindow::on_pushButton_2_clicked() // функция по нажатию кнопки "Сохранить"
{
    QPixmap screenshot = ui->tab->grab();
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Screenshot"), "", tr("Images (*.png *.jpg *.bmp)"));

    if (!filePath.isEmpty()) {
        screenshot.save(filePath);
    }
}


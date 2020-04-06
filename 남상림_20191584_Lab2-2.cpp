//////////////////////////////////////////////////////////////
//Lab 2 : Compute Area of the Figures (다면체 면적 구하기) 
//Name : Nam Sang Lim
// ID : 20191584
// Program Description : Compute Area of the Figures (다면체 면적 구하기) Lab2-2
//Algorithm : math..? 수학공식 ..? 
// Variable : angel[] : 다각형 마다의 입력 받아야 하는 정보 들을 담은 배열
/////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

struct Angle {
    string fig;
    int width;
    int height;
    int round;
    double area;
};

Angle angle[7];

int main() {
    cout << "INPUT DATA FILE : (7 개 데이터)\n";
    for (int t = 0; t < 7; t++) {
        cin >> angle[t].fig;
        if (angle[t].fig == "triangle") {
            cin >> angle[t].width >> angle[t].height;
            angle[t].area = angle[t].width * angle[t].height / 2.0;
        }
        else if (angle[t].fig == "rectangle") {
            cin >> angle[t].width >> angle[t].height;
            angle[t].area = angle[t].width * angle[t].height;
        }
        else if (angle[t].fig == "circle") {
            cin >> angle[t].round;
            angle[t].area = angle[t].round * angle[t].round * 3.14;
        }
    }
   
    cout << "\nOUTPUT :" << endl;
    cout << fixed; //소수점 고정을 위함 아직 자세히는 모르겠음..
    cout.precision(2); //소수점 2쨋 자리까지 출력하기 위해 적어둠
    for (int t = 0; t < 7; t++) {
        cout << angle[t].fig << " ";
        if (angle[t].fig == "triangle") {
            cout << angle[t].width * 1.0 << " " << angle[t].height * 1.0 << " " << angle[t].area << endl;
        }
        else if (angle[t].fig == "rectangle") {
            cout << angle[t].width * 1.0 << " " << angle[t].height * 1.0 << " " << angle[t].area << endl;
        }
        else if (angle[t].fig == "circle") {
            cout << angle[t].round * 1.0 << " " << angle[t].area << endl;

        }
    }
}